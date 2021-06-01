#include "triangularMtx.h"
namespace simple_matrix
{
	// Посчитать сумму элементов в нижней треугольной матрице
	int TriangularSum(struct triangularMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->currentMtxSize; row++)
			{
				mtx->sum += mtx->currentMtx[row];
			}
			mtx->sumMarker = true;
			return mtx->sum;
		}
		else
		{
			return mtx->sum;
		}
	}

	// Вывод нижней треугольной матрицы в поток
	void TriangularOutput(struct triangularMtx* mtx, ofstream& ofst)
	{
		int count = 0; // Переменная для хранения номера элемента под вывод

		ofst << "It is Triangular matrix. Matrix side size: " << mtx->sideSize << ". The sum of the elements of the matrix: " << mtx->sum << endl;

		switch (mtx->style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					if (col < row + 1)
					{
						ofst << mtx->currentMtx[count] << "\t";
						count++;
					} // Если номер столбца меньше, чем номер строчки+1, то надо вывести число из  массива (в 0 строке - 1 ненулевой элемент, в 1 - 2 ненулевых и т.д.)
					else
					{
						ofst << "0" << "\t";
					}
				}
				ofst << endl;
			}
			break;
		case 1:
			ofst << "Matrix output style - \"Output by columns\" " << endl;
			for (int col = 0; col < mtx->sideSize; col++)
			{
				for (int row = 0; row < mtx->sideSize; row++)
				{
					if (row >= col)
					{
						ofst << mtx->currentMtx[count] << "\t";
						count++;
					} // Если номер столбца меньше, чем номер строчки+1, то надо вывести число из  массива (в 0 строке - 1 ненулевой элемент, в 1 - 2 ненулевых и т.д.)
					else
					{
						ofst << "0" << "\t";
					}
				}
				ofst << endl;
			}
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int col = 0; col < mtx->currentMtxSize; col++)
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

	// Ввод нижней треугольной матрицы на основании данных из потока
	triangularMtx* TriangularInput(ifstream& ifst)
	{
		string content = ""; // Создаем пустую строку для считывания элементов массив
		string delimiter = ","; // Разделитель
		string part = ""; // Строка для записи отдельных элементов массива
		size_t pos = 0;
		int col = 0;
		int count = 1; // Переменная для определения кол-ва элементов в одномерном массиве (элементов на один больше, чем кол-во разделяющих их запятых)
		int check = 0; // Переменная для проверки возможности составления нижней треугольной матрицы 

		triangularMtx* mtx = new triangularMtx;

		ifst >> content; // Считываем элементы массива разделенные запятыми

		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				count++;
			}
		} // Определили количество элементов в массиве

		mtx->sideSize = (long)sqrt(count) + 1; // Определяем размер стороны матрицы

		check = (1 + mtx->sideSize) * mtx->sideSize / 2; // Определяем количество элементов, необходимое для заполнения нижнего треугольника (сумма членов арифметической прогрессии)
		if (count == check)
		{
			mtx->currentMtxSize = count;
			mtx->currentMtx = new int[count]; // Создаем новый динамический массив под хранение элементов

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
		else
		{
			return NULL;
		}
	}

	// Очистка памяти
	void TriangularClear(struct triangularMtx* mtx)
	{
		delete[] mtx->currentMtx; // После вывода очищаем область памяти, выделенную под массив 
	}
} // end namesapce simple_matrix