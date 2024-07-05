#ifndef MAIN_H
#define MAIN_H

#include "buildMap.h"
#include "stack.h"
#include "renderValues.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "keycodes.h"
#include "team.h"
#include "battle.h"



// Struct para o inimigo
typedef struct
{
    int renderValue;
    int eY;
    int eX;
    Team team;
} Enemy;

// struct de dados do player
typedef struct 
{
    int pX;
    int pY;
    int renderValue;
    Map lastCoord;
    Team team;
    void * currentEntity;
    int checkAct;

} Player;

// struct que contém os valores de renderização
typedef struct 
{
    int renderWall;
    int renderPokeball;
    int renderEnemy;
    int renderHole;
    int renderStep;
    int renderWallColorSecond;
} Objects;

// struct para gerenciamento de telas 
typedef struct 
{
    int Map;
    int SecondMap;
    int Fight;
} ScreenModes;

// struct principal com todas as informações do jogo
struct Room
{
    Stack stackEvents;
    MapData mapScreen;
    MapData secondMapScreen;
    MapData fightScreen;
    MapData attackScreen;
    MapData bagScreen;
    MapData bagUseScreen;
    MapData PokeScreen;

    
    Objects objects;
    Player player;
    Player actions;
    ScreenModes screenModes;
};





// inicialização dos modos da tela. O primeiro mapa ja inicia ligado
ScreenModes screenModesInnit()
{
    ScreenModes screenModes;
    screenModes.Fight = 0;
    screenModes.Map = 1;
    screenModes.SecondMap = 0;

    return screenModes;
}

// inicialização dos valores do player com base nos parâmetros
Player playerInnit(int renderValue, int y, int x)
{
    Player player;
    player.pX = x;
    player.pY = y;
    player.renderValue = renderValue;
    player.lastCoord.value = 0;
    player.checkAct = 0;


    return player;
}

// incialização dos valores de renderização
Objects objectsInnit(int renderPokeball, int renderEnemy, int wall, int hole, int step)
{
    Objects objects;
    objects.renderPokeball = renderPokeball;
    objects.renderWall = wall;
    objects.renderEnemy = renderEnemy;
    objects.renderHole = hole;
    objects.renderStep = step;
    objects.renderWallColorSecond = 0; 

    return objects;
}

// função para inicializar os mapas que serão utilzados
Map** mapInnit(int rows, int collums)
{
    Map **map = malloc(rows * sizeof(Map*));
    for(int i=0; i<rows; i++)
    {
        map[i] = malloc(collums * sizeof(Map));
        for(int j=0; j<collums; j++)
            map[i][j].value = 0;
    }

    return map;
}

// função para atribuir os dados dos mapas
MapData mapDataInnit(int rows, int collums)
{
    MapData mapData;
    mapData.collums = collums;
    mapData.rows = rows;
    mapData.map = mapInnit(rows,collums);
    mapData.screenUpdated = 1;

    return mapData;
}

// inicializador da matriz que servirá para caixas de seleção
Options ** matrizOptionsInnit(int rows, int collums)
{
    Options ** options = malloc(rows * sizeof(Options*));
    for(int i=0; i<rows; i++)
        options[i] = malloc(collums * sizeof(Options));
    
    return options;
}

// inicializador de struct que contém os dados da caixa de seleção
SelectOptions selectOptionsInnit(int rows, int collums)
{
    SelectOptions selectOptions;
    selectOptions.rows = rows;
    selectOptions.collums = collums;
    return selectOptions;
}

// inicializador do menu padrão com as coordenadas das caixas de seleção
Options ** menuInnit()
{
    Options ** options = matrizOptionsInnit(2,2);
    

    options[0][0].optY = 37;
    options[0][0].optX = 33;
    options[0][0].optY_ = 48;
    options[0][0].optX_ = 54;

    options[0][1].optY = 37;
    options[0][1].optX = 55;
    options[0][1].optY_ = 48;
    options[0][1].optX_ = 76;

    options[1][0].optY = 49;
    options[1][0].optX = 33;
    options[1][0].optY_ = 60;
    options[1][0].optX_ = 54;

    options[1][1].optY = 49;
    options[1][1].optX = 55;
    options[1][1].optY_ = 60;
    options[1][1].optX_ = 76;


    //Os valores a cima se referem as coordenadas de cada quadrado de seleção que será apresenado no terminal
    // é utilizado uma função para imprimi-los que pede a coordenada de começo do retângulo e de final, então aqui atribuimos cada uma


    return options;
}






// Função para gerar um oponente no mapa
void spawnEnemy(Map** map, int renderValue, int y, int x)
{
    Enemy * enemy = malloc(sizeof(Enemy));
    enemy->renderValue = renderValue;
    enemy->eY = y;
    enemy->eX = x;
    enemy->team = teamConstructor();

    map[y][x].value = renderValue;
    map[y][x].entity = enemy;
    
}

