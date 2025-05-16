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

        if (START == NULL || nim <= START->noMhs){
            if (START != NULL && nim== START->noMhs){
                cout << "\nDuplicate number not allowed" <<endl;
                return;
            }

            newNode->next = START;

            if (START != NULL)
                START->prev = newNode;

            newNode->prev = NULL;

            START = newNode;
            return;
        }

        Node*current = START;
        while (current->next != NULL && current->next->noMhs<nim){
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs){
            cout << "\nDuplicate roll numbers not allowed"<< endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
    }

    void hapus(){
        if (START == NULL){
            cout << "\nList id Empty"<< endl;
            return;
        }
        cout << "\nEnter the roll number of the student whose is to be deleted: ";
        int rollNo;
        cin>> rollNo;

        Node *current = START;
        
        while(current != NULL && current->noMhs != rollNo)
        current = current->next;
        if (current==NULL){
            cout << "Record not found"<< endl;
            return;
        }

        if (current==START){
            START = current->next;
            if (START != NULL)
            START->prev = NULL;
        }
        else{
            current->prev->next =current->next;

            if (current->next != NULL)
            current->next->prev=current->prev;
        }

        delete current;
        cout << "Record with roll number "<< rollNo<< "deleted"<<endl;
    }

    void traverse(){
        if (START == NULL){
            cout << "\nList Empty"<< endl;
            return;
        }

        Node *currentNode = START;

        cout << "\nRecords in ascending order of roll number are: \n";
        int i = 0 ;
        while(currentNode != NULL){
            cout << i + 1 << ". " << currentNode->noMhs<<" "<< endl;

            currentNode = currentNode->next;
            i++;
        }
    }

    void retraverse (){
        if (START == NULL){
            cout << "\nList is Empty"<<endl;
            return;
        }

        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
            i++;
        }
        cout << "\nRecords in descrnding order of roll number are: \n";
        while (currentNode != NULL){
            cout << i +1 << ". "<< currentNode->noMhs<< " "<<endl;
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchdata(){
        if (START == NULL){
            cout << "\nList is empty"<< endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
        current = current->next;

        if (current == NULL){
            cout << "Record not found\n";
        }
        else{
            cout << "record found\n";
            cout << "roll Number: "<< current->noMhs <<endl;
        }
    }

};