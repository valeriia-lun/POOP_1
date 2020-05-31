#include <QCoreApplication>
#include "PhoneBook.h"
#include "Contact.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoneBook phonebook;

       bool working = true;

       int option;


       while(working){
           cout << "=====MENU=====" << endl;
           cout << "1 - VIEW ALL CONTACTS" << endl;
           cout << "2 - ADD CONTACT" << endl;
           cout << "3 - ADD PHONE NUMBER TO EXISTING CONTACT" << endl;
           cout << "4 - SEARCH CONTACT BY NAME" << endl;
           cout << "5 - SEARCH CONTACT BY LAST NAME" << endl;
           cout << "6 - SEARCH CONTACT BY NAME AND LAST NAME" << endl;
           cout << "7 - SEARCH CONTACT BY PHONE NUMBER" << endl;
           cout << "8 - DELETE CONTACT" << endl;
           cout << "0 - EXIT" << endl;
           cout << "==============" << endl;

           cout << "What do you want to do? ";
           cin >> option;

           if(option == 1){
               cout << phonebook << endl;
           } else if(option == 2){
               cout << "=====ADDING CONTACT=====" << endl;
               string name, lastname, phone;
               cout << "Name: ";
               cin >> name;
               cout << '\n' << "Last name: ";
               cin >> lastname;
               cout << '\n' << "Phone: ";
               cin >> phone;
               Contact c(name, lastname, phone);
               cout << '\n' << "Do you want to add more phones? " << endl;
               cout << "1 - YES | 0 - NO";
               int op;
               cin >> op;
               bool more = false;
               if(op == 1) {
                   more = true;
               } else { more = false;}
               while(more){
                   cout << '\n' << "Phone: ";
                   cin >> phone;
                   c.addPhoneNumber(phone);
                   cout << '\n' << "Do you want to add more phones? " << endl;
                   cout << "1 - YES | 0 - NO";
                   cin >> op;
                   if(op == 1) {
                       more = true;
                   } else { more = false;}
               }
               phonebook.addContact(c);
               cout << "CONTACT ADDED" << endl;
           } else if(option == 3){
               for(int i = 0; i < phonebook.size(); i++){
                   cout << i + 1 << ") " << phonebook[i] << endl;
               }
               cout << "CHOOSE CONTACT" << endl;
               int index;
               cin >> index;
               cout << "CONTACT :\n" << phonebook[index - 1] << endl;
               cout << "WRITE PHONE :" << endl;
               string phone;
               cin >> phone;
               phonebook[index - 1].addPhoneNumber(phone);
               cout << '\n' << "Do you want to add more phones? " << endl;
               cout << "1 - YES | 0 - NO";
               int op;
               cin >> op;
               bool more = false;
               if(op == 1) {
                   more = true;
               } else { more = false;}
               while(more){
                   cout << '\n' << "Phone: ";
                   cin >> phone;
                   phonebook[index - 1].addPhoneNumber(phone);
                   cout << '\n' << "Do you want to add more phones? " << endl;
                   cout << "1 - YES | 0 - NO";
                   cin >> op;
                   if(op == 1) {
                       more = true;
                   } else { more = false;}
               }
           } else if(option == 4){
               cout << "WRITE NAME: ";
               string name;
               cin >> name;
               cout << "\n CONTACT: " << phonebook.searchByName(name) << endl;
           } else if(option == 5){
               cout << "WRITE LAST NAME: ";
               string lastname;
               cin >> lastname;
               cout << "\n CONTACT: " << phonebook.searchByLastname(lastname) << endl;
           } else if(option == 6){
               cout << "WRITE NAME: ";
               string name;
               cin >> name;
               cout << "\n WRITE LAST NAME: ";
               string lastname;
               cin >> lastname;
               cout << "\n CONTACT: \n" << phonebook.searchByNameAndLastname(name, lastname) << endl;
           } else if(option == 7){
               cout << "WRITE PHONE: ";
               string phone;
               cin >> phone;
               cout << "\n CONTACT: \n" << phonebook.searchByNumber(phone) << endl;
           } else if(option == 8){
               for(int i = 0; i < phonebook.size(); i++){
                   cout << i + 1 << ") " << phonebook[i] << endl;
               }
               cout << "CHOOSE CONTACT" << endl;
               int index;
               cin >> index;
               phonebook.deleteContact(index - 1);
               cout << "CONTACT WAS DELETED" << endl;
           } else if(option == 0){
               working = false;
           }
       }

    return a.exec();
}
