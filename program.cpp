#include <iostream>
#include <string>
using namespace std;

// ****************************************
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

int dlCategorias = 0;
int dlprestamos = 0;
int dlpreatatarios = 0;
int df=15;

Prestatario prestatarios[15];
Prestamo prestamos[15];
Categoria categorias[15]; //categoria struct, categoriaS array
//dentro de categoria hay descrip y codigo
// ***********************************************
// Opcion 1 = Administrar y consultar Categorías y Prestatarios

string agregarCategoria(categorias, dlCategorias){
    cout<<"ingrese la descripcion de la categoria: ";
    cin>>descripcion;
    for(int i=0; i<descripcion.length(); i++){
        descripcion[i]=toupper(descripcion[i]);
    }
    Categoria[dlCategorias].descripcion= descripcion;
    Categoria.codigoCategoria=dlCategorias;
    dlCategorias++;
    return Categoria.codigoCategoria;
}

void modificarCategoria(){
    cout << "Modificar categoria" << endl;
    //muestra todas las categorias existentes
    //el usuario selecciona la categoria a modificar
}

void eliminarCategoria(){
    cout << "Eliminar categoria" << endl;
    //muestra todas las categorias existentes
    //el usuario selecciona la categoria a eliminar
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

int opcionPrincipal;
char opcionCase;
string descripcion;

int dlCategorias = 0;
int dlprestamos = 0;
int dlpreatatarios = 0;
int df=15;

Prestatario prestatarios[15];
Prestamo prestamos[15];
Categoria categorias[15];
//########################################################################################################
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
                        cout<<agregarCategoria(categorias, dlCategorias);
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
                        cout <<"usted eligio la op 1"<< endl;
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