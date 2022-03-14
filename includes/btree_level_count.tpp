
#ifndef BTREE_LEVEL_COUNT_TPP
#define BTREE_LEVEL_COUNT_TPP

#include "btree.tpp"

template <typename T>
static T max_depth(T left_depth, T right_depth)
{
	if (left_depth > right_depth)
		return (left_depth);
	return (right_depth);
}

template <typename T>
int btree_level_count(ft::btree<T> *root)
{
	if (!root || (!root->left && !root->right))
		return (0);
	else
		return (max_depth(btree_level_count(root->left), btree_level_count(root->right)) + 1);
}

#endif
