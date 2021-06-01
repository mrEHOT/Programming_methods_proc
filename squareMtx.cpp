#include "squareMtx.h"
namespace simple_matrix
{
	// Вывод стандартной матрицы в поток
	void SquareOutput(struct squareMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Square matrix. Matrix side size: " << mtx->sideSize << endl;
		for (int row = 0; row < mtx->sideSize; row++)
		{
			for (int col = 0; col < mtx->sideSize; col++)
			{
				ofst << mtx->currentMtx[row][col] << "\t";
			}
			ofst << endl;
		}
		ofst << endl;
	}

	// Ввод стандартной матрицы на основании данных из потока
	squareMtx* SquareInput(ifstream& ifst)
	{
		string content = ""; // Создаем пустую строку для считывания элементов массив
		string delimiter = ","; // Разделитель
		string part = ""; // Строка для записи отдельных элементов массива
		size_t pos = 0;
		int col = 0;

		squareMtx* mtx = new squareMtx;

		ifst >> mtx->sideSize; // Считываем размер двумерного массива (кол-во элементов в одномерном), затем считываем сами элементы
		mtx->currentMtx = new int* [mtx->sideSize]; // Создаем массив указателей на указатели
		for (int row = 0; row < mtx->sideSize; row++)
		{
			mtx->currentMtx[row] = new int[mtx->sideSize]; //Создаем указатель на одномерный массив
		} // Создание двумерного массива

		for (int row = 0; row < mtx->sideSize; row++)
		{
			ifst >> content;

			while ((pos = content.find(delimiter)) != string::npos)
			{
				part = content.substr(0, pos);
				mtx->currentMtx[row][col] = atoi(part.c_str()); // Заполняем col элемент массива в строке row
				col++;
				content.erase(0, pos + delimiter.length());
			} // Выполняем парсинг строки по разделителю ","

			mtx->currentMtx[row][col] = atoi(content.c_str()); // Вводим последний элемент строки с номером row
			content = ""; //Обнуляем строку content
			col = 0; //Обнуляем счетчик движения по столбцам
		}

		return mtx;
	}

	// Очистка памяти
	void SquareClear(struct squareMtx* mtx)
	{
		for (int row = 0; row < mtx->sideSize; row++)
		{
			delete mtx->currentMtx[row];
		} // Удаляем указатели на одномерные массивы

		delete[] mtx->currentMtx; // После вывода очищаем область памяти, выделенную под массив 
	}
} // end namesapce simple_matrix