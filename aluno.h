typedef struct alunos Alunos;

Alunos *capturaAluno(char nome[81], int matricula, float documento);

void escreveAluno();

void ordenaListaNome(Alunos **alunos, int tamanho);

void ordenaListaMatricula(Alunos **alunos, int tamanho);

int buscaExponencial(Alunos **alunos, int mat, char nome[81], int tamanho, int opcao);

void exibeAluno(Alunos **aluno, int posicao);

void libera(Alunos **aluno, int tamanho);