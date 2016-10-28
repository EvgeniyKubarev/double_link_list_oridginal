#include "list.h"


elem* add(int data)
{
	elem* curr = new elem;
	curr->data = data;
	curr->prev = NULL;
	curr->next = NULL;
	return curr;
}

elem* addBeginElem(int data, elem **head)
{
	elem* curr = new elem;
	curr->data = data;
	(*head)->prev = curr;
	curr->next = *head;
	*head = curr;
	curr->prev = NULL;
	return *head;
}

void insert(int base, int valive, elem **head)
{
	elem* curr = search(base, *head), *newList = new elem;
	newList->data = valive;
	newList->prev = curr;
	curr->prev->next = newList;
	curr->prev = newList;
	newList->next = curr;
}

elem* appand(int data, elem **tail)
{
	elem* curr = new elem;
	curr->data = data;
	(*tail)->next = curr;
	curr->prev = *tail;
	*tail = curr;
	curr->next = NULL;
	return *tail;
}

void deleteElem(int data, elem **head, elem **tail)
{
	elem *curr = search(data, *head);
	if(curr->prev != NULL && curr->next != NULL)
	{
		elem *PREV = curr->prev;
		elem *NEXT = curr->next;
		PREV->next = NEXT;
		NEXT->prev = PREV;
		delete curr;
		return;
	}
	if (curr->prev == NULL && curr->next != NULL)
	{
		*head = curr->next;
		delete curr;
		return;
	}
	if (curr->prev != NULL && curr->next == NULL)
	{
		*tail = curr->prev;
		delete curr;
		return;
	}
	if (curr->prev == NULL && curr->next == NULL)
	{
		delete curr;
		head = NULL;
		tail = NULL;
		return;
	}
}

void sortList(elem **head)
{
	elem* curr = *head;
	while (curr->next)
	{
		if (curr->data > curr->next->data)
		{
			int data = curr->data;
			curr->data = curr->next->data;
			curr->next->data = data;
			curr = curr->next;
			sortList(head);
		}
		else
			curr = curr->next;
	}
}

elem* search(int data, elem *curr)
{
	while (curr != NULL && curr->data != data)
	{
		curr = curr->next;
	}
	return curr;
}

void printList(elem *head)
{
	elem* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}
