// delete base:
// recebe um conteúdo
// acha o node respectivo
// se for folha, *apaga
// se não, acha pós, substitui conteúdo (novo delete base)


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
