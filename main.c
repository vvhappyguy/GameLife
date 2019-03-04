#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "logging.h"
#include <time.h>

int setup()
{
    initLog(0);
    putLog("SETUP:\n",0);

    putLog("\n",0);
    return 0;
}


int main()
{
    if(setup() != 0)
        exit(1);

    stopLog();
    return 0;
}