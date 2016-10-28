#include <conio.h>
#include <iostream>
using namespace std;

struct elem
{
	int data;
	elem *prev;
	elem *next;
};

elem* add(int data);

elem* addBeginElem(int data, elem **head);

void insert(int base, int valive, elem **head);

elem* appand(int data, elem **tail);

void deleteElem(int data, elem **head, elem **tail);

void sortList(elem **head);

elem* search(int data, elem *head);

void printList(elem *head);
