// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    // Constructor por defecto
    Contact();

    // Setters
    void setFirstName(const std::string& fn);
    void setLastName(const std::string& ln);
    void setNickname(const std::string& nn);
    void setPhoneNumber(const std::string& pn);
    void setDarkestSecret(const std::string& ds);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    // Para saber si el contacto está vacío
    bool isEmpty() const;
};

#endif