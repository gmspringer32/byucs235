//
// Created by gmspr on 11/2/2022.
//

#include "Node.h"

using namespace std;

Node::Node(int the_data, Node* left_val, Node* right_val) {
    data = the_data;
    leftChild = left_val;
    rightChild = right_val;
}

Node::~Node() {}

int Node::getData() const {
    return data;
}

Node *Node::getLeftChild() const {
    return leftChild;
}

Node *Node::getRightChild() const {
    return rightChild;
}
