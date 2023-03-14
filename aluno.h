typedef struct alunos Alunos;

Alunos *criaAluno(char nome[81], int matricula, float documento);

void ordenaLista(Alunos ** alunos, int tamanho);

int buscaExponencial(Alunos **alunos, int tamanho, int valor);

int buscaExponencialNome(Alunos **alunos, int tamanho, char nome[81]);

void exibeAluno(Alunos **aluno, int posicao);

void libera(Alunos **aluno);