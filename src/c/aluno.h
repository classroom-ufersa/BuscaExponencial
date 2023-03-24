typedef struct alunos Alunos;

Alunos *capturaAluno(char nome[81], int matricula, float documento);

void escreveAluno();

void ordenaListaNome(Alunos **alunos, int tamanho);

void ordenaListaMatricula(Alunos **alunos, int tamanho);

int buscaExponencialNome(Alunos **alunos, char nome[81], int tamanho);

int buscaExponencialMatricula(Alunos **alunos, int mat, int tamanho);

int buscaBinariaNome(Alunos **alunos, int index, int posicao, char nome[81]);

int buscaBinariaMatricula(Alunos **alunos, int index, int posicao, int mat);

void exibeAluno(Alunos **aluno, int posicao);

void libera(Alunos **aluno, int tamanho);