
#ifndef BTREE_APPLY_BY_LEVEL_TPP
#define BTREE_APPLY_BY_LEVEL_TPP

#include "btree.tpp"
#include "tests.hpp"
#include <queue>

# define CYAN			"\e[0;36m"
# define RESET			"\e[0m"

template <typename T>
void print_node_infos(T *item, int level, bool is_first)
{
	if (is_first)
		std::cout << CYAN;
	else
		std::cout << RESET;
	if(!item)
		std::cout << std::endl;
	else
		std::cout << *item << "(" << level << ")" << std::endl;
}

template <typename T>
void add_children_to_queue(std::queue<ft::btree<T> *> &leaf_queue, ft::btree<T> * node)
{
	if(node->left)
		leaf_queue.push(node->left);
	if(node->right)
		leaf_queue.push(node->right);
}

template <typename T>
void set_new_level(std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first)
{
	is_first = true;
	current_level++;
	leaf_queue.push(new ft::btree<int>());
}

template <typename T>
bool is_last_node(std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first, ft::btree<T> *node)
{
	if (node->item)
		return (false);
	if (leaf_queue.empty())
		return (true);
	set_new_level(leaf_queue, current_level, is_first);
	return (false);
}

template <typename T>
void btree_apply_by_level(ft::btree<T> *root, void (*applyf)(T *item, int current_level, bool is_first))
{
	if (root)
	{
		bool is_first = true;
		int current_level = 0;

		std::queue<ft::btree<T> *> leaf_queue;
		leaf_queue.push(root);
		leaf_queue.push(new ft::btree<int>());

		ft::btree<T> *node = NULL;
		while(true)
		{
			node = leaf_queue.front();
			if (!node->item)
				delete node;
			leaf_queue.pop();
			applyf(node->item, current_level, is_first);
			is_first = false;
			if (is_last_node(leaf_queue, current_level, is_first, node))
				break;
			else
				add_children_to_queue(leaf_queue, node);
		}
	}
}

#endif