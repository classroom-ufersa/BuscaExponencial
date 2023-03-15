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

    do
    {
        printf("1 - Buscar aluno por nome\n2 - Buscar aluno por matricula\n3 - exibir alunos\n4 - Sair.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nInforme o nome da aluno: ");
            scanf(" %[^\n]s", buscaNome);
            ordenaLista(alunos, tamanho);
            posicao = buscaExponencialNome(alunos, i, buscaNome);
            posicao == -1 ? printf("Valor nao encontrado") : exibeAluno(alunos, posicao);
            break;
        case 2:
            printf("Informe a matricula do aluno: ");
            scanf("%d", &buscaMatricula);

            posicao = buscaExponencial(alunos, i, buscaMatricula);
            posicao == -1 ? printf("Valor nao encontrado") : exibeAluno(alunos, posicao);
            break;
        case 3:
            printf("Exibindo alunos...\n");
            int n;
            ordenaLista(alunos, tamanho);
            for (n = 0; n < tamanho; n++)
            {
                exibeAluno(alunos, n);
            }
            break;
        case 4:
            printf("Saindo do programa...\n");
            exit(1);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 854158);

    libera(alunos);
    fclose(aAluno);

    return 0;
}