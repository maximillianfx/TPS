#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Nó para lista de disciplinas
typedef struct disciplina
{
    char nome[40];
    char prof[50];
    char codigo[8];
    int creditos;
    char avisos[100];
    struct aluno *matriculados;
    struct disciplina *ant;
    struct disciplina *prox;
}DISCIPLINA;

//Nó para lista de alunos
typedef struct aluno
{
    char nome[50];
    int matricula;
    char curso[30];
    int presenca;
    char bluetooth[40];
    struct aluno *ant;
    struct aluno *prox;
}ALUNO;

DISCIPLINA* CriaListaD(void);
DISCIPLINA* InsereListaD(DISCIPLINA *lista, char *nome, char *prof, char *codigo, int creditos, char *avisos);
void RetiraListaD(DISCIPLINA *lista, char *codigo);
void ImprimeListaD(DISCIPLINA *lista);
void LiberaListaD(DISCIPLINA *lista);
ALUNO* CriaListaA(void);
ALUNO* InsereListaA(ALUNO *lista, char *nome, int matricula, char *curso, char *bluetooth);
void RetiraListaA(ALUNO *lista, int matricula);
void ImprimeListaA(ALUNO *lista);
void LiberaListaA(ALUNO *lista);
ALUNO* BuscaAluno(ALUNO *lista, char *bluetooth);
void LeArquivo(DISCIPLINA *d);

#endif
