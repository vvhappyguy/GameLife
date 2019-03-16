//
// Created by dyaki on 3/4/2019.
//

#include "logging.h"

int initLog(unsigned short int _level)
{
    if(!logGame.f)
        logGame.f = fopen(LOG_NAME, "a");
    if(!logGame.f) {
        printf("error in log[initLog]: %s\n",LOG_NAME);
        return 1;
    }
    logGame.level = _level;
    const time_t timer = time(NULL);
    char tmp[50];
    sprintf(tmp,"Start Logging to file: %s with level: %d\n",LOG_NAME, _level);
    putLog(tmp, 0);
    sprintf(tmp,"Time: %s",ctime(&timer));
    putLog(tmp,0);
    return 0;
}

int putLog(const char* _msg, unsigned short int _level)
{
    if(_level > logGame.level)
        return 0;
    if(!logGame.f) {
        printf("error in log[put]:%s\n", _msg);
        return 1;
    }
    fprintf(logGame.f,"[%i] - %s",_level,_msg);
    return 0;
}

int stopLog()
{
    if(!logGame.f) {
        printf("error ing log - bad handler\n");
        return 1;
    }
    putLog("Finished logging\n",0);
    fclose(logGame.f);
    logGame.level = 0;
    return 0;
}