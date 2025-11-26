#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVES 4
#define MAX_TEAM 3 // kita pakai 2, tapi biar fleksibel

// -------------------------------------------------
//  ENUM TYPE & UTILITAS
// -------------------------------------------------
typedef enum
{
    TYPE_NORMAL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC
} Type;

const char *typeName(Type t)
{
    switch (t)
    {
    case TYPE_NORMAL:
        return "Normal";
    case TYPE_FIRE:
        return "Fire";
    case TYPE_WATER:
        return "Water";
    case TYPE_GRASS:
        return "Grass";
    case TYPE_ELECTRIC:
        return "Electric";
    default:
        return "Unknown";
    }
}

// chart sangat disederhanakan
float typeEffectiveness(Type moveType, Type targetType)
{
    // super effective
    if (moveType == TYPE_FIRE && targetType == TYPE_GRASS)
        return 2.0f;
    if (moveType == TYPE_WATER && targetType == TYPE_FIRE)
        return 2.0f;
    if (moveType == TYPE_GRASS && targetType == TYPE_WATER)
        return 2.0f;
    if (moveType == TYPE_ELECTRIC && targetType == TYPE_WATER)
        return 2.0f;

    // not very effective
    if (moveType == TYPE_FIRE && targetType == TYPE_WATER)
        return 0.5f;
    if (moveType == TYPE_WATER && targetType == TYPE_GRASS)
        return 0.5f;
    if (moveType == TYPE_GRASS && targetType == TYPE_FIRE)
        return 0.5f;
    if (moveType == TYPE_ELECTRIC && targetType == TYPE_GRASS)
        return 0.5f;

    return 1.0f;
}

// -------------------------------------------------
//  STRUCT MOVE, POKEMON, TRAINER
// -------------------------------------------------
typedef struct
{
    char name[20];
    Type type;
    int power; // 0 = move non-damage (buff/debuff)
    int maxPP;
    int pp;
    int accuracy; // 1-100
} Move;

typedef struct
{
    char name[20];
    Type type;
    int maxHP;
    int hp;
    int attack;
    int defense;
    int speed;
    Move moves[MAX_MOVES];
} Pokemon;

typedef struct
{
    char name[20];
    Pokemon team[MAX_TEAM];
    int teamSize;
    int activeIndex; // index pokemon yang sedang bertarung
} Trainer;

// -------------------------------------------------
//  HELPER: STATUS & CEK
// -------------------------------------------------
int isAlive(const Pokemon *p)
{
    return p->hp > 0;
}

int hasAlivePokemon(const Trainer *t)
{
    for (int i = 0; i < t->teamSize; i++)
    {
        if (t->team[i].hp > 0)
            return 1;
    }
    return 0;
}

void printPokemon(const Pokemon *p)
{
    printf("%s (%s) HP: %d/%d ATK:%d DEF:%d SPD:%d\n",
           p->name, typeName(p->type),
           p->hp, p->maxHP,
           p->attack, p->defense, p->speed);
}

void printMoves(const Pokemon *p)
{
    for (int i = 0; i < MAX_MOVES; i++)
    {
        if (p->moves[i].power == 0 && p->moves[i].maxPP == 0)
            continue; // slot kosong
        printf("%d. %s [%s] Pow:%d PP:%d/%d Acc:%d%%\n",
               i + 1,
               p->moves[i].name,
               typeName(p->moves[i].type),
               p->moves[i].power,
               p->moves[i].pp,
               p->moves[i].maxPP,
               p->moves[i].accuracy);
    }
}

int allMovesOutOfPP(const Pokemon *p)
{
    for (int i = 0; i < MAX_MOVES; i++)
    {
        if (p->moves[i].power == 0 && p->moves[i].maxPP == 0)
            continue;
        if (p->moves[i].pp > 0)
            return 0;
    }
    return 1;
}

