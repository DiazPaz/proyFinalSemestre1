#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctype.h>
#include <array>

using namespace std;

string numeroSerie[5] = {"A2483", "A1701", "A1278", "A1132", "A2984"}, nombreComercial[5] = {"iPhone", "iPad", "MacBook", "AirPods", "Apple Watch"};
int cantidadProductosDisponibles[5] = {5,5,5,5,5}, carritoNumeroDeProducto[5] = {0,0,0,0,0}, unidadesVendidas[5] = {0,0,0,0,0}, disponibilidadPrevia[5] = {0,0,0,0,0}; 
float costoProductos[5] = {13998.99, 18999.99, 24999.99, 3699.99, 5499.99}, reporteVentas[5] = {0,0,0,0,0};

// int numDeCliente = 0; 
int numeroDeCliente = 0.0;
int numeroDeClienteTemp;
int opc5_Int = 0;
int contadorProductos = 0; 
int anadirUnidadesNuevasInt = 0; 
string anadirUnidadesNuevasString; 
char opc5, volver_a_comprar, procederComprarRegistro;
int contadorClienteContrasena = 0;
bool registroCliente, carritoSobreDisponibilidad; 
const int clientes = 100;
const int maxDatos = 4; 
const int maxDatosCompras = 6; 

int contadorClientes = 0; 

string perfilCliente[clientes][maxDatos];
string logInCliente[2];

vector<vector<int>> ticketsProductos;

int carritoClientes[clientes][maxDatosCompras] = {numeroDeCliente, 0, 0, 0, 0, 0};
int carritoCosto[clientes][maxDatosCompras] = {numeroDeCliente, 0, 0, 0, 0, 0}; 
int acumuladorCompras = 0; 

void comprasCliente();
void revisionDisponibilidadProducto(int opcion_convertida_entera); 
void impresionMenuCliente();
void impresionCarrito();
void impresionTicket();
bool tieneAlMenosUnDigito(const string& str);
bool tieneAlMenosUnaMayuscula(const string& str);
bool tieneAlMenosUnaMinuscula(const string& str) ;
bool noContieneEspecialesNiEspacios(const string& str);
bool tieneSoloNumeros(const string& str);
bool confirmacionUsuarioCliente();
bool confirmacionContrasenaCliente();
void impresionResumenTickets();


