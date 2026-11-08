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

	cout << "\nSLOZHENIE, \"FKSIS \" + A + B + \" BSUIR\":" << endl;
	cout << ("FKSIS " + A + B + " BSUIR") << endl;
	// cout << (A + B) << endl;

	cout << "\nVYCHITANIE, \"PRIVET\" - A - B - \"POKA\":" << endl;
	cout << ("PRIVET" - A - B - "POKA") << endl;
	// cout << (A - B) << endl;

	cout << "\nC += A and C -= B:" << endl;
	C += A;
	cout << C << endl;
	C -= B;
	cout << C << endl;

	cout << "\nSRAVNENIYA:" << endl;
	cout << "A == B: " << (A == B) << " | A > B: " << (A > B) << " | A >= B: ";
	cout << (A >= B) << " | A < B: " << (A < B) << " | A <= B: " << (A <= B) << endl;

	cout << "\nINCREMENT AND DECREMENT:" << endl;
	cout << "A: " << A << " ++A: " << ++A << " A++: " << A++ << endl;
	cout << "B: " << B << " --B: " << --B << " B--: " << B-- << endl;
	cout << "--(--A): " << --(--A) << endl;
	cout << "++(++B): " << ++(++B) << endl;

	cout << "\n() and []:" << endl;
	cout << "C: " << C << endl;
	cout << "C[5]: " << C[5] << endl;

	cout << "Sdelaem C[5] = '!'" << endl;
	C[5] = '!';
	cout << "C[5]: " << C[5] << endl;

	cout << "C(3, 5): " << C(3, 5) << endl;
	cout << "(++C)[2]: " << (++C)[2] << endl;

	return 0;
}