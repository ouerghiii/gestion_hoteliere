#include "Enregistrement.h"

Enregistrement::Enregistrement(const Client& client, const Chambre& chambre, const std::string& dateArrivee, const std::string& dateDepart) : client(client), chambre(chambre), dateArrivee(dateArrivee), dateDepart(dateDepart) {}

Client Enregistrement::getClient() const {
    return client;
}

Chambre Enregistrement::getChambre() const {
    return chambre;
}

std::string Enregistrement::getDateArrivee() const {
    return dateArrivee;
}

std::string Enregistrement::getDateDepart() const {
    return dateDepart;
}

bool Enregistrement::overlaps(const std::string& dateDebut, const std::string& dateFin) const {
    // Logique pour vérifier si la période chevauche la période de l'enregistrement
    // Utilisez les membres dateArrivee et dateDepart si nécessaire

    // Par exemple, vérifiez si la période spécifiée chevauche la période de l'enregistrement
    if (dateArrivee <= dateFin && dateDepart >= dateDebut) {
        return true;
    } else {
        return false;
    }
}