int main() {

    float reporteVentasFinal = 0;
    int supervisorintentos = 3, clienteintentos = 3, temp = 0, *apuntador; 
    char salirMenuSupervisor = 'y', salirMenuEmpleado = 'y', opc1, opc2, opc3, subOpc3, opc4, subOpc4, subSubOpc4, opc6;
    bool systemON = true, menuSupervisor , menuCliente, menuVentas, validarUsuarioCliente, validarContrasenaCliente, subMenuCliente, menuCarrito;

    const string contrasupervisor = "1", usuarioSupervisor = "uno"; 
    string contraSup, usuarioSup, numSerie;  

    int clonUnidadesVendidas[5];
    perfilCliente[0][0] = "0";


    while (systemON) {
        cout << "\n--------------------------------------\n"; 
        cout << "Bienvenido al Sistema de Ventas de Apple" << endl;
        cout << "Seleccione la opciOn con la que quiere ingresar (1-3):" << endl;
        cout << "1. Empleado" << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Terminar" << endl;
        cin >> opc1;

        switch(opc1){
            case '1':
                salirMenuEmpleado = 'y';
                do{
                    cout << "\n--------------------------------------\n";
                    cout << "Seleccione cOmo desea acceder al sistema (1-3):" << endl;
                    cout << "1. Supervisor" << endl;
                    cout << "2. Ventas" << endl;
                    cout << "3. Regresar" << endl;
                    cin >> opc2;
                    switch(opc2){
                        case '1': 
                            do{
                                cout << "\n--------------------------------------\n"; 
                                cout << "Ingrese el usuario: ";
                                cin >> usuarioSup;
                                if(usuarioSup  != usuarioSupervisor){
                                    cout << "Usuario no existente. Intente de nuevo. " << endl;
                                    if (supervisorintentos == 0) {
                                        cout << "Bienvenido " << usuarioSupervisor << endl;
                                    }
                                }
                            }while(usuarioSup != usuarioSupervisor);

                            do{
                                cout << "Ingrese la contrasena de supervisor: ";
                                cin >> contraSup;
                                if(contraSup  != contrasupervisor){
                                    supervisorintentos--;
                                    cout << "Contrasena incorrecta. Intentos restantes: " << supervisorintentos << endl;
                                    if (supervisorintentos == 0) {
                                        cout << "LImite de intentos permitidos superado." << endl;
                                        supervisorintentos = 3; 
                                        break;
                                    }
                                }
                            }while(contraSup  != contrasupervisor);

                                if (contraSup == contrasupervisor) {
                                    menuSupervisor = true;
                                    while(menuSupervisor){
                                    cout << "\n--------------------------------------\n"; 
                                    cout << "Bienvenido" << endl; 
                                    cout << "Seleccione una opciOn (1-3):" << endl;
                                    cout << "1. Reporte de Ventas" << endl;
                                    cout << "2. Reporte de Inventario" << endl;
                                    cout << "3. Terminar sesiOn" << endl;
                                    cin >> opc3;

                                    switch (opc3){

                                        case '1':
                                            salirMenuSupervisor = 'y';
                                            do{
                                                cout << "\n--------------------------------------\n";
                                                cout << "\nDesea generar el un reporte general o especIfico a algUn producto? (1-3)" << endl; 
                                                cout << "1. General" << endl;
                                                cout << "2. EspecIfico" << endl;
                                                cout << "3. Regresar" << endl; 
                                                cin >> subOpc3; 
                                                
                                                switch(subOpc3){

                                                    case '1': 
                                                        cout << "\n------------------------------------REPORTE DE VENTAS------------------------------------\n\n";
                                                        cout << "Num. Serie" << "\t" << "DescripciOn" << "\t" << "Precio Unitario" << "\t\t" << "Unidades Vendidas" << "\t" << "Ganancias" << endl;
                                                        for(int i = 0; i < 5; i++){
                                                            if(i < 3){
                                                                cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t$" << costoProductos[i] << "\t\t\t\t" << unidadesVendidas[i] << "\t\t" << "$" << reporteVentas[i] << endl; 
                                                            } else if (i == 3){
                                                                cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t$" << costoProductos[i] << "\t\t\t" << unidadesVendidas[i] << "\t\t" << "$" << reporteVentas[i] << endl;
                                                            } else if (i > 3){
                                                                cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t$" << costoProductos[i] << "\t\t\t" << unidadesVendidas[i] << "\t\t" << "$" << reporteVentas[i] << endl;
                                                            }
                                                        } 
                                                        reporteVentasFinal = reporteVentas[0] + reporteVentas[1] + reporteVentas[2] + reporteVentas[3] + reporteVentas[4];
                                                        cout << endl << "\t\t\t\t\t\t\t\t\t" << " Total: $" << reporteVentasFinal << endl;
                                                        for(int i = 0; i < 5; i++){
                                                            clonUnidadesVendidas[i] = unidadesVendidas[i];
                                                        }
                                                        int aux;
                                                        for (int i = 0; i < 5; i++) {
                                                            for (int j = i + 1; j < 5; j++) {
                                                                if (clonUnidadesVendidas[j] > clonUnidadesVendidas[i]) {
                                                                    aux = clonUnidadesVendidas[j];
                                                                    clonUnidadesVendidas[j] = clonUnidadesVendidas[i];
                                                                    clonUnidadesVendidas[i] = aux;
                                                                }
                                                            }
                                                        } 
                                                        if(reporteVentasFinal == 0){
                                                            cout << "No existe producto mAs vendido. AUn." << endl;
                                                        } else {
                                                            for(int i = 0; i < sizeof(unidadesVendidas)/sizeof(unidadesVendidas[0]); i++){
                                                                if(unidadesVendidas[i] == clonUnidadesVendidas[0]){
                                                                    cout << "Producto(s) mAs vendido(s): " << nombreComercial[i] << endl; 
                                                                }
                                                            }
                                                        }
                                                        cout << "------------------------------------------------------------------------------------------\n";
                                                        break;

                                                    case '2': 
                                                        do{ 
                                                            cout << "\n--------------------------------------\n";
                                                            cout << "Ingresa el numero de serie (A2483, A1701, A1278, A1132, A2984): ";
                                                            cin >> numSerie;
                                                            if((numSerie !="A2483")&&(numSerie != "A1701")&& (numSerie !="A1278")&&(numSerie != "A1132")&& (numSerie !="A2984")){
                                                                cout << "Producto inexistente. Por favor digitelo de nuevo. " << endl << endl; 
                                                            }
                                                        }while((numSerie !="A2483")&&(numSerie != "A1701")&& (numSerie !="A1278")&&(numSerie != "A1132")&& (numSerie !="A2984"));
                                                        for (int i = 0; i < 5; i++) {
                                                            if (numeroSerie[i] == numSerie){
                                                                cout << "\n-------------------------------REPORTE DE VENTAS DE " << nombreComercial[i] << "-------------------------------\n\n";
                                                                cout << "Num. Serie" << "\t" << "DescripciOn" << "\t" << "Precio Unitario" << "\t\t" << "Unidades Vendidas" << "\t" << "Ganancias" << endl;
                                                                if(i < 3){
                                                                    cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t$" << costoProductos[i] << "\t\t\t\t" << unidadesVendidas[i] << "\t\t" << "$" << reporteVentas[i] << endl; 
                                                                } else if (i == 3){
                                                                    cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t$" << costoProductos[i] << "\t\t\t" << unidadesVendidas[i] << "\t\t" << "$" << reporteVentas[i] << endl;
                                                                } else if (i > 3){
                                                                    cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t$" << costoProductos[i] << "\t\t\t" << unidadesVendidas[i] << "\t\t" << "$" << reporteVentas[i] << endl;
                                                                }
                                                                cout << "\n------------------------------------------------------------------------------------------\n";                                                            
                                                            }
                                                        } 
                                                        break; 

                                                    case '3': salirMenuSupervisor = 'n'; cout << "Regresando a menU anterior..."; break;

                                                    default: cout << "OpciOn no valida. " << endl; break;
                                                } 
                                            } while (salirMenuSupervisor != 'n');
                                        break;

                                        case '2':    
                                            cout << "\n-----------------------------------REPORTE DE INVENTARIO-----------------------------------\n\n";
                                            cout << "Num. Serie" << "\t" << "DescripciOn" << "\t" << "Disponbilidad Actual" << "\t" << "UbicaciOn" << endl << endl;
                                            for (int i = 0; i < 5; i++) {
                                                apuntador = &cantidadProductosDisponibles[i];
                                                if(i != 4){
                                                cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t" << cantidadProductosDisponibles[i] << "\t\t\t" << apuntador << endl;
                                                } else {
                                                    cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "     " << cantidadProductosDisponibles[i] << "\t\t\t" << apuntador << endl;
                                                }                                                       
                                            } 
                                            cout << "\n-------------------------------------------------------------------------------------------\n";     
                                        break;

                                        case '3': menuSupervisor = false; break; 

                                        default: cout << "OpciOn no valida. " << endl; break; 

                                        } 
                                    } 
                                }
                            break;


                        case '2':  
                            menuVentas = true; 
                            while(menuVentas){
                                cout << "\n--------------------------------------\n";
                                cout << "\nSeleccione una opciOn (1-3): " << endl; 
                                cout << "1. Registrar producto" << endl;
                                cout << "2. Tickets de compra" << endl;
                                cout << "3. Regresar" << endl; 
                                cin >> opc6;

                                switch (opc6){

                                    case '1': 
                                    do{ 
                                        cout << "------------------------------------------------------------------\n"; 
                                        cout << "Ingresa el numero de serie para registrar unidades nuevas (A2483, A1701, A1278, A1132, A2984): ";
                                        cin >> numSerie;
                                        if((numSerie !="A2483")&&(numSerie != "A1701")&& (numSerie !="A1278")&&(numSerie != "A1132")&& (numSerie !="A2984")){
                                            cout << "Producto inexistente. Por favor digitelo de nuevo. " << endl << endl; 
                                        }
                                    }while((numSerie !="A2483")&&(numSerie != "A1701")&& (numSerie !="A1278")&&(numSerie != "A1132")&& (numSerie !="A2984"));
                                    for (int i = 0; i < 5; i++) {
                                        if (numeroSerie[i] == numSerie){
                                            cout << "Por favor ingrese la cantidad de unidades nuevas a registrar de " << nombreComercial[i] << ": "; 

                                            do{
                                                cin >> anadirUnidadesNuevasString;
                                                if(!tieneSoloNumeros(anadirUnidadesNuevasString)){
                                                    cout << "Por favor ingrese la cantidad de unidades nuevas a registrar de " << nombreComercial[i] << ": "; 
                                                }
                                            }while(!tieneSoloNumeros(anadirUnidadesNuevasString));
                                            anadirUnidadesNuevasInt = stoi(anadirUnidadesNuevasString);

                                            disponibilidadPrevia[i] = cantidadProductosDisponibles[i]; 
                                            cantidadProductosDisponibles[i] += anadirUnidadesNuevasInt; 
                                            cout << "------------------------------------------------------------------\n";
                                            cout << "Num. Serie" << "\t" << "DescripciOn" << "\t" << "Disponbilidad Actual" << "\t" << "Disponibilidad Previa" << endl;
                                            cout << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t" << cantidadProductosDisponibles[i]<< "\t\t\t" << disponibilidadPrevia[i] << endl;
                                            cout << "------------------------------------------------------------------\n";
                                        }
                                    } 
                                    break;

                                    case '2': impresionResumenTickets(); break;

                                    case '3': menuVentas = false; break;

                                    default: cout << "OpciOn no valida. " << endl; break; 
                                }
                            }
                            break;

                        case '3': 
                            salirMenuEmpleado = 'n';
                            cout << "Regresando a inicio... " << endl;
                            break;
                        default: 
                            cout << "OpciOn no valida. " << endl;
                            break; 
                    }
                } while (salirMenuEmpleado != 'n');
                break; 

            case '2': 
                
                menuCliente = true; 
                while(menuCliente){ 
                    cout << "\n--------------------------------------\n";
                    cout << "Seleccione una opciOn (1-3):" << endl;
                    cout << "1. Acceder con cuenta ya existente" << endl;
                    cout << "2. Crear cuenta" << endl;
                    cout << "3. Regresar" << endl;
                    cin >> opc4;

                    switch(opc4){
                        
                        case '1': 
                        if (perfilCliente[0][0] != "0"){
                            cout << "\n--------------------------------------\n";

                            validarUsuarioCliente = false;
                            do{
                                // numeroDeCliente = 0;
                                cout << "- Usuario: "; cin >> logInCliente[0]; 
                                for(int i = 0; i < sizeof(perfilCliente)/sizeof(perfilCliente[0]); i++){
                                    if(perfilCliente[i][0] == logInCliente[0]){
                                        // ¿Por qué no se cumple esta condición?
                                        validarUsuarioCliente = true;
                                    } 
                                } 
                                if(!confirmacionUsuarioCliente()){
                                    cout << "Usuario no encontrado. Por favor intente de nuevo. " << endl; 
                                }
                                
                            } while(!confirmacionUsuarioCliente());

                            validarContrasenaCliente = false;
                            do{

                                cout << "- ContraseNa: "; cin >> logInCliente[1]; 
                                for(int i = 0; i < sizeof(perfilCliente)/sizeof(perfilCliente[0]); i++){
                                    if(perfilCliente[i][0] == logInCliente[0]){
                                        if(perfilCliente[i][1] == logInCliente[1]){
                                            validarContrasenaCliente = true; 
                                            numeroDeClienteTemp = i;
                                        } else {
                                            clienteintentos--; 
                                            cout << "ContraseNa incorrecta. Intentos restantes: " << clienteintentos << endl; 
                                            if(clienteintentos == 0){
                                                cout << "LImite de intentos permitidos superado." << endl;
                                                clienteintentos = 3; 
                                                break; 
                                            }
                                        }
                                    } 
                                }
                            } while(!confirmacionContrasenaCliente());

                            // Crear una variable que almacene el número del cliente temporalmente. 

                            if(validarUsuarioCliente and validarContrasenaCliente){
                                subMenuCliente = true;
                                while(subMenuCliente == true){
                                    cout << "\n--------------------------------------\n";
                                    cout << "Bienvenid@ " << perfilCliente[numeroDeClienteTemp][0] << ". Elija una opciOn (1-3): " << endl; 
                                    cout << "1. Comprar" << endl;
                                    cout << "2. Carrito" << endl;
                                    cout << "3. Regresar" << endl;
                                    cin >> subOpc4; 
                                    switch(subOpc4){
                                        case '1': comprasCliente(); break;
                                        case '2': 
                                            menuCarrito = false; 
                                            for(int i = 1; i < 6; i++){
                                                if(carritoClientes[numeroDeClienteTemp][i] != 0){
                                                    menuCarrito = true; 
                                                }
                                            }
                                            if(menuCarrito == false){
                                                cout << "\nNo hay elementos en el carrito. " << endl;
                                            }
                                            while(menuCarrito){
                                                impresionCarrito(); 
                                                cout << "Desea proceder a comprar? (s/n) " << endl;
                                                cin >> subSubOpc4;
                                                switch(subSubOpc4){
                                                    case 's': impresionTicket();

                                                    
                                                    carritoSobreDisponibilidad = true; 
                                                    // Valida si la cantidad de productos en el carrito supera la disponibilidad del producto. 
                                                    for(int i = 1; i < 6; i++){
                                                        if(carritoClientes[numeroDeClienteTemp][i] > cantidadProductosDisponibles[i-1]){
                                                            cout << "Lo sentimos, nuestros productos se agotaron. \nRevise nuestra secciOn de compras para una nueva selecciOn de productos. \n"; 
                                                            for(int k = 1; k < 6; k++){
                                                                carritoClientes[numeroDeClienteTemp][k] = 0;
                                                                carritoCosto[numeroDeClienteTemp][k] = 0; 
                                                            }
                                                            carritoSobreDisponibilidad = false; 
                                                        } 
                                                    }

                                                    if(carritoSobreDisponibilidad){

                                                        for(int j = 1; j < 6; j++){
                                                            contadorProductos = carritoClientes[numeroDeClienteTemp][j];
                                                            cantidadProductosDisponibles[j-1] -= contadorProductos;
                                                            unidadesVendidas[j-1] += contadorProductos; 
                                                            reporteVentas[j-1] = unidadesVendidas[j-1] * costoProductos[j-1];
                                                        }

                                                        acumuladorCompras++;
                                                        for (int a = 0; a < acumuladorCompras; a++) { // Agregaremos N(acumuladorCompras) número de filas
                                                            vector<int> fila(maxDatosCompras, 0); // Crea una fila con el número de columnas(maxDatosCompras) especificado 
                                                            for (int b = 0; b < fila.size(); b++) { // Introduce valores al vector
                                                                fila[b] = numeroDeClienteTemp;
                                                                if (b != 0) {
                                                                    for(int c = 1; c < maxDatosCompras; c++){
                                                                        fila[c] = carritoClientes[numeroDeClienteTemp][c]; // Aquí las compras almacenadas en el carrito del cliente son almacenadas en el vector 'fila'
                                                                    }
                                                                }
                                                            }
                                                            ticketsProductos.push_back(fila); // Agrega la fila al vector ticketsProductos
                                                        }

                                                        for(int h = 1; h < 6; h++){
                                                            carritoClientes[numeroDeClienteTemp][h] = 0;
                                                            carritoCosto[numeroDeClienteTemp][h] = 0; 
                                                        }
                                                        menuCarrito = false;

                                                    } else{
                                                        menuCarrito = false; 
                                                    }
                                                    
                                                    break;  
                                                    case 'n': menuCarrito = false; break;
                                                    default: cout << "OpciOn no valida. " << endl; break; 
                                                }
                                            }
                                        break; 
                                        case '3': subMenuCliente = false; logInCliente[0] = "0"; logInCliente[1] = "0"; clienteintentos = 3; break; 
                                        default: cout << "OpciOn no valida. " << endl; break;
                                    }
                                }
                            }
                        } else {
                            cout << "\nNo hay usuarios existentes. Favor de registrarse para proceder a comprar. " << endl; 
                        }
                        break;

                        case '2': 
                        registroCliente = true; 
                        cout << "\n--------------------------------------\n";
                        cout << "Para poder registrar una cuenta serA necesario: " << endl << endl; 
                        cout << "-- Usuario: "; cin >> perfilCliente[numeroDeCliente][0]; cout << "\n"; 
                        cout << "-- Contrasena" << endl;
                        contadorClienteContrasena = 0; 
                        do {
                            if (contadorClienteContrasena > 0){
                                cout << "(Al menos 1 MayUscula)" << endl << "(Al menos 1 MinUscula)" << endl << "(Al menos 1 NUmero)" << endl << "(Al menos 6 caracteres)" << endl << "(Sin espacios ni caracteres): ";
                            }
                            getline(cin, perfilCliente[numeroDeCliente][1]);
                            contadorClienteContrasena++; 
                        } while (perfilCliente[numeroDeCliente][1].length() < 6 || !tieneAlMenosUnDigito(perfilCliente[numeroDeCliente][1]) || !tieneAlMenosUnaMayuscula(perfilCliente[numeroDeCliente][1]) || !tieneAlMenosUnaMinuscula(perfilCliente[numeroDeCliente][1]) || !noContieneEspecialesNiEspacios(perfilCliente[numeroDeCliente][1]));
                        cout << "\n-- MEtodo de pago: " << endl; 
                        cout << "1. Tarjeta de DEbito" << endl; 
                        cout << "2. Tarjeta de CrEdito" << endl; 
                        do{
                            cin >> perfilCliente[numeroDeCliente][2];
                            if (perfilCliente[numeroDeCliente][2] != "1" && (perfilCliente[numeroDeCliente][2] != "2")){
                                cout << "OpciOn no vAlida. " << endl; 
                            }
                        } while(perfilCliente[numeroDeCliente][2] != "1" && (perfilCliente[numeroDeCliente][2] != "2"));
                        if(perfilCliente[numeroDeCliente][2] == "1"){
                            cout << "Ingrese los 12 nUmeros de su tarjeta de dEbito: "; 
                            do{
                                cin >> perfilCliente[numeroDeCliente][3];
                                if(perfilCliente[numeroDeCliente][3].length() != 12 || !tieneSoloNumeros(perfilCliente[numeroDeCliente][3])){
                                    cout << "Valores invAlidos. Por favor intente de nuevo. " << endl; 
                                }
                            } while(perfilCliente[numeroDeCliente][3].length() != 12 || !tieneSoloNumeros(perfilCliente[numeroDeCliente][3]));
                        } else if(perfilCliente[numeroDeCliente][2] == "2"){
                            cout << "-- Ingrese los 12 nUmeros de su tarjeta de crEdito: "; 
                            do{
                                cin >> perfilCliente[numeroDeCliente][3];
                                if(perfilCliente[numeroDeCliente][3].length() != 12 || !tieneSoloNumeros(perfilCliente[numeroDeCliente][3])){
                                    cout << "Valores invAlidos. Por favor intente de nuevo. " << endl; 
                                }
                            } while(perfilCliente[numeroDeCliente][3].length() != 12 || !tieneSoloNumeros(perfilCliente[numeroDeCliente][3]));
                        }
                        cout << "Su registro ha sido completado. " << endl;
                        procederComprarRegistro = 'y';
                        do{
                            cout << "\nDesea proceder a comprar? (s/n) ";
                            cin >> procederComprarRegistro; 

                            if(procederComprarRegistro != 's' && procederComprarRegistro != 'n'){
                                cout << "OpciOn no vAlida. \n";
                            }
                        }while((procederComprarRegistro != 's') && (procederComprarRegistro != 'n'));
                        if(procederComprarRegistro == 's'){
                            subMenuCliente = true;
                            while(subMenuCliente == true){
                                cout << "\n--------------------------------------\n";
                                cout << "Bienvenid@ " << perfilCliente[numeroDeCliente][0] << ". Elija una opciOn (1-3): " << endl; 
                                cout << "1. Comprar" << endl;
                                cout << "2. Carrito" << endl;
                                cout << "3. Regresar" << endl;
                                cin >> subOpc4; 
                                switch(subOpc4){
                                    case '1': comprasCliente(); break;
                                    case '2': 
                                        menuCarrito = false; 
                                        for(int i = 1; i < 6; i++){
                                            if(carritoClientes[numeroDeCliente][i] != 0){
                                                menuCarrito = true; 
                                            }
                                        }
                                        if(menuCarrito == false){
                                            cout << "\nNo hay elementos en el carrito. " << endl;
                                        }
                                        while(menuCarrito == true){
                                            impresionCarrito(); 
                                            cout << "Desea proceder a comprar? (s/n) " << endl;
                                            cin >> subSubOpc4;
                                            switch(subSubOpc4){
                                                case 's': impresionTicket(); 

                                                carritoSobreDisponibilidad = true; 
                                                // Valida si la cantidad de productos en el carrito supera la disponibilidad del producto. 
                                                for(int i = 1; i < 6; i++){
                                                    if(carritoClientes[numeroDeClienteTemp][i] > cantidadProductosDisponibles[i-1]){
                                                        cout << "Lo sentimos, nuestros productos se agotaron. \nRevise nuestra sección de compras para una nueva selección de productos. \n"; 
                                                        for(int k = 1; k < 6; k++){
                                                            carritoClientes[numeroDeClienteTemp][k] = 0;
                                                            carritoCosto[numeroDeClienteTemp][k] = 0; 
                                                        }
                                                        carritoSobreDisponibilidad = false; 
                                                    } 
                                                }

                                                if(carritoSobreDisponibilidad){

                                                    for(int j = 1; j < 6; j++){
                                                        contadorProductos = carritoClientes[numeroDeClienteTemp][j];
                                                        cantidadProductosDisponibles[j-1] -= contadorProductos;
                                                        unidadesVendidas[j-1] += contadorProductos; 
                                                        reporteVentas[j-1] = unidadesVendidas[j-1] * costoProductos[j-1];
                                                    }

                                                    acumuladorCompras++;
                                                    for (int a = 0; a < acumuladorCompras; a++) { // Agregaremos N(acumuladorCompras) número de filas
                                                        vector<int> fila(maxDatosCompras, 0); // Crea una fila con el número de columnas(maxDatosCompras) especificado 
                                                        for (int b = 0; b < fila.size(); b++) { // Introduce valores al vector
                                                            fila[b] = numeroDeClienteTemp;
                                                            if (b != 0) {
                                                                for(int c = 1; c < maxDatosCompras; c++){
                                                                    fila[c] = carritoClientes[numeroDeClienteTemp][c]; // Aquí las compras almacenadas en el carrito del cliente son almacenadas en el vector 'fila'
                                                                }
                                                            }
                                                        }
                                                        ticketsProductos.push_back(fila); // Agrega la fila al vector ticketsProductos
                                                    }

                                                    for(int h = 1; h < 6; h++){
                                                        carritoClientes[numeroDeClienteTemp][h] = 0;
                                                        carritoCosto[numeroDeClienteTemp][h] = 0; 
                                                    }
                                                    menuCarrito = false;

                                                } else{
                                                    menuCarrito = false; 
                                                }

                                                break;

                                                case 'n': menuCarrito = false; break;
                                                default: cout << "OpciOn no valida. " << endl; break; 
                                            }
                                        }
                                    break; 
                                    case '3': numeroDeCliente++; subMenuCliente = false; logInCliente[0] = "0"; logInCliente[1] = "0";  clienteintentos = 3; break; 
                                    default: cout << "OpciOn no valida. " << endl; break;
                                }
                            }
                        } else if(procederComprarRegistro == 'n'){
                            procederComprarRegistro = 'n';
                            numeroDeCliente++;
                        }
                        registroCliente = false; 
                        break; 

                        case '3': menuCliente = false; break; 
                        default: cout << "OpciOn no valida. " << endl; break;
                    }
                }
                break;

            case '3': 
                cout << "Apagando sistema. Gracias. " << endl;
                return false;
            
            default: 
                cout << "OpciOn no valida. " << endl;
                break;
        }
    }
    return 0;
}

