#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    int dataNascimento[3];
    char nome[20];
    char genero[20];
};

void preCadastro(struct Pessoa *pessoas)
{

    // Pessoa 01
    strcpy(pessoas[0].nome, "Henrique");
    strcpy(pessoas[0].genero, "Masculino");
    pessoas[0].dataNascimento[0] = 10;
    pessoas[0].dataNascimento[1] = 8;
    pessoas[0].dataNascimento[2] = 2002;

    // Pessoa 02
    strcpy(pessoas[1].nome, "William");
    strcpy(pessoas[1].genero, "Masculino");
    pessoas[1].dataNascimento[0] = 11;
    pessoas[1].dataNascimento[1] = 8;
    pessoas[1].dataNascimento[2] = 2003;

    // Pessoa 03
    strcpy(pessoas[2].nome, "Milena");
    strcpy(pessoas[2].genero, "Feminino");
    pessoas[2].dataNascimento[0] = 10;
    pessoas[2].dataNascimento[1] = 8;
    pessoas[2].dataNascimento[2] = 2000;

    // Pessoa 04
    strcpy(pessoas[3].nome, "Robert");
    strcpy(pessoas[3].genero, "Masculino");
    pessoas[3].dataNascimento[0] = 7;
    pessoas[3].dataNascimento[1] = 8;
    pessoas[3].dataNascimento[2] = 1990;

    // Pessoa 05
    strcpy(pessoas[4].nome, "Josiane");
    strcpy(pessoas[4].genero, "Feminino");
    pessoas[4].dataNascimento[0] = 11;
    pessoas[4].dataNascimento[1] = 8;
    pessoas[4].dataNascimento[2] = 1980;
}

int calcularIdade(struct Pessoa *pessoa)
{
    int diaPessoa = pessoa->dataNascimento[0];
    int mesPessoa = pessoa->dataNascimento[1];
    int anoPessoa = pessoa->dataNascimento[2];

    int idade = 0;
    int diaAtual = 12;
    int mesAtual = 8;
    int anoAtual = 2022;

    if (mesPessoa < mesAtual)
    {
        idade = anoAtual - anoPessoa;
    }
    else if (mesPessoa > mesAtual)
    {
        idade = anoAtual - anoPessoa - 1;
    }
    else
    {
        if (diaPessoa > diaAtual)
        {
            idade = anoAtual - anoPessoa;
        }
        else
        {
            idade = anoAtual - anoPessoa - 1;
        }
    }
    return idade;
}

int maiorIdade(struct Pessoa *pessoas)
{
    int calcularIdade(struct Pessoa * pessoa);
    int i, maiorIdade = 0;

    for (i = 0; i < 5; i++)
    {
        if (calcularIdade(&pessoas[i]) > maiorIdade)
        {
            maiorIdade = calcularIdade(&pessoas[i]);
        }
    }
    return maiorIdade;
}

int calcularMedia(struct Pessoa *pessoas)
{

    int calcularIdade(struct Pessoa * pessoa);
    char homem, mulher, tudo;
    int i, idade, idades = 0;
    for (i = 0; i < 5; i++)
    {
        idade = calcularIdade(&pessoas[i]);
        idades += idade;
    }
    return idades / 5;
}

int calcularMediaHomens(struct Pessoa *pessoas)
{
    int calcularIdade(struct Pessoa * pessoa);
    int i, homem = 0, quant = 0, idade = 0, quantHomem = 0;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(pessoas[i].genero, "Masculino") == 0)
        {
            idade = calcularIdade(&pessoas[i]);
            homem += idade;
            quantHomem += 1;
        }
    }
    return homem / quantHomem;
}

int calcularMediaMulheres(struct Pessoa *pessoas)
{
    int calcularIdade(struct Pessoa * pessoa);
    int i, mulheres = 0, quant = 0, idade = 0, quantMulher = 0;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(pessoas[i].genero, "Feminino") == 0)
        {
            idade = calcularIdade(&pessoas[i]);
            mulheres += idade;
            quantMulher += 1;
        }
    }
    return mulheres / quantMulher;
}

