#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "../src/c/aluno.h"

#define MAX_ALUNOS 30 // quantidade de alunos possiveis de serem cadastrados

int main(void)
{

    int index = 0, matricula, buscaMatricula, posicao = 0, op;
    char nome[81], buscaNome[81];
    float documento;

    Alunos *alunos[MAX_ALUNOS];

    FILE *aAluno;

    aAluno = fopen("../service/alunos.txt", "r");
    // capturando todos os alunos já existentes no arquivo
    while (!(feof(aAluno)))
    {
        fscanf(aAluno, " %[^\t]\t%d\t%f", nome, &matricula, &documento);
        alunos[index] = capturaAluno(nome, matricula, documento);
        index++;
    }
    index -= 1;
    fclose(aAluno);

    printf("Bem-vindo ao programa de gerenciamento de alunos!\nAutores: Heitor Claudino, Murilo Fontes, Lucas Emanuel e Hector dos Santos\tVersao: 1.0\n");
    do
    {
        printf("\nMenu:\n1 - Escrever aluno\n2 - Buscar aluno por nome\n3 - Buscar aluno por matricula\n4 - Exibir alunos\n5 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEscrevendo um aluno...\n");
            // escrevendo um aluno no arquivo
            escreveAluno();
            aAluno = fopen("../service/alunos.txt", "r");
            index = 0;
            // capturando todos os alunos escritos no arquivo
            while (!(feof(aAluno)))
            {
                fscanf(aAluno, " %[^\t]\t%d\t%f", nome, &matricula, &documento);
                alunos[index] = capturaAluno(nome, matricula, documento);
                index++;
            }
            index -= 1;
            fclose(aAluno);
            break;
        case 2:
            printf("\nBuscando por um aluno...\n");
            printf("Digite o nome da aluno: ");
            scanf(" %[^\n]s", buscaNome);
            ordenaListaNome(alunos, index);
            posicao = buscaExponencialNome(alunos, buscaNome, index);
            posicao == -1 ? printf("\nAluno inexistente!\n") : exibeAluno(alunos, posicao);
            break;
        case 3:
            printf("\nBuscando por um aluno...\n");
            printf("Digite a matricula do aluno: ");
            scanf("%d", &buscaMatricula);
            // ordenando a lista pelo número da matrícula (ordem crescente)
            ordenaListaMatricula(alunos, index);
            // fazendo a busca exponencial pelo número da matrículo
            posicao = buscaExponencialMatricula(alunos, buscaMatricula, index);
            posicao == -1 ? printf("\nAluno inexistente!\n") : exibeAluno(alunos, posicao);
            break;
        case 4:
            printf("\nExibindo alunos...\n");
            int n;
            // ordenando a lista em ordem alfabética
            ordenaListaNome(alunos, index);
            for (n = 0; n < index; n++)
            {
                exibeAluno(alunos, n);
            }
            break;
        case 5:
            printf("\nSaindo do programa...\n");
            exit(1);
            break;
        }
    } while (op != 5);

    libera(alunos, index);
    return 0;
}