// Função para a conversão de 'int' para 'char'. Para renderizar precisa ser 'char'
char *intToStr(int num) {

    char *str = (char *)malloc(12 * sizeof(char)); 

    sprintf(str, "%d", num);

    return str;
}

// construtor da matriz que mostra os ataques
void attackScreenConstructor(Room * game)
{

    fightScreenConstruct(game->attackScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);
    
     //1/4
        buildFullSquare(game->attackScreen.map,38,34,47,53,0);
    //2/4
        buildFullSquare(game->attackScreen.map,38,56,47,77,0);
    //3/4
        buildFullSquare(game->attackScreen.map,50,34,59,53,0);
    //4/4
        buildFullSquare(game->attackScreen.map,50,56,59,75,0);



    game->attackScreen.map[42][42].entity = game->player.team.pokes[0].atk[0].name;     
    game->attackScreen.map[42][42].value = MESSAGE;
    game->attackScreen.map[46][52].entity = intToStr(game->player.team.pokes[0].atk[0].uses);
    game->attackScreen.map[46][52].value = MESSAGE;


    game->attackScreen.map[42][64].entity = game->player.team.pokes[0].atk[1].name;
    game->attackScreen.map[42][64].value = MESSAGE;
    game->attackScreen.map[46][74].entity = intToStr(game->player.team.pokes[0].atk[1].uses);
    game->attackScreen.map[46][74].value = MESSAGE;


    game->attackScreen.map[54][42].entity = game->player.team.pokes[0].atk[2].name;
    game->attackScreen.map[54][42].value = MESSAGE;
    game->attackScreen.map[58][52].entity = intToStr(game->player.team.pokes[0].atk[2].uses);
    game->attackScreen.map[58][52].value = MESSAGE;


    game->attackScreen.map[54][64].entity = game->player.team.pokes[0].atk[3].name;
    game->attackScreen.map[54][64].value = MESSAGE;
    game->attackScreen.map[58][74].entity = intToStr(game->player.team.pokes[0].atk[3].uses);
    game->attackScreen.map[58][74].value = MESSAGE;

}

// construtor da matriz que mostra os pokemons para realizar a troca
void PokeConstructor(Room * game)
{
    fightScreenConstruct(game->PokeScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);
    
     //1/4
        buildFullSquare(game->PokeScreen.map,38,34,47,53,0);
    //2/4
        buildFullSquare(game->PokeScreen.map,38,56,47,77,0);
    //3/4
        buildFullSquare(game->PokeScreen.map,50,34,59,53,0);
    //4/4
        buildFullSquare(game->PokeScreen.map,50,56,59,75,0);



    game->PokeScreen.map[42][42].entity = game->player.team.pokes[0].name;     
    game->PokeScreen.map[42][42].value = MESSAGE;

    game->PokeScreen.map[42][64].entity = game->player.team.pokes[1].name;
    game->PokeScreen.map[42][64].value = MESSAGE;

    game->PokeScreen.map[54][42].entity = game->player.team.pokes[2].name;
    game->PokeScreen.map[54][42].value = MESSAGE;

    game->PokeScreen.map[54][64].entity = game->player.team.pokes[3].name;
    game->PokeScreen.map[54][64].value = MESSAGE;
}

// função para executar o resultado de uma caixa de seleção
void selectOptionFight(Room * game, int option)
{   
    if(game->player.team.alive == 'd' || ((Enemy *)game->player.currentEntity)->team.alive == 'd')                 // verifica se a batalha acabou ou não
    {
        pop(&game->stackEvents);
        game->screenModes.Fight = 0;
        game->objects.renderWallColorSecond = 0;
        return;
    }
    
    switch (option)
    {
    case 0:

        
        game->actions = playerInnit(0,0,0);

        resetScreen(&game->fightScreen);
        attackScreenConstructor(game);
        push(&game->stackEvents, &game->attackScreen);
        Sleep(100);
        
        break;
    case 1:
        
        break;
    case 2:
        game->actions = playerInnit(0,0,0);
        resetScreen(&game->fightScreen);
        PokeConstructor(game);
        push(&game->stackEvents, &game->PokeScreen);
        Sleep(100);
        
        break;
    case 3:
        resetScreen(&game->fightScreen);
        pop(&game->stackEvents);
        game->screenModes.Fight = 0;
        game->screenModes.Map = 1;
        
        Sleep(100);
        break;
    
    default:
        break;
    }
}

