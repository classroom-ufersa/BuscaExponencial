typedef struct alunos Alunos;

Alunos *criaAluno(char nome[81], int matricula, float documento);

void * exibirAluno(Alunos * alunos);

int buscaExponencial(Alunos ** alunos, int tamanho, int valor);

void libera(Alunos *aluno);