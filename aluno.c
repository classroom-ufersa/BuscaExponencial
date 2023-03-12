#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

struct alunos
{
    char nome[81];
    int matricula;
    float documento;
};

Alunos *buscaAluno(char nome[81])
{
    Alunos *a = (Alunos *)malloc(sizeof(Alunos));
    strcpy(a->nome, nome);

    return a;
}

Alunos* criar_aluno(char nome[81], int matricula, float documento) {
    Alunos * aluno = (Alunos*) malloc(sizeof(Alunos));
    if(aluno == NULL)
    {
        printf("Erro na alocação da struct aluno!");
        exit(1);
    }
    aluno->nome = nome;
    aluno->matricula = matricula;
    aluno->documento = documento;
    return aluno;
}  

void libera(Alunos *aluno)
{
    free(aluno);
}