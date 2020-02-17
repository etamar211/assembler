#include <stdio.h>
#include <stdlib.h>
#include "labelTable.h"

/**
 * sets all the linked lists in table to NULL
 * @param table label Table
 */
void setLabelTable(labelTable* table){
    table->labels = NULL;
}

/**
 * sets new label node with given label name and value
 * @param labelName given label name
 * @param value label value
 * @return labelNode* to new node; NULL if error
 */
labelNode* setNewLabelNode(char* labelName, int value){
    labelNode* newNode = (labelNode*) malloc(sizeof(labelNode));
    if(newNode != NULL){
        newNode->next = NULL;
        newNode->value = value;
        newNode->labelName = labelName;
    }
    return newNode;
}

/**
 * releases allocated dynamic memory in given table
 * @param table given table
 */
void releaseLabelMemory(labelTable* table){
    labelNode* curr = table->labels, *next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
}
