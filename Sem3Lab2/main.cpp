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

	cout << "Enter string C: ";
	cin >> C;

	cout << "Slozhenie i vychtanie:" << endl;
	cout << ("FKSIS" + --A + ++B - "BSUIR");
	C += B-- - A;
	cout << C;

	cout << "Sravneniya:" << endl;
	cout << (A == B) << endl;
	cout << (A > C) << endl;
	cout << (A >= B) << endl;
	cout << (B < C) << endl;
	cout << (B <= A) << endl;

	cout << "() and []:" << endl;
	cout << C[5];
	cout << C(4, 6);

	return 0;
}