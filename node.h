#ifndef NODE_H_TP1
#define NODE_H_TP1

#include <iostream>
#include <string>

class Node {
private:
	std::string _nome_aluno;
	float _nota;
	int _curso1, _curso2;
	bool _aprovado;
	Node *_prox;
public:
	Node();
	Node(std::string nome_aluno, float nota, int curso1, int curso2);
	//~Node();

	void SetProx(Node *prox);
	void SetStatus(bool aprovado);
	
	std::string GetNome();
	float GetNota();
	int GetCurso1();
	int GetCurso2();
	Node *GetProx();
	bool Status();

};

#endif