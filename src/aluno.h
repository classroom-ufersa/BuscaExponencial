typedef struct alunos Alunos;

Alunos *capturaAluno(char nome[81], int matricula, float documento);

void escreveAluno();

void ordenaLista(Alunos **alunos, int tamanho, int opcao);

int buscaExponencial(Alunos **alunos, int mat, char nome[81], int tamanho, int opcao);

int buscaBinaria(Alunos **alunos, int index, int posicao, int mat, char nome[81], int opcao);

void exibeAluno(Alunos **aluno, int posicao);

void libera(Alunos **aluno, int tamanho);