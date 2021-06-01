#include "matrix.h"
namespace simple_matrix
{
	// Добавление новой квадратной матрицы на основании данных из потока
	matrix* MtxInput(ifstream& ifst)
	{
		matrix* newMatrix;
		int currKey;
		ifst >> currKey;

		switch (currKey)
		{
		case 0:
			newMatrix = (matrix*)SquareInput(ifst);
			if (newMatrix != NULL)
			{
				newMatrix->key = SQUARE;
				break;
			}
			else
			{
				return NULL;
			}
		case 1:
			newMatrix = (matrix*)DiagonalInput(ifst);
			if (newMatrix != NULL)
			{
				newMatrix->key = DIAGONAL;
				break;
			}
			else
			{
				return NULL;
			}
		case 2:
			newMatrix = (matrix*)TriangularInput(ifst);
			if (newMatrix != NULL)
			{
				newMatrix->key = TRIANGULAR;
				break;
			}
			else
			{
				return NULL;
			}
		default:
			return NULL; // Возвращаем NULL, т.к. не удалось идентифицировать к какому типу принадлежит матрица
		}

		return newMatrix; // Возвращаем указатель на созданную матрицу
	}

	// Вывод информации о квадратной матрице в поток
	bool MtxOutput(matrix* mtx, ofstream& ofst)
	{
		bool check = false;

		if (!check)
		{
			if (mtx->key == SQUARE)
			{
				SquareOutput((squareMtx*)mtx, ofst);
				return true;
			} // Если выводимая в поток матрица явлется обыкновенной квадртной матрицей => вывод в поток + TRUE

			if (mtx->key == DIAGONAL)
			{
				DiagonalOutput((diagonalMtx*)mtx, ofst);
				return true;
			} // Если выводимая в поток матрица явлется диагональной матрицей, полученной на основании одномерного массива => вывод в поток + TRUE

			if (mtx->key == TRIANGULAR)
			{
				TriangularOutput((triangularMtx*)mtx, ofst);
				return true;
			} // Если выводимая в поток матрица явлется  нижней трегольной матрицей, полученной на основании одномерного массива => вывод в поток + TRUE

			check = true; // Если матрица не принадлежит ни одному из типов => выставляем TRUE
		}

		if (check)
		{
			ofst << "Incorrect matrix!" << endl;
			return false;
		} // Вывод сообщения об ошибке в том случае, когда матрица не принадлежит ни к одному из предусмотренных типов

	}

	// Очистка памяти, выделенной под хранение матрицы
	void MtxClear(matrix* mtx)
	{
		if (mtx->key == SQUARE)
		{
			SquareClear((squareMtx*)mtx);
		} //Очистка памяти для обычной квадратной матрицы

		if (mtx->key == DIAGONAL)
		{
			DiagonalClear((diagonalMtx*)mtx);
		} //Очистка памяти для диагональной матрицы матрицы

		if (mtx->key == TRIANGULAR)
		{
			TriangularClear((triangularMtx*)mtx);
		} //Очистка памяти для диагональной матрицы матриц

	}
} // end namesapce simple_matrix