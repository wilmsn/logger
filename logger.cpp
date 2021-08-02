#include "logger.h"

Logger::Logger(unsigned int _numLines, unsigned int _lineSize) {
  lineSize = _lineSize;
  numLines = _numLines;
}


void Logger::begin(void) {
  outbuf = (char*)malloc(lineSize*numLines+1);
  logbuf = new char*[lineSize];
  for (int i=0; i<numLines; i++) {
    logbuf[i] = (char*)malloc(lineSize+1);
    memset(logbuf[i],0,lineSize);
  }  
}

void Logger::addLine(const char* buf1, const char* buf2, const char* buf3) {
  freeLine();
  snprintf(logbuf[numLines-1],lineSize,"%s: %s: %s", buf1,buf2,buf3);
}

void Logger::addLine(const char* buf1, const char* buf2) {
  freeLine();
  snprintf(logbuf[numLines-1],lineSize,"%s: %s", buf1, buf2);
}

void Logger::addLine(const char* buf1) {
  freeLine();
  snprintf(logbuf[numLines-1],lineSize,"%s", buf1);
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
