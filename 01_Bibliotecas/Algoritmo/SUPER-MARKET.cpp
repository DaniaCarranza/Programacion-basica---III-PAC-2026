#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ==========================================
// FUNCIONES ESPECIFICADAS EN EL ALGORITMO
// ==========================================

// 1. FUNCION POR VALOR: Calcula el subtotal (precio * cantidad)
double calcularSubtotal(double precio, double cantidad) {
    return precio * cantidad;
}

// 2. FUNCION POR VALOR: Calcula el descuento según un porcentaje
double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje;
}

// 3. FUNCION POR REFERENCIA: Modifica los acumuladores generales y de unidades/libras vendidas
void acumularVenta(double &subtotalGeneral, double &totalVendidas, double subtotal, double cantidad) {
    subtotalGeneral += subtotal;
    totalVendidas += cantidad;
}

// 4. FUNCION POR REFERENCIA: Calcula los impuestos ISV general (15%) y adicional en licores (3%)
void calcularImpuestos(double base, double baseLicores, double &impuestoISV, double &impuestoLicores) {
    impuestoISV = base * 0.15;
    impuestoLicores = baseLicores * 0.03;
}

// 5. FUNCION POR VALOR: Valida si la cantidad supera el stock disponible
bool validarStock(double cantidad, double stockTotal) {
    return cantidad > stockTotal;
}

