#include "node.h"
namespace simple_matrix
{
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

	// Удаление узла с номером (pos - 1) из списка
	void NodeRemove(struct node* head, int pos)
	{
		node* currNode = head; // Устанавливаем указатель текущей позиции на "голову" списка

		for (int i = 0; i < pos - 1; i++)
		{
			currNode = currNode->next;
		} // Идем по списку до нахождения элемента списка с номером n-1
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