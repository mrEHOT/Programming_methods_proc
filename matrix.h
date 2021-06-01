#pragma once
#ifndef matrix_definition
#define matrix_definition
#include <string>
#include <iostream>
#include <fstream>
#include "squareMtx.h"
#include "diagonalMtx.h"
using namespace std;
namespace simple_matrix
{
	enum type { SQUARE, DIAGONAL }; // Тип квадратной матрицы: 1. Обычный двумерный массив размером n x n; 2. Диагональная матрица (на основе одномерного массива)

// Структура обобщающая все виды квадратных матриц
	struct matrix
	{
		type key;
		long sideSize; // Размер стороны
	};

	int MtxSum(matrix* mtx); //Посчитать сумму элементов в матрице
	matrix* MtxInput(ifstream& ifst); // Добавление новой квадратной матрицы на основании данных из потока
	bool MtxOutput(matrix* mtx, ofstream& ofst); // Вывод информации о квадратной матрице в поток
	void MtxClear(matrix* mtx); // Очистка памяти, выделенной под хранение матрицы
}// end namesapce simple_matrix
#endif // !matrix_definition