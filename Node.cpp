#include "Node.h"

Node::Node(char data, Node* next){
    this->data = data;
    this->next = next;
}

Node::Node(Node& other){
    this->data = other.data;
    this->next = other.next;
}