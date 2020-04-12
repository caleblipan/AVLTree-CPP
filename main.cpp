#include <iostream>
#include <memory>

using std::cout;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

class Node
{
public:
    int key, height;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int _key)
    {
        key = _key;
        height = 1;
    }
};

class AVLTree
{
private:
    int height(shared_ptr<Node> nodePointer)
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
    shared_ptr<Node> root;
    int randomNumber;

    shared_ptr<Node> rightRotate(shared_ptr<Node> y)
    {
        shared_ptr<Node> x = y->left;
        shared_ptr<Node> T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = maximum(height(y->left), height(y->right)) + 1;
        x->height = maximum(height(x->left), height(x->right)) + 1;

        return x;
    }

    shared_ptr<Node> leftRotate(shared_ptr<Node> x)
    {
        shared_ptr<Node> y = x->right;
        shared_ptr<Node> T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = maximum(height(x->left), height(x->right)) + 1;
        y->height = maximum(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(shared_ptr<Node> nodePointer)
    {
        if (nodePointer == NULL)
            return 0;

        return height(nodePointer->left) - height(nodePointer->right);
    }

    shared_ptr<Node> insertValue(shared_ptr<Node> nodePointer, int key)
    {
        if (nodePointer == NULL)
        {
            nodePointer = make_shared<Node>(key);
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

    void preOrder(shared_ptr<Node> nodePointer)
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
    unique_ptr<AVLTree> tree = make_unique<AVLTree>();

    tree->root = tree->insertValue(tree->root, 10);// Since root is initially null, function uses the first if statement
    						   // which call the Node constructor and initializes the key value in the Node class to be 10
						   // and height = 1
						   // the function then ends immediately in the function's first If statement
						   // the return value is put into the root, therefore initializing it.

    tree->root = tree->insertValue(tree->root, 5); // The pointer to node 10, which is previously added above, is added to the first parameter
    						   // Since nodePointer is not null (previously added), it skips the first If statement
						   // then, the number 5 (key) is compared with the number 10 (nodePointer->key)
						   // Since 5 is actually smaller than 10, it calls the Left node class pointer.
						   // Then, it uses the insertValue() function with the left node pointer as the first argument
						   // Since the left node pointer is null, function uses the first if statement
						   // which calls the Node constructor and initializes the key value in the Node class to be 5
						   // and height = 1
						   // the function then ends immediately in the function's first If statement
						   // the return value is put into the Left node pointer

    					           // Now, the previous Node pointer, which points to the node 10, takes the height value,
						   // which was previously 1
						   // then reinitializes it with the maxiumum() function
						   // the maximum() function has 2 parameters: the height(nodePointer->left)... 
						   // and height(nodePointer->right)
						   // the height(nodePointer->left) has the return value of 1
						   // the height(nodePointer->right) has the return value of 0 (right is NULL)
						   // Therefore, the maxiumum would be 1
						   // The height, which is pointed by the previous Node pointer, will be 1 (constant) + 1 = 2
						   
						   // Now, the entire function looks for the balance value
						   // It uses the getBalance() function with the pointer to node 10
						   // then it subtracts height(nodePointer->left) with height(nodePointer-right)
						   // the height(nodePointer->left) has the return value of 1
						   // the height(noePointer->right) has the return value of 0 (right is NULL)
						   // Subtract both of them to get 1
						   // int balance = 1
						   // Since the balance is only 1 and not more, it immediately returns the nodePointer
						   // which is still the pointer to the node 10 (the first one)
						   // Therefore, tree->root = nodePointer, in which nodePointer is the pointer to node 10
						   
    tree->root = tree->insertValue(tree->root, 20); // The pointer to node 10 is added to the first parameter
  						    // Since the nodePointer is not null, the first If statement is skipped
						    // then, the number 20 is compared with the number 10 (nodePointer->key)
						    // Since 20 is bigger than 10, it calls the right Node class pointer
						    // Then, it initializes the variable with the insertValue() function, 
						    // with the right Node class pointer as the first argument.
						    // Since the right pointer is NULL, function uses the first If statement,
						    // which class the Node constructor and assigns the key in the Node class to be 20
						    // and height 1
						    // The function then ends immediately in the function's first If statement.
						    // The return value is put into the right Node pointer.
						    
    						    // Now, the nodePointer takes the height value, then reinitializes it:
						    // nodePointer->height = 1 + maximum(height(nodePointer->left), height(nodePointer->right))
						    // the height(nodePointer->left) has the return value of 1
						    // the height(nodePointer->right) has the return value of 1 as well
						    // Therefore, the maximum would be 1
						    // The nodePointer->height would be:
						    // 1 + 1 = 2
						    
   						    // Now, the entire function looks for the balance value.
						    // int balance = getBalance(nodePointer)
						    // then it subtracts height(nodePointer->left) with height(nodePointer->right)
						    // the height(nodePointer->left) has the return value of 1
						    // the height(nodePointer->right) has the return value of 1
						    // Subtract both of them to get 0
						    // int balance = 0
						    // Since the balance is still 0, which is BALANCED, it immediately returns the nodePointer
						    // which is still the pointer to the node 10 (the first one)
						    // Therefore, tree->root = nodePointer

    tree->preOrder(tree->root); // Guess what's the output?

    return 0;
}
