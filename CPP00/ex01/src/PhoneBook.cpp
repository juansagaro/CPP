// PhoneBook.cpp
#include "../include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

static std::string truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

PhoneBook::PhoneBook() : count(0), next_index(0) {}

void PhoneBook::addContact(const Contact& new_contact) {
    contacts[next_index] = new_contact;
    next_index = (next_index + 1) % MAX_CONTACTS;
    if (count < MAX_CONTACTS)
        count++;
}

int PhoneBook::getCount() const {
    return count;
}

static void printColumn(const std::string& text) {
    std::cout << std::setw(10) << std::right << truncate(text) << "|";
}

void PhoneBook::displayAll() const {
    if (count == 0) {
        std::cout << "PhoneBook vacío todavía :(\n";
        return;
    }

    std::cout << "     index|first name| last name|  nickname|\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|";
        printColumn(contacts[i].getFirstName());
        printColumn(contacts[i].getLastName());
        printColumn(contacts[i].getNickname());
        std::cout << "\n";
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= count || contacts[index].isEmpty()) {
        std::cout << "Índice inválido o contacto vacío.\n";
        return;
    }

    const Contact& c = contacts[index];
    std::cout << "First name:     " << c.getFirstName() << "\n";
    std::cout << "Last name:      " << c.getLastName() << "\n";
    std::cout << "Nickname:       " << c.getNickname() << "\n";
    std::cout << "Phone number:   " << c.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
}