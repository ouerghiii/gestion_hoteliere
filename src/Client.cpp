#include "Client.h"

Client::Client(const std::string& nom, const std::string& adresse, const std::string& telephone) : nom(nom), adresse(adresse), telephone(telephone) {}

std::string Client::getNom() const {
    return nom;
}

std::string Client::getAdresse() const {
    return adresse;
}

std::string Client::getTelephone() const {
    return telephone;
}
