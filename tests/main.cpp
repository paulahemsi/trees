
#include "tests.hpp"

int main(void)
{
	int item = 7;
	ft::btree<int> *root = NULL;
	btree_insert_data(&root, item, &compare);
	std::cout << root->item << std::endl;
}
