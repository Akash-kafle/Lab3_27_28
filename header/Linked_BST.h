#include "binary_tree.h"

class Node{
int data;
int depth;
Node* right;
Node* left;

public:
 Node* getRight(){
    return right;
 }
 Node* getLeft(){
    return left;
 }

 int getData(){
    return data;
 }
 int getDepth(){
    return depth;
 }
};

