#include "bibliotecas/biblio.h"

int main()
{
    Bag *bag = bagConstructor();

    Team me = myTeamConstructor();

    Team enemy = teamConstructor();

    battle(&me, &enemy, bag);
}