#include "../header/Array_BST.h"
#include <math.h>

bool ArrayBinarySearchTree::isEmpty()
{
    if (data_user == nullptr)
    {
        return true;
    }
    return false;
}
bool ArrayBinarySearchTree::isFull()
{
    if (nodeCount == size)
    {
        return true;
    }
    return false;
}

void ArrayBinarySearchTree::addBST(int data)
{
    if (data_user == nullptr || isFull())
    {
        if (!resize())
        {
            throw "Error allocating space";
        }
    }
    nodeCount++;
    if (nodeCount == 0)
    {
        data_user[0] = new Node;
        data_user[0]->data = data;
        depth = 0;
        return;
    }
    depth = static_cast<int>(log2(nodeCount));

    int i{1};
    while (i <= size)
    {
        int left = 2 * i;
        int right = left + 1;
        if (left >= size)
        {
            resize();
        }
        if (data_user[left] == nullptr)
        {
            data_user[left] = new Node;
            data_user[left]->data = data;
            return;
        }
        if (right >= size)
        {
            resize();
        }
        if (data_user[right] == nullptr)
        {
            data_user[right] = new Node;
            data_user[right]->data = data;
            return;
        }
        i++;
    }
}

void ArrayBinarySearchTree::removeBST(int key)
{
    int i{1};
    Node *Node_to_delete = nullptr;
    while (i <= size)
    {
        int left = 2 * i;
        int right = left + 1;
        if (left >= size || right >= size)
        {
            break;
        }
        if (data_user[left]->data == key)
        {
            Node_to_delete = data_user[left];
            int right_most = 2 * left + 1;
            while (2 * right_most + 1 < size && data_user[2 * right_most + 1] != nullptr)
            {
                right_most = 2 * right_most + 1;
            }

            if (data_user[right_most] != nullptr)
            {
                Node_to_delete->data = data_user[right_most]->data;
                delete data_user[right_most];
                data_user[right_most] = nullptr;
            }
            else
            {
                Node_to_delete->data = data_user[left]->data;
                delete data_user[left];
                data_user[left] = nullptr;
            }
        }
        if (data_user[right]->data == key)
        {
            Node_to_delete = data_user[right];
            int right_most = 2 * right;
            while (2 * right_most + 1 < size && data_user[2 * right_most + 1] != nullptr)
            {
                right_most = 2 * right_most + 1;
            }

            if (data_user[right_most] != nullptr)
            {
                Node_to_delete->data = data_user[right_most]->data;
                delete data_user[right_most];
                data_user[right_most] = nullptr;
            }
            else
            {
                Node_to_delete->data = data_user[right]->data;
                delete data_user[right];
                data_user[right] = nullptr;
            }
            i++;
        }
    }

    if (Node_to_delete == nullptr)
    {
        std::cout << "The selected element does not exists in the binary tree" << std::endl;
    }
}

int ArrayBinarySearchTree::searchBST(int key)
{
    return 0;
}
bool ArrayBinarySearchTree::resize(int temp_size = 0)
{
    Node *temp = nullptr;
    try
    {
        if (data_user == nullptr)
        {
            data_user = new Node *[10];
            size = 10;
            for (int i = 0; i < 10; i++)
            {
                data_user[i] = nullptr;
            }
            return true;
        }
        if (temp_size == 0)
        {
            temp_size = pow(2, depth) == 1 ? 1 : pow(2, depth + 1) + 1;
            depth++;
        }
        temp = new Node[temp_size * 2];
        int i;
        for (i = 0; i < size; i++)
        {
            temp[i] = *data_user[i];
        }
        for (i = 0; i < size; i++)
        {
            delete data_user[i];
        }
        delete[] data_user;

        data_user = new Node *[temp_size * 2];
        for (int i = 0; i < temp_size; i++)
        {
            data_user[i] = &temp[i];
        }
        size *= 2;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }
}