#include "diagonalMtx.h"
namespace simple_matrix
{
	//Посчитать сумму элементов в диагональной матрице матрице
	int DiagonalSum(struct diagonalMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->sideSize; row++)
			{
				mtx->sum += mtx->currentMtx[row];
			}
			mtx->sumMarker = true; // Фиксируем, что сумма была посчитана
			return mtx->sum;
		} // Если сумма еще не была посчитана => считаем и возвращаем
		else
		{
			return mtx->sum;
		} // Возвращаем ранее зафиксированное значение суммы
	}

	// Вывод диагональной матрицы в поток
	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << mtx->sideSize << ". Sum of matrix elements: " << mtx->sum << endl;
		for (int row = 0; row < mtx->sideSize; row++)
		{
			for (int col = 0; col < mtx->sideSize; col++)
			{
				if (row != col)
				{
					ofst << "0" << "\t";
				}
				else
				{
					ofst << mtx->currentMtx[row] << "\t";
				}
			}
			ofst << endl;
		}

		ofst << endl;
	}

	// Ввод диагональной матрицы на основании данных из потока
	diagonalMtx* DiagonalInput(ifstream& ifst)
	{
		string content = ""; // Создаем пустую строку для считывания элементов массив
		string delimiter = ","; // Разделитель
		string part = ""; // Строка для записи отдельных элементов массива
		size_t pos = 0;
		int col = 0;

		diagonalMtx* mtx = new diagonalMtx;

		ifst >> mtx->sideSize >> content; // Считываем размер матрицы (кол-во элементов в одномерном массиве), затем считываем сами элементы
		mtx->currentMtx = new int[mtx->sideSize]; // Создаем новый динамический массив


		while ((pos = content.find(delimiter)) != string::npos)
		{
			part = content.substr(0, pos);
			mtx->currentMtx[col] = atoi(part.c_str()); // Заполняем col элемент массива
			col++;
			content.erase(0, pos + delimiter.length());
		} // Выполняем парсинг строки по разделителю ","

		mtx->currentMtx[col] = atoi(content.c_str()); // Вводим последний элемент массива

		return mtx;
	}

	// Очистка памяти
	void DiagonalClear(struct diagonalMtx* mtx)
	{
		delete[] mtx->currentMtx; // После вывода очищаем область памяти, выделенную под массив 
	}
} // end namesapce simple_matrix