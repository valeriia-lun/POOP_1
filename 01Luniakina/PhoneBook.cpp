//
// Created by Valerie Luniakina on 27.05.2020.
//

#include "PhoneBook.h"
#include "Contact.h"
#include "string"
#include <iostream>
#include <vector>
using namespace std;


PhoneBook::PhoneBook(){}

PhoneBook::PhoneBook(Contact contact){
    this->_contact[0] = contact;
}

PhoneBook::PhoneBook(PhoneBook& pb){
    for(int i = 0; i < pb.size(); i++) {
        this->_contact[i] = pb._contact[i];
    }
}

PhoneBook::~PhoneBook() {
    _contact.clear();
}

void PhoneBook::addContact(Contact c){
    _contact.push_back(c);
}

void PhoneBook::deleteContact(int index){
      vector<Contact> :: iterator it;
      it = _contact.begin();

      for(int i = 0; i < this->size(); i++){
          if(i == index){
              _contact.erase(it);
          }
          it++;
      }

}

Contact PhoneBook::searchByName(string name){
    bool found = false;
    int index;
    for(int i = 0; i < this->size(); i++){
        if(_contact[i].name() == name) {
            found = true;
            index = i;
        }
    }
    if(found){
        return _contact[index];
    }else {
        cout << "There is no contact with this name!" << endl;
    }
}

Contact PhoneBook::searchByLastname(string lastname){
    bool found = false;
    int index;
    for(int i = 0; i < this->size(); i++){
        if(_contact[i].lastname() == lastname) {
            found = true;
            index = i;
        }
    }

    if(found){
        return _contact[index];
    }else {
        cout << "There is no contact with this last name!" << endl;
    }
}

Contact PhoneBook::searchByNameAndLastname(string name, string lastname){
    bool found = false;
    int index;
    for(int i = 0; i < this->size(); i++){
        if(_contact[i].name() == name && _contact[i].lastname() == lastname) {
            found = true;
            index = i;
        }
    }

    if(found){
        return _contact[index];
    }else {
        cout << "There is no contact with this name and last name!" << endl;
    }
}

Contact PhoneBook::searchByNumber(string number){
    bool found = false;
    int index;
    for(int i = 0; i < this->size(); i++){
        for(int j = 0; j < _contact[i].amountOfPhoneNumbers(); j++) {
            if ((_contact[i])[j] == number) {
                found = true;
                index = i;
            }
        }
    }

    if(found){
        return _contact[index];
    }else {
        cout << "There is no contact with this phone number!" << endl;
    }
}

ostream& operator<<(ostream& os, const PhoneBook& pb){
    os << "Amount of contacts: " << pb.size() << '\n';
    os << "Contacts: " << '\n';
    for (int i = 0; i < pb.size(); i++){
        os << pb[i] << '\n';
    }
    return os;
}
