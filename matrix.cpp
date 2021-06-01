#include "matrix.h"
namespace simple_matrix
{

	matrix* MtxInput(ifstream& ifst)
	{
		matrix* newMatrix;
		int currKey;
		int style = -1;

		ifst >> currKey;
		ifst >> style;

		switch (currKey)
		{
		case 0:
			newMatrix = (matrix*)SquareInput(ifst);
			if (newMatrix != NULL)
			{
				if (MtxStyleSet(newMatrix, style))
				{
					newMatrix->key = SQUARE;
					break;
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				return NULL;
			}
		case 1:
			newMatrix = (matrix*)DiagonalInput(ifst);
			if (newMatrix != NULL)
			{
				if (MtxStyleSet(newMatrix, style))
				{
					newMatrix->key = DIAGONAL;
					break;
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				return NULL;
			}
		case 2:
			newMatrix = (matrix*)TriangularInput(ifst);
			if (newMatrix != NULL)
			{
				if (MtxStyleSet(newMatrix, style))
				{
					newMatrix->key = TRIANGULAR;
					break;
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				return NULL;
			}
		default:
			return NULL;
		}

		return newMatrix;
	}


	bool MtxOutput(matrix* mtx, ofstream& ofst)
	{
		bool check = false;

		if (!check)
		{
			if (mtx->key == SQUARE)
			{
				SquareOutput((squareMtx*)mtx, ofst);
				return true;
			}

			if (mtx->key == DIAGONAL)
			{
				DiagonalOutput((diagonalMtx*)mtx, ofst);
				return true;
			}

			if (mtx->key == TRIANGULAR)
			{
				TriangularOutput((triangularMtx*)mtx, ofst);
				return true;
			}

			check = true;
		}

		if (check)
		{
			ofst << "Incorrect matrix!" << endl;
			return false;
		}

	}


	void MtxClear(matrix* mtx)
	{
		if (mtx->key == SQUARE)
		{
			SquareClear((squareMtx*)mtx);
		}

		if (mtx->key == DIAGONAL)
		{
			DiagonalClear((diagonalMtx*)mtx);
		}

		if (mtx->key == TRIANGULAR)
		{
			TriangularClear((triangularMtx*)mtx);
		}

		bool MtxStyleSet(matrix * mtx, int style)
		{
			switch (style)
			{
			case 0:
				mtx->style = LINEBYLINE;
				break;
			case 1:
				mtx->style = BYCOLUMNS;
				break;
			case 2:
				mtx->style = ONEDIMENARR;
				break;
			default:
				return false;
			}
			return true;
		}
	} // end namesapce simple_matrix