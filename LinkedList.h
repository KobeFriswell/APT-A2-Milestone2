#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
  	
class LinkedList {
public:
   LinkedList();
   ~LinkedList();
      
   int size();
   void clear();
   int get(int i);

   void addFront(int data);
   void addBack(int data);

private:
   Node* head;
   Node* last;
   int listSize;
};

#endif // LINKED_LIST_H