//
// Created by gmspr on 9/13/2022.
//

#ifndef TODO_LIST_PROJECT_TODOLIST_H
#define TODO_LIST_PROJECT_TODOLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <Vector>
#include "TodoListInterface.h"
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


class TodoList : public TodoListInterface {
public:
    TodoList(){}
    ~TodoList() {}

    /*
    *   Adds an item to the todo list with the data specified by the string
"_duedate" and the task specified by "_task"
    */
    void add(string _duedate, string _task){
        //open file
        ofstream myfile;
        myfile.open ("TODOlist.txt", ios::app);
        //write to the end of the file
        myfile << _duedate << " - " << _task << endl;
        //close the file
        myfile.close();
    }
    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    int remove(string _task){
        vector<string> list = readFile();

        // third, remove the specified task
        string badTask= _task;
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
    /*
    *   Prints out the full todo list to the console
    */
    void printTodoList(){
        vector<string> list = readFile();
        for (int i = 0; i < list.size(); i++){
            cout << list[i] << endl;
        }
    }

    /*
    *   Prints out all items of a todo list with a particular due date (specified
by _duedate)
    */
    void printDaysTasks(string _date){
        string day = _date;
        vector<string> list = readFile();

        for (int i = 0; i < list.size(); i++) {
            bool found = list[i].find(day) != string::npos;
            if (found) {
                cout << list[i].substr(list[i].find("- ") + 1) << endl;
            } else {
                continue;
            }
        }
    }
};





//
//
//int addItem(int argc, char *argv[]){
//    if(argc < 4){
//        cout << "Error there are not enough inputs" << endl;
//        return -1;
//    }
//    //open file
//    ofstream myfile;
//    myfile.open ("TODOlist.txt", ios::app);
//    //write to the end of the file
//    myfile << argv[2] << " - " << argv[3] << endl;
//    //close the file
//    myfile.close();
//}
//
//int removeItem(int argc, char *argv[]){
//    if(argc < 3){
//        cout << "Error" << endl;
//        return -1;
//    }
//    // second, read task into a vector
//    vector<string> list = readFile();
//
//    // third, remove the specified task
//    string badTask= argv[2];
//    int index;
//    for (index = 0; index < list.size(); index++) {
//        if (list[index].find(badTask) != string::npos)
//            break;
//    }
//    if (index < list.size()) {
//        cout << "removing: " << list[index] << endl;
//        list.erase(list.begin()+index);
//    }
//    // fourth, write the vector back out to the file
//    ofstream output("TODOlist.txt");
//    for (int i = 0; i < list.size(); i++) {
//        output << list.at(i) << endl;
//    }
//
//    output.close();
//}
//
//int printList(int argc, char *argv[]){
//    if (argc != 2){
//        cout << "Error: invalid number of arguments" << endl;
//        return -1;
//    }
//    vector<string> list = readFile();
//    for (int i = 0; i < list.size(); i++){
//        cout << list[i] << endl;
//    }
//}
//
//int printDay(int argc, char *argv[]){
//    if (argc != 3){
//        cout << "Error: invalid number of arguments" << endl;
//        return -1;
//    }
//
//    string day = argv[2];
//    vector<string> list = readFile();
//
//    for (int i = 0; i < list.size(); i++){
//        bool found = list[i].find(day) != string::npos;
//        if (found){
//            cout << list[i].substr(list[i].find("- ") + 1) << endl;
//        }
//        else{
//            continue;
//        }
//    }
//}

#endif //TODO_LIST_PROJECT_TODOLIST_H
