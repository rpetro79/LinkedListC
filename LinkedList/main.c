#include<stdio.h>
#include "LinkedList.h"

void main()
{
	list_t *myList = create();
	int a = 5, b = 6, c = 7;
	addItem(myList, a);
	addItem(myList, b);
	addItem(myList, c);

	node_t item;
	getItem(myList, &item, 2);

	removeItem(myList, item);

	getItem(myList, &item, 0);
	getItem(myList, &item, 1);
}