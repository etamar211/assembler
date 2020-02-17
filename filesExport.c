#include <stdio.h>
#include "assemblerHelper.h"
#include "filesExport.h"

/**
 * Exports the object, entries and external files.
 * @param fileName file name
 * @param codeArr array of asmWord pointers, that represents the code section
 * @param codeLength length of code in asmWords
 * @param dt pointer to the data table
 * @param entryTable pointer to entry table
 * @param externTable pointer to external table
 * @return OK(0) if OK; else errCode as defined in assemblerHelper
 */
int exportFiles(char* fileName, asmWord** codeArr, int codeLength, dataTable* dt,
                labelTable* entryTable, labelTable* externTable){
    int errCode;
    if((errCode = exportObjectFile(fileName, codeArr, codeLength, dt)) != 0){
        return errCode;
    }
    if((errCode = exportEntriesFile(fileName, entryTable)) != 0) {
        return errCode;
    }
    if((errCode = exportExternalsFile(fileName, externTable)) != 0) {
        return errCode;
    }
    return OK;
}

/**
 * Exports the data in assembly file to .ob file.
 * First line is: "[code_length] [data_length]
 * First section is: "[code_addr] [asmWord of code in octal]
 * Second section is: "[data_addr] [value]
 * @param fileName file name
 * @param codeArr array of asmWord pointers, that represents the code section
 * @param codeLength length of code in asmWords
 * @return OK(0) if OK; else errCOde as defined in assemblerHelper
 */
int exportObjectFile(char* fileName, asmWord** codeArr, int codeLength, dataTable* dt){
    FILE* fp;
    int errCode, i;
    dataNode* curr = dt->data;
    errCode = openFile(fileName, 'o', &fp);
    if(errCode != OK){
        printErr(errCode);
        if(errCode == ERR_CANT_SET_MEMORY){
            return 0;
        }
    }
    else{
        /*
         * write to file
         */
        fprintf(fp,"\t%d %d\n", codeLength, dt->length);

        for(i = 0; i < codeLength; i++){
            fprintf(fp,"%04d %05d\n", (i+100), wordToOctal(codeArr[i]));
        }

        while(curr->next){
            fprintf(fp,"%04d %05d\n", curr->addr, dataToOctal(curr->value));
            curr = curr->next;
        }
        fprintf(fp,"%04d %05d", curr->addr, dataToOctal(curr->value));

        fclose(fp);
    }

    return OK;
}

/**
 * Exports the entries in assembly file to .ent file.
 * Format: "[entry_name] [entry_addr]"
 * @param fileName file name
 * @param entryTable entries table to print to file
 * @return OK(0) if OK; else errCode as defined in assemblerHelper
 */
int exportEntriesFile(char* fileName, labelTable* entryTable){
    FILE* fp;
    int errCode, i;
    labelNode* curr = entryTable->labels;
    errCode = openFile(fileName, 'e', &fp);
    if(errCode != OK){
        printErr(errCode);
        if(errCode == ERR_CANT_SET_MEMORY){
            return 0;
        }
    }
    else{
        /*
         * write to file
         */
        while(curr->next){
            fprintf(fp,"%s %04d\n", curr->labelName, curr->value);
            curr = curr->next;
        }
        fprintf(fp,"%s %04d", curr->labelName, curr->value);

        fclose(fp);
    }

    return OK;
}

/**
 * Exports the externals in assembly file to .ext file.
 * Format: "[external_name] [external_addr]"
 * @param fileName file name
 * @param externTable externals table to print to file
 * @return OK(0) if OK; else errCode as defined in assemblerHelper
 */
int exportExternalsFile(char* fileName, labelTable* externTable){
    FILE* fp;
    int errCode, i;
    labelNode* curr = externTable->labels;
    errCode = openFile(fileName, 'x', &fp);
    if(errCode != OK){
        printErr(errCode);
        if(errCode == ERR_CANT_SET_MEMORY){
            return 0;
        }
    }
    else{
        /*
         * write to file
         */
        while(curr->next){
            fprintf(fp,"%s %04d\n", curr->labelName, curr->value);
            curr = curr->next;
        }
        fprintf(fp,"%s %04d", curr->labelName, curr->value);

        fclose(fp);
    }

    return OK;
}