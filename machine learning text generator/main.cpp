#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <list>
#include <time.h>


using namespace std;

int main(int argc, char *argv[]) {
    int numWords = stoi(argv[2]);
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
	          tokens.push_back(nopunct);
              unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }

    ofstream setfile(filename+"_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
        setfile << ' ' << *it << endl;
    }

    ofstream  vectorfile(filename+"_vector.txt");
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it){
        vectorfile << *it << endl;
    }

    ofstream mapfile(filename+"_map.txt");
//    map<string, string> wordmap;
//    string last="";
//    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
//        wordmap[last]=*it;
//        last = *it;
//    }

    const int M = 3;
    map<list<string>, vector<string> > wordmap;
    list<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }

    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }



//    for (map<string, vector<string> >::iterator it = wordmap.begin(); it != wordmap.begin(); it++){
//
//        cout << it->first << ", " << it->second << endl;
//    }
    srand(time(NULL)); // this line initializes the random number generated
    // so you dont get the same thing every time
    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    for (int i = 0; i < numWords; i++) {
        int ind = rand() % wordmap[state].size();
        cout << wordmap[state][ind]<<" ";
        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }
}
