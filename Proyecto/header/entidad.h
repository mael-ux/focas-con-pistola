#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>
#include <iostream>

class entidad {
protected:
    std::string nombre;
    int HP;
    int lvl;
    int ataque;

public:
    entidad(std::string nombre = "Entidad", int HP = 0, int lvl = 0, int ataque = 0);
    std::string getNombre() const;
    void setNombre(const std::string& n);

    int getHP() const;
    void setHP(int hp);

    int getAtaque() const;
    void setAtaque(int atk);

    virtual void info() const; // Método virtual para especialización en herencias
};

#endif

