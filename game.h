//
// Created by dyaki on 3/14/2019.
//

#ifndef GAMELIFE_GAME_H
#define GAMELIFE_GAME_H

#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <mem.h>
#include "logging.h"

typedef struct GameLogic{
    bool** map;
    size_t size;
} Game;

Game* initGame(size_t _size);
void randomMap(Game* _game);
bool endGame(Game* _game);

bool saveGame(Game* _game, const char* _filename);
bool loadGame(Game* _game, const char* _filename);
bool copyGame(Game *_to, Game *_from);


#endif //GAMELIFE_GAME_H
