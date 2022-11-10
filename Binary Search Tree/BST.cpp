//
// Created by gmspr on 11/2/2022.
//

#include "BST.h"

BST::BST() {
    root = NULL;
}


BST::~BST() {clear();}


Node *BST::getRootNode() const {
    return root;
}


bool BST::add(int data) {
    return insert(data, root);
}


bool BST::insert(int _val, Node* &Tr) {

    //if the value is already in the tree don't add it
    if(search(_val, Tr)){
        return false;
    }

    //if the current node (root) is NULL then add a new node with the value to insert
    if(Tr == NULL){
        Tr = new Node(_val);
        return true;
    }

    //if the value to insert is less than the data in the current node recursively call insert with the leftChild
    if(_val < Tr->data){
        return insert(_val, Tr->leftChild);
    }

    //if the value to insert is greater than the data in the current node recursively call insert with the rightChild
    if(_val > Tr->getData()){
        return insert(_val, Tr->rightChild);
    }
}

bool BST::remove(int data) {
    return removeAt(data, root);
}


bool BST::removeAt(int _val, Node* &Tr){

    //if the node (root) is NULL then you cannot remove anything
    if(Tr == NULL){
        return false;
    }

    //if the value is not found in the tree you cannot remove it
    if(!search(_val, Tr)){
        return false;
    }

    //go down the left subtree if the value is less than the data in the node
    if(_val < Tr->data){
        return removeAt(_val, Tr->leftChild);
    }

    //go down the right subtree if the value is greater than the data in the node
    if(_val > Tr->data) {
        return removeAt(_val, Tr->rightChild);
    }

    // once you find the node with the data that you are trying to remove
    else if(_val == Tr->data){

        //if there is no right or left child remove the current node without any replacements
        if(Tr->rightChild == NULL && Tr->leftChild == NULL){
            delete Tr;
            Tr = NULL;
            return true;
        }

        //if there is only a left child, set current node as a temp, point Tr to its left child, and delete temp
        if(Tr->rightChild == NULL && Tr->leftChild != NULL){
            Node *temp = Tr;
            Tr = Tr->leftChild;
            delete temp;
            temp = NULL;
            return true;
        }

        //if there is only a right child, set current node as a temp, point Tr to its right child, and delete temp
        if(Tr->rightChild != NULL && Tr->leftChild == NULL){
            Node *temp = Tr;
            Tr = Tr->rightChild;
            delete temp;
            temp = NULL;
            return true;
        }

        //if there is both a left and right child find the in order predecessor (next biggest)
        else{
            Node* temp = Tr -> leftChild;
            //find the most right node of its left subtree
            while(temp->rightChild != NULL){
                temp = temp->rightChild;
            }
            //store the most right node data in the current node
            Tr->data = temp->data;
            removeAt(Tr->data, Tr->leftChild);
            return true;
        }

    }
}

void BST::clear() {
    recursiveClear(this -> root);
    this -> root = NULL;
}


bool BST::recursiveClear(Node *ptr) {
    if(ptr != NULL){
        recursiveClear(ptr->getLeftChild());
        recursiveClear(ptr->getRightChild());
        delete ptr;
    }
    return true;
}


bool BST::search(int _val, Node* Tr) {
    if(Tr == NULL){
        return false;
    }
    if(_val == Tr->data){
        return true;
    }
    if(_val < Tr->data){
        return search(_val, Tr->leftChild);
    }
    if(_val > Tr->getData()){
        return search(_val, Tr->rightChild);
    }

}



