#include <iostream>
#include <string>
using namespace std;

// ****************************************
// Structs
struct Categoria{
    int codigoCategoria;
    string descriptcion;
};

struct Prestatario{
    int codigoPrestatario;
    string nombre;
    string apellido;
};

struct Prestamo{
    struct Categoria categoria;
    struct Prestatario prestatario;
    string description;
    bool estado;
};
// ***********************************************
// Variables
int opcionPrincipal;
char opcionCase;

string prestamos[15];

string prestatarios[15];

string categorias[15];

// ***********************************************
// Opcion 1 = Administrar y consultar Categorías y Prestatarios

void agregarCategoria(){
    cout << "Agregar categoria" << endl;
}

void modificarCategoria(){
    cout << "Modificar categoria" << endl;
}

void eliminarCategoria(){
    cout << "Eliminar categoria" << endl;
}

void agregarPrestatario(){
    cout << "Agregar prestatario" << endl;
}

void modificarPrestatario(){
    cout << "Modificar prestatario" << endl;
}

void eliminarPrestatario(){
    cout << "Eliminar prestatario" << endl;
} 

// Opcion 2 = Administrar Préstamos

void agregarPrestamo(){
    cout << "Agregar prestamo" << endl;
}

void modificarPrestamo(){
    cout << "Modificar prestamo" << endl;
}

void eliminarPrestamo(){
    cout << "Eliminar prestamo" << endl;
}

void devolverPrestamo(){
    cout << "Devolver prestamo" << endl;
}

// Opcion 3 = Consultar Préstamos

void cantObjetosPorCategoria(){
    cout << "Cantidad de objetos por categoria" << endl;
}

void listadoPrestamosPorCategoria(){
    cout << "Listado de prestamos por categoria" << endl;
}

void listadoPrestamosPorPrestatario(){
    cout << "Listado de prestamos por prestatario" << endl;
}

void prestatariosConobjetosPrestados(){
    cout << "Prestatarios con objetos prestados" << endl;
}

//***############################################################################################################################################

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
                    cin >> opcionCase;
                    switch (tolower((opcionCase)))
                    {
                    case 'a':
                        cout << "usted eligio la op 1" << endl;
                        agregarCategoria();
                        break;
                    case 'b':
                        cout << "usted eligio la op 2" << endl;
                        modificarCategoria();
                        break;
                    case 'c':
                        cout << "usted eligio la op 3" << endl;
                        eliminarCategoria();                       
                        break;
                    case 'd':
                        cout << "usted eligio la op 4" << endl;
                        agregarPrestatario();
                        break;
                    case 'e':
                        cout << "usted eligio la op 5" << endl;
                        modificarPrestatario();
                        break;
                    case 'f':
                        cout << "usted eligio la op 6" << endl;
                        eliminarPrestatario();
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcionCase != 'a', opcionCase != 'b', opcionCase != 'c', opcionCase != 'd', opcionCase != 'e', opcionCase != 'f');
                break;
            case 2:
                do
                {
                    cout << "  Administrar Préstamos" << endl;
                    cout << "  A) Agregar préstamo" << endl;
                    cout << "  B) Modificar préstamo" << endl;
                    cout << "  C) Eliminar préstamo" << endl;
                    cout << "  D) Devolver préstamo" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase;
                    switch (tolower((opcionCase)))
                    {
                    case 'a':
                        cout << "usted eligio la op 1" << endl;
                        agregarPrestamo();                     
                        break;
                    case 'b':
                        cout <<"usted eligio la op 2"<< endl;
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
                } while (opcionCase != 'a', opcionCase != 'b', opcionCase != 'c', opcionCase != 'd');
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
                    cin >> opcionCase;
                    switch (tolower((opcionCase)))
                    {
                    case 'a':
                        cout << "usted eligio la op 1" << endl;
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
                } while (opcionCase != 'a', opcionCase != 'b', opcionCase != 'c', opcionCase != 'd');
                    break;
            default:
                cout << "POR FAVOR INGRESE UNA OPCION VALIDA" << endl;
                break;
            }
        } while (opcionPrincipal != 1, opcionPrincipal != 2, opcionPrincipal != 3);
        
    return 0;
}