#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;

/*
    Patient class is used to store the information of Patient
    which carry characteristics of Node so that the Patient can be stored in form of List
*/
class Patient : public Node
{
//private attribute
	int id,  age;
	string name, address, contact, illness;
	bool insurance;
    string doctor_name;
    string medicine;

//public attribute
public:
    //prototype of overloaded constructor
    Patient(int id, int age, string name, string address, string contact, string illness, bool insurance, string doctor_name, string medicine);

    //prototpye of getter & setter
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

    string getIllness();
    void setIllness(string illness);

    string getDoctorName();
    void setDoctorName(string doctor_name);

    bool getInsurance();
    void setInsurance(bool insurance);

    string getMedicine();
    void setMedicine(string medicine);

    void print();
    void printDetail();
    std::string toString();
    bool operator <(Node& tmp);
};

