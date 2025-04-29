#include <iostream>
using namespace std;
// Limite a que sea una matriz de 3x3
// y mi exponente maximo sea 10
const int n = 3;
const int max_exp = 10;

int pedir_exponente();
void pedir_matriz(int matriz_base[n][n]);
void copiar_matriz(int matriz_origen[n][n], int matriz_destino[n][n]);
void multiplicar_matrices(int arreglo_1[n][n], int arreglo_2[n][n], int arreglo_3[n][n]);
void potencia_recursiva(int matriz_base[n][n], int matriz_resultado[n][n], int exp);
void imprimir_matriz(int matriz[n][n]);

int pedir_exponente() {
    int exp;
    cout<<"Ingrese el exponente de n (max 10):";
    cin>>exp;
    while (exp < 1 || exp > max_exp) {
        cout << "Invalido. Digite nuevamente (max 10):";
        cin >>exp;
    }
    return exp;
}

void pedir_matriz(int matriz_base[n][n]) {
    cout << "Digite los " << n << "x" << n << " elementos de la matriz:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            cout <<" matriz[" << i << "][" << j << "] = ";
            cin >>matriz_base[i][j];
        }
}

void copiar_matriz(int matriz_origen[n][n],int matriz_destino[n][n]) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matriz_destino[i][j] = matriz_origen[i][j];
        }
    }
}

void multiplicar_matrices(int arreglo_1[n][n],int arreglo_2[n][n],int arreglo_3[n][n]) {
    int matriz_temporal[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matriz_temporal[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n; k++){
            for (int j = 0; j < n; j++){
                matriz_temporal[i][j] += arreglo_1[i][k] * arreglo_2[k][j];
            }
        }
    }
    copiar_matriz(matriz_temporal, arreglo_3);
}

void potencia_recursiva(int matriz_base[n][n],int matriz_resultado[n][n],int exp) {
    if (exp == 1) {
        copiar_matriz(matriz_base, matriz_resultado);
    } 
    else {
        int matriz_anterior[n][n];
        potencia_recursiva(matriz_base, matriz_anterior, exp - 1);
        multiplicar_matrices(matriz_base, matriz_anterior, matriz_resultado);
    }
}

void imprimir_matriz(int matriz[n][n]) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int exp = pedir_exponente();
    int matriz_base[n][n], matriz_resultado[n][n];
    pedir_matriz(matriz_base);
    potencia_recursiva(matriz_base, matriz_resultado, exp);
    cout << "\nM^" << exp << " =\n";
    imprimir_matriz(matriz_resultado);
    return 0;
}