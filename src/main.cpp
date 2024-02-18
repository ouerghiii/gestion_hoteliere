#include <iostream>
#include "GestionHoteliere.h"
int main() {
    // Création d'une instance de GestionHoteliere
    GestionHoteliere gestionHoteliere;

    // Ajout de quelques chambres
    Chambre chambre1(101, "Simple");
    Chambre chambre2(202, "Double");
    gestionHoteliere.ajouterChambre(chambre1);
    gestionHoteliere.ajouterChambre(chambre2);

    // Ajout de quelques clients
    Client client1("Jean Dupont", "123 rue de Paris", "123456789");
    Client client2("Marie Martin", "456 avenue du Soleil", "987654321");
    gestionHoteliere.ajouterClient(client1);
    gestionHoteliere.ajouterClient(client2);

    // Enregistrement de clients dans des chambres
    gestionHoteliere.enregistrerClient(client1, chambre1, "2024-02-18", "2024-02-20");
    gestionHoteliere.enregistrerClient(client2, chambre2, "2024-02-19", "2024-02-21");

    // Obtention des chambres disponibles pour une période donnée
    std::vector<Chambre> chambresDisponibles = gestionHoteliere.obtenirChambresDisponibles("2024-02-22", "2024-02-24");
    std::cout << "Chambres disponibles pour la période du 22 au 24 février 2024 :" << std::endl;
    for (const auto& chambre : chambresDisponibles) {
        std::cout << "Chambre " << chambre.getNumero() << " - Type: " << chambre.getType() << std::endl;
    }

    // Recherche d'un client par nom
    Client* clientRecherche = gestionHoteliere.rechercherClient("Marie Martin");
    if (clientRecherche != nullptr) {
        std::cout << "Client trouvé : " << clientRecherche->getNom() << " - Adresse : " << clientRecherche->getAdresse() << std::endl;
    } else {
        std::cout << "Client non trouvé." << std::endl;
    }

    // Obtention du rapport des invités
    std::string rapportInvites = gestionHoteliere.obtenirRapportInvites();
    std::cout << "Rapport des invités :" << std::endl << rapportInvites << std::endl;

    return 0;
}

