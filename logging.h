//
// Created by dyaki on 3/4/2019.
//

#ifndef GAMELIFE_LOGGING_H
#define GAMELIFE_LOGGING_H

#include <stdio.h>
#include <time.h>


#define LOG_NAME "GameLife.log"
static FILE* f;

typedef struct logGame
{
    FILE* f; // File descriptor
    unsigned short int level; // Level of logging, can be 0 - only main, 1 - system logs, 2 - game logs, 4 - all
} logging;

static logging logGame;

int initLog(unsigned short int _level);
int putLog(const char* _msg, unsigned short int _level);
int stopLog();


#endif //GAMELIFE_LOGGING_H
