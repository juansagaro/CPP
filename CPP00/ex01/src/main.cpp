// main.cpp
#include "../include/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static std::string readLine(const std::string& prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

static Contact createContact() {
    Contact c;
    std::string input;

    do {
        input = readLine("First name: ");
        if (input.empty()) std::cout << "No puede estar vacío!\n";
    } while (input.empty());
    c.setFirstName(input);

    do {
        input = readLine("Last name: ");
        if (input.empty()) std::cout << "No puede estar vacío!\n";
    } while (input.empty());
    c.setLastName(input);

    do {
        input = readLine("Nickname: ");
        if (input.empty()) std::cout << "No puede estar vacío!\n";
    } while (input.empty());
    c.setNickname(input);

    do {
        input = readLine("Phone number: ");
        if (input.empty()) std::cout << "No puede estar vacío!\n";
    } while (input.empty());
    c.setPhoneNumber(input);

    do {
        input = readLine("Darkest secret: ");
        if (input.empty()) std::cout << "No puede estar vacío!\n";
    } while (input.empty());
    c.setDarkestSecret(input);

    std::cout << "Contacto añadido con éxito!\n";
    return c;
}

int main() {
    PhoneBook phonebook;
    std::string command;

    std::cout << "¡Bienvenido al Awesome PhoneBook de los 80!\n";
    std::cout << "Comandos disponibles: ADD, SEARCH, EXIT\n\n";

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD") {
            Contact new_contact = createContact();
            phonebook.addContact(new_contact);
        }
        else if (command == "SEARCH") {
            phonebook.displayAll();
            if (phonebook.getCount() > 0) {
                std::cout << "\nIntroduce el índice del contacto a mostrar: ";
                std::string idx_str;
                if (std::getline(std::cin, idx_str)) {
                    int index = std::atoi(idx_str.c_str());
                    phonebook.displayContact(index);
                }
            }
        }
        else if (command == "EXIT" || std::cin.eof()) {
            std::cout << "¡Adiós! Tus contactos se han perdido para siempre... (como en los 80)\n";
            break;
        }
        else if (!command.empty()) {
            std::cout << "Comando desconocido. Usa ADD, SEARCH o EXIT.\n";
        }
    }
    return 0;
}