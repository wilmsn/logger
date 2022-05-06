#include "logger.h"

Logger::Logger(unsigned int _numLines, unsigned int _lineSize) {
  lineSize = _lineSize;
  numLines = _numLines;
}

void Logger::begin(void) {
  outbuf = (char*)malloc(lineSize*numLines+1);
  logbuf = new char*[lineSize];
  posInLine = 0;
  for (int i=0; i<numLines; i++) {
    logbuf[i] = (char*)malloc(lineSize+1);
    memset(logbuf[i],0,lineSize);
  }  
}

size_t Logger::write(uint8_t c) { 
    size_t retval=0;
    // CF und LF sorgen für Zeilenumbruch
    if (c == 10 || c == 13) {
       freeLine();	
       posInLine = 0;
    }
    if ( posInLine < lineSize ) {
	if (c > 31 && c < 127) {
	    logbuf[numLines-1][posInLine] = c;
	    posInLine++;
	    retval = 1;
        }
    } else {
	retval = 0;
    }
#ifdef ESP8266
    delay(0);
#endif    
    return retval; 
}

void Logger::freeLine(void) {
  for (unsigned int i=1; i<numLines; i++) {
    sprintf(logbuf[i-1],"%s",logbuf[i]);
  }
}

unsigned int Logger::get_lineNo(void) {
  return numLines;
}

bool Logger::lineIsUsed(unsigned int lineNo) {
  if (logbuf[lineNo][0] == '\0' ) { return false; } else { return true; }
}

char* Logger::printBuffer(void) {
  memset(outbuf,0,sizeof outbuf);  
  for (unsigned int i=0; i<numLines; i++) {
    if (logbuf[i][0] != 0 ) {  
      strcat(outbuf,logbuf[i]);
      strcat(outbuf,"\n");
    }
  }
  return outbuf;
}
