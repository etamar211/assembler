#include <stdio.h>
#include "asmWord.h"
#include "dataTable.h"
#include "labelTable.h"

/**
 *
 * @param fp file pointer to the asm file.
 * @param codeArr array of pointer to asmWord that will represent the code in binary
 * @param ic counter that will save the code length
 * @param dt pointer to dataTable that will save the data
 * @param entryTable pointer to labelTable that will save the entries
 * @param externTable pointer to labelTable that will save the externals
 * @return
 */
int firstReview(FILE* fp, asmWord** codeArr, int* ic, dataTable* dt,
                labelTable* entryTable, labelTable* externTable);