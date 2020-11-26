#include "PaymentModule.h"

PaymentModule::PaymentModule(List* pl, List* ml, List* dl, List* paymentlist)
	:patientList(pl),medicineList(ml),doctorList(dl),paymentList(paymentlist)
{}

void PaymentModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Payment Module" << endl;
	cout << line << endl;
	cout << "1 -> New Payment Record" << endl;
	cout << "2 -> View Payment Record" << endl;
	cout << "3 -> Exit" << endl;
	cout << line << endl;
}

void PaymentModule::mainProcess(int input) {
	switch (input) {
	case 1:
		makePayment();
		break;
	case 2:
		displayPayment();
		break;
	case 3:
		std::cout << "Returning to Main Menu." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid option! Please try again!" << std::endl;
	}
}

void PaymentModule::makePayment() {
	const int PATIENTSIZE = patientList->size();
	bool functionLoop = true;
	do {
		//let user select patient
		printPatientTable();
		int index = InputModule::getIntegerInput("Enter Patient Index (-1 to exit):");
		if (index == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (index > 0 && index <= PATIENTSIZE) {
			int id = InputModule::getIntegerInput("Enter Payment Id : ");
			Patient* patient = dynamic_cast<Patient*>(patientList->get(index-1));

			std::string name = patient->getName();
			double total_price = calculateTotalPrice(patient);

			//get the current date and time
			time_t rawtime;
			time(&rawtime);
			char* date = new char[30];
			ctime_s(date,30,&rawtime);

			//create new constructor
			paymentList->add(new Payment(id, name, date, total_price));
			paymentList->sort();
			functionLoop = false;
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (functionLoop);
}

void PaymentModule::displayPayment() {
	const int SIZE = paymentList->size();
	bool functionLoop = true;
	do {
		printPaymentTable();
		int index = InputModule::getIntegerInput("Enter doctor index(-1 to exit): ");
		if (index == -1) {
			std::cout << "Returning to Module Menu" << std::endl;
			functionLoop = false;
		}
		else if (index >= 1 && index <= SIZE) {
			Payment* ptr = dynamic_cast<Payment*>(paymentList->get(index - 1));
			ptr->printDetail();
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (functionLoop);
}

void PaymentModule::printPaymentTable() {
	Payment* ptr = nullptr;
	std::string line(50, '-');

	printf("%-10s|%-20s|%-20s\n", "Index", "Patient Name", "Payment date");
	std::cout << line << std::endl;

	ptr = dynamic_cast<Payment*>(paymentList->getHead());
	int index = 1;
	//use while loop to display until end of doctorList
	while (ptr != nullptr)
	{
		printf("%-10d", index);
		ptr->print();
		ptr = dynamic_cast<Payment*>(ptr->getNext());
		++index;
	}

	std::cout << line << std::endl;
}

double PaymentModule::calculateTotalPrice(Patient* patient) {
	const int DOCTORSIZE = doctorList->size(), MEDICINESIZE = medicineList->size();
	double doctor_price = 0.0, medicine_price = 0.0;
	std::string doctor_name = patient->getDoctorName();
	std::string medicine_name = patient->getMedicine();

	if (doctor_name.size() != 0) {
		for (int i = 0; i < DOCTORSIZE; ++i) {
			Doctor* doctor = dynamic_cast<Doctor*>(doctorList->get(i));
			if (doctor_name.compare(doctor->getName()) == 0) {
				doctor_price = doctor->getConsultation_price();
			}
		}
	}
	
	if (medicine_name.size() != 0) {
		for (int i = 0; i < MEDICINESIZE; ++i) {
			Medicine* medicine = dynamic_cast<Medicine*>(medicineList->get(i));
			if (medicine_name.compare(medicine->getName()) == 0) {
				medicine_price = medicine->getPrice();
			}
		}
	}

	return doctor_price + medicine_price;
}

void PaymentModule::printPatientTable()
{
	Patient* ptr = nullptr;
	string line(50, '-');
	printf("%-10s|%-20s\n", "Index", "Patient Name");
	cout << line << endl;
	ptr = dynamic_cast<Patient*>(patientList->getHead());
	int index = 1;
	while (ptr != nullptr) {
		printf("%-10d|", index);
		ptr->print();
		ptr = dynamic_cast<Patient*>(ptr->getNext());
		index++;
	}
	cout << line << endl;
}