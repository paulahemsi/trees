/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes_lais.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:21:27 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/14 22:07:23 by phemsi-a         ###   ########.fr       */
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


	int dez = 10;
	int cinco = 5;
	int sete = 7;
	int vinte = 20;
	int vinte_e_cinco = 25;
	int vinte_e_um = 21;
	int trinta = 30;
	int quinze = 15;
	int doze = 12;
	
	btree_insert_data<int>(&root, &dez, &compare);
	print_level(root, 0);
	btree_insert_data<int>(&root, &cinco, &compare);
	print_level(root, 1);
	btree_insert_data<int>(&root, &sete, &compare);
	print_level(root, 2);
	btree_insert_data<int>(&root, &vinte, &compare);
	print_level(root, 2);
	btree_insert_data<int>(&root, &vinte_e_cinco, &compare);
	print_level(root, 2);
	btree_insert_data<int>(&root, &vinte_e_um, &compare);
	print_level(root, 3);
	btree_insert_data<int>(&root, &trinta, &compare);
	print_level(root, 3);
	btree_insert_data<int>(&root, &quinze, &compare);
	print_level(root, 3);
	btree_insert_data<int>(&root, &doze, &compare);
	print_level(root, 3);

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos);
	
}

int testes_lais(void)
{

	create_tree();

	return(0);
}
