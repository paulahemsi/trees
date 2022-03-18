/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes_lais.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:21:27 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/17 22:06:52 by phemsi-a         ###   ########.fr       */
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
	
	btree_insert_data<int>(&root, new int(10), &compare);
	print_level(root, 0);
	btree_insert_data<int>(&root, new int(5), &compare);
	print_level(root, 1);
	btree_insert_data<int>(&root, new int(7), &compare);
	print_level(root, 2);
	btree_insert_data<int>(&root, new int(20), &compare);
	print_level(root, 2);
	btree_insert_data<int>(&root, new int(25), &compare);
	print_level(root, 2);
	btree_insert_data<int>(&root, new int(21), &compare);
	print_level(root, 3);
	btree_insert_data<int>(&root, new int(30), &compare);
	print_level(root, 3);
	btree_insert_data<int>(&root, new int(15), &compare);
	print_level(root, 3);
	btree_insert_data<int>(&root, new int(12), &compare);
	print_level(root, 3);

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos);
	std::cout << "\n---NODE AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_node_and_parent);
	btree_delete_tree(root);
}

int testes_lais(void)
{
	std::cout << "\n---TESTE LAIS---\n" << std::endl;

	create_tree();

	return(0);
}
