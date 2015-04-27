#include <iostream>
#include <string>
#include "llist.h"


using namespace std;

void mainMenu();

int main() {
    int userInput = 0;
    int llistTypeSelection;
    string stringInput;
    bool llistCreated = 0;
    bool warningDisplayed = 0;
    llist * linkedList;

    while(userInput != -1) {
        warningDisplayed = 0;
        mainMenu();
        cin>>userInput;
        if(!cin) {
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Malformed Input: Numbers 1 - 11 only"<<endl;
            warningDisplayed = 1;
        }

        switch(userInput) {
            case(1): { // Initialize the linked list
                if(!llistCreated) {
                    cout<<"What type of linked list?"<<endl;
                    cout<<"(1) LIFO   (2) FIFO   (3) Priority"<<endl;
                    cin.ignore();
                    cin>>llistTypeSelection;
                    if(!cin) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Malformed Input: Numbers 1 - 3 only"<<endl;
                    }
                    else if(llistTypeSelection <= 3 && llistTypeSelection >= 1) {
                        linkedList = new llist(llistTypeSelection);
                        llistCreated = 1;
                    }
                    else cout<<"Malformed input: expected input between 1 and 3"<<endl;
                }
                else cout<<"Linked list already initialized"<<endl;
                break;
            }
            case(2): { // Push into the linked list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                cout<<"Enter a string:"<<endl;
                cin.ignore();
                getline(cin, stringInput);
                linkedList->push(stringInput);
                break;
            }
            case(3): { // Pop off of the liked list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) {
                    cout<<"List empty"<<endl;
                }
                else cout<<linkedList->pop()<<endl;
                break;
            }
            case(4): { // Change list type
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                cout<<"What type of linked list?"<<endl;
                cout<<"(1) LIFO   (2) FIFO   (3) Priority"<<endl;
                cin.ignore();
                cin>>llistTypeSelection;
                if(!cin) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout<<"Malformed Input: Numbers 1 - 3 only"<<endl;
                }
                else if(llistTypeSelection <= 3 && llistTypeSelection >= 1) {
                    linkedList->changeType(llistTypeSelection);
                }
                else cout<<"Malformed input: expected input between 1 and 3"<<endl;
                break;
            }
            case(5): { // Check if list is empty
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) cout<<"List empty"<<endl;
                else cout<<"List not empty"<<endl;
                break;
            }
            case(6): { // Check top value of list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) cout<<"List empty"<<endl;
                else cout<<linkedList->topPeek()<<endl;
                break;
            }
            case(7): { // Check bottom value of list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) cout<<"List empty"<<endl;
                else cout<<linkedList->bottomPeek()<<endl;
                break;
            }
            case(8): { // Print list contents
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) cout<<"List empty"<<endl;
                else linkedList->printLinkedList();
                break;
            }
            case(9): { // Delete entire list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) cout<<"List empty"<<endl;
                else linkedList->deleteList();
                break;
            }
            case(10): { // Delete member of list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                if(linkedList->isEmpty()) cout<<"List empty"<<endl;
                else {
                    cout<<"Enter a string:"<<endl;
                    cin.ignore();
                    getline(cin, stringInput);
                    linkedList->deleteMember(stringInput);
                }
                break;
            }
            case(11): { // Destruct linked list
                if(!llistCreated) {
                    cout<<"Initialize the linked list first"<<endl;
                    break;
                }
                linkedList->~llist();
                llistCreated = 0;
                break;
            }
            case(12): {
                userInput = -1;
                if(llistCreated) linkedList->~llist();
                break;
            }
            default: {
                if(!warningDisplayed) cout<<"Malformed Input: Numbers 1 - 11 only"<<endl;
            }
        }
    }
}

void mainMenu() {
    cout<<"-- Linked List Usage and Conversion Driver --"<<endl;
    cout<<"1.  Initialize linked list"<<endl;
    cout<<"2.  Push into linked list"<<endl;
    cout<<"3.  Pop off of linked list"<<endl;
    cout<<"4.  Change list type"<<endl;
    cout<<"5.  Check if list is empty"<<endl;
    cout<<"6.  Check top value of list"<<endl;
    cout<<"7.  Check bottom value of list"<<endl;
    cout<<"8.  Print list contents"<<endl;
    cout<<"9.  Delete entire list"<<endl;
    cout<<"10. Delete member of list"<<endl;
    cout<<"11. Destruct linked list"<<endl;
    cout<<"12. Exit"<<endl;
}
