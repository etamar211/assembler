typedef struct labelNode{
    char* labelName;
    int value;
    struct labelNode* next;
} labelNode;

typedef struct labelTable{
    labelNode* labels;
} labelTable;

/**
 * sets all the linked lists in table to NULL
 * @param table label Table
 */
void setLabelTable(labelTable* table);

/**
 * sets new label node with given label name and value
 * @param labelName given label name
 * @param value label value
 * @return labelNode* to new node; NULL if error
 */
labelNode* setNewLabelNode(char* labelName, int value);

/**
 * releases allocated dynamic memory in given table
 * @param table given table
 */
void releaseLabelMemory(labelTable* table);