//
// Created by dyaki on 3/22/2019.
//

#include "interface.h"

#ifdef CONSOLE_INTERFACE

// Clear console, try to show map by Game->size
bool setupInterface(Game* _game)
{
    for(unsigned short int i = 0; i < _game->size; i++)
    {
        for(unsigned short int j = 0; i < _game->size; j++)
            printf(" ");
        printf("\n");
    }
};

void updateMap(Game* _game)
{
    // TODO Clear console here
    for(unsigned short int i = 0; i < _game->size; i++)
    {
        for(unsigned short int j = 0; i < _game->size; j++)
        {
            if(_game->map[i][j] == 1)
                printf("%c",LIFE_SYM);
            else
                printf("%c",DIED_SYM);
        }
        printf("\n");
    }
};

void clear()
{
    // TODO Write clear function
};

#else

// TODO Add all function from header file for <graphics.h>

#endif
