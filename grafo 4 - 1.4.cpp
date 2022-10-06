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
    g->vertices = v;
    g->arestas = 0;
    g->vert = new VERTICE[v];
    for(int i =0; i<v; i++)
        g->vert[i].cad = NULL;
    return g;
}
ADJACENCIA* criaAdj(int v, int peso){
ADJACENCIA* temp = new(ADJACENCIA);
temp->vertice= v;
temp->peso = peso;
temp->prox = NULL;
return(temp);
}
//Criação da aresta 
bool criaAresta(GRAFO* gr, int vi, int vf, int p){
    if(!gr) return(false);
    if((vf < 0)||(vf >= gr->vertices))
        return(false);
     if((vi < 0)||(vf >= gr->vertices))
        return(false);
        
ADJACENCIA* novo = criaAdj(vf,p);
novo->prox=gr->vert[vi].cad;
gr->vert[vi].cad = novo;
gr->arestas++;
return(true);
    
}


    
    void imprime(GRAFO* gr){
        cout<<"Vertice: " << gr->vertices<<".Arestas: "<<gr->arestas <<endl;
        for(int i = 0; i < gr->vertices; i++){
            cout<<"v" << i <<": ";
            ADJACENCIA* ad  = gr->vert[i].cad;
            while(ad){
                cout <<"v" <<ad->vertice <<"(" <<ad->peso <<")";
                ad = ad->prox;
            }
            cout <<endl;
        }
    }
    int main(){
   
    GRAFO* gr = criaGrafo(6);
    criaAresta(gr,1,3,4);
    criaAresta(gr,1,4,2);
    criaAresta(gr,1,5,3);
    criaAresta(gr,2,3,4);
    criaAresta(gr,2,4,-2);
    criaAresta(gr,2,5,3);
    criaAresta(gr,3,5,5);
    criaAresta(gr,4,5,1);
    
    
    imprime(gr);
    return 0;
}