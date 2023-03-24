#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void ordenaListaNome(Alunos **alunos, int tamanho)
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

    i = 0;
    while (i < tamanho)
    {
        fprintf(f, "%s\t%d\t%.0f\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        i++;
    }

    fclose(f);
}

void ordenaListaMatricula(Alunos **alunos, int tamanho)
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

    i = 0;
    while (i < tamanho)
    {
        fprintf(f, "%s\t%d\t%.0f\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        i++;
    }

    fclose(f);
}

int buscaExponencialNome(Alunos **alunos, char nome[81], int tamanho)
{
    int i = 1;

    if (strcmp(alunos[0]->nome, nome) == 0)
    {
        return 0;
    }
    while (i < tamanho && strcmp(alunos[i]->nome, nome) <= 0) // n
    {
        i *= 2;
    }
    return buscaBinariaNome(alunos, i / 2, fmin(i, tamanho - 1), nome);
}

int buscaExponencialMatricula(Alunos **alunos, int mat, int tamanho)
{
    if (alunos[0]->matricula == mat)
    {
        return 0;
    }

    int i = 1;
    while (i < tamanho && alunos[i]->matricula <= mat)
    {
        i *= 2;
    }
    return buscaBinariaMatricula(alunos, i / 2, fmin(i, tamanho - 1), mat);
}

int buscaBinariaNome(Alunos **alunos, int inicio, int fim, char nome[81])
{
    if (fim >= inicio)
    {
        int mid = inicio + (fim - inicio) / 2;

        if (strcmp(alunos[mid]->nome, nome) == 0)
        {
            return mid;
        }
        if (strcmp(alunos[mid]->nome, nome) > 0)
        {
            return buscaBinariaNome(alunos, inicio, mid - 1, nome);
        }

        return buscaBinariaNome(alunos, mid + 1, fim, nome);
    }
    return -1;
};

int buscaBinariaMatricula(Alunos **alunos, int inicio, int fim, int mat)
{

    if (fim >= inicio)
    {
        int mid = inicio + (fim - inicio) / 2;

        if (alunos[mid]->matricula == mat)
        {
            return mid;
        }
        if (alunos[mid]->matricula > mat)
        {
            return buscaBinariaMatricula(alunos, inicio, mid - 1, mat);
        }

        return buscaBinariaMatricula(alunos, mid + 1, fim, mat);
    }
    return -1;
};

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