
#ifndef BTREE_TPP
#define BTREE_TPP

#include <iostream>

#define	RED		false
#define	BLACK	true

namespace ft
{
	template <typename T>
	struct btree
	{
		typedef	bool	t_color;

		struct btree	*left;
		struct btree	*right;
		struct btree	*parent;
		t_color			color;
		T				*item;

		btree(void): left(NULL), right(NULL), parent(NULL), color(RED), item(NULL) {}
		btree(T *new_item): left(NULL), right(NULL), parent(NULL), color(RED), item(new_item) {}
		btree(T *new_item, bool is_black): left(NULL), right(NULL), parent(NULL), color(is_black), item(new_item) {}
		~btree(void) {}
	};
};

#endif
