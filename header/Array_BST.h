#include "binary_tree.h"
struct Node{
    int data;
    int depth;
};

class ArrayBinarySearchTree : public BinarySearchTree
{
    Node *data_user = nullptr;
    int nodeCount{};
    int size{};
    bool resize();
    bool isFull();
public:

~ArrayBinarySearchTree(){
    delete []data_user;
}
bool isEmpty();
bool addBST(int data);
bool removeBST(int key);
int  searchBST(int key);
};

