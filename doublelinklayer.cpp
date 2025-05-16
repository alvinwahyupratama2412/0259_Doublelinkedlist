#include <iostream>
#include <string>
using namespace std;


class Node{
    public :
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList {
    Node* START;
public:
    DoubleLinkedList() {
        START = NULL;
    }

    void addNode(){
        int nim;
        cout << "\nEnter the roll number of the Student: ";
        cin >> nim;

        Node *newNode = new Node();

        newNode->noMhs = nim;
    }

};