#include <iostream>
#include <string>
using namespace std;

class Tanque{
private:
    int id_tanque;
    int capacidad;
public:
    Tanque();
    ~Tanque();
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

class Surtidor{
private:
    int id;
    string modelo_maquina;
    float ventas;

public:
    Surtidor(int _id, string _modelo);
    int obtenerId() const {
        return id;
    }
    void vender(float cantidad);
    float obtenerVentas() const { // metodo para total de ventas
        return ventas; // Total de ventas
    }
    ~Surtidor(){//Destructor
        cout<< "Destructor del Surtidor ID " << id << " llamado." << endl;
    }
};

class Estacion {
private:
    long id_estacion;
    string gerente;
    string region;
    string ubicacion;
    int maquinas_espendedoras; // Total de surtidores
    string nombre_estacion;
    Surtidor** surtidores; // Puntero a un arreglo de punteros a Surtidor
    int max_surtidores;    // Maximo numero de surtidores permitidos
    int contar_surtidores; // Contador de surtidores activos

public:
    // Constructor
    Estacion(string, long, string, string, string, int);
    // Métodos getter
    string getNombreEstacion() const {
        return nombre_estacion;
    }
    string getGerente() const {
        return gerente;
    }
    string getRegion() const {
        return region;
    }
    long getid_Estacion(){
        return id_estacion;
    }
    void agregarSurtidor( string modelo);
    void eliminarSurtidor(int id);
    void activarSurtidor(int id );
    void desactivarSurtidor(int id );
    // consultarHistorico();
    //asignarCapacidad();
    //verificarFugas();
    ~Estacion();
};

class Red{
private:
    Estacion* estaciones[12]; // Maximo de estaciones de servicios
    string precio_combustible;
    int totalEstaciones;
    string nombre_red;
public:
    Red(string _nombre_red, int _precio_combustible);
    ~Red();
    void agregarEstacion();
    void eliminarEstacion(long codigo); // Metodo para eliminar una estacion por su codigo
    void calcularVentas();
    void fijarPrecios();
    // Metodo para mostrar informacion de la red y sus estaciones
    void mostrarEstaciones() const;
};

int main() {
    Red miRed("TerMax", 10000);
    cout << "Bienvenidos a la red de Servicios TerMax" << endl;

    int op_menu = 1;
    while (op_menu != 0) {
        cout << "\n- Menu principal -" << endl;
        cout << "[1] Gestion de Red" << endl;
        cout << "[2] Gestion de Estacion" << endl;
        cout << "[0] Salir" << endl;
        cin >> op_menu;

        switch (op_menu) {
        case 1: {
            int op_submenu;
            cout << "- Gestion de Red -" << endl;
            cout << "[1] Agregar Estacion" << endl;
            cout << "[2] Eliminar Estacion" << endl;
            cout << "[3] Calcular Ventas" << endl;
            cout << "[4] Fijar Precios" << endl;
            cin >> op_submenu;

            switch (op_submenu) {
            case 1: {
                miRed.agregarEstacion();
                break;
            }
            case 2: {
                long codigo;
                cout << "Ingrese el código de la estacion a eliminar: ";
                cin >> codigo;
                miRed.eliminarEstacion(codigo);
                break;
            }
            case 3:
                miRed.calcularVentas();
                break;
            case 4: {
                miRed.fijarPrecios();
                break;
            }
            }
            break;
        }

        case 2: {
            int op_submenu;
            cout << "- Gestion de Estacion -" << endl;
            cout << "[1] Agregar Surtidor" << endl;
            cout << "[2] Eliminar Surtidor" << endl;
            cin >> op_submenu;

            switch (op_submenu) {
            case 1: {
                string modelo;
                cout << "Ingrese el modelo del surtidor: ";
                cin >> modelo;
                // Aquí deberías tener una referencia a una estación específica para agregar el surtidor.
                // Por simplicidad, este ejemplo no está asociado a una estación concreta.
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese el ID del surtidor a eliminar: ";
                cin >> id;
                // Similarmente, aquí debería hacerse la búsqueda del surtidor en una estación específica.
                break;
            }
            }
            break;
        }

        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;

        default:
            cout << "Opción no válida." << endl;

        }
    }
    return 0;
}

Surtidor::Surtidor(int _id, string _modelo){
    id =_id;
    modelo_maquina = _modelo;
    ventas = 0.0;
}

void Surtidor::vender(float cantidad){
    if (cantidad > 0 ){
        ventas += cantidad; //Acumula cantidad vendida
        cout<<  "Venta realizada en el surtidor ID " << id << ". Total vendido: " << ventas << " unidades." << endl;
    }
}

Estacion::Estacion(string _nombre, long _id, string _gerente, string _region, string _ubicacion, int _max){
    nombre_estacion = _nombre;
    id_estacion = _id;
    gerente = _gerente;
    region = _region;
    ubicacion = _ubicacion;
    maquinas_espendedoras = 0;
    contar_surtidores = 0;
    max_surtidores = _max;
    surtidores = new Surtidor*[max_surtidores]; // reserva de memoria para los surtidores
}

void Estacion::agregarSurtidor(string modelo){
    if (contar_surtidores < max_surtidores){
        surtidores[contar_surtidores] = new Surtidor(contar_surtidores +1, modelo);
        contar_surtidores ++;
        maquinas_espendedoras ++;
        cout << "Se ha agregado exitosamente un surtidor. Modelo " << modelo << ". Total de surtidores: " << contar_surtidores << endl;
    }
}

void Estacion::eliminarSurtidor(int id){
    for (int i = 0; i < contar_surtidores; i++){
        if (surtidores[i] -> obtenerId()  == id) {
            if (surtidores[i]->obtenerVentas() == 0) {
                delete surtidores[i];
                for(int j = i; j < contar_surtidores -1; j++){
                    surtidores [j] = surtidores [j + 1]; // reorganizar el arreglo
                }
                contar_surtidores --;
                maquinas_espendedoras --;
                cout << "El surtidor con ID " << id << " fue eliminado. El total de surtidores actual es " << contar_surtidores << endl;
                return;
            }
        }
        cout << "Surtidor con ID " << id << " no encontrado." << endl;}
}

void Estacion::activarSurtidor(int id){
    for (int i = 0; i < contar_surtidores; i++) {
        if (surtidores[i] -> obtenerId() == id) {
            cout << "Surtidor con ID " << id << " activado." << endl;
            return;
        }
    }
    cout << "Surtidor con ID " << id << " no encontrado." << endl;
}

void Estacion::desactivarSurtidor(int id){
    for (int i = 0; i < contar_surtidores; i++) {
        if ( surtidores[i] -> obtenerId()== id) {
            cout << "Surtidor con ID " << id << " desactivado." << endl;
            return;
        }
    }
    cout << "Surtidor con ID " << id << " no encontrado." << endl;
}

Estacion::~Estacion(){
    for (int i = 0; i < contar_surtidores; i++){
        delete surtidores[i]; // libera la memoria de los surtidores
    }
    delete[] surtidores;
}

Red::Red(string _nombre_red, int _precio_combustible) {  // Inicializo el constructor
    totalEstaciones = 0;
    precio_combustible = _precio_combustible;
    nombre_red = _nombre_red;
}

Red::~Red() {  // Destructor libera memoria dinamica
    for (int i = 0; i < totalEstaciones; i++) {
        delete estaciones[i];
    }
}

void Red::agregarEstacion() {
    if (totalEstaciones <= 12) {
        string nombre, gerente, region, ubicacionGPS;
        long codigo;
        int op_region = 1;
        cout << "Ingrese el nombre de la estacion: ";
        cin >> nombre;
        cout << "Ingrese el codigo de la estacion: ";
        cin >> codigo;
        cout << "Ingrese el nombre del gerente: ";
        cin >> gerente;
        cout << "Selecione la region:" << endl;
        cout << "[1] Norte" << endl;
        cout << "[2] Centro" << endl;
        cout << "[3] Sur" << endl;
        cin >> op_region;
        if (op_region != 1 && op_region != 2 && op_region != 3){
            cout << "Region no valida. No se pudo agregar la estacion" << endl;
        }
        else{
            if (op_region == 1)
                region = "Norte";
            else if(op_region == 2)
                region = "Centro";
            else
                region = "Sur";
            cout << "Ingrese la ubicacion GPS: ";
            cin >> ubicacionGPS;
            estaciones[totalEstaciones] = new Estacion(nombre, codigo, gerente, region, ubicacionGPS, 10); // Asumir max surtidores como 10
            totalEstaciones++;
            cout << "Se agrego la estacion " << nombre << " con codigo " << codigo << " correctamente" << endl;
        }
    }
    else
        cout << "No se pueden agregar mas estaciones" << endl;
}

void Red::eliminarEstacion(long codigo) {
    bool encontrado = false;
    for (int i = 0; i < totalEstaciones; i++) {
        if (estaciones[i]->getid_Estacion() == codigo) {  // accedemos -> a la estacion atraves del codigo
            delete estaciones[i];  // Elimina la estacion
            for (int j = i; j < totalEstaciones - 1; j++) {
                estaciones[j] = estaciones[j + 1];  // Reorganizar el arreglo
            }
            estaciones[totalEstaciones - 1] = nullptr; // libera el espacio de memoria
            totalEstaciones -= 1;
            encontrado = true;
            cout << "Estacion eliminada correctamente." << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estacion con codigo " << codigo << " no encontrada." << endl;
    }
}

void Red::calcularVentas(){
    cout << "Calculando ventas para las " << totalEstaciones << " estaciones de la red..." << endl;
    for (int i = 0; i < totalEstaciones; i++) {
        cout << "Estacion: " << estaciones[i]->getNombreEstacion() << " (Codigo: " << estaciones[i]->getid_Estacion() << ")" << endl;
        // falta agregar logica para calcular ventas, por ejemplo, simulando un valor.
    }
}

void Red::fijarPrecios(){
    string precio_regular, precio_premium, precio_ecoextra;
    cout << "Ingrese el precio del combustible Regular" << endl;
    cin >> precio_regular;
    cout << "Ingrese el precio del combustible Premium" << endl;
    cin >> precio_premium;
    cout << "Ingrese el precio del combustible EcoExtra" << endl;
    cin >> precio_ecoextra;
    precio_combustible = precio_regular + ":" + precio_premium + ":" + precio_ecoextra;
    cout << "Nuevos precios fijados." << endl;
    cout << "Combustible Regular: " << precio_regular << endl;
    cout << "Combustible Premium: " << precio_premium << endl;
    cout << "Combustible EcoExtra: " << precio_ecoextra << endl;
}

void Red::mostrarEstaciones() const {
    cout << "Red: " << nombre_red << endl;
    for (int i = 0; i < totalEstaciones; i++){
        cout << "Estacion " << i + 1 << ": " << estaciones[i]->getNombreEstacion()
        << ", Codigo: " << estaciones[i]->getid_Estacion()
        << ", Gerente: " << estaciones[i]->getGerente()
        << ", Region: " << estaciones[i]->getRegion() << endl;
    }
}
