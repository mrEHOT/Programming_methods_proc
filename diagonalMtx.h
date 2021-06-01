#pragma once
#ifndef diagonalMtx_definition
#define diagonalMtx_definition
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
namespace simple_matrix
{
	enum type;

	// Структура, характеризующая обыкновенные квадратные матрицы
	struct diagonalMtx
	{
		type key;
		long sideSize; // Размер стороны матрицы
		int* currentMtx; // Динамический одномерный массив для хранения объектов типа int
	};

	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst); // Вывод диагональной матрицы в поток
	diagonalMtx* DiagonalInput(ifstream& ifst); // Ввод диагональной матрицы на основании данных из потока
	void DiagonalClear(struct diagonalMtx* mtx); // Очистка памяти
} // end namesapce simple_matrix
#endif // !diagonalMtx_definition