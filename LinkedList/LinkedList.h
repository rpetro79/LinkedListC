#pragma once
#include <stdint.h>

typedef enum {OK, EMPTY, NOT_FOUND, _NULL, ERROR}ListReturnCode;
typedef struct LinkedList* list_t;
typedef struct node* node_t;

list_t create();
ListReturnCode addItem(list_t self, void* item);
ListReturnCode getItem(list_t self, void** item, uint16_t index);
ListReturnCode removeItem(list_t self, void* item);
uint16_t numberOfItems(list_t self);