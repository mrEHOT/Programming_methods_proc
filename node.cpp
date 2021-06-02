#include "node.h"
namespace simple_matrix
{
	// ������� ��������� ����� ������
	void NodeCompare(struct node* head, int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (MtxCompare(GetNode(head, i)->mtx, GetNode(head, j)->mtx))
				{
					NodeSwap(head, i, j);
				}
			}
		}
	}

	// ���������� ���� � ������������� ������� (��������)
	node* GetNode(struct node* head, int pos)
	{
		struct node* retNode = head;

		for (int i = 0; i < pos; i++)
		{
			retNode = retNode->next;
		}
		return retNode;
	}

	// ������ ������� ���������� ����� � ���������������� ��������
	void NodeSwap(struct node* head, int first, int second)
	{
		struct node* temp = new node; // ���������� ��������� ��������� �� Node
		temp->mtx = GetNode(head, first)->mtx; // ������������� ��������� �� ������� ������� ����
		GetNode(head, first)->mtx = GetNode(head, second)->mtx; // �������� �� ������� ������� ���� ��������� �� ������� �������
		GetNode(head, second)->mtx = temp->mtx; // �������� �� ������� ������� ���� ��������� �� ������� �������
	}

	// ���������� ������ ���� �� ��������� ������ �� ������
	bool NodeAdd(struct container* cont, ifstream& ifst)
	{
		node* newNode = new node(); // �������������� ����� ������ node ��� ������ ������������ �� ���������
		newNode->mtx = MtxInput(ifst); // ������������� ��������� �� ������ ���� matrix (� �������������� ��� ��� ������ ������ �� ������)

		if (newNode->mtx != NULL)
		{
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
		else
		{
			return false;
		}

	}

	// �������� ���� � ������� pos �� ������
	void NodeRemove(struct node* head, int pos)
	{
		node* currNode = head; // ������������� ��������� ������� ������� �� "������" ������

		for (int i = 0; i < pos; i++)
		{
			currNode = currNode->next;
		} // ���� �� ������ �� ���������� �������� ������ � ������� pos
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
		} // ��������� ������ ����� ������ ���� �� ������ ������� � ������ �������

		if (!MtxOutput(currNode->mtx, ofst))
		{
			cout << "Cannot to output matrix!" << endl;
			return false;
		} // ���� ����� ������� � ����� �������� ��������� => TRUE => !TRUE = FALSE => ��������� �� ������ �� ����� ��������

		return true; // ���������� TRUE, �.�. ������� ������ ��� ������� matrix � �����
	}

	// ���������� ����� ����� � �����
	bool FilteredNodeOutput(struct node* head, int pos, ofstream& ofst)
	{
		node* currNode = head; // ������������� ��������� ������� ������� �� "������" ������

		for (int i = 0; i < pos; i++)
		{
			currNode = currNode->next;
		} // ��������� ������ ����� ������ ���� �� ������ ������� � ������ �������

		if (FilteredMtxOutput(currNode->mtx, ofst))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
} // end namespace simple_matrix