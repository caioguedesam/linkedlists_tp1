#ifndef LISTA_H_TP1
#define LISTA_H_TP1

#include "node.h"

class Lista {
private:
	Node *_head;
	std::string _nome_curso;
	int _vagas;
	int _total;
	float _corte;
	int _id;
public:
	Lista();
	Lista(std::string nome_curso, int vagas);
	//~Lista();

	std::string GetNome();
	int GetVagas();
	int GetSize();
	float GetCorte();
	Node *GetHead();
	int GetId();

	void SetNome(std::string nome_curso);
	void SetVagas(int vagas);
	void SetCorte(float corte);
	void SetHead(Node *head);
	void SetId(int id);

	void InsereNode(Node *n);
	void ImprimeLista();

	void Resultado();

};

#endif