//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include <iostream>
#include "NodeInterface.h"

class Node : NodeInterface {
friend class BST;

private:
    int value;
    Node* left = NULL;
    Node* right = NULL;

public:
//    double value;
//    Node *left, *right = NULL;
//
//    Node(){
//        //cout << "Node constructor "<< endl;
//        value = -99999;
//        left = right = NULL;
//    }

    Node(int _data){
        //cout << "Node constructor" << endl;
        value = _data;
//        left = right = NULL;
    }

    ~Node(){}

    /*
    * Returns the data that is stored in this node
    *
    * @return the data that is stored in this node.
    */
    int getData() const;

    /*
    * Returns the left child of this node or null if it doesn't have one.
    *
    * @return the left child of this node or null if it doesn't have one.
    */
    NodeInterface * getLeftChild() const;

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    NodeInterface * getRightChild() const;

};