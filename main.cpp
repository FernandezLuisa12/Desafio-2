#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Surtidor{
private:
    int id;
    int id_estacion;
    string modelo_maquina;
    float ventas;

public:
    Surtidor(int _id, int _id_estacion, string modelo);
    int getId_surtidor() const {
        return id;
    }
    int getId_estacion() const{
        return id_estacion;
    }
    string getModelo(){
        return modelo_maquina;
    }
    void vender(float cantidad, string region, const string &precio_combustible);
    float obtenerVentas() const { // metodo para total de ventas
        return ventas; // total de ventas
    }
    ~Surtidor(){//Destructor
        cout<< "Destructor del Surtidor ID " << id << " llamado." << endl;
    }
};

class Estacion{
private:
    int id_estacion;
    string gerente;
    string region;
    string ubicacion;
    int maquinas_espendedoras;
    string nombre_estacion;
    Surtidor* surtidores[144]; // Arreglo de surtidores
    int contar_surtidores; // Contador de surtidores activos
    double capacidad_tanque[4];// Para Regular, Premium, EcoExtra
    double vendidos[4]; // Para rastrear lo vendido por tipo
public:
    // Constructor
    Estacion(string, int, string, string, string);
    // Métodos getter y setter
    void getCapacidad(double* _capacidad) const {
        for (int i = 0; i < 4; ++i) {
            _capacidad[i] = capacidad_tanque[i];
        }
    }
    void getVendidos(double* _vendidos) const {
        for (int i = 0; i < 4; ++i) {
            _vendidos[i] = capacidad_tanque[i];
        }
    }
    string getNombreEstacion() const {
        return nombre_estacion;
    }
    string getGerente() const {
        return gerente;
    }
    string getRegion() const {
        return region;
    }
    int getid_Estacion(){
        return id_estacion;
    }
    string getUbicacion(){
        return ubicacion;
    }
    bool verificarSurtidor(int id, int codigo);
    void mostrarSurtidores(int id_estacion);
    void agregarSurtidor(int id_estacion);
    void eliminarSurtidor(int id, int codigo);
    void activarSurtidor(int id );
    void desactivarSurtidor(int id );
    static string cambiar_precios(string region, const string &precio_combustible);
    void verificarFugas(int id, const double (&capacidad_tanque)[4], const double (&vendidos)[4]);
    // consultarHistorico();
    ~Estacion();
};