int calcularHomens(struct Pessoa *pessoas)
{
    int i, quant = 0;

    for (i = 0; i < 5; i++)
    {
        if (strcmp(pessoas[i].genero, "Masculino") == 0)
        {
            quant += 1;
        }
    }
    return quant;
}

int calcularMulheres(struct Pessoa *pessoas)
{
    int i, quant = 0;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(pessoas[i].genero, "Feminino") == 0)
        {
            quant += 1;
        }
    }
    return quant;
}

void visualizarPessoas(struct Pessoa *pessoas)
{
    int i;
    printf(" ___________________________________________________________________________________________");
    printf("\n|\n|                      Dados pre-cadastrados \n|\n");
    for (i = 0; i < 5; i++)
    {
        printf("|   Nome: %s    Nascimento: %d/%d/%d    Genero: %s  Idade: %d\n", pessoas[i].nome, pessoas[i].dataNascimento[0],
               pessoas[i].dataNascimento[1], pessoas[i].dataNascimento[2], pessoas[i].genero, calcularIdade(&pessoas[i]));
    }
    printf("|___________________________________________________________________________________________\n|\n");
}

void visualizarAtualizadas(struct Pessoa *pessoas)
{
    int i;
    printf(" ___________________________________________________________________________________________");
    printf("\n|\n|                      Dados Atualizados \n|\n");

    for (i = 0; i < 5; i++)
    {
        printf("|   Nome: %s      Nascimento: %d/%d/%d    Genero: %s  Idade: %d\n", pessoas[i].nome, pessoas[i].dataNascimento[0],
               pessoas[i].dataNascimento[1], pessoas[i].dataNascimento[2], pessoas[i].genero, calcularIdade(&pessoas[i]));
    }
    printf("|___________________________________________________________________________________________\n|\n");
}

void novaDataNascimento(struct Pessoa *pessoas, int a, int b, int c)
{
    pessoas->dataNascimento[0] = a;
    pessoas->dataNascimento[1] = b;
    pessoas->dataNascimento[2] = c;
}

int main()
{
    struct Pessoa pessoaV1, pessoaV2, pessoaV3, pessoaV4, pessoaV5;
    struct Pessoa pessoas[] = {pessoaV1, pessoaV2, pessoaV3, pessoaV4, pessoaV5};
    int a = 1;
    int b = 5;
    int c = 1960;

    preCadastro(pessoas);
    visualizarPessoas(pessoas);

    printf("|                       Funcoes \n|");
    printf("\n|   A maior idade e .........................................:  %d\n", maiorIdade(pessoas));
    printf("|   A media das idades e ....................................:  %d\n", calcularMedia(pessoas));
    printf("|   A media das idades dos homens e .........................:  %d\n", calcularMediaHomens(pessoas));
    printf("|   A media das idades das mulheres e .......................:  %d\n", calcularMediaMulheres(pessoas));
    printf("|   Quantidade de homens ....................................:  %d\n", calcularHomens(pessoas));
    printf("|   Quantidade de mulheres ..................................:  %d\n|\n", calcularMulheres(pessoas));
    printf("|___________________________________________________________________________________________\n\n\n");

    novaDataNascimento(&pessoas[0], 1, 5, 1960);
    novaDataNascimento(&pessoas[1], 7, 7, 1986);
    novaDataNascimento(&pessoas[2], 13, 8, 1998);
    novaDataNascimento(&pessoas[3], 15, 9, 2000);
    novaDataNascimento(&pessoas[4], 10, 11, 2006);
    visualizarAtualizadas(pessoas);

    printf("|                       Funcoes \n|");
    printf("\n|   A maior idade e .........................................:  %d\n", maiorIdade(pessoas));
    printf("|   A media das idades e ....................................:  %d\n", calcularMedia(pessoas));
    printf("|   A media das idades dos homens e .........................:  %d\n", calcularMediaHomens(pessoas));
    printf("|   A media das idades das mulheres e .......................:  %d\n", calcularMediaMulheres(pessoas));
    printf("|   Quantidade de homens ....................................:  %d\n", calcularHomens(pessoas));
    printf("|   Quantidade de mulheres ..................................:  %d\n|\n", calcularMulheres(pessoas));
    printf("|___________________________________________________________________________________________\n\n");
    system("pause");
    system("cls");
    return 0;
}