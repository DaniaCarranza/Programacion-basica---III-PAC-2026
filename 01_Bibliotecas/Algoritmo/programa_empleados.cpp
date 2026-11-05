#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nombreEmpleado;
    int edadEmpleado, tipoEmpleado;
    char sexoEmpleado;
    double salario;
    double horasDiaLV, horasSabado, horasSemana;

    cout << "========== PILLOFON ===========" << endl;
    cout << "Ingrese el nombre del empleado: ";
    getline(cin >> ws, nombreEmpleado);

    cout << "Ingrese la edad del empleado: ";
    cin >> edadEmpleado;
    while (edadEmpleado < 18 || edadEmpleado > 65)
    {
        cout << "Edad fuera de rango" << endl;
        cout << "Ingrese la edad del empleado: ";
        cin >> edadEmpleado;
    }

    cout << "Ingrese el sexo del empleado (M/F): ";
    cin >> sexoEmpleado;
    while (sexoEmpleado != 'M' && sexoEmpleado != 'm' && sexoEmpleado != 'F' && sexoEmpleado != 'f')
    {
        cout << "Sexo no valido" << endl;
        cout << "Ingrese el sexo del empleado (M/F): ";
        cin >> sexoEmpleado;
    }

    cout << "Ingrese el sueldo mensual: L. ";
    cin >> salario;
    while (salario <= 16000)
    {
        cout << "Salario no valido (debe ser mayor a L. 16,000.00)" << endl;
        cout << "Ingrese el sueldo mensual: L. ";
        cin >> salario;
    }

    cout << "Tipo de empleado (1-Planta, 2-Medio tiempo, 3-Contrato): ";
    cin >> tipoEmpleado;

    switch (tipoEmpleado)
    {
    case 1: // Planta
        horasDiaLV = 10.5 - 1;   // 7:00 am - 5:30 pm menos almuerzo = 9.5
        horasSabado = 7 - 1;     // 8:00 am - 3:00 pm menos almuerzo = 6
        horasSemana = horasDiaLV * 5 + horasSabado; // 53.5
        cout << "Empleado de planta: " << horasDiaLV << " h de lunes a viernes y "
             << horasSabado << " h los sabados, total semanal " << horasSemana << " h" << endl;
        break;
    case 2: // Medio tiempo
        horasDiaLV = 6.5 - 1;    // 7:00 am - 1:30 pm menos almuerzo = 5.5
        horasSabado = horasDiaLV;
        horasSemana = horasDiaLV * 6; // 33
        cout << "Empleado de medio tiempo: " << horasDiaLV << " h de lunes a sabado, total semanal "
             << horasSemana << " h" << endl;
        break;
    case 3: // Contrato
        cout << "Ingrese las horas semanales trabajadas: ";
        cin >> horasSemana;
        if (horasSemana < 30 || horasSemana > 40)
        {
            cout << "ERROR: horas fuera de rango permitido" << endl;
            return 0;
        }
        horasDiaLV = horasSemana / 5;
        horasSabado = 0;
        cout << "Empleado por contrato: " << horasSemana << " h semanales" << endl;
        break;
    default:
        cout << "Tipo de empleado no valido" << endl;
        return 0;
    }

    // Calculos (el mes tiene 4 semanas)
    double horasMes = horasSemana * 4;
    double sueldoHora = salario / horasMes;
    double sueldoMinuto = sueldoHora / 60;
    double sueldoSegundo = sueldoMinuto / 60;
    double sueldoDiarioLV = sueldoHora * horasDiaLV;
    double sueldoSabado = sueldoHora * horasSabado;
    double sueldoSemanaLV = sueldoDiarioLV * 5;
    double sueldoSemanaLS = sueldoSemanaLV + sueldoSabado;
    double sueldoQuincenal = salario / 2;

    // Reporte
    cout << fixed;
    cout.precision(2);
    cout << "\n======= REPORTE =======" << endl;
    cout << nombreEmpleado << ", " << edadEmpleado << " anios, sexo " << sexoEmpleado
         << ", sueldo mensual L. " << salario << endl;
    cout << "1. Sueldo diario (L-V): L. " << sueldoDiarioLV
         << "  (" << sueldoHora << " x " << horasDiaLV << " h)" << endl;
    cout << "2. Sueldo de los sabados: L. " << sueldoSabado
         << "  (" << sueldoHora << " x " << horasSabado << " h)" << endl;
    cout << "3. Sueldo por hora: L. " << sueldoHora
         << "  (" << salario << " / " << horasMes << " h)" << endl;
    cout << "4. Sueldo por minuto: L. " << sueldoMinuto << endl;
    cout.precision(4);
    cout << "5. Sueldo por segundo: L. " << sueldoSegundo << endl;
    cout.precision(2);
    cout << "6. Sueldo semanal L-V: L. " << sueldoSemanaLV << endl;
    if (horasSabado > 0)
        cout << "7. Sueldo semanal L-S: L. " << sueldoSemanaLS << endl;
    else
        cout << "7. Sueldo semanal L-S: no aplica" << endl;
    cout << "8. Sueldo quincenal: L. " << sueldoQuincenal << endl;
    cout << "9. Horas trabajadas totales (mes): " << horasMes << " h" << endl;

    return 0;
}