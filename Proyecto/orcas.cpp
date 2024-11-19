#include "orcas.h"

orcas::orcas(std::string nombre, int HP, int lvl, int ataque)
    : entidad(nombre, HP, lvl, ataque) {}

// Sobrecarga de operador +
orcas orcas::operator+(const orcas& otra) {
    return orcas(nombre + " & " + otra.nombre, HP + otra.HP, ataque + otra.ataque);
}
Orca& operator+=() {
    lvl += 1;
    return *this;
}
