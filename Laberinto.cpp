#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool sePuede(int n, int m, int x, int y){return (x>=0 && y>=0 && x<n && y<m);}

bool resolverMaze(vector<vector<int>> matriz){

    int filas = matriz.size();
    int columnas = matriz[0].size();

    int sX = filas-1;
    int sY = columnas-1;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    queue<pair<int,int>> cola;

    cola.push({0,0});

    while(!cola.empty()){

        int x = cola.front().first;
        int y = cola.front().second;

        cola.pop();

        for(int i = 0; i<4; i++){

            int nX = x + dx[i];
            int nY = y +dy[i];

            if(nX == sX && nY == sY){return true;}

            if(sePuede(filas,columnas,nX,nY)){
                if(matriz[nX][nY] == 0){

                cola.push({nX,nY});

                matriz[nX][nY] = 1;


                }
            }


        }







    }

    return false;

}




int main(){

    vector<vector<int>> matriz = {
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,0,1,1},
        {0,0,0,0,0,0,1,0},
        {0,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
    };

    cout<<resolverMaze(matriz)<<endl;


    return 0;
}