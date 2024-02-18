#include "Chambre.h"

Chambre::Chambre(int numero, const std::string& type) : numero(numero), type(type) {}

int Chambre::getNumero() const {
    return numero;
}

std::string Chambre::getType() const {
    return type;
}


