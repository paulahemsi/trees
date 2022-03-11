
#include "tests.hpp"

int main(void)
{
	int item = 7;
	ft::btree<int> *node = btree_create_node(&item);
	std::cout << node->item << std::endl;
}
