#ifndef BUILDMAP
#define BUILDMAP

#include "main.h"


void buildLine(int mode, Map ** screen,int coordX, int coordY, int size)
{
     if(mode == 1)
     {
            for (int i = coordX; i < (coordX + size); i++)
               screen[coordY][i].value = 1;
     }  // HORIZONTAL
        
    else if(mode == 2)
    {
            for (int i = coordY; i < (coordY + size); i++)
                screen[i][coordX].value = 1;
    } // VERTICAL

    else
    {
            screen[coordX][coordY].value = 5;
    }
    
}


void buildSquare(Map ** map, int coordY, int coordX, int coordY_, int coordX_, int value)
{
    int lenght = coordX_ - coordX;
    int height = coordY_ - coordY;
    int biggest = (height>lenght)?height:lenght;
    for(float i=0; i<=biggest; i++)
    {
        map[coordY + (int)((i/biggest)*height)][coordX].value = value;
        map[coordY_ - (int)((i/biggest)*height)][coordX_].value = value;
        map[coordY][coordX + (int)((i/biggest)*lenght)].value = value;
        map[coordY_][coordX_ - (int)((i/biggest)*lenght)].value = value;
    }
}




void buildHole(Map** map, int coordUpY, int coordUpX)
{
    const int lenght = 3;
    
    for(int i=0; i<lenght; i++)
    {
        map[coordUpY+i][coordUpX].value = HOLE;
        map[coordUpY+i][coordUpX+ (lenght-2)].value = HOLE;
        map[coordUpY+i][coordUpX+ (lenght-1)].value = HOLE;
    }

}




void resetScreen(MapData * mapData)
{
    for(int i=0; i<mapData->rows; i++)
        for(int j=0; j<mapData->collums; j++)
            mapData->map[i][j].value = 0;
}



