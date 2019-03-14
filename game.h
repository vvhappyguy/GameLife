//
// Created by dyaki on 3/14/2019.
//

#ifndef GAMELIFE_GAME_H
#define GAMELIFE_GAME_H

#include <stdbool.h>
#include <stddef.h>

typedef struct GameLogic{
    bool** map;
    size_t size;
} Game;

Game* initGame(size_t _size);
void randomMap(Game* _game);
bool endGame(Game* _game);
void simpleShow(Game* _game);

bool saveGame(Game* _game, const char* _filename);

#endif //GAMELIFE_GAME_H
