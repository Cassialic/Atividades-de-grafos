#include <iostream>
#include <fstream>
#include <stdlib.h>

typedef int TIPOPESO;

using namespace std;
//BUSCA em profundidade num grafo representado usando Lista de adjacência.
/*
Dirigido/direcionado e ponderado
*/

typedef struct adjacencia {
int vertice;
int peso;
struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice {
ADJACENCIA *cad;
}VERTICE;

typedef struct grafo{
int vertices;
int arestas;
VERTICE *vert;
}GRAFO;

GRAFO* criaGrafo(int v);
bool criaAresta(GRAFO* gr, int vi, int vf, TIPOPESO p);
void imprime(GRAFO* gr);
void dfs_busca(GRAFO* gr, int no , bool v[]);
void inicializa_visitados(bool v[], int tam);
void print_visitados(bool v[], int tam);
int no_sem_visitar(bool v[], int tam);

int main()
{

    int qtd_vertices = 6;
    GRAFO* gr = criaGrafo(qtd_vertices);
    criaAresta(gr,0,2,4);
    criaAresta(gr,0,3,2);
    criaAresta(gr,0,4,3);
    criaAresta(gr,1,2,4);
    criaAresta(gr,1,3,-2);
    criaAresta(gr,1,4,3);
    criaAresta(gr,2,4,5);
    criaAresta(gr,3,4,1);
    imprime(gr);

    bool visitados[qtd_vertices];
    inicializa_visitados(visitados,qtd_vertices);
    print_visitados(visitados,qtd_vertices);

    // inciar pelo nó 1
    dfs_busca(gr,0,visitados);

    // tenho que conferir que todos foram visitados
    int sem_visitar = no_sem_visitar(visitados,qtd_vertices);
    cout << "sem_visitar " << sem_visitar << endl;
    while (sem_visitar != -1){
        dfs_busca(gr,sem_visitar,visitados);
        sem_visitar = no_sem_visitar(visitados, qtd_vertices);
    }
    print_visitados(visitados,qtd_vertices);
    return 0;
}

int no_sem_visitar(bool v[], int tam){
    for (int j=0; j <tam; j++)
            if (v[j]==false)
                return j;
    return -1;
}



void inicializa_visitados(bool v[], int tam){
        for (int j=0; j <tam; j++)
            v[j]=false;

}

void print_visitados(bool v[], int tam){
        for (int j=0; j <tam; j++)
        cout << v[j] << ",";
}

void dfs_busca(GRAFO* gr, int no , bool v[]){
    v[no]=true;
    cout << "O no "<< no+1 << " foi visitado" << endl;
    ADJACENCIA* ad = gr->vert[no].cad;
    while (ad){
        if (v[ad->vertice]==false)
            dfs_busca (gr, ad->vertice, v);
        ad=ad->prox;
    }
    cout << "Terminou com o nó " << no+1 << endl;
}


GRAFO* criaGrafo(int v){
    GRAFO* g = new (GRAFO);
    g->vertices=v;
    g->arestas=0;
    g->vert = new VERTICE[v];
    for (int i=0; i<v; i++)
        g->vert[i].cad = NULL;
    return g;
}

ADJACENCIA* criaAdj(int v, int peso){
    ADJACENCIA* temp = new(ADJACENCIA);
    temp->vertice=v;
    temp->peso = peso;
    temp->prox=NULL;
    return (temp);
}

bool criaAresta(GRAFO* gr, int vi, int vf, TIPOPESO p){
    if (!gr) return (false);
    if ((vf<0)|| (vf >= gr->vertices))
        return (false);
    if ((vi<0)|| (vi>=gr->vertices))
        return (false);
    ADJACENCIA* novo = criaAdj(vf,p);
    novo->prox=gr->vert[vi].cad;
    gr->vert[vi].cad = novo;
    gr->arestas++;
    return (true);
}

void imprime(GRAFO* gr){
    cout << "Vertices: " << gr->vertices <<". Arestas: "<< gr->arestas << endl;
    for (int i=0; i < gr->vertices; i++){
        cout << "v" << i <<": ";
        ADJACENCIA* ad = gr->vert[i].cad;
        while(ad){
            cout << "v" << ad->vertice << "(" << ad->peso << "), ";
            ad = ad->prox;
        }
    cout << endl;
}
}