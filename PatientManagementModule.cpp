#include "PatientManagementModule.h"

PatientManagementModule::PatientManagementModule(List* pl, List* gl) :patientList(pl), guardianList(gl) {}

void PatientManagementModule::printPatientTable()
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

void PatientManagementModule::printGuardianTable()
{
    Guardian* ptr = nullptr;
    string line(50, '-');
    printf("%-10s|%-20s\n", "Index", "Guardian Name");
    cout << line << endl;
    ptr = dynamic_cast<Guardian*>(guardianList->getHead());
    int index = 1;
    while (ptr != nullptr) {
        printf("%10d|", index);
        ptr->print();
        ptr = dynamic_cast<Guardian*>(ptr->getNext());
        index++;
    }
}

void PatientManagementModule::addPatient()
{
    int id = 0, age = 0;
    string name(""), address(""), contact(""), illness("");
    bool insurance("");
    string doctor_Name = "", medicine_Name = "";

    id = InputModule::getIntegerInput("Enter Patient ID: ");
    name = InputModule::getStringInput("Enter Patient Name: ");
    age = InputModule::getIntegerInput("Enter Patient Age: ");
    address = InputModule::getStringInput("Enter Patient Address: ");
    contact = InputModule::getStringInput("Enter Patient Contact: ");
    insurance = InputModule::getCharInput("Patient has Insurance (Y/N): ");
    int gId = InputModule::getIntegerInput("Enter Guardian ID: ");
    string gName = InputModule::getStringInput("Enter Guardian Name: ");
    int gAge = InputModule::getIntegerInput("Enter Guardian Age: ");
    bool gGender = InputModule::getCharInput("Enter Guardian Gender: ");
    string gAddress = InputModule::getStringInput("Enter Guardian Address: ");
    string gContact = InputModule::getStringInput("Enter Guardian Contact: ");

    Node* patient = new Patient(id, age, name, address, contact, illness, insurance, doctor_Name, medicine_Name);
    Node* guardian = new Guardian(gId, gAge, gName, gAddress, gContact, gGender);
    patientList->add(patient);
    patientList->sort();
    guardianList->add(guardian);
    guardianList->sort();
}

void PatientManagementModule::modifyPatient()
{
    const int SIZE = patientList->size();
    string line(50, '-');
    int input = 0;
    bool functionLoop = true;
    do {
        printPatientTable();
        input = InputModule::getIntegerInput("Enter patient index(-1 to exit): ");
        if (input == -1) {
            cout << "Returning to Module Menu" << endl;
            functionLoop = false;
        }
        else if (input >= 1 && input <= SIZE) {
            Patient* ptr = dynamic_cast<Patient*>(patientList->get(input - 1));
            bool editLoop = true;
            do {
                cout << line << endl;
                ptr->printDetail();
                cout << "---------------Edit Patient Records--------------" << endl;
                cout << "1) ID" << endl;
                cout << "2) Name" << endl;
                cout << "3) Age" << endl;
                cout << "4) Address" << endl;
                cout << "5) Contact" << endl;
                cout << "6) Insurance" << endl;
                cout << "7) Exit\n" << endl;
                int option = InputModule::getIntegerInput("Your option: ");
                switch (option) {
                case 1:
                    ptr->setId(InputModule::getIntegerInput("Enter Patient ID: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 2:
                    ptr->setName(InputModule::getStringInput("Enter Patient Name: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 3:
                    ptr->setAge(InputModule::getIntegerInput("Enter Patient Age: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 4:
                    ptr->setAddress(InputModule::getStringInput("Enter Patient Address: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 5:
                    ptr->setContact(InputModule::getStringInput("Enter Patient Contact: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 6:
                    ptr->setInsurance(InputModule::getCharInput("Patient has Insurance (Y/N): "));
                    cout << "Applied changes!" << endl;
                    break;
                case 7:
                    editLoop = false;
                    break;
                default:
                    cout << "Option Invalid!" << endl;
                    break;
                }
            } while (editLoop);
        }
        else cout << "Invalid input! Please try again!" << endl;
    } while (functionLoop);
}

void PatientManagementModule::removePatient()
{
    bool functionLoop = true;
    do {
        int size = patientList->size();
        printPatientTable();
        int index = InputModule::getIntegerInput("Enter patient index(-1 to exit): ");
        if (index == -1) {
            cout << "Returning to Module Menu" << endl;
            functionLoop = false;
        }
        else if (index >= 1 && index <= size) {
            Patient* ptr = dynamic_cast<Patient*>(patientList->get(index - 1));
            ptr->printDetail();
            bool invalid = true;
            do {
                char confirm = InputModule::getCharInput("Are you sure you want to remove the data?[Y/N] : ");

                switch (confirm) {
                case 'y':
                case 'Y':
                    patientList->remove(index - 1);
                    std::cout << "The record has been removed." << std::endl;
                    invalid = false;
                    break;
                case 'x':
                case 'X':
                    std::cout << "The record was not removed." << std::endl;
                    invalid = false;
                    break;
                default:
                    std::cout << "Invalid input! Please try again!" << std::endl;
                }
            } while (invalid);
        }
        else {
            std::cout << "Invalid input! Please try again!" << std::endl;
        }
    } while (functionLoop);
}

void PatientManagementModule::displayPatient()
{
    const int SIZE = patientList->size();
    bool functionLoop = true;
    do {
        printPatientTable();
        int index = InputModule::getIntegerInput("Enter patient index(-1 to exit): ");
        if (index == -1) {
            cout << "Returning to Module Menu" << endl;
            functionLoop = false;
        }
        else if (index >= 1 && index <= SIZE) {
            Patient* ptr = dynamic_cast<Patient*>(patientList->get(index - 1));
            ptr->printDetail();
        }
        else {
            std::cout << "Invalid input! Please try again!" << std::endl;
        }
    } while (functionLoop);
}

void PatientManagementModule::modifyGuardian()
{
    const int SIZE = patientList->size();
    string line(50, '-');
    int input = 0;
    bool functionLoop = true;
    do {
        printGuardianTable();
        input = InputModule::getIntegerInput("Enter guardian index(-1 to exit): ");
        if (input == -1) {
            cout << "Returning to Module Menu" << endl;
            functionLoop = false;
        }
        else if (input >= 1 && input <= SIZE) {
            Guardian* ptr = dynamic_cast<Guardian*>(guardianList->get(input - 1));
            bool editLoop = true;
            do {
                cout << "---------------Edit Guardian Records--------------" << endl;
                cout << "1) ID" << endl;
                cout << "2) Name" << endl;
                cout << "3) Gender" << endl;
                cout << "4) Age" << endl;
                cout << "5) Address" << endl;
                cout << "6) Contact" << endl;
                cout << "7) Exit\n" << endl;
                int option = InputModule::getIntegerInput("Your option: ");
                switch (option) {
                case 1:
                    ptr->setId(InputModule::getIntegerInput("Enter Guardian ID: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 2:
                    ptr->setName(InputModule::getStringInput("Enter Guardian Name: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 3:
                    ptr->setGender(InputModule::getCharInput("Enter Guardian Gender: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 4:
                    ptr->setAge(InputModule::getIntegerInput("Enter Guardian Age: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 5:
                    ptr->setAddress(InputModule::getStringInput("Enter Guardian Address: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 6:
                    ptr->setContact(InputModule::getStringInput("Enter Guardian Contact: "));
                    cout << "Applied changes!" << endl;
                    break;
                case 7:
                    editLoop = false;
                    break;
                default:
                    cout << "Option Invalid!" << endl;
                    break;
                }
            } while (editLoop);
        }
        else cout << "Invalid input! Please try again!" << endl;
    } while (functionLoop);
}

void PatientManagementModule::removeGuardian()
{
    bool functionLoop = true;
    do {
        int size = guardianList->size();
        printGuardianTable();
        int index = InputModule::getIntegerInput("Enter guardian index(-1 to exit): ");
        if (index == -1) {
            cout << "Returning to Module Menu" << endl;
            functionLoop = false;
        }
        else if (index >= 1 && index <= size) {
            Guardian* ptr = dynamic_cast<Guardian*>(guardianList->get(index - 1));
            ptr->printDetail();
            bool invalid = true;
            do {
                char confirm = InputModule::getCharInput("Are you sure you want to remove the data?[Y/N] : ");

                switch (confirm) {
                case 'y':
                case 'Y':
                    guardianList->remove(index - 1);
                    std::cout << "The record has been removed." << std::endl;
                    invalid = false;
                    break;
                case 'x':
                case 'X':
                    std::cout << "The record was not removed." << std::endl;
                    invalid = false;
                    break;
                default:
                    std::cout << "Invalid input! Please try again!" << std::endl;
                }
            } while (invalid);
        }
        else {
            std::cout << "Invalid input! Please try again!" << std::endl;
        }
    } while (functionLoop);
}

void PatientManagementModule::displayGuardian()
{
    const int SIZE = guardianList->size();
    bool functionLoop = true;
    do {
        printGuardianTable();
        int index = InputModule::getIntegerInput("Enter guardian index(-1 to exit): ");
        if (index == -1) {
            cout << "Returning to Module Menu" << endl;
            functionLoop = false;
        }
        else if (index >= 1 && index <= SIZE) {
            Guardian* ptr = dynamic_cast<Guardian*>(guardianList->get(index - 1));
            ptr->printDetail();
        }
        else {
            std::cout << "Invalid input! Please try again!" << std::endl;
        }
    } while (functionLoop);
}

void PatientManagementModule::printMainMenu()
{
    string line(50, '-');
    cout << line << endl;
    cout << "Patient Management Module" << endl;
    cout << line << endl;
    cout << "1-> Add New Patient Record" << endl;
    cout << "2-> Edit Patient Record" << endl;
    cout << "3-> Delete Patient Record" << endl;
    cout << "4-> View Patient Record" << endl;
    cout << "5-> Edit Guardian Record" << endl;
    cout << "6-> Delete Guardian Record" << endl;
    cout << "7-> View Guardian Record" << endl;
    cout << "8-> Return to Main Menu" << endl;
    cout << line << endl;
}

void PatientManagementModule::mainProcess(int input)
{
    switch (input) {
    case 1:
        addPatient();
        break;
    case 2:
        modifyPatient();
        break;
    case 3:
        removePatient();
        break;
    case 4:
        displayPatient();
        break;
    case 5:
        modifyGuardian();
        break;
    case 6:
        removeGuardian();
        break;
    case 7:
        displayGuardian();
        break;
    case 8:
        cout << "Returning to Main Menu." << endl;
        this->endProcess();
        break;
    default:
        cout << "Invalid option! Please try again!" << endl;
    }
}
