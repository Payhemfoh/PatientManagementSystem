#include "MainModule.h"

MainModule::MainModule(List* pl, List* dl, List* ml, List* gl, List* payment)
	:patientList(pl),doctorList(dl),medicineList(ml),guardianList(gl),paymentList(payment)
{}


void MainModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Welcome to Patient Management System" << endl;
	cout << line << endl;
	cout << "1 -> Patient Management Module" << endl;
	cout << "2 -> Doctor Management Module" << endl;
	cout << "3 -> Medicine Management Module" << endl;
	cout << "4 -> Diagnostic Module" << endl;
	cout << "5 -> Payment Module" << endl;
	cout << "6 -> Search Module" << endl;
	cout << "7 -> Export Record" << endl;
	cout << "8 -> Exit" << endl;
	cout << line << endl;
}

void MainModule::mainProcess(int input) {
	switch (input) {
	case 1:
	{
		PatientManagementModule pm(patientList, guardianList);

		do {
			pm.printMainMenu();
			int choice = InputModule::getIntegerInput("Your option : ");
			pm.mainProcess(choice);
		} while (pm.isContinue());
	}
	break;
	case 2:
	{
		DoctorManagementModule dm(doctorList);

		do {
			dm.printMainMenu();
			int choice = InputModule::getIntegerInput("Your option : ");
			dm.mainProcess(choice);
		} while (dm.isContinue());
	}
	break;
	case 3:
	{
		MedicineManagementModule mm(medicineList);

		do {
			mm.printMainMenu();
			int choice = InputModule::getIntegerInput("Your option : ");
			mm.mainProcess(choice);
		} while (mm.isContinue());
	}
	break;
	case 4:
	{
		if (patientList->isEmpty() || doctorList->isEmpty()) {
			std::cout << "You cannot enter diagnostic module without patient or doctor data." << std::endl;
		}
		else {
			DiagnosticModule dm(doctorList, patientList, medicineList);

			do {
				dm.printMainMenu();
				int choice = InputModule::getIntegerInput("Your option : ");
				dm.mainProcess(choice);
			} while (dm.isContinue());
		}
	}
	break;
	case 5:
	{
		if (patientList->isEmpty()) {
			std::cout << "You cannot enter payment module without any patient data." << std::endl;
		}
		else {
			PaymentModule pm(patientList, medicineList, doctorList, paymentList);

			do {
				pm.printMainMenu();
				int choice = InputModule::getIntegerInput("Your option : ");
				pm.mainProcess(choice);
			} while (pm.isContinue());
		}
	}
	break;
	case 6:
	{
		SearchModule sm(patientList, doctorList, medicineList, guardianList, paymentList);

		do {
			sm.printMainMenu();
			int choice = InputModule::getIntegerInput("Your option : ");
			sm.mainProcess(choice);
		} while (sm.isContinue());
	}
	break;
	case 7:
	{
		HTMLExportationModule em(patientList, doctorList, medicineList, guardianList, paymentList);

		do {
			em.printMainMenu();
			int choice = InputModule::getIntegerInput("Your option : ");
			em.mainProcess(choice);
		} while (em.isContinue());
	}
	break;
	case 8:
		std::cout << "Thank you for using the system.\nHope you have a nice day." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid input! Please try again!" << std::endl;
	}
}