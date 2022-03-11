
#ifndef BTREE_CREATE_NODE_TPP
#define BTREE_CREATE_NODE_TPP

#include "btree.tpp"

template <typename T>
ft::btree<T> *btree_create_node(T *item)
{
	ft::btree<int>	*new_node = new ft::btree<int>;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->item = *item;
	return (new_node);
}

#endif
