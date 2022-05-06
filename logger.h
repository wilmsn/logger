#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arduino.h"
#include "Print.h"

class Logger : public Print {
    
public:
    Logger(unsigned int _numLines, unsigned int _lineSize);
    void begin(void);
    unsigned int get_lineNo(void);
    bool lineIsUsed(unsigned int lineNo);
    char* printBuffer(void);
size_t write(uint8_t c);

private:
    unsigned int lineSize, numLines, posInLine;   
    char** logbuf;
    char*  outbuf;
    void freeLine(void);
};

#endif
