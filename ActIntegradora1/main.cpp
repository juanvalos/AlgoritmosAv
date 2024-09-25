# include "Solution.h"

int main()
{

vector <string> vecTrans1;
ifstream transmission1;
transmission1.open("transmission1.txt"); //open file

vector <string> vecTrans2;
ifstream transmission2;
transmission2.open("transmission2.txt"); //open file

vector <string> vecMcode1;
ifstream mcode1;
mcode1.open("mcode1.txt"); //open file

vector <string> vecMcode2;
ifstream mcode2;
mcode2.open("mcode2.txt"); //open file

vector <string> vecMcode3;
ifstream mcode3;
mcode3.open("mcode3.txt"); //open file



textToVec (transmission1, vecTrans1);

cout << "\n"<< endl;

textToVec (transmission2, vecTrans2);

cout << "\n"<< endl;



textToVec (mcode1, vecMcode1);

cout << "\n"<< endl;

textToVec (mcode2, vecMcode2);

cout << "\n"<< endl;

textToVec (mcode3, vecMcode3);

cout << "\n"<< endl;


return 0;
}