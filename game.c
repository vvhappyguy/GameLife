//
// Created by dyaki on 3/14/2019.
//
#include "game.h"

Game *initGame(size_t _size) {
    putLog("Init Game\n", 0);
    if(_size <= 0)
    {
        putLog("ERROR while initGame - bad argument\n",0);
        return NULL;
    }

    Game *_game = malloc(sizeof(Game));

    _game->size = _size;

    _game->map = (bool **) malloc(sizeof(bool *) * _size);
    for (size_t i = 0; i < _size; i++)
        _game->map[i] = (bool *) malloc(sizeof(bool) * _size);

    for (size_t i = 0; i < _size; i++)
        for (size_t j = 0; j < _size; j++)
            _game->map[i][j] = 0;

    putLog("Successfully\n", 2);
    return _game;
};

bool randomMap(Game *_game) {
    putLog("Randomise map\n", 2);
    if (_game == NULL) {
        putLog("ERROR - Failed randomMap - bad argument\n", 0);
        return false;
    }

    srand(time(NULL));   // Initialization, should only be called once.

    for (size_t i = 0; i < _game->size; i++)
        for (size_t j = 0; j < _game->size; j++)
            _game->map[i][j] = rand() % 2;

    putLog("Random successfully\n", 2);
    return true;
}

bool endGame(Game *_game) {
    putLog("endGame\n", 2);
    if (_game == NULL) {
        putLog("ERROR - Failed endGame - bad argument\n", 0);
        return false;
    }

    for (size_t i = 0; i < _game->size; i++)
        free(_game->map[i]);
    free(_game->map);
    free(_game);
    putLog("Successfully endGame\n", 2);
    return true;
};

bool saveGame(Game *_game, const char *_filename) {
    if ((strlen(_filename) == 0) || (!_game)) {
        char *errorLog = (char *) malloc(sizeof(char) * 256);
        sprintf(errorLog, "ERROR - Invalid arguments saveGame(%d, %s).\n", (int) _game, _filename);
        putLog(errorLog, 0);
        free(errorLog);
        return false;
    }
    char *msgLog = (char *) malloc(sizeof(char) * 256);
    sprintf(msgLog, "Game saving template to %s\n", _filename);
    putLog(msgLog, 1);

    FILE *fileHandle;
    fileHandle = fopen(_filename, "w");

    fprintf(fileHandle, "%d\n", _game->size * _game->size);
    for (int i = 0; i < _game->size; i++)
        for (int j = 0; j < _game->size; j++)
            fprintf(fileHandle, "%d\n", _game->map[i][j]);

    putLog("Successfully save template from program to file.\n", 1);
    fclose(fileHandle);
    free(msgLog);
    return 1;
};

bool loadGame(Game *_game, const char *_filename) {
    if ((strlen(_filename) == 0) || (!_game)) {
        char *errorLog = (char *) malloc(sizeof(char) * 256);
        sprintf(errorLog, "ERROR - Invalid arguments loadGame(%d, %s).\n", (int) _game, _filename);
        putLog(errorLog, 0);
        free(errorLog);
        return false;
    }
    char *msgLog = (char *) malloc(sizeof(char) * 256);
    sprintf(msgLog, "Game loading template from %s.\n", _filename);
    putLog(msgLog, 1);

    FILE *fileHandle;
    fileHandle = fopen(_filename, "r");

    size_t sizeF = 0;
    fscanf(fileHandle, "%d", &sizeF);
    if ((int) sqrt(sizeF) != _game->size) {
        sprintf(msgLog, "ERROR - Invalid size from program(%d) or template(%d).\n", _game->size, (int) sqrt(sizeF));
        putLog(msgLog, 0);
        free(msgLog);
        return false;
    }

    {
        char buf[10];
        size_t i = 0;
        fgets(buf, 10, fileHandle);
        while (fgets(buf, 10, fileHandle) != NULL) {
            _game->map[(int) (i / _game->size)][i % _game->size] = buf[0] % 2;
            i++;
        }
    }
    putLog("Successfully load template from file to program.\n", 1);
    fclose(fileHandle);
    free(msgLog);
    return true;
};

bool copyGame(Game *_to, Game *_from)
{
    if(_to == NULL || _from == NULL)
    {
        putLog("ERROR - copyGame arguments aren't valid\n",1);
        return false;
    }
    if(_to->size != _from->size)
    {
        putLog("ERROR - copyGame size of _to not equal size of _from.\n",1);
        return false;
    }

    size_t size = _from->size;

    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
            _to->map[i][j] = _from->map[i][j];

    putLog("Completed copyGame.\n",2);
    return true;
};

