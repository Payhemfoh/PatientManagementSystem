#include "Payment.h"
using namespace std;

//body of overload constructor
Payment::Payment(int id, string patient_name, string date, double totalPrice) {
	this->setId(id);
	this->setPatientName(patient_name);
	this->setDate(date);
	this->setTotalPrice(totalPrice);
}

//body of getter & setter
int Payment::getId() { return id; }
void Payment::setId(int id) { this->id = id; }

string Payment::getPatientName() { return patient_name; }
void Payment::setPatientName(string patient_name) { this->patient_name = patient_name; }

string Payment::getDate(){ return date;}
void Payment::setDate(string date) { this->date = date; }

double Payment::getTotalPrice() { return totalPrice; }
void Payment::setTotalPrice(double totalPrice) { this->totalPrice = totalPrice; }

void Payment::print() {
	printf("%-20s|%-15s\n", patient_name.c_str(), date.c_str());
}

void Payment::printDetail() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Payment ID : " << id << endl;
	cout << "Patient Name : " << patient_name << endl;
	cout << "Payment Date : " << date << endl;
	cout << "Total Price : " << totalPrice << endl;
	cout << line << endl;
}

std::string Payment::toString() {
	return to_string(id) + ";" + patient_name + ";" + date + ";" + to_string(totalPrice);
}

bool Payment::operator <(Node& tmp) {
	Payment p = dynamic_cast<Payment&>(tmp);

	return this->id < p.id;
}