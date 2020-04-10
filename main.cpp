#include <iostream>

using std::cout;

class Node
{
public:
    int key, height;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int _key)
    {
        key = _key;
        height = 1;
    }
};

class AVLTree
{
private:
    int height(Node* nodePointer)
    {
        if (nodePointer == NULL)
            return 0;
        return nodePointer->height;
    }

    int maximum(int a, int b)
    {
        return (a > b) ? a : b;
    }

public:
    Node* root = nullptr;

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = maximum(height(y->left), height(y->right)) + 1;
        x->height = maximum(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = maximum(height(x->left), height(x->right)) + 1;
        y->height = maximum(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node* nodePointer)
    {
        if (nodePointer == NULL)
            return 0;

        return height(nodePointer->left) - height(nodePointer->right);
    }

    Node* insertValue(Node* nodePointer, int key)
    {
        if (nodePointer == NULL)
        {
            nodePointer = new Node(key);
            return nodePointer;
        }

        if (key < nodePointer->key)
            nodePointer->left = insertValue(nodePointer->left, key);
        else if (key > nodePointer->key)
            nodePointer->right = insertValue(nodePointer->right, key);

        nodePointer->height = 1 + maximum(height(nodePointer->left), height(nodePointer->right));

        int balance = getBalance(nodePointer);

        // Right rotation
        if (balance > 1 && key < nodePointer->left->key)
        {
            return rightRotate(nodePointer);
        }

        // Left rotation
        if (balance < -1 && key > nodePointer->right->key)
        {
            return leftRotate(nodePointer);
        }

        // Left-right rotation
        if (balance > 1 && key > nodePointer->left->key)
        {
            nodePointer->left = leftRotate(nodePointer->left);

            return rightRotate(nodePointer);
        }

        // Right-Left rotation
        if (balance < -1 && key < nodePointer->right->key)
        {
            nodePointer->right = rightRotate(nodePointer->right);

            return leftRotate(nodePointer);
        }

        return nodePointer;
    }

    void preOrder(Node* nodePointer)
    {
        if (nodePointer != nullptr)
        {
            cout << nodePointer->key << " ";
            preOrder(nodePointer->left);
            preOrder(nodePointer->right);
        }
    }
};

int main()
{
    AVLTree* tree = new AVLTree();

    tree->root = tree->insertValue(tree->root, 10);
    tree->root = tree->insertValue(tree->root, 20);
    tree->root = tree->insertValue(tree->root, 30);
    tree->root = tree->insertValue(tree->root, 40);
    tree->root = tree->insertValue(tree->root, 50);
    tree->root = tree->insertValue(tree->root, 5);

    tree->preOrder(tree->root); // Guess what's the output?

    delete tree;

    return 0;
}
