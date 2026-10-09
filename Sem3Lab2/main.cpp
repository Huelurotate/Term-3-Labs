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

	cout << "SLOZHENIE, \"FKSIS \" - A - B - \" BSUIR\":" << endl;
	cout << ("FKSIS " + A + B + " BSUIR") << endl;
	// cout << (A + B) << endl;

	cout << "VYCHITANIE, \"PRIVET\" - A - B - \"POKA\":" << endl;
	cout << ("PRIVET" - A - B - "POKA") << endl;
	// cout << (A - B) << endl;

	cout << "C += A and C -= B:" << endl;
	C += A;
	cout << C << endl;
	C -= B;
	cout << C << endl;

	cout << "SRAVNENIYA:" << endl;
	cout << "A == B: " << (A == B) << " A > B: " << (A > B) << " A >= B: ";
	cout << (A >= B) << " A < B: " << (A < B) << " A <= B: " << (A <= B) << endl;

	cout << "INCREMENT AND DECREMENT:" << endl;
	cout << "A: " << A << " ++A: " << ++A << " A++: " << A++ << endl;
	cout << "B: " << B << " --B: " << --B << " B--: " << B-- << endl;
	cout << "--(--A): " << --(--A) << endl;
	cout << "++(++B): " << ++(++B) << endl;

	cout << "() and []:" << endl;
	cout << "C[5]: " << C[5] << endl;
	cout << "C(3, 5): " << C(3, 5) << endl;
	cout << "(++C)[2]: " << (++C)[2] << endl;

	return 0;
}