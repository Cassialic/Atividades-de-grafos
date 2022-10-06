#include <iostream>

using namespace std;

typedef struct adjacencia{
    int vertice;
    int peso;
    struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{
    ADJACENCIA *cad;
}VERTICE;


typedef struct grafo{
    int vertices;
    int arestas;
    int peso;
     int **adj;
}GRAFO;


GRAFO* inicializa_grafo(int v){
	GRAFO * g = new (GRAFO);
	g->vertices = v,
	g->arestas = 0;

	//inicializa matriz
	
	g->adj = new(int *[v]);
	for(int i = 0; i < v; i++)
		g->adj[i] =new (int[v]);
	for( int i = 0; i < v; i++)
	 for( int j = 0; j < v; j++)
	
		g->adj[i][j] =0;
	return g;
}// v é o numero de vertices


bool inserir_aresta(GRAFO* gr, int vi, int vf,int p){
    if(!gr) return(false);
    if((vf < 0)||(vf >= gr->vertices))
        return(false);
     if((vi < 0)||(vf >= gr->vertices))
        return(false);
    if(gr->adj[vi][vf]=p){
    	gr->adj[vi][vf]=p;
    	gr->arestas++;
    	
    	
	
	return(true);
}

}

void imprime(GRAFO* gr){
        
        for(int i = 0; i < gr->vertices; i++){
        	cout <<endl << "Vertice" << i <<": ";
        	 for(int j = 0; j < gr->vertices; j++)
        	  cout <<" "<< gr->adj[i][j];
        }
    }
    int main(){
   
    GRAFO* gr = inicializa_grafo(6);
     imprime(gr);
     	cout <<endl<< "APÓS INSERIR TEMOS: ";
    inserir_aresta(gr,1,3,4);
      inserir_aresta(gr,1,4,2);
   inserir_aresta(gr,1,5,3);
   inserir_aresta(gr,2,3,4);
   inserir_aresta(gr,2,4,-2);
   inserir_aresta(gr,2,5,3);
   inserir_aresta(gr,3,5,5);
    inserir_aresta(gr,4,5,1);

     imprime(gr);
    return 0;
}