// função para executar o resultado de uma caixa de seleção
void selectOptionAttack(Room * game, int option)
{
    if(GetAsyncKeyState(VK_ESC))
    {
        resetScreen(&game->attackScreen);
        fightScreenConstruct(game->fightScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);
        pop(&game->stackEvents);
    }

    if(option != -1 && game->player.team.pokes[0].atk[option].uses)
    {
        int dmg = atack(&game->player.team, &((Enemy*)game->player.currentEntity)->team, option);


        buildFullSquare(game->fightScreen.map, 37,2, 60, 20, 0);
        

        fightScreenConstruct(game->fightScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);
        game->fightScreen.map[46][6].entity = game->player.team.pokes[0].name;
        game->fightScreen.map[46][6].value = MESSAGE;
        game->fightScreen.map[46][13].entity = "used";
        game->fightScreen.map[46][13].value = MESSAGE;
        game->fightScreen.map[46][16].entity = game->player.team.pokes[0].atk[option].name;
        game->fightScreen.map[46][16].value = MESSAGE;




        if(dmg == 0.5)
        {
            game->fightScreen.map[50][9].entity = "it's not much effective..";
            game->fightScreen.map[50][9].value = MESSAGE;
        }
        else if(dmg == 2)
        {
            game->fightScreen.map[50][9].entity = "it's super effective !";
            game->fightScreen.map[50][9].value = MESSAGE;
        }
        else if(dmg == 0)
        {
            game->fightScreen.map[50][9].entity = "it's NULL !";
            game->fightScreen.map[50][9].value = MESSAGE;
        }
        else if(dmg == 1)
        {
            game->fightScreen.map[50][9].entity = "it's a normal attack";
            game->fightScreen.map[50][9].value = MESSAGE;
        }
        
        
        


        game->actions = playerInnit(0,0,0);
        game->player.checkAct = 1;
        resetScreen(&game->attackScreen);
        pop(&game->stackEvents);
    }
}


// Nossa batalha leva em consideração o primeiro Pokémon do Array de Pokémons
// Essa função altera o Pokémon 'Ativo'
void switchPoke(Room * game, int index)
{
    if(GetAsyncKeyState(VK_ESC))
    {
        resetScreen(&game->PokeScreen);
        fightScreenConstruct(game->fightScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);
        pop(&game->stackEvents);
    }
    Pokemon aux;

    if(index != -1 && game->player.team.pokes[index].hp > 0 && GetAsyncKeyState(VK_ENTER))
    {
        aux = game->player.team.pokes[0];
        game->player.team.pokes[0] = game->player.team.pokes[index];
        game->player.team.pokes[index] = aux;
        game->player.checkAct = 1;
        resetScreen(&game->PokeScreen);
        pop(&game->stackEvents);
        fightScreenConstruct(game->fightScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);
    }

}


void enemyRound(Room * game, Team * you, Team * enemy)
{   

    Sleep(4000);    
    
    srand(time(NULL));

    resetScreen(&game->fightScreen);
    fightScreenConstruct(game->fightScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);

    srand(time(NULL));
    int mult;
    int indexAtack;

    do{
        indexAtack =  rand()%4;
        mult = atack(enemy, you, indexAtack);
    } while (!enemy->pokes[0].atk[indexAtack].uses);

    game->fightScreen.map[46][6].entity = enemy->pokes[0].name;
    game->fightScreen.map[46][6].value = MESSAGE;
    game->fightScreen.map[46][13].entity = "used";
    game->fightScreen.map[46][13].value = MESSAGE;
    game->fightScreen.map[46][16].entity = game->player.team.pokes[0].atk[indexAtack].name;
    game->fightScreen.map[46][16].value = MESSAGE;


     if(mult == 0.5)
    {
        game->fightScreen.map[50][9].entity = "it's not much effective..";
        game->fightScreen.map[50][9].value = MESSAGE;
    }
    else if(mult == 2)
    {
        game->fightScreen.map[50][9].entity = "it's super effective !";
        game->fightScreen.map[50][9].value = MESSAGE;
    }
    else if(mult == 0)
    {
        game->fightScreen.map[50][9].entity = "it's NULL !";
        game->fightScreen.map[50][9].value = MESSAGE;
    }
    else if(mult == 1)
    {
        game->fightScreen.map[50][9].entity = "it's a normal attack";
        game->fightScreen.map[50][9].value = MESSAGE;
    }

    game->player.checkAct = 0;

    Sleep(4000);
}








// inicializador do jogo inteiro
Room gameInnit(int rows, int collums, Player player,Objects objects)
{
    Room map;
    map.player = player;


    map.objects = objects;
    map.screenModes = screenModesInnit();

    map.mapScreen = mapDataInnit(rows,collums);
    map.secondMapScreen = mapDataInnit(rows,collums);

    map.fightScreen = mapDataInnit(rows,collums);
    map.fightScreen.selectOptions = selectOptionsInnit(2,2);
    map.fightScreen.selectOptions.options = menuInnit();
    map.fightScreen.func = selectOptionFight;


    map.attackScreen = mapDataInnit(rows, collums);
    map.attackScreen.selectOptions = selectOptionsInnit(2,2);
    map.attackScreen.selectOptions.options = menuInnit();
    map.attackScreen.func = selectOptionAttack;


    map.PokeScreen = mapDataInnit(rows,collums);
    map.PokeScreen.selectOptions = selectOptionsInnit(2,2);
    map.PokeScreen.selectOptions.options = menuInnit();
    map.PokeScreen.func = switchPoke;


    map.stackEvents = constructor_list();

    return map;
}









#endif //MAIN_H