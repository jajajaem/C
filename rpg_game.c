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
    printf("플레이어의 이름은? : ");
    fgets(temp, sizeof(temp), stdin);

    size_t len = strlen(temp);
    if(temp[len - 1] == '\n') temp[len - 1] = '\0';

    p->name = (char*)malloc(len);
    if(p->name == NULL){
        printf("이름 메모리 할당 실패\n");
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
    printf("\n[플레이어 상태]\n");
    printf("이름: %s\n", p->name);
    printf("레벨: %d\n", p->level);
    printf("HP: %d / %d\n", p->hp, p->max_hp);
    printf("공격력: %d\n", p->attack);
    printf("방어력: %d\n", p->defense);
    printf("경험치: %d / %d\n", p->exp, p->max_exp);
    printf("보유 금액 : %d\n", p->gold);
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

        printf("레벨업! 이제 %d 레벨이 되었습니다!\n체력이 회복되었습니다.\n", p->level);
    }
}

void save_game(Player *p){
    FILE *fp = fopen("save.txt", "w");
    if(fp == NULL){
        printf("세이브 파일을 열 수 없습니다. 새 게임을 시작합니다.\n");
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
        printf("게임이 성공적으로 저장되었습니다.\n");
}

void load_game(Player *p){
    FILE *fp = fopen("save.txt", "r");
    if(fp == NULL){
        printf("세이브 파일이 존재하지 않습니다.\n");
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
        p->inventory[i].name = strdup(name_buf); // strdup : 문자열 복사, 메모리 할당
        p->inventory[i].heal_amount = heal;
    }
    fclose(fp);
    printf("게임 데이터를 불러왔습니다.\n");
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
    printf("경험치 %d 획득!\n", exp_reward);
    level_up(p);

    for(int i = 0; i < m->drop_count; i++){
        Item item = m->drop_items[i];
        int roll = rand() % 100;

        if(roll < item.drop_rate){
            if(p->item_count >= INVENTORY_SIZE){
                printf("인벤토리가 가득 찼습니다.\n");
                return;
            }

            p->inventory[p->item_count] = item;
            p->item_count++;

            printf("%s을(를) 획득했습니다! (회복량 : %d)\n", item.name, item.heal_amount);
        }
    }

    int gold_min = m->drop_gold / 2;
    int gold_max = m->drop_gold + gold_min;
    int drop_gold = rand() % (gold_max - gold_min + 1) + gold_min;
    p->gold += drop_gold;
    printf("%d골드를 얻었습니다!\n", drop_gold);
}

void use_item(Player *p){
    if(p->item_count == 0){
        printf("인벤토리에 아이템이 없습니다!\n");
        return;
    }

    printf("\n[인벤토리]\n");
    for(int i = 0; i < p->item_count; i++){
        printf("%d. %s (회복량 : %d)\n", i + 1,p->inventory[i].name, p->inventory[i].heal_amount);
    }

    printf("사용할 아이템 번호를 입력하세요 : ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if(choice < 1 || choice > p->item_count){
        printf("잘못된 선택입니다.\n");
        return;
    }

    Item selected = p->inventory[choice - 1];

    if(selected.heal_amount > 0){
        p->hp += selected.heal_amount;
        if(p->hp > p->max_hp) p->hp = p->max_hp;
        printf("체력이 %d민큼 회복되었습니다! (현재 HP : %d)\n", selected.heal_amount, p->hp);
    }

    for(int i = choice - 1; i < p->item_count - 1; i++){
        p->inventory[i] = p->inventory[i + 1];
    }
    p->item_count--;
}

int battle(Player *p, Monster *m){
    printf("\n전투 시작! %s vs %s\n", p->name, m->name);

    while(p->hp > 0 && m->hp > 0){

        printf("1. 공격\n2.아이템 사용\n>>");
        int choice;
        scanf("%d", &choice);
        getchar();
        if(choice == 1){
            int dmg_to_mon = p->attack - m->defense;
            if(dmg_to_mon < 1) dmg_to_mon = 1;
            m->hp -= dmg_to_mon;

            printf("%s가 %s에게 %d 데미지!\n남은 체력 : %d\n", p->name, m->name, dmg_to_mon, m->hp);
            if(m->hp <= 0){
                printf("%s를 물리쳤습니다!\n", m->name);
                give_battle_rewards(p, m);
                return 1;
            }
        } else if(choice == 2){
            use_item(p);
        } else{
            printf("잘못된 선택입니다.\n");
            continue;
        }
        int dmg_to_player = m->attack - p->defense;
            if(dmg_to_player < 1) dmg_to_player = 1;
            p->hp -= dmg_to_player;

            printf("%s가 %s에게 %d 데미지!\n남은 체력 : %d\n", m->name, p->name, dmg_to_player, p->hp);
    }
    if(p->hp <= 0){
        printf("%s가 쓰러졌습니다...\n", p->name);
        return 0;
    }
    return 1;
}

int encounter(Player *p, Map *map){
    int index = rand() % map->monster_count;
    Monster m = map->monster[index];

    printf("\n[%s]에서 %s(이)가 나타났다. [hp: %d, atk: %d, def: %d]\n", map->name, m.name, m.hp, m.attack, m.defense);
    return battle(p, &m);

}

int main(){
    srand(time(NULL));
    Player player;

    printf("게임을 불러오시겠습니까? (1: 예 / 아무 키: 아니오) >> ");
    int load_choice;
    scanf("%d", &load_choice);
    getchar();

    if(load_choice == 1){
        load_game(&player);
    } else{
        init_player(&player);
    }
    Item forest_items[] = {
        {"작은 회복약", 10, 50},
        {"중간 회복약", 20, 30},
        {"희귀 회복약", 50, 5}    
    };
    
    Monster forest_monster[] = {
        {"슬라임", 10, 2, 0, 5, 20, forest_items, 3},
        {"고블린", 20, 4, 1, 10, 30, forest_items, 3}
    };

    Monster cave_monster[] = {
        {"오크", 35, 6, 2, 15, 60},
        {"스켈레톤", 40, 7, 3, 20, 80}
    };

    Monster volcano_monster[] = {
        {"드래곤", 100, 20, 5, 100, 300}
    };

    Map maps[] = {
        {"초원", forest_monster, sizeof(forest_monster) / sizeof(forest_monster[0]), 1, 1},
        {"동굴", cave_monster, sizeof(cave_monster) / sizeof(cave_monster[0]), 5, 3},
        {"화산", volcano_monster, sizeof(volcano_monster) / sizeof(volcano_monster[0]), 10, 8}
    };

    int map_count = sizeof(maps) / sizeof(maps[0]);
    
    while(player.hp > 0){
        printf("\n메뉴\n1. 상태 보기\n2. 몬스터 만나기\n3. 회복\n4. 아이템 사용\n5. 저장\n6. 종료\n>> ");
        int choice;
        scanf("%d", &choice);
        getchar();

        if(choice == 1){
            show_status(&player);
        } else if(choice == 2){
            printf("이동할 맵을 선택하세요 :\n");
            for(int i = 0; i < map_count; i++){
                printf("%d. %s (레벨 %d 이상, 난이도 ", i + 1, maps[i].name, maps[i].min_level);
                for(int j = 0; j < maps[i].difficulty; j++) printf("★");
                printf(")\n");
            }
            printf(">> ");

            int map_choice;
            scanf("%d", &map_choice);
            getchar();

            if(map_choice < 1 || map_choice > map_count){
                printf("잘못된 선택입니다.\n");
                continue;
            }
            
            if(player.level < maps[map_choice - 1].min_level){
                printf("이 지역은 최소 레벨 %d 이상만 입장할 수 있습니다.", maps[map_choice - 1].min_level);
                continue;
            }

            Map *current_map = &maps[map_choice - 1];
            int result = encounter(&player,current_map);
            if(result == 0){
                printf("\n게임 오버\n");
                break;
            }
        } else if(choice == 3){
            player.hp = player.max_hp;
            printf("체력을 모두 회복했습니다!\n");
        }else if(choice == 4){
            use_item(&player);
        } else if(choice == 5){
            save_game(&player);
        }else if(choice == 6){
            printf("게임을 종료합니다.\n");
            break;
        } else{
            printf("잘못된 입력입니다.\n");
        }
    }

    cleanup(&player);
    return 0;
}
