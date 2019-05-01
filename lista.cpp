#include "lista.h"

Lista::Lista()
{
	_head = nullptr;
	_nome_curso = "";
	_vagas = -1;
	_total = 0;
	_corte = 0;
}
Lista::Lista(std::string nome_curso, int vagas)
{
	_head = new Node();
	_nome_curso = nome_curso;
	_vagas = vagas;
	_total = 0;
	_corte = 0;
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
	Node *aluno = new Node(n->GetNome(), n->GetNota(), n->GetCurso1(), n->GetCurso2());
	// Inserir primeiro elemento
	if(_head->GetProx() == nullptr)
	{
		_head->SetProx(aluno);
		aluno->SetProx(nullptr);
		_total++;
	}
	// Inserir além do primeiro elemento
	else
	{
		
		Node *aux = this->_head;
		Node *aux_prox = aux->GetProx();

		while(aux_prox != nullptr)
		{
			// Inserindo nota maior do que uma que já existe
			if(aux_prox->GetNota() < aluno->GetNota())
			{
				aux->SetProx(aluno);
				aluno->SetProx(aux_prox);
				_total++;
				break;
			}
			aux = aux_prox;
			aux_prox = aux_prox->GetProx();

			// Inserindo menor nota do curso
			if(aux_prox == nullptr)
			{
				aux->SetProx(aluno);
				aluno->SetProx(nullptr);
				_total++;
			}
		}

	}
}
//Função para inserir nós sem importar a ordem da nota
void Lista::InsereNodeDesord(Node *n)
{
	Node *aluno = new Node(n->GetNome(), n->GetNota(), n->GetCurso1(), n->GetCurso2());

	// Inserir primeiro elemento
	if(_head->GetProx() == nullptr)
	{
		_head->SetProx(aluno);
		aluno->SetProx(nullptr);
		_total++;
	}
	else
	{
		Node *aux = this->_head;
		Node *aux_prox = aux->GetProx();

		while(aux_prox != nullptr)
		{
			aux = aux_prox;
			aux_prox = aux_prox->GetProx();
		}

		aux->SetProx(aluno);
		aluno->SetProx(nullptr);
		_total++;
	}
}

void Lista::ImprimeLista()
{
	Node *aux = _head->GetProx();
	/*std::cout << "Curso: " << _nome_curso << " | Vagas: " << _vagas << " | Inscritos: "<< _total << "\n";
	std::cout << "--------------------\n";*/
	while(aux != nullptr)
	{
		std::cout <<  aux->GetNome() << " " << aux->GetNota() << std::endl;
		aux = aux->GetProx();
	}
}

int Lista::GetSize()
{
	return _total;
}
int Lista::GetCorte()
{
	return _corte;
}

Node* Lista::GetHead()
{
	return _head;
}

void Lista::SetHead(Node *head)
{
	_head = head;
}
void Lista::SetNome(std::string nome_curso)
{
	_nome_curso = nome_curso;
}
void Lista::SetVagas(int vagas)
{
	_vagas = vagas;
}
void Lista::SetCorte(int corte)
{
	_corte = corte;
}