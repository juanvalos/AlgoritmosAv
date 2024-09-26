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

// Returns the largest substring between 2 strings
string findLargestSubstr(string& str1, string& str2){
    int strlength1 = str1.length();
    int strlength2 = str2.length();
    int maxLength = 0;
    int endIdx = 0;

    vector<vector<int>> dp(strlength1 + 1, vector<int>(strlength2 + 1, 0));

    for (int i = 1; i <= strlength1; ++i) {
        for (int j = 1; j <= strlength2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIdx = i;  
                }
            }
        }
    }

    string longestSubstring = str1.substr(endIdx - maxLength, maxLength);
    return longestSubstring;
};

// Find malicious code in a transmission (Part1)
void malCodeTester(vector <string>& vec, string& malcode1, string& malcode2, string& malcode3) {
    string transm;
    string malcode;
    int flags[3] = {0,0,0};

    for (int i = 0; i < vec.size(); i++) {
        transm = vec[i];
        
        if (mcodeExists(transm, malcode1) == 1){
            malcode = malcode1;
            cout << "True  " << malcode << "  line: " << i + 1;
            stringCount(transm, malcode);
            flags[0] = 1;
        }
        

        if (mcodeExists(transm, malcode2) == 1){
            malcode = malcode2;
            cout << "True  " << malcode << "  line: " << i + 1;
            stringCount(transm, malcode);
            flags[1] = 1;
        }

        if (mcodeExists(transm, malcode3) == 1){
            malcode = malcode3;
            cout << "True  " << malcode << "  line: " << i + 1;
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

// Finds palindromes and the largest palindromes in a transmission (Part2)
void palindromesTester (vector <string>& vec){
    string transm;
    string largestPal = " ";
    int lineLargPal;

    for (int i = 0; i < vec.size(); i++){
        transm = vec [i];

        if (palindromeExists(transm) == true){
            if (transm.length() > largestPal.length()){
                largestPal = transm;
                lineLargPal = i + 1;
            }
            cout << "Palindrome detected -> " << transm << "  line: " << i + 1 << endl;
        }
    }

    cout << "Largest Palindrome in transmission -> " << largestPal << "  line: " << lineLargPal;
    stringCount(largestPal, largestPal);
};

// Finds the largest substring located in both trasnmissions
void findTopSubstring (vector <string>& vec1, vector <string>& vec2) {
    string transm1;
    string transm2;
    string larStr = " ";
    int linet1;
    int linet2;
    int idxt1;
    int idxt2;

    for (int i = 0; i < vec1.size(); i++) {
        transm1 = vec1[i];
        for (int ii = 0; ii < vec2.size(); ii++){
            transm2 = vec2[ii];
            string str = findLargestSubstr(transm1, transm2);
            if (str.length() > larStr.length()){
                larStr = str;
                linet1 = i + 1;
                linet2 = ii + 1;
                idxt1 = i;
                idxt2 = ii;
            }
        }
    }

    cout << "Largest substring -> " << larStr << endl;
    cout << "\n";
    cout <<"Location in Transmission 1 -> " << "line:  " << linet1;
    stringCount(vec1[idxt1], larStr);
    cout <<"Location in Transmission 2 -> " << "line:  " << linet2;
    stringCount(vec2[idxt2], larStr);
    cout << "\n";
};