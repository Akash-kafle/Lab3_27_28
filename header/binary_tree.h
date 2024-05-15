#include <iostream>

class BinarySearchTree
{
public:
virtual bool isEmpty() = 0;
virtual bool addBST(int data) = 0;
virtual bool removeBST(int key) = 0;
virtual int  searchBST(int key)= 0;
};
