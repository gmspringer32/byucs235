//
// Created by gmspr on 10/4/2022.
//

#include "Pathfinder.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;

Pathfinder::Pathfinder() {
    for (int row = 0; row < ROW_SIZE; row++){
        for (int col = 0; col < COL_SIZE; col++) {
            for (int z = 0; z < Z_SIZE; z++) {
                maze_grid[row][col][z] = 1;
            }
        }
    }
    srand(time(0));
}

bool Pathfinder::importMaze(string file_name) {
    int tempMaze[5][5][5];
    cout << "importMaze from " << file_name << endl;
    ifstream file(file_name.c_str());
    int count = 0;
    int countZ = 0;
    string line = "";
    if (file.is_open()) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                do {
                    getline(file, line);
                } while (line.empty());

                stringstream ss(line);
                for (int z = 0; z < Z_SIZE; z++) {
                    int value;
                    string temp;
                    ss >> temp;
                    if (file.eof() && (z != 4 && row != 4)){
                        return false;
                    }

                    if (temp == "0" || temp == "1"){
                        //cout << "[" << row << "][" << col << "][" << z << "]=" << value << endl;
                        value = stoi(temp);
                        tempMaze[row][col][z] = value;
                        count++;
                    }
                    else{
                        cout << "Invalid input in one or more points" << endl;
                        return false;
                    }
                }
            }
        }
    }
//    stringstream st;
//    for (int row = 0; row < ROW_SIZE; row++){
//        for (int col = 0; col < COL_SIZE; col++){
//            for (int z = 0; z < Z_SIZE; z++){
//                st<< maze_grid[row][col][z];
//                st << " ";
//            }
//            st << endl;
//        }
//        st << endl;
//    }
//    cout << st.str();

    getline(file, line);
    if(!file.eof()){
        return false;
    }

    if (tempMaze[0][0][0] != 1 || tempMaze[4][4][4] != 1) {
        cout << "Imported maze does not have correct starting and ending points" << endl;
        return false;
    }
    if (count != 125){
        cout << count << endl;
        cout << "Imported maze does not have the correct number of points" << endl;
        return false;
    }
    else{
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                for (int z = 0; z < Z_SIZE; z++) {
                    maze_grid[row][col][z] = tempMaze[row][col][z];
                }
            }
        }
        return true;
    }

}


string Pathfinder::toString() const
{
    stringstream ss;
    for (int row = 0; row < ROW_SIZE; row++){
        for (int col = 0; col < COL_SIZE; col++){
            for (int z = 0; z < Z_SIZE; z++){
                ss << maze_grid[row][col][z];
                if (z < Z_SIZE -1){
                    ss << " ";
                }
            }
            ss << endl;
        }
        if (row < ROW_SIZE-1){
            ss << endl;
        }
    }
    return ss.str();
}

vector<string> Pathfinder::solveMaze(){
    solution.clear();
    //string step;
    int tempMaze[5][5][5];
    for(int x = 0; x < ROW_SIZE; x++){
        for(int y = 0; y < COL_SIZE; y++){
            for(int z = 0; z < Z_SIZE; z++){
                tempMaze[x][y][z] = maze_grid[x][y][z];
            }
        }
    }
    findPath(0,0,0, tempMaze);
    return solution;
}

void Pathfinder::createRandomMaze() {
    cout << "Creating random maze" << endl;
    for (int row = 0; row < ROW_SIZE; row++){
        for (int col = 0; col < COL_SIZE; col++){
            for (int z = 0; z < Z_SIZE; z++){
                int value = rand()%2;
                maze_grid[row][col][z] = value;
            }
        }
    }
    maze_grid[0][0][0] = 1;
    maze_grid[4][4][4] = 1;

}

bool Pathfinder::findPath(int x, int y, int z, int maze[5][5][5]){
    // base case(s)
    string coords = "(" + to_string(z) + ", " + to_string(y) + ", " + to_string(x) + ")";
    if ((x < 0) || (x > 4) || (y < 0) || (y > 4) || (z < 0) || (z > 4))
        return false;
    if (x == 4 && y == 4 && z == 4) {
        solution.push_back(coords);
        return true;
    }
    if (maze[x][y][z] == 0)
        return false;
    if (maze[x][y][z] == 3)
        return false;

    maze[x][y][z] = 3;
    // recursive step(s) (call(s))

    if(findPath(x+1, y, z, maze) ||
            findPath(x-1, y, z, maze) ||
            findPath(x, y+1, z, maze) ||
            findPath(x, y-1, z, maze) ||
            findPath(x, y, z+1, maze) ||
            findPath(x, y, z-1, maze)){
        solution.insert(solution.begin(), coords);
        return true;
    }
    else{
        return false;
    }
}