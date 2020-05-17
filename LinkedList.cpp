#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    last = nullptr;
    listSize = 0;
}

LinkedList::~LinkedList(){
    clear();
}
      
int LinkedList::size(){
    //Return the int listSize as it keeps track of the size 
    //when adding and clearing
    return listSize;
}

void LinkedList::clear(){
    Node* curr = head;
    Node* prev;
    head = nullptr;

    while (curr != nullptr){
        prev = curr;
        curr = curr->next;

        delete prev;
    }

    //Reset List Size
    listSize = 0;
}

char LinkedList::get(int i){
    Node* current = head;

    while (i !=0){
        i--;
        current = current->next;
    }
    return current->data;
}

void LinkedList::addFront(char data){
    Node* newNode = new Node(data,head);

    //Check to see if new list with no nodes, meaning it will
    //be first and last
    if (head == nullptr){
        last = newNode;
    }

    head = newNode;
    listSize++;
}

void LinkedList::addBack(char data){
    Node* newNode = new Node(data, nullptr);
    last->next = newNode;
    last = new Node(data, nullptr);
    listSize++;
}