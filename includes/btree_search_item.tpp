
#ifndef BTREE_SEARCH_ITEM_TPP
#define BTREE_SEARCH_ITEM_TPP

#include "btree.tpp"

template <typename T>
T *btree_search_item(ft::btree<T> *root, T &data_ref,  bool (*compare)(T &, T &))
{
	if (root == NULL)
		return (NULL);
	if (root->item == data_ref)
		return (&root->item);
	if (compare(data_ref, root->item))
		return (btree_search_item(root->right, data_ref, compare));
	else
		return (btree_search_item(root->left, data_ref, compare));
}

#endif
