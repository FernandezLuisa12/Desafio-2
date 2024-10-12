#include <iostream>
#include <string>

using namespace std;

class Red{
private:
    Estacion* estaciones[12]; // Maximo de estaciones de servicios
    int precio_combustible;
    int totalEstaciones;
    string nombre_red
public:
    Red(string _nombre_red, int _precio_combustible) {  // Inicializo el constructor 
        totalEstaciones = 0
        precio_combustible = _precio_combustible;
        nombre_red = _nombre_red;
    }

    ~Red() {  // Destructor libera memoria dinamica
        for (int i = 0; i < totalEstaciones; i++) {
            delete estaciones[i];  
        }
    }
    void agregarEstacion( string nombre; long codigo, string gerente, string region; string ubicacionGPS);{
        if (totalEstaciones < 12) {
            estaciones[totalEstaciones] = new Estacion(nombre, codigo, gerente, region, ubicacionGPS);
            totalEstaciones++;
        }  
    }

  // Metodo para eliminar una estacion por su codigo
    void eliminarEstacion(long codigo) {
        bool encontrado = false;
        for (int i = 0; i < totalEstaciones; i++) {
            if (this -> estaciones[i]->codigo == codigo) {  // accedemos -> a la estacion atraves del codigo 
                delete estaciones[i];  // Elimina la estacion
                for (int j = i; j < totalEstaciones - 1; j++) {
                    estaciones[j] = estaciones[j + 1];  // Reorganizar el arreglo
                }
                estaciones[totalEstaciones - 1] = nullptr; // libera el espacio de memoria
                totalEstaciones -= 1
                encontrado = true;
                cout << "Estacion eliminada correctamente." << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "Estacion con codigo " << codigo << " no encontrada." << endl;
        }
    }
    
    void calcularVentas(){
        cout << "Calculando ventas para las " << totalEstaciones << " estaciones de la red..." << endl;
        for (int i = 0; i < totalEstaciones; i++) {
            cout << "Estacion: " << this -> estaciones[i]->nombre << " (Codigo: " << this -> estaciones[i]->codigo << ")" << endl;
            // Aqui podrias agregar logica para calcular ventas, por ejemplo, simulando un valor.
        }
    }
    
    void fijarPrecios(int nuevo_precio);{
        precio_combustible = nuevo_precio;
        cout << "El nuevo precio del combustible es: " << precio_combustible << " por litro." << endl;
    }
    
    void mostrarEstaciones() {
        cout << "Red: " << nombre_red << endl;
        for (int i = 0, i < totalEstaciones; i++){
             cout << "Estacion " << i + 1 << ": " << estaciones[i]->nombre 
                 << ", Codigo: " << estaciones[i]->codigo 
                 << ", Gerente: " << estaciones[i]->gerente 
                 << ", Region: " << estaciones[i]->region << endl;
        }
    }

    // Metodo para mostrar informacion de la red y sus estaciones
    void mostrarEstaciones() const {
        cout << "Red: " << nombre_red << endl;
        for (int i = 0; i < totalEstaciones; i++) {
            cout << "Estación " << i + 1 << ": " << estaciones[i]->nombre 
                 << ", Código: " << estaciones[i]->codigo 
                 << ", Gerente: " << estaciones[i]->gerente 
                 << ", Región: " << estaciones[i]->region << endl;
        }
    }
}

class Estacion{
private:
    int id_estacion;
    string gerente;
    string region;
    string ubicacion;
    int maquinas_espendedoras;
public:
    string nombre_estacion;
    Estacion();
    agregarSurtidor();
    eliminarSurtidor();
    activarSurtidor();
    desactivarSurtidor();
    consultarHistorico();
    asignarCapacidad();
    verificarFugas();
    ~Estacion();
};

class Tanque{
private:
    int id_tanque;
    int capacidad;
public:
    Tanque();
    ~Tanque();
};

class Surtidor{
private:
    int id;
    string modelo_maquina;
    char ventas;
public:
    Surtidor();
    void vender();
    ~Surtidor();
};

class Venta{
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
    Venta();
    void registrarVenta();
    ~Venta();
};
int main()
{
    Red miRed;
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

red::~Red(){

}
