#include "lista.h"
#include <iomanip>

// Funções utilizadas no main (definidas posteriormente):
// Função que cria e retorna lista com todos os alunos inscritos
Lista GetAlunos(int num_alunos);

// Função que cria e retorna listas de classificados e
// de espera para todos os cursos
Lista** GetListasClassificados(int num_cursos);

// Função que calcula e imprime os resultados do "SISU"
void Resultados(Lista alunos, Lista *cursos_arr, Lista *espera_arr, int num_cursos);


int main()
{
	// Entrando numero de cursos e de alunos
	int num_cursos, num_alunos;
	std::cin >> num_cursos >> num_alunos;

	// Armazenando as listas de classificados e de espera em arrays
	Lista **cursos_e_esperas = GetListasClassificados(num_cursos);
	// Todas as listas de classificados:
	Lista *cursos_arr = cursos_e_esperas[0];
	// Todas as listas de espera:
	Lista *espera_arr = cursos_e_esperas[1];

	// Armazenando todos os alunos em ordem de nota
	Lista alunos = GetAlunos(num_alunos);

	Resultados(alunos, cursos_arr, espera_arr, num_cursos);
	
	return 0;
}

Lista GetAlunos(int num_alunos)
{

	Lista alunos = Lista();
	int i;
	for(i = 0; i < num_alunos; i++)
	{
		std::string nome_aluno;
		float nota;
		int curso1, curso2;

		std::cin.ignore();
		getline(std::cin, nome_aluno, '\n');
		std::cin >> nota >> curso1 >> curso2;

		Node *aluno = new Node(nome_aluno, nota, curso1, curso2);

		alunos.InsereNode(aluno);
	}

	return alunos;
}

Lista** GetListasClassificados(int num_cursos)
{
	int i;

	Lista **return_arr = new Lista*[2];
	Lista *cursos_arr = new Lista[num_cursos];
	Lista *espera_arr = new Lista[num_cursos];

	for(i = 0; i < num_cursos; i++)
	{
		std::string nome_curso;
		int vagas;

		std::cin.ignore();
		getline(std::cin, nome_curso, '\n');
		std::cin >> vagas;

		cursos_arr[i].SetHead(new Node());
		cursos_arr[i].SetNome(nome_curso);
		cursos_arr[i].SetVagas(vagas);
		cursos_arr[i].SetId(i);

		espera_arr[i].SetHead(new Node());
		espera_arr[i].SetNome(nome_curso);
		espera_arr[i].SetVagas(vagas);
		espera_arr[i].SetId(i);
		
	}

	return_arr[0] = cursos_arr;
	return_arr[1] = espera_arr;

	return return_arr;
}

void Resultados(Lista alunos, Lista *cursos_arr, Lista *espera_arr, int num_cursos)
{
	// Fazendo nós auxiliares
	Node *aux = alunos.GetHead()->GetProx();

	// Iterando sobre os alunos e verificando as opções
	while(aux != nullptr)
	{
		if(cursos_arr[aux->GetCurso1()].GetSize() < cursos_arr[aux->GetCurso1()].GetVagas())
		{
			cursos_arr[aux->GetCurso1()].InsereNode(aux);
			// Colocando nota de corte do curso
			if(cursos_arr[aux->GetCurso1()].GetSize() == cursos_arr[aux->GetCurso1()].GetVagas())
			{
				cursos_arr[aux->GetCurso1()].SetCorte(aux->GetNota());
			}
				
		}
		else
		{
			espera_arr[aux->GetCurso1()].InsereNode(aux);
			if(cursos_arr[aux->GetCurso2()].GetSize() < cursos_arr[aux->GetCurso2()].GetVagas())
			{
				cursos_arr[aux->GetCurso2()].InsereNode(aux);
				// Colocando nota de corte do curso
				if(cursos_arr[aux->GetCurso2()].GetSize() == cursos_arr[aux->GetCurso2()].GetVagas())
				{
					cursos_arr[aux->GetCurso2()].SetCorte(aux->GetNota());
				}

			}
			else
			{
				espera_arr[aux->GetCurso2()].InsereNode(aux);
			}
		}

		// Indo para o aluno seguinte
		aux = aux->GetProx();
	}

	// Imprimindo todos os cursos com lista de classificados e lista de espera:
	int i;
	// Configurações de saída de decimais
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for(i = 0; i < num_cursos; i++)
	{
		std::cout << cursos_arr[i].GetNome() << " " << cursos_arr[i].GetCorte() << std::endl;
		std::cout << "Classificados" << std::endl;
		cursos_arr[i].ImprimeLista();
		std::cout << "Lista de Espera" << std::endl;
		espera_arr[i].ImprimeLista();
		std::cout << std::endl;
	}
}