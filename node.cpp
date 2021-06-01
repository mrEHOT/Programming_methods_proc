#include "node.h"
namespace simple_matrix
{
	// ���������� ������ ���� �� ��������� ������ �� ������
	bool NodeAdd(struct container* cont, ifstream& ifst)
	{
		node* newNode = new node(); // �������������� ����� ������ node ��� ������ ������������ �����������
		newNode->mtx = MtxInput(ifst); // ������������� ��������� �� ������ ���� matrix

		if (newNode->mtx == NULL)
		{
			delete (newNode);
			return false;
		} // ���� ������ ���� matrix �� ������� ������� �� ������ => ��������� �� matrix == NULL => ��������� ������� � ������ �� �����

		if (cont->head == NULL)
		{
			cont->head = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
		} // ���� ������ ������, �� ��������� ������ �������
		else
		{
			newNode->next = cont->head;
			newNode->prev = cont->head->prev;
			cont->head->prev->next = newNode;
			cont->head->prev = newNode;
		} // � ������ ��� ���� "������"

		return true;
	}

	// �������� ���� � ������� (pos - 1) �� ������
	void NodeRemove(struct node* head, int pos)
	{
		node* currNode = head; // ������������� ��������� ������� ������� �� "������" ������

		for (int i = 0; i < pos - 1; i++)
		{
			currNode = currNode->next;
		} // ���� �� ������ �� ���������� �������� ������ � ������� n-1
		MtxClear(currNode->mtx);
		free(currNode); // ����������� ������� ������, �� ������� ��������� currNode
	}

	// ����� ���� � �����
	bool NodeOutput(struct node* head, int pos, ofstream& ofst)
	{
		node* currNode = head; // ������������� ��������� ������� ������� �� "������" ������

		for (int i = 0; i < pos; i++)
		{
			currNode = currNode->next;
		} // 

		if (!MtxOutput(currNode->mtx, ofst))
		{
			cout << "Cannot to output matrix!" << endl;
			return false;
		} // ���� ����� ������� � ����� �������� ��������� => TRUE => !TRUE = FALSE => ��������� �� ������ �� ����� ��������

		return true; // ���������� TRUE, �.�. ������� ������ ��� ������� matrix � �����
	}
} // end namespace simple_matrix