#include <iostream>
using namespace std;

int fibonacci(int numero)
{

    if (numero == 1 || numero == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(numero - 1) + fibonacci(numero - 2);
    }
}

int main()
{
    int numero;
    
    cout<<"*************** FIBONACCI RECURSIVO ***************"<<endl;
    cout<<"Ingrese un numero: ";
    cin >> numero;
    cout << "\nEl fibonacci de " << numero << " es: "<<endl;
    
    for (int i = 1; i <= numero; i++)
    {
        cout<< fibonacci(i)<<" ";
    }
    
}