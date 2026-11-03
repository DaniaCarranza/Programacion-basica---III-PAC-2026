#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int main() {
    // Configuración para caracteres en españolb
    setlocale(LC_ALL, "spanish");

    string nombreEstudiante;
    int edadEstudiante;
    char sexoEstudiante;
    double nota1, nota2, nota3;
    double notaPonderada1, notaPonderada2, notaPonderada3;
    double sumaNotasPonderadas;

    // Ciclo para registrar los 5 estudiantes
    for (int i = 1; i <= 5; i++) {
        cout << "\n========================================\n";
        cout << "REGISTRO DEL ESTUDIANTE " << i << endl;
        cout << "========================================\n";

        // 1. Lectura del nombre del estudiante
        cout << "Ingrese el nombre del estudiante: ";
        cin >> ws;
        getline(cin, nombreEstudiante);

        // 2. Validación de la edad
        cout << "Ingrese la edad del estudiante: ";
        cin >> edadEstudiante;
        if (edadEstudiante < 16 || edadEstudiante > 90) {
            cout << "Edad incorrecta. Reinicie el registro para este estudiante.\n";
            i--; // Repetir la iteración para este estudiante
            continue;
        }

        // 3. Validación del sexo ('M', 'm', 'F', 'f')
        cout << "Ingrese el sexo del estudiante (M/F): ";
        cin >> sexoEstudiante;
        if (sexoEstudiante != 'M' && sexoEstudiante != 'm' && 
            sexoEstudiante != 'F' && sexoEstudiante != 'f') {
            cout << "Sexo incorrecto. Reinicie el registro para este estudiante.\n";
            i--;
            continue;
        }

        // 4. Ingreso de notas (en base a 100)
        cout << "Ingrese la nota del I Parcial (25%): ";
        cin >> nota1;
        if (nota1 < 0 || nota1 > 100) {
            cout << "Calificacion incorrecta en el I Parcial.\n";
            i--;
            continue;
        }

        cout << "Ingrese la nota del II Parcial (35%): ";
        cin >> nota2;
        if (nota2 < 0 || nota2 > 100) {
            cout << "Calificacion incorrecta en el II Parcial.\n";
            i--;
            continue;
        }

        cout << "Ingrese la nota del III Parcial (40%): ";
        cin >> nota3;
        if (nota3 < 0 || nota3 > 100) {
            cout << "Calificacion incorrecta en el III Parcial.\n";
            i--;
            continue;
        }

        // 5. Cálculo de notas ponderadas
        notaPonderada1 = nota1 * 0.25; // 25%
        notaPonderada2 = nota2 * 0.35; // 35%
        notaPonderada3 = nota3 * 0.40; // 40%

        sumaNotasPonderadas = notaPonderada1 + notaPonderada2 + notaPonderada3;

        // 6. Salida de resultados y observación según la escala
        cout << "\n--- RESULTADOS PARA: " << nombreEstudiante << " ---\n";
        cout << "Promedio final ponderado: " << sumaNotasPonderadas << " / 100\n";
        cout << "Ponderacion / Observacion: ";

        if (sumaNotasPonderadas >= 90) {
            cout << "Sobresaliente\n";
        } else if (sumaNotasPonderadas >= 80) {
            cout << "Notable\n";
        } else if (sumaNotasPonderadas >= 70) {
            cout << "Aprobado\n";
        } else if (sumaNotasPonderadas >= 60) {
            cout << "Regular\n";
        } else {
            cout << "Reprobado\n";
        }
    
    cout << "\nFin del programa de notas.\n";
    return 0;
    }