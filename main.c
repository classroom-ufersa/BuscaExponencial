#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#define MAX_ALUNOS 30
int main(void)
{
    int i = 0, matricula, buscaMatricula, posicao = 0, op;
    char nome[81], buscaNome[81];
    float documento;

    Alunos *alunos[MAX_ALUNOS];

    FILE *aAluno = fopen("../alunos/aluno.txt", "r");
    if (aAluno == NULL)
    {
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }

    while (!(feof(aAluno)))
    {
        fscanf(aAluno, "%s %d %f", nome, &matricula, &documento);
        alunos[i] = capturaAluno(nome, matricula, documento);
        i++;
    }

    do
    {
        printf("1 - Escrever Aluno.\n2 - Buscar Aluno por Nome.\n3 - Buscar Aluno por Matricula.\n4 - Exibir Alunos.\n5 - Sair.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Escrevendo um aluno...\n");
            escreveAluno();
            break;
        case 2:
            printf("\nInforme o nome da aluno: ");
            scanf(" %[^\n]s", buscaNome);
            ordenaListaNome(alunos, MAX_ALUNOS);
            posicao = buscaExponencialNome(alunos, MAX_ALUNOS, buscaNome);
            posicao == -1 ? printf("Valor nao encontrado") : exibeAluno(alunos, posicao);
            break;
        case 3:
            printf("Informe a matricula do aluno: ");
            scanf("%d", &buscaMatricula);
            ordenaListaMatricula(alunos, i);
            posicao = buscaExponencial(alunos, i, buscaMatricula);
            posicao == -1 ? "Valor nao encontrado" : exibeAluno(alunos, posicao);
            break;
        case 4:
            printf("Exibindo alunos...\n");
            int n;
            ordenaListaNome(alunos, i);
            for (n = 0; n < i; n++)
            {
                if (alunos[n] == NULL)
                {
                    break;
                }
                exibeAluno(alunos, n);
            }
            break;
        case 5:
            printf("Saindo do programa...\n");
            exit(1);
            break;
        case 6:
            printf("Digite a matricula do aluno que deseja excluir:");
            scanf("%d", &buscaMatricula);
            posicao = buscaExponencial(alunos, i, buscaMatricula);
            excluirAluno(alunos, posicao);
            break;
        }
    } while (op != 5);

    libera(alunos, i);
    fclose(aAluno);

    return 0;
}