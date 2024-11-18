#include <iostream>
#include "header/partida.h"

// Funciones de utilidad
void limpiarConsola();
void escribirLento(const std::string&, int delay = 50);

int main() {
    int opc;
    partida juego;

    do {
        juego.menu();
        std::cout << "Selecciona una opción: ";
        std::cin >> opc;

        limpiarConsola(); // Limpia antes de procesar la opción

        switch (opc) {
        case 1:
            escribirLento("Iniciando nivel...\n");
            juego.nivel(juego.getNivel());
            break;
        case 2: {
            std::string nuevoNombre;
            escribirLento("Introduce el nuevo nombre del jugador: ");
            std::cin >> nuevoNombre;
            juego.setJugador(nuevoNombre);
            escribirLento("Nombre cambiado exitosamente a: " + nuevoNombre + "\n");
            break;
        }
        case 3:
            escribirLento("Mostrando equipo...\n");
            //juego.mostrarEquipo();
            break;
        case 4:
            escribirLento("Saliendo del juego...\n");
            break;
        default:
            escribirLento("Opción no válida. Intente de nuevo.\n");
            break;
        }

        if (opc != 4) {
            escribirLento("Presiona Enter para continuar...");
            std::cin.ignore(); // Limpia el buffer
            std::cin.get();    // Espera un Enter
        }

    } while (opc != 4);

    return 0;
}
