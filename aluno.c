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

    if(alunos[0]->nome == nome){
        return 0;
    }

    int i = 1;
    while (i < 6 && strcmp(alunos[i]->nome, nome) <= 0)
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
    printf("Nome do aluno: %s\nMatricula: %d\nDocumento: %.0f", aluno[posicao]->nome, aluno[posicao]->matricula, aluno[posicao]->documento);
}

void libera(Alunos **aluno)
{
    free(aluno);
}