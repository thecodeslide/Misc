#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class elemType>
struct Node
{
	elemType info;
	Node<elemType> *rightLink;
	Node<elemType> *leftLink;
};

template <class elemType>
class binaryTree
{
protected:
	Node<elemType>  *root;
private:
	void copyTree(Node<elemType>* &copiedTreeRoot, Node<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. 
      //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.

    void destroy(Node<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: Memory space occupied by each node, in 
      //               the binary tree to which p points, is 
      //               deallocated.
      //               p = NULL;

    void inorder(Node<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in inorder sequence.

public:
	const binaryTree& operator=(const binaryTree&); 
      //Overload the assignment operator.

    bool isEmpty() const;
      //Function to determine whether the binary tree is empty.
      //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.

	void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: Nodes are printed in inorder sequence.

//	void deleteNode(const elemType& deleteItem);
    void destroyTree();
      //Function to destroy the binary tree.
      //Postcondition: Memory space occupied by each node 
      //               is deallocated.
      //               root = NULL;

    bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the binary 
      //search tree.
      //Postcondition: Returns true if searchItem is found in 
      //               the binary search tree; otherwise, 
      //               returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If there is no node in the binary search
      //               tree that has the same info as 
      //               insertItem, a node with the info 
      //               insertItem is created and inserted in the
      //               binary search tree.

//	void getList(ifstream&);  

	binaryTree(const binaryTree& otherTree); 
      //Copy constructor

    binaryTree();   
      //Default constructor

    ~binaryTree();   
      //Destructor
};

//implementation
template <class elemType>
binaryTree<elemType>::binaryTree()
{
    root = NULL;
}

template <class elemType>
void binaryTree<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void  binaryTree<elemType>::copyTree
                       (Node<elemType>* &copiedTreeRoot,
                        Node<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new Node<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->leftLink, otherTreeRoot->leftLink);
        copyTree(copiedTreeRoot->rightLink, otherTreeRoot->rightLink);
    }
} //end copyTree

template <class elemType>
void binaryTree<elemType>::inorder(Node<elemType> *p) const
{
    if (p != NULL)
    {
        inorder(p->leftLink);
        cout << p->info << " ";
        inorder(p->rightLink);
    }
}

   //Overload the assignment operator
template <class elemType>
const binaryTree<elemType>& binaryTree<elemType>::
        operator=(const binaryTree<elemType>& otherTree)
{ 
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)   //if the binary tree is not empty,
                            //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  binaryTree<elemType>::destroy(Node<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->leftLink);
        destroy(p->rightLink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void  binaryTree<elemType>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class elemType>
binaryTree<elemType>::binaryTree
                (const binaryTree<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

    //Destructor
template <class elemType>
binaryTree<elemType>::~binaryTree()
{
    destroy(root);
}

template <class elemType>
bool binaryTree<elemType>::search(const elemType& searchItem) const
{
    Node<elemType> *current;
    bool found = false;

    if (root == NULL)
        cout << "Cannot search an empty tree." << endl;
    else
    { 
       current = root;

       while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->leftLink;
            else
                current = current->rightLink;
        }//end while
    }//end else

    return found;
}//end search

template <class elemType>
void binaryTree<elemType>::insert(const elemType& insertItem)
{
	Node<elemType> *current; //pointer to traverse the tree
    Node<elemType> *trailCurrent; //pointer behind current
    Node<elemType> *newNode;  //pointer to create the node

    newNode = new Node<elemType>;
    newNode->info = insertItem;
    newNode->leftLink = NULL;
    newNode->rightLink = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
 
        while (current != NULL)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                return;
            }
            else if (current->info > insertItem)
                current = current->leftLink;
            else
                current = current->rightLink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->leftLink = newNode;
        else
            trailCurrent->rightLink = newNode;
    }
}//end insert

#endif
