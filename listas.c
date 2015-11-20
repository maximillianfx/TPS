#include "listas.h"

//Cria uma lista de disciplinas
DISCIPLINA* CriaListaD(void)
{
    return NULL;
}

//Insere um nó na lista de disciplinas
DISCIPLINA* InsereListaD(DISCIPLINA *lista, char *nome, char *prof, char *codigo, int creditos, char *avisos)
{
    DISCIPLINA *p, *aux;

    if(lista == NULL) //Caso seja o primeiro nó
    {
        p = (DISCIPLINA*)malloc(sizeof(DISCIPLINA)); //Adiciona na lista
        strcpy(p->nome, nome);
        strcpy(p->prof, prof);
        strcpy(p->codigo, codigo);
        p->creditos = creditos;
        strcpy(p->avisos, avisos);
        p->matriculados = CriaListaA();

        p->prox = NULL; //Organiza os ponteiros
        p->ant = NULL;
        return p;
    }
    else //Caso não seja o primeiro nó
    {
        for(aux = lista;aux != NULL;aux = aux->prox) //Roda a lista toda
        {
            if(strcmp(codigo, aux->codigo) == 0) //Caso já tenha aquela disciplina na lista
            {
                return lista; //Retorna ela mesma
            }
            else if((strcmp(codigo, aux->codigo) > 0)&&(strcmp(aux->prox->codigo, codigo) > 0)) //Caso não tenha a disciplina
            {
                p = (DISCIPLINA*)malloc(sizeof(DISCIPLINA)); //Adiciona ela na lista
                strcpy(p->nome, nome);
                strcpy(p->prof, prof);
                strcpy(p->codigo, codigo);
                p->creditos = creditos;
                strcpy(p->avisos, avisos);
                p->matriculados = CriaListaA();

                p->prox = aux->prox->ant; //Organiza os ponteiros
                aux->prox->ant = p;
                aux->prox = p;
                p->ant = aux;

                return lista;
            }
            else if((strcmp(codigo, aux->codigo) > 0)&&(aux->prox == NULL)) //Caso só tenha 1 e vá vir depois
            {
                p = (DISCIPLINA*)malloc(sizeof(DISCIPLINA)); //Adiciona ela na lista
                strcpy(p->nome, nome);
                strcpy(p->prof, prof);
                strcpy(p->codigo, codigo);
                p->creditos = creditos;
                strcpy(p->avisos, avisos);
                p->matriculados = CriaListaA();

                p->prox = aux->prox; //Organiza os ponteiros
                aux->prox = p;
                p->ant = aux;

                return lista;
            }
            else if((strcmp(codigo, aux->codigo) < 0)&&(aux->ant == NULL)) //Caso só tenha 1 e vá vir antes
            {
                p = (DISCIPLINA*)malloc(sizeof(DISCIPLINA)); //Adiciona ela na lista
                strcpy(p->nome, nome);
                strcpy(p->prof, prof);
                strcpy(p->codigo, codigo);
                p->creditos = creditos;
                strcpy(p->avisos, avisos);
                p->matriculados = CriaListaA();

                p->prox = aux; //Organiza os ponteiros
                aux->ant = p;
                p->ant = aux->ant;

                return lista;
            }
        }
    }
}

//Retira elemento da lista de disciplinas com o código pedido
void RetiraListaD(DISCIPLINA *lista, char *codigo)
{
    DISCIPLINA *aux;

    for(aux = lista;aux != NULL;aux = aux->prox) //Roda a lista toda
    {
        if(strcmp(aux->codigo, codigo) == 0) //Caso seja o elemento que tem aquele código
        {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
        }
    }
}

//Imprime a lista de disciplinas
void ImprimeListaD(DISCIPLINA *lista)
{
    DISCIPLINA *aux;

    for(aux = lista;aux !=NULL;aux = aux->prox)
    {
        printf("/n/nDisciplina: %s", aux->nome);
        printf("/n  Professor: %s", aux->prof);
        printf("/n  Codigo: %s", aux->codigo);
        printf("/n  Creditos: %d", aux->creditos);
        printf("/n  Avisos: %s", aux->avisos);
    }
}

