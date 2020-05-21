#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    last = nullptr;
    listSize = 0;
}

LinkedList::~LinkedList(){
    clear();
}

//Return the int listSize as it keeps track of the size when adding and clearing
int LinkedList::size(){
    return listSize;
}

void LinkedList::clear(){
    Node* curr = head;
    Node* prev;
    head = nullptr;
    last = nullptr;

    while (curr != nullptr){
        prev = curr;
        curr = curr->next;

        delete prev;
    }

    //Reset List Size
    listSize = 0;
}

Node* LinkedList::getNode(int i){
    Node* current = head;
    while (i != 0){
            i--;
            current = current->next;
        }
    return current;
}

char LinkedList::getData(int i){
    return getNode(i)->data;
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

    if (last == nullptr && head == nullptr){
        last = newNode;
        head = newNode;
    } else{
        last->next = newNode;
        last = newNode;
    }
    listSize++;
}

//Grabs First Tile as Bag is shuffled
char LinkedList::grabTile(){
    if (listSize>0){
        Node* selectedTile = head;
        char tileData = selectedTile->data;

        head = selectedTile->next;

        delete selectedTile;
        return tileData;
    } else{
        return '-';
    }
    
}
