# include "solution.h"

int main()
{

vector <string> vecTrans1;
ifstream transmission1;
transmission1.open("transmission1.txt"); //open file

for(string listOfWords; getline(transmission1, listOfWords, '\n'); ){
    vecTrans1.push_back(listOfWords);
} 

for (int i = 0; i < vecTrans1.size(); i++){
    cout << vecTrans1[i]<< endl;
}



return 0;
}