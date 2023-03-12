#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

int main(void)
{
    Alunos *alunos;
    char str[81];

    FILE *aAluno = fopen("../alunos/aluno.txt", "r");
    if (aAluno == NULL)
    {
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }

    fgets(str, 81, aAluno);
    printf("%s", str);

    libera(alunos);
    fclose(aAluno);

    return 0;
}