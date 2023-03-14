#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

int main(void)
{
    int i = 0, matricula, buscaMatricula, posicao = 0, tamanho = 8, op;
    char nome[81], buscaNome[81];
    float documento;

    Alunos *alunos[tamanho];

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

    ordenaLista(alunos, tamanho);

    printf("Voce deseja buscar o nome (1) ou a matricula (2) do aluno? ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("\nInforme o nome da aluno: ");
        scanf(" %[^\n]s", buscaNome);

        posicao = buscaExponencialNome(alunos, i, buscaNome);
        break;
    case 2:
        printf("Informe a matricula do aluno: ");
        scanf("%d", &buscaMatricula);

        posicao = buscaExponencial(alunos, i, buscaMatricula);
        break;
    default:
        break;
    }
    if (posicao == -1)
    {
        printf("Valor nao encontrado");
    }
    else
    {
        exibeAluno(alunos, posicao);
    }

    libera(alunos);
    fclose(aAluno);

    return 0;
}