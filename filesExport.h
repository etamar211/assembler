#include "asmWord.h"
#include "dataTable.h"
#include "labelTable.h"

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
        labelTable* entryTable, labelTable* externTable);

/**
 * Exports the data in assembly file to .ob file.
 * First line is: "[code_length] [data_length]
 * First section is: "[code_addr] [asmWord of code in octal]
 * Second section is: "[data_addr] [value]
 * @param fileName file name
 * @param codeArr array of asmWord pointers, that represents the code section
 * @param codeLength length of code in asmWords
 * @param dt pointer to the data table
 * @return OK(0) if OK; else errCode as defined in assemblerHelper
 */
int exportObjectFile(char* fileName, asmWord** codeArr, int codeLength, dataTable* dt);

/**
 * Exports the entries in assembly file to .ent file.
 * Format: "[entry_name] [entry_addr]"
 * @param fileName file name
 * @param entryTable entries table to print to file
 * @return OK(0) if OK; else errCode as defined in assemblerHelper
 */
int exportEntriesFile(char* fileName, labelTable* entryTable);

/**
 * Exports the externals in assembly file to .ext file.
 * Format: "[external_name] [external_addr]"
 * @param fileName file name
 * @param externTable externals table to print to file
 * @return OK(0) if OK; else errCode as defined in assemblerHelper
 */
int exportExternalsFile(char* fileName, labelTable* externTable);