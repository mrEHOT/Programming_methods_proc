#include "triangularMtx.h"
namespace simple_matrix
{
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

	void TriangularOutput(struct triangularMtx* mtx, ofstream& ofst)
	{
		int count = 0;

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
					}
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
				}
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
			ofst << "]" << endl;
			break;
		default:
			break;
		}

		ofst << endl;
	}

	triangularMtx* TriangularInput(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = ""; 
		size_t pos = 0;
		int col = 0;
		int count = 1;
		int check = 0;

		triangularMtx* mtx = new triangularMtx;

		ifst >> content;

		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				count++;
			}
		}

		mtx->sideSize = (long)sqrt(count) + 1;

		check = (1 + mtx->sideSize) * mtx->sideSize / 2;
		if (count == check)
		{
			mtx->currentMtxSize = count;
			mtx->currentMtx = new int[count];


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
		else
		{
			return NULL;
		}
	}

	void TriangularClear(struct triangularMtx* mtx)
	{
		delete[] mtx->currentMtx;
	}
} // end namesapce simple_matrix