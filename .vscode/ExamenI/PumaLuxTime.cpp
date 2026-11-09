#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//Dania Maricela Carranza Salgado
//20181007873

// ======================================================
// PUMA LUX TIME - JOYERIA Y ACCESORIOS
//           Programacion Basica 
// ======================================================

// Inventario inicial
int inv1 = 12, inv2 = 10, inv3 = 8;
int inv4 = 18, inv5 = 12, inv6 = 10;
int inv7 = 22, inv8 = 20, inv9 = 14;
int inv10 = 10, inv11 = 8, inv12 = 30;

// Unidades vendidas durante el dia
int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
int v5 = 0, v6 = 0, v7 = 0, v8 = 0;
int v9 = 0, v10 = 0, v11 = 0, v12 = 0;

// Estadisticas generales
double ganRelojes = 0, ganCadenas = 0, ganPulseras = 0;
double ganSets = 0, ganAccesorios = 0;
double descuentosDia = 0, isvDia = 0, totalDia = 0;

int pagosEfectivo = 0, pagosTransferencia = 0;

// ------------------------------------------------------
// Lee un numero entero y vuelve a pedirlo si no es valido
// ------------------------------------------------------
int leerEntero(string mensaje, int minimo, int maximo)
{
    int dato;

    while (true)
    {
        cout << mensaje;
        cin >> dato;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada no valida. Ingrese un numero." << endl;
        }
        else if (dato < minimo || dato > maximo)
        {
            cout << "Opcion fuera de rango. Elija nuevamente." << endl;
        }
        else
        {
            return dato;
        }
    }
}

// ------------------------------------------------------
// Lee texto y no permite que quede vacio
// ------------------------------------------------------
string leerTexto(string mensaje)
{
    string dato;

    while (true)
    {
        cout << mensaje;
        getline(cin >> ws, dato);

        if (dato == "")
            cout << "Este campo no puede quedar vacio. Intente de nuevo." << endl;
        else
            return dato;
    }
}

// ------------------------------------------------------
// Lee una letra permitida
// ------------------------------------------------------
char leerLetra(string mensaje, char opcion1, char opcion2)
{
    char dato;

    while (true)
    {
        cout << mensaje;
        cin >> dato;

        if (dato == opcion1 || dato == opcion2 ||
            dato == opcion1 + 32 || dato == opcion2 + 32)
            return dato;

        cout << "Opcion no valida. Elija " << opcion1
             << " o " << opcion2 << "." << endl;
    }
}

// ------------------------------------------------------
// Menu de productos
// ------------------------------------------------------
void mostrarProductos()
{
    cout << "\n====================================================" << endl;
    cout << "                 PUMA LUX TIME" << endl;
    cout << "              JOYERIA Y ACCESORIOS" << endl;
    cout << "====================================================" << endl;
    cout << "CODIGO  PRODUCTO                         PRECIO   STOCK" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1  Reloj Clasico Puma Classic          L.1450   " << inv1 << endl;
    cout << "2  Reloj Deportivo Puma Sport          L.1900   " << inv2 << endl;
    cout << "3  Smartwatch Puma Smart X             L.3600   " << inv3 << endl;
    cout << "4  Cadena acero delgada                L.780    " << inv4 << endl;
    cout << "5  Cadena acero gruesa                 L.1150   " << inv5 << endl;
    cout << "6  Cadena bano oro                     L.1650   " << inv6 << endl;
    cout << "7  Pulsera cuero                       L.420    " << inv7 << endl;
    cout << "8  Pulsera acero                       L.650    " << inv8 << endl;
    cout << "9  Pulsera bano oro                    L.980    " << inv9 << endl;
    cout << "10 Set cadena + pulsera acero          L.1350   " << inv10 << endl;
    cout << "11 Set cadena + pulsera bano oro       L.2200   " << inv11 << endl;
    cout << "12 Aretes (par)                       L.350    " << inv12 << endl;
    cout << "0  Finalizar seleccion de productos" << endl;
    cout << "====================================================" << endl;
}

// ------------------------------------------------------
// Agrega un producto al carrito
// ------------------------------------------------------
void agregarProducto(int codigo, int cantidad,
                     int &q1, int &q2, int &q3, int &q4,
                     int &q5, int &q6, int &q7, int &q8,
                     int &q9, int &q10, int &q11, int &q12)
{
    switch (codigo)
    {
        case 1:
            if (cantidad > inv1)
                cout << "Stock insuficiente. Disponible: " << inv1 << endl;
            else
            {
                q1 += cantidad;
                inv1 -= cantidad;
                v1 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 2:
            if (cantidad > inv2)
                cout << "Stock insuficiente. Disponible: " << inv2 << endl;
            else
            {
                q2 += cantidad;
                inv2 -= cantidad;
                v2 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 3:
            if (cantidad > inv3)
                cout << "Stock insuficiente. Disponible: " << inv3 << endl;
            else
            {
                q3 += cantidad;
                inv3 -= cantidad;
                v3 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 4:
            if (cantidad > inv4)
                cout << "Stock insuficiente. Disponible: " << inv4 << endl;
            else
            {
                q4 += cantidad;
                inv4 -= cantidad;
                v4 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 5:
            if (cantidad > inv5)
                cout << "Stock insuficiente. Disponible: " << inv5 << endl;
            else
            {
                q5 += cantidad;
                inv5 -= cantidad;
                v5 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 6:
            if (cantidad > inv6)
                cout << "Stock insuficiente. Disponible: " << inv6 << endl;
            else
            {
                q6 += cantidad;
                inv6 -= cantidad;
                v6 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 7:
            if (cantidad > inv7)
                cout << "Stock insuficiente. Disponible: " << inv7 << endl;
            else
            {
                q7 += cantidad;
                inv7 -= cantidad;
                v7 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 8:
            if (cantidad > inv8)
                cout << "Stock insuficiente. Disponible: " << inv8 << endl;
            else
            {
                q8 += cantidad;
                inv8 -= cantidad;
                v8 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 9:
            if (cantidad > inv9)
                cout << "Stock insuficiente. Disponible: " << inv9 << endl;
            else
            {
                q9 += cantidad;
                inv9 -= cantidad;
                v9 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 10:
            if (cantidad > inv10)
                cout << "Stock insuficiente. Disponible: " << inv10 << endl;
            else
            {
                q10 += cantidad;
                inv10 -= cantidad;
                v10 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 11:
            if (cantidad > inv11)
                cout << "Stock insuficiente. Disponible: " << inv11 << endl;
            else
            {
                q11 += cantidad;
                inv11 -= cantidad;
                v11 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;

        case 12:
            if (cantidad > inv12)
                cout << "Stock insuficiente. Disponible: " << inv12 << endl;
            else
            {
                q12 += cantidad;
                inv12 -= cantidad;
                v12 += cantidad;
                cout << "Producto agregado al carrito." << endl;
            }
            break;
    }
}

// ------------------------------------------------------
// Estadisticas finales del dia
// ------------------------------------------------------
void mostrarEstadisticas()
{
    int mayor = 0, menor = 0;
    string nombreMayor = "Ninguno", nombreMenor = "Ninguno";

    // Producto mas vendido
    if (v1 > mayor) { mayor = v1; nombreMayor = "Reloj Clasico Puma Classic"; }
    if (v2 > mayor) { mayor = v2; nombreMayor = "Reloj Deportivo Puma Sport"; }
    if (v3 > mayor) { mayor = v3; nombreMayor = "Smartwatch Puma Smart X"; }
    if (v4 > mayor) { mayor = v4; nombreMayor = "Cadena acero delgada"; }
    if (v5 > mayor) { mayor = v5; nombreMayor = "Cadena acero gruesa"; }
    if (v6 > mayor) { mayor = v6; nombreMayor = "Cadena bano oro"; }
    if (v7 > mayor) { mayor = v7; nombreMayor = "Pulsera cuero"; }
    if (v8 > mayor) { mayor = v8; nombreMayor = "Pulsera acero"; }
    if (v9 > mayor) { mayor = v9; nombreMayor = "Pulsera bano oro"; }
    if (v10 > mayor) { mayor = v10; nombreMayor = "Set cadena + pulsera acero"; }
    if (v11 > mayor) { mayor = v11; nombreMayor = "Set cadena + pulsera bano oro"; }
    if (v12 > mayor) { mayor = v12; nombreMayor = "Aretes"; }

    // Producto menos vendido, excluyendo productos sin ventas
    if (v1 > 0) { menor = v1; nombreMenor = "Reloj Clasico Puma Classic"; }
    if (v2 > 0 && (menor == 0 || v2 < menor)) { menor = v2; nombreMenor = "Reloj Deportivo Puma Sport"; }
    if (v3 > 0 && (menor == 0 || v3 < menor)) { menor = v3; nombreMenor = "Smartwatch Puma Smart X"; }
    if (v4 > 0 && (menor == 0 || v4 < menor)) { menor = v4; nombreMenor = "Cadena acero delgada"; }
    if (v5 > 0 && (menor == 0 || v5 < menor)) { menor = v5; nombreMenor = "Cadena acero gruesa"; }
    if (v6 > 0 && (menor == 0 || v6 < menor)) { menor = v6; nombreMenor = "Cadena bano oro"; }
    if (v7 > 0 && (menor == 0 || v7 < menor)) { menor = v7; nombreMenor = "Pulsera cuero"; }
    if (v8 > 0 && (menor == 0 || v8 < menor)) { menor = v8; nombreMenor = "Pulsera acero"; }
    if (v9 > 0 && (menor == 0 || v9 < menor)) { menor = v9; nombreMenor = "Pulsera bano oro"; }
    if (v10 > 0 && (menor == 0 || v10 < menor)) { menor = v10; nombreMenor = "Set cadena + pulsera acero"; }
    if (v11 > 0 && (menor == 0 || v11 < menor)) { menor = v11; nombreMenor = "Set cadena + pulsera bano oro"; }
    if (v12 > 0 && (menor == 0 || v12 < menor)) { menor = v12; nombreMenor = "Aretes"; }

    cout << fixed << setprecision(2);

    cout << "\n\n====================================================" << endl;
    cout << "             ESTADISTICAS DEL DIA" << endl;
    cout << "====================================================" << endl;

    if (mayor == 0)
        cout << "Producto mas vendido: No hubo ventas." << endl;
    else
        cout << "Producto mas vendido: " << nombreMayor
             << " (" << mayor << " unidades)" << endl;

    if (menor == 0)
        cout << "Producto menos vendido: No hubo ventas." << endl;
    else
        cout << "Producto menos vendido: " << nombreMenor
             << " (" << menor << " unidades)" << endl;

    cout << "\nGanancias por categoria (sin ISV):" << endl;
    cout << "Relojes:     L. " << ganRelojes << endl;
    cout << "Cadenas:     L. " << ganCadenas << endl;
    cout << "Pulseras:    L. " << ganPulseras << endl;
    cout << "Sets:        L. " << ganSets << endl;
    cout << "Accesorios:  L. " << ganAccesorios << endl;

    cout << "\nDescuentos aplicados: L. " << descuentosDia << endl;
    cout << "ISV recaudado:        L. " << isvDia << endl;
    cout << "Total vendido:        L. " << totalDia << endl;
    cout << "Total en dolares:     $ " << totalDia / 26.42 << endl;

    cout << "\nMetodo de pago mas utilizado:" << endl;

    if (pagosEfectivo > pagosTransferencia)
        cout << "Efectivo (" << pagosEfectivo << " veces)" << endl;
    else if (pagosTransferencia > pagosEfectivo)
        cout << "Transferencia (" << pagosTransferencia << " veces)" << endl;
    else
        cout << "Empate entre efectivo y transferencia." << endl;

    cout << "====================================================" << endl;
}

// ======================================================
// PROGRAMA PRINCIPAL
// ======================================================
int main()
{
    char otroCliente = 'S';

    while (otroCliente == 'S' || otroCliente == 's')
    {
        // Datos del cliente
        string nombre;
        int edad, tipoCliente;
        char sexo;

        cout << "\n\n============================================" << endl;
        cout << "       BIENVENIDO A PUMA LUX TIME" << endl;
        cout << "============================================" << endl;

        nombre = leerTexto("Nombre del cliente: ");
        edad = leerEntero("Edad (1 a 120): ", 1, 120);
        sexo = leerLetra("Sexo (F = Femenino / M = Masculino): ", 'F', 'M');

        cout << "\nTIPO DE CLIENTE" << endl;
        cout << "1. Regular - 5% en Pulseras" << endl;
        cout << "2. VIP - 10% en Relojes" << endl;
        cout << "3. Mayorista - 12% en Cadenas y Sets" << endl;

        tipoCliente = leerEntero("Seleccione tipo de cliente (1-3): ", 1, 3);

        // Carrito individual del cliente
        int q1=0, q2=0, q3=0, q4=0, q5=0, q6=0;
        int q7=0, q8=0, q9=0, q10=0, q11=0, q12=0;

        int codigo, cantidad;
        bool tieneProductos = false;
        char seguir = 'S';

        // El cliente debe agregar al menos un producto
        while (!tieneProductos || seguir == 'S' || seguir == 's')
        {
            mostrarProductos();

            codigo = leerEntero("Seleccione codigo (0 para terminar): ", 0, 12);

            if (codigo == 0)
            {
                if (!tieneProductos)
                {
                    cout << "\nEl carrito esta vacio. Debe agregar al menos un producto." << endl;
                    cout << "Elija un producto del menu para continuar." << endl;
                    seguir = 'S';
                    continue;
                }
                else
                    break;
            }

            cantidad = leerEntero("Ingrese cantidad (mayor que 0): ", 1, 10000);

            // Validar stock antes de agregar
            bool stockCorrecto = true;

            switch (codigo)
            {
                case 1: if (cantidad > inv1) stockCorrecto = false; break;
                case 2: if (cantidad > inv2) stockCorrecto = false; break;
                case 3: if (cantidad > inv3) stockCorrecto = false; break;
                case 4: if (cantidad > inv4) stockCorrecto = false; break;
                case 5: if (cantidad > inv5) stockCorrecto = false; break;
                case 6: if (cantidad > inv6) stockCorrecto = false; break;
                case 7: if (cantidad > inv7) stockCorrecto = false; break;
                case 8: if (cantidad > inv8) stockCorrecto = false; break;
                case 9: if (cantidad > inv9) stockCorrecto = false; break;
                case 10: if (cantidad > inv10) stockCorrecto = false; break;
                case 11: if (cantidad > inv11) stockCorrecto = false; break;
                case 12: if (cantidad > inv12) stockCorrecto = false; break;
            }

            if (!stockCorrecto)
            {
                cout << "\nSTOCK INSUFICIENTE. Elija otra cantidad o producto." << endl;
                continue;
            }

            agregarProducto(codigo, cantidad,
                q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12);

            tieneProductos = true;

            cout << "\nDesea agregar otro producto? (S/N): ";
            seguir = leerLetra("", 'S', 'N');

            if (seguir == 'N' || seguir == 'n')
                break;
        }

        // ==================================================
        // CALCULO DE SUBTOTAL Y DESCUENTOS
        // ==================================================

        double subtotal = 0, descuentos = 0;
        int puntos = 0;

        // Precios por producto
        double b1=q1*1450.0, b2=q2*1900.0, b3=q3*3600.0;
        double b4=q4*780.0, b5=q5*1150.0, b6=q6*1650.0;
        double b7=q7*420.0, b8=q8*650.0, b9=q9*980.0;
        double b10=q10*1350.0, b11=q11*2200.0, b12=q12*350.0;

        subtotal = b1+b2+b3+b4+b5+b6+b7+b8+b9+b10+b11+b12;

        // Descuentos individuales por producto
        double d1=0,d2=0,d3=0,d4=0,d5=0,d6=0;
        double d7=0,d8=0,d9=0,d10=0,d11=0,d12=0;

        // Acumuladores para mostrar el desglose en factura
        double descTipoCliente = 0;
        double descSexo = 0;
        double descEdad = 0;
        double descSetPremium = 0;
        double descVolumen = 0;
        double descCombo = 0;

        // --------------------------------------------------
        // DESCUENTO POR TIPO DE CLIENTE
        // --------------------------------------------------
        if (tipoCliente == 1)
        {
            descTipoCliente = (b7+b8+b9)*0.05;

            d7 += b7*0.05;
            d8 += b8*0.05;
            d9 += b9*0.05;
        }

        if (tipoCliente == 2)
        {
            descTipoCliente = (b1+b2+b3)*0.10;

            d1 += b1*0.10;
            d2 += b2*0.10;
            d3 += b3*0.10;
        }

        if (tipoCliente == 3)
        {
            descTipoCliente = (b4+b5+b6+b10+b11)*0.12;

            d4 += b4*0.12;
            d5 += b5*0.12;
            d6 += b6*0.12;
            d10 += b10*0.12;
            d11 += b11*0.12;
        }

        // --------------------------------------------------
        // DESCUENTO POR SEXO
        // --------------------------------------------------
        if (sexo == 'F' || sexo == 'f')
        {
            descSexo = (b7+b8+b9)*0.08;

            d7 += b7*0.08;
            d8 += b8*0.08;
            d9 += b9*0.08;
        }

        if (sexo == 'M' || sexo == 'm')
        {
            descSexo = (b1+b2+b3)*0.05;

            d1 += b1*0.05;
            d2 += b2*0.05;
            d3 += b3*0.05;
        }

        // --------------------------------------------------
        // DESCUENTO POR TERCERA EDAD
        // --------------------------------------------------
        if (edad >= 60)
        {
            descEdad = subtotal*0.10;

            d1 += b1*0.10;
            d2 += b2*0.10;
            d3 += b3*0.10;
            d4 += b4*0.10;
            d5 += b5*0.10;
            d6 += b6*0.10;
            d7 += b7*0.10;
            d8 += b8*0.10;
            d9 += b9*0.10;
            d10 += b10*0.10;
            d11 += b11*0.10;
            d12 += b12*0.10;
        }

        // --------------------------------------------------
        // DESCUENTO SET PREMIUM
        // Solo se aplica si compra alguno de los dos sets
        // --------------------------------------------------
        descSetPremium = (b10+b11)*0.05;

        d10 += b10*0.05;
        d11 += b11*0.05;

        // --------------------------------------------------
        // DESCUENTO POR VOLUMEN
        // Mas de 2 unidades del mismo producto
        // --------------------------------------------------
        if (q1>2) { descVolumen += b1*0.04; d1 += b1*0.04; }
        if (q2>2) { descVolumen += b2*0.04; d2 += b2*0.04; }
        if (q3>2) { descVolumen += b3*0.04; d3 += b3*0.04; }
        if (q4>2) { descVolumen += b4*0.04; d4 += b4*0.04; }
        if (q5>2) { descVolumen += b5*0.04; d5 += b5*0.04; }
        if (q6>2) { descVolumen += b6*0.04; d6 += b6*0.04; }
        if (q7>2) { descVolumen += b7*0.04; d7 += b7*0.04; }
        if (q8>2) { descVolumen += b8*0.04; d8 += b8*0.04; }
        if (q9>2) { descVolumen += b9*0.04; d9 += b9*0.04; }
        if (q10>2) { descVolumen += b10*0.04; d10 += b10*0.04; }
        if (q11>2) { descVolumen += b11*0.04; d11 += b11*0.04; }
        if (q12>2) { descVolumen += b12*0.04; d12 += b12*0.04; }

        // --------------------------------------------------
        // COMBO ELEGANTE
        // Si compra reloj clasico y cadena acero delgada
        // --------------------------------------------------
        if (q1>0 && q4>0)
        {
            descCombo = (b1+b4)*0.06;

            d1 += b1*0.06;
            d4 += b4*0.06;

            cout << "\nPromocion Combo Elegante aplicada: 6%." << endl;
        }

        // --------------------------------------------------
        // TOTAL DE DESCUENTOS
        // --------------------------------------------------
        descuentos = d1+d2+d3+d4+d5+d6+
                     d7+d8+d9+d10+d11+d12;

        // --------------------------------------------------
        // PUNTOS POR PRODUCTO
        // --------------------------------------------------
        puntos = q1*80 + q2*95 + q3*140 + q4*55 +
                 q5*75 + q6*90 + q7*25 + q8*35 +
                 q9*60 + q10*110 + q11*160 + q12*20;

        // Calculos finales
        double neto = subtotal - descuentos;
        double isv = neto * 0.15;
        double totalPagar = neto + isv;

        // Ganancia neta por categoria, sin ISV
        ganRelojes += (b1-d1)+(b2-d2)+(b3-d3);
        ganCadenas += (b4-d4)+(b5-d5)+(b6-d6);
        ganPulseras += (b7-d7)+(b8-d8)+(b9-d9);
        ganSets += (b10-d10)+(b11-d11);
        ganAccesorios += b12-d12;

        // ==================================================
        // FACTURA
        // ==================================================
        cout << fixed << setprecision(2);

        cout << "\n\n====================================================" << endl;
        cout << "                 PUMA LUX TIME" << endl;
        cout << "                    FACTURA" << endl;
        cout << "====================================================" << endl;

        cout << "Cliente: " << nombre << endl;
        cout << "Edad: " << edad << " anos" << endl;
        cout << "Sexo: " << ((sexo=='F'||sexo=='f') ? "Femenino" : "Masculino") << endl;
        cout << "Tipo: " << (tipoCliente==1 ? "Regular" :
                     (tipoCliente==2 ? "VIP" : "Mayorista")) << endl;

        cout << "----------------------------------------------------" << endl;
        cout << "Producto                         Cant.     Importe" << endl;

        if(q1>0) cout << "Reloj Clasico Puma Classic       " << q1 << "       L." << b1 << endl;
        if(q2>0) cout << "Reloj Deportivo Puma Sport       " << q2 << "       L." << b2 << endl;
        if(q3>0) cout << "Smartwatch Puma Smart X          " << q3 << "       L." << b3 << endl;
        if(q4>0) cout << "Cadena acero delgada             " << q4 << "       L." << b4 << endl;
        if(q5>0) cout << "Cadena acero gruesa              " << q5 << "       L." << b5 << endl;
        if(q6>0) cout << "Cadena bano oro                  " << q6 << "       L." << b6 << endl;
        if(q7>0) cout << "Pulsera cuero                    " << q7 << "       L." << b7 << endl;
        if(q8>0) cout << "Pulsera acero                    " << q8 << "       L." << b8 << endl;
        if(q9>0) cout << "Pulsera bano oro                 " << q9 << "       L." << b9 << endl;
        if(q10>0) cout << "Set cadena + pulsera acero       " << q10 << "       L." << b10 << endl;
        if(q11>0) cout << "Set cadena + pulsera bano oro    " << q11 << "       L." << b11 << endl;
        if(q12>0) cout << "Aretes                           " << q12 << "       L." << b12 << endl;

        cout << "----------------------------------------------------" << endl;
        cout << "Subtotal:              L. " << subtotal << endl;

        // Desglose de descuentos aplicados
        cout << "\n---------------------------------------------" << endl;
        cout << "          DESCUENTOS APLICADOS" << endl;
        cout << "---------------------------------------------" << endl;

        if (descTipoCliente > 0)
            cout << "Por tipo de cliente:   L. " << descTipoCliente << endl;

        if (descSexo > 0)
            cout << "Por sexo:              L. " << descSexo << endl;

        if (descEdad > 0)
            cout << "Por tercera edad:      L. " << descEdad << endl;

        if (descSetPremium > 0)
            cout << "Por Set Premium:       L. " << descSetPremium << endl;

        if (descVolumen > 0)
            cout << "Por volumen:           L. " << descVolumen << endl;

        if (descCombo > 0)
            cout << "Por Combo Elegante:    L. " << descCombo << endl;

        if (descuentos == 0)
            cout << "No se aplicaron descuentos." << endl;

        cout << "---------------------------------------------" << endl;
        cout << "TOTAL DE DESCUENTOS:   L. " << descuentos << endl;
        cout << "---------------------------------------------" << endl;

        cout << "Total con descuentos:  L. " << neto << endl;
        cout << "ISV 15%:               L. " << isv << endl;
        cout << "TOTAL A PAGAR:         L. " << totalPagar << endl;
        cout << "Total en dolares:      $ " << totalPagar/26.42 << endl;

        cout << "\nPor esta compra acumulaste: " << puntos << " puntos." << endl;

        cout << "====================================================" << endl;

        // ==================================================
        // METODO DE PAGO
        // ==================================================
        int metodo = leerEntero(
            "\nMetodo de pago: 1. Efectivo  2. Transferencia: ", 1, 2);

        if (metodo == 1)
        {
            double recibido;

            while (true)
            {
                cout << "Monto recibido en lempiras: L. ";
                cin >> recibido;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Ingrese un monto numerico." << endl;
                }
                else if (recibido < totalPagar)
                {
                    cout << "Monto insuficiente. Debe recibir al menos L. "
                         << totalPagar << endl;
                }
                else
                    break;
            }

            cout << "Cambio: L. " << recibido-totalPagar << endl;
            pagosEfectivo++;
        }
        else
        {
            string referencia, bancoOrigen, bancoDestino;
            double montoTransferido;

            referencia = leerTexto("Numero de comprobante/referencia: ");
            bancoOrigen = leerTexto("Banco de emision: ");
            bancoDestino = leerTexto("Banco de destino: ");

            while (true)
            {
                cout << "Ingrese el monto exacto transferido (L. "
                     << totalPagar << "): ";

                cin >> montoTransferido;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Ingrese un monto numerico." << endl;
                }
                else if (montoTransferido < totalPagar - 0.01 ||
                         montoTransferido > totalPagar + 0.01)
                {
                    cout << "El monto debe ser exacto. Ingrese nuevamente." << endl;
                }
                else
                    break;
            }

            cout << "Transferencia registrada. Referencia: "
                 << referencia << endl;
            cout << "Banco emisor: " << bancoOrigen << endl;
            cout << "Banco destino: " << bancoDestino << endl;

            pagosTransferencia++;
        }

        // ==================================================
        // ACUMULADORES DEL DIA
        // ==================================================
        descuentosDia += descuentos;
        isvDia += isv;
        totalDia += totalPagar;

        otroCliente = leerLetra(
            "\nDesea ingresar otro cliente? (S/N): ", 'S', 'N');
    }

    // Mostrar estadisticas finales
    mostrarEstadisticas();

    return 0;
}
