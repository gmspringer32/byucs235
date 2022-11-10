//
// Created by gmspr on 9/21/2022.
//

#include "Navigation.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Navigation::Navigation() {
    //cout << "This is my Navigation constructor" << endl;
}
Navigation::~Navigation() {
    //cout << "This is my Navigation deconstructor" << endl;
}

bool Navigation::readNetwork(string _mapName){
    string filename(_mapName);
    int number;
    int start_num;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        exit(-1);
    }
    input_file >> start_num;

    for(int i = 0; i < start_num; i++){
        vector<int> ints;
        for(int j = 0; j < start_num; j++){
            input_file >> number;
            ints.push_back(number);
            //cout << ints[j] << endl;
        }
        theCosts.push_back(ints);
    }

    input_file.close();

//    string line;
//    int num = 0, count = 0;
//    while(getline(map, line)){
//        istringstream ss(line);
//        while(ss >> num){
//            vector<int> nums;
//            nums.push_back(num);
//            theCosts.push_back(nums);
//            cout << "Hello there" << endl;
//            ++count;
//        }
//    }


    return true;
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd){

    //(1)   PriorityQueue<Node> PQ
    priority_queue<Node, vector<Node>, Node> PQ;

    //(2)   Create Node n, with n.cost = 0 and n.path = <A>
    Node n;
    n.cost = 0;
    n.path.push(_startInd);

    //(3)   Insert Node n into PQ
    PQ.push(n);

    //(4)   Loop while the top Node in PQ does not contain a path that ends in the destination
    while(PQ.top().path.back() != _endInd){
        //(5)      Pop the top item off the priority queue and store it in current
        Node current = PQ.top();
        PQ.pop();

        //(6)      Set last to be the last destination in current.path
        int last = current.path.back();

        //(7)      For each neighbor j of last (i.e., Cost(last,j) > 0), insert a new Node (denoted nn) into PQ in
        //             which nn.cost = current.cost+Cost(last,j) and nn.path = concat(current.path, j)
        for(int i = 0; i < theCosts.size(); i++){
            if(theCosts[last][i] > 0){
                Node nn;
                nn.cost = current.cost + theCosts[last][i];
                nn.path = current.path;
                nn.path.push(i);

                PQ.push(nn);
            }

        }
    }
    queue<int> thePath = PQ.top().path;

    return thePath;
}

void Navigation::printPath(queue<int> _path){
    while(!_path.empty()){
        cout << _path.front() << ", ";
        _path.pop();
    }
    cout << endl;
}