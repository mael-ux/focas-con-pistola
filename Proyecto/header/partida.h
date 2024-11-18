#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
#include <vector>
#include "focas.h"
#include "orcas.h"

class partida {
private:
    std::string jugador;             // Nombre del jugador
    int lvl = 1;                     // Nivel actual del jugador
    std::vector<focas> enemigos;    // Enemigos generados
    std::vector<orcas> equipoOrcas; // Equipo del jugador (sus orcas)

public:
    partida();

    std::string getJugador() const;
    void setJugador(const std::string& nombre);

    int getNivel() const;
    void setNivel(int nivel);

    void menu();
    void nivel(int dificultad);
    void crearEnemigos(int min, int max);
    int randomNum(int min, int max);

    void combate(); // Método de combate
};

#endif
