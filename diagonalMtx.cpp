#include "diagonalMtx.h"
namespace simple_matrix
{
	int DiagonalSum(struct diagonalMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->sideSize; row++)
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

	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << mtx->sideSize << ". The sum of the elements of the matrix: " << mtx->sum << endl;

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
			ofst << "]" << endl;
			break;
		default:
			break;
		}

		ofst << endl;
	}

	diagonalMtx* DiagonalInput(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;

		diagonalMtx* mtx = new diagonalMtx;

		ifst >> mtx->sideSize >> content;
		mtx->currentMtx = new int[mtx->sideSize];


		while ((pos = content.find(delimiter)) != string::npos)
		{
			part = content.substr(0, pos);
			mtx->currentMtx[col] = atoi(part.c_str());
			col++;
			content.erase(0, pos + delimiter.length());
		}

		mtx->currentMtx[col] = atoi(content.c_str());

		return mtx;
	}

	void DiagonalClear(struct diagonalMtx* mtx)
	{
		delete[] mtx->currentMtx;
	}
} // end namesapce simple_matrix