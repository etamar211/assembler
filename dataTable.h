typedef struct dataNode{
    short addr;
    int value;
    struct dataNode* next;
} dataNode;

typedef struct dataTable{
    dataNode* data;
    int length;
} dataTable;

/**
 * sets all the linked lists in table to NULL
 * @param table data Table
 */
void setDataTable(dataTable* table);

/**
 * sets new data node with given address and value
 * @param addr given address
 * @param value data value
 * @return dataNode* to new node; NULL if error
 */
dataNode* setNewDataNode(short addr, int value);

/**
 * add a given node to a given table
 * @param table given data table
 * @param node given node
 */
void addDataNodeToList(dataTable* table, dataNode* node);

/**
 * returns the octal representation of given value.
 * @param val given value
 * @return octal representation of value
 */
int dataToOctal(int value);

/**
 * releases allocated dynamic memory in given table
 * @param table given table
 */
void releaseDataMemory(dataTable* table);