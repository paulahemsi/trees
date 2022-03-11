
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
		T				item;
	};
	
};

#endif
