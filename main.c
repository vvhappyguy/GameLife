#include "main.h"

int setup(size_t _level)
{
    initLog(_level);
    putLog("SETUP:\n",0);

    putLog("\n",0);
    return 0;
}


int main()
{
    if(setup(3) != 0)
        exit(1);

    printf("\n\nGAME1:\n");
    Game* game = initGame(5);
    randomMap(game);
    updateMap(game);
    saveGame(game,"1.template");
    endGame(game);

    printf("\n\nGAME2:\n");

    Game* game2 = initGame(5);
    loadGame(game2, "1.te"
                    "mplate");
    updateMap(game2);
    stepGame(game2);
    endGame(game2);

    stopLog();

    system("pause");
    return 0;
}