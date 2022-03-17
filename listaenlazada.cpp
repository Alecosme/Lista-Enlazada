#include<iostream>
using namespace std;


struct Nodo{
int valor;
Nodo *NextNode;

};



//listado de funciones
void opciones();
void Insert(Nodo *&,int);
void printlist(Nodo *);
void buscarLista(Nodo *,int);
void eliminarNodo(Nodo *&, int);

Nodo *lista = NULL;

int main()
{
int k;
cout << "******************************************* \n";
cout << "*Programa para simular una lista enlazada* \n";
cout << "******************************************* \n";
opciones();
// int valor;
// cout << " escriba la cantidad de valores que quiere ingresar: \n";
// cin >> k;
//   for(int i = 0; i < k; i++)
//               {
// cout << " digite un numero: \n";
// cin >> valor;
// Insert(lista,valor);
//                 }
// printlist(lista);







return 0;
}
void opciones()
{
int opcion;
int valor;
int k;
do
{
cout << endl;
cout << " opciones " << endl;
cout << " 1- insertar elemento a la lista \n";
cout << " 2- Mostrar los elementos de la lista \n";
cout << " 3- buscar un elemento \n";
cout << " 4- eliminar un valor \n";
cout << " 5- Salir \n";
cout << " Digite el numero de la opcion que desea hacer: \n";
cin >> opcion;

switch(opcion)
{
case 1:
// int valor;
cout << " escriba la cantidad de valores que quiere ingresar: \n";
cin >> k;
for(int i = 0; i < k; i++)
{
cout << " digite un numero: \n";
cin >> valor;
Insert(lista,valor);
}


break;
case 2:
cout << endl << " Los elementos ingresados son: \n";
printlist(lista);
cout << endl;
break;
case 3:
cout << " digite un numero para buscar \n";
cin >> valor;
buscarLista(lista,valor);
cout << endl;
break;
case 4:
cout << " Digite el elemento que desea borrar: \n";
cin >> valor;
eliminarNodo(lista, valor);
cout << endl;




break;
}

}while(opcion != 5);

}

void Insert(Nodo *&lista,int n)
{
Nodo *nuevo_nodo = new Nodo();
nuevo_nodo-> valor = n;
Nodo *Nodoauxiliar1= lista;
Nodo *Nodoauxiliar2;
while((Nodoauxiliar1 != NULL) && (Nodoauxiliar1->valor < n))
{
Nodoauxiliar2 = Nodoauxiliar1;
Nodoauxiliar1 = Nodoauxiliar1->NextNode;
}

if (lista ==Nodoauxiliar1)
{
lista = nuevo_nodo;
}
else
{
Nodoauxiliar2->NextNode = nuevo_nodo;


}
nuevo_nodo-> NextNode = Nodoauxiliar1;
cout << " El numero " << n << " esta agregado en la lista enlazada \n" << endl;

}

void printlist(Nodo *lista)
{
Nodo *actual = new Nodo();
actual = lista;
while (actual != NULL)
{
cout << actual-> valor << " , " ;
actual =actual-> NextNode;
}


}
void buscarLista(Nodo *lista, int n)
{
int i = 0;
bool band = false;
Nodo *actual = new Nodo();
actual = lista;
while ((actual != NULL) && (actual -> valor <= n))
{
if (actual -> valor == n)
{
band = true;
}
actual = actual-> NextNode;
i++;

}
if (band == true )
{
cout << " elemento  " << n << " ha sido encontrado en la posicion " << i <<   endl ;
}

else
{
cout << " elemento  " << n << "  no ha sido encontrado " << endl ;
}

}

void eliminarNodo(Nodo *&lista, int n)
{
if (lista != NULL)
{
Nodo *auxborrar;
Nodo *anterior = NULL;
auxborrar = lista;

while ((auxborrar != NULL) && (auxborrar->valor != n))
{
  anterior = auxborrar;
  auxborrar= auxborrar->NextNode;
}

if (auxborrar == NULL)
{
cout << " El elemento no ha sido borrado \n";
}
else if (anterior == NULL )
{
lista = lista-> NextNode;
delete auxborrar;
}
else
{
anterior-> NextNode = auxborrar-> NextNode;
delete auxborrar;
}
}

}
