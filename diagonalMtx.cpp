#include "diagonalMtx.h"
namespace simple_matrix
{
	// Вывод диагональной матрицы в поток
	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << mtx->sideSize << endl;

		switch (mtx->style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
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
			break;
		case 1:
			ofst << "Matrix output style - \"Output by columns\" " << endl;
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
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int col = 0; col < mtx->sideSize; col++)
			{
				ofst << mtx->currentMtx[col] << " ";
			}
			ofst << "]" << endl << endl;
			break;
		default:
			break;
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