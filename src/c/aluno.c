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

Alunos *capturaAluno(char nome[81], int matricula, float documento)
{
    Alunos *a = (Alunos *)malloc(sizeof(Alunos));
    strcpy(a->nome, nome);
    a->matricula = matricula;
    a->documento = documento;

    return a;
}

void escreveAluno()
{
    char nome[81];
    int matricula;
    float documento;

    FILE *f = fopen("../service/alunos.txt", "a");
    if (f == NULL)
    {
        printf("Nao foi possivel criar o aluno!\n");
        exit(1);
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o documento do aluno: ");
    scanf("%f", &documento);

    fprintf(f, "%s\t%d\t%.0f\n", nome, matricula, documento);
    fclose(f);
}

void ordenaLista(Alunos **alunos, int tamanho, int opcao)
{
    int i, j;

    FILE *f = fopen("../service/alunos.txt", "w");
    if (f == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    Alunos *temp = (Alunos *)malloc(sizeof(Alunos));
    if (temp == NULL)
    {
        printf("Erro na alocação de memoria da variavel temp!\n");
        exit(1);
    }

    if (opcao == 2 || opcao == 4)
    {
        for (i = 0; i < tamanho; i++)
        {
            for (j = 0; j < tamanho - 1 - i; j++)
            {
                if (strcmp(alunos[j]->nome, alunos[j + 1]->nome) > 0)
                {
                    temp = alunos[j];
                    alunos[j] = alunos[j + 1];
                    alunos[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < tamanho; i++)
        {
            for (j = 0; j < tamanho - 1 - i; j++)
            {
                if (alunos[j]->matricula > alunos[j + 1]->matricula)
                {
                    temp = alunos[j];
                    alunos[j] = alunos[j + 1];
                    alunos[j + 1] = temp;
                }
            }
        }
    }

    i = 0;
    while (i < tamanho)
    {
        fprintf(f, "%s\t%d\t%.0f\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        i++;
    }

    fclose(f);
}

int buscaExponencial(Alunos **alunos, int mat, char nome[81], int tamanho, int opcao)
{
    int i = 1;
    if (opcao == 2)
    {
        if (alunos[0]->nome == nome)
        {
            return 0;
        }
        while (i < tamanho && strcmp(alunos[i]->nome, nome) <= 0)
        {
            i *= 2;
        }
        int j;
        for (j = i / 2; j < i; j++)
        {
            if ((strcmp(alunos[j]->nome, nome) == 0))
            {
                return j;
            }
        }
        return -1;
    }
    else if (opcao == 3)
    {
        i = 1;
        while (i < tamanho && alunos[i]->matricula <= mat)
        {
            i *= 2;
        }
        int j;
        for (j = i / 2; j < i; j++)
        {
            if (alunos[j]->matricula == mat)
            {
                return j;
            }
        }
        return -1;
    }
}

void exibeAluno(Alunos **aluno, int posicao)
{
    if (aluno[0]->nome == "")
    {
        printf("Nao ha alunos cadastrados.");
    }
    else
    {
        printf("Nome do aluno: %s || Matricula: %d || Documento: %.0f\n", aluno[posicao]->nome, aluno[posicao]->matricula, aluno[posicao]->documento);
    }
}

void libera(Alunos **aluno, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        free(aluno[i]);
    }
    free(aluno);
}