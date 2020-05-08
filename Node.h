#ifndef NODE_H
#define NODE_H

#include "Tiles.h"

class Node {
public:

   Node(Tiles* data, Node* next);
   Node(Node& other);

   Tiles* data;
   Node*  next;
};

#endif // NODE_H