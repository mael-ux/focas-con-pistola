#include <iostream>
#include "header/entidad.h"

std::string entidad::getNombre(void) const{
    return nombre;

}

void entidad::setNombre(const std::string& n) { nombre = n; }

int entidad::getHP(void) const{
    return HP;
}
void entidad::setHP(int hp_){
    this->HP=hp_;
}
int entidad::getAtaque(void) const{
    return ataque;
}
void entidad::setAtaque(int ataque_){
    this->ataque=ataque_;
}
#include "entidad.h"

entidad::entidad(std::string nombre, int HP, int lvl, int ataque)
    : nombre(nombre), HP(HP), lvl(lvl), ataque(ataque) {}

void entidad::info() const {
    std::cout << "Nombre: " << nombre
              << ", HP: " << HP
              << ", Nivel: " << lvl
              << ", Ataque: " << ataque << std::endl;
}

