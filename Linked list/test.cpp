//
// Created by gmspr on 10/18/2022.
//

#include "iostream"
#include "string"
#include "LinkedList.h"

using namespace std;

int main(){
    LinkedList<string> linko;

    linko.insertHead("Faith");
    linko.insertHead("Hope");
    linko.insertHead("Charity");
    linko.insertHead("Faith");

    cout << linko.toString() << endl;

    linko.insertTail("Peace");

    cout << linko.toString() << endl;

    linko.insertAfter("Me", "Charity");

    cout << linko.toString() << endl;

    cout << linko.at(5) << endl;

    cout << linko.size() << endl;

    return 0;

}