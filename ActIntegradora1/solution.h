# include <iostream>
# include <string>
# include <fstream>
# include <vector>

using namespace std;

void textToVec (ifstream& text, vector <string>& vec){
    
    for(string line; getline(text, line, '\n'); ){
        vec.push_back(line);
    } 

};

bool mcodeExists (string str, string substr) {
    return str.find(substr) != string::npos;
};