// -------------------------------------------------
//  INPUT MOVE (PLAYER & AI)
// -------------------------------------------------
int chooseMovePlayer(const Pokemon *p)
{
    int choice;
    while (1)
    {
        printf("Pilih jurus (1-%d): ", MAX_MOVES);
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // flush
            continue;
        }
        if (choice < 1 || choice > MAX_MOVES)
        {
            printf("Pilihan tidak valid.\n");
            continue;
        }
        Move *m = &((Pokemon *)p)->moves[choice - 1];
        if (m->maxPP == 0 && m->power == 0)
        {
            printf("Slot jurus kosong. Pilih yang lain.\n");
            continue;
        }
        if (m->pp <= 0)
        {
            printf("PP habis untuk jurus %s. Pilih yang lain.\n", m->name);
            continue;
        }
        return choice - 1;
    }
}

int chooseMoveAI(const Pokemon *p)
{
    int availableIndices[MAX_MOVES];
    int count = 0;

    for (int i = 0; i < MAX_MOVES; i++)
    {
        if (p->moves[i].maxPP == 0 && p->moves[i].power == 0)
            continue;
        if (p->moves[i].pp > 0)
        {
            availableIndices[count++] = i;
        }
    }

    if (count == 0)
        return -1;
    int r = rand() % count;
    return availableIndices[r];
}

// -------------------------------------------------
//  DAMAGE & PERFORM MOVE
// -------------------------------------------------
int calcDamage(const Pokemon *attacker,
               const Pokemon *defender,
               const Move *move)
{
    // simple-ish formula
    float atk = (float)attacker->attack;
    float def = (float)(defender->defense + 1);
    float base = (atk / def) * move->power + 5.0f;

    // random factor 0.85 - 1.00
    float randFactor = 0.85f + (float)(rand() % 16) / 100.0f;

    float typeMult = typeEffectiveness(move->type, defender->type);

    float dmgF = base * randFactor * typeMult;
    int dmg = (int)dmgF;
    if (dmg < 1)
        dmg = 1;
    return dmg;
}

void performMove(Pokemon *attacker,
                 Pokemon *defender,
                 int moveIndex)
{
    Move *m = &attacker->moves[moveIndex];

    if (m->maxPP == 0 && m->power == 0)
    {
        printf("%s tidak punya jurus di slot itu!\n", attacker->name);
        return;
    }
    if (m->pp <= 0)
    {
        printf("%s kehabisan PP untuk %s!\n", attacker->name, m->name);
        return;
    }

    printf("%s menggunakan %s!\n", attacker->name, m->name);

    // move non-damage (power 0) di sini cuma “kosong”
    if (m->power == 0)
    {
        printf("Tidak terjadi damage (move non-damage / dummy).\n");
        m->pp--;
        return;
    }

    // cek akurasi
    int roll = rand() % 100 + 1; // 1–100
    if (roll > m->accuracy)
    {
        printf("Serangan %s meleset!\n", m->name);
        m->pp--;
        return;
    }

    int dmg = calcDamage(attacker, defender, m);
    defender->hp -= dmg;
    if (defender->hp < 0)
        defender->hp = 0;
    m->pp--;

    printf("Serangan mengenai %s dan memberikan %d damage!\n",
           defender->name, dmg);

    float eff = typeEffectiveness(m->type, defender->type);
    if (eff > 1.0f)
    {
        printf("Itu sangat efektif!\n");
    }
    else if (eff < 1.0f)
    {
        printf("Tidak terlalu efektif...\n");
    }
}

