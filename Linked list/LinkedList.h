//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>
#include "LinkedListInterface.h"
#include "iostream"
#include "sstream"
#include <stdexcept>


using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>{


private:
    struct node {
        node(T _value){
            value = _value;
            next = NULL;
        }
        T value;
        node *next;
    };

    node *head;
    int nodeSize = 0;

public:

    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        clear();
    }

    /*
    insertHead

    A node with the given value should be inserted at the beginning of the list.

    Do not allow duplicate values in the list.
    */
    void insertHead(T value){
        for(node *ptr=head; ptr != NULL; ptr=ptr->next){
            if(value == ptr->value){
                return;
            }
        }
        node *tmp = head;
        head = new node(value);
        head->next = tmp;
        nodeSize++;
    }

    /*
    insertTail

    A node with the given value should be inserted at the end of the list.

    Do not allow duplicate values in the list.
    */
    void insertTail(T value) {
        if(nodeSize == 0){
            head = new node(value);
            nodeSize++;
            return;
        }
        else{
            for(node *ptr=head; ptr != NULL; ptr=ptr->next){
                if (value == ptr->value) {
                    return;
                }
                if(ptr->next == NULL) {
                    ptr->next = new node(value);
                    nodeSize++;
                    return;
                }
            }
        }

    }

    /*
    insertAfter

    A node with the given value should be inserted immediately after the
    node whose value is equal to insertionNode.

    A node should only be added if the node whose value is equal to
    insertionNode is in the list. Do not allow duplicate values in the list.
    */
    void insertAfter(T value, T insertionNode){
        bool val = false;
        for(node *ptr=head; ptr != NULL; ptr=ptr->next) {
            if (value == ptr->value) {
                return;
            }
        }
        for(node *ptr=head; ptr != NULL; ptr=ptr->next) {
            if(ptr->value == insertionNode){
                val = true;
                node *tmp = ptr->next;
                ptr->next = new node(value);
                ptr->next->next = tmp;
                nodeSize++;
                return;
            }
        }
        if (val == false){
            return;
        }

    }

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    void remove(T value){
        if(nodeSize == 0){
            return;
        }
        node *tmp = head;

        // special case for head
        if(value == head->value){
            head = tmp->next;
            delete tmp;
            nodeSize--;
            return;
        }

        bool val = false;
        for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
            if (value == ptr->value) {
                val = true;
                break;
            }
        }

        if(val == false){
            return;
        }


        for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
            if (value == ptr->next->value) {
                node *temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
                nodeSize--;
                return;
            }
        }
    }

    /*
    clear

    Remove all nodes from the list.
    */
    void clear() {
            node *ptr;
            node *prev;
            ptr = head;
            if (nodeSize == 0){
                return;
            }
            while (ptr->next != NULL){
                prev = ptr;
                ptr = ptr->next;
                delete prev;
            }

            delete ptr;
            head = NULL;
            nodeSize = 0;
    }

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index){
        if ((index < 0) || (index >= size())) {
            throw out_of_range("out of range");
        }

        else{
            T val;
            int i = 0;
            for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
                if(i == index){
                    val = ptr->value;
                    break;
                }
                i++;
            }
            return val;
        }
    }

    /*
    size

    Returns the number of nodes in the list.
    */
    int size(){
        return nodeSize;
    }

    /*
    toString

    Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
    There should be no trailing space at the end of the string

    For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
    "1 2 3 4 5"
    */
    string toString(){
        if(nodeSize == 0){
            return "";
        }

        else{
            stringstream ss;

            node *current = head;
            while (current != NULL){
                if(current->next == NULL){
                    ss << current->value;
                }
                else{
                    ss << current->value << " ";
                }
                current = current->next;
            }

            return ss.str();
        }
    }

};
