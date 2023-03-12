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
    // int index = 0;
    while (i < tamanho && alunos[i]->matricula <= valor)
    {           // Encontra o intervalo onde o valor pode estar
        i *= 2; // Dobro do tamanho do intervalo
        // index++;
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

void libera(Alunos **aluno)
{
    free(aluno);
}