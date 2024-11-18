#include "focas.h"

focas::focas(int lvl, int HP, int ataque)
    : entidad("Foca", HP, lvl, ataque) {}

int focas::atacar(int defensa) const {
    return ataque; 
}
