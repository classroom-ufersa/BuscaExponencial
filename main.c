#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

#define MAX_ALUNOS 30 // quantidade de alunos possiveis de serem cadastrados

int main(void)
{
    int index = 0, matricula, buscaMatricula, posicao = 0, op;
    char nome[81], buscaNome[81];
    float documento;

    Alunos *alunos[MAX_ALUNOS];

    FILE *aAluno;

    printf("Bem-vindo ao programa de gerenciamento de alunos!\nAutores: Heitor Claudino, Murilo Fontes, Lucas Emanuel e Hector dos Santos\tVersao: 1.0\n");
    do
    {
        printf("\nMenu:\n1 - Escrever aluno\n2 - Buscar aluno por nome\n3 - Buscar aluno por matricula\n4 - Exibir alunos\n5 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEscrevendo um aluno...\n");
            escreveAluno(); // pede as informaçoes do aluno e escreve no arquivo
            aAluno = fopen("../alunos/alunos.txt", "r");
            index = 0;
            while (!(feof(aAluno))) // capturando todos os alunos escritos no arquivo
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
            scanf(" %[^\n]s", buscaNome);                                                   // nome do aluno a ser buscado
            ordenaListaNome(alunos, index);                                                 // ordena a lista por nome
            posicao = buscaExponencial(alunos, matricula, buscaNome, index, op);            // faz a busca exponencial por string
            posicao == -1 ? printf("\nAluno inexistente!\n") : exibeAluno(alunos, posicao); // exibe as informaçoes do aluno, caso encontrado
            break;
        case 3:
            printf("\nBuscando por um aluno...\n");
            printf("Digite a matricula do aluno: ");
            scanf("%d", &buscaMatricula);                                                   // matricula do aluno a ser buscado
            ordenaListaMatricula(alunos, index);                                            // ordena a lista por matricula
            posicao = buscaExponencial(alunos, buscaMatricula, nome, index, op);            // faz a busca exponencial por matricula
            posicao == -1 ? printf("\nAluno inexistente!\n") : exibeAluno(alunos, posicao); // exibe as informaçoes do aluno, caso encontrado
            break;
        case 4:
            printf("\nExibindo alunos...\n");
            int n;
            ordenaListaNome(alunos, index); // ordena alunos por ordem alfabetica antes de exibir
            for (n = 0; n < index; n++)
            {
                // fazer verificacao caso nao tenha alunos
                exibeAluno(alunos, n); // exibe alunos
            }
            break;
        case 5:
            printf("\nSaindo do programa...\n");
            exit(1);
            break;
        }
    } while (op != 5);

    libera(alunos, index); // libera o espaco alocado para alunos
    return 0;
}