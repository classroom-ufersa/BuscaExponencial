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

    FILE *f = fopen("../alunos/aluno.txt", "a");
    if (f == NULL)
    {
        printf("Não foi possivel criar o aluno!\n");
        exit(1);
    }

    printf("Digite o nome do aluno:\n");
    scanf(" %[^\n]s", nome);
    printf("Digite a matricula do aluno:\n");
    scanf("%d", &matricula);
    printf("Digite o documento do aluno:\n");
    scanf("%f", &documento);

    fprintf(f, "%s %d %.0f\n", nome, matricula, documento);
    fclose(f);
}

void excluirAluno(Alunos **alunos, int posicao)
{
    alunos[posicao] = NULL;
}

void ordenaListaNome(Alunos **alunos, int tamanho)
{
    char temp[81];
    int i, j, matriculaT1, matriculaT2;
    float documentoT1, documentoT2;
    FILE *f = fopen("../alunos/aluno.txt", "w");
    if (f == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho - 1 - i; j++)
        {
            if (strcmp(alunos[j]->nome, alunos[j + 1]->nome) > 0)
            {
                matriculaT1 = alunos[j]->matricula;
                documentoT1 = alunos[j]->documento;
                matriculaT2 = alunos[j + 1]->matricula;
                documentoT2 = alunos[j + 1]->documento;

                strcpy(temp, alunos[j]->nome);
                strcpy(alunos[j]->nome, alunos[j + 1]->nome);
                strcpy(alunos[j + 1]->nome, temp);

                alunos[j]->documento = documentoT2;
                alunos[j]->matricula = matriculaT2;
                alunos[j + 1]->matricula = matriculaT1;
                alunos[j + 1]->documento = documentoT1;
            }
        }
    }
    i = 0;
    while (i < tamanho)
    {
        fprintf(f, "%s %d %.0f\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        i++;
    }

    fclose(f);
}

void ordenaListaMatricula(Alunos **alunos, int tamanho)
{
    char temp[81];
    int i, j, matriculaT1, matriculaT2;
    float documentoT1, documentoT2;
    FILE *f = fopen("../alunos/aluno.txt", "w");
    if (f == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho - 1 - i; j++)
        {
            if (alunos[j]->matricula > alunos[j + 1]->matricula)
            {
                matriculaT1 = alunos[j]->matricula;
                documentoT1 = alunos[j]->documento;
                matriculaT2 = alunos[j + 1]->matricula;
                documentoT2 = alunos[j + 1]->documento;

                strcpy(temp, alunos[j]->nome);
                strcpy(alunos[j]->nome, alunos[j + 1]->nome);
                strcpy(alunos[j + 1]->nome, temp);

                alunos[j]->documento = documentoT2;
                alunos[j]->matricula = matriculaT2;
                alunos[j + 1]->matricula = matriculaT1;
                alunos[j + 1]->documento = documentoT1;
            }
        }
    }
    i = 0;
    while (i < tamanho)
    {
        fprintf(f, "%s %d %.0f\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        i++;
    }

    fclose(f);
}

int buscaExponencial(Alunos **alunos, int tamanho, int valor)
{
    int i = 1;

    while (i < tamanho && alunos[i]->matricula <= valor)
    {
        i *= 2;
    }
    int j;
    for (j = i / 2; j < i; j++)
    {
        if (alunos[j]->matricula == valor)
        {
            return j;
        }
    }
    return -1;
}

// Função toda bugada
int buscaExponencialNome(Alunos **alunos, int tamanho, char nome[81])
{ // Busca exponencial porque o tamanho do intervalo é dobrado a cada iteração
    if (alunos[0]->nome == nome)
    {
        return 0;
    }
    int i = 1;
    while (i < tamanho && strcmp(alunos[i]->nome, nome) <= 0)
    {           // Encontra o intervalo onde o valor pode estar
        i *= 2; // Dobro do tamanho do intervalo
    }
    int j;
    for (j = i / 2; j < i; j++)
    { // Busca linear no intervalo
        if ((strcmp(alunos[j]->nome, nome) == 0))
        { // Se o valor for encontrado, retorna a posição
            return j;
        }
    }
    return -1; // Se o valor não for encontrado, retorna -1
}

void exibeAluno(Alunos **aluno, int posicao)
{
    printf("Nome do aluno: %s || Matricula: %d || Documento: %.0f\n", aluno[posicao]->nome, aluno[posicao]->matricula, aluno[posicao]->documento);
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