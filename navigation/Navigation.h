//
// Created by gmspr on 9/21/2022.
//

#ifndef LAB2_NAVIGATIONCODE_NAVIGATION_H
#define LAB2_NAVIGATIONCODE_NAVIGATION_H
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "NavigationInterface.h"
#include <list>

using namespace std;

struct Node {
    int cost;
    queue<int> path;

    bool operator() (Node const& n1, Node const& n2) {
        return n1.cost > n2.cost;
    }
};

class Navigation : public NavigationInterface {
private:
    vector < vector<int> > theCosts;
    int numNodes;
public:
    Navigation();
    ~Navigation();

    bool readNetwork(string _mapName);

    queue<int> computeShortestPath(int _startInd, int _endInd);

    void printPath(queue<int> _path);
};


#endif //LAB2_NAVIGATIONCODE_NAVIGATION_H
