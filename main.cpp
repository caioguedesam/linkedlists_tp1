#include "lista.h"

int main()
{

	int num_cursos, num_alunos;
	std::cin >> num_cursos >> num_alunos;

	Lista *cursos_arr = new Lista[num_cursos];
	int i;
	for(i = 0; i < num_cursos; i++)
	{
		std::string nome_curso;
		int vagas;
		std::cin.ignore();
		getline(std::cin, nome_curso, '\n');
		std::cin >> vagas;

		cursos_arr[i] = Lista(nome_curso, vagas);
	}
	
	Node *aluno_temp1 = new Node();
	Node *aluno_temp2 = new Node();

	for(i = 0; i < num_alunos; i++)
	{
		std::string nome_aluno;
		float nota;
		int curso1, curso2;

		std::cin.ignore();
		getline(std::cin, nome_aluno, '\n');
		std::cin >> nota >> curso1 >> curso2;

		aluno_temp1 = new Node(nome_aluno, nota, curso1, curso2);
		aluno_temp2 = new Node(nome_aluno, nota, curso1, curso2);

		cursos_arr[curso1].InsereNode(aluno_temp1);
		if(curso1 != curso2)
			cursos_arr[curso2].InsereNode(aluno_temp2);

	}

	for(i = 0; i < num_cursos; i++)
	{
		cursos_arr[i].ImprimeLista();
	}

	/*for(i = 0; i < num_cursos; i++)
		std::cout << "Curso " << i+1 << ": " << cursos_arr[i].GetNome() << "\n";

	/*Lista curso1 = Lista("Mineracao", 2);
	Lista curso2 = Lista("Engenharia", 3);

	Node *aluno1 = new Node("Olaf", 100, 0, 1);
	Node *aluno2 = new Node("Anna", 102, 0, 1);

	curso1.InsereNode(aluno1);
	curso2.InsereNode(aluno1);
	curso1.InsereNode(aluno2);
	curso2.InsereNode(aluno2);
	curso1.ImprimeLista();
	curso2.ImprimeLista();*/
	
	

	return 0;
}