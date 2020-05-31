#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
    vector<Contact> _contact;

public:
    PhoneBook();
    PhoneBook(Contact contact);

    PhoneBook(PhoneBook&);

    ~PhoneBook();

    int size() const { return _contact.size(); }

    Contact & operator[](const int index){return _contact[index];}
    const Contact & operator[](const int index) const{return _contact[index];}

    void addContact(Contact c);
    void deleteContact(int index);

    Contact searchByName(string name);
    Contact searchByLastname(string lastname);
    Contact searchByNameAndLastname(string name, string lastname);
    Contact searchByNumber(string number);

};
ostream& operator<<(ostream& os, const PhoneBook& pb);

#endif // PHONEBOOK_H
