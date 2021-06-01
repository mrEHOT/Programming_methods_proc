#include "matrix.h"
namespace simple_matrix
{
	// ?обавление новой квадратной матрицы на основании данных из потока
	matrix* MtxInput(ifstream& ifst)
	{
		matrix* newMatrix;
		int currKey;
		ifst >> currKey;

		switch (currKey)
		{
		case 0:
			newMatrix = (matrix*)SquareInput(ifst);
			newMatrix->key = SQUARE;
			break;
		case 1:
			newMatrix = (matrix*)DiagonalInput(ifst);
			newMatrix->key = DIAGONAL;
			break;
		default:
			return NULL; // ¬озвращаем NULL, т.к. не удалось идентифицировать к какому типу принадлежит матрица
		}

		return newMatrix; // ¬озвращаем указатель на созданную матрицу
	}

	// ¬ывод информации о квадратной матрице в поток
	bool MtxOutput(matrix* mtx, ofstream& ofst)
	{
		bool check = false;

		if (!check)
		{
			if (mtx->key == SQUARE)
			{
				SquareOutput((squareMtx*)mtx, ofst);
				return true;
			} // ?сли выводима¤ в поток матрица ¤влетс¤ обыкновенной квадртной матрицей => вывод в поток + TRUE

			if (mtx->key == DIAGONAL)
			{
				DiagonalOutput((diagonalMtx*)mtx, ofst);
				return true;
			} // ?сли выводима¤ в поток матрица ¤влетс¤ диагональной матрицей, полученной на основании одномерного массива => вывод в поток + TRUE

			check = true; // ?сли матрица не принадлежит ни одному из типов => выставл¤ем TRUE
		}

		if (check)
		{
			ofst << "Incorrect matrix!" << endl;
			return false;
		} // ¬ывод сообщени¤ об ошибке в том случае, когда матрица не принадлежит ни к одному из предусмотренных типов

	}

	// ќчистка пам¤ти, выделенной под хранение матрицы
	void MtxClear(matrix* mtx)
	{
		if (mtx->key == SQUARE)
		{
			SquareClear((squareMtx*)mtx);
		} //ќчистка пам¤ти дл¤ обычной квадратной матрицы

		if (mtx->key == DIAGONAL)
		{
			DiagonalClear((diagonalMtx*)mtx);
		} //ќчистка пам¤ти дл¤ диагональной матрицы матрицы

	}
} // end namesapce simple_matrix