void impresionMenuCliente(){
    cout << "\n----------------------------------------------------------------\n";
    cout << "\t" << "Num. Serie" << "\t" << "DescripciOn" << "\t" << "Disponibilidad" << "\t" << "Costo" << endl;
    for(int i = 0; i < 5; i++){
        if(i!=4){
        cout << i+1 << "." << "\t" << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t\t" << cantidadProductosDisponibles[i]<< "\t\t" << "$" << costoProductos[i] << endl; 
        } else {
            cout << i+1 << "." << "\t" << numeroSerie[i] << "\t\t" << nombreComercial[i] << "\t" << cantidadProductosDisponibles[i]<< "\t\t" << "$" << costoProductos[i] << endl; 
        }
    } 
    cout << "\n6-" << "\t" << "Regresar\n"; 
    cout << "----------------------------------------------------------------\n";
    cout << "QuE producto desea aNadir a su carrito? (1-6) ";
    cin >> opc5;
    return;
}

void revisionDisponibilidadProducto(int opcion_convertida_entera){

    // NO HAY DISPONIBILIDAD
    if(cantidadProductosDisponibles[opcion_convertida_entera-1] <= 0){

        cout << "\nNo hay disponibilidad. Lo sentimos." << endl;

        do{
            cout << "Quisiera agregar algo mAs? (s/n) "; cin >> volver_a_comprar; 
            if(volver_a_comprar != 's' && volver_a_comprar != 'n'){
                cout << "OpciOn no vAlida. \n";
            }
        }while((volver_a_comprar != 's') && (volver_a_comprar != 'n'));

        if(volver_a_comprar == 's'){
            comprasCliente();
        } else if(volver_a_comprar == 'n'){
            volver_a_comprar = 'n';
        }

    // HAY DISPONIBILIDAD
    } else {

        if(registroCliente){
        numeroDeClienteTemp = numeroDeCliente; 
        } 
        
        if(carritoClientes[numeroDeClienteTemp][opcion_convertida_entera] >= cantidadProductosDisponibles[opcion_convertida_entera-1]){
            
            do{
                cout << "\nLo sentimos, no hay disponibilidad. Quisiera agregar algo mAs? (s/n) "; cin >> volver_a_comprar; 
                if(volver_a_comprar != 's' && volver_a_comprar != 'n'){
                    cout << "OpciOn no vAlida. \n";
                }
            }while((volver_a_comprar != 's') && (volver_a_comprar != 'n'));
            
            if(volver_a_comprar == 's'){
                comprasCliente();
            } else if(volver_a_comprar == 'n'){
                volver_a_comprar = 'n';
            } 

        } else {

            carritoClientes[numeroDeClienteTemp][opcion_convertida_entera] += 1; 
            carritoCosto[numeroDeClienteTemp][opcion_convertida_entera] = carritoClientes[numeroDeClienteTemp][opcion_convertida_entera] * costoProductos[opcion_convertida_entera-1];
            
            do{
                cout << "Quisiera agregar algo mAs? (s/n) "; cin >> volver_a_comprar; 
                if(volver_a_comprar != 's' && volver_a_comprar != 'n'){
                    cout << "OpciOn no vAlida. \n";
                }
            }while((volver_a_comprar != 's') && (volver_a_comprar != 'n'));

            if(volver_a_comprar == 's'){
                comprasCliente();
            } else if(volver_a_comprar == 'n'){
                volver_a_comprar = 'n';
            }    

        }
    } 

    return;
}

