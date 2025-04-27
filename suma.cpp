#include<iostream>
using namespace std;
int pedir_numero();
int suma_recursiva(int x);
void mostrar_suma(int m, int n);

int pedir_numero(){
    int num;
    cout<<"Digite un numero:";
    cin>>num;
    while(num<0){
        cout<<"invalido.Digite nuevamente:";
        cin>>num;
    }
    return num;
}
int suma_recursiva(int x){
    if(x==0){
        return 0; 
    }
    else{
        return x + suma_recursiva(x-1);
    }
}

void mostrar_suma(int m, int n){
    cout<<"La suma de los primeros "<<m<<" numeros naturales es: "<<n<<endl;
}

int main(){
    int valor = pedir_numero();
    int suma = suma_recursiva(valor);
    mostrar_suma(valor,suma);
    system("pause");
    return 0;
}