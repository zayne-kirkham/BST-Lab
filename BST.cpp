
#pragma once

#include "BST.h"
#include <queue>

using namespace std;

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface* BST::getRootNode() const{
   // cout << "Returning root node. Root value = " << root -> value << endl;
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
    cout << "attempting to add"<< data << endl;
    return insert(data, root);
}

bool BST::insert(int _val, Node *&localRoot){
    // if root is null, add
    if (localRoot == NULL){
        localRoot = new Node(_val);
        return true;
    }

    // else checks the values
    if (localRoot->value == _val){
        return false;
    }
    else if (localRoot->value > _val){
        return insert(_val, localRoot->left);
    }
    else if (localRoot->value < _val){
        return insert(_val, localRoot->right);
    }
    else
        return false;
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data){
    cout << "attempting to remove"<< data << endl;
    return remove_val(data, root);
}

bool BST::remove_val(int _val, Node *&localRoot){
    //Checks if the tree is empty
    if (localRoot == NULL){
        return false;
    }

    // Checks to see if the node matches the data
    if (localRoot->value == _val){
        // If node holds the value and there are no children, delete node
        if (localRoot->left == NULL && localRoot->right == NULL){
            cout << "removing" << endl;
            cout << "left = " << localRoot->left << endl;
            cout << "right = " << localRoot->right << endl;
            cout << "value = " << localRoot->value << endl;
            delete localRoot;
            localRoot =  NULL;
            cout << "set to null" << endl;
//            cout << "left = " << localRoot->getLeftChild() << endl;
//            cout << "right = " << localRoot->getRightChild() << endl;
//            cout << "value = " << localRoot->getData() << endl;
//            cout  << "foo bar" << endl;
            return true;
        }

        // no right child
        if (localRoot->right == NULL && localRoot->left != NULL){
            Node* Temp_Node = localRoot;
            localRoot = Temp_Node->left; // replaces the deleted node with its child
            delete Temp_Node;
            return true;
        }
        // no left child
        else if (localRoot->left == NULL && localRoot->right !=NULL){
            Node* Temp_Node = localRoot;
            localRoot = Temp_Node->right; // replaces the deleted node with its child
            delete Temp_Node;
            return true;
        }
        // if both children are present
        else{
            // finds the pivot node
            Node* Temp_Node = inOrderPredecessor(localRoot);
            cout << "pivot node val = " << Temp_Node->value << endl;

            //overides node with pivot node value
            localRoot->value = Temp_Node->value;

            //Removes pivot node
            return remove_val(Temp_Node->value, localRoot->left);
        }
    }
    // Checks the right branch
    else if (localRoot->value < _val){
        return remove_val(_val, localRoot->right);

    }
    // checks the left branch
    else if (localRoot->value > _val){
        return remove_val(_val, localRoot->left);

    }
    else
        return false;
}

Node* BST::inOrderPredecessor(Node *&localRoot){
    // finds the rightmost value on the left branch for the pivot
    Node* leftChild = localRoot->left;
    if (leftChild->right == NULL)
        return leftChild;
    else{
        while (leftChild->right != NULL){
            leftChild = leftChild->right;
        }
        return leftChild;
    }
}


/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear(){
    cout << "Clearing your BST ... ";
    remove_everything(root);
    root = NULL;
}

void BST::remove_everything(Node *&localRoot){
    // Base case
    if (localRoot ==NULL)
        return;

    //traverse right branch
    if (localRoot->right != NULL)
        remove_everything(localRoot->right);

    //Traverse left branch
    if (localRoot->left != NULL)
        remove_everything(localRoot->left);

    //if at the bottom of branch, remove it.
    if (localRoot->right == NULL && localRoot->left ==NULL){
        delete localRoot;
        localRoot ==NULL;
        return;
    }
}
