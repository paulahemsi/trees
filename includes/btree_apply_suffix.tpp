
#ifndef BTREE_APPLY_SUFFIX_TPP
#define BTREE_APPLY_SUFFIX_TPP

#include "btree.tpp"

template <typename T>
void btree_apply_suffix(ft::btree<T> *root, void (*applyf)(T &))
{
	if (root->left)
		btree_apply_suffix(root->left, applyf);
	if (root->right)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}

#endif
