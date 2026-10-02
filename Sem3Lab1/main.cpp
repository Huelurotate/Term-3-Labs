// Яровиков Владислав Юрьевич 550502
// Вариант 2
// Создать класс для работы с двух мерными массивами, 
// в классе реализовать следующие методы:
// 1. Ввод данных в массивы
// 2. Вывод массивов на экран
// 3. Сложение матриц
// Память под массивы отводить динамически, использовать конструктор под 
// выделения памяти под массивы и использовать диструктор для освобождение памяти.

#include <iostream>
#include "Matrix.h"
using namespace std;

int main() 
{
	// Ввод кол-ва строк и столбцов 
	int rows, cols;
	cout << "Enter the number of rows: ";
	rows = Matrix::input_rows_cols();


	cout << "Enter the number of columns: ";
	cols = Matrix::input_rows_cols();

	// Ввод матриц
	Matrix A(rows, cols);
	cout << "Enter matrix A:" << endl;
	A.input_matrix();

	Matrix B(rows, cols);
	cout << "Enter matrix B:" << endl;
	B.input_matrix();

	// Вывод матриц
	cout << "\nMatrix A:" << endl;
	A.print_matrix();

	cout << "\nMatrix B:" << endl;
	B.print_matrix();

	// Вычисление суммы матриц
	Matrix C = A.sum_matrixes(B);
	cout << "\nSum of A and B:" << endl;
	C.print_matrix();

	/*Matrix C = A + B;
	cout << "\nSum of A and B:" << endl;
	C.print_matrix();*/

	return 0;
}