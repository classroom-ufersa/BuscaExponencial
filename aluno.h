typedef struct alunos Alunos;

Alunos *capturaAluno(char nome[81], int matricula, float documento);

void escreveAluno();

void ordenaLista(Alunos **alunos, int tamanho, int opcao);

int buscaExponencial(Alunos **alunos, int tamanho, int valor);

int buscaExponencialNome(Alunos **alunos, int tamanho, char nome[81]);

void exibeAluno(Alunos **aluno, int posicao);

void libera(Alunos **aluno, int tamanho);