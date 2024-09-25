# include <iostream>
# include <string>
# include <fstream>
# include <vector>

using namespace std;

void textToVec (ifstream& text, vector <string>& vec){
    
    for(string line; getline(text, line, '\n'); ){
        vec.push_back(line);
    } 

    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
};