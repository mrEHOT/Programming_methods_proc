#include "squareMtx.h"
namespace simple_matrix
{
	int SquareSum(struct squareMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					mtx->sum += mtx->currentMtx[row][col];
				}
			}
			mtx->sumMarker = true;
			return mtx->sum;
		}
		else
		{
			return mtx->sum;
		}
	}

	void SquareOutput(struct squareMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Square matrix. Matrix side size: " << mtx->sideSize << ". The sum of the elements of the matrix: " << mtx->sum << endl;

		switch (mtx->style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					ofst << mtx->currentMtx[row][col] << "\t";
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
					ofst << mtx->currentMtx[row][col] << "\t";
				}
				ofst << endl;
			}
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					ofst << mtx->currentMtx[row][col] << " ";
				}
			}
			ofst << "]" << endl;
			break;
		default:
			break;
		}

		ofst << endl;
	}

	squareMtx* SquareInput(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;

		squareMtx* mtx = new squareMtx;

		ifst >> mtx->sideSize;
		mtx->currentMtx = new int* [mtx->sideSize];
		for (int row = 0; row < mtx->sideSize; row++)
		{
			mtx->currentMtx[row] = new int[mtx->sideSize];
		}

		for (int row = 0; row < mtx->sideSize; row++)
		{
			ifst >> content;

			while ((pos = content.find(delimiter)) != string::npos)
			{
				part = content.substr(0, pos);
				mtx->currentMtx[row][col] = atoi(part.c_str());
				col++;
				content.erase(0, pos + delimiter.length());
			}

			mtx->currentMtx[row][col] = atoi(content.c_str());
			content = "";
			col = 0;
		}

		return mtx;
	}

	void SquareClear(struct squareMtx* mtx)
	{
		for (int row = 0; row < mtx->sideSize; row++)
		{
			delete mtx->currentMtx[row];
		}

		delete[] mtx->currentMtx;
	}
} // end namesapce simple_matrix