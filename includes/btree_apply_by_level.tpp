
#ifndef BTREE_APPLY_BY_LEVEL_TPP
#define BTREE_APPLY_BY_LEVEL_TPP

#include "btree.tpp"
#include "tests.hpp"
#include <cstddef>
#include <queue>

# define CYAN			"\e[0;36m"
# define RESET			"\e[0m"

template <typename T>
void print_node_infos(T &item, int level, bool is_first)
{
	if (is_first)
		std::cout << CYAN;
	else
		std::cout << RESET;
	if(item == 999)
		std::cout << std::endl;
	else
		std::cout << item << "(" << level << ")" << std::endl;
}

template <typename T>
void add_new_nodes_to_queue(std::queue<ft::btree<T> *> &leaf_queue, ft::btree<T> * node)
{
	if(node->left)
		leaf_queue.push(node->left);
	if(node->right)
		leaf_queue.push(node->right);
}

template <typename T>
void set_initial_values(ft::btree<T> *root, std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first, ft::btree<T> *new_line)
{
	leaf_queue.push(root);
	leaf_queue.push(new_line);
	is_first = true;
	current_level = 0;
}

template <typename T>
void btree_apply_by_level(ft::btree<T> *root, void (*applyf)(T &item, int current_level, bool is_first))
{
	if (!root)
		return ;
	ft::btree<T> *new_line = new ft::btree<T>;
	new_line->item = 999;
	new_line->left = NULL;
	new_line->right = NULL;

	std::queue<ft::btree<T> *> leaf_queue;
	ft::btree<T> *node = NULL;
	bool is_first;
	int current_level;
	set_initial_values(root, leaf_queue, current_level, is_first, new_line);

	while(true)
	{
		node = leaf_queue.front();
		leaf_queue.pop();
		applyf(node->item, current_level, is_first);
		is_first = false;
		if (node->item == 999)
		{
			if (leaf_queue.empty())
				break;
			is_first = true;
			current_level++;
			leaf_queue.push(new_line);
		}
		else
			add_new_nodes_to_queue(leaf_queue, node);
	}
}

#endif
