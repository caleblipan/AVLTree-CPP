<h2>Warning: this is going to be a very long documentation.</h2>
There are 3 functionalities in AVLTrees:
1. Insert
2. Search
3. Delete

Currently, there is only one functionality, and that is insertion using the ```insertValue()``` function. I will be adding more in the future.
<h2>insertValue()</h2>
We try to insert the number 10 as the root of the tree

```
    tree->root = tree->insertValue(tree->root, 10);
```

Since root is initially null, function uses the first if statementIt call the Node constructor and initializes the ```key``` value in the Node class to be 10 and ```height``` = 1
The function then ends immediately in the function's first If statement
The return value is put into the root, therefore initializing it.
<br>
<br>
Then, we would like to add the number 5 to the tree.
The pointer to node 10, which is previously added above, is added to the first parameter of the second insertValue() function.
```
    tree->root = tree->insertValue(tree->root, 5);
```
Since nodePointer is not null (previously added), it skips the first If statement
Then, the number 5 (key) is compared with the number 10 (nodePointer->key)
Since 5 is actually smaller than 10, it calls the Left node class pointer.
Then, it uses the ```insertValue()``` function with the left node pointer as the first argument.
Since the left node pointer is null, function uses the first if statement, which calls the Node constructor and initializes the ```key``` value in the Node class to be 5 and ```height = 1```.
The function then ends immediately in the function's first If statement.
The return value is put into the Left node pointer

Now, the previous Node pointer, which points to the node 10, takes the height value, which was previously 1
then reinitializes it with the ```maxiumum()``` function
the ```maximum()``` function has 2 parameters: the ```height(nodePointer->left)``` 
and ```height(nodePointer->right)```.
```the height(nodePointer->left)``` has the return value of 1
the ```height(nodePointer->right)``` has the return value of 0 (right is NULL)
Therefore, the maxiumum would be 1
The height, which is pointed by the previous Node pointer, will be 1 (constant) + 1 = 2
						   
Now, the entire function looks for the balance value
It uses the ```getBalance()``` function with the pointer to node 10
then it subtracts ```height(nodePointer->left)``` with ```height(nodePointer-right)```.
the ```height(nodePointer->left)``` has the return value of 1
the ```height(noePointer->right)``` has the return value of 0 (right is NULL)
Subtract both of them to get 1
```
int balance = 1
```
Since the balance is only 1 and not more, it immediately returns the nodePointer, which is still the pointer to the node 10 (the first one)
Therefore, 
```
tree->root = nodePointer
```
in which nodePointer is the pointer to node 10
<br>
<br>
Then, we would like to add the number 20 into the AVL Tree.
```				   
tree->root = tree->insertValue(tree->root, 20); // The pointer to node 10 is added to the first parameter
```
Since the nodePointer is not null, the first If statement is skipped.
Then, the number 20 is compared with the number 10 (nodePointer->key)
Since 20 is bigger than 10, it calls the right Node class pointer
Then, it initializes the variable with the insertValue() function with the right Node class pointer as the first argument.
Since the right pointer is NULL, function uses the first If statement, which class the Node constructor and assigns the key in the Node class to be 20 and height 1
The function then ends immediately in the function's first If statement.
The return value is put into the right Node pointer.
						    
Now, the nodePointer takes the height value, then reinitializes it:
```
nodePointer->height = 1 + maximum(height(nodePointer->left), height(nodePointer->right))
```
The ```height(nodePointer->left)``` has the return value of 1
The ```height(nodePointer->right)``` has the return value of 1 as well
Therefore, the maximum would be 1
The ```nodePointer->height``` would be:
1 + 1 = 2
						    
Now, the entire function looks for the balance value:
```
int balance = getBalance(nodePointer)
```
then it subtracts ```height(nodePointer->left)``` with ```height(nodePointer->right)```
The ```height(nodePointer->left)``` has the return value of 1
The ```height(nodePointer->right)``` has the return value of 1
Subtract both of them to get 0
```                
int balance = 0
```
Since the balance is still 0, which is BALANCED, it immediately returns the nodePointer
which is still the pointer to the node 10 (the first one)
Therefore, 
```
tree->root = nodePointer
```
As you can see here, the root never changes :)
