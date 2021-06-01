#pragma once
#ifndef node_definition
#define node_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "container.h"
using namespace std;
namespace simple_matrix
{
	// ���������, ����������� ���� ������
	struct node
	{
		matrix* mtx; // ��������� �� ������ ���� "�������"
		node* next; // ��������� �� ��������� ������� ������
		node* prev; // ��������� �� ���������� ������� ������
	};

	bool NodeAdd(struct container* cont, ifstream& ifst); // ���������� ������ ���� �� ��������� ������ �� ������
	void NodeRemove(struct node* head, int pos); // �������� ���� � ������� (pos - 1) �� ������
	bool NodeOutput(struct node* head, int pos, ofstream& ofst); // ����� ���� � �����
} // end namespace simple_matrix
#endif // !node_definition