// -------------------------------------------------
//  SWITCH POKEMON
// -------------------------------------------------
int chooseSwitchPlayer(const Trainer *t)
{
    printf("Pilih Pokemon untuk diganti:\n");
    for (int i = 0; i < t->teamSize; i++)
    {
        printf("%d. %s (HP %d/%d)%s\n",
               i + 1,
               t->team[i].name,
               t->team[i].hp,
               t->team[i].maxHP,
               (i == t->activeIndex ? " [Sedang bertarung]" : ""));
    }

    int choice;
    while (1)
    {
        printf("Pilihan: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        if (choice < 1 || choice > t->teamSize)
        {
            printf("Pilihan tidak valid.\n");
            continue;
        }
        if (choice - 1 == t->activeIndex)
        {
            printf("Pokemon itu sudah di lapangan, pilih yang lain.\n");
            continue;
        }
        if (t->team[choice - 1].hp <= 0)
        {
            printf("Pokemon itu sudah pingsan, pilih yang lain.\n");
            continue;
        }
        return choice - 1;
    }
}

int autoSwitchAI(const Trainer *t)
{
    for (int i = 0; i < t->teamSize; i++)
    {
        if (i == t->activeIndex)
            continue;
        if (t->team[i].hp > 0)
            return i;
    }
    return -1;
}

// -------------------------------------------------
//  BATTLE LOOP
// -------------------------------------------------
void battle(Trainer *player, Trainer *enemy)
{
    printf("\n--- Pertarungan dimulai! ---\n");
    printf("%s mengirim %s!\n", player->name,
           player->team[player->activeIndex].name);
    printf("%s mengirim %s!\n", enemy->name,
           enemy->team[enemy->activeIndex].name);

    while (hasAlivePokemon(player) && hasAlivePokemon(enemy))
    {
        Pokemon *pAct = &player->team[player->activeIndex];
        Pokemon *eAct = &enemy->team[enemy->activeIndex];

        printf("\nStatus:\n");
        printPokemon(pAct);
        printPokemon(eAct);

        // --- player pilih aksi ---
        int playerAction;
        printf("\nGiliran %s:\n", player->name);
        printf("1. Serang\n");
        printf("2. Ganti Pokemon\n");
        printf("Pilih aksi: ");
        if (scanf("%d", &playerAction) != 1)
        {
            while (getchar() != '\n')
                ;
            playerAction = 1;
        }

        int playerMoveIndex = -1;
        int playerSwitchIndex = -1;

        if (playerAction == 2 && player->teamSize > 1)
        {
            playerSwitchIndex = chooseSwitchPlayer(player);
        }
        else
        {
            if (allMovesOutOfPP(pAct))
            {
                printf("Semua jurus habis PP! Dipaksa pakai slot jurus 1.\n");
                playerMoveIndex = 0;
            }
            else
            {
                printf("Pilih jurus untuk %s:\n", pAct->name);
                printMoves(pAct);
                playerMoveIndex = chooseMovePlayer(pAct);
            }
        }

        // enemy pilih jurus (AI sangat sederhana)
        int enemyMoveIndex;
        if (allMovesOutOfPP(eAct))
        {
            enemyMoveIndex = 0;
        }
        else
        {
            enemyMoveIndex = chooseMoveAI(eAct);
        }

        // tentukan urutan (speed) kalau sama: player dulu
        int playerActsFirst = 1;
        if (playerSwitchIndex != -1)
        {
            playerActsFirst = 1; // switch selalu dilakukan sebelum diserang
        }
        else if (pAct->speed < eAct->speed)
        {
            playerActsFirst = 0;
        }

        // ------------ RESOLUSI GILIRAN ------------
        if (playerActsFirst)
        {
            // aksi player
            if (playerSwitchIndex != -1)
            {
                printf("%s menarik %s dan mengirim %s!\n",
                       player->name,
                       pAct->name,
                       player->team[playerSwitchIndex].name);
                player->activeIndex = playerSwitchIndex;
                pAct = &player->team[player->activeIndex];
            }
            else
            {
                performMove(pAct, eAct, playerMoveIndex);
            }

            // cek enemy pingsan
            if (eAct->hp <= 0)
            {
                printf("%s pingsan!\n", eAct->name);
                int next = autoSwitchAI(enemy);
                if (next == -1)
                {
                    printf("Semua Pokemon %s pingsan! %s menang!\n",
                           enemy->name, player->name);
                    return;
                }
                else
                {
                    enemy->activeIndex = next;
                    eAct = &enemy->team[enemy->activeIndex];
                    printf("%s mengirim %s berikutnya!\n",
                           enemy->name, eAct->name);
                }
            }

            // giliran enemy (kalau masih hidup)
            if (eAct->hp > 0)
            {
                performMove(eAct, pAct, enemyMoveIndex);
                if (pAct->hp <= 0)
                {
                    printf("%s pingsan!\n", pAct->name);
                    if (!hasAlivePokemon(player))
                    {
                        printf("Semua Pokemon %s pingsan! %s menang!\n",
                               player->name, enemy->name);
                        return;
                    }
                    printf("%s harus mengganti Pokemon!\n", player->name);
                    int idx = chooseSwitchPlayer(player);
                    player->activeIndex = idx;
                    pAct = &player->team[player->activeIndex];
                    printf("%s mengirim %s!\n",
                           player->name, pAct->name);
                }
            }
        }
        else
        {
            // enemy duluan
            performMove(eAct, pAct, enemyMoveIndex);
            if (pAct->hp <= 0)
            {
                printf("%s pingsan!\n", pAct->name);
                if (!hasAlivePokemon(player))
                {
                    printf("Semua Pokemon %s pingsan! %s menang!\n",
                           player->name, enemy->name);
                    return;
                }
                printf("%s harus mengganti Pokemon!\n", player->name);
                int idx = chooseSwitchPlayer(player);
                player->activeIndex = idx;
                pAct = &player->team[player->activeIndex];
                printf("%s mengirim %s!\n",
                       player->name, pAct->name);
            }

            // lalu aksi player (kalau masih hidup)
            if (pAct->hp > 0)
            {
                if (playerSwitchIndex != -1)
                {
                    printf("%s menarik %s dan mengirim %s!\n",
                           player->name,
                           pAct->name,
                           player->team[playerSwitchIndex].name);
                    player->activeIndex = playerSwitchIndex;
                }
                else
                {
                    performMove(pAct, eAct, playerMoveIndex);
                }
                if (eAct->hp <= 0)
                {
                    printf("%s pingsan!\n", eAct->name);
                    int next = autoSwitchAI(enemy);
                    if (next == -1)
                    {
                        printf("Semua Pokemon %s pingsan! %s menang!\n",
                               enemy->name, player->name);
                        return;
                    }
                    else
                    {
                        enemy->activeIndex = next;
                        printf("%s mengirim %s berikutnya!\n",
                               enemy->name,
                               enemy->team[next].name);
                    }
                }
            }
        }
    }
}

// -------------------------------------------------
//  BUILDER POKEMON
// -------------------------------------------------
Pokemon makeBulbasaur(void)
{
    Pokemon p;
    strcpy(p.name, "Bulbasaur");
    p.type = TYPE_GRASS;
    p.maxHP = 60;
    p.hp = 60;
    p.attack = 11;
    p.defense = 10;
    p.speed = 10;

    p.moves[0] = (Move){"Tackle", TYPE_NORMAL, 8, 35, 35, 95};
    p.moves[1] = (Move){"Vine Whip", TYPE_GRASS, 14, 25, 25, 95};
    p.moves[2] = (Move){"Razor Leaf", TYPE_GRASS, 18, 15, 15, 90};
    p.moves[3] = (Move){"Growl", TYPE_NORMAL, 0, 40, 40, 100}; // dummy

    return p;
}

Pokemon makeCharmander(void)
{
    Pokemon p;
    strcpy(p.name, "Charmander");
    p.type = TYPE_FIRE;
    p.maxHP = 55;
    p.hp = 55;
    p.attack = 13;
    p.defense = 9;
    p.speed = 13;

    p.moves[0] = (Move){"Scratch", TYPE_NORMAL, 9, 35, 35, 95};
    p.moves[1] = (Move){"Ember", TYPE_FIRE, 15, 25, 25, 95};
    p.moves[2] = (Move){"Flame Burst", TYPE_FIRE, 20, 15, 15, 90};
    p.moves[3] = (Move){"Growl", TYPE_NORMAL, 0, 40, 40, 100};

    return p;
}

Pokemon makeSquirtle(void)
{
    Pokemon p;
    strcpy(p.name, "Squirtle");
    p.type = TYPE_WATER;
    p.maxHP = 65;
    p.hp = 65;
    p.attack = 11;
    p.defense = 13;
    p.speed = 9;

    p.moves[0] = (Move){"Tackle", TYPE_NORMAL, 8, 35, 35, 95};
    p.moves[1] = (Move){"Water Gun", TYPE_WATER, 14, 25, 25, 95};
    p.moves[2] = (Move){"Bubble", TYPE_WATER, 12, 30, 30, 100};
    p.moves[3] = (Move){"Tail Whip", TYPE_NORMAL, 0, 30, 30, 100};

    return p;
}

Pokemon makePikachu(void)
{
    Pokemon p;
    strcpy(p.name, "Pikachu");
    p.type = TYPE_ELECTRIC;
    p.maxHP = 50;
    p.hp = 50;
    p.attack = 14;
    p.defense = 8;
    p.speed = 16;

    p.moves[0] = (Move){"Quick Attack", TYPE_NORMAL, 10, 30, 30, 100};
    p.moves[1] = (Move){"Thunder Shock", TYPE_ELECTRIC, 14, 25, 25, 95};
    p.moves[2] = (Move){"Spark", TYPE_ELECTRIC, 18, 15, 15, 90};
    p.moves[3] = (Move){"Growl", TYPE_NORMAL, 0, 40, 40, 100};

    return p;
}

// -------------------------------------------------
//  MAIN
// -------------------------------------------------
int main(void)
{
    srand((unsigned int)time(NULL));

    Trainer player;
    strcpy(player.name, "Player");
    player.teamSize = 0;
    player.activeIndex = 0;

    Trainer enemy;
    strcpy(enemy.name, "Rival");
    enemy.teamSize = 0;
    enemy.activeIndex = 0;

    // pool pokemon
    Pokemon pool[4];
    pool[0] = makeBulbasaur();
    pool[1] = makeCharmander();
    pool[2] = makeSquirtle();
    pool[3] = makePikachu();

    printf("=== Pokemon Battle (C, versi lebih kompleks) ===\n");
    printf("Pilih 2 Pokemon untuk tim kamu:\n");

    int chosen[4] = {0};

    for (int pick = 0; pick < 2; pick++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!chosen[i])
            {
                printf("%d. %s (%s)\n",
                       i + 1, pool[i].name, typeName(pool[i].type));
            }
        }
        int c;
        printf("Pilihan ke-%d: ", pick + 1);
        if (scanf("%d", &c) != 1)
        {
            while (getchar() != '\n')
                ;
            pick--;
            continue;
        }
        if (c < 1 || c > 4 || chosen[c - 1])
        {
            printf("Pilihan tidak valid atau sudah dipilih.\n");
            pick--;
            continue;
        }
        player.team[player.teamSize++] = pool[c - 1];
        chosen[c - 1] = 1;
    }

    // musuh ambil 2 sisa
    for (int i = 0; i < 4 && enemy.teamSize < 2; i++)
    {
        if (!chosen[i])
        {
            enemy.team[enemy.teamSize++] = pool[i];
        }
    }

    printf("\nTim kamu:\n");
    for (int i = 0; i < player.teamSize; i++)
    {
        printPokemon(&player.team[i]);
    }

    printf("\nTim lawan:\n");
    for (int i = 0; i < enemy.teamSize; i++)
    {
        printPokemon(&enemy.team[i]);
    }

    battle(&player, &enemy);

    printf("\nTerima kasih sudah bermain!\n");
    return 0;
}
