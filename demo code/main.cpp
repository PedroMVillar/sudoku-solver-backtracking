#include <bits/stdc++.h>
using namespace std;

const int N = 9; // Ancho de sudoku
// Tamaño de la matriz del sudoku es NxN

const int lugarvacio = 0; // Espacios vacios



bool buscarVacio(int grid[N][N], int& fila, int& col);
bool esFactible(int grid[N][N], int fila, int col, int num);
bool solucionarSudoku (int grid[N][N]);
bool usadoenFila(int grid[N][N], int fila, int num);
bool usadoenCol(int grid[N][N], int col, int num);
bool usadoen3x3(int grid[N][N], int fila3x3, int col3x3, int num);
void printGrid(int grid[N][N]);

int main() {
    int grid[N][N] = { { 0, 0, 8, 0, 5, 0, 0, 0, 0},
                       { 1, 0, 0, 9, 2, 0, 0, 0, 6},
                       { 0, 6, 0, 0, 0, 0, 0, 7, 0},
                       { 0, 0, 4, 0, 0, 0, 8, 0, 0},
                       { 0, 0, 0, 0, 0, 3, 0, 0, 0},
                       { 2, 0, 0, 1, 6, 0, 0, 0, 7},
                       { 0, 0, 2, 3, 9, 0, 0, 4, 0},
                       { 0, 0, 0, 0, 0, 5, 0, 0, 9},
                       { 3, 0, 0, 0, 0, 7, 0, 0, 0}};
    if(solucionarSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No hay solución";
    return 0;
    
}

bool solucionarSudoku (int grid[N][N]){
    int fila, col;
    if (!buscarVacio(grid, fila, col))
        return true;

    for (int num = 1; num <= 9; num++){
        if(esFactible(grid, fila, col, num)){
            grid[fila][col] = num;
            if(solucionarSudoku(grid)){
                return true;
            }
            grid[fila][col] = lugarvacio;
        }
    }

    return false;
}
//Funcion buscarVacio
//Busca en la matriz una ubicación vacía, si la encuentra, redefine row y col y devuelve true
bool buscarVacio(int grid[N][N], int& fila, int& col){
    for(fila = 0; fila < N; fila++){
        for(col = 0; col < N; col++){
            if (grid [fila][col] == lugarvacio)
                return true;
        }
    }   
    return false;
}

//Funcion usadoenFila
//Verifica si el número ya está en la fila
bool usadoenFila(int grid[N][N], int fila, int num){
    for(int col = 0; col < N; col++)
        if(grid[fila][col] == num)
            return true;
    return false; 
}

//Funcion usadoenCol
//Verifica si el número ya está en la columna
bool usadoenCol(int grid[N][N], int col, int num){
    for(int fila = 0; fila < N; fila++)
        if(grid[fila][col] == num)
            return true;
    return false;
}

//Funcion usadoen3x3
//Verifica si el número ya está en el cuadrado de 3x3
bool usadoen3x3(int grid[N][N], int fila3x3, int col3x3, int num){
    for(int fila = 0; fila < 3; fila++){
        for(int col = 0; col < 3; col++){
            if (grid[fila + fila3x3] [col + col3x3] == num)
                return true;
        }
    }
    return false;
}

//Funcion esFactible
//Verifica si el numero puede ir en la posicion
bool esFactible(int grid[N][N], int fila, int col, int num){
    return !usadoenFila(grid, fila, num) && 
           !usadoenCol(grid, col, num) && 
           !usadoen3x3(grid, fila - fila % 3, col - col % 3, num) && 
           grid[fila][col] == lugarvacio;
}



void printGrid(int grid[N][N]){
    for(int fila = 0; fila < N; fila++){
        for(int col = 0; col < N; col++){
            cout << grid[fila][col] << " ";
        }
        cout << endl;
    }
}

