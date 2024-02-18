#include <algorithm> // Pour std::find_if
#include <iostream> // Pour afficher les messages (à des fins de débogage)
#include <iterator> // Pour std::distance
#include "GestionHoteliere.h"


void GestionHoteliere::ajouterChambre(const Chambre& chambre) {
    chambres.push_back(chambre);
}

void GestionHoteliere::ajouterClient(const Client& client) {
    clients.push_back(client);
}

void GestionHoteliere::enregistrerClient(const Client& client, const Chambre& chambre, const std::string& dateArrivee, const std::string& dateDepart) {
    Enregistrement enregistrement(client, chambre, dateArrivee, dateDepart);
    enregistrements.push_back(enregistrement);
}

bool GestionHoteliere::estChambreReservee(const Chambre& chambre, const std::vector<Enregistrement>& enregistrements, const std::string& dateDebut, const std::string& dateFin) const {
    for (const auto& enregistrement : enregistrements) {
        if (enregistrement.getChambre() == chambre) {
            if (enregistrement.overlaps(dateDebut, dateFin)) {
                return true;
            }
        }
    }
    return false;
}


std::vector<Chambre> GestionHoteliere::obtenirChambresDisponibles(const std::string& dateDebut, const std::string& dateFin) {
    std::vector<Chambre> chambresDisponibles;

    // Parcours de toutes les chambres
    for (const auto& chambre : chambres) {
        // Vérifier si la chambre est réservée pour la période demandée
        if (!estChambreReservee(chambre, enregistrements, dateDebut, dateFin)) {
            // Si la chambre est disponible, l'ajouter à la liste des chambres disponibles
            chambresDisponibles.push_back(chambre);
        }
    }

    // Affichage à des fins de débogage
    std::cout << "Nombre de chambres disponibles pour la période du " << dateDebut << " au " << dateFin << " : " << chambresDisponibles.size() << std::endl;

    return chambresDisponibles;
}

Client* GestionHoteliere::rechercherClient(const std::string& nom) {
    for (auto& client : clients) {
        if (client.getNom() == nom) {
            return &client; // Retourne un pointeur vers le client trouvé
        }
    }

    return nullptr; // Aucun client trouvé, retourne un pointeur nul
}

std::string GestionHoteliere::obtenirRapportInvites() const {
    // Implémentation pour générer le rapport des invités

    std::string rapport;

    // Ajouter des informations sur les invités au rapport
    rapport += "Rapport des invités :\n";

    for (const auto& enregistrement : enregistrements) {
        rapport += "Nom du client : " + enregistrement.getClient().getNom() + "\n";
        rapport += "Chambre : " + std::to_string(enregistrement.getChambre().getNumero()) + "\n";
        rapport += "Dates de séjour : " + enregistrement.getDateArrivee() + " - " + enregistrement.getDateDepart() + "\n";
        rapport += "\n";
    }

    // Retourner le rapport généré
    return rapport;
}
//bool Enregistrement::overlaps(const std::string& dateDebut, const std::string& dateFin) const {
//    // Logique pour vérifier si la période chevauche la période de l'enregistrement
//    // Retourne true si c'est le cas, false sinon
//    return false;
//}