// divanibarbosa@gmail.com
#include <stdio.h>
#include <stdlib.h>
///////////////////////////////////////
// VARIAVEIS GLOBAL PILHA
int *itens, topo, tam;
///////////////////////////////////////
void Inicia_Pilha(int n) {
    itens = (int *) malloc(n*sizeof(int));
    if (itens==NULL) {
    	printf("Erro alocacao memoria itens pilha");
    	exit(0);
	}
    tam = n;
    topo = 0;
}
void push(int valor) { // empilha
    itens [ topo ] = valor;
    topo++;
}
void pop()   { topo--; } // desempilha
int top()    { return itens[ topo-1 ]; } // consulta topo
int empty()  { return ( topo == 0 ); } // pilha vazia?
///////////////////////////////////////////////
typedef struct {
	char item;
	int visitado;
} NO;
///////////////////////////////////////
// VARIAVEIS GLOBAL GRAFO   
NO *VetorNos; // vetor de nós
int **MatAdj; // matriz de adjacência
int nNOs;     // numero de nós
///////////////////////////////////////////////
void Inicia_Grafo(int max) {
    // max = quantidade maxima de Nos
    int i, j;
    VetorNos = (NO *) malloc(max*sizeof(NO));
    if (VetorNos==NULL) {
    	printf("Erro alocacao memoria VetorNos");
    	exit(0);
	}
    MatAdj = (int **) malloc(max*sizeof(int *));
    if (MatAdj==NULL) {
    	printf("Erro alocacao memoria MatAdj");
    	exit(0);
	}
    for(i=0; i<max; i++) {
    	MatAdj[i] = (int *) malloc(max*sizeof(int));
    	if (MatAdj[i]==NULL) {
    		printf("Erro alocacao memoria MatAdj");
    		exit(0);
		}
	}
    
    for (j=0; j<max; j++) // inicializando matriz de adjacencia
        for (i=0; i<max; i++)
            MatAdj[i][j] = 0;
    nNOs = 0;
    Inicia_Pilha(max);
}
void insereNO(char v) {
    VetorNos[nNOs].item = v;
    VetorNos[nNOs].visitado = 0;
    nNOs++;
}
void insereAresta(int inicio, int fim) {
    MatAdj[inicio][fim] = 1;
    MatAdj[fim][inicio] = 1;
}
void mostraNo(int v) {
    printf("%c ",VetorNos[v].item);
}
// Retorna Nó que não foram visitados e são adjacentes ao Nó passado como parametro
int NoNaoVisitado(int i) {
	int j;
    for (j=0; j<nNOs; j++)
        if (MatAdj[i][j]==1 && VetorNos[j].visitado==0)
            return j;
    return -1;
}

  // Algoritmo Busca por profundidade (dfs)
  // Esse algoritmo possui um laço até que a pilha esteja vazia, onde são realizadas 4 tarefas:
  //  1- Examinar o Nó do topo da pilha, usando metodo top
  //  2- Tentar encontrar um vizinho não visitado desse Nó
  //  3- Se não encontrar um, desempilha
  //  4- Se encontrar o Nó, visita ele (marca como visitado) e empilha-o
void dfs() {
     VetorNos[0].visitado = 1; // Começa visitando o Nó zero
     mostraNo(0); // Exibe o Nó zero
     push(0); // Empilha o Nó zero
     while(!empty()) { // enquanto a pilha NAO esta vazia
        int v = NoNaoVisitado(top());
        if ( v == -1) // Se nao houver Nó NAO visitado
           pop(); // desempilha
        else {
           VetorNos[v].visitado = 1; // Visita o Nó
           mostraNo(v); // Exibe o Nó
           push(v); // Empilha o Nó
        }
     } // fim while
     // Aqui a pilha esta vazia, chegou no final
	 int i;
     for (i=0; i<nNOs; i++) // redefine flags para uso posterior se necessário
         VetorNos[i].visitado = 0;
}
///////////////////////////////////////////////
main() {
    Inicia_Grafo(10);

    insereNO('A'); // 0
    insereNO('B'); // 1
    insereNO('C'); // 2
    insereNO('D'); // 3
    insereNO('E'); // 4
    insereNO('F'); // 5
    insereNO('G'); // 6
    insereNO('H'); // 7
    insereNO('I'); // 8

    insereAresta(0, 1); // AB
    insereAresta(1, 5); // BF
    insereAresta(5, 7); // FH
    insereAresta(0, 2); // AC
    insereAresta(0, 3); // AD
    insereAresta(3, 6); // DG
    insereAresta(6, 8); // GI
    insereAresta(0, 4); // AE

    printf("Visitada DFS: ");
    dfs(); // Busca em profundidade ou largura
    printf("\n");
    system("pause");
}