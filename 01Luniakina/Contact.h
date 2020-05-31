#ifndef CONTACT_H
#define CONTACT_H

#include "string"
#include <iostream>
#include <vector>
using namespace std;

class Contact {
private:
    string _name;
    string _lastname;

    vector<string> _phone;

public:

    Contact(string name, string lastname, string phone);
    Contact(string name, string lastname);

    Contact(const Contact& c);

    ~Contact();

    string name() const { return _name; }
    string lastname() const { return _lastname; }

    int amountOfPhoneNumbers() const { return _phone.size(); }

    string & operator[](const int index){return _phone[index];}
    const string & operator[](const int index) const{return _phone[index];}

    void addPhoneNumber(string number);

    bool isCorrectNumber(string number);

};
ostream& operator<<(ostream& os, const Contact& c);
#endif // CONTACT_H