void fightScreenConstruct(Map **screen)
{

    //first message box 
    buildLine(1,screen,2,1,30);
    buildLine(1,screen,2,9,34);
    buildLine(2,screen,2,1,8);
    buildLine(2,screen,32,1,9);

    // second message box
    buildLine(1, screen, 46, 25, 30);
    buildLine(1, screen, 43, 33, 33);
    buildLine(2, screen, 46, 25, 8);
    buildLine(2, screen, 76, 25, 9);

    //big rectangle below
    buildLine(1,screen,0,35,79);
    buildLine(1,screen,0,62,79);
    buildLine(2,screen,0,36,26);
    buildLine(2,screen,78,36,26);


    // buildLine(2,screen,2,37,24);
    // buildLine(2,screen,31,37,24); 
    // buildLine(1,screen,2,37,29);
    // buildLine(1,screen,2,60,29);



    //MOLDE
        buildSquare(screen, 37,33,60,76,1);
        buildLine(1,screen, 34,49,42);
        buildLine(1,screen, 34,48,42);
        buildLine(2,screen, 55,37,23);


    //QUADRANTES
        //1/4
            // buildSquare(screen,37,33,48,54,1);
    //WHAT
            buildLine(2,screen, 2, 39, 8);
            buildLine(1,screen, 2, 46, 2);
            buildLine(2,screen, 4, 43, 4);
            buildLine(1,screen, 4, 46, 2);
            buildLine(2,screen, 6, 39, 8);

            buildLine(2,screen, 8, 39, 8);
            buildLine(1,screen, 8, 42, 2);
            buildLine(2,screen, 10, 39, 8);

            buildLine(2,screen, 12, 39, 8);
            buildLine(1,screen, 12, 39, 2);
            buildLine(2,screen, 14, 39, 8);
            buildLine(1,screen, 12, 42, 2);
            
            buildLine(1,screen, 16, 39, 3);
            buildLine(2,screen, 17, 39, 8);

    //WILL
            buildLine(2,screen, 20, 39, 8);
            buildLine(1,screen, 20, 46, 2);
            buildLine(2,screen, 22, 43, 4);
            buildLine(1,screen, 22, 46, 2);
            buildLine(2,screen, 24, 39, 8);
            
            buildLine(2,screen, 26, 40, 7);

            buildLine(2,screen, 28, 39, 8);
            buildLine(1,screen, 28, 46, 2);
            
            buildLine(2,screen, 31, 39, 8);
            buildLine(1,screen, 31, 46, 2);
            
    //DO
            buildLine(2,screen, 20, 52, 7);
            buildLine(1,screen, 20, 51, 2);
            buildLine(2,screen, 22, 51, 1);
            buildLine(1,screen, 22, 52, 1);
            buildLine(2,screen, 23, 52, 7);
            buildLine(1,screen, 22, 58, 1);
            buildLine(2,screen, 22, 59, 1);
            buildLine(1,screen, 20, 59, 2);

            buildLine(2,screen, 27, 51, 8);
            buildLine(2,screen, 25, 51, 8);
            buildLine(1,screen, 25, 59, 3);
            buildLine(1,screen, 25, 51, 2);

            
            buildLine(2,screen, 29, 50, 3);
            buildLine(1,screen, 29, 50, 2);
            buildLine(2,screen, 31, 50, 5);
            buildLine(1,screen, 29, 54, 2);
            buildLine(2,screen, 29, 54, 4);
            buildLine(2,screen, 29, 60, 1);//Cristian arruma

            


        //2/4
            // buildSquare(screen,37,55,48,76,1);
        //3/4
            // buildSquare(screen,49,33,60,54,1);
        //4/4
            // buildSquare(screen,49,55,60,76,1);

    //FIGHT
        //F
            buildLine(1,screen,35,39,2);
            buildLine(2,screen,35,40,7);
            buildLine(1,screen,36,43,1);
        //I
            buildLine(2,screen,38,40,7);
        //G
            buildLine(1,screen,40,39,4);
            buildLine(1,screen,41,46,4);
            buildLine(1,screen,42,43,2);
            buildLine(2,screen,40,40,7);
            buildLine(2,screen,44,43,4);
        //H
            buildLine(2,screen,46,39,8);
            buildLine(2,screen,48,39,8);
            buildLine(2,screen,47,43,1);
        //T
            buildLine(1,screen,50,39,3);
            buildLine(2,screen,51,40,7);

    //RUN
        //R
            buildLine(2,screen,59,52,7);

            buildLine(1,screen,59,51,4);
            buildLine(1,screen,61,54,2);
            buildLine(2,screen,62,52,2);
            
            buildLine(2,screen,61,54,5);
            buildLine(1,screen,60,58,1);
            // buildLine(2,screen,61,56,1);
        //U
            buildLine(2,screen,64,51,8);
            buildLine(2,screen,67,51,8);
            buildLine(1,screen,65,58,2);
        //N
            buildLine(2,screen,69,51,8);
            buildLine(2,screen,73,51,8);

            buildLine(1,screen,70,51,2);
            
            buildLine(2,screen,71,52,7);

            buildLine(1,screen,72,58,2);

    //BAG

            buildLine(2,screen, 59, 40, 6);
            buildLine(2,screen, 62, 40, 6);
            buildLine(1,screen, 59, 46, 3);
            buildLine(1,screen, 59, 39, 3);
            buildLine(1,screen, 61, 43, 1);

            buildLine(2,screen, 64, 39, 7);
            buildLine(1,screen, 64, 39, 3);
            buildLine(2,screen, 67, 39, 7);
            buildLine(1,screen, 64, 42, 3);

            buildLine(2,screen, 69, 39, 7);
            buildLine(1,screen, 69, 39, 3);
            buildLine(1,screen, 69, 46, 4);
            buildLine(2,screen, 72, 44, 2);
            buildLine(1,screen, 71, 43, 2);

    //POKE

            buildLine(2,screen, 35 , 52, 6);
            buildLine(2,screen, 38, 51, 3);
            buildLine(1,screen, 35, 54, 4);
            buildLine(1,screen, 35, 51, 3);

            buildLine(2,screen, 40, 51, 7);
            buildLine(1,screen, 40, 51, 3);
            buildLine(2,screen, 43, 51, 7);
            buildLine(1,screen, 40, 58, 4);

            buildLine(2,screen, 45, 52, 7);
            buildLine(1,screen, 45, 56, 4);
            buildLine(2,screen, 47, 52, 4);
            buildLine(2,screen, 48, 56, 3);


            buildLine(2,screen, 50, 51, 7);
            buildLine(1,screen, 50, 51, 3);
            buildLine(1,screen, 50, 55, 3);
            buildLine(1,screen, 50, 58, 3);

            //Bulbasaur
            screen[0][53].entity = "                           ,'           \\  | \\";
            screen[1][53].entity = "                         /             | |   \\";
            screen[2][53].entity = "       _   \\  `. ---.   |                | j    |";
            screen[3][53].entity = "      / `-._\\   `Y   \\  |                |.     |";
            screen[4][53].entity = "     _`.    ``    \\   \\ |..              '      |,-'''7,...";
            screen[5][53].entity = "     l     '-.     . , `|  | , |`. , ,  /,     ,'    '/   ,'_,.-.";
            screen[6][53].entity = "     `-..     `-.  : :     |/ `   ' '\\,' | _  /          '-'    /___";
            screen[7][53].entity = "      \\''' __.,.-`.: :        /   /._    l'.,'";
            screen[8][53].entity = "       ,---..._,.--'''''''--.__..----,-.'   .  /    .'   ,.--";
            screen[9][53].entity = "       |                          ,':| /    | /     ;.,-'--      ,.-";
            screen[10][53].entity = "       |     .---.              .'  :|'     |/ ,.-=''-.`'`' _   -.'";
            screen[11][53].entity = "       /    \\    /               `. :|--.  _L,'---.._        '----'";
            screen[12][53].entity = "     ,' `.   \\ ,'           _,     `''   ``.-'       `-  -..___,";
            screen[13][53].entity = "    . ,.  .   `   __     .-'  _.-           `.     .__    \\";
            screen[14][53].entity = "    |. |`        '  ;   !   ,.  |             `.    `.`'---";
            screen[15][53].entity = "    ,| |C\\       ` /    | ,' |(]|            -. |-..--`";
            screen[16][53].entity = "   /  ''--'       '      /___|__]        `.  `- |`";
            screen[17][53].entity = "  .       ,'                   ,   /       .    `. \\";
            screen[18][53].entity = "    \\                      .,-'  ,'         .     `-.";
            screen[19][53].entity = "     x---..`.  -'  __..--''/''''  ,-.      |   |   |";
            screen[20][53].entity = "    / \\--._'-.,.--'     _`-    _. ' /       |     -.|";
            screen[21][53].entity = "  .  _,'         ''-----''      |    `   | /  ,'    ;";
            screen[22][53].entity = "  |-'  .-.    `._               |     `._// ,'     /";
            screen[23][53].entity = " _|    `-'   _,' '`--.._________|        `,'    _ /.";
            screen[24][53].entity = "//\\   ,-._.''/\\__,.   _,'     /_\\__/`. /'.-.'.-/_,`-'";

            screen[0][53].value = MESSAGE;
            screen[1][53].value = MESSAGE;
            screen[2][53].value = MESSAGE;
            screen[3][53].value = MESSAGE;
            screen[4][53].value = MESSAGE;
            screen[5][53].value = MESSAGE;
            screen[6][53].value = MESSAGE;
            screen[7][53].value = MESSAGE;
            screen[8][53].value = MESSAGE;
            screen[9][53].value = MESSAGE;
            screen[10][53].value = MESSAGE;
            screen[11][53].value = MESSAGE;
            screen[12][53].value = MESSAGE;
            screen[13][53].value = MESSAGE;
            screen[14][53].value = MESSAGE;
            screen[15][53].value = MESSAGE;
            screen[16][53].value = MESSAGE;
            screen[17][53].value = MESSAGE;
            screen[18][53].value = MESSAGE;
            screen[19][53].value = MESSAGE;
            screen[20][53].value = MESSAGE;
            screen[21][53].value = MESSAGE;
            screen[22][53].value = MESSAGE;
            screen[23][53].value = MESSAGE;
            screen[24][53].value = MESSAGE;
            // Charizard
            screen[10][7].entity = "                 `. ' ' `.  ,";
            screen[11][7].entity = "              .--'  . _  '-' `.";
            screen[12][7].entity = "               `  '--.   ,-''";
            screen[13][7].entity = "                `'`   |  \\";
            screen[14][7].entity = "                   -. \\, |";
            screen[15][7].entity = "                    `--Y.'      __.";
            screen[16][7].entity = "                         \\     L._, \\";
            screen[17][7].entity = "               _.,        `.   <  <\\ \\               ";
            screen[18][7].entity = "             ,' '           `, `.   | \\            (;";
            screen[19][7].entity = "          ../, `:            `  |    .\\`.           \\ \\_";
            screen[20][7].entity = "         ,' ,..  .           _.,'    ||\\|            )  ''.";
            screen[21][7].entity = "        , ,'   \\  :        ,'.-.`-._,'  |           .  _._`";
            screen[22][7].entity = "      ,' /      \\ :      `' ' `--/   | \\          / /   ..\\";
            screen[23][7].entity = "    .'  /        \\ ;         |\\__ - _ ,'` `        / /     `.`";
            screen[24][7].entity = "    |  '          ..         `-...-'  |  `-'      / /        . `.";
            screen[25][7].entity = "    | /           |L__           |    |          / /          `. `.";
            screen[26][7].entity = "   , /            .   .          |    |         / /             ` `";
            screen[27][7].entity = " / /          ,. ,`._ `-_        |    | _   ,-' /               ` \\";
            screen[28][7].entity = ".  '         .-f    ,'   `    '.       \\__.---'     _   .' ' `     \\";
            screen[29][7].entity = "' /     . . .`.'    l     .' /          \\..      ,_|/   `.  ,'`     L\\";
            screen[30][7].entity = "||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|";
            screen[31][7].entity = "||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||";
            screen[32][7].entity = "|| '              V      / /           :   | `   ,'   ,' '.    !  `. ||";
            screen[33][7].entity = "||/            _,-------7 '             :  |  `-'    l         /    `||";
            screen[34][7].entity = " `'        ,'    `'.'    |               |    `.        '. -.'       `'";
        
            screen[33][7].value = MESSAGE;
            screen[34][7].value = MESSAGE;
            screen[32][7].value = MESSAGE;
            screen[31][7].value = MESSAGE;
            screen[30][7].value = MESSAGE;
            screen[29][7].value = MESSAGE;
            screen[28][7].value = MESSAGE;
            screen[27][7].value = MESSAGE;
            screen[26][7].value = MESSAGE;
            screen[25][7].value = MESSAGE;
            screen[24][7].value = MESSAGE;
            screen[23][7].value = MESSAGE;
            screen[22][7].value = MESSAGE;
            screen[21][7].value = MESSAGE;
            screen[20][7].value = MESSAGE;
            screen[19][7].value = MESSAGE;
            screen[17][7].value = MESSAGE;
            screen[18][7].value = MESSAGE;
            screen[15][7].value = MESSAGE;
            screen[16][7].value = MESSAGE;
            screen[14][7].value = MESSAGE;
            screen[13][7].value = MESSAGE;
            screen[12][7].value = MESSAGE;
            screen[11][7].value = MESSAGE;
            screen[10][7].value = MESSAGE;
}


#endif 