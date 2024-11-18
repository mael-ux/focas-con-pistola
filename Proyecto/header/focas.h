#ifndef FOCAS_H
#define FOCAS_H

#include "entidad.h"

class focas : public entidad {
public:
    focas(int lvl, int HP, int ataque);
    
    int atacar(int defensa) const;
};

#endif
