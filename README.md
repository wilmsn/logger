# logger
A text based logger object for Arduino.

logger builds a text buffer in memory. You can store N lines and each line takes up to M characters.
If you pass more than M characters, additional characters will be truncated.

M and N is configurable, but you need 2*N*M bytes of RAM.

So 20 lines of 80(+1) characters each will take 3240 Bytes!!!
