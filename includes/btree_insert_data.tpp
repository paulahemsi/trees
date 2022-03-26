
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "tests.hpp"

template <typename T>
bool is_parent_left_child(ft::btree<T> *parent, ft::btree<T> *node)
{
	return (parent->left == node);
}

template <typename T>
ft::btree<T> * get_sibling(ft::btree<T> *node)
{
	if (is_parent_left_child(node->parent, node))
		return node->parent->right;
	return node->parent->left;
}

template <typename T>
bool sibling_is_red(ft::btree<T> *node)
{
	if (get_sibling(node)->color == RED)
		return (true);
	return (false);
}

template <typename T>
void recolor(ft::btree<T> *node)
{
	node->color = !node->color;
}

template <typename T>
bool node_is_root(ft::btree<T> *node)
{
	return (node->parent == NULL);
}

template <typename T>
void recolor_node_and_sibling(ft::btree<T> *node)
{
	recolor(node);
	recolor(get_sibling(node));
}

template <typename T>
void check_rules(ft::btree<T> *node)
{
	if (node->parent->color == BLACK)
		return ;
	if (sibling_is_red(node->parent))
	{
		ft::btree<T>* grandma = node->parent->parent;
		recolor_node_and_sibling(node->parent);
		if(node_is_root(grandma))
			return ;
		recolor(grandma);
		return check_rules(grandma);
	}
	//rotations
	//recolor
	//return
}

template <typename T>
void btree_insert_data_recursive(ft::btree<T> **root, ft::btree<T> *parent, T *new_item, bool (*compare)(T *, T *))
{
	if (*root == NULL)
	{
		*root = new ft::btree<int>(new_item);
		(*root)->parent = parent;
		//check_rules(*root);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data_recursive(&(*root)->right, *root, new_item, compare);
	else
		btree_insert_data_recursive(&(*root)->left, *root, new_item, compare);
}

template <typename T>
void btree_insert_data(ft::btree<T> **root, T *new_item, bool (*compare)(T *, T *))
{
	if (*root == NULL)
	{
		*root = new ft::btree<int>(new_item, BLACK);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data_recursive(&(*root)->right, *root, new_item, compare);
	else
		btree_insert_data_recursive(&(*root)->left, *root, new_item, compare);
}

#endif
