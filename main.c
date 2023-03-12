#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

Alunos *alunos[4];

int main(void)
{
    char nome[81];
    int matricula;
    float documento;
    int i = 0;

    FILE *aAluno = fopen("../alunos/aluno.txt", "r");
    if (aAluno == NULL)
    {
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }

    while (!(feof(aAluno)))
    {
        fscanf(aAluno, "%s %d %f", nome, &matricula, &documento);
        alunos[i] = criaAluno(nome, matricula, documento);
        i++;
    }

    int posicao = buscaExponencial(alunos, 4, 4);
    if (posicao == -1)
    {
        printf("Valor nao encontrado");
    }
    else
    {
        printf("Valor encontrado na posicao %d", posicao);
    }

    libera(alunos);
    fclose(aAluno);

    return 0;
}