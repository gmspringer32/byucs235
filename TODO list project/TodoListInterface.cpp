//
// Created by gmspr on 9/13/2022.
//

#include "TodoListInterface.h"

//
// Created by gmspr on 9/6/2022.
//

#ifndef TODO_LIST_PROJECT_TODOLISTINTERFACE_1_H
#define TODO_LIST_PROJECT_TODOLISTINTERFACE_1_H
#include <iostream>
#include <fstream>
#include <string>
#include <Vector>
using namespace std;


vector<string> readFile() {
    ifstream input;
    input.open("TODOlist.txt");
    if (!input) {
        cout << "TODOlist.txt not found" << endl;
        exit(-1);
    }
    vector<string> list;
    while (!input.eof()) {
        string linea;
        getline(input, linea);
        if (linea.length() >= 2)
            list.push_back(linea);
    }
    input.close();
    return list;
}

int addItem(int argc, char *argv[]){
    if(argc < 4){
        cout << "Error there are not enough inputs" << endl;
        return -1;
    }
    //open file
    ofstream myfile;
    myfile.open ("TODOlist.txt", ios::app);
    //write to the end of the file
    myfile << argv[2] << " - " << argv[3] << endl;
    //close the file
    myfile.close();
}

int removeItem(int argc, char *argv[]){
    if(argc < 3){
        cout << "Error" << endl;
        return -1;
    }
    // second, read task into a vector
    vector<string> list = readFile();

    // third, remove the specified task
    string badTask= argv[2];
    int index;
    for (index = 0; index < list.size(); index++) {
        if (list[index].find(badTask) != string::npos)
            break;
    }
    if (index < list.size()) {
        cout << "removing: " << list[index] << endl;
        list.erase(list.begin()+index);
    }
    // fourth, write the vector back out to the file
    ofstream output("TODOlist.txt");
    for (int i = 0; i < list.size(); i++) {
        output << list.at(i) << endl;
    }

    output.close();
}

int printList(int argc, char *argv[]){
    if (argc != 2){
        cout << "Error: invalid number of arguments" << endl;
        return -1;
    }
    vector<string> list = readFile();
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << endl;
    }
}

int printDay(int argc, char *argv[]){
    if (argc != 3){
        cout << "Error: invalid number of arguments" << endl;
        return -1;
    }

    string day = argv[2];
    vector<string> list = readFile();

    for (int i = 0; i < list.size(); i++){
        bool found = list[i].find(day) != string::npos;
        if (found){
            cout << list[i].substr(list[i].find("- ") + 1) << endl;
        }
        else{
            continue;
        }
    }
}

#endif //TODO_LIST_PROJECT_TODOLISTINTERFACE_1_H