//Libera a lista
void LiberaListaD(DISCIPLINA *lista)
{
    DISCIPLINA *aux;

    while(lista != NULL)
    {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
}

//Cria uma lista de alunos
ALUNO* CriaListaA(void)
{
    return NULL;
}

//Insere um nó na lista de alunos
ALUNO* InsereListaA(ALUNO *lista, char *nome, int matricula, char *curso, char *bluetooth)
{
    ALUNO *p, *aux;

    if(lista == NULL) //Caso seja o primeiro nó
    {
        p = (ALUNO*)malloc(sizeof(ALUNO)); //Adiciona na lista
        strcpy(p->nome, nome);
        p->matricula = matricula;
        strcpy(p->curso, curso);
        p->presenca = 0;
        strcpy(p->bluetooth, bluetooth);

        p->prox = NULL; //Organiza os ponteiros
        p->ant = NULL;
        return p;
    }
    else //Caso não seja o primeiro nó
    {
        for(aux = lista;aux != NULL;aux = aux->prox) //Roda a lista toda
        {
            if(aux->matricula == matricula) //Caso já tenha aquele aluno na lista
            {
                return lista; //Retorna ela mesma
            }
            else if((matricula > aux->matricula)&&(aux->prox->matricula > matricula)) //Caso não tenha o aluno
            {
                p = (ALUNO*)malloc(sizeof(ALUNO)); //Adiciona na lista
                strcpy(p->nome, nome);
                p->matricula = matricula;
                strcpy(p->curso, curso);
                p->presenca = 0;
                strcpy(p->bluetooth, bluetooth);

                p->prox = aux->prox->ant; //Organiza os ponteiros
                aux->prox->ant = p;
                aux->prox = p;
                p->ant = aux;

                return lista;
            }
        }
    }
}

//Retira elemento da lista de alunos com a matrícula pedida
void RetiraListaA(ALUNO *lista, int matricula)
{
    ALUNO *aux;

    for(aux = lista;aux != NULL;aux = aux->prox) //Roda a lista toda
    {
        if(aux->matricula == matricula) //Caso seja o elemento que tem aquela matrícula
        {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
        }
    }
}

//Imprime a lista de alunos
void ImprimeListaA(ALUNO *lista)
{
    ALUNO *aux;

    for(aux = lista;aux !=NULL;aux = aux->prox)
    {
        printf("/n/n  Aluno: %s", aux->nome);
        printf("/n    Matricula: %d", aux->matricula);
        printf("/n    Curso: %s", aux->curso);
        printf("/n    Presenca: %d", aux->presenca);
        printf("/n    Bluetooth: %s", aux->bluetooth);
    }
}

//Libera a lista
void LiberaListaA(ALUNO *lista)
{
    ALUNO *aux;

    while(lista != NULL)
    {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
}

//Busca aluno dentro de uma lista com o código do bluetooth
ALUNO* BuscaAluno(ALUNO *lista, char *bluetooth)
{
    ALUNO *aux;

    for(aux = lista;aux != NULL;aux = aux->prox) //Roda a lista toda
    {
        if(strcmp(aux->bluetooth, bluetooth) == 0) //Caso seja o elemento que tem aquela matrícula
        {
            return(aux);
        }
    }
    return(NULL);
}

//Le arquivo com as informacoes e coloca nas listas
void LeArquivo(DISCIPLINA *d)
{
	FILE *arq;
	DISCIPLINA *auxd;
	ALUNO *auxa;
	char buffer, mudanca[12];
	int n;
	
	auxd = (DISCIPLINA*)malloc(sizeof(DISCIPLINA));
	auxa = (ALUNO*)malloc(sizeof(ALUNO));	
	arq = fopen("informacoes.txt", "r");
	fscanf(arq, "%s", mudanca); //mudanca = "Disciplina:"
	
	while(!feof(arq))
	{
		fscanf(arq, "%s", auxd->nome); //Copia os dados da disciplina
		fscanf(arq, "%s", auxd->prof);
		fscanf(arq, "%s", auxd->codigo);
		fscanf(arq, "%d", &auxd->creditos);
		fscanf(arq, "%c", &buffer);
		fscanf(arq, "%c", &buffer);
		n=0;
		while(buffer != '.') //Le os avisos até o ponto
		{
			auxd->avisos[n] = buffer;
			n++;
			fscanf(arq, "%c", &buffer);
		}
		auxd->avisos[n] = '.';
		auxd->avisos[n] = '\0';
		fscanf(arq, "%s", mudanca);
		d = InsereListaD(d, auxd->nome, auxd->prof, auxd->codigo, auxd->creditos, auxd->avisos); //Põe a disciplina na lista
		while(strcmp(mudanca, "Aluno:") == 0) //Copia os dados dos alunos
		{
			fscanf(arq, "%s", auxa->nome);
			fscanf(arq, "%d", &auxa->matricula);
			fscanf(arq, "%s", auxa->curso);
			fscanf(arq, "%s", auxa->bluetooth);
			fscanf(arq, "%s", mudanca);
			d->matriculados = InsereListaA(d->matriculados, auxa->nome, auxa->matricula, auxa->curso, auxa->bluetooth); //Põe o aluno na lista
		}
	}
	free(auxd);
	free(auxa);
	fclose(arq);
}
