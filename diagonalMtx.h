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
	enum outputStyle;

	// Структура, характеризующая обыкновенные квадратные матрицы
	struct diagonalMtx
	{
		type key;
		long sideSize; // Размер стороны матрицы
		outputStyle style; // Способ вывода
		int* currentMtx; // Динамический одномерный массив для хранения объектов типа int
		int sum = 0; // Сумма элементов матрицы
		bool sumMarker = false; // Поле, фиксирующее, что сумма уже была рассчитана
	};

	int DiagonalSum(struct diagonalMtx* mtx); // Посчитать сумму элементов в квадратной матрице
	bool DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst); // Вывод диагональной матрицы в поток
	diagonalMtx* DiagonalInput(ifstream& ifst); // Ввод диагональной матрицы на основании данных из потока
	void DiagonalClear(struct diagonalMtx* mtx); // Очистка памяти
} // end namesapce simple_matrix
#endif // !diagonalMtx_definition