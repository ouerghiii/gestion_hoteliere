#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>

class Chambre {
private:
    int numero;
    std::string type;

public:
    Chambre(int numero, const std::string& type);
    int getNumero() const;
    std::string getType() const;

    // Surcharge de l'opérateur d'égalité
    bool operator==(const Chambre& autre) const {
        return this->numero == autre.numero;
    }
    
};

#endif // CHAMBRE_H
