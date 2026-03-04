#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

bool codigoValido(string codigo) {
    if (codigo.length() != 3) return false;
    for (char c : codigo) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {

    int opcion;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Operacion Continua\n";
        cout << "2. Operacion por Sesion\n";
        cout << "3. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            string base, cotizada, continuar;
            long double tasa, monto, convertido;

            do {
                do {
                    cout << "Divisa base: ";
                    cin >> base;
                } while (!codigoValido(base));

                do {
                    cout << "Divisa cotizada: ";
                    cin >> cotizada;
                } while (!codigoValido(cotizada));

                do {
                    cout << "Tasa: ";
                    cin >> tasa;
                } while (tasa <= 0);

                do {
                    cout << "Monto a convertir: ";
                    cin >> monto;
                } while (monto <= 0);

                convertido = monto * tasa;

                cout << fixed << setprecision(2);

                cout << "\n=== CONVERSION DE DIVISAS ===\n";
                cout << "Par: " << base << "/" << cotizada << endl;
                cout << "Tasa: " << setprecision(6) << tasa << endl;
                cout << setprecision(2);
                cout << "Monto base: " << monto << " " << base << endl;
                cout << "Monto convertido: " << convertido << " " << cotizada << endl;

                cout << "\nDesea otra conversion? (si/no): ";
                cin >> continuar;

            } while (continuar == "si" || continuar == "SI");

        }

        else if (opcion == 2) {

            string base, cotizada;
            long double tasa;

            do {
                cout << "Divisa base: ";
                cin >> base;
            } while (!codigoValido(base));

            do {
                cout << "Divisa cotizada: ";
                cin >> cotizada;
            } while (!codigoValido(cotizada));

            do {
                cout << "Tasa: ";
                cin >> tasa;
            } while (tasa <= 0);

            // Estadísticas
            int contador = 0;
            long double totalBase = 0;
            long double totalConvertido = 0;
            long double min = numeric_limits<long double>::max();
            long double max = 0;

            cout << "\n=== SESION DE CONVERSION ===\n";
            cout << "Par: " << base << "/" << cotizada << endl;
            cout << "Tasa: " << fixed << setprecision(6) << tasa << endl;

            while (true) {

                string entrada;
                cout << "\nIngrese monto (o 'q' para salir): ";
                cin >> entrada;

                if (entrada == "q" || entrada == "Q")
                    break;

                long double monto = stold(entrada);

                if (monto <= 0) {
                    cout << "Monto invalido.\n";
                    continue;
                }

                long double convertido = monto * tasa;

                contador++;
                totalBase += monto;
                totalConvertido += convertido;

                if (monto < min) min = monto;
                if (monto > max) max = monto;

                long double promedio = totalBase / contador;

                cout << fixed << setprecision(2);
                cout << "\nConversion #" << contador << endl;
                cout << "Monto base: " << monto << " " << base << endl;
                cout << "Monto convertido: " << convertido << " " << cotizada << endl;

                cout << "\n--- Estadisticas ---\n";
                cout << "Total conversiones: " << contador << endl;
                cout << "Total base: " << totalBase << " " << base << endl;
                cout << "Total convertido: " << totalConvertido << " " << cotizada << endl;
                cout << "Promedio: " << promedio << " " << base << endl;
                cout << "Minimo: " << min << " " << base << endl;
                cout << "Maximo: " << max << " " << base << endl;
            }

            cout << "\n=== RESUMEN FINAL ===\n";
            cout << "Total conversiones: " << contador << endl;
            cout << "Total base: " << totalBase << " " << base << endl;
            cout << "Total convertido: " << totalConvertido << " " << cotizada << endl;
        }

        else if (opcion != 3) {
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 3);

    cout << "Programa finalizado.\n";
    return 0;
}
