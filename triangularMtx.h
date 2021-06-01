#pragma once
#ifndef triangularMtx_definition
#define triangularMtx_definition
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_matrix
{
	enum type;

	// Структура, характеризующая нижние треугольные матрицы
	struct triangularMtx
	{
		type key;
		long sideSize; // Размер стороны матрицы
		int* currentMtx; // Динамический двумерный массив для хранения объектов типа int
	};

	void TriangularOutput(struct triangularMtx* mtx, ofstream& ofst); // Вывод нижней треугольной матрицы в поток
	triangularMtx* TriangularInput(ifstream& ifst); // Ввод нижней треугольной матрицы на основании данных из потока
	void TriangularClear(struct triangularMtx* mtx); // Очистка памяти
} // end namesapce simple_matrix
#endif // !triangularMtx_definition