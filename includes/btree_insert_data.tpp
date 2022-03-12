
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "tests.hpp"

template <typename T>
void btree_insert_data(ft::btree<T> **root, T &new_item, bool (*compare)(T &, T &))
{
	if (*root == NULL)
	{
		*root = btree_create_node(new_item);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data(&(*root)->right, new_item, compare);
	else
		btree_insert_data(&(*root)->left, new_item, compare);
}

#endif
