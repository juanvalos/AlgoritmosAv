# include "solution.h"

int main()
{

vector <string> vecTrans1;
ifstream transmission1;
transmission1.open("transmission1.txt"); //open file

textToVec (transmission1, vecTrans1);


return 0;
}