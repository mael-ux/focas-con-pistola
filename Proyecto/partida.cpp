#include "partida.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

void escribirLento(const std::string& texto, int delay = 50) {
    for (char c : texto) {
        std::cout << c << std::flush; // Imprime cada carácter inmediatamente
        std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // Retraso entre caracteres
    }
    std::cout << std::endl; // Nueva línea al final
}
void limpiarConsola() {
#ifdef _WIN32
    system("cls"); // Comando para limpiar consola en Windows
#else
    system("clear"); // Comando para limpiar consola en Linux/Mac
#endif
}

// Constructor
partida::partida() {
    jugador = "Jugador";
    lvl = 1;
    srand(static_cast<unsigned int>(time(0))); // Semilla para números aleatorios
}

// Métodos básicos
std::string partida::getJugador() const {
    return jugador;
}

void partida::setJugador(const std::string& nombre) {
    jugador = nombre;
}

int partida::getNivel() const {
    return lvl;
}

void partida::setNivel(int nivel) {
    lvl = nivel;
}

// Mostrar menú
void partida::menu() {
    limpiarConsola(); // Limpia la pantalla antes de mostrar el menú
    escribirLento("==== MENÚ ====", 50);
    escribirLento("1. Iniciar Nivel", 50);
    escribirLento("2. Cambiar Nombre del Jugador", 50);
    escribirLento("3. Mostrar Equipo", 50);
    escribirLento("4. Salir", 50);
    escribirLento("================", 50);
}


// Generar un número aleatorio entre min y max
int partida::randomNum(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Crear enemigos (entre 2 y 5 enemigos)
void partida::crearEnemigos(int min, int max) {
    int numEnemigos = randomNum(min, max); // Determina cuántos enemigos
    enemigos.clear();                      // Limpia la lista de enemigos anterior

    for (int i = 0; i < numEnemigos; ++i) {
        int nivelEnemigo = lvl + randomNum(-1, 2); // Nivel del enemigo basado en el nivel del jugador
        int vidaEnemigo = randomNum(20, 50) * nivelEnemigo; // Vida basada en nivel
        int ataqueEnemigo = randomNum(5, 15) * nivelEnemigo; // Ataque basado en nivel

        // Crear un enemigo y agregarlo al vector
        enemigos.emplace_back(focas(nivelEnemigo, vidaEnemigo, ataqueEnemigo));
    }

    // Mostrar enemigos generados
    std::cout << "Se han generado " << enemigos.size() << " enemigos:\n";
    for (size_t i = 0; i < enemigos.size(); ++i) {
        std::cout << "Enemigo " << i + 1 << ": ";
        enemigos[i].info();
    }
}

// Inicializar un nivel
void partida::nivel(int dificultad) {
    std::cout << "Iniciando nivel " << dificultad << "...\n";
    setNivel(dificultad);

    // Generar entre 2 y 5 enemigos
    crearEnemigos(2, 5);

    // Realizar combate
    combate();

    // Si ganas el nivel, subes de nivel y consigues una nueva orca
    if (!enemigos.empty()) {
        std::cout << "¡Has perdido el nivel!\n";
    } else {
        std::cout << "¡Felicidades! Has ganado el nivel " << dificultad << ".\n";
        setNivel(getNivel() + 1);

        // Recompensa: añadir una nueva orca
        equipoOrcas.emplace_back(orcas("Nueva Orca", 100 + lvl * 10, lvl, 15 + lvl * 2));
        std::cout << "Has conseguido una nueva orca:\n";
        equipoOrcas.back().info();
    }
}
void partida::combate() {
    std::cout << "¡El combate ha comenzado!\n";

    // Variables locales para el combate
    size_t turno = 0;

    do {
        std::cout << "\nTurno " << turno + 1 << ":\n";

        // Turno de las orcas
        for (size_t i = 0; i < equipoOrcas.size(); ++i) {
            if (enemigos.empty()) break; // Si no quedan enemigos, termina
            std::cout << equipoOrcas[i].getNombre() << " ataca.\n";

            // Ataque a un enemigo aleatorio
            int index = randomNum(0, enemigos.size() - 1);
            enemigos[index].setHP(enemigos[index].getHP() - equipoOrcas[i].getAtaque());

            if (enemigos[index].getHP() <= 0) {
                std::cout << enemigos[index].getNombre() << " ha sido derrotado.\n";
                enemigos.erase(enemigos.begin() + index); // Eliminar enemigo
            }
        }

        // Turno de las focas
        for (size_t i = 0; i < enemigos.size(); ++i) {
            if (equipoOrcas.empty()) break; // Si no quedan orcas, termina
            std::cout << enemigos[i].getNombre() << " ataca.\n";

            // Ataque a una orca aleatoria
            int index = randomNum(0, equipoOrcas.size() - 1);
            equipoOrcas[index].setHP(equipoOrcas[index].getHP() - enemigos[i].getAtaque());

            if (equipoOrcas[index].getHP() <= 0) {
                std::cout << equipoOrcas[index].getNombre() << " ha sido derrotada.\n";
                equipoOrcas.erase(equipoOrcas.begin() + index); // Eliminar orca
            }
        }

        ++turno; // Incrementar turno

    } while (!enemigos.empty() && !equipoOrcas.empty()); // Continúa hasta que alguien pierda

    // Resultado del combate
    if (equipoOrcas.empty()) {
        std::cout << "¡Has perdido el combate! Todas tus orcas han sido derrotadas.\n";
    } else if (enemigos.empty()) {
        std::cout << "¡Has ganado el combate! Todas las focas han sido derrotadas.\n";
    }
}
