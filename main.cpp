#include "lista.h"

int main()
{
	// Entrando numero de cursos e de alunos
	int num_cursos, num_alunos, i;
	std::cin >> num_cursos >> num_alunos;

	// Array de listas para armazenar todos os cursos
	Lista *cursos_arr = new Lista[num_cursos];

	// Criando cursos e armazenando em array de cursos
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
		
	}

	// Criando alunos e armazenando nas listas no array
	for(i = 0; i < num_alunos; i++)
	{
		std::string nome_aluno;
		float nota;
		int curso1, curso2;

		std::cin.ignore();
		getline(std::cin, nome_aluno, '\n');
		std::cin >> nota >> curso1 >> curso2;

		cursos_arr[curso1].InsereNode(new Node(nome_aluno, nota, curso1, curso2));
		if(curso1 != curso2)
			cursos_arr[curso2].InsereNode(new Node(nome_aluno, nota, curso1, curso2));
	}

	for(i = 0; i < num_cursos; i++)
		cursos_arr[i].ImprimeLista();


	return 0;
}