class Red{
private:
    Estacion* estaciones[12]; // Estaciones de servicios
    string precio_combustible;
    int totalEstaciones;
    string nombre_red;
public:
    int getTotalEstaciones(){
        return totalEstaciones;
    }
    void getDatos(int, string &nom, int &id, string &ger, string &reg, string &ubi);
    Red(string _nombre_red, string _precio_combustible);
    bool verificarEstacion(int codigo);
    void agregarEstacion();
    void eliminarEstacion(int codigo); // Metodo para eliminar una estacion por su codigo
    void calcularVentas();
    void fijarPrecios();
    // Metodo para mostrar informacion de la red y sus estaciones
    void mostrarEstaciones() const;
    ~Red();
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

int main() {
    string nombre, gerente, region, ubicacion;
    int codigo, op_menu = 1, id_estacion;
    Red miRed("TerMax", "4000:5000:6000");
    cout << "- Bienvenidos a la red de Servicios TerMax -" << endl;
    cout << "Registre una estacion para iniciar la Red" << endl;
    miRed.agregarEstacion();
    miRed.getDatos(codigo, nombre, id_estacion,gerente, region, ubicacion);
    Estacion miEstacion(nombre, id_estacion, gerente, region, ubicacion);
    while (op_menu != 0) {
        cout << "\n- Menu principal -" << endl;
        cout << "[1] Gestion de Red" << endl;
        cout << "[2] Gestion de Estacion" << endl;
        cout << "[0] Salir" << endl;
        cin >> op_menu;

        switch (op_menu) {
        case 1: {
            int op_submenu = 1;
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
                int codigo;
                if (miRed.getTotalEstaciones() == 0){
                    cout << "No se encontraron estaciones registradas" << endl;
                }
                else{
                    miRed.mostrarEstaciones();
                    cout << "Ingrese el codigo de la estacion a eliminar: ";
                    cin >> codigo;
                    miRed.eliminarEstacion(codigo);
                }
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
            miRed.mostrarEstaciones();
            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            if (miRed.verificarEstacion(codigo)){
                miRed.getDatos(codigo, nombre, id_estacion,gerente, region, ubicacion);
                int op_submenu = 1;
                while (op_submenu != 0){
                    cout << endl << "- Gestion de Estacion " << nombre << " -"<< endl;
                    cout << "[1] Agregar Surtidor" << endl;
                    cout << "[2] Eliminar Surtidor" << endl;
                    cout << "[3] Verificar Fugas" << endl;
                    cout << "[0] Salir" << endl;
                    cin >> op_submenu;
                    switch (op_submenu) {
                    case 1: {
                        miEstacion.agregarSurtidor(id_estacion);
                        break;
                    }
                    case 2: {
                        int id;
                        miEstacion.mostrarSurtidores(id_estacion);
                        cout << "Ingrese el ID del surtidor a eliminar: ";
                        cin >> id;
                        miEstacion.eliminarSurtidor(id, id_estacion);
                        break;
                    }
                    case 3:{
                        double _capacidad[4];
                        double _vendidos[4];
                        miEstacion.getCapacidad(_capacidad);
                        miEstacion.getVendidos(_vendidos);
                        miEstacion.verificarFugas(id_estacion, _capacidad, _vendidos);
                    }
                    case 0:{
                        cout << "Saliendo de la estacion..." << endl;
                        break;
                    }
                    }
                }
            }
            else
                cout << "Estacion con codigo " << codigo << " no encontrada." << endl;
            break;
        }

        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;

        }
    }
    return 0;
}

void Red::getDatos(int codigo, string &nom, int &id, string &ger, string &reg, string &ubi)
{
    for (int i = 0; i < totalEstaciones; i++) {
        if (estaciones[i]->getid_Estacion() == codigo) {
            nom = estaciones[i]->getNombreEstacion();
            id = estaciones[i]->getid_Estacion();
            ger = estaciones[i]->getGerente();
            reg = estaciones[i]->getRegion();
            ubi = estaciones[i]->getUbicacion();
        }
    }
}

Red::Red(string _nombre_red, string _precio_combustible) {  // Inicializo el constructor
    totalEstaciones = 0;
    precio_combustible = _precio_combustible;
    nombre_red = _nombre_red;
}

bool Red::verificarEstacion(int codigo){
    for (int i = 0; i < totalEstaciones; i++) {
        if (estaciones[i]->getid_Estacion() == codigo) {
            return true;
        }
    }
    return false;
}

void Red::agregarEstacion() {
    if (totalEstaciones < 12) {
        string nombre, gerente, region, ubicacionGPS;
        int codigo, op_region = 1;
        cout << endl << "Ingrese el nombre de la estacion: ";
        cin >> nombre;
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
            codigo = 3960 + (totalEstaciones +1);
            estaciones[totalEstaciones] = new Estacion(nombre, codigo, gerente, region, ubicacionGPS); // Asumir max surtidores como 6
            totalEstaciones++;
            cout << "Se agrego la estacion " << nombre << " con codigo " << codigo << " correctamente" << endl;
        }
    }
    else
        cout << "No se pueden agregar mas estaciones" << endl;
}

void Red::eliminarEstacion(int codigo) {
    if(verificarEstacion(codigo)){
        for (int i = 0; i < totalEstaciones; i++) {
            if (estaciones[i]->getid_Estacion() == codigo) {  // accedemos -> a la estacion atraves del codigo
                delete estaciones[i];  // Elimina la estacion
                for (int j = i; j < totalEstaciones - 1; j++) {
                    estaciones[j] = estaciones[j + 1];  // Reorganizar el arreglo
                }
                estaciones[totalEstaciones - 1] = nullptr; // libera el espacio de memoria
                totalEstaciones -= 1;
                cout << "Estacion eliminada correctamente." << endl;
                break;
            }
        }
    }
    else
        cout << "Estacion con codigo " << codigo << " no encontrada." << endl;
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
    cout << "Combustible Regular: $" << precio_regular << endl;
    cout << "Combustible Premium: $" << precio_premium << endl;
    cout << "Combustible EcoExtra: $" << precio_ecoextra << endl;
    cout << "La variacion de precios por region fue establecida de la siguienta manera:" << endl;
    cout << "Norte: +12%" << endl;
    cout << "Centro: +10%" << endl;
    cout << "Sur: +15%" << endl;
}

void Red::mostrarEstaciones() const {
    cout << endl << "Red: " << nombre_red << endl;
    for (int i = 0; i < totalEstaciones; i++){
        cout << "Estacion " << i + 1 << ": " << estaciones[i]->getNombreEstacion()
        << ", Codigo: " << estaciones[i]->getid_Estacion()
        << ", Gerente: " << estaciones[i]->getGerente()
        << ", Region: " << estaciones[i]->getRegion() << endl;
    }
}

Red::~Red() {  // Destructor libera memoria dinamica
    for (int i = 0; i < totalEstaciones; i++) {
        delete estaciones[i];
    }
}

Estacion::Estacion(string _nombre, int _id, string _gerente, string _region, string _ubicacion){
    nombre_estacion = _nombre;
    id_estacion = _id;
    gerente = _gerente;
    region = _region;
    ubicacion = _ubicacion;
    maquinas_espendedoras = 0;
    contar_surtidores = 0;
    srand(static_cast<unsigned int>(time(0))); // Inicializa la semilla
    capacidad_tanque[0] = _id;
    vendidos[0] = _id;
    for (int i = 1; i < 4; i++) {
        capacidad_tanque[i] = rand() % 101 + 100; // Capacidad aleatoria entre 100 y 200 litros
        vendidos[i] = 0;
    }
}

void Estacion::mostrarSurtidores(int id_estacion){
    for (int i = 0; i < contar_surtidores; i++) {
        if (surtidores[i]->getId_estacion() == id_estacion){
            cout << "Surtidor " << i + 1 << ": "
                 << " ID: " << surtidores[i]->getId_surtidor()
                 << ", Modelo: " << surtidores[i]->getModelo() << endl;
        }
    }
}

void Estacion::agregarSurtidor(int id_estacion){
    int id_surtidor, op_modelo; string modelo;
    if (contar_surtidores < 12){
        cout << "Seleccione un modelo de maquina para asignarle:" << endl;
        cout << "[1] MT4523" << endl;
        cout << "[2] MT5631" << endl;
        cout << "[3] MT6752" << endl;
        cin >> op_modelo;
        if (op_modelo != 1 && op_modelo != 2 && op_modelo != 3){
            cout << "Modelo no valido. No se pudo agregar el surtidor" << endl;
        }
        else{
            if (op_modelo == 1)
                modelo = "MT4523";
            else if(op_modelo == 2)
                modelo = "MT5631";
            else
                modelo = "MT6752";
            id_surtidor = 4000 + (contar_surtidores + 1);
            surtidores[contar_surtidores] = new Surtidor(id_surtidor, id_estacion, modelo);
            contar_surtidores ++;
            maquinas_espendedoras ++;
            cout << "Se ha agregado exitosamente un surtidor con id " << id_surtidor << ". Total de surtidores: " << contar_surtidores << endl;
        }
    }
    else
        cout << "No se pueden agregar mas surtidores." << endl;
}

bool Estacion::verificarSurtidor(int id, int codigo){
    for (int i = 0; i < contar_surtidores; i++) {
        if (surtidores[i]->getId_surtidor() == id && surtidores[i]->getId_estacion() == codigo) {
            return true;
        }
    }
    return false;
}

