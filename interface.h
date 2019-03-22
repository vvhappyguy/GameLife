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

#define LIFE_SYM 178
#define DIED_SYM 177

bool setupInterface(Game* _game);
void updateMap(Game* _game);
void clearMap();


#endif //GAMELIFE_INTERFACE_H
