#include "container.h"
#include "node.h"

namespace simple_matrix
{
	// ���������� ����������
	void Sort(struct container* cont)
	{
		NodeCompare(cont->head, cont->size); // ����� ������� ��������� �����
	}

	// ������������� ����������
	void Init(struct container* cont)
	{
		cont->size = 0; // ��� ������������� ���������� ��� ������ ����� ����
		cont->head = NULL; // ��� ������������� ��������� ���� => "������" ���
	}

	// ������� ���������� � ��� ��������� � ��������� ���������
	void Clear(struct container* cont)
	{
		if (cont->head == NULL)
		{
			return;
		} // ��� ������ ���������� ������� �� ���������
		else
		{
			for (int i = cont->size - 1; i >= 0; i--)
			{
				NodeRemove(cont->head, i); // ��������� �������� ������� ���� ������ (������� �������� ����������)
			}
			cont->head = NULL; // ����� ������ ������� ���������� ��������� ��������������� �� NULL
		}

		cont->size = 0; // ����� ������� � ���������� �� ��������� ���������
	}

	// ���� ����������� ���������� �� ���������� ������
	bool Input(struct container* cont, ifstream& ifst)
	{
		while (!ifst.eof())
		{
			if (NodeAdd(cont, ifst))
			{
				(cont->size)++; // ����������� ���������� ��������� � ����������
			} // ���� �������� ���������� � ������ ��������� ��������� => ������������ TRUE � ������������� ������ ����������
			else
			{
				return false;
			} // �������� ���������� � ������ �� ���������
		} // ���� �� ��������� ����� ������

		return true;
	}

	//����� ����������� ���������� � ��������� �����
	void Output(struct container* cont, ofstream& ofst)
	{
		ofst << "Container contains " << cont->size << " elements." << endl; // ������� ����� ���������� ��������� � ����������
		for (int i = 0; i < cont->size; i++)
		{
			if (!NodeOutput(cont->head, i, ofst))
			{
				cout << "Node is broken!" << endl; // ����� ��������� � ������������� ������ ��������
			} // ���� �������� ������� ��������� => �������� TRUE => !TRUE = FALSE => ��������� �� ������ �� �������� �� ������
		} // ����������� ����� ��������� ���������� � �����
	}

	//���������� ����� � ��������� �����.
	void FilteredOutput(struct container* cont, ofstream& ofst)
	{
		ofst << endl << "Filtered Output - Square matrix:" << endl << endl;
		for (int i = 0; i < cont->size; i++)
		{
			FilteredNodeOutput(cont->head, i, ofst);
		} // ����������� ����� ����������� ���������� ������ �� ���������� � �����
	}
} //end namespace simple_matrix