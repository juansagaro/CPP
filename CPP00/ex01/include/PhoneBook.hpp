// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int     count;        // cuántos contactos hay realmente
    int     next_index;   // índice donde insertaremos el próximo (para comportamiento circular)

public:
    PhoneBook();

    // Añade un contacto (reemplaza el más antiguo si ya hay 8)
    void addContact(const Contact& new_contact);

    // Muestra todos los contactos en formato tabla
    void displayAll() const;

    // Muestra el contacto completo en el índice dado (0-7)
    void displayContact(int index) const;

    // Devuelve cuántos contactos hay realmente
    int getCount() const;
};

#endif