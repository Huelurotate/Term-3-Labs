#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	String A, B, C;

	cout << "Enter string A: ";
	cin >> A;

	cout << "Enter string B: ";
	cin >> B;

	C = "FKSIS" + --A + ++B + "BSUIR";
	cout << C++;

	cout << C[5];
	cout << C(4, 6);

	C += B-- + " 550502";
	cout << C;

	return 0;
}