
#include "tests.hpp"

template <typename T>
void deal_double_black(ft::btree<T> *double_black_node);

template <typename T>
ft::btree<T> * get_opposite_niece(ft::btree<T> *node, ft::btree<T> *sibling)
{
	if (is_left_child(node->parent, node))
		return (sibling->right);
	return (sibling->left);
}

template <typename T>
ft::btree<T> * get_same_direction_niece(ft::btree<T> *node, ft::btree<T> *sibling)
{
	if (is_left_child(node->parent, node))
		return (sibling->left);
	return (sibling->right);
}

template <typename T>
void do_opposite_rotation(ft::btree<T> *node_to_compare, ft::btree<T> *node_to_rotate)
{
	if (is_left_child(node_to_compare->parent, node_to_compare))
		btree_right_rotate(node_to_rotate);
	else
		btree_left_rotate(node_to_rotate);
}

template <typename T>
void do_same_side_rotation(ft::btree<T> *node_to_compare, ft::btree<T> *node_to_rotate)
{
	if (is_left_child(node_to_compare->parent, node_to_compare))
		btree_left_rotate(node_to_rotate);
	else
		btree_right_rotate(node_to_rotate);
}

template <typename T>
bool is_black_or_null(ft::btree<T> *node)
{
	if (node == NULL)
		return (true);
	if (node->color == BLACK)
		return (true);
	return (false);
}

template <typename T>
bool is_red_node(ft::btree<T> *node)
{
	return (!is_black_or_null(node));
}

template <typename T>
void	remove_double_black(ft::btree<T> *node)
{
	node->color = BLACK;
}

template <typename T>
void swap_node_color(ft::btree<T> *node1, ft::btree<T> *node2)
{
	ft::t_color tmp;

	tmp = node1->color;
	node1->color = node2->color;
	node2->color = tmp;
}

template <typename T>
void	black_sibling_case(ft::btree<T> *double_black_node)
{
	ft::btree<T> *sibling = get_sibling(double_black_node);
	ft::btree<T> *parent = double_black_node->parent;
	
	if (is_red_node(get_opposite_niece(double_black_node, sibling)))
	{
		swap_node_color(parent, sibling);
		get_opposite_niece(double_black_node, sibling)->color = BLACK;
		do_same_side_rotation(double_black_node, parent);
		remove_double_black(double_black_node);
	}
	// filhas da irmã pretas
	else if (is_black_or_null(get_same_direction_niece(double_black_node, sibling)))
	{
		double_black_node->color = BLACK;
		sibling->color = RED;
		parent->color++;
		if (parent->color == DOUBLE_BLACK)
			deal_double_black(parent);
	}
	// filha na direção do DB vermelha e filha na outra direção preta
	else
	{
		swap_node_color(sibling, get_same_direction_niece(double_black_node, sibling));
		do_opposite_rotation(double_black_node, sibling);
		deal_double_black(double_black_node);
	}
}

// swapa cores da irmã e da mãe
// rotaciona mãe para direção do DB btree_rotate_DB_dir(mãe)
// função pra resolver DB (DB ou mãe?)
template <typename T>
void	red_sibling_case(ft::btree<T> *double_black_node)
{
	ft::btree<T> *sibling = get_sibling(double_black_node);
	ft::btree<T> *parent = double_black_node->parent;
	
	swap_node_color(parent, sibling);
	if (is_left_child(parent, double_black_node))
		btree_left_rotate(parent);
	else
		btree_right_rotate(parent);
	deal_double_black(double_black_node);
}

// função para resolver DB(DB ou mãe?):
template <typename T>
void deal_double_black(ft::btree<T> *double_black_node)
{
	if (is_tree_root(double_black_node))
		return (remove_double_black(double_black_node));
	if (sibling_is_red(double_black_node))
		red_sibling_case(double_black_node);
	else	
		black_sibling_case(double_black_node);
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
	node->color = DOUBLE_BLACK;
	deal_double_black(node);
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
