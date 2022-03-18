
#ifndef BTREE_LEFT_ROTATE_TPP
#define BTREE_LEFT_ROTATE_TPP

#include "btree.tpp"
#include "btree_rotate_aux.tpp"

template <typename T>
ft::btree<T> * btree_left_rotate(ft::btree<T> *node_to_rotate)
{
	ft::btree<T> *parent = node_to_rotate->parent;
	ft::btree<T> *new_root = node_to_rotate->right;
	node_to_rotate->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = node_to_rotate;
	new_root->left = node_to_rotate;
	node_to_rotate->parent = new_root;
	new_root->parent = parent;
	if (new_root->parent)
		update_parent_child(node_to_rotate, new_root);
	return (new_root);
}

#endif
