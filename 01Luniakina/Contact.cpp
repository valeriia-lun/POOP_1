
#include "Contact.h"
#include "string"
#include <vector>
#include <iostream>
using namespace std;

Contact::Contact(string name, string lastname, string phone){
    if(isCorrectNumber(phone)){
        _name = name;
        _lastname = lastname;
        _phone.push_back(phone);

    } else {
        cout << "Wrong number!!! Number should be from 10 our 12 digits." << endl;
    }
}

Contact:: Contact(string name, string lastname): _name(name), _lastname(lastname){}

Contact::Contact(const Contact &c): _name(c._name), _lastname(c._lastname){
    _phone=vector<string>(c.amountOfPhoneNumbers());
    for (int i=0; i<c.amountOfPhoneNumbers(); i++)
        _phone[i]=c[i];
}

Contact::~Contact(){
   _phone.clear();
}

void Contact::addPhoneNumber(string number){
    if(isCorrectNumber(number)){
        _phone.push_back(number);
    } else {
        cout << "Wrong number!!! Number should be from 10 our 12 digits." << endl;
    }
}

bool Contact::isCorrectNumber(string number) {
    return number.length() == 12 || number.length() == 10;
}

ostream& operator<<(ostream& os, const Contact& c){
    os << "Name: " << c.name() << '\n' << "Last Name: " << c.lastname() << '\n';
    os << "Phones: ";
    for (int i = 0; i < c.amountOfPhoneNumbers(); i++){
        os << c[i] << '\n';
    }
    return os;
}
