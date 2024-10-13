#include <iostream>
#include <string>

using namespace std;

class red{
private:
    char estaciones;
    int precio_combustible;
public:
    string nombre_red;
    red();
    void agregarEstacion();
    void eliminarEstacion();
    void calcularVentas();
    void fijarPrecios();
    ~red();
};

class estacion{
private:
    int id_estacion;
    string gerente;
    string region;
    string ubicacion;
    int maquinas_espendedoras;
public:
    string nombre_estacion;
    estacion();
    agregarSurtidor();
    eliminarSurtidor();
    activarSurtidor();
    desactivarSurtidor();
    consultarHistorico();
    asignarCapacidad();
    verificarFugas();
    ~estacion();
};

class tanque{
private:
    int id_tanque;
    int capacidad;
public:
    tanque();
    ~tanque();
};

class surtidor{
private:
    int id;
    string modelo_maquina;
    char ventas;
public:
    surtidor();
    void vender();
    ~surtidor();
};

class venta{
private:
    int nro;
    string fecha;
    string hora;
    int cantidad;
    string tipo_combustible;
    string metodo_pago;
    int nro_doc_cliente;
    int valor;
public:
    venta();
    void registrarVenta();
    ~venta();
};

int main()
{
    red miRed;
    cout << "Bienvenido a Red de Servicios " << miRed.nombre_red << endl;
    int op_menu = 1;
    while (op_menu != 0){
        int op_submenu = 1;
        cout << endl << "- Menu principal -" << endl << "Selecione una opcion:" << endl;
        cout << "[1]. Gestion de Red." << endl;
        cout << "[2]. Gestion de Estacion." << endl;
        cout << "[0]. Salir." << endl;
        cin >> op_menu;

        switch (op_menu){
        case 1:
            cout << endl << "- Gestion de Red -" << endl << "Selecione una opcion:" << endl;
            cout << "[1]. Agregar Estacion de Servicios." << endl;
            cout << "[2]. Eliminar Estacion de Servicios." << endl;
            cout << "[3]. Calcular Monto Total de Ventas." << endl;
            cout << "[4]. Fijar Precios de Combustible." << endl;
            cin >> op_submenu;

            switch (op_submenu) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
            }
            break;
        case 2:
            cout << endl << "- Gestion de Estacion -" << endl << "Selecione una opcion:" << endl;
            cout << "[1]. Agregar Surtidor." << endl;
            cout << "[2]. Eliminar Surtidor." << endl;
            cout << "[3]. Activar Surtidor." << endl;
            cout << "[4]. Desactivar Surtidor." << endl;
            cout << "[5]. Consultar Historico de Transacciones." << endl;
            cout << "[6]. Reportar Cantidad de litros vendida." << endl;
            cout << "[7]. Simular Venta." << endl;
            cin >> op_submenu;

            switch (op_submenu) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
            }
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    }
    return 0;
}

red::red(){
    nombre_red = "TerMax";
}

void red::agregarEstacion(){
    cout << "Ingrese el nombre de la estacion:" << endl;
}

red::~red(){

}
