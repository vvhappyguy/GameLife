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

bool setBlockTrue(Game* _game, unsigned short int _i,unsigned short int _j)
{
    size_t size = _game->size;
    if(size <= _i || size <= _j)
        return false;
    _game->map[_i][_j] = 1;
    return true;
}

bool setBlockFalse(Game* _game, unsigned short int _i,unsigned short int _j)
{
    size_t size = _game->size;
    if(size <= _i || size <= _j)
        return false;
    _game->map[_i][_j] = 0;
    return true;
}

void updateMap(Game* _game)
{
    // TODO Clear console here
    for(unsigned short int i = 0; i < _game->size; i++)
    {
        for(unsigned short int j = 0; i < _game->size; j++)
            printf("%c",'l');
        printf("\n");
    }
}

#else

// TODO Add all function from header file for <graphics.h>

#endif
