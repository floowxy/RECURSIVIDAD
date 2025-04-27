#include<iostream>
using namespace std;
int pedir_numero();
int suma_digitos_recursividad(int n);
void mostrar_resultado(int x);

int pedir_numero(){
    int num;
    cout<<"Digite un numero mayor a 0 : ";
    cin>>num;
    while(num<=0){
        cout<<"Invalido.Digite nuevamente: ";
        cin>>num;
    }
    return num;
}
int suma_digitos_recursividad(int n){
    if( n==0){
        return 0;
    }
    else{
        return (n%10) + suma_digitos_recursividad(n/10);
    }

}
void mostrar_resultado(int m, int n){
    cout<<"La suma de cifras del numero "<<m<<" es : "<<n<<endl;
}
int main(){
    int valor = pedir_numero();
    int suma = suma_digitos_recursividad(valor);
    mostrar_resultado(valor,suma);
    system("pause");
    return 0;
}