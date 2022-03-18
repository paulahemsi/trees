
#ifndef BTREE_TPP
#define BTREE_TPP

#include <iostream>

namespace ft
{
	template <typename T>
	struct btree
	{
		struct btree	*left;
		struct btree	*right;
		struct btree	*parent;
		T				*item;

		btree(void): left(NULL), right(NULL), parent(NULL), item(NULL) {}
		btree(T *new_item): left(NULL), right(NULL), parent(NULL), item(new_item) {}
		~btree(void)
		{
			if (this->item)
				delete item;
		}
	};
	
};

#endif
