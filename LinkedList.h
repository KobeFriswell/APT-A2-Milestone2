#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

#include <iostream>
  	
class LinkedList {
public:
   LinkedList();
   ~LinkedList();
      
   int size();
   void clear();
   Node* getNode(int i);
   char getData(int i);

   void addFront(char data);
   void addBack(char data);
   char grabTile();

private:
   Node* head;
   Node* last;
   int listSize;
};

#endif // LINKED_LIST_H