#ifndef ORCAS_H
#define ORCAS_H

#include "entidad.h"

class orcas : public entidad {
public:
    orcas(std::string nombre, int HP, int lvl, int ataque);
};

#endif
