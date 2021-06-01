#include "node.h"
namespace simple_matrix
{
	// Функция сравнения узлов списка
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

	// Возвращает узел с сответсвующим номером (позицией)
	node* GetNode(struct node* head, int pos)
	{
		struct node* retNode = head;

		for (int i = 0; i < pos; i++)
		{
			retNode = retNode->next;
		}
		return retNode;
	}

	// Меняет местами содержимое узлов с соответствующими номерами
	void NodeSwap(struct node* head, int first, int second)
	{
		struct node* temp = new node; // Определяем временный указатель на Node
		temp->mtx = GetNode(head, first)->mtx; // Устанавливаем указатель на матрицу первого узал
		GetNode(head, first)->mtx = GetNode(head, second)->mtx; // Указтель на матрицу первого узла указывает на матрицу второго
		GetNode(head, second)->mtx = temp->mtx; // Указтель на матрицу второго узла указывает на матрицу первого
	}

	// Добавление нового узла на основании данных из потока
	bool NodeAdd(struct container* cont, ifstream& ifst)
	{
		node* newNode = new node(); // Инициализируем новый объект node при помощи конструктора поумолчанию
		newNode->mtx = MtxInput(ifst); // Устанавливаем указатель на объект типа matrix

		if (newNode->mtx == NULL)
		{
			delete (newNode);
			return false;
		} // Если объект типа matrix не удалось считать из потока => указатель на matrix == NULL => добавлять элемент в список не нужно

		if (cont->head == NULL)
		{
			cont->head = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
		} // Если список пустой, то добавляем первый элемент
		else
		{
			newNode->next = cont->head;
			newNode->prev = cont->head->prev;
			cont->head->prev->next = newNode;
			cont->head->prev = newNode;
		} // В списке уже есть "голова"

		return true;
	}

	// Удаление узла с номером pos из списка
	void NodeRemove(struct node* head, int pos)
	{
		node* currNode = head; // Устанавливаем указатель текущей позиции на "голову" списка

		for (int i = 0; i < pos; i++)
		{
			currNode = currNode->next;
		} // Идем по списку до нахождения элемента списка с номером pos
		MtxClear(currNode->mtx);
		free(currNode); // Освобождаем область памяти, на которую указывает currNode
	}

	// Вывод узла в поток
	bool NodeOutput(struct node* head, int pos, ofstream& ofst)
	{
		node* currNode = head; // Устанавливаем указатель текущей позиции на "голову" списка

		for (int i = 0; i < pos; i++)
		{
			currNode = currNode->next;
		} // 

		if (!MtxOutput(currNode->mtx, ofst))
		{
			cout << "Cannot to output matrix!" << endl;
			return false;
		} // Если вывод матрицы в поток выполнен корректно => TRUE => !TRUE = FALSE => сообщение об ошибке не будет получено

		return true; // Возвращаем TRUE, т.к. успешно вывели все объекты matrix в поток
	}
} // end namespace simple_matrix