
#include "tests.hpp"

template <typename T>
void swap_node_color(ft::btree<T> *node1, ft::btree<T> *node2)
{
	//mudar na struct para poder usar t_color aqui??
	int tmp;

	tmp = node1->color;
	node1->color = node2->color;
	node2->color = tmp;
}

// função para resolver DB(DB ou mãe?):
template <typename T>
void deal_db(ft::btree<T> *node)
{
	// se for root, só remove DB
	if (is_tree_root(node))
	{
		node->color = BLACK;
		return ;
	}
	// se irmã do DB for vermelha:
	// swapa cores da irmã e da mãe
	// rotaciona mãe para direção do DB btree_rotate_DB_dir(mãe)
	// função pra resolver DB (DB ou mãe?)
	ft::btree<T> *sibling = get_sibling(node);
	ft::btree<T> *parent = node->parent;
	if (sibling->color == RED)
	{
		swap_node_color(parent, sibling);
		if (is_left_child(parent, node))
			btree_left_rotate(parent);
		else
			btree_right_rotate(parent);
		deal_db(node);
	}
}

//achando a folha para deletar:
//é vermelha, deleta, return
//é preta, conteúdo NULL e cor DB:
template <typename T>
void check_delete_rules(ft::btree<T> *node)
{
	if (node->color == RED)
		return ;
	node->item = NULL;
	node->color = DB;
	deal_db(node);
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
