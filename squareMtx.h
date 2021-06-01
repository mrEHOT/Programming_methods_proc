#pragma once
#ifndef squareMtx_definition
#define squareMtx_definition
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_matrix
{
	enum type;

	// Структура, характеризующая обыкновенные квадратные матрицы
	struct squareMtx
	{
		type key;
		long sideSize; // Размер стороны матрицы
		int** currentMtx; // Динамический двумерный массив для хранения объектов типа int
	};

	void SquareOutput(struct squareMtx* mtx, ofstream& ofst); // Вывод стандартной матрицы в поток
	squareMtx* SquareInput(ifstream& ifst); // Ввод стандартной матрицы на основании данных из потока
	void SquareClear(struct squareMtx* mtx); // Очистка памяти
} // end namesapce simple_matrix
#endif // !squareMtx_definition