#include "BST.h"


binaryTree::binaryTree()
{
    root = NULL;
}

//bool binaryTree::isEmpty() const
//{
//    return (root == NULL);
//}

void binaryTree::inorderTraversal() const
{
    inorder(root);
}

void binaryTree::preorderTraversal() const
{
    preorder(root);
}

void binaryTree::postorderTraversal() const
{
    postorder(root);
}

int binaryTree::treeHeight() const
{
    return height(root);
}

//void  binaryTree::copyTree
//                       (Node* &copiedTreeRoot,
//                        Node* otherTreeRoot)
//{
//    if (otherTreeRoot == NULL)
//        copiedTreeRoot = NULL;
//    else
//    {
//        copiedTreeRoot = new Node;
//        copiedTreeRoot->info = otherTreeRoot->info;
//        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
//        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
//    }
//} //end copyTree

void binaryTree::inorder(Node *p) const
{
    if (p != NULL)
    {
        inorder(p->leftLink);
        cout << p->info << " ";
        inorder(p->rightLink);
    }
}

void binaryTree::preorder(Node *p) const
{
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->leftLink);
        preorder(p->rightLink);
    }
}

void binaryTree::postorder(Node *p) const
{
    if (p != NULL)
    {
        postorder(p->leftLink);
        postorder(p->rightLink);
        cout << p->info << " ";
    }		
}

   //Overload the assignment operator
//template <class elemType>
//const binaryTreeType<elemType>& binaryTreeType<elemType>::
//        operator=(const binaryTreeType<elemType>& otherTree)
//{ 
//    if (this != &otherTree) //avoid self-copy
//    {
//        if (root != NULL)   //if the binary tree is not empty,
//                            //destroy the binary tree
//            destroy(root);
//
//        if (otherTree.root == NULL) //otherTree is empty
//            root = NULL;
//        else
//            copyTree(root, otherTree.root);
//    }//end else
//
//    return *this; 
//}

void  binaryTree::destroy(Node* &p)
{
    if (p != NULL)
    {
        destroy(p->leftLink);
        destroy(p->rightLink);
        delete p;
        p = NULL;
    }
}

void  binaryTree::destroyTree()
{
    destroy(root);
}

	//copy constructor
//template <class elemType>
//binaryTreeType<elemType>::binaryTreeType
//                (const binaryTreeType<elemType>& otherTree)
//{
//    if (otherTree.root == NULL) //otherTree is empty
//        root = NULL;
//    else
//        copyTree(root, otherTree.root);
//}

    //Destructor
binaryTree::~binaryTree()
{
    destroy(root);
}

void binaryTree::deleteNode(const int& deleteItem)
{
    Node *current; //pointer to traverse the tree
    Node *trailCurrent; //pointer behind current
    bool found = false;

    if (root == NULL)
        cout << "Cannot delete from an empty tree." 
             << endl;
    else
    {
        current = root;
        trailCurrent = root;

        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->leftLink;
                else
                    current = current->rightLink;
            }
        }//end while

        if (current == NULL)
            cout << "The item to be deleted is not in the tree." 
                 << endl;
        else if (found)
        {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->leftLink);
            else
                deleteFromTree(trailCurrent->rightLink);
        }
        else
            cout << "The item to be deleted is not in the tree."
                 << endl;
    }
} //end deleteNode

void binaryTree::deleteFromTree(Node* &p)
{
    Node *current; //pointer to traverse the tree
    Node *trailCurrent;  //pointer behind current
    Node *temp;      //pointer to delete the node

    if (p == NULL)
        cout << "Error: The node to be deleted is NULL."
             << endl;
    else if (p->leftLink == NULL && p->rightLink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->leftLink == NULL)
    {
        temp = p;
        p = temp->rightLink;
        delete temp;
    }
    else if (p->rightLink == NULL)
    {
        temp = p;
        p = temp->leftLink;
        delete temp;
    }
    else
    {
        current = p->leftLink;
        trailCurrent = NULL;

        while (current->rightLink != NULL)
        {
            trailCurrent = current;
            current = current->rightLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == NULL) //current did not move; 
                               //current == p->lLink; adjust p
            p->leftLink = current->leftLink;
        else
            trailCurrent->rightLink = current->leftLink;
 
        delete current;
    }//end else
} //end deleteFromTree

int binaryTree::height(Node *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->leftLink), height(p->rightLink));
}

bool binaryTree::search(const int& searchItem) const
{
    Node *current;
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

void binaryTree::insert(const int& insertItem)
{
	Node *current; //pointer to traverse the tree
    Node *trailCurrent; //pointer behind current
    Node *newNode;  //pointer to create the node

    newNode = new Node;
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
                /*cout << "The item to be inserted is already ";
                cout << "in the tree -- duplicates are not "
                     << "allowed." << endl;
                return;*/
				if(insertItem < current->info)
					current=current->rightLink;
				else
					current=current->leftLink;
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

//int binaryTree::max(int x, int y) const
//{
//    if (x >= y)
//        return x;
//    else
//        return y;
//}

//template <class elemType>
//int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
//{
//    cout << "Write the definition of the function nodeCount."
//         << endl;
//
//    return 0;
//}

//template <class elemType>
//int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
//{
//    cout << "Write the definition of the function leavesCount."
//         << endl;
//
//    return 0;
//}