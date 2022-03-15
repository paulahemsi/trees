
#include "tests.hpp"

int main(void)
{
	ft::btree<int> *root = NULL;
	for (int i = 10; i < 20; i++)
		btree_insert_data(&root, new int(i), &compare);
	for (int i = 0; i < 10; i++)
		btree_insert_data(&root, new int(i), &compare);

	std::cout << "\n---INFIX---\n" << std::endl;
	btree_apply_infix(root, print_item);
	std::cout << "\n---PREFIX---\n" << std::endl;
	btree_apply_prefix(root, print_item);
	std::cout << "\n---SUFFIX---\n" << std::endl;
	btree_apply_suffix(root, print_item);

	std::cout << "\n---SEARCH---\n" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		int * number = btree_search_item(root, new int(i), &compare);
		std::cout << *number << " " << number << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		int * number = btree_search_item(root, new int(i), &compare);
		std::cout << *number << " " << number << std::endl;
	}
	for (int i = 99; i < 111; i++)
	{
		int * number = btree_search_item(root, new int(i), &compare);
		if (number == NULL)
			std::cout << i << " NOT IN TREE" << std::endl;
		else
			std::cout << *number << " " << number << std::endl;
	}

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos);
	testes_lais();
}
