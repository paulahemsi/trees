
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "tests.hpp"

template <typename T>
bool compare(T& item1, T& item2)
{
	if (item1 > item2)
		return true;
	return false;
}

template <typename T>
void btree_insert_data(ft::btree<T> **root, T &new_item, bool (*compare)(T &, T &))
{
	if (*root == NULL)
	{
		*root = btree_create_node(new_item);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data(&(*root)->left, new_item, compare);
	else
		btree_insert_data(&(*root)->right, new_item, compare);
}

#endif
