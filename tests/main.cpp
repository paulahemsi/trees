
#include "tests.hpp"

int main(void)
{
	ft::btree<int> *root = NULL;
	for (int i = 10; i < 20; i++)
		btree_insert_data(&root, i, &compare);
	for (int i = 0; i < 10; i++)
		btree_insert_data(&root, i, &compare);
	btree_apply_prefix(root, print_item);
}
