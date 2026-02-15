// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int     count;
    int     next_index;

public:
    PhoneBook();

    void addContact(const Contact& new_contact);

    void displayAll() const;

    void displayContact(int index) const;

    int getCount() const;
};

#endif