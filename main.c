#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "logging.h"
#include "game.h"
#include <time.h>

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

    Game* game = initGame(3);
    randomMap(game);
    simpleShow(game);
    endGame(game);
    stopLog();
    return 0;
}