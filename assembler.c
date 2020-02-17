#include <stdio.h>
#include "assemblerHelper.h"
#include "asmWord.h"
#include "filesExport.h"

int main(int argc, char** argv){
    int errCode, i, ic;
    FILE* fp;
    asmWord* code[CODE_ARR_SIZE];
    dataTable dataT;
    labelTable entryT;
    labelTable externT;

    /*
     * no files entered
     */
    if(argc <= 1){
        printErr(ERR_NO_FILES);
        return 0;
    }

    for(i = 1; i < argc; i++){
        errCode = openFile(argv[i], 'a', &fp);
        if(errCode != OK){
            printErr(errCode);
            if(errCode == ERR_CANT_SET_MEMORY){
                return 0;
            }
        }
        else{
            //call to first and second review


            if((errCode = exportFiles(argv[i], code, ic, &dataT, &entryT, &externT)) != OK){
                printErr(errCode);
            }

            fclose(fp);
        }
    }

    return 0;
}

