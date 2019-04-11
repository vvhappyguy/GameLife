//
// Created by dyaki on 3/22/2019.
//

#include "interface.h"

#ifdef CONSOLE_INTERFACE

// Clear console, try to show map by Game->size
bool setupInterface(Game* _game)
{
    // TODO Here must be setting of size console window
};

void updateMap(Game* _game)
{
    if (_game == NULL) {
        putLog("ERROR - updateMap argument isn't valid\n", 1);
        return;
    }


    clearMap();
    for(unsigned short int i = 0; i < _game->size; i++)
    {
        for(unsigned short int j = 0; j < _game->size; j++)
        {
            if(_game->map[i][j] == 1)
                printf("%c%c",(char)LIFE_SYM,(char)LIFE_SYM);
            else
                printf("%c%c",(char)DIED_SYM,(char)DIED_SYM);
        }
        printf("\n");
    }
    putLog("updateMap successfully.\n", 3);
};

void clearMap()
{
    system("cls");
    putLog("clearMap successfully.\n", 3);
};

#else

// TODO Add all function from header file for <graphics.h>

#endif
