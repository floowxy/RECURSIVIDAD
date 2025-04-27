#include<iostream>
using namespace std;

int pedir_valor();
int factorial_recursividad(int m);
void mostrar_resultado(int x, int y);

int pedir_valor(){
    int num;
    cout<<"Digite un numero mayor o igual que 0:";
    cin>>num;
    while(num<0){
        cout<<"Invalido.Digite nuevamente:";
        cin>>num;
    }
    return num;
}
int factorial_recursividad(int m){
    if(m==0){
        return 1;
    }
    else{
        return m*factorial_recursividad(m-1);
    }
}
void mostrar_resultado(int x, int y){
    cout<<"El factorial de "<<x<<"!  es :"<<y<<endl;
}
int main(){
    int valor = pedir_valor();
    int factorial = factorial_recursividad(valor);
    mostrar_resultado(valor,factorial);
    system("pause");
    return 0;
}