#include <stdio.h>
#include <stdlib.h>
#include "dataTable.h"

/**
 * sets all the linked lists in table to NULL
 * @param table data Table
 */
void setDataTable(dataTable* table){
    table->data = NULL;
    table->length = 0;
}

/**
 * sets new data node with given address and value
 * @param addr given address
 * @param value data value
 * @return dataNode* to new node; NULL if error
 */
dataNode* setNewDataNode(short addr, int value){
    dataNode* newNode = (dataNode*) malloc(sizeof(dataNode));
    if(newNode != NULL){
        newNode->next = NULL;
        newNode->value = value;
        newNode->addr = addr;
    }
    return newNode;
}

/**
 * Add a given node to a given table; given that the node.next is NULL
 * @param table given data table
 * @param node given node
 */
void addDataNodeToList(dataTable* table, dataNode* node){
    dataNode* curr = table->data;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = node;
    table->length++;
}

/**
 * returns the octal representation of given value.
 * @param val given value
 * @return octal representation of value
 */
int dataToOctal(int value){
    int octal = 0, digits = 0;
    while(value / 8 != 0){
        octal += value % 8 * ((digits == 0) ? 1 : (digits * 10));
        digits++;
        value /= 8;
    }
    octal += value % 8 * ((digits == 0) ? 1 : (digits * 10));
    return octal;
}

/**
 * releases allocated dynamic memory in given table
 * @param table given table
 */
void releaseDataMemory(dataTable* table){
    dataNode* curr = table->data, *next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
}
