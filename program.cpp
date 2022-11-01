#include <iostream>
#include <string>
using namespace std;

// ****************************************
int dlCategorias = 0;
int dlprestamos = 0;
int dlprestatarios = 0;
int df=15;
const int MAX=15;

// Structs
struct Categoria{
    int codigoCategoria;
    string descripcion;
};

struct Prestatario{
    int codigoPrestatario;
    string nombre;
    string apellido;
};

struct Prestamo{
    struct Categoria categoria;
    struct Prestatario prestatario;
    string descripcion;
    bool estado;
};
// ***********************************************
// Variables
int opcionPrincipal;
char opcionCase;
string descripcion;

// ***********************************************
Prestatario prestatarios[15];
Prestamo prestamos[15];
Categoria categorias[15]; 

// ***********************************************
// Opcion 1 = Administrar y consultar Categorías y Prestatarios

int agregarCategoria(Categoria categorias[], int &dlCategorias){
    // el codigo de la categoria es el indice del array
    string descripcion;
    categorias[dlCategorias].codigoCategoria = dlCategorias;
    cout<<"Ingrese la descripcion de la categoria(X para salir): ";
    cin>>descripcion;

    while(descripcion != "X" && dlCategorias < MAX){
        categorias[dlCategorias].descripcion = descripcion;
        cout << "Categoria agregada con exito \nodigo: " << dlCategorias << endl;
        dlCategorias++;
        categorias[dlCategorias].codigoCategoria = dlCategorias;
        cout<<"Ingrese la descripcion de la categoria(X para salir): ";
        cin>>descripcion;
    }
    return dlCategorias;
} 

int modificarCategoria(Categoria categorias[], int &dlCategorias){
    int codigo_mod;
    string nueva_desc;
 
    cout<<"ingrese el codigo de la categoria a modificar: ";
    cin>>codigo_mod;
    for (int i=0; i=dlCategorias; i++){
        if(codigo_mod==dlCategorias){
            cout<<"ingrese la nueva descripcion de la categoria:";
            cin>>nueva_desc;
            categorias[dlCategorias].descripcion = nueva_desc;
        }
        else{
            cout<<"la categoria seleccionada no existe"<<endl;
        }
    }
    return 1;
}

void eliminarCategoria(Categoria categorias[], int &dlCategorias, Prestamo prestamos[], int &dlprestamos, int codigoCategorias){
    cout << "Eliminar categoria" << endl;
    codigoCategorias;
    cout << "Ingrese el codigo de la categoria a eliminar: ";
    cin >> codigoCategorias;

    if(existePrestamo(prestamos, dlprestamos, codigoCategorias) == false){
        for(int i = 0; i < dlCategorias; i++){
            if(categorias[i].codigoCategoria == codigoCategoria){
                for(int j = i; j < dlCategorias; j++){
                    categorias[j] = categorias[j+1];
                }
                dlCategorias--;
                cout << "Categoria eliminada con exito" << endl;
                break;
            }
        }
    }
    else{
        cout << "No se puede eliminar la categoria porque tiene prestamos asociados" << endl;
    }
    
}
// funcion secundaria a EliminarCategoria
// funcion ExistePrestamo para saber si hay algun prestamo con la categoria a eliminar
bool existePrestamo(Prestamo prestamos[], int codigoCategorias){
    for(int i=0; i < dlprestamos; i++)
        if(prestamos[i].categoria.codigoCategoria == codigoCategorias)
            return true;
    return false;
}

void agregarPrestatario(){
    cout << "Agregar prestatario" << endl;
    //pide al usuario cargar un prestatario
}

void modificarPrestatario(){
    cout << "Modificar prestatario" << endl;
    //muestra todos los prestatarios existentes
    //el usuario selecciona el prestatario a modificar
}

void eliminarPrestatario(){
    cout << "Eliminar prestatario" << endl;
    //muestra todos los prestatarios existentes
    //el usuario selecciona el prestatario a eliminar
} 

// Opcion 2 = Administrar Préstamos

void agregarPrestamo(){
    cout << "Agregar prestamo" << endl;
    //pide al usuario cargar un prestamo
}

void modificarPrestamo(){
    cout << "Modificar prestamo" << endl;
    //muestra todas los prestamos existentes
    //el usuario selecciona el prestamo a modificar
}

void eliminarPrestamo(){
    cout << "Eliminar prestamo" << endl;
    //muestra todas los prestamos existentes
    //el usuario selecciona el prestamo a eliminar
}

void devolverPrestamo(){
    cout << "Devolver prestamo" << endl;
    //muestra todas los prestamos existentes
    //se modifica el estado del prestamo seleccionado
}

// Opcion 3 = Consultar Préstamos

void cantObjetosPorCategoria(){
    cout << "Cantidad de objetos por categoria" << endl;
    //muestra muestra todos los objetos existentes en cada categoria
}

void listadoPrestamosPorCategoria(){
    cout << "Listado de prestamos por categoria" << endl;
    //muestra el listado de objetos por categoria
}

void listadoPrestamosPorPrestatario(){
    cout << "Listado de prestamos por prestatario" << endl;
    //muestra el listado de prestamos por prestatario
}

void prestatariosConobjetosPrestados(){
    cout << "Prestatarios con objetos prestados" << endl;
    //muestra un listado de prestatarios que tengan uno o mas objetos prestados
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
                        agregarCategoria(categorias, dlCategorias);
                        break;
                    case 'b':
                        modificarCategoria(categorias, dlCategorias);
                        break;
                    case 'c':
                        eliminarCategoria(categorias, dlCategorias);             
                        break;
                    case 'd':
                        agregarPrestatario();
                        break;
                    case 'e':
                        modificarPrestatario();
                        break;
                    case 'f':
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
                        agregarPrestamo();                     
                        break;
                    case 'b':
                        modificarPrestamo();
                        break;
                    case 'c':
                        eliminarPrestamo();
                        break;
                    case 'd':
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
                        cantObjetosPorCategoria();
                        break;
                    case 'b':
                        listadoPrestamosPorCategoria();
                        break;
                    case 'c':
                        listadoPrestamosPorPrestatario();
                        break;
                    case 'd':
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