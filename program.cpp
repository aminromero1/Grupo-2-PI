#include <iostream>
#include<string>
using namespace std;

// Opcion 1
void agregarCategoria(char Categoria){}//utilizar un cin para pedir el nombre de la categoria y guardar

char categoriaPrincipal[];//array categoria principal

char modificarCategoria(char categoriaPrincipal []){}/*usar cin y for para modificar */

char eliminarCategoria(char categoriaPrincipal []){}/*usar cin y for para eliminar */

const int cantClientes=10;
char agregarPrestatario(char prestatario[cantClientes]){} /*usar cin y for para agregar */

char modificarPrestatario(char prestatario[cantClientes]){} /*usar cin y for para modificar */

char eliminarPrestatario(char prestatario[cantClientes]){} /*usar cin y for para eliminar */

// Opcion 2

char agregarPrestamo(){}//utilizar un cin para pedir el nombre de la categoria y guardar

char modificarPrestamo(){}//utilizar un cin para pedir el nombre de la categoria y guardar

char eliminarPrestamo(){}//utilizar un cin para pedir el nombre de la categoria y eliminar

char devolverPrestamo(){}//utilizar un cin para pedir el nombre de la categoria y guardar

// Opcion 3

char cantObjetosPorCategoria(){}// utilizar un cin para pedir el nombre de la categoria y mostrar la cantidad de objetos

char listadoPrestamosPorCategoria(){}// utilizar un cin para pedir el nombre de la categoria y mostrar los prestamos

char listadoPrestamosPorPrestatario(){}//   utilizar un cin para pedir el nombre del prestatario y mostrar los prestamos

char prestatariosConobjetosPrestados(){}// mostrar los prestatarios que tienen objetos prestados

//***********************

// funcion principal
int main(){
    int opcionPrincipal;//variable que almacena el numero de la opción del menu principal
    char opcionCase1;
    char opcionCase2;
    char opcionCase3;
    const int cantClientes=10;//dimensión fisica
    int codigo=cantClientes;//la cantidad de código de prestatario es la misma que la cantidad de prestatarios
    char categorias;
    string nombreyApellido;
    char prestamo;
    char prestatario[cantClientes]; //sacar de main y   poner dentro de una función asi no ocupa espacio
        do{
            cout << "1. Administrar y consultar Categorías y Prestatarios" << endl;
            cout << "2. Administrar Préstamos" << endl;
            cout << "3. Consultar Préstamos" << endl;
            cout << "ingrese una opcion: ";
            cin >> opcionPrincipal;

            switch (opcionPrincipal)
            {
            case 1:
                do
                {
                    cout << "Administrar y consultar Categorías y Prestatarios" << endl;
                    cout << "  A) Agregar categoría" << endl;
                    cout << "  B) Modificar categoría" << endl;
                    cout << "  C) Eliminar categoría" << endl;
                    cout << "  D) Agregar prestatario" << endl;
                    cout << "  E) Modificar prestatario" << endl;
                    cout << "  F) Eliminar prestatario" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase1;
                    switch (tolower((opcionCase1)))
                    {
                    case 'a':
                        cout << "usted eligio la op 1" << endl; // sacar los cout y poner las funciones
                        agregarCategoria(categorias);
                        break;
                    case 'b':
                        cout << "usted eligio la op 2" << endl;
                        modificarCategoria(categoriaPrincipal);
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        eliminarCategoria(categoriaPrincipal);
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        agregarPrestatario(prestatario);
                        break;
                    case 'e':
                        cout << "usted eligio la op 5" << endl;
                        modificarPrestatario(prestatario);
                        break;
                    case 'f':
                        cout << "usted eligio la op 6" << endl;
                        eliminarPrestatario(prestatario);
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcionCase1 != 'a', opcionCase1 != 'b', opcionCase1 != 'c', opcionCase1 != 'd', opcionCase1 != 'e', opcionCase1 != 'f');
                break;
            case 2:
                do
                {
                    cout << "  Administrar Préstamos" << endl; // AGREAGAR SWITCH ctrl c + ctrl v
                    cout << "  A) Agregar préstamo" << endl;
                    cout << "  B) Modificar préstamo" << endl;
                    cout << "  C) Eliminar préstamo" << endl;
                    cout << "  D) Devolver préstamo" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase2;
                    switch (tolower((opcionCase2)))
                    {
                    case 'a':
                        cout << "usted eligio la op 1" << endl;
                        agregarPrestamo();
                        break;
                    case 'b':
                        cout << "encontraste el secreto" << endl;
                        modificarPrestamo();
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        eliminarPrestamo();
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        devolverPrestamo();
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }

                } while (opcionCase2 != 'a', opcionCase2 != 'b', opcionCase2 != 'c', opcionCase2 != 'd');
                break;
            case 3:
                do
                {
                    cout << "Consultar Préstamos" << endl;
                    cout << "  A) Cantidad de objetos prestados por categoría" << endl;
                    cout << "  B) Listado de préstamos por categoría" << endl;
                    cout << "  C) Listado de préstamos ordenados por categoría o prestatario" << endl;
                    cout << "  D) Listar todos los prestatarios que tienen al menos un objeto prestado" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase3;
                    switch (tolower((opcionCase3)))
                    {
                    case 'a':
                        cout << "usted eligio la op 1" << endl; // sacar los cout y poner las funciones
                        cantObjetosPorCategoria();
                        break;
                    case 'b':
                        cout << "usted eligio la op 2" << endl;
                        listadoPrestamosPorCategoria();
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        listadoPrestamosPorPrestatario();
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        prestatariosConobjetosPrestados();
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcionCase3 != 'a', opcionCase3 != 'b', opcionCase3 != 'c', opcionCase3 != 'd');
                    break;
            default:
                cout << "POR FAVOR INGRESE UNA OPCION VALIDA" << endl;
                break;
            }
        } while (opcionPrincipal != 1, opcionPrincipal != 2, opcionPrincipal != 3);
        
    return 0;
}