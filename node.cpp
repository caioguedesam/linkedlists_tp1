#include "node.h"

Node::Node()
{
	_nome_aluno = "head";
	_nota = -1;
	_curso1 = -1;
	_curso2 = -1;
	_aprovado = false;
	_prox = nullptr;
}
Node::Node(std::string nome_aluno, float nota, int curso1, int curso2)
{
	_nome_aluno = nome_aluno;
	_nota = nota;
	_curso1 = curso1;
	_curso2 = curso2;
	_aprovado = false;
	_prox = nullptr;
}

Node::~Node()
{
	if(_prox != nullptr)
		delete _prox;
}

void Node::SetProx(Node *prox)
{
	_prox = prox;
}

std::string Node::GetNome()
{
	return _nome_aluno;
}
float Node::GetNota()
{
	return _nota;
}
int Node::GetCurso1()
{
	return _curso1;
}
int Node::GetCurso2()
{
	return _curso2;
}
Node* Node::GetProx()
{
	return _prox;
}
bool Node::Status()
{
	return _aprovado;
}
void Node::SetStatus(bool aprovado)
{
	_aprovado = aprovado;
}