void Estacion::eliminarSurtidor(int id, int codigo){
    if(verificarSurtidor(id, codigo)){
        for (int i = 0; i < contar_surtidores; i++){
            if (surtidores[i]->getId_surtidor() == id){
                delete surtidores[i];
                for(int j = i; j < contar_surtidores -1; j++){
                    surtidores[j] = surtidores[j + 1]; // reorganizar el arreglo
                }
                surtidores[contar_surtidores - 1] = nullptr;
                contar_surtidores --;
                maquinas_espendedoras --;
                cout << "El surtidor con ID " << id << " fue eliminado. El total de surtidores actual es " << contar_surtidores << endl;
                return;
            }
        }
    }
    else
        cout << "Surtidor con ID " << id << "no existe o no pertenece a la estacion." << endl;
}

void Estacion::activarSurtidor(int id){
    for (int i = 0; i < contar_surtidores; i++) {
        if (surtidores[i] -> getId_surtidor() == id) {
            cout << "Surtidor con ID " << id << " activado." << endl;
            return;
        }
    }
    cout << "Surtidor con ID " << id << " no encontrado." << endl;
}

void Estacion::desactivarSurtidor(int id){
    for (int i = 0; i < contar_surtidores; i++) {
        if ( surtidores[i] -> getId_surtidor()== id) {
            cout << "Surtidor con ID " << id << " desactivado." << endl;
            return;
        }
    }
    cout << "Surtidor con ID " << id << " no encontrado." << endl;
}

string Estacion::cambiar_precios(string region, const string &precio_combustible) {
    string nuevo_precio;
    float regular = 0, premium = 0, ecoextra = 0, porcentaje = 0.0;

    size_t pos1 = precio_combustible.find(":");
    if (pos1 != string::npos) {
        regular = stof(precio_combustible.substr(0, pos1));
        size_t pos2 = precio_combustible.find(":", pos1 + 1);
        if (pos2 != string::npos) {
            premium = stof(precio_combustible.substr(pos1 + 1, pos2 - pos1 - 1));
            ecoextra = stof(precio_combustible.substr(pos2 + 1));
        }
    }

    if (region == "Norte") {
        porcentaje = 12.0;
    } else if (region == "Centro") {
        porcentaje = 10.0;
    } else {
        porcentaje = 15.0;
    }

    regular += regular * (porcentaje / 100.0);
    premium += premium * (porcentaje / 100.0);
    ecoextra += ecoextra * (porcentaje / 100.0);

    nuevo_precio = to_string(regular) + ":" + to_string(premium) + ":" + to_string(ecoextra);
    return nuevo_precio;
}


Estacion::~Estacion(){
    for (int i = 0; i < contar_surtidores; ++i) {
        delete surtidores[i];
    }
}

Surtidor::Surtidor(int _id, int _id_estacion, string modelo){
    id =_id;
    modelo_maquina = modelo;
    id_estacion = _id_estacion;
    ventas = 0.0;
}

void Surtidor::vender(float cantidad, string region, const string &precio_combustible){
    string precios = Estacion::cambiar_precios(region, precio_combustible);
    float regular, premium, ecoextra; regular = 0; premium = 0; ecoextra = 0;
    size_t pos1 = precios.find(":");
    if (pos1 != string::npos){
        regular = stof(precios.substr(0, pos1));
        size_t pos2 = precios.find(":");
        if (pos2 != string::npos){
            premium = stof(precios.substr(pos1 +1, pos2 - pos1 -1));
            ecoextra = stof(precios.substr(pos2 +1));
        }
    }
    if (cantidad > 0 ){
        ventas += cantidad; //Acumula cantidad vendida
        cout<<  "Venta realizada en el surtidor ID " << id << ". Total vendido: " << ventas << " unidades." << endl;
    }
}

// Método para verificar fugas
void Estacion::verificarFugas(int id, const double (&capacidad_tanque)[4], const double (&vendidos)[4]) {
    if (capacidad_tanque[0] == id) {
        for (int i = 1; i < 4; ++i) {
            if ((capacidad_tanque[i] - vendidos[i]) < (0.05 * capacidad_tanque[i])) {
                cout << "Fuga detectada en estacion " << id << " en categoría " << i << endl;
            }
            else
                cout << "No se encontraron fugas en la estacion " << id << endl;
        }

    }
}
