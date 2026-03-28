#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string nombre;
    string Edad;
    int edad = 0;
    bool edadValida = false;

    // 1. Solicitar el nombre
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    // 2. Solicitar y validar la edad
    while (!edadValida) {
        cout << "Ingrese su edad (numero entero de hasta 2 digitos): ";
        cin >> Edad;

        try {
            // Intentar convertir la cadena a entero
            size_t pos;
            edad = stoi(Edad, &pos);

            // Validar que no haya caracteres extra (ej. "25a") y que tenga max 2 dígitos
            // También validamos que sea un número positivo
            if (pos != Edad.length() || Edad.length() > 2 || edad < 0) {
                throw invalid_argument("Formato incorrecto");
            }

            edadValida = true; // Si llega aquí, el dato es correcto
        } 
        catch (...) {
            cout << "Error: El dato es incorrecto. Ingrese un numero correcto de dos digitos." << endl;
            // Limpiar el estado de cin por si acaso
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // 3. Determinar si es mayor de edad y mostrar en pantalla
    cout << "\n------------------------------------------" << endl;
    if (edad >= 18) {
        cout << nombre << " eres mayor de edad. al tener " <<edad <<"  años " << endl;
    } else {
        cout << nombre << " no eres mayor de edad (es menor de edad)." << endl;
    }
    cout << "------------------------------------------" << endl;

    return 0;
}