#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string nom;
    std::string adresse;
    std::string telephone;

public:
    Client() = default; // Constructeur par défaut
    Client(const std::string& nom, const std::string& adresse, const std::string& telephone);
    std::string getNom() const;
    std::string getAdresse() const;
    std::string getTelephone() const;
};

#endif // CLIENT_H
