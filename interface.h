//
// Created by dyaki on 3/22/2019.
//
#include "Game.h"

#ifndef GAMELIFE_INTERFACE_H
#define GAMELIFE_INTERFACE_H

#define GRAPHIC_INTERAFACE 0
#define CONSOLE_INTERFACE 1

#ifdef GRAPHIC_INTERAFACE
// TODO include graphic lib here
#endif

bool setupInterface(Game* _game);

bool setBlockTrue(Game* _game, unsigned short int _i,unsigned short int _j);
bool setBlockFalse(Game* _game, unsigned short int _i,unsigned short int _j);

void updateMap(Game* _game);

bool loadFromGame(Game* _game);

void clearMap(Game* _game, unsigned short int _i,unsigned short int _j);


#endif //GAMELIFE_INTERFACE_H
