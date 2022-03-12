
#ifndef BTREE_APPLY_PREFIX_TPP
#define BTREE_APPLY_PREFIX_TPP

#include "btree.tpp"

template <typename T>
void btree_apply_prefix(ft::btree<T> *root, void (*applyf)(T &))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

#endif
