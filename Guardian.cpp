#include "Guardian.h"


Guardian::Guardian(int id, int age, string name, string address, string contact, char gender) {
	this->id = id;
	this->age = age;
	this->name = name;
	this->address = address;
	this->contact = contact;
	this->gender = gender;
}


int Guardian::getId() { return id; }
void Guardian::setId(int id) { this->id = id; }

int Guardian::getAge() { return age; }
void Guardian::setAge(int age) { this->age = age; }

string Guardian::getName() { return name; }
void Guardian::setName(string name) { this->name = name; }

string Guardian::getAddress() { return address; }
void Guardian::setAddress(string address) { this->address = address; }

string Guardian::getContact() { return contact; }
void Guardian::setContact(string contact) { this->contact = contact; }

char Guardian::getGender() { return gender;}
void Guardian::setGender(char gender) { this->gender = gender; }

void Guardian::print() {
	cout << name << endl;
}

void Guardian::printDetail() {
	string line(50, '-');

	cout << line << endl;
	cout << "Guardian ID : " << id << endl;
	cout << "Guardian Name : " << name << endl;
	cout << "Gender : " << gender << endl;
	cout << "Address : " << address << endl;
	cout << "Age : " << age << endl;
	cout << "Contact No : " << contact << endl;
	cout << line << endl;
}

std::string Guardian::toString() {
	return to_string(id) + ";" + to_string(age) + ";" + name + 
		";" + address + ";" + contact + ";" + gender;
}

bool Guardian::operator < (Node& temp) {
	Guardian g = dynamic_cast<Guardian&>(temp);

	return this->id < g.id;
}