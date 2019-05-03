#include "lista.h"

Lista::Lista()
{
	_head = new Node();
	_nome_curso = "";
	_vagas = -1;
	_total = 0;
	_corte = 0;
	_id = -1;
}
Lista::Lista(std::string nome_curso, int vagas)
{
	_head = new Node();
	_nome_curso = nome_curso;
	_vagas = vagas;
	_total = 0;
	_corte = 0;
	_id = -1;
}
/*Lista::~Lista()
{
	if(_head != nullptr)
		delete _head;
	std::cout << "Deleted lista " << this->GetNome() << std::endl;
}*/

// Função que insere o nó na lista dada - O(n)
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
			// Caso de empate
			else if(aux_prox->GetNota() == aluno->GetNota())
			{
				if(aluno->GetCurso1() == this->GetId() && aux_prox->GetCurso1() != this->GetId())
				{
					aux->SetProx(aluno);
					aluno->SetProx(aux_prox);
					_total++;
					break;
				}
			}
			aux = aux_prox;
			aux_prox = aux_prox->GetProx();

			// Inserindo menor nota do curso no final
			if(aux_prox == nullptr)
			{
				aux->SetProx(aluno);
				aluno->SetProx(nullptr);
				_total++;
			}
		}

	}
}

// Função que imprime os nós de cada lista - O(n)
void Lista::ImprimeLista()
{
	Node *aux = _head->GetProx();
	while(aux != nullptr)
	{
		std::cout <<  aux->GetNome() << " " << aux->GetNota() << std::endl;
		aux = aux->GetProx();
	}
}

// Funções para definir valores de atributos privados - O(1)
std::string Lista::GetNome() {return _nome_curso;}
int Lista::GetVagas() {return _vagas;}
int Lista::GetSize() {return _total;}
float Lista::GetCorte() {return _corte;}
Node* Lista::GetHead() {return _head;}
int Lista::GetId() {return _id;}

// Funções para retornar valores de atributos privados - O(1)
void Lista::SetHead(Node *head) {_head = head;}
void Lista::SetNome(std::string nome_curso) {_nome_curso = nome_curso;}
void Lista::SetVagas(int vagas) {_vagas = vagas;}
void Lista::SetCorte(float corte) {_corte = corte;}
void Lista::SetId(int id) {_id = id;}