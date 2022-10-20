#include <bits/stdc++.h>
//Número de pontos do grafo
#define pontos 20

using namespace std;

vector<int> imagem;

bool verificaL(int la, int lb, int a[][pontos], int b[][pontos]){
    for(int i = 0; i < pontos; i++){
        if(a[la][i] != b[lb][i]){
            return false;
        }
    }
    return true;
}

//Função que recebe os valores de permuntação pra comparar
bool verifica(int a[][pontos], int b[][pontos], vector<int> candidato){
    for(int i = 0; i < pontos; i++){
        if(verificaL(i, candidato[i], a, b) == true)
            return true;
        return false;
    }
}

//Função responsável por permutar a array de índices
void troca(int vetor[], int i, int j){
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup, int a[][pontos], int b [][pontos]){
	if(inf == sup){
		for(int i = 0; i <= sup; i++)
			imagem.push_back(vetor[i]);
		if(verifica(a, b, imagem) == true){
           return;
		}
		imagem.clear();
	}else{
		for(int i = inf; i <= sup; i++){
			troca(vetor, inf, i);
			permuta(vetor, inf + 1, sup, a, b);
			troca(vetor, inf, i); // backtracking
		}
	}
}

int main(){
    //Inicialização do vetor de índices a permutar
	int v[pontos];
	for(int i = 0; i < pontos; i++){
        v[i] = i;
	}
	int tam_v = pontos;
	//Representando os grafos usando a matriz de incidência
	int A[pontos][pontos] = {}, B[pontos][pontos] = {}, C[pontos][pontos] = {};

	//Relacionando os pontos vizinhos do grafo A
	A[0][1] = 1;
	A[0][9] = 1;
	A[0][12] = 1;
	A[0][13] = 1;
	A[0][14] = 1;
	A[0][19] = 1;
	A[1][2] = 1;
	A[1][3] = 1;
	A[1][4] = 1;
	A[1][7] = 1;
	A[1][8] = 1;
	A[1][9] = 1;
	A[1][10] = 1;
	A[1][11] = 1;
	A[1][12] = 1;
	A[1][13] = 1;
	A[1][15] = 1;
	A[1][19] = 1;
	A[2][3] = 1;
	A[2][4] = 1;
	A[2][7] = 1;
	A[2][9] = 1;
	A[2][11] = 1;
	A[2][12] = 1;
	A[2][13] = 1;
	A[2][15] = 1;
	A[2][16] = 1;
	A[3][5] = 1;
	A[3][6] = 1;
	A[3][8] = 1;
	A[3][9] = 1;
	A[3][10] = 1;
	A[3][11] = 1;
	A[3][12] = 1;
	A[3][13] = 1;
	A[3][16] = 1;
	A[3][17] = 1;
	A[4][6] = 1;
	A[4][7] = 1;
	A[4][8] = 1;
	A[4][12] = 1;
	A[4][15] = 1;
	A[4][17] = 1;
	A[4][18] = 1;
	A[4][19] = 1;
	A[5][7] = 1;
	A[5][9] = 1;
	A[5][11] = 1;
	A[5][13] = 1;
	A[5][14] = 1;
	A[5][15] = 1;
	A[5][16] = 1;
	A[5][19] = 1;
	A[6][9] = 1;
	A[6][10] = 1;
	A[6][11] = 1;
	A[6][12] = 1;
	A[6][13] = 1;
	A[6][14] = 1;
	A[6][15] = 1;
	A[6][17] = 1;
	A[6][18] = 1;
	A[6][19] = 1;
	A[7][9] = 1;
	A[7][11] = 1;
	A[7][12] = 1;
	A[7][13] = 1;
	A[7][14] = 1;
	A[7][15] = 1;
	A[8][10] = 1;
	A[8][11] = 1;
	A[8][12] = 1;
	A[8][14] = 1;
	A[8][15] = 1;
	A[8][17] = 1;
	A[8][18] = 1;
	A[9][11] = 1;
	A[9][12] = 1;
	A[9][13] = 1;
	A[9][14] = 1;
	A[9][16] = 1;
	A[9][17] = 1;
	A[9][19] = 1;
	A[10][13] = 1;
	A[10][14] = 1;
	A[10][16] = 1;
	A[10][19] = 1;
	A[11][12] = 1;
	A[11][13] = 1;
	A[11][14] = 1;
	A[11][16] = 1;
	A[11][17] = 1;
	A[12][13] = 1;
	A[12][14] = 1;
	A[12][15] = 1;
	A[12][16] = 1;
	A[12][17] = 1;
	A[12][19] = 1;
	A[13][15] = 1;
	A[13][16] = 1;
	A[14][18] = 1;
	A[14][19] = 1;
	A[15][16] = 1;
	A[15][17] = 1;
	A[15][18] = 1;
	A[16][18] = 1;
	A[17][18] = 1;
	A[17][19] = 1;
	A[18][19] = 1;

	//Relacionando os pontos vizinhos do grafo B
	B[0][1] = 1;
	B[0][4] = 1;
	B[0][7] = 1;
	B[0][12] = 1;
	B[0][13] = 1;
	B[0][19] = 1;
	B[1][2] = 1;
	B[1][5] = 1;
	B[1][7] = 1;
	B[1][10] = 1;
	B[1][11] = 1;
	B[1][12] = 1;
	B[1][16] = 1;
	B[1][17] = 1;
	B[1][18] = 1;
	B[1][19] = 1;
	B[2][3] = 1;
	B[2][6] = 1;
	B[2][7] = 1;
	B[2][8] = 1;
	B[2][10] = 1;
	B[2][11] = 1;
	B[2][12] = 1;
	B[2][13] = 1;
	B[2][14] = 1;
	B[2][17] = 1;
	B[2][19] = 1;
	B[3][4] = 1;
	B[3][7] = 1;
	B[3][8] = 1;
	B[3][9] = 1;
	B[3][10] = 1;
	B[3][11] = 1;
	B[3][12] = 1;
	B[3][13] = 1;
	B[3][15] = 1;
	B[3][16] = 1;
	B[3][18] = 1;
	B[4][5] = 1;
	B[4][6] = 1;
	B[4][7] = 1;
	B[4][9] = 1;
	B[4][10] = 1;
	B[4][11] = 1;
	B[4][12] = 1;
	B[4][13] = 1;
	B[4][14] = 1;
	B[4][18] = 1;
	B[4][19] = 1;
	B[5][6] = 1;
	B[5][7] = 1;
	B[5][9] = 1;
	B[5][11] = 1;
	B[5][12] = 1;
	B[5][13] = 1;
	B[5][14] = 1;
	B[5][16] = 1;
	B[6][8] = 1;
	B[6][9] = 1;
	B[6][12] = 1;
	B[6][13] = 1;
	B[6][14] = 1;
	B[6][15] = 1;
	B[6][16] = 1;
	B[6][17] = 1;
	B[6][18] = 1;
	B[7][8] = 1;
	B[7][9] = 1;
	B[7][11] = 1;
	B[7][12] = 1;
	B[7][13] = 1;
	B[7][15] = 1;
	B[7][16] = 1;
	B[7][19] = 1;
	B[8][11] = 1;
	B[8][12] = 1;
	B[8][14] = 1;
	B[8][17] = 1;
	B[8][18] = 1;
	B[8][19] = 1;
	B[9][11] = 1;
	B[9][12] = 1;
	B[9][13] = 1;
	B[9][14] = 1;
	B[9][15] = 1;
	B[10][13] = 1;
	B[10][15] = 1;
	B[10][18] = 1;
	B[10][19] = 1;
	B[11][12] = 1;
	B[11][13] = 1;
	B[11][15] = 1;
	B[11][16] = 1;
	B[11][18] = 1;
	B[12][13] = 1;
	B[12][14] = 1;
	B[12][15] = 1;
	B[12][18] = 1;
	B[12][19] = 1;
	B[13][15] = 1;
	B[13][16] = 1;
	B[14][17] = 1;
	B[14][18] = 1;
	B[14][19] = 1;
	B[15][16] = 1;
	B[15][17] = 1;
	B[16][19] = 1;
	B[17][18] = 1;
	B[17][19] = 1;

	//Fazendo a famosa """""brincadeira"""""
	permuta(v, 0, tam_v - 1, A, B);
    //Impressão da função
    cout << "f: V(A) -> V(B)\n";
    for(int i = 0; i < pontos; i++){
        cout << i << " -> " << imagem[i] << "\n";
    }
	return 0;
}