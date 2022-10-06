

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
    VERTICE *vert;
}GRAFO;


GRAFO * criaGrafo(int v){
    GRAFO* g = new(GRAFO);
    g->vertices = v++;
    g->arestas = 0;
    g->vert = new VERTICE[v];
    for(int i = 0 ; i<v; i++)
        g->vert[i].cad = NULL;
    return g;
}
ADJACENCIA* criaAdj(int v){
ADJACENCIA* temp = new(ADJACENCIA);
temp->vertice= v;
//temp->peso = peso;
temp->prox = NULL;
return(temp);
}
//Criação da aresta 
bool criaAresta_nao(GRAFO* gr, int vi, int vf){
    if(!gr) return(false);
    if((vf < 0)||(vf >= gr->vertices))
        return(false);
     if((vi < 0)||(vi >= gr->vertices))
        return(false);
        
ADJACENCIA* novo = criaAdj(vf);
novo->prox=gr->vert[vi].cad;
gr->vert[vi].cad = novo;

ADJACENCIA* novo2 = criaAdj(vi);
novo2->prox=gr->vert[vf].cad;
gr->vert[vf].cad = novo2;

gr->arestas++;
return(true);
    
}

int grau_do_no(GRAFO* gr, int no){
	int j = no -1, c = 0;
	ADJACENCIA* ad = gr->vert[j].cad;
	while(ad){
		c++;
		ad= ad->prox;
	}
	return c;
}

bool existe_aresta(GRAFO* gr, int vi, int vf){
	ADJACENCIA* ad= gr->vert[vi].cad;
	while(ad){
		if(ad->vertice == vf) return true;
		ad = ad->prox;
}
return false;
}

int grau_no_entrada(GRAFO* gr, int no){
	int j = no-1, c=0;
	for(int i = 0; i< gr->vertices; i++){
		ADJACENCIA* ad = gr->vert[i].cad;
		while(ad){
			if(ad->vertice == j)c++;
			ad = ad->prox;
		}
	}
	return c;
}


    
    void imprime(GRAFO* gr){
        cout<<"Vertice: " << gr->vertices<<".Arestas: "<<gr->arestas <<endl;
        for(int i = 0; i < gr->vertices; i++){
            cout<<"v" << i <<": ";
            ADJACENCIA* ad  = gr->vert[i].cad;
            while(ad){
                cout <<"v" <<ad->vertice ;
                ad = ad->prox;
            }
            cout <<endl;
        }
    }
    int main(){
   
    GRAFO* gr = criaGrafo(5);
    criaAresta_nao(gr,1,3);
    criaAresta_nao(gr,1,4);
    criaAresta_nao(gr,1,5);
    criaAresta_nao(gr,2,3);
    criaAresta_nao(gr,2,4);
    criaAresta_nao(gr,2,5);
    
    
    
    
    imprime(gr);
    return 0;
}