#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assemblerHelper.h"

/**
 * prints errors by error code.
 * @param errCode error code
 */
void printErr(int errCode) {
    switch (errCode){
        case ERR_NO_FILES:
            printf("Error: no files entered\n");
            break;

        case ERR_CANT_OPEN_FILE:
            printf("Error: can't open file\n");
            break;

        case ERR_CANT_SET_MEMORY:
            printf("Error: can't set new memory\n");
            break;

        case ERR_CANT_CREATE_FILE:
            printf("Error: can't create file\n");

        default:
            break;
    }
}

/**
 * Opens file and changes fp to the new file pointer
 * @param fileName name of the file to open
 * @param fileType 'a' for asm, 'o' for object, 'x' for externals, 'e' for entries
 * @param fp file pointer to change to new file.
 * @return error code; OK if OK.
 */
int openFile(char* fileName, char fileType, FILE** fp){
    unsigned int fileNameLen = strlen(fileName);
    char mode[1];
    char* fileNameWithEnding = (char*) malloc(sizeof(char) * (fileNameLen + 5));
    if(fileNameWithEnding == NULL){
        return ERR_CANT_SET_MEMORY;
    }
    strncpy(fileNameWithEnding, fileName, fileNameLen);
    fileNameWithEnding[fileNameLen] = '.';
    switch (fileType){
        case 'a':
            fileNameWithEnding[fileNameLen + 1] = 'a';
            fileNameWithEnding[fileNameLen + 2] = 's';
            fileNameWithEnding[fileNameLen + 3] = '\0';
            mode[0] = 'r';
            break;
        case 'o':
            fileNameWithEnding[fileNameLen + 1] = 'o';
            fileNameWithEnding[fileNameLen + 2] = 'b';
            fileNameWithEnding[fileNameLen + 3] = '\0';
            mode[0] = 'w';
            break;
        case 'x':
            fileNameWithEnding[fileNameLen + 1] = 'e';
            fileNameWithEnding[fileNameLen + 2] = 'x';
            fileNameWithEnding[fileNameLen + 3] = 't';
            fileNameWithEnding[fileNameLen + 4] = '\0';
            mode[0] = 'w';
            break;
        case 'e':
            fileNameWithEnding[fileNameLen + 1] = 'e';
            fileNameWithEnding[fileNameLen + 2] = 'n';
            fileNameWithEnding[fileNameLen + 3] = 't';
            fileNameWithEnding[fileNameLen + 4] = '\0';
            mode[0] = 'w';
            break;
        default:
            break;
    }
    fileNameWithEnding[fileNameLen + 4] = '\0';
    if((*fp = fopen(fileName, mode)) == NULL){
        return (mode[0] == 'r') ? ERR_CANT_OPEN_FILE : ERR_CANT_CREATE_FILE;
    }
    else{
        return OK;
    }
}
