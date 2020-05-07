#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
  	
class LinkedList {
public:
   LinkedList();
   ~LinkedList();
      
   int size();
   void clear();
   Tiles* get(int i);

   void addFront(Tiles* data);
   void addBack(Tiles* data);

private:
   Node* head;
   Node* last;
   int listSize;
};

#endif // LINKED_LIST_H