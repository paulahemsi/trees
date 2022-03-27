
#include "tests.hpp"

int main(void)
{
	ft::btree<int> *root = NULL;
	for (int i = 10; i < 20; i++)
	{
		std::cout << "insert " << i << std::endl;
		btree_insert_data(&root, new int(i), &compare);
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "insert " << i << std::endl;
		btree_insert_data(&root, new int(i), &compare);
		btree_apply_by_level(root, print_rb_node_infos);
	}

	std::cout << "\n---INFIX---\n" << std::endl;
	btree_apply_infix(root, print_item);
	std::cout << "\n---PREFIX---\n" << std::endl;
	btree_apply_prefix(root, print_item);
	std::cout << "\n---SUFFIX---\n" << std::endl;
	btree_apply_suffix(root, print_item);

	std::cout << "\n---SEARCH---\n" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		int * number = btree_search_item(root, i, &compare);
		std::cout << *number << " " << number << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		int * number = btree_search_item(root, i, &compare);
		std::cout << *number << " " << number << std::endl;
	}
	for (int i = 99; i < 111; i++)
	{
		int * number = btree_search_item(root, i, &compare);
		if (number == NULL)
			std::cout << i << " NOT IN TREE" << std::endl;
		else
			std::cout << *number << " " << number << std::endl;
	}

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos);

	std::cout << "\n---NODE AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_node_and_parent);

	std::cout << "\n---DELETE---\n" << std::endl;
	for (int i = 10; i < 15; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 15; i < 20; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	
//btree_delete_tree(root);
	testes_lais();
}
