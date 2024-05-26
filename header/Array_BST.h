#include "binary_tree.h"
struct Node
{
    int data;
};

class ArrayBinarySearchTree : public BinarySearchTree
{
    Node **data_user = nullptr;
    int nodeCount{};
    int size{};
    int depth{};
    bool resize(int temp = 0);
    bool isFull();

public:
    ArrayBinarySearchTree()
    {
        resize();
    }
    ~ArrayBinarySearchTree()
    {
        for (int i = 0; i < size; i++)
        {
            delete data_user[i];
        }
        delete[] data_user;
    }
    bool isEmpty();
    void addBST(int data);
    void removeBST(int key);
    int searchBST(int key);
};
