#include "logger.h"

Logger::Logger(unsigned int _logsize) {
    logsize = _logsize;
    logbuf = new char*[logsize];
}


void Logger::begin(void) {
  for (int i=0; i<logsize; i++) {
    logbuf[i]=0;
  }  
}

void Logger::add(char* prefix, char* buf) {
  unsigned int entrylength = strlen(buf)+strlen(prefix)+3;  
  if (logbuf[logsize - 1] != 0) {
    free(logbuf[0]);
    for (unsigned int i=1; i<logsize; i++) {
      logbuf[i-1]=logbuf[i];
    }
  }
  logbuf[logsize-1]=(char*)malloc(entrylength);
  snprintf(logbuf[logsize-1],entrylength,"%s: %s", prefix, buf);
//  logbuf[logsize-1][strlen(buf)]='\0';
}

String Logger::printBuffer(void) {
  String retval;  
  for (unsigned int i=0; i<logsize; i++) {
    if (logbuf[i] != 0 ) {  
      retval += logbuf[i];
      retval += "\n";
    }
  }
  return retval;
}
