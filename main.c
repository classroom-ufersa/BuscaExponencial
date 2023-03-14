#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

Alunos *alunos[4];

int main(void)
{
    char nome[81];
    int matricula, inputMatricula;
    float documento;
    int i = 0, posicao = 0;

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

    //printf("Informe o numero da matricula: ");
    //scanf("%d", &inputMatricula);

    //posicao = buscaExponencial(alunos, 4, inputMatricula);
    posicao = buscaExponencialNome(alunos, 4, "heitor");

    if (posicao == -1)
    {
        printf("Valor nao encontrado");
    }
    else
    {
        printf("%d", posicao);
    }

    libera(alunos);
    fclose(aAluno);

    return 0;
}