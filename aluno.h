typedef struct alunos Alunos;

Alunos *criaAluno(char nome[81], int matricula, float documento);

int buscaExponencial(Alunos **alunos, int tamanho, int valor);

void exibeAluno(Alunos **aluno, int posicao);

void libera(Alunos **aluno);