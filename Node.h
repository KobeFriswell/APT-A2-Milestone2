#ifndef NODE_H
#define NODE_H

#include "Tiles.h"

class Node {
public:

   Node(char data, Node* next);
   Node(Node& other);

   char data;
   Node*  next;
};

#endif // NODE_H