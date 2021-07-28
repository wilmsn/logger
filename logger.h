

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arduino.h"



class Logger {
public:
    Logger(unsigned int _logsize);
    void begin(void);
    String printBuffer(void);
    void add(char* prefix, char* buf);
    
private:
    unsigned int logsize;   
    char** logbuf;
    
    
};


#endif
