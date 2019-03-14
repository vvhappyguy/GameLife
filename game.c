//
// Created by dyaki on 3/14/2019.
//

#include <malloc.h>
#include <time.h>
#include "game.h"
#include "logging.h"

Game* initGame(size_t _size)
{
    putLog("Init Game\n", 1);
    Game* _game = malloc(sizeof(Game));

    _game->size = _size;

    _game->map = (bool**)malloc(sizeof(bool*) * _size);
    for(size_t i = 0; i < _size; i++)
        _game->map[i] = (bool*)malloc(sizeof(bool) * _size);

    for(size_t i = 0; i < _size; i++)
        for(size_t j = 0; j < _size; j++)
            _game->map[i][j] = 0;

    putLog("Successfully\n", 1);
    return _game;
};

void randomMap(Game* _game)
{
    putLog("Randomise map\n", 2);
    if(_game == NULL)
    {
        putLog("Failed randomMap\n", 2);
        return;
    }

    srand(time(NULL));   // Initialization, should only be called once.

    for(size_t i = 0; i < _game->size; i++)
        for(size_t j = 0; j < _game->size; j++)
            _game->map[i][j] =  rand() % 2;

    putLog("Random successfully\n", 2);
    return;
}

bool endGame(Game* _game)
{
    putLog("endGame\n",1);
    if(_game == NULL)
    {
        putLog("Failed endGame\n",1);
        return 0;
    }

    for(size_t i = 0; i < _game->size; i++)
        free(_game->map[i]);
    free(_game->map);
    free(_game);
    putLog("Successfully endGame\n",1);
    return 1;
};

void simpleShow(Game* _game)
{
  if(_game == NULL)
  {
      putLog("ERROR - _game is NULL - Failed\n",1);
      return;
  }

    printf("SHOW SIMPLE GAME\n");
  for(size_t i = 0; i < _game->size; i++)
  {
      printf("\n");
      for (size_t j = 0; j < _game->size; j++)
          printf("%d",_game->map[i][j]);
  }
    printf("\n");
};

