#ifndef GESTIONHOTELIERE_H
#define GESTIONHOTELIERE_H

#include "Chambre.h"
#include "Client.h"
#include "Enregistrement.h"
#include <vector>
#include <string>

class GestionHoteliere {
private:
    std::vector<Chambre> chambres;
    std::vector<Client> clients;
    std::vector<Enregistrement> enregistrements;
    //bool estChambreReservee(const Chambre& chambre, const std::vector<Enregistrement>& enregistrements, const std::string& dateDebut, const std::string& dateFin);
    bool estChambreReservee(const Chambre& chambre, const std::vector<Enregistrement>& enregistrements, const std::string& dateDebut, const std::string& dateFin) const;

public:
    void ajouterChambre(const Chambre& chambre);
    void ajouterClient(const Client& client);
    void enregistrerClient(const Client& client, const Chambre& chambre, const std::string& dateArrivee, const std::string& dateDepart);
    std::vector<Chambre> obtenirChambresDisponibles(const std::string& dateDebut, const std::string& dateFin);
    Client* rechercherClient(const std::string& nom);
    std::string obtenirRapportInvites() const;
};

#endif // GESTIONHOTELIERE_H
