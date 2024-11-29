#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For better formatting (setw, left, etc.)

using namespace std;

// Structure to hold patient information
struct Patient {
    int id;
    string name;
    int age;
    string disease;
};

// Structure to hold doctor information
struct Doctor {
    int id;
    string name;
    string specialization;
};

// Structure to hold appointment details
struct Appointment {
    int patientId;
    int doctorId;
    string date;
};

// Class to manage the hospital system
class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    // Add a new patient
    void addPatient() {
        Patient newPatient;
        cout << "\nEnter Patient ID: ";
        cin >> newPatient.id;
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, newPatient.name);
        cout << "Enter Patient Age: ";
        cin >> newPatient.age;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, newPatient.disease);
        patients.push_back(newPatient);
        cout << "\nPatient added successfully!\n";
    }

    // Add a new doctor
    void addDoctor() {
        Doctor newDoctor;
        cout << "\nEnter Doctor ID: ";
        cin >> newDoctor.id;
        cout << "Enter Doctor Name: ";
        cin.ignore();
        getline(cin, newDoctor.name);
        cout << "Enter Specialization: ";
        getline(cin, newDoctor.specialization);
        doctors.push_back(newDoctor);
        cout << "\nDoctor added successfully!\n";
    }

    // Schedule an appointment
    void scheduleAppointment() {
        int patientId, doctorId;
        string date;
        cout << "\nEnter Patient ID: ";
        cin >> patientId;
        cout << "Enter Doctor ID: ";
        cin >> doctorId;
        cout << "Enter Appointment Date (DD-MM-YYYY): ";
        cin.ignore();
        getline(cin, date);

        // Check if patient and doctor exist
        bool patientExists = false, doctorExists = false;
        for (const auto& patient : patients) {
            if (patient.id == patientId) {
                patientExists = true;
                break;
            }
        }
        for (const auto& doctor : doctors) {
            if (doctor.id == doctorId) {
                doctorExists = true;
                break;
            }
        }

        if (patientExists && doctorExists) {
            Appointment newAppointment = {patientId, doctorId, date};
            appointments.push_back(newAppointment);
            cout << "\nAppointment scheduled successfully!\n";
        } else {
            cout << "\nPatient or Doctor not found!\n";
        }
    }

    // View all patients
    void viewPatients() {
        cout << "\n--------------------------\n";
        cout << "Patient List:\n";
        cout << "--------------------------\n";
        cout << setw(10) << left << "Patient ID" 
             << setw(25) << left << "Name" 
             << setw(10) << left << "Age" 
             << setw(25) << left << "Disease" << endl;
        cout << "----------------------------------------------------------\n";
        for (const auto& patient : patients) {
            cout << setw(10) << left << patient.id 
                 << setw(25) << left << patient.name 
                 << setw(10) << left << patient.age 
                 << setw(25) << left << patient.disease << endl;
        }
        cout << "--------------------------\n";
    }

    // View all doctors
    void viewDoctors() {
        cout << "\n--------------------------\n";
        cout << "Doctor List:\n";
        cout << "--------------------------\n";
        cout << setw(10) << left << "Doctor ID" 
             << setw(25) << left << "Name" 
             << setw(25) << left << "Specialization" << endl;
        cout << "----------------------------------------------------------\n";
        for (const auto& doctor : doctors) {
            cout << setw(10) << left << doctor.id 
                 << setw(25) << left << doctor.name 
                 << setw(25) << left << doctor.specialization << endl;
        }
        cout << "--------------------------\n";
    }

    // View all appointments
    void viewAppointments() {
        cout << "\n------------------------------\n";
        cout << "Appointment List:\n";
        cout << "------------------------------\n";
        cout << setw(15) << left << "Patient ID" 
             << setw(15) << left << "Doctor ID" 
             << setw(20) << left << "Appointment Date" << endl;
        cout << "----------------------------------------------------------\n";
        for (const auto& appointment : appointments) {
            cout << setw(15) << left << appointment.patientId 
                 << setw(15) << left << appointment.doctorId 
                 << setw(20) << left << appointment.date << endl;
        }
        cout << "------------------------------\n";
    }
};

int main() {
    HospitalManagementSystem hms;
    int choice;

    while (true) {
        cout << "\n------------------------------------\n";
        cout << "Hospital Management System Menu:\n";
        cout << "------------------------------------\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Schedule Appointment\n";
        cout << "4. View Patients\n";
        cout << "5. View Doctors\n";
        cout << "6. View Appointments\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hms.addPatient();
                break;
            case 2:
                hms.addDoctor();
                break;
            case 3:
                hms.scheduleAppointment();
                break;
            case 4:
                hms.viewPatients();
                break;
            case 5:
                hms.viewDoctors();
                break;
            case 6:
                hms.viewAppointments();
                break;
            case 7:
                cout << "\nExiting program.\n";
                return 0;
            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}
