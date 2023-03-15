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

Alunos *criaAluno(char nome[81], int matricula, float documento)
{
    Alunos *a = (Alunos *)malloc(sizeof(Alunos));
    strcpy(a->nome, nome);
    a->matricula = matricula;
    a->documento = documento;

    return a;
}

void ordenaLista(Alunos **alunos, int tamanho)
{
    char temp[81];
    FILE *f = fopen("../alunos/aluno.txt", "w");
    if (f == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho - 1 - i; j++)
        {
            if (strcmp(alunos[j]->nome, alunos[j + 1]->nome) > 0)
            {
                strcpy(temp, alunos[j]->nome);
                strcpy(alunos[j]->nome, alunos[j + 1]->nome);
                strcpy(alunos[j + 1]->nome, temp);
            }
        }
    }
    int i = 0;
    while (i < tamanho)
    {
        fprintf(f, "%s %d %.0f\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        i++;
    }

    fclose(f);
}

int buscaExponencial(Alunos **alunos, int tamanho, int valor)
{ // Busca exponencial porque o tamanho do intervalo é dobrado a cada iteração
    int i = 1;

    while (i < tamanho && alunos[i]->matricula <= valor)
    {           // Encontra o intervalo onde o valor pode estar
        i *= 2; // Dobro do tamanho do intervalo
    }
    int j;
    for (j = i / 2; j < i; j++)
    { // Busca linear no intervalo
        if (alunos[j]->matricula == valor)
        { // Se o valor for encontrado, retorna a posição
            return j;
        }
    }
    return -1; // Se o valor não for encontrado, retorna -1
}

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

void libera(Alunos **aluno)
{
    free(aluno);
}