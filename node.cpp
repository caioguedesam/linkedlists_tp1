#include "node.h"

Node::Node()
{
	_nome_aluno = "head";
	_nota = -1;
	_curso1 = -1;
	_curso2 = -1;
	_prox = nullptr;
}
Node::Node(std::string nome_aluno, float nota, int curso1, int curso2)
{
	_nome_aluno = nome_aluno;
	_nota = nota;
	_curso1 = curso1;
	_curso2 = curso2;
	_prox = nullptr;
}

/*Node::~Node()
{
	if(_prox != nullptr)
		delete _prox;
	std::cout << "Deleted aluno " << this->GetNome() << std::endl;
}*/

// Função para definir o valor do ponteiro para nó seguinte - O(1)
void Node::SetProx(Node *prox) {_prox = prox;}

// Funções para retornar valores de atributos privados - O(1)
std::string Node::GetNome() {return _nome_aluno;}
float Node::GetNota() {return _nota;}
int Node::GetCurso1() {return _curso1;}
int Node::GetCurso2() {return _curso2;}
Node* Node::GetProx() {return _prox;}