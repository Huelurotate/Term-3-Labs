#pragma once

// Объявление класса матрицы
class Matrix 
{
private:
	// минимум и максимум строк и столбцов матриц
	static constexpr short MIN_ROWS_COLS = 1;
	static constexpr short MAX_ROWS_COLS = 100;

	int** matrix;
	int rows;
	int cols;

public:
	// Конструктор
	Matrix(int rows, int cols);

	// Конструктор копирования
	Matrix(const Matrix& other);

	// Деструктор
	~Matrix();

	// Ввод и вывод матрицы 
	void input_matrix();
	void print_matrix() const;

	// Вычисление суммы матриц
	Matrix sum_matrixes(const Matrix& other) const;

	// Перегрузка оператора сложения
	Matrix operator+(const Matrix& other) const;

	// Ввод кол-ва строк и столбцов
	static int input_rows_cols();

	// Ввод значения типа int
	static int enter_num_value(int& input_value);
};
