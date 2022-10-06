#include<iostream>
using namespace std;


typedef struct adjacencia{
	int vertice;
	struct adjacencia *prox;
}ADJACENCIA;


typedef struct vertice{
	ADJACENCIA *cad;
}VERTICE;


typedef struct grafo{
	int vertices;
	int arestas;
	VERTICE *vert;
}GRAFO;


GRAFO *criaGrafo(int v);
bool criaAresta(GRAFO *gr, int vi, int vf);
void imprime(GRAFO *gr);


int main(){
	
	GRAFO *gr = criaGrafo(5);
	
	criaAresta(gr,0,1);
	criaAresta(gr,1,2);
	criaAresta(gr,2,0);
	criaAresta(gr,2,4);
	criaAresta(gr,3,1);
	criaAresta(gr,4,3);
	
	imprime(gr);

	
	return 0;
}





GRAFO *criaGrafo(int v){
	GRAFO *g = new (GRAFO);
	g->vertices = v;
	g->arestas = 0;
	g->vert = new VERTICE[v];
	for(int i = 0; i<v; i++)
		g->vert[i].cad = NULL;
	return g;
}


ADJACENCIA * criaAdj(int v){
	ADJACENCIA *temp = new(ADJACENCIA);
	temp->vertice = v;
	//temp->peso = peso;
	temp->prox = NULL;
	return (temp);
}


bool criaAresta(GRAFO *gr, int vi, int vf){
	if(!gr) return (false);
	if ((vf < 0) || (vf >= gr->vertices)) return (false);
	if ((vi < 0) || (vi >= gr->vertices)) return (false);
	
	ADJACENCIA *novo = criaAdj(vf);
	novo->prox = gr->vert[vi].cad;
	gr->vert[vi].cad = novo;
	gr->arestas++;
	
}

void imprime(GRAFO *gr){
	cout<<"Vertices: " <<gr->vertices <<". Arestas: " << gr->arestas<<endl;
	
	for(int i=0; i < gr->vertices; i++){
		cout<< "v" << i <<": ";
		ADJACENCIA *ad = gr->vert[i].cad;
		
		while(ad){
			cout<< "v" << ad->vertice <<" ";
			ad = ad->prox;
		}
		
		cout << endl;
	}
}