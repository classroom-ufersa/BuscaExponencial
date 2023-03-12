typedef struct alunos Alunos;

Alunos *criaAluno(char nome[81], int matricula, float documento);

int buscaExponencial(Alunos ** alunos, int tamanho, int valor);

void libera(Alunos *aluno);