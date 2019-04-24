#include "lista.h"

Lista::Lista()
{
	_head = nullptr;
	_nome_curso = "";
	_vagas = -1;
	_total = 0;
}
Lista::Lista(std::string nome_curso, int vagas)
{
	_head = new Node();
	_nome_curso = nome_curso;
	_vagas = vagas;
	_total = 0;
}
Lista::~Lista()
{
	if(_head != nullptr)
		delete _head;
}

std::string Lista::GetNome()
{
	return _nome_curso;
}
int Lista::GetVagas()
{
	return _vagas;
}

void Lista::InsereNode(Node *n)
{
	if(this->_head->GetProx() == nullptr)
	{
		this->_head->SetProx(n);
		_total++;
	}
	else
	{
		Node *aux = new Node();
		Node *aux_prox = new Node();
		aux = this->_head;
		aux_prox = aux->GetProx();

		while(aux_prox != nullptr)
		{
			if(aux_prox->GetNota() < n->GetNota())
			{
				aux->SetProx(n);
				n->SetProx(aux_prox);
				_total++;
				break;
			}
			
			aux = aux_prox;
			aux_prox = aux_prox->GetProx();

			if(aux_prox == nullptr)
			{
				aux->SetProx(n);
				_total++;
			}
		}
	}
}

void Lista::ImprimeLista()
{
	Node *aux = _head->GetProx();
	std::cout << "Curso: " << _nome_curso << " | Vagas: " << _vagas << " | Inscritos: "<< _total << "\n";
	std::cout << "--------------------\n";
	while(aux != nullptr)
	{
		std::cout << "Aluno: " << aux->GetNome() << "  Nota: " << aux->GetNota() << "\n";
		aux = aux->GetProx();
	}
	std::cout << "--------------------\n";
}

int Lista::GetSize()
{
	return _total;
}