#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* element;
	struct node* next;
}node;

typedef struct LinkedList {
	struct node* first;
	struct node* current;
	int count;
}list;


list_t create()
{
	list_t newList = calloc(100, sizeof(list));

	if (newList == NULL)
		return NULL;


	newList->count = 0;

	return newList;
}

ListReturnCode addItem(list_t self, void* item)
{
	if (item == NULL)
		return _NULL;

	struct node* x;
	x = malloc(sizeof(node));
	if (x == NULL)
		return ERROR;

	x->element = item;
	x->next = NULL;

	if (self->first == NULL)
	{
		self->first=x;
	}
	else
	{
		self->current->next = x;
	}
	self->current = x;
	(self->count)++;
	return OK;
}

ListReturnCode getItem(list_t self, void** item, uint16_t index)
{
	if (self == NULL)
		return _NULL;

	if (index > self->count)
	{
		*item = NULL;
		return NOT_FOUND;
	}

	struct node *temp = self->first;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	*item = temp;
	return OK;
}

ListReturnCode removeItem(list_t self, void* item)
{
	if (self == NULL)
		return _NULL;

	if (self->first == item)
	{
		self->first = self->first->next;
		(self->count)--;
		return OK;
	}

	struct node* current, * previous;
	current = self->first->next;
	previous = self->first;
	for (int i = 1; i < self->count; ++i)
	{
		if (current == item)
		{
			previous->next = current->next;
			free(current);
			(self->count)--;
			return OK;
		}
		previous = current;
		current = current->next;
	}
	return NOT_FOUND;
}

uint16_t numberOfItems(list_t self)
{
	return self->count;
}