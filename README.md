# Busca exponencial

A busca exponencial consiste em buscar um elemento de um array (vetor) quando não se sabe sua posição exata.

Para isso, basta encontrar a faixa do vetor em que o elemento está presente, e depois fazer a busca binária para localizar sua posição.

## Organização dos arquivos
- bin
    - aluno.o
    - main.o
- out
    - main.exe
- public
    - index.c
- service
    - alunos.txt
- src
    - c
        - aluno.c
        - aluno.h
    - css
        - styles.css
    - js
        - index.js
## Como executar o código
Para executar o código é preciso estar no diretório `out` e, no terminal, escrever e executar a linha de comando `./main`.

## Explicação do código que faz a Busca Exponencial
As funções que realizam a busca exponencial estão separadas por categoria, `buscaExponencialNome`e `buscaExponencialMatricula`, dependendo da opção que o usuário digitar. A declaração de ambas as funções é parecida, mudando apenas o argumento relacionado ao método de busca (nome ou matrícula). Os vetores precisam estar ordenados para que a função funcione.

```c
int buscaExponencialNome(Alunos **alunos, char nome[81], int tamanho, int opcao);
int buscaExponencialMatricula(Alunos **alunos, int mat, int tamanho, int opcao);
```

Ao chamar a função `buscaExponencialNome`, compara-se o nome do primeiro índice do vetor com o nome procurado (através da função `strcmp`, da biblioteca `string.h`) e, caso estes sejam iguais, retorna a primeira posição do vetor (0). Isso precisa ocorrer pois, na busca exponencial, as verificações precisam iniciar do índice 1, então o índice 0 precisa ser verificado à parte.

Caso a verificação retorne falso, o código entra no while, que funciona enquanto o índice (iniciado em 1) for menor do que o tamanho do vetor, e enquanto a primeira letra do nome do vetor for 'menor' do que a primeira letra do nome procurado (isto é, se o nome procurado começa com C, a procura continua sendo feita enquanto a inicial dos nomes do vetor forem A, B ou C).

O while incrementa a variável `i` de forma exponencial, multiplicando seu valor anterior por 2. Dessa forma, em um vetor de 8 posições, primeiro será verificada a posição 1, depois a posição 2, depois a posição 4 e, por fim, a posição 8. As verificações param quando o `i` assume um valor maior que o tamanho do vetor, ou quando a primeira letra do nome do vetor ultrapassa a primeira letra do nome pesquisado (isto é, se estou pesquisando um nome que se inicia com a letra C, e já verifiquei todos os nomes com a letra C, certamente o nome procurado está nas verificações já feitas).

Por fim, ao encontrar a faixa de elementos em que o elemento está, chama-se a busca binária passando como parâmetros o vetor de alunos, a faixa do vetor em que o elemento está presente e o nome procurado.

```c
int i = 1;
    {
        if (strcmp(alunos[0]->nome, nome) == 0) // analisa se o nome procurado está no primeiro índice do vetor
        {
            return 0;
        }
        while (i < tamanho && strcmp(alunos[i]->nome, nome) <= 0) // analisa a faixa em que o nome está presente
        {
            i *= 2;
        }
        return buscaBinariaNome(alunos, i / 2, fmin(i, tamanho - 1), nome); // chama a busca binária para encontrar o nome
    }
```

## Explicação do funcionamento da Busca Binária
A busca binária é outro grupo

```c
int buscaBinariaNome(Alunos **alunos, int index, int posicao, char nome[81]);
int buscaBinariaMatricula(Alunos **alunos, int index, int posicao, int mat);
```