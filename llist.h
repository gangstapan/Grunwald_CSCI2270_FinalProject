#ifndef LLIST_H
#define LLIST_H
#include <string>
#include <iostream>

struct node {
    std::string value;
    bool sorted;
    node * next;
    node * previous;
};

class llist
{
    public:
        llist(int);
        ~llist();
        void push(std::string);
        void printLinkedList();
        std::string pop();
        bool isEmpty();
        void changeType(int);
        std::string topPeek();
        std::string bottomPeek();
        void deleteList();
        void deleteMember(std::string);
    protected:
    private:
        node * sentinel;
        int list_type;
        int llistSize;
};

#endif // LLIST_H
