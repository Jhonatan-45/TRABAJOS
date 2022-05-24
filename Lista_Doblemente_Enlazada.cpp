#include <iostream>
using namespace std;

class Nodo {

private:
    int dato;
    Nodo* anterior;
    Nodo* siguiente;
public:
    Nodo(int dato)
    {
        this->dato = dato;
        anterior = NULL;
        siguiente = NULL;
    }
    int getDato()
    {
        return dato;
    }
    void setDato(int dato)
    {
        this->dato = dato;
    }
    Nodo* getAnterior()
    {
        return this->anterior;
    }
    Nodo* getSiguiente()
    {
        return this->siguiente;
    }
    void setAnterior(Nodo* anterior)
    {
        this->anterior = anterior;
    }
    void setSiguiente(Nodo* siguiente)
    {
        this->siguiente = siguiente;
    }
};

class Lista_Doble {
    Nodo* inicio;
    Nodo* fin;
public:
    Lista_Doble()
    {
        this->inicio = NULL;
        this->fin = NULL;
    }
    void InsertarAlFinal(int dato)
    {
        Nodo* temp = new Nodo(dato);
        Nodo* auxiliar = this->fin;
        if (EstaVacia())
        {
            inicio = fin = temp;
        }
        else
        {
            if (inicio == fin)
            {
                fin= temp;
                fin->setAnterior(inicio);
                inicio->setSiguiente(fin);
            }
            else
            {
                fin= temp;
                fin->setAnterior(auxiliar);
                auxiliar->setSiguiente(fin);
            }
        }
    }
    void InsertarAlInicio(int dato)
    {
        Nodo* temp = new Nodo(dato);
        Nodo* auxiliar = this->inicio;
        if (EstaVacia())
        {
            inicio = fin = temp;
        }
        else
        {
            if (inicio == fin)
            {
                inicio= temp;
                inicio->setSiguiente(fin);
                fin->setAnterior(inicio);
            }
            else
            {
                inicio= temp;
                inicio->setSiguiente(auxiliar);
                auxiliar->setAnterior(inicio);
            }
        }
    }
    void ImprimirEnLinea()
    {
        Nodo* recorrido = inicio;
        cout << "Lista doblemente enlazada****************************" << endl;
        if (EstaVacia())
        {
            cout << "\nLista vacia" << endl<< endl;
        }
        else
        {
            while (recorrido != NULL)
            {
                cout << recorrido->getDato() << "\t";
                recorrido = recorrido->getSiguiente();
            }
        }
        cout << "****************************" << endl << endl;
        //delete recorrido;
    }
    void Buscar(int datoBuscado)
    {
        bool encontrado = false;
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            if (recorrido->getDato() == datoBuscado)
            {
                cout << "Elemento encontrado en la dirección de memoría: " << recorrido << endl;
                encontrado = true;
                break;
            }
            else
            {
                recorrido = recorrido->getSiguiente();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }
    void EliminarElementoFinal()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (inicio->getSiguiente() == NULL)
            {
                inicio = fin = NULL;
            }
            else
            {
                fin = fin->getAnterior();
                fin->setSiguiente(NULL);
            }

        }

    }
    void EliminarElemento(int elemento)
    {
        bool encontrado = false;
        Nodo* auxiliar_anterior;
        Nodo* auxiliar_siguiente;
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            auxiliar_anterior = recorrido->getAnterior();
            auxiliar_siguiente = recorrido->getSiguiente();

            if (recorrido->getDato() == elemento)
            {
                encontrado = true;
                auxiliar_anterior->setSiguiente(auxiliar_siguiente);
                delete recorrido;
                break;
            }
            else
            {
                recorrido = recorrido->getSiguiente();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento a eliminar no fue encontrado." << endl;
        }
    }
    void EliminarElementoInicio()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            inicio = inicio->getSiguiente();
            inicio->setAnterior(NULL);
        }
    }
    void Vaciar()
    {
        inicio = fin = NULL;
    }
    bool EstaVacia()
    {
        if (inicio == NULL && fin == NULL)
            return true;
        else
            return false;
    }
};

void MostrarMenu()
{
    cout << "1.- Ver el contenido de la lista enlazada" << endl;
    cout << "2.- Insertar un elemento al inicio" << endl;
    cout << "3.- Insertar un elemento al final" << endl;
    cout << "4.- Buscar un elemento" << endl;
    cout << "5.- Eliminar un elemento inicial" << endl;
    cout << "6.- Eliminar un elemento final" << endl;
    cout << "7.- Vaciar la lista" << endl;
    cout << "8.- Eliminar un elemento " << endl;
    cout << "0.- Salir" << endl;
}
int main()
{
    Lista_Doble edades = Lista_Doble();

    int elemento;
    int opcion;
    do
    {
        MostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            cout << "Ingeniería de Sistemas, hasta luego." << endl;
            break;
        case 1:
            edades.ImprimirEnLinea();
            break;
        case 2:
            cout << "Digite el elemento a insertar: " << endl;
            cin >> elemento;
            edades.InsertarAlInicio(elemento);
            break;
        case 3:
            cout << "Digite el elemento a insertar: " << endl;
            cin >> elemento;
            edades.InsertarAlFinal(elemento);
            break;
        case 4:
            cout << "Digite el elemento a buscar: " << endl;
            cin >> elemento;
            edades.Buscar(elemento);
            break;
        case 5:
            edades.EliminarElementoInicio();
            break;
        case 6:
            edades.EliminarElementoFinal();
            break;
        case 7:
            edades.Vaciar();
            break;
        case 8:
            cout << "Digite el elemento a eliminar: " << endl;
            cin >> elemento;
            edades.EliminarElemento(elemento);
            break;
        default:
            cout << "Opción no valida." << endl;
            break;
        }
    } while (opcion != 0);

}