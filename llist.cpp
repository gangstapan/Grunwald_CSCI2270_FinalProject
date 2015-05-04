#include "llist.h"

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::llist(int listType);                                                   *
 *                                                                               *
 * Function Description:                                                         *
 * This method will initialize a linked list with a type depending on the input. *
 * If 1 is input, it will initialize a LIFO, 2 a FIFO and 3 an Alphabetized      *
 * Priority Queue.                                                               *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList = new llist(int);                                          *
 *                                                                               *
 * Precondition:                                                                 *
 * listType is an integer between 1 and 3                                        *
 *                                                                               *
 * Postcondition:                                                                *
 * A sentinel node is created and initialized as is the linked list type and the *
 * size of the linked list.                                                      *
 ********************************************************************************/
llist::llist(int listType)
{
    //ctor
    list_type = listType;
    sentinel = new node;
    sentinel->next = NULL;
    sentinel->previous = NULL;
    llistSize = 0;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::~llist();                                                              *
 *                                                                               *
 * Function Description:                                                         *
 * This method will destruct the linked list. If it is empty, it just deletes    *
 * the sentinel. Otherwise it deletes the contents of the list before deleting   *
 * the sentinel.                                                                 *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * linkedList->~llist();                                                         *
 *                                                                               *
 * Precondition:                                                                 *
 * List is initialized.                                                          *
 *                                                                               *
 * Postcondition:                                                                *
 * There is no remaining data structure. List is no longer initialized.          *
 ********************************************************************************/
llist::~llist()
{
    //dtor
    if(sentinel->next != NULL) deleteList();
    delete sentinel;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::push(std::string input);                                               *
 *                                                                               *
 * Function Description:                                                         *
 * Adds node with value input to the linked list either at the front if a LIFO   *
 * or FIFO or in the appropriately sorted location if Priority Queue.            *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * linkedList->push(std::string);                                                *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list has been initialized and input is a string.                       *
 *                                                                               *
 * Postcondition:                                                                *
 * A node with the value input has been placed in the linked list according to   *
 * the type and pointers have been updated.                                      *
 ********************************************************************************/
void llist::push(std::string input) {
    llistSize++;
    node * inputNode = new node;
    inputNode->value = input;
    inputNode->sorted = 0;
    if(sentinel->next == NULL) {
        sentinel->next = inputNode;
        inputNode->next = sentinel;
        sentinel->previous = inputNode;
        inputNode->previous = sentinel;
    }
    else if(list_type == 3) {
        if(entryExists(input) == false) {
            node * placer = sentinel->next;
            while(placer->value.compare(input) < 0 && placer != sentinel) {
                placer = placer->next;
            }
            inputNode->previous = placer->previous;
            placer->previous->next = inputNode;
            placer->previous = inputNode;
            inputNode->next = placer;
        }
        else std::cout<<"Entry already exists. Node not added."<<std::endl;
    }
    else {
        if(entryExists(input) == false) {
            inputNode->next = sentinel->next;
            sentinel->next->previous = inputNode;
            sentinel->next = inputNode;
            inputNode->previous = sentinel;
        }
        else std::cout<<"Entry already exists. Node not added."<<std::endl;
    }
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::printLinkedList();                                                     *
 *                                                                               *
 * Function Description:                                                         *
 * Prints the contents of the linked list in the order they would be popped from *
 * the linked list.                                                              *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * linkedList->printLinkedList();                                                *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list has been initialized and is not empty.                            *
 *                                                                               *
 * Postcondition:                                                                *
 * Prints all items in list to terminal.                                         *
 ********************************************************************************/
void llist::printLinkedList() {
    node * namePrinter;
    if(list_type == 2) namePrinter = sentinel->previous;
    else namePrinter = sentinel->next;
    int i = 1;
    while(namePrinter != sentinel) {
        std::cout<<i<<": "<<namePrinter->value<<std::endl;
        if(list_type == 2) namePrinter = namePrinter->previous;
        else namePrinter = namePrinter->next;
        i++;
    }
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::pop();                                                                 *
 *                                                                               *
 * Function Description:                                                         *
 * Pops the first node off of the linked list if a Priority linked list or LIFO  *
 * or the last node if a FIFO.                                                   *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * std::string = linkedList->pop();                                              *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list has been initialized and is not empty.                            *
 *                                                                               *
 * Postcondition:                                                                *
 * Returns the value of the top node of the linked list, and then deletes the    *
 * node it belonged to.                                                          *
 ********************************************************************************/
std::string llist::pop() {
    std::string returnValue;
    node * poppedNode;
    if(list_type == 2) {
        returnValue = sentinel->previous->value;
        poppedNode = sentinel->previous;
        sentinel->previous = poppedNode->previous;
        poppedNode->previous->next = sentinel;
    }
    else {
        returnValue = sentinel->next->value;
        poppedNode = sentinel->next;
        sentinel->next = poppedNode->next;
        poppedNode->next->previous = sentinel;
    }
    llistSize--;
    delete poppedNode;
    if(llistSize == 0) {
        sentinel->next = NULL;
        sentinel->previous = NULL;
    }
    return returnValue;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::isEmpty();                                                             *
 *                                                                               *
 * Function Description:                                                         *
 * Determines if the linked list is empty by looking at the next and previous    *
 * values of the sentinel node.                                                  *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * bool = linkedList->isEmpty();                                                 *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list has been initialized.                                             *
 *                                                                               *
 * Postcondition:                                                                *
 * Returns true if the linked list is empty and false otherwise.                 *
 ********************************************************************************/
bool llist::isEmpty() {
    if(sentinel->next == NULL) return true;
    else return false;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::changeType(int);                                                       *
 *                                                                               *
 * Function Description:                                                         *
 * Changes the type of the linked list. If changing to a Priority Queue, will    *
 * sort the list appropriately.                                                  *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * linkedList->changeType(int);                                                  *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list is initialized.                                                   *
 *                                                                               *
 * Postcondition:                                                                *
 * Changes the list type and updates pointers if changed to Priority Queue.      *
 ********************************************************************************/
void llist::changeType(int newType) {
    list_type = newType;
    if(newType == 3) {
        node * swapper = new node;;
        node * listLoc1;
        node * listLoc2;
        for(int c = 1; c <= llistSize; c++) {
            for(int d = 1; d <= llistSize - c; d++) {
                listLoc1 = sentinel->next;
                listLoc2 = listLoc1->next;
                for(int b = 1; b < d; b++) {
                    listLoc1 = listLoc1->next;
                }
                listLoc2 = listLoc1->next;
                if(listLoc1->value.compare(listLoc2->value) > 0) {
                    swapper->previous = listLoc1->previous;
                    listLoc1->next = listLoc2->next;
                    listLoc1->previous->next = listLoc2;
                    listLoc1->previous = listLoc2;
                    listLoc2->next->previous = listLoc1;
                    listLoc2->next = listLoc1;
                    listLoc2->previous = swapper->previous;
                }
            }
        }
        delete swapper;
    }
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::topPeek();                                                             *
 *                                                                               *
 * Function Description:                                                         *
 * Returns the value of the top node in the linked list without deleting the     *
 * node.                                                                         *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * std::string = linkedList->topPeek();                                          *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list is initialized and is not empty.                                  *
 *                                                                               *
 * Postcondition:                                                                *
 * Returns value of top node in form of string.                                  *
 ********************************************************************************/
std::string llist::topPeek() {
    if(list_type == 2) return sentinel->previous->value;
    else return sentinel->next->value;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::bottomPeek();                                                          *
 *                                                                               *
 * Function Description:                                                         *
 * Returns the value of the bottom node in the linked list without deleting the  *
 * node.                                                                         *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * std::string = linkedList->bottomPeek();                                       *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list is initialized and is not empty.                                  *
 *                                                                               *
 * Postcondition:                                                                *
 * Returns value of bottom node in form of string.                               *
 ********************************************************************************/
std::string llist::bottomPeek() {
    if(list_type == 2) return sentinel->next->value;
    else return sentinel->previous->value;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::deleteList();                                                          *
 *                                                                               *
 * Function Description:                                                         *
 * Deletes the contents of the linked list leaving the sentinel node intact.     *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * linkedList->deleteList();                                                     *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list is initialized and is not empty.                                  *
 *                                                                               *
 * Postcondition:                                                                *
 * List has no contents and sentinel node points to NULL on both sides.          *
 ********************************************************************************/
void llist::deleteList() {
    node * deletor = sentinel->next;
    node * next = deletor->next;
    sentinel->next = NULL;
    while(deletor != sentinel) {
        delete deletor;
        deletor = next;
        next = next->next;
    }
    sentinel->previous = NULL;
}

/*********************************************************************************
 * Function Prototype:                                                           *
 * llist::deleteMember(std::string);                                             *
 *                                                                               *
 * Function Description:                                                         *
 * Searches the linked list for the node containing the input string and deletes *
 * it.                                                                           *
 *                                                                               *
 * Example:                                                                      *
 * llist * linkedList;                                                           *
 * linkedList->deleteMember(std::string);                                        *
 *                                                                               *
 * Precondition:                                                                 *
 * Linked list is initialized and is not empty.                                  *
 *                                                                               *
 * Postcondition:                                                                *
 * Node containing the input string is deleted and pointers are updated.         *
 ********************************************************************************/
void llist::deleteMember(std::string deleteValue) {
    node * searcher = sentinel->next;
    while(searcher->value != deleteValue && searcher != sentinel) {
        searcher = searcher->next;
    }
    if(searcher != sentinel) {
        searcher->previous->next = searcher->next;
        searcher->next->previous = searcher->previous;
        delete searcher;
    }
}

bool llist::entryExists (std::string Value)
{
    node * searcher = sentinel->next;
    bool exists = false;
    while(searcher->value != Value && searcher != sentinel)
    {
        searcher = searcher->next;
    }
    if (searcher->value == Value)
    {
        exists = true;
    }
    return exists;
}

