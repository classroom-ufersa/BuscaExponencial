#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

Alunos *alunos[3];

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
    fclose(aAluno);
    ordenaLista(alunos, 3);

    char nomeProcurado[81];
    printf("Informe o nome da aluno: ");
    scanf(" %[^\n]s", nomeProcurado);

    //posicao = buscaExponencial(alunos, 4, inputMatricula);
    posicao = buscaExponencialNome(alunos, i, nomeProcurado);

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