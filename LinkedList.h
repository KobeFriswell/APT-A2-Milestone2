#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
  	
class LinkedList {
public:
   LinkedList();
   ~LinkedList();
      
   int size();
   void clear();
   char get(int i);

   void addFront(char data);
   void addBack(char data);

private:
   Node* head;
   Node* last;
   int listSize;
};

#endif // LINKED_LIST_H