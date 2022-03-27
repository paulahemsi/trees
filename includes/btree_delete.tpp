
#include "tests.hpp"

template <typename T>
bool is_leaf(ft::btree<T> *node)
{
	if (node->left || node->right)
		return (false);
	return (true);
}

template <typename T>
ft::btree<T> * find_successor(ft::btree<T> *node)
{
	if (!node->left)
		return (node);
	return (find_successor(node->left));
}

template <typename T>
ft::btree<T> * find_predecessor(ft::btree<T> *node)
{
	if (!node->right)
		return (node);
	return (find_predecessor(node->right));
}

template <typename T>
ft::btree<T> * find_neighbor(ft::btree<T> *node)
{
	if (node->right)
		return (find_successor(node->right));
	else
		return (find_predecessor(node->left));
}

template <typename T>
void replace_content(ft::btree<T> *node, ft::btree<T> *node_to_replace)
{
	node->item = node_to_replace->item;
}

template <typename T>
void delete_node(ft::btree<T> *node)
{
	if (is_left_child(node->parent, node))
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	delete node;
}

template <typename T>
void btree_delete_recursive(ft::btree<T> *node_to_delete)
{
	if (is_leaf(node_to_delete))
		return (delete_node(node_to_delete));
	ft::btree<T> * node_to_replace = find_neighbor(node_to_delete);
	replace_content(node_to_delete, node_to_replace);
	return (btree_delete_recursive(node_to_replace));
}

template <typename T>
T * btree_delete(ft::btree<T> *root, T data_ref)
{
	ft::btree<T> * node_to_delete = btree_search_node(root, data_ref, &compare);
	if (!node_to_delete)
		return (NULL);
	T * item_to_return = node_to_delete->item;
	btree_delete_recursive(node_to_delete);
	return (item_to_return);
}


//achando a folha para deletar:
//é vermelha, deleta, return
//é preta, conteúdo NULL e cor DB:

	// função para resolver DB(DB ou mãe?):
	// se for root, só remove DB

	// se irmã do DB for vermelha:
	// swapa cores da irmã e da mãe
	// rotaciona mãe para direção do DB btree_rotate_DB_dir(mãe)
	// função pra resolver DB (DB ou mãe?)

	// se irmã do DB for preta:
	// três possibilidades:

	// filhas da irmã pretas
	// elimina node DB
	// irmã vira Vermelha
	// Se mãe do DB for vermelha:
		// Vira preta
		// retorna
	// Se for preta
		// Vira DB
		// função para resolver DB
	
	// filha na direção do DB vermelha e filha na outra direção preta
		// swapa cores da irmã do DB com filha da irmã na mesma direção (vermelha)
		// rotaciona irmã na direção oposta a da DB
		// função para resolver DB
	
	// filha na direção oposta ao DB vermelha (a outra pouco importa)
		// swapa cores da mãe e irmã
		// passa preto para filha da irmã na direção oposta (vermelha)
		// remove node DB
		// rotaciona mãe na direção da DB
