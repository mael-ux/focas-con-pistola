#ifndef ORCAS_H
#define ORCAS_H

#include "entidad.h"

class orcas : public entidad {
public:
//constructor
    orcas(std::string nombre, int HP, int lvl, int ataque);
//sobrecargas de operadores
    orcas operator+(const Orcas& otra); //Unir Orcas
    orcas operator*(); //Imprimir lore de orcas 
    

// UnirOrcas

};

#endif
