
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
		T				*item;

		btree(void): left(NULL), right(NULL), item(NULL) {}
		btree(T *new_item): left(NULL), right(NULL), item(new_item) {}
		~btree(void)
		{
			if (this->item)
				delete item;
		}
	};
	
};

#endif
