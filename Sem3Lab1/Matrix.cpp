#include <iostream>
#include <limits>
#include <iomanip>
#include "Matrix.h"
using namespace std;

// Конструктор
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix = new int* [this->rows];
	for (int i = 0; i < this->rows; i++)
		matrix[i] = new int[this->cols];
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other)
{
	this->rows = other.rows;
	this->cols = other.cols;
	this->matrix = new int*[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			this->matrix[i][j] = other.matrix[i][j];
	}
}

// Ввод матрицы
void Matrix::input_matrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter number on position [" << i << "][" << j << "]: ";
			enter_num_value(matrix[i][j]);
		}
	}
}

// Вывод матрицы
void Matrix::print_matrix() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << setw(7) << matrix[i][j];
		cout << '\n';
	}
}

// Вычисление суммы матриц
Matrix Matrix::sum_matrixes(const Matrix& other) const
{
	Matrix result_matrix(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			result_matrix.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
	return result_matrix;
}

// Перегрузка оператора сложения
Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix result_matrix(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			result_matrix.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
	return result_matrix;
}

// Деструктор
Matrix::~Matrix()
{
	if (matrix != nullptr)
	{
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
}

// Ввод кол-ва строк и столбцов матриц
int Matrix::input_rows_cols()
{
	int value;
	while (true)
	{
		value = enter_num_value(value);
		if (value < MIN_ROWS_COLS || value > MAX_ROWS_COLS)
			cout << "Enter a value from " << MIN_ROWS_COLS \
			<< " to " << MAX_ROWS_COLS << ":" << endl;
		else
			return value;
	}
}

// Ввод значения типа int
int Matrix::enter_num_value(int& input_value)
{
	while (true)
	{
		if (cin >> input_value) return input_value;
		else 
		{
			cout << "Please, enter a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
