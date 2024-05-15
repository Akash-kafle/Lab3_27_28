#include "../header/Array_BST.h"

bool ArrayBinarySearchTree::isEmpty( )
{
    if(data_user == nullptr){
        return true;
    }
    return false;
}
bool ArrayBinarySearchTree::isFull()
{
    return false;
}

bool ArrayBinarySearchTree::addBST(int data)
{
    if(data_user == nullptr || isFull()){
        if(resize()){
            throw "Error allocating space";
        }
    }
    
    return false;
}

bool ArrayBinarySearchTree::removeBST(int key)
{
    return false;
}

int ArrayBinarySearchTree::searchBST(int key)
{
    return 0;
}
bool ArrayBinarySearchTree::resize()
{
    return false;
}