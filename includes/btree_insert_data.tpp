
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
void btree_insert_data(ft::btree<T> **root, T &item, bool (*compare)(T &, T &))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (compare(item, (*root)->item))
		btree_insert_data(&(*root)->left, item, compare);
	btree_insert_data(&(*root)->right, item, compare);
}

#endif
