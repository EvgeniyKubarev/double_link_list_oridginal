// double_lincet_list.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "list.h"


int _tmain(int argc, _TCHAR* argv[])
{
	elem* curr = add(0), *head = curr, *tail = curr;
	for (int i = 1; i < 10; i++)
	{
		addBeginElem(i, &head);
	}
	insert(5, 0, &head);
	appand(0, &tail);
	printList(head);
	deleteElem(5, &head, &tail);
	sortList(&head);
	printList(head);
	_gettch();
	return 0;
}