int main() {
    int edadCliente, tipoCliente, diaSemana;
    char continuarCompra = 's';

    cout << "=== SISTEMA DE VENTAS SUPERMERCADO ===\n";

    // Validacion de rango de edad (15 - 100)
    do {
        cout << "Ingrese la edad del cliente (15 - 100): ";
        cin >> edadCliente;
        if (edadCliente < 15 || edadCliente > 100) {
            cout << "[ERROR] Edad fuera de rango. Intente de nuevo.\n";
        }
    } while (edadCliente < 15 || edadCliente > 100);

    // Validacion de tipo de cliente (1, 2 o 3)
    do {
        cout << "Tipo de cliente (1. Cliente estrella, 2. Cliente Regular, 3. Cliente nuevo): ";
        cin >> tipoCliente;
        if (tipoCliente < 1 || tipoCliente > 3) {
            cout << "[ERROR] Tipo de cliente invalido. Intente de nuevo.\n";
        }
    } while (tipoCliente < 1 || tipoCliente > 3);

    // Validacion de dia de la semana (1 - 7)
    do {
        cout << "Dia de la semana (1=Lunes, 2=Martes, 3=Miercoles, 4=Jueves, 5=Viernes, 6=Sabado, 7=Domingo): ";
        cin >> diaSemana;
        if (diaSemana < 1 || diaSemana > 7) {
            cout << "[ERROR] Dia invalido. Intente de nuevo.\n";
        }
    } while (diaSemana < 1 || diaSemana > 7);

    // Stocks iniciales
    double stockTomates = 100, stockRepollo = 100, stockPapas = 100;
    double stockCarneMolida = 100, stockCarneDeCerdo = 100, stockCarneAsar = 100;
    double stockCervezaN = 100, stockCervezaE = 100, stockVino = 100, stockVodka = 100;

    // Acumuladores de Clientes (libras/unidades)
    double librasTomatesCliente = 0, librasRepolloCliente = 0, librasPapazCliente = 0;
    double librasCarneMolidaCliente = 0, librasCarneDeCerdoCliente = 0, librasCarneAsarCliente = 0;
    double unidadesCervezaNCliente = 0, unidadesCervezaECliente = 0, unidadesVinoCliente = 0, unidadesVodkaCliente = 0;

    // Acumuladores de Subtotales por producto
    double subtotalTomates = 0, subtotalRepollo = 0, subtotalPapas = 0;
    double subtotalCarneMolida = 0, subtotalCarneDeCerdo = 0, subtotalCarneAsar = 0;
    double subtotalCervezaN = 0, subtotalCervezaE = 0, subtotalVino = 0, subtotalVodka = 0;

    // Totales vendidos generales
    double totalLibrosTomates = 0, totalLibrosRepollo = 0, totalLibrosPapas = 0;
    double totalLibrosCarneMolida = 0, totalLibrosCarneDeCerdo = 0, totalLibrosCarneAsar = 0;
    double totalUnidadesCervezaN = 0, totalUnidadesCervezaE = 0, totalUnidadesVino = 0, totalUnidadesVodka = 0;

    int contadorCarnes = 0;

     while (continuarCompra == 's' || continuarCompra == 'S') {
        char opcionMenu;
        cout << "\n--- MODULO 1: SELECCION DE PRODUCTO ---\n";
        cout << "Seleccione area (V = Verduras, C = Carnes, L = Licores): ";
        cin >> opcionMenu;

        if (opcionMenu == 'V' || opcionMenu == 'v') {
            int opcionVerduras;
            do {
                cout << "\n1- Tomates (L. 10)\n2- Repollo (L. 15)\n3- Papas (L. 17)\nElija opcion: ";
                cin >> opcionVerduras;
                if (opcionVerduras < 1 || opcionVerduras > 3) {
                    cout << "[ERROR] Opcion para verduras incorrecta. Intente de nuevo.\n";
                }
            } while (opcionVerduras < 1 || opcionVerduras > 3);

            double cantidad;
            double *stockActual = nullptr;
            double *librasCliente = nullptr;
            double *subtotalProd = nullptr;
            double *totalGen = nullptr;
            double precio = 0;

            if (opcionVerduras == 1) {
                stockActual = &stockTomates; librasCliente = &librasTomatesCliente;
                subtotalProd = &subtotalTomates; totalGen = &totalLibrosTomates; precio = 10.0;
            } else if (opcionVerduras == 2) {
                stockActual = &stockRepollo; librasCliente = &librasRepolloCliente;
                subtotalProd = &subtotalRepollo; totalGen = &totalLibrosRepollo; precio = 15.0;
            } else if (opcionVerduras == 3) {
                stockActual = &stockPapas; librasCliente = &librasPapazCliente;
                subtotalProd = &subtotalPapas; totalGen = &totalLibrosPapas; precio = 17.0;
            }

            do {
                cout << "Ingrese la cantidad en libras (Stock disponible: " << *stockActual << "): ";
                cin >> cantidad;
                if (cantidad <= 0) {
                    cout << "[ERROR] La cantidad debe ser mayor a 0.\n";
                } else if (validarStock(cantidad, *stockActual)) {
                    cout << "[ERROR] Cantidad supera el stock disponible.\n";
                }
            } while (cantidad <= 0 || validarStock(cantidad, *stockActual));

            *librasCliente += cantidad;
            *stockActual -= cantidad;
            double subtotalActual = calcularSubtotal(precio, cantidad);
            acumularVenta(*subtotalProd, *totalGen, subtotalActual, cantidad);

        } else if (opcionMenu == 'C' || opcionMenu == 'c') {
            int opcionCarnes;
            do {
                cout << "\n1- Carne Molida (L. 50)\n2- Carne de Cerdo (L. 70)\n3- Carne para Asar (L. 75)\nElija opcion: ";
                cin >> opcionCarnes;
                if (opcionCarnes < 1 || opcionCarnes > 3) {
                    cout << "[ERROR] Opcion para carnes incorrecta. Intente de nuevo.\n";
                }
            } while (opcionCarnes < 1 || opcionCarnes > 3);

            double cantidad;
            double *stockActual = nullptr;
            double *librasCliente = nullptr;
            double *subtotalProd = nullptr;
            double *totalGen = nullptr;
            double precio = 0;
               if (opcionCarnes == 1) {
                stockActual = &stockCarneMolida; librasCliente = &librasCarneMolidaCliente;
                subtotalProd = &subtotalCarneMolida; totalGen = &totalLibrosCarneMolida; precio = 50.0;
            } else if (opcionCarnes == 2) {
                stockActual = &stockCarneDeCerdo; librasCliente = &librasCarneDeCerdoCliente;
                subtotalProd = &subtotalCarneDeCerdo; totalGen = &totalLibrosCarneDeCerdo; precio = 70.0;
            } else if (opcionCarnes == 3) {
                stockActual = &stockCarneAsar; librasCliente = &librasCarneAsarCliente;
                subtotalProd = &subtotalCarneAsar; totalGen = &totalLibrosCarneAsar; precio = 75.0;
            }

            do {
                cout << "Ingrese la cantidad en libras (Stock disponible: " << *stockActual << "): ";
                cin >> cantidad;
                if (cantidad <= 0) {
                    cout << "[ERROR] La cantidad debe ser mayor a 0.\n";
                } else if (validarStock(cantidad, *stockActual)) {
                    cout << "[ERROR] Cantidad supera el stock disponible.\n";
                }
            } while (cantidad <= 0 || validarStock(cantidad, *stockActual));

            contadorCarnes++;
            *librasCliente += cantidad;
            *stockActual -= cantidad;
            double subtotalActual = calcularSubtotal(precio, cantidad);
            acumularVenta(*subtotalProd, *totalGen, subtotalActual, cantidad);

        } else if (opcionMenu == 'L' || opcionMenu == 'l') {
            if (edadCliente < 18) {
                cout << "[PROHIBIDO] Prohibido vender licores a menores de 18 anos.\n";
            } else {
                int opcionLicores;
                do {
                    cout << "\n1- Cerveza Nacional (L. 50)\n2- Cerveza Extranjera (L. 80)\n3- Vino (L. 200)\n4- Vodka (L. 100)\nElija opcion: ";
                    cin >> opcionLicores;
                    if (opcionLicores < 1 || opcionLicores > 4) {
                        cout << "[ERROR] Opcion incorrecta de licores. Intente de nuevo.\n";
                    }
                } while (opcionLicores < 1 || opcionLicores > 4);

                double cantidad;
                double *stockActual = nullptr;
                double *unidadesCliente = nullptr;
                double *subtotalProd = nullptr;
                double *totalGen = nullptr;
                double precio = 0;

                if (opcionLicores == 1) {
                    stockActual = &stockCervezaN; unidadesCliente = &unidadesCervezaNCliente;
                    subtotalProd = &subtotalCervezaN; totalGen = &totalUnidadesCervezaN; precio = 50.0;
                } else if (opcionLicores == 2) {
                    stockActual = &stockCervezaE; unidadesCliente = &unidadesCervezaECliente;
                    subtotalProd = &subtotalCervezaE; totalGen = &totalUnidadesCervezaE; precio = 80.0;
                      } else if (opcionLicores == 3) {
                    stockActual = &stockVino; unidadesCliente = &unidadesVinoCliente;
                    subtotalProd = &subtotalVino; totalGen = &totalUnidadesVino; precio = 200.0;
                } else if (opcionLicores == 4) {
                    stockActual = &stockVodka; unidadesCliente = &unidadesVodkaCliente;
                    subtotalProd = &subtotalVodka; totalGen = &totalUnidadesVodka; precio = 100.0;
                }

                do {
                    cout << "Ingrese la cantidad en unidades (Stock disponible: " << *stockActual << "): ";
                    cin >> cantidad;
                    if (cantidad <= 0) {
                        cout << "[ERROR] La cantidad debe ser mayor a 0.\n";
                    } else if (validarStock(cantidad, *stockActual)) {
                        cout << "[ERROR] Cantidad supera el stock disponible.\n";
                    }
                } while (cantidad <= 0 || validarStock(cantidad, *stockActual));

                *unidadesCliente += cantidad;
                *stockActual -= cantidad;
                double subtotalActual = calcularSubtotal(precio, cantidad);
                acumularVenta(*subtotalProd, *totalGen, subtotalActual, cantidad);
            }
        } else {
            cout << "[ERROR] Opcion de menu invalida. Intente de nuevo.\n";
            continue;
        }

        do {
            cout << "\nDesea seguir comprando? (S/N): ";
            cin >> continuarCompra;
            if (continuarCompra != 's' && continuarCompra != 'S' && continuarCompra != 'n' && continuarCompra != 'N') {
                cout << "[ERROR] Respuesta invalida. Ingrese S o N.\n";
            }
        } while (continuarCompra != 's' && continuarCompra != 'S' && continuarCompra != 'n' && continuarCompra != 'N');
    }

    // ==========================================
    // PROCESAMIENTO DE TOTALES Y DESCUENTOS
    // ==========================================
    double subtotalVerduras = subtotalTomates + subtotalRepollo + subtotalPapas;
    double subtotalCarnes = subtotalCarneMolida + subtotalCarneDeCerdo + subtotalCarneAsar;
    double subtotalLicores = subtotalCervezaN + subtotalCervezaE + subtotalVino + subtotalVodka;
    double subtotalCliente = subtotalVerduras + subtotalCarnes + subtotalLicores;

    double descuentoClienteEstrella = 0;
    double descuentoClienteRegular = 0;
    double descuentoClienteNuevo = 0;
    double descuentoDiaSemana = 0;
    double descuentoViernes = 0;
    double descuentoSegundoProducto = 0;
    double descuentoSixpack = 0;

    // Descuento por tipo de cliente
    if (tipoCliente == 1) {
        descuentoClienteEstrella = calcularDescuento(subtotalCarnes + subtotalVerduras, 0.04);
    } else if (tipoCliente == 2) {
        descuentoClienteRegular = calcularDescuento(subtotalCarnes, 0.03);
    } else if (tipoCliente == 3) {
        descuentoClienteNuevo = calcularDescuento(subtotalLicores, 0.02);
    }

    // Descuento por dia (Lunes = 1 o Miercoles = 3)
    if (diaSemana == 1 || diaSemana == 3) {
        descuentoDiaSemana = calcularDescuento(subtotalCliente, 0.03);
    }

    // Descuento Viernes para tercera edad (Viernes = 5)
    if (diaSemana == 5 && edadCliente >= 65) {
        descuentoViernes = calcularDescuento(subtotalCliente, 0.10);
    }

    // Descuento segundo producto en carnes (50%)
    if (contadorCarnes >= 2) {
        descuentoSegundoProducto = subtotalCarnes * 0.50;
    }

    // Descuento Six-pack de cerveza (L. 10 por cada 6 cervezas)
    double totalCervezas = unidadesCervezaNCliente + unidadesCervezaECliente;
    descuentoSixpack = (static_cast<int>(totalCervezas) / 6) * 10.0;

    // Total Descuentos
    double descuentoTotal = descuentoClienteEstrella + descuentoClienteRegular + descuentoClienteNuevo +
                            descuentoDiaSemana + descuentoViernes + descuentoSegundoProducto + descuentoSixpack;

    double subtotalConDescuento = subtotalCliente - descuentoTotal;

    // Impuestos
    double impuestoISV = 0, impuestoLicores = 0;
    calcularImpuestos(subtotalConDescuento, subtotalLicores, impuestoISV, impuestoLicores);
    double impuestoTotal = impuestoISV + impuestoLicores;

    double totalPagarLempiras = subtotalConDescuento + impuestoTotal;
    double tipoCambio = 24.5;
    double totalDolares = totalPagarLempiras / tipoCambio;

    // ==========================================
    // SALIDA (FACTURA)
    // ==========================================
    cout << "\n========================================\n";
    cout << "           FACTURA SUPERMERCADO         \n";
    cout << "========================================\n";
    cout << fixed << setprecision(2);
    cout << " Subtotal:          L. " << subtotalCliente << endl;
    cout << " Descuentos:        L. " << descuentoTotal << endl;
    cout << " Impuestos:         L. " << impuestoTotal << endl;
    cout << " Total a pagar:     L. " << totalPagarLempiras << endl;
    cout << " Total en Dolares:  $  " << totalDolares << endl;
    cout << "========================================\n";

    return 0;
}