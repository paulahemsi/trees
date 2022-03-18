
#ifndef BTREE_RIGHT_ROTATE_TPP
#define BTREE_RIGHT_ROTATE_TPP

#include "btree.tpp"
#include "btree_rotate_aux.tpp"

template <typename T>
ft::btree<T> * btree_right_rotate(ft::btree<T> *node_to_rotate)
{
	ft::btree<T> *parent = node_to_rotate->parent;
	ft::btree<T> *new_root = node_to_rotate->left;
	node_to_rotate->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = node_to_rotate;
	new_root->right = node_to_rotate;
	node_to_rotate->parent = new_root;
	new_root->parent = parent;
	if (new_root->parent)
		update_parent_child(node_to_rotate, new_root);
	return (new_root);
}

#endif
