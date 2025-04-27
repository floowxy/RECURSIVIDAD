#include<iostream>
using namespace std;
int pedir_valor_base();
int pedir_valor_exp();
int potencia_recursividad(int x,int y);
void mostrar_resultado(int a, int b, int c);

int pedir_valor_base(){
    int base;
    cout<<"Digite la base y que seas un numero mayor o igual que 0: ";
    cin>>base;
    while(base<0){
        cout<<"Invalido.Digite nuevamente:";
        cin>>base;
    }
    return base;
}
int pedir_valor_exp(){
    int exp;
    cout<<"Digite el exponente y que sea un numero mayor o igual que 0; ";
    cin>>exp;
    while(exp<0){
        cout<<"Invalido.Digite nuevamente:";
        cin>>exp;
    }
    return exp;
}

int potencia_recursividad(int x,int y){
    if(y==0){
        return 1;
    }
    else{
        return x*potencia_recursividad(x,y-1);
    }
}
void mostrar_resultado(int a, int b,int c){
    cout<<"El resultado de"<<a<<"^"<<b<<" es:"<<c<<endl;
}
int main(){
    int valor_b = pedir_valor_base();
    int valor_e = pedir_valor_exp();
    int potencia = potencia_recursividad(valor_b,valor_e);
    mostrar_resultado(valor_b,valor_e,potencia);
    system("pause");
    return 0;
}
