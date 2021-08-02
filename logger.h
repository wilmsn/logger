

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arduino.h"



class Logger {
public:
    Logger(unsigned int _numLines, unsigned int _lineSize);
    void begin(void);
    unsigned int get_lineNo(void);
    bool lineIsUsed(unsigned int lineNo);
    char* printBuffer(void);
    void addLine(const char* buf1, const char* buf2, const char* buf3);
    void addLine(const char* buf1, const char* buf2);
    void addLine(const char* buf1);
    
private:
    unsigned int lineSize, numLines;   
    char** logbuf;
    char*  outbuf;
    void freeLine(void);
};


#endif
