#ifndef LISTA_H_TP1
#define LISTA_H_TP1

#include "node.h"

class Lista {
private:
	Node *_head;
	std::string _nome_curso;
	int _vagas;
	int _total;
public:
	Lista();
	Lista(std::string nome_curso, int vagas);
	~Lista();

	std::string GetNome();
	int GetVagas();
	int GetSize();
	Node *GetHead();

	void SetNome(std::string nome_curso);
	void SetVagas(int vagas);
	void SetHead(Node *head);

	void InsereNode(Node *n);
	void ImprimeLista();

	void Resultado();

};

#endif