# include "Solution.h"

int main()
{

vector <string> vecTrans1;
vector <string> vecTrans2;
string strMcode1;
string strMcode2;
string strMcode3;

ifstream transmission1;
ifstream transmission2;
ifstream mcode1;
ifstream mcode2;
ifstream mcode3;

transmission1.open("transmission1.txt"); //open file
transmission2.open("transmission2.txt"); //open file
mcode1.open("mcode1.txt"); //open file
mcode2.open("mcode2.txt"); //open file
mcode3.open("mcode3.txt"); //open file

txtToVec(transmission1, vecTrans1);
txtToVec(transmission2, vecTrans2);
txtToString(mcode1, strMcode1);
txtToString(mcode2, strMcode2);
txtToString(mcode3, strMcode3);

cout << "\n" << endl;
cout << "-------- Find malicious code in each transmission --------" << endl;
cout << "\n" << endl;

cout << "          Transmission 1          " << endl;
malCodeTester(vecTrans1, strMcode1, strMcode2, strMcode3);
cout << "\n" << endl;
cout << "          Transmission 2          " << endl;
malCodeTester(vecTrans2, strMcode1, strMcode2, strMcode3);



cout << "\n" << endl;
cout << "--------  Palindromes in each transmission --------" << endl;
cout << "\n" << endl;

cout << "          Transmission 1          " << endl;
palindromesTester(vecTrans1);
cout << "\n" << endl;
cout << "          Transmission 2          " << endl;
palindromesTester(vecTrans2);



cout << "\n" << endl;
cout << "--------  Largest substring between transmissions --------" << endl;
cout << "\n" << endl;
cout << "\n" << endl;

palindromesTester(vecTrans2);

return 0;
}