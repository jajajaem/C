#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INVENTORY_SIZE 10

typedef struct{
    const char *name;
    int heal_amount;
    int drop_rate;
} Item;

typedef struct{
    const char *name;
    int power;
} Item2;

typedef struct{
    char *name;
    int hp;
    int max_hp;
    int attack;
    int defense;
    int level;
    int exp;
    int max_exp;
    Item inventory[INVENTORY_SIZE];
    int item_count;
    int gold;
} Player;

typedef struct{
    const char *name;
    int hp;
    int attack;
    int defense;
    int exp_reward;
    int drop_gold;
    Item *drop_items;
    int drop_count;
} Monster;

typedef struct{
    const char *name;
    Monster *monster;
    int monster_count;
    int min_level;
    int difficulty;
} Map;

void init_player(Player *p){
    char temp[100];
    printf("�÷��̾��� �̸���? : ");
    fgets(temp, sizeof(temp), stdin);

    size_t len = strlen(temp);
    if(temp[len - 1] == '\n') temp[len - 1] = '\0';

    p->name = (char*)malloc(len);
    if(p->name == NULL){
        printf("�̸� �޸� �Ҵ� ����\n");
        exit(1);
    }
    strcpy(p->name, temp);

    p->attack = 5;
    p->defense = 2;
    p->exp = 0;
    p->level = 1;
    p->hp = 25;
    p->max_hp = 25;
    p->max_exp = 20;
    p->item_count = 0;
    p->gold = 0;
}

void show_status(Player *p){
    printf("\n[�÷��̾� ����]\n");
    printf("�̸�: %s\n", p->name);
    printf("����: %d\n", p->level);
    printf("HP: %d / %d\n", p->hp, p->max_hp);
    printf("���ݷ�: %d\n", p->attack);
    printf("����: %d\n", p->defense);
    printf("����ġ: %d / %d\n", p->exp, p->max_exp);
    printf("���� �ݾ� : %d\n", p->gold);
}

void level_up(Player *p){
    while(p->exp >= p->max_exp){
        p->exp = 0;
        p->level++;
        p->max_hp += 5;
        p->hp = p->max_hp;
        p->attack += 1;
        p->defense += 1;
        p->max_exp += p->max_exp/3;

        printf("������! ���� %d ������ �Ǿ����ϴ�!\nü���� ȸ���Ǿ����ϴ�.\n", p->level);
    }
}

void save_game(Player *p){
    FILE *fp = fopen("save.txt", "w");
    if(fp == NULL){
        printf("���̺� ������ �� �� �����ϴ�. �� ������ �����մϴ�.\n");
        init_player(p);
        return;
    }

    fprintf(fp, "%s\n", p->name);
    fprintf(fp, "%d %d %d %d %d %d %d %d\n",
        p->hp, p->max_hp, p->attack, p->defense,
        p->level, p->exp, p->max_exp, p->gold);
    
        fprintf(fp, "%d\n", p->item_count);
        for(int i = 0; i < p->item_count; i++){
            fprintf(fp, "\"%s\" %d\n", p->inventory[i].name, p->inventory[i].heal_amount);
        }
        fclose(fp);
        printf("������ ���������� ����Ǿ����ϴ�.\n");
}

void load_game(Player *p){
    FILE *fp = fopen("save.txt", "r");
    if(fp == NULL){
        printf("���̺� ������ �������� �ʽ��ϴ�.\n");
        return;
    }

    char temp[100];
    fgets(temp, sizeof(temp), fp);
    size_t len = strlen(temp);
    if(temp[len - 1] == '\n') temp[len - 1] = '\0';

    p->name = (char*)malloc(len);
    strcpy(p->name, temp);

    fscanf(fp, "%d %d %d %d %d %d %d %d",
        &p->hp, &p->max_hp, &p->attack, &p->defense,
        &p->level, &p->exp, &p->max_exp, &p->gold);

    fscanf(fp, "%d", &p->item_count);
    for(int i = 0; i < p->item_count; i++){
        char name_buf[50];
        int heal;
        fscanf(fp, " \"%[^\"]\" %d", name_buf, &heal);
        p->inventory[i].name = strdup(name_buf); // strdup : ���ڿ� ����, �޸� �Ҵ�
        p->inventory[i].heal_amount = heal;
    }
    fclose(fp);
    printf("���� �����͸� �ҷ��Խ��ϴ�.\n");
}

void cleanup(Player *p){
    if(p->name){
        free(p->name);
        p->name = NULL;
    }

    for(int i = 0; i < p->item_count; i++){
        if(p->inventory[i].name){
            free((void*)p->inventory[i].name);
            p->inventory[i].name = NULL;
        }
    }
}

void give_battle_rewards(Player *p, Monster *m){
    int base = m->exp_reward;
    int min_exp = base / 2;
    int max_exp = base + min_exp;
    int exp_reward = rand() % (max_exp - min_exp + 1) + min_exp;
    p->exp += exp_reward;
    printf("����ġ %d ȹ��!\n", exp_reward);
    level_up(p);

    for(int i = 0; i < m->drop_count; i++){
        Item item = m->drop_items[i];
        int roll = rand() % 100;

        if(roll < item.drop_rate){
            if(p->item_count >= INVENTORY_SIZE){
                printf("�κ��丮�� ���� á���ϴ�.\n");
                return;
            }

            p->inventory[p->item_count] = item;
            p->item_count++;

            printf("%s��(��) ȹ���߽��ϴ�! (ȸ���� : %d)\n", item.name, item.heal_amount);
        }
    }

    int gold_min = m->drop_gold / 2;
    int gold_max = m->drop_gold + gold_min;
    int drop_gold = rand() % (gold_max - gold_min + 1) + gold_min;
    p->gold += drop_gold;
    printf("%d��带 ������ϴ�!\n", drop_gold);
}

void use_item(Player *p){
    if(p->item_count == 0){
        printf("�κ��丮�� �������� �����ϴ�!\n");
        return;
    }

    printf("\n[�κ��丮]\n");
    for(int i = 0; i < p->item_count; i++){
        printf("%d. %s (ȸ���� : %d)\n", i + 1,p->inventory[i].name, p->inventory[i].heal_amount);
    }

    printf("����� ������ ��ȣ�� �Է��ϼ��� : ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if(choice < 1 || choice > p->item_count){
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    Item selected = p->inventory[choice - 1];

    if(selected.heal_amount > 0){
        p->hp += selected.heal_amount;
        if(p->hp > p->max_hp) p->hp = p->max_hp;
        printf("ü���� %d��ŭ ȸ���Ǿ����ϴ�! (���� HP : %d)\n", selected.heal_amount, p->hp);
    }

    for(int i = choice - 1; i < p->item_count - 1; i++){
        p->inventory[i] = p->inventory[i + 1];
    }
    p->item_count--;
}

int battle(Player *p, Monster *m){
    printf("\n���� ����! %s vs %s\n", p->name, m->name);

    while(p->hp > 0 && m->hp > 0){

        printf("1. ����\n2.������ ���\n>>");
        int choice;
        scanf("%d", &choice);
        getchar();
        if(choice == 1){
            int dmg_to_mon = p->attack - m->defense;
            if(dmg_to_mon < 1) dmg_to_mon = 1;
            m->hp -= dmg_to_mon;

            printf("%s�� %s���� %d ������!\n���� ü�� : %d\n", p->name, m->name, dmg_to_mon, m->hp);
            if(m->hp <= 0){
                printf("%s�� �����ƽ��ϴ�!\n", m->name);
                give_battle_rewards(p, m);
                return 1;
            }
        } else if(choice == 2){
            use_item(p);
        } else{
            printf("�߸��� �����Դϴ�.\n");
            continue;
        }
        int dmg_to_player = m->attack - p->defense;
            if(dmg_to_player < 1) dmg_to_player = 1;
            p->hp -= dmg_to_player;

            printf("%s�� %s���� %d ������!\n���� ü�� : %d\n", m->name, p->name, dmg_to_player, p->hp);
    }
    if(p->hp <= 0){
        printf("%s�� ���������ϴ�...\n", p->name);
        return 0;
    }
    return 1;
}

int encounter(Player *p, Map *map){
    int index = rand() % map->monster_count;
    Monster m = map->monster[index];

    printf("\n[%s]���� %s(��)�� ��Ÿ����. [hp: %d, atk: %d, def: %d]\n", map->name, m.name, m.hp, m.attack, m.defense);
    return battle(p, &m);

}

int main(){
    srand(time(NULL));
    Player player;

    printf("������ �ҷ����ðڽ��ϱ�? (1: �� / �ƹ� Ű: �ƴϿ�) >> ");
    int load_choice;
    scanf("%d", &load_choice);
    getchar();

    if(load_choice == 1){
        load_game(&player);
    } else{
        init_player(&player);
    }
    Item forest_items[] = {
        {"���� ȸ����", 10, 50},
        {"�߰� ȸ����", 20, 30},
        {"��� ȸ����", 50, 5}    
    };
    
    Monster forest_monster[] = {
        {"������", 10, 2, 0, 5, 20, forest_items, 3},
        {"���", 20, 4, 1, 10, 30, forest_items, 3}
    };

    Monster cave_monster[] = {
        {"��ũ", 35, 6, 2, 15, 60},
        {"���̷���", 40, 7, 3, 20, 80}
    };

    Monster volcano_monster[] = {
        {"�巡��", 100, 20, 5, 100, 300}
    };

    Map maps[] = {
        {"�ʿ�", forest_monster, sizeof(forest_monster) / sizeof(forest_monster[0]), 1, 1},
        {"����", cave_monster, sizeof(cave_monster) / sizeof(cave_monster[0]), 5, 3},
        {"ȭ��", volcano_monster, sizeof(volcano_monster) / sizeof(volcano_monster[0]), 10, 8}
    };

    int map_count = sizeof(maps) / sizeof(maps[0]);
    
    while(player.hp > 0){
        printf("\n�޴�\n1. ���� ����\n2. ���� ������\n3. ȸ��\n4. ������ ���\n5. ����\n6. ����\n>> ");
        int choice;
        scanf("%d", &choice);
        getchar();

        if(choice == 1){
            show_status(&player);
        } else if(choice == 2){
            printf("�̵��� ���� �����ϼ��� :\n");
            for(int i = 0; i < map_count; i++){
                printf("%d. %s (���� %d �̻�, ���̵� ", i + 1, maps[i].name, maps[i].min_level);
                for(int j = 0; j < maps[i].difficulty; j++) printf("��");
                printf(")\n");
            }
            printf(">> ");

            int map_choice;
            scanf("%d", &map_choice);
            getchar();

            if(map_choice < 1 || map_choice > map_count){
                printf("�߸��� �����Դϴ�.\n");
                continue;
            }
            
            if(player.level < maps[map_choice - 1].min_level){
                printf("�� ������ �ּ� ���� %d �̻� ������ �� �ֽ��ϴ�.", maps[map_choice - 1].min_level);
                continue;
            }

            Map *current_map = &maps[map_choice - 1];
            int result = encounter(&player,current_map);
            if(result == 0){
                printf("\n���� ����\n");
                break;
            }
        } else if(choice == 3){
            player.hp = player.max_hp;
            printf("ü���� ��� ȸ���߽��ϴ�!\n");
        }else if(choice == 4){
            use_item(&player);
        } else if(choice == 5){
            save_game(&player);
        }else if(choice == 6){
            printf("������ �����մϴ�.\n");
            break;
        } else{
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }

    cleanup(&player);
    return 0;
}
