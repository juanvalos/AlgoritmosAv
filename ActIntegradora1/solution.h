# include <iostream>
# include <string>
# include <fstream>
# include <vector>

using namespace std;

// Converts a .txt file into a vector, in each vector index is a line of the .txt file
void txtToVec (ifstream& txt, vector <string>& vec){
    for(string str; getline(txt, str, '\n'); ){
        vec.push_back(str);
    }
};

// Converts a .txt file into a string
void txtToString (ifstream& txt, string& str) {
    getline(txt, str);
};

// Checks if a substring is in a certain string
bool mcodeExists (string str, string substr) {
    return str.find(substr) != string::npos;
};

// Checks if a string is a palindrome
bool palindromeExists(string str){
    int  start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;

};

// Shows in terminal where a substring starts and finishes on a certain string
void stringCount (string& str, string& substr){
    size_t start = str.find(substr);
    size_t end = start + substr.length() - 1;
    cout << "  chars from "<< start << " to " << end << endl;
};

// Find malicious code in a transmission (Part1)
void malCodeTester(vector <string>& vec, string& malcode1, string& malcode2, string& malcode3) {
    string transm;
    string malcode;
    int flags[3] = {0,0,0};
    int line = 1;

    for (int i = 0; i < vec.size(); i++) {
        transm = vec[i];
        
        if (mcodeExists(transm, malcode1) == 1){
            malcode = malcode1;
            cout << "True  " << malcode << "  line: " << line + i;
            stringCount(transm, malcode);
            flags[0] = 1;
        }
        

        if (mcodeExists(transm, malcode2) == 1){
            malcode = malcode2;
            cout << "True  " << malcode << "  line: " << line + i;
            stringCount(transm, malcode);
            flags[1] = 1;
        }

        if (mcodeExists(transm, malcode3) == 1){
            malcode = malcode3;
            cout << "True  " << malcode << "  line: " << line + i;
            stringCount(transm, malcode);
            flags[2] = 1;
        }
    }

    if (flags[0] == 0){
        cout << "False  " << malcode1 << endl;
    }

    if (flags[1] == 0){
        cout << "False  " << malcode2 << endl;
    }

    if (flags[2] == 0){
        cout << "False  " << malcode3 << endl;
    }
};

void palindromesTester (vector <string>& vec){
    string transm;
    int line = 1;
    string largestPal = " ";
    int lineLargPal;

    for (int i = 0; i < vec.size(); i++){
        transm = vec [i];

        if (palindromeExists(transm) == true){
            if (transm.length() > largestPal.length()){
                largestPal = transm;
                lineLargPal = line + i;
            }
            cout << "Palindrome detected ->  " << transm << "  line: " << line +i << endl;
        }
    }

    cout << "Largest Palindrome in transmission ->  " << largestPal << "  line: " << lineLargPal;
    stringCount(largestPal, largestPal);
};

void findTopSubstring (vector <string>& transm1, vector <string>& transm2) {
    //Solution Part 3
    
};