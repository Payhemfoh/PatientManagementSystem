#include "DiagnosticModule.h"

DiagnosticModule::DiagnosticModule(List* dl, List* pl, List* ml)
	:doctorList(dl), patientList(pl), medicineList(ml)
{}

void DiagnosticModule::printDoctorList() {
	Doctor* ptr = nullptr;
	std::string line(50, '-');

	printf("%-10s|%-20s|%-20s\n", "Index", "Doctor Name", "Experienced Field");
	std::cout << line << std::endl;

	ptr = dynamic_cast<Doctor*>(doctorList->getHead());
	int index = 1;
	//use while loop to display until end of doctorList
	while (ptr != nullptr)
	{
		printf("%-10d|", index);
		ptr->print();
		ptr = dynamic_cast<Doctor*>(ptr->getNext());
		++index;
	}

	std::cout << line << std::endl;
}

void DiagnosticModule::printPatientList() {
	Patient* ptr = nullptr;
	std::string line(50, '-');

	printf("%-10s|%-20s|%-20s\n", "Index", "Patient Name", "Patient Address");
	std::cout << line << std::endl;

	ptr = dynamic_cast<Patient*>(patientList->getHead());
	int index = 1;
	//use while loop to display until end of patientList
	while (ptr != nullptr)
	{
		printf("%-10d|", index);
		ptr->print();
		ptr = dynamic_cast<Patient*>(ptr->getNext());
		++index;
	}

	std::cout << line << std::endl;
}

void DiagnosticModule::printMedicineList() {
	Medicine* ptr = nullptr;
	std::string line(50, '-');

	printf("%-10s|%-20s\n", "Index", "Medicine Name");
	std::cout << line << std::endl;

	ptr = dynamic_cast<Medicine*>(medicineList->getHead());
	int index = 1;
	//use while loop to display until end of medicineList
	while (ptr != nullptr)
	{
		printf("%-10d|", index);
		ptr->print();
		ptr = dynamic_cast<Medicine*>(ptr->getNext());
		++index;
	}

	std::cout << line << std::endl;
}

void DiagnosticModule::diagnose() {
	int option = 0;
	const int PATIENTSIZE = patientList->size();
	const int DOCTORSIZE = doctorList->size();
	const int MEDICINESIZE = medicineList->size();
	bool functionLoop = true;
	int doctorIndex = 0;

	do {

		printDoctorList();
		doctorIndex = InputModule::getIntegerInput("Enter doctor index(0 to exit): ");

		if (doctorIndex == 0) {
			std::cout << "Returning to Diagnostic Module..." << std::endl;
			functionLoop = false;
		}
		else if(doctorIndex > 0 && doctorIndex <= DOCTORSIZE){
			Doctor* doctor_ptr = dynamic_cast<Doctor*>(doctorList->get(doctorIndex - 1));
			bool selectPatient = true;

			do {
				printPatientList();
				int patientIndex = InputModule::getIntegerInput("Enter patient index(0 to exit): ");

				if (patientIndex == 0) {
					std::cout << "Returning to Doctor Selection Menu..." << std::endl;
					selectPatient = false;
				}
				else if (patientIndex > 0 && patientIndex <= PATIENTSIZE) {
					string description = "";
					Patient* patient_ptr = dynamic_cast<Patient*>(patientList->get(patientIndex - 1));
					patient_ptr->printDetail();

					string illness = InputModule::getStringInput("Please enter patient's illness description:");

					bool selectMedicine = true;
					int medicineIndex = 0;
					Medicine* medicine_ptr = nullptr;
					do {
						printMedicineList();
						medicineIndex = InputModule::getIntegerInput("Enter medicine index(0 if no medicine needed): ");

						if (medicineIndex==0) {
							selectMedicine = false;
						}
						else if (medicineIndex > 0 && medicineIndex <= MEDICINESIZE) {
							medicine_ptr = dynamic_cast<Medicine*>(medicineList->get(medicineIndex - 1));
							std::cout << "Medicine selected : " << medicine_ptr->getName() << std::endl;
							selectMedicine = false;
						}
						else {
							std::cout << "Invalid index. Please try again." << std::endl;
						}
					} while (selectMedicine);
					
					patient_ptr->setIllness(illness);
					patient_ptr->setDoctorName(doctor_ptr->getName());
					if (medicine_ptr != nullptr) {
						patient_ptr->setMedicine(medicine_ptr->getName());
					}

					std::cout << "Diagnose result entered sucessful" << std::endl;
				}
				else {
					std::cout << "Invalid index. Please try again." << std::endl;
				}
			} while (selectPatient);
		}
		else {
			std::cout << "Invalid index. Please try again." << std::endl;
		}
	} while (functionLoop);

}

void DiagnosticModule::checkDiagnose() {
	int option = 0;
	const int PATIENTSIZE = patientList->size();
	bool functionLoop = true;

	do {
		printPatientList();
		int patientIndex = InputModule::getIntegerInput("Enter patient index(0 to exit): ");

		if (patientIndex == 0) {
			std::cout << "Returning to Diagnostic Module..." << std::endl;
			functionLoop = false;
		}
		else if (patientIndex > 0 && patientIndex <= PATIENTSIZE) {
			Patient* patient_ptr = dynamic_cast<Patient*>(patientList->get(patientIndex - 1));
			patient_ptr->printDetail();
			cout << string(50, '-') << endl;
		}
		else {
			std::cout << "Invalid index. Please try again." << std::endl;
		}
	} while (functionLoop);

}

void DiagnosticModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Diagnostic Module" << endl;
	cout << line << endl;
	cout << "1 -> Diagnose" << endl;
	cout << "2 -> Check Diagnostic Record" << endl;
	cout << "3 -> Return to Main Menu" << endl;
	cout << line << endl;
}

void DiagnosticModule::mainProcess(int input) {
	switch (input) {
	case 1:
		this->diagnose();
		break;
	case 2:
		this->checkDiagnose();
		break;
	case 3:
		std::cout << "Returning to Main Menu." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid option! Please try again!" << std::endl;
	}
}
