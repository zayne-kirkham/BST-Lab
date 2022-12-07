

#pragma once

#include <iostream>
#include "Node.h"

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const{
//    cout << "Value = " << value << endl;
    return value;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface* Node::getLeftChild() const{
    return left;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface* Node::getRightChild() const{
    return right;
}

