/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes_lais.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:21:27 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/26 22:29:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>
#include <string>


template<typename T>
void print_level(T* element, int current_level, int is_first)
{
	if (is_first)
		std::cout << std::endl << "level " << current_level << ": " << *element;
	else
		std::cout << " | " << *element;
}

template<typename T>
void print_level(ft::btree<T> *root, int expected)
{
	int level;
	
	level = btree_level_count<int>(root);
	std::cout << "level expected: " << expected << "\tlevel count: " << level << std::endl;
}



void	create_tree(void)
{
	ft::btree<int>	*root = NULL;
	
	std::cout << "insert " << 10 << std::endl;
	btree_insert_data(&root, new int(10), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 5 << std::endl;
	btree_insert_data(&root, new int(5), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 7 << std::endl;
	btree_insert_data(&root, new int(7), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 20 << std::endl;
	btree_insert_data(&root, new int(20), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 25 << std::endl;
	btree_insert_data(&root, new int(25), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 21 << std::endl;
	btree_insert_data(&root, new int(21), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 30 << std::endl;
	btree_insert_data(&root, new int(30), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 15 << std::endl;
	btree_insert_data(&root, new int(15), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 12 << std::endl;
	btree_insert_data(&root, new int(12), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---DELETE 21---\n" << std::endl;
	btree_delete(root, new int(21));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---DELETE 15---\n" << std::endl;
	btree_delete(root, new int(15));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---DELETE 20---\n" << std::endl;
	btree_delete(root, new int(20));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---RIGHT ROTATE---\n" << std::endl;
	btree_right_rotate(btree_search_node(root, new int(07), &compare));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---LEFT ROTATE---\n" << std::endl;
	btree_left_rotate(btree_search_node(root, new int(25), &compare));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	
	
	btree_delete_tree(root);
}

int testes_lais(void)
{
	std::cout << "\n---TESTE LAIS---\n" << std::endl;

	create_tree();

	return(0);
}
