//
// Created by gmspr on 11/3/2022.
//

#include <iostream>
#include "BST.h"
#include "Node.h"

using namespace std;

int main(){

    BST* bstptr = new BST();
    Node* ptr = NULL;

    bstptr ->add(4);
    bstptr -> add(3);
    cout << bstptr->getRootNode()->data << endl;
    cout << bstptr->getRootNode()->leftChild->data << endl;
    bstptr->remove(4);

    bstptr->add(4);


    cout << bstptr->getRootNode()->data << endl;

    bstptr->add(5);
    cout << bstptr->getRootNode()->data << endl;
    bstptr->add(5);
    cout << bstptr->getRootNode() -> data << endl;

    bstptr->clear();

    if(bstptr->getRootNode() == NULL){
        cout << "is null" << endl;
    }


    return 0;
}