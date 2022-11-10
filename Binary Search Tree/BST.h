//
// Created by gmspr on 11/2/2022.
//

#ifndef LAB7_BST_H
#define LAB7_BST_H

#pragma once

#include "Node.h"
#include "BSTInterface.h"


using namespace std;

class BST : public BSTInterface{
protected:
    Node *root;

public:
    BST();
    ~BST();

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface

    /*
    * Returns the root node for this tree
    *
    * @return the root node for this tree.
    */
    Node * getRootNode() const;

    /*
    * Attempts to add the given int to the BST tree
    *
    * @return true if added
    * @return false if unsuccessful (i.e. the int is already in tree)
    */
    bool add(int data);

    /*
    * Attempts to remove the given int from the BST tree
    *
    * @return true if successfully removed
    * @return false if remove is unsuccessful(i.e. the int is not in the tree)
    */
    bool remove(int data);

    /*
    * Removes all nodes from the tree, resulting in an empty tree.
    */
    void clear();

    bool search(int _val, Node* Tr);

    bool insert(int _val, Node* &Tr);

    bool removeAt(int _val, Node* &Tr);

    bool recursiveClear(Node* ptr);


};

#endif //LAB7_BST_H
