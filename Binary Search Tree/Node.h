//
// Created by gmspr on 11/2/2022.
//

#ifndef LAB7_NODE_H
#define LAB7_NODE_H
#pragma once

#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface{

public:
    Node(int the_data, Node* left_val = NULL, Node* right_val = NULL);
    ~Node();

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
    Node * getLeftChild() const;

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    Node * getRightChild() const;

    Node* leftChild;
    Node *rightChild;
    int data;
};

#endif //LAB7_NODE_H
