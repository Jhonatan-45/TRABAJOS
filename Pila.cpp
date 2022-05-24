#include <iostream>
using namespace std;

class Nodo {

private:
    int dato;
    Nodo* enlace;
public:
    
    Nodo(int dato)
    {
        this->dato = dato;
        enlace = NULL;
    }
    
    int getDato()
    {
        return dato;
    }
    void setDato(int dato)
    {
        this->dato = dato;
    }
    Nodo* getEnlace()
    {
        return this->enlace;
    }
    void setEnlace(Nodo* enlace)
    {
        this->enlace = enlace;
    }
};

class Lista {
    Nodo* inicio;
public:

    Lista()
    {
        this->inicio = NULL;
    }
    Nodo* get_Inicio()
    {
        return this->inicio;
    }
    void Insertar_Final(int dato)
    {
        Nodo* temp = new Nodo(dato);
        if (Lista_Vacia())
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            while (recorrido->getEnlace() != NULL)
            {
                recorrido = recorrido->getEnlace();
            }
            recorrido->setEnlace(temp);
        }
    }
    
    void Imprimir_Lista()
    {
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            cout << recorrido->getDato() << "\t";
            recorrido = recorrido->getEnlace();
        }
        cout << "\n****************************" << endl << endl;
    }
    int Eliminar_Final()
    {
        if (Lista_Vacia())
        {
            return NULL;
        }
        else
        {
            int datoEliminar = 0;
            if (inicio->getEnlace() == NULL)
            {
                datoEliminar = inicio->getDato();
                inicio = NULL;
            }
            else
            {
                Nodo* recorrido = inicio;
                while (recorrido->getEnlace() != NULL)
                {
                    if (recorrido->getEnlace()->getEnlace() != NULL)
                        recorrido = recorrido->getEnlace();
                    else
                        break;
                }
                cout << endl;
                datoEliminar = recorrido->getEnlace()->getDato();
                recorrido->setEnlace(NULL);
            }

        }

    }
    bool Lista_Vacia()
    {
        if (inicio == NULL)
            return true;
        else
            return false;
    }
};

class Pila
{

private:
    Lista elementos;

public:
    Pila()
    {
        elementos = Lista();
    }
    bool Pila_Vacia()
    {
        if (elementos.get_Inicio() == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Insertar(int elemento)
    {
        elementos.Insertar_Final(elemento);
    }
    int Quitar()
    {
        if (Pila_Vacia())
        {
            cout << "No hay en elementos en la pila" << endl;
            return NULL;
        }
        else
        {
            return elementos.Eliminar_Final();
        }
    }
    void Imprimir()
    {   
        cout << "########## PILA ##########" << endl;
        cout << "\n****************************" << endl;
        elementos.Imprimir_Lista();
    }
};

void Menu()
{
    cout << "1) Insertar elemento " << endl;
    cout << "2) Quitar elemento " << endl;
    cout << "3) Imprimir pila " << endl;
    cout << "0) Salir " << endl;
}

int main()
{
    int opcion = 0;
    int elemento = 0;
    Pila pila = Pila();
    do
    {
        Menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese el elemento" << endl;
            cin >> elemento;
            pila.Insertar(elemento);
            break;
        case 2:
            cout << "El elemento quitado es: " << pila.Quitar() << endl;
            break;
        case 3:
            pila.Imprimir();
            break;

        default:
            cout << "opción no valida" << endl;
            break;
        }
    } while (opcion != 0);

}