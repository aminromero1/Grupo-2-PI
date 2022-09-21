#include <iostream>
#include<string>
using namespace std;

//Variables globales fuera de la funcion principal
    int opcionPrincipal;//variable que almacena el numero de la opción del menu principal
    char opcionCase1;
    char opcionCase2;
    char opcionCase3;

    //variables opcion categorias #############################################################################################################

    char categorias[cantCategorias];//sacar de main y   poner dentro de una función asi no ocupa espacio
    const int cantCategorias=50;//dimesion fisica
    int codigoCat=cantCcategorias+1;//el codigo de categoria es la misma que la cantidad de categorias -1 (inicia en 0)
    char prestatario[cantClientes]; //sacar de main y   poner dentro de una función asi no ocupa espacio
    const int cantClientes=50;//dimensión fisica
    int codigoPres=cantClientes+1;//la cantidad de código de prestatario es la misma que la cantidad de prestatarios -1 (inicia en 0)

    //variables opcion prestamo ###############################################################################################################

    const int cantPrestamos=50;
    char prestamos[cantPrestamos];

    //variables opcion consultas ##############################################################################################################

    const int cantObjetos=50;
    char objetosPrestados[cantObjetos];

     string nombreyApellido;

// Opcion 1 = Administrar y consultar Categorías y Prestatarios

void agregarCategoria(char categorias [cantCategorias]){}//utilizar un cin para pedir el nombre de la categoria y guardar

char modificarCategoria(char categorias [cantCategorias]){}//usar cin y for para modificar

char eliminarCategoria(char categorias [cantCategorias]){}//usar cin y for para eliminar

char agregarPrestatario(char prestatario[cantClientes], char prestatario[cantClientes]){} //usar cin y for para agregar

char modificarPrestatario(char prestatario[cantClientes]){} //usar cin y for para modificar

char eliminarPrestatario(char prestatario[cantClientes]){} //usar cin y for para eliminar

// Opcion 2 = Administrar Préstamos

char agregarPrestamo(char prestamos[cantPrestamos]){}//utilizar un cin para pedir el nombre de la categoria y guardar

char modificarPrestamo(char prestamos[cantPrestamos]){}//utilizar un cin para pedir el nombre de la categoria y guardar

char eliminarPrestamo(char prestamos[cantPrestamos]){}//utilizar un cin para pedir el nombre de la categoria y eliminar

char devolverPrestamo(char prestamos[cantPrestamos]){}//utilizar un cin para pedir el nombre de la categoria y guardar

// Opcion 3 = Consultar Préstamos

char cantObjetosPorCategoria(char objetosPrestados[cantObjetos]){}// utilizar un cin para pedir el nombre de la categoria y mostrar la cantidad de objetos

char listadoPrestamosPorCategoria(char objetosPrestados[cantObjetos]){}// utilizar un cin para pedir el nombre de la categoria y mostrar los prestamos

char listadoPrestamosPorPrestatario(char prestamos[cantPrestamos]){}//   utilizar un cin para pedir el nombre del prestatario y mostrar los prestamos

char prestatariosConobjetosPrestados(char prestatario[cantClientes]){}// mostrar los prestatarios que tienen objetos prestados

//#############################################################################################################################################

// funcion principal
int main(){
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
                        agregarCategoria(categorias); // el parametro categoria lo completa el usuario por teclado en el cout
                        cout<<"ingrese el nombre de la nueva categoria: ";
                        cin>>categorias;
                        break;
                    case 'b':
                        cout << "usted eligio la op 2" << endl;
                        modificarCategoria(categorias);// el parametro categoria lo completa el usuario por teclado en el cout
                        //haria un switch para preguntar si desea ver las categorias existentes
                        cout<<"ingrese el nombre de la categoria a modificar: ";
                        cin>>categorias;
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        eliminarCategoria(categorias);// el parametro categoria lo completa el usuario por teclado en el cout
                        //haria un switch para preguntar si desea ver las categorias existentes
                        cout<<"ingrese el nombre de la categoria a eliminar: ";
                        cin>>categorias;
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        agregarPrestatario(prestatarioN, prestatarioP);// el parametro prestatario lo completa el usuario por teclado en el cout
                        cout<<"ingrese el nombre del nuevo prestatario: ";
                        cin>>prestatarioN;//poner toupper para dejar en mayuscula la primer letra
                        cout<<"ingrese el apellido del nuevo prestatario: ";
                        cin>>prestatarioP;//poner toupper para dejar en mayuscula la primer letra
                        break;
                    case 'e':
                        cout << "usted eligio la op 5" << endl;
                        modificarPrestatario(prestatario);// el parametro prestatario lo completa el usuario por teclado en el cout
                        //haria un switch para preguntar si desea ver los prestatarios existentes
                        cout<<"ingrese el nombre de el prestatario a modificar: ";
                        cin>>prestatario;
                        break;
                    case 'f':
                        cout << "usted eligio la op 6" << endl;
                        eliminarPrestatario(prestatario);// el parametro prestatario lo completa el usuario por teclado en el cout
                        //haria un switch para preguntar si desea ver los prestatarios existentes
                        cout<<"ingrese el nombre de el prestatario a eliminar: ";
                        cin>>prestatario;
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
                        agregarPrestamo(prestamos);//el parametro prestamos lo completa el usuario por teclado en el cout
                        cout<<"ingrese el nombre de el nuevo prestamo: ";
                        cin>>prestamos;
                        break;
                    case 'b':
                        cout <<"usted eligio la op 2"<< endl;
                        modificarPrestamo(prestamos);//el parametro prestamos lo completa el usuario por teclado en el cout
                        //haria un switch para preguntar si desea ver los prestamos existentes
                        cout<<"ingrese el nombre de el prestamo a modificar: ";
                        cin>>prestamos;
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        eliminarPrestamo(prestamos);//el parametro prestamos lo completa el usuario por teclado en el cout
                        //haria un switch para preguntar si desea ver los prestamos existentes
                        cout<<"ingrese el nombre de el prestamo a eliminar: ";
                        cin>>prestamos;
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        devolverPrestamo(prestamos);//el parametro prestamos lo completa el usuario por teclado en el cout
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
                        cantObjetosPorCategoria(objetosPrestados);//el parametro objetosPrestados lo completa el usuario por teclado en el cout
                        break;
                    case 'b':
                        cout << "usted eligio la op 2" << endl;
                        listadoPrestamosPorCategoria(objetosPrestados);//el parametro objetosPrestados lo completa el usuario por teclado en el cout
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        listadoPrestamosPorPrestatario(prestamos);//el parametro prestamos lo completa el usuario por teclado en el cout
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        prestatariosConobjetosPrestados(prestatario);//el parametro prestatario lo completa el usuario por teclado en el cout
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