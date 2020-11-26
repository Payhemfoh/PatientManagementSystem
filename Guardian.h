#pragma once
#include <string>
#include <iostream>
#include "Printable.h"
#include "Node.h"
using namespace std;

/*
    Guardian class is used to store the information of Guardian of the patients
    which carry characteristics of Node so that the Guardian can be stored in form of List
*/
class Guardian : public Node
{
private:
	int id, age;
	string name, address, contact;
	char gender;

public:
    
	Guardian(int id,int age, string name, string address, string contact, char gender);
    
    int getId();
    void setId(int id);

    int getAge();
    void setAge(int age);

    string getName();
    void setName(string name);

    string getAddress();
    void setAddress(string address);

    string getContact();
    void setContact(string contact);

    char getGender();
    void setGender(char gender);

    /*
        Display the minimised details which contains only several data of the record to the screen
    */
    void print();

    /*
        Display the full details which contains all the data of the record to the screen
    */
    void printDetail();

    /*
        Get a minified string which contains all the data of the record which 
        typically used to save record into the file
        @return - a string of record which ';' as delimiter
    */
    std::string toString();

    bool operator < (Node& temp);
};

