#include "matrix.h"

namespace simple_matrix
{
	bool MtxCompare(matrix* firstMtx, matrix* secondMtx)
	{
		if (MtxSum(firstMtx) > MtxSum(secondMtx))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int MtxSum(matrix* mtx)
	{
		if (mtx->key == SQUARE)
		{
			return SquareSum((squareMtx*)mtx);
		}

		if (mtx->key == DIAGONAL)
		{
			return DiagonalSum((diagonalMtx*)mtx);
		}

		if (mtx->key == TRIANGULAR)
		{
			return TriangularSum((triangularMtx*)mtx);
		}
	}

	matrix* MtxInput(ifstream& ifst)
	{
		matrix* newMatrix;
		int currKey = 0;
		int style = 0;
		string content = "";

		ifst >> content;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				currKey++;
			}
		}
		if (currKey != 0)
		{
			return NULL;
		}
		else
		{
			currKey = atoi(content.c_str());
			content = "";
		}

		ifst >> content;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				style++;
			}
		}
		if (style != 0)
		{
			return NULL;
		}
		else
		{
			style = atoi(content.c_str());
			content = "";
		}

		switch (currKey)
		{
		case 0:
			newMatrix = (matrix*)SquareInput(ifst);
			if (newMatrix != NULL)
			{
				if (MtxStyleSet(newMatrix, style))
				{
					newMatrix->key = SQUARE;
					MtxSum(newMatrix);
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
					MtxSum(newMatrix);
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
					MtxSum(newMatrix);
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
				return SquareOutput((squareMtx*)mtx, ofst);
			}

			if (mtx->key == DIAGONAL)
			{
				return DiagonalOutput((diagonalMtx*)mtx, ofst);
			}

			if (mtx->key == TRIANGULAR)
			{
				return TriangularOutput((triangularMtx*)mtx, ofst);
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
	}

	bool MtxStyleSet(matrix* mtx, int style)
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

	bool FilteredMtxOutput(matrix* mtx, ofstream& ofst)
	{
		if (mtx->key == SQUARE)
		{
			if (SquareOutput((squareMtx*)mtx, ofst))
			{
				return true;
			}
			else
			{
				ofst << "Incorrect square matrix!" << endl;
				return false;
			}
		}
	}
} // end namesapce simple_matrix