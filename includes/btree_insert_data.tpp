
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "tests.hpp"

template <typename T>
void btree_insert_data_recursive(ft::btree<T> **root, ft::btree<T> *parent, T *new_item, bool (*compare)(T *, T *))
{
	if (*root == NULL)
	{
		*root = new ft::btree<int>(new_item);
		(*root)->parent = parent;
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data_recursive(&(*root)->right, *root, new_item, compare);
	else
		btree_insert_data_recursive(&(*root)->left, *root, new_item, compare);
}

template <typename T>
void btree_insert_data(ft::btree<T> **root, T *new_item, bool (*compare)(T *, T *))
{
	if (*root == NULL)
	{
		*root = new ft::btree<int>(new_item, BLACK);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data_recursive(&(*root)->right, *root, new_item, compare);
	else
		btree_insert_data_recursive(&(*root)->left, *root, new_item, compare);
}

#endif
