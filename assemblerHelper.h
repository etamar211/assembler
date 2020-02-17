#define OK 0
#define ERR_NO_FILES 1
#define ERR_CANT_OPEN_FILE 2
#define ERR_CANT_SET_MEMORY 3
#define ERR_CANT_CREATE_FILE 4

#define CODE_ARR_SIZE 4096

/**
 * prints error to the standard error file.
 * @param errCode error code
 */
void printErr(int errCode);

/**
 * Opens file and changes fp to the new file pointer
 * @param fileName name of the file to open
 * @param fileType 'a' for asm, 'o' for object, 'x' for externals, 'e' for entries
 * @param fp file pointer to change to new file.
 * @return error code; OK if OK.
 */
int openFile(char* fileName, char fileType, FILE** fp);