//Bibliotecas a serem utilizadas:
#include <iostream>
#include <vector>
#include <algorithm>
#define m 8 //Definição do número de arestas que serão lidos no grafo.

using namespace std;

int main(){
    vector<pair<int, pair<int,int>>> G; //Lista que irá conter as arestas e seus respectivos pesos. {Peso, {v1, v2}}.
    vector<pair<int, pair<int,int>>> AGM; //Lista que receberá as arestas que comporão a AGM.
    int N, v1, v2, P;
    bool c = false;
    cin >> N; //Leitura do número de vértices.
    int v[N+1] = {};
    vector<int> adj[N+1];
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2 >> P; //Leitura da aresta e seu peso.
        G.push_back({P, {v1, v2}});
    }
    sort(G.begin(), G.end()); //Ordenação do grafo em ordem crescente em relação aos pesos.
    //A ideia segue o algoritmo de Kruskal, onde a cada adição de arestas, verifico a existência de ciclos.
    for(int i = 0; i < m; i++){
        //Adição de uma aresta a AGM.
        AGM.push_back(G[i]);
        adj[G[i].second.first].push_back(G[i].second.second);
        adj[G[i].second.second].push_back(G[i].second.first);
        v[G[i].second.first]++;
        v[G[i].second.second]++;
        //Verificação das cardinalidades de cada vértice adjacente ao primeiro vértice da aresta. 
        for(int j = 0; j < adj[G[i].second.first].size(); j++){
            if(v[adj[G[i].second.first][j]] == 1){
                c = true;
                break;
            }
        }
        //Verificação das cardinalidades de cada vértice adjacente ao segundo vértice da aresta.
        for(int j = 0; j < adj[G[i].second.second].size(); j++){
            if(c == true) break; //Sinalização de que não há formação de ciclo com relação ao primeiro vértice da aresta.
            if(v[adj[G[i].second.second][j]] == 1){
                break;
            }else if(v[adj[G[i].second.second][j]] != 1 && j == adj[G[i].second.second].size() - 1){
                //Caso formação de ciclo, remoção da aresta adicionada.
                AGM.pop_back();
                adj[G[i].second.first].pop_back();
                adj[G[i].second.second].pop_back();
                v[G[i].second.first]--;
                v[G[i].second.second]--;
            }
        }
        c = false;
    }
    //Impressão da AGM.
    for(int i = 0; i < AGM.size(); i++){
        cout << AGM[i].second.first << " " << AGM[i].second.second << " " << AGM[i].first << endl;
    }
    return 0;
}
