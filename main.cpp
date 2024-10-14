#include <iostream>
#include <string>

using namespace std;

class Surtidor;
class Estacion;
class Red;
class Tanque;
class Venta;



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
    Surtidor(int _id, string _modelo){
        id =_id;
        string modelo_maquina = _modelo;
        ventas = 0.0;
    }
    
    void vender(float cantidad){
        if (cantidad > 0 ){
            ventas += cantidad; //Acumula cantidad vendida
            cout<<  "Venta realizada en el surtidor ID " << id << ". Total vendido: " << ventas << " unidades." << endl;
        }
    }
    // metodo para total de ventas 
    float obtenerVentas() const {
        return ventas; // Total de ventas 
    }

    //Destructor
    ~Surtidor(){
        cout<< "Destructor del Surtidor ID " << id << " llamado." << endl;
    }
};

class Estacion{
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
    Estacion(string _nombre, long _id, string _gerente, string _region, string _ubicacion, int _max){
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
    
    void agregarSurtidor( string modelo){

        if (contar_surtidores < max_surtidores){
            surtidores[contar_surtidores] = new Surtidor(contar_surtidores +1, modelo);
            contar_surtidores ++;
            maquinas_espendedoras ++;
            cout << "se agragado exitosamente un surtigo. Modelo" << modelo << "Total de surtidores: " << contar_surtidores << endl;
        }
    }

    void eliminarSurtidor(int id){
        for (int i = 0; i < contar_surtidores; i++){
            if (surtidores[1] -> id == id) {
            if (surtidores[i]->obtenerVentas() == id) {  
                delete surtidores[i];
                for(int j = i; j < contar_surtidores -1; j++){
                    surtidores [j] = surtidores [j + 1]; // reorganizar el arreglo
                }
                contar_surtidores --;
                maquinas_espendedoras --;
                cout << " El surtido por ID" << id << "Fue eliminando. El total de surtidores actual es" << contar_surtidores << endl;
                return;
                
            }
        }
        cout << "Surtidor con ID " << id << " no encontrado." << endl;


    }
   

    void activarSurtidor(int id){
        for (int i = 0; i < contar_surtidores; i++) {
            if (surtidores[i +1] == id) {
                cout << "Surtidor con ID " << id << " activado." << endl;
                return;
            }
        }
        cout << "Surtidor con ID " << id << " no encontrado." << endl;
    }

    void desactivarSurtidor(int id ){
        for (int i = 0; i < contar_surtidores; i++) {
            if ( surtidores[i+1]== id) {
                cout << "Surtidor con ID " << id << " desactivado." << endl;
                return;
            }
        }
        cout << "Surtidor con ID " << id << " no encontrado." << endl;
    }
    consultarHistorico();

    //asignarCapacidad();
    //verificarFugas();
    ~Estacion(){
        for (int i = 0; i < contar_surtidores; i++){
            delete surtidores[i]; // libera la memoria de los surtidores
        }
        delete[] surtidores;
    }
    }
};
   
class Red{

private:
    Estacion* estaciones[12]; // Maximo de estaciones de servicios
    int precio_combustible;
    int totalEstaciones;
    string nombre_red;
public:

    Red(string _nombre_red, int _precio_combustible) {  // Inicializo el constructor 
        totalEstaciones = 0;
        precio_combustible = _precio_combustible;
        nombre_red = _nombre_red;
    }

    ~Red() {  // Destructor libera memoria dinamica
        for (int i = 0; i < totalEstaciones; i++) {
            delete estaciones[i];  
        }
    }
    
    void agregarEstacion( string nombre, long codigo, string gerente, string region, string ubicacionGPS) {
        if (totalEstaciones < 12) {
            estaciones[totalEstaciones] = new Estacion(nombre, codigo, gerente, region, ubicacionGPS, 10); // Asumir max surtidores como 10
            totalEstaciones++;
        }  
    }

  // Metodo para eliminar una estacion por su codigo
    void eliminarEstacion(long codigo) {
        bool encontrado = false;
        for (int i = 0; i < totalEstaciones; i++) {
            if (estaciones[i]->id_estacion == codigo) {  // accedemos -> a la estacion atraves del codigo 
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
    
    void calcularVentas(){
        cout << "Calculando ventas para las " << totalEstaciones << " estaciones de la red..." << endl;
        for (int i = 0; i < totalEstaciones; i++) {
            cout << "Estacion: " << estaciones[i]->nombre_estacion << " (Codigo: " << estaciones[i]->id_estacion << ")" << endl;
            // falta agregar logica para calcular ventas, por ejemplo, simulando un valor.
        }
    }
    
    void fijarPrecios(int nuevo_precio){
        precio_combustible = nuevo_precio;
        cout << "El nuevo precio del combustible es: " << precio_combustible << " por litro." << endl;
    }
 
    // Metodo para mostrar informacion de la red y sus estaciones
    void mostrarEstaciones() const {
        cout << "Red: " << nombre_red << endl;
        for (int i = 0, i < totalEstaciones; i++){
             cout << "Estacion " << i + 1 << ": " << estaciones[i]->nombre_estacion 
                 << ", Codigo: " << estaciones[i]->id_estacion
                 << ", Gerente: " << estaciones[i]->gerente 
                 << ", Region: " << estaciones[i]->region << endl;
        }
    }
};

int main() {
    Red miRed("TerMax", 10000);
    cout << "Bienvenido a la Red de Servicios " << miRed << endl;

    int op_menu = 1;
    while (op_menu != 0) {
        cout << "\n- Menú principal -" << endl;
        cout << "[1] Gestión de Red" << endl;
        cout << "[2] Gestión de Estación" << endl;
        cout << "[0] Salir" << endl;
        cin >> op_menu;

        switch (op_menu) {
            case 1: {
                int op_submenu;
                cout << "- Gestión de Red -" << endl;
                cout << "[1] Agregar Estación" << endl;
                cout << "[2] Eliminar Estación" << endl;
                cout << "[3] Calcular Ventas" << endl;
                cout << "[4] Fijar Precios" << endl;
                cin >> op_submenu;

                switch (op_submenu) {
                    case 1: {
                        string nombre, gerente, region, ubicacionGPS;
                        long codigo;
                        cout << "Ingrese el nombre de la estación: ";
                        cin >> nombre;
                        cout << "Ingrese el código de la estación: ";
                        cin >> codigo;
                        cout << "Ingrese el nombre del gerente: ";
                        cin >> gerente;
                        cout << "Ingrese la región: ";
                        cin >> region;
                        cout << "Ingrese la ubicación GPS: ";
                        cin >> ubicacionGPS;
                        miRed.agregarEstacion(nombre, codigo, gerente, region, ubicacionGPS);
                        break;
                    }
                    case 2: {
                        long codigo;
                        cout << "Ingrese el código de la estación a eliminar: ";
                        cin >> codigo;
                        miRed.eliminarEstacion(codigo);
                        break;
                    }
                    case 3:
                        miRed.calcularVentas();
                        break;
                    case 4: {
                        int nuevo_precio;
                        cout << "Ingrese el nuevo precio del combustible: ";
                        cin >> nuevo_precio;
                        miRed.fijarPrecios(nuevo_precio);
                        break;
                    }
                }
                break;
            }

            case 2: {
                int op_submenu;
                cout << "- Gestión de Estación -" << endl;
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