#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

#include "Chambre.h"
#include "Client.h"
#include <string>

class Enregistrement {
private:
    Client client;
    Chambre chambre;
    std::string dateArrivee;
    std::string dateDepart;

public:
    Enregistrement(const Client& client, const Chambre& chambre, const std::string& dateArrivee, const std::string& dateDepart);
    Client getClient() const;
    Chambre getChambre() const;
    std::string getDateArrivee() const;
    std::string getDateDepart() const;

    // Méthode pour vérifier si la période chevauche la période de l'enregistrement
    bool overlaps(const std::string& dateDebut, const std::string& dateFin) const;
};

#endif // ENREGISTREMENT_H