void comprasCliente(){

    volver_a_comprar = 'y';
    impresionMenuCliente();

    do{
        switch(opc5){
            
            case '1': 
            opc5_Int = opc5 - '0';
            revisionDisponibilidadProducto(opc5_Int);
            break;

            case '2': 
            opc5_Int = opc5 - '0';
            revisionDisponibilidadProducto(opc5_Int);
            break; 

            case '3': 
            opc5_Int = opc5 - '0';
            revisionDisponibilidadProducto(opc5_Int);
            break; 

            case '4': 
            opc5_Int = opc5 - '0';
            revisionDisponibilidadProducto(opc5_Int);
            break;

            case '5':
            opc5_Int = opc5 - '0'; 
            revisionDisponibilidadProducto(opc5_Int);
            break;

            case '6': 
            volver_a_comprar = 'n';
            cout << "Regresando a inicio... " << endl; 
            break; 

            default: cout << "OpciOn no valida. " << endl; comprasCliente(); break;
        }
    } while(volver_a_comprar != 'n' && opc5_Int != 6); 

    return;
}

// Las siguientes 5 funciones nos permiten validar si algún caracter del string introducido para 
// la contraseña del cliente:
// tieneAlMenosUnDigito, tieneAlMenosUnaMayuscula, tieneAlMenosUnaMinuscula, noContieneEspecialesNiEspacios y tieneSoloNumeros 
// Esto lo hacemos mediante ciclos FOR-EACH iterando a través de cada carácter 'c' en la cadena 'str'
// devolviendo un valor booleano si detecta un caracter no válido. 
bool tieneAlMenosUnDigito(const string& str) {
    for (char c : str) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool tieneAlMenosUnaMayuscula(const string& str) {
    for (char c : str) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

bool tieneAlMenosUnaMinuscula(const string& str) {
    for (char c : str) {
        if (islower(c)) {
            return true;
        }
    }
    return false;
}

bool noContieneEspecialesNiEspacios(const string& str) {
    for (char c : str) {
        if (!isalnum(c) || isspace(c)) {
            return false;
        }
    }
    return true;
}

bool tieneSoloNumeros(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool confirmacionUsuarioCliente(){

    // Esta función nos permite validar si es que el usuario introducido para el reacceso del cliente
    // es igual al usuario introducido al momento de crear su cuenta.
    for(int i = 0; i < sizeof(perfilCliente)/sizeof(perfilCliente[0]); i++){
        if(perfilCliente[i][0] == logInCliente[0]){
            return true; 
        }   
    } 
    return false; 
}

bool confirmacionContrasenaCliente(){
    
    // Esta función nos permite validar si es que la contraseña introducida para el reacceso del cliente
    // es igual a la contrasña introducida al momento de crear su cuenta.  
    for(int i = 0; i < sizeof(perfilCliente)/sizeof(perfilCliente[0]); i++){
        if(perfilCliente[i][1] == logInCliente[1]){
            return true; 
        }   
    } 
    return false; 
}

void impresionCarrito(){

    cout << "\n------------------------Carrito de Compras------------------------\n";
    cout << "DescripciOn" << "\t" << "Cantidad" << "\t" << "Costo" << endl;
    if(registroCliente){
        numeroDeClienteTemp = numeroDeCliente; 
    } 
    for(int i = 1; i < 6; i++){
        if(i!=5){
        cout << nombreComercial[i-1] << "\t\t" << carritoClientes[numeroDeClienteTemp][i] << "\t\t" << "$" << carritoCosto[numeroDeClienteTemp][i] << endl; 
        } else {
            cout << nombreComercial[i-1] << "     " << carritoClientes[numeroDeClienteTemp][i] << "\t\t" << "$" << carritoCosto[numeroDeClienteTemp][i] << endl; 
        }
    } 
    cout << endl << "\t\t\t\t" << "Total: $" << carritoCosto[numeroDeClienteTemp][1] + carritoCosto[numeroDeClienteTemp][2] + carritoCosto[numeroDeClienteTemp][3] + carritoCosto[numeroDeClienteTemp][4] + carritoCosto[numeroDeClienteTemp][5] << endl;
    cout << "\t\t\t\t" << "IVA (16%): $" << (carritoCosto[numeroDeClienteTemp][1] + carritoCosto[numeroDeClienteTemp][2] + carritoCosto[numeroDeClienteTemp][3] + carritoCosto[numeroDeClienteTemp][4] + carritoCosto[numeroDeClienteTemp][5]) * 0.16 << endl;
    cout << "\t\t\t\t" << "Total+IVA: $" << (carritoCosto[numeroDeClienteTemp][1] + carritoCosto[numeroDeClienteTemp][2] + carritoCosto[numeroDeClienteTemp][3] + carritoCosto[numeroDeClienteTemp][4] + carritoCosto[numeroDeClienteTemp][5]) * 1.16 << endl; 
    cout << "------------------------------------------------------------------\n";
    return;
}

void impresionTicket(){
    cout << "\n------------------------Compra Procesada------------------------\n";
    cout << "\nMEtodo de pago: ";
    if(registroCliente){
        numeroDeClienteTemp = numeroDeCliente; 
    }
    if(perfilCliente[numeroDeCliente][2] == "1"){
        cout << "Tarjeta de DEbito" << endl << "TerminaciOn de Tarjeta: "; 
        for(int i = 8; i < perfilCliente[numeroDeClienteTemp][3].size(); i++){
            cout<< perfilCliente[numeroDeClienteTemp][3][i];
        }
    } else if(perfilCliente[numeroDeClienteTemp][2] == "2"){
        cout << "Tarjeta de CrEdito" << endl << "TerminaciOn de Tarjeta: "; 
        for(int i = 8; i < perfilCliente[numeroDeClienteTemp][3].size(); i++){
            cout<< perfilCliente[numeroDeClienteTemp][3][i];
        }
    }
    cout << "\n\nDescripciOn" << "\t" << "Cantidad" << "\t" << "Costo" << endl;
    for(int i = 1; i < 6; i++){
        if(i!=5){
            cout << nombreComercial[i-1] << "\t\t" << carritoClientes[numeroDeClienteTemp][i] << "\t\t" << "$" << carritoCosto[numeroDeClienteTemp][i] << endl; 
        } else {
            cout << nombreComercial[i-1] << "     " << carritoClientes[numeroDeClienteTemp][i] << "\t\t" << "$" << carritoCosto[numeroDeClienteTemp][i] << endl; 
        }
    } 
    cout << endl << "\t\t\t\t" << "Total: $" << carritoCosto[numeroDeClienteTemp][1] + carritoCosto[numeroDeClienteTemp][2] + carritoCosto[numeroDeClienteTemp][3] + carritoCosto[numeroDeClienteTemp][4] + carritoCosto[numeroDeClienteTemp][5] << endl;
    cout << "\t\t\t\t" << "IVA (16%): $" << (carritoCosto[numeroDeClienteTemp][1] + carritoCosto[numeroDeClienteTemp][2] + carritoCosto[numeroDeClienteTemp][3] + carritoCosto[numeroDeClienteTemp][4] + carritoCosto[numeroDeClienteTemp][5]) * 0.16 << endl;
    cout << "\t\t\t\t" << "Total+IVA: $" << (carritoCosto[numeroDeClienteTemp][1] + carritoCosto[numeroDeClienteTemp][2] + carritoCosto[numeroDeClienteTemp][3] + carritoCosto[numeroDeClienteTemp][4] + carritoCosto[numeroDeClienteTemp][5]) * 1.16 << endl;
    cout << "Gracias por su compra " << perfilCliente[numeroDeClienteTemp][0] << "!" << endl; 
    cout << "------------------------------------------------------------------\n";

    return;
}

void impresionResumenTickets(){

    int l = 0, o = 1, A = 0; 

    // El vector ticketsProductos tiene la siguiente estructura en su columna [0] por cada fila. Cada número es una compra.
    /* 
    [n][0]   # Compra      'n'  Posiciones Necesarias
      0          0          0           0
      1                     1
      1          1          2           2
      2                     3
      2                     4
      2          2          5           5
      3                     6
      3                     7
      3                     8
      3          3          9           9
    */      
   // Debido a que utilizamos la función push_back con el vector ticketsProductos para añadir filas por cada compra realizada, 
   // filas sobrantes son añadidas a la par siguiendo el siguiente algoritmo: 
   // a = 0; b = 0; c = 1; X = a + b; b += c; a++; c++;
   // X ahora dandonos como resultado la siguiente secuencia: 0, 2, 5, 9, 14, 21, 27 etc.
   // Este ciclo FOR nos permite asociar e impimir los datos de los vectores y arreglos en las posiciones respectivas de la información de la compra, 
   // omitiendo, de ese modo, los datos innecesarios sobrantes de cada linea de ticketsProductos. 
    for(int i = 0; i < ticketsProductos.size(); i++){

        float costoResumenTickets = 0;
        A = i + l;
        l += o;
        o++;

        if(A < ticketsProductos.size()){
            int filaCliente = ticketsProductos[A][0]; // ticketsProductos[A][0] también es igual al número del cliente en la compra
            cout << "\n\n-------------------Usuario: " << perfilCliente[filaCliente][0] << "-----------------\n";
            cout << "\nMEtodo de pago: ";
            if(perfilCliente[filaCliente][2] == "1"){
                cout << "Tarjeta de DEbito" << endl << "TerminaciOn de Tarjeta: "; 
                for(int j = 8; j < perfilCliente[filaCliente][3].size(); j++){ 
                    cout << perfilCliente[filaCliente][3][j];
                }
            } else if(perfilCliente[filaCliente][2] == "2"){
                cout << "Tarjeta de CrEdito" << endl << "TerminaciOn de Tarjeta: "; 
                for(int k = 8; k < perfilCliente[filaCliente][3].size(); k++){
                    cout<< perfilCliente[filaCliente][3][k];
                }
            }
            cout << "\n\nDescripciOn" << "\t" << "Cantidad" << "\t" << "Costo" << endl;
            for (int h = 1; h < maxDatosCompras; ++h) { // h nos permite ubicarnos en las columnas de la información del carrito del cliente
                if(h!=5){
                    cout << nombreComercial[h-1] << "\t\t" << ticketsProductos[A][h] << "\t\t" << "$" << ticketsProductos[A][h]*costoProductos[h-1] << endl; 
                } else {
                    cout << nombreComercial[h-1] << "     " << ticketsProductos[A][h] << "\t\t" << "$" << ticketsProductos[A][h]*costoProductos[h-1] << endl; 
                }
                costoResumenTickets += ticketsProductos[i][h]*costoProductos[h-1];
            }
            cout << endl << "\t\t\t\t" << "Total: $" << costoResumenTickets << endl;
            cout << "\t\t\t\t" << "Total+IVA: $" << costoResumenTickets * 1.16 << endl;
            cout << "Gracias por su compra!" << endl; 
            cout << "------------------------------------------------------------------\n" << endl;
            costoResumenTickets = 0;
        } 
    } 
}
