#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
const int MAX_USERS = 20; // Maximum number of registered users
// Function to check if a username already exists
bool viewAllFlights(){
    ifstream file("flight.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    return false;
}
bool removeFlight(string flightno){
    ifstream file("flight.txt");
    string line;
    while (getline(file, line)) {
        size_t found = line.find(flightno);
        if (found != string::npos) {
            file.close();
            return true;
            cout<<"------------------------------"<<endl;
            cout<<"Processing Cancellation ....." << endl;
            using namespace std::this_thread; // sleep_for, sleep_until
            using namespace std::chrono; // nanoseconds, system_clock, seconds
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now() + seconds(4));

            cout << "Cancellation Successful" << endl;
            return true;
        }
    }
    file.close();
    return false;
}
bool removeTicket(string flightno){
    ifstream file("ticket.txt");
    string line;
    while (getline(file, line)) {
        size_t found = line.find(flightno);
        if (found != string::npos) {
            file.close();
            return true;
            cout<<"------------------------------"<<endl;
            cout<<"Processing Cancellation ....." << endl;
            using namespace std::this_thread; // sleep_for, sleep_until
            using namespace std::chrono; // nanoseconds, system_clock, seconds
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now() + seconds(4));
            cout << "Cancellation Successful" << endl;
            return true;
        }
    }
    file.close();
    return false;
}
bool addFlight(){
    string flightno, source, destination, date, time, price;
                            cout<<"------------------------------"<<endl;
                            cout << "Enter flight number: ";
                            cout<<"------------------------------"<<endl;
                            cin >> flightno;
                            cout<<"------------------------------"<<endl;
                            cout << "Enter source: ";
                            cout<<"------------------------------"<<endl;
                            cin >> source;
                            cout << "Enter destination: ";
                            cout<<"------------------------------"<<endl;
                            cin >> destination;
                            cout << "Enter date: ";
                            cin >> date;
                            cout<<"------------------------------"<<endl;
                            cout << "Enter time: ";
                            cout<<"------------------------------"<<endl;
                            cin >> time;
                            cout<<"------------------------------"<<endl;
                            cout << "Enter price: ";
                            cout<<"------------------------------"<<endl;
                            cin >> price;
    ofstream file("flight.txt", ios::app);
    if (file.is_open()) {
        file << flightno << " " << source << " " << destination << " " << date << " " << time << " " << price << endl;
        file.close();
        cout << "Flight Added Successfully!" << endl;
        return true;
    } else {
        cout << "Failed to open users file for writing." << endl;
        return false;
    }
}
bool isUsernameExists(string username, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t found = line.find(username);
        if (found != string::npos) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool checkticket(string username, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t found = line.find(username);
        if (found != string::npos) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function to register a new user
bool registerUser(string username, string password, string filename) {
    if (isUsernameExists(username, filename)) {
        cout << "Username already exists. Please choose a different username." << endl;
        return false;
    }

    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!" << endl;
        return true;
    } else {
        cout << "Failed to open users file for writing." << endl;
        return false;
    }
}

bool addBeverage(string username, string filename) {
    if (isUsernameExists(username, filename)) {
        cout << "U CAN AD ONLY ONE ITEM IN THIS FLIGHT." << endl;
        return false;
    }
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << username<< endl;
        file.close();
        cout << "Processing Payment ..." << endl;
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(4));
        cout << "Payment Successful" << endl;
        return true;
    } else {
        cout << "Failed to open beverage file for writing." << endl;
        return false;
    }
}

// Function to check if login credentials are valid
bool isLoginValid(string username, string password, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t found = line.find(username + " " + password);
        if (found != string::npos) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool showflight(string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        cout << line ;
    }
    file.close();
    return false;
}

bool checkflight(string username, string password, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t found = line.find(username + " " + password);
        if (found != string::npos) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool bookticket(string id, string filename) {
    if (checkticket(id, filename)) {
        cout << "Flight already in list " << endl;
        return false;
    }

    ofstream file(filename, ios::app);
    if (file.is_open()) {
        
        file << id << endl;
        file.close();
        cout << "Processing Payment ....." << endl;
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(4));
        cout << "Payment Successful" << endl;
        return true;
    } else {
        cout << "Failed to open users file for writing." << endl;
        return false;
    }
}

bool cancelFlight(string id,string filename){
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t found = line.find(id);
        if (found != string::npos) {
            file.close();
            return true;
            cout<<"------------------------------"<<endl;
            cout<<"Processing Cancellation ....." << endl;
            using namespace std::this_thread; // sleep_for, sleep_until
            using namespace std::chrono; // nanoseconds, system_clock, seconds
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now() + seconds(4));
            cout<<"------------------------------"<<endl;
            cout << "Cancellation Successful" << endl;
            cout<<"------------------------------"<<endl;
        }
    }
    file.close();
    return false;
}

int main() {
    string username,password;
    while (true) {
        cout<<"------------------------------"<<endl;
        cout << "Welcome to the Login/Register System!" << endl;
        cout<<"------------------------------"<<endl;
        cout << "1. Register as Customer" << endl;
        cout<<"------------------------------"<<endl;
        cout << "2. Customer Login" << endl;
        cout<<"------------------------------"<<endl;
        cout << "3. Admin Login" << endl;
        cout<<"------------------------------"<<endl;
        cout << "4. Quit" << endl;
        cout<<"------------------------------"<<endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Register as Customer
                ifstream file("customers.txt");
                
                file.close();

                string newUsername, newPassword;
                cout << "Enter a new username: ";
                cin >> newUsername;
                cout << "Enter a new password: ";
                cin >> newPassword;

                if (registerUser(newUsername, newPassword, "customers.txt")) {
                    break;
                } else {
                    cout << "Registration failed. Please try again." << endl;
                    break;
                }
            }

            case 2: {
                // Customer Login   string username, password;
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;

                if (isLoginValid(username, password, "customers.txt")) {
                   cout << "Customer login successful!" << endl;
                    int select;
                    cout << "ENTER THE CHOICE : "<<endl;
                    cout<<"------------------------------"<<endl;
                    cout << "1. BOOK TICKET" << endl;
                    cout<<"------------------------------"<<endl;
                    cout<<"2. Check Status"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<"3. Add Beverages"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<"4. Logout"<<endl;
                    cout<<"------------------------------"<<endl;
                    cin >> select;
                    switch(select){
                        case 1:{
                            string in,out,id;
                            cout<<"------------------------------"<<endl;
                            cout<< "ENTER THE CITY FROM WHERE YOU WILL DEPART : "<<endl;
                            cout<<"------------------------------"<<endl;
                            cin >> in;
                            cout<<"------------------------------"<<endl;
                            cout<< "ENTER THE CITY FROM WHERE YOU WILL ARRIVE : "<<endl;
                            cout<<"------------------------------"<<endl;
                            cin >> out;
                            cout<<"------------------------------"<<endl;
                            cout << "FLIGHTS AVAILABLE : "<<endl;
                            cout<<"------------------------------"<<endl;
                            viewAllFlights();
                            cout<<"------------------------------"<<endl;
                            cout << "BOOK TICKET : "<<endl;
                            cout<<"------------------------------"<<endl;
                            cout<<"ENTER THE FLIGHT ID YOU WANT TO BOOK : "<<endl;
                            cin >> id;
                            bookticket(id , "ticket.txt");
                            cout<<"------------------------------"<<endl;
                            cout << "TICKET BOOKED SUCCESSFULLY : "<<endl;
                            cout<<"------------------------------"<<endl;
                            return 0;
                        }
                        case 2:{
                            cout<<"------------------------------"<<endl;
                            cout << "Enter your username: ";
                            cout<<"------------------------------"<<endl;
                            cin >> username;
                            cout << "Enter your password: ";
                            cout<<"------------------------------"<<endl;
                            cin >> password;
                            if (isLoginValid(username, password, "customers.txt")){
                                cout<<"------------------------------"<<endl;
                                cout << "1. CHECK STATUS : "<<endl;
                                cout<<"------------------------------"<<endl;
                                cout << " 2. CANCEL FLIGHT :"<<endl;
                                cout<<"------------------------------"<<endl;
                                int select1;
                                string flightno;
                                cin >> select1;
                                switch(select1){
                                    case 1:{
                                        cout<<"------------------------------"<<endl;
                                        cout << "ENTER THE FLIGHT NUMBER : "<<endl;
                                        cout<<"------------------------------"<<endl;
                                        cin >> flightno;
                                        if (checkticket(flightno, "ticket.txt")) {
                                            cout << "Checking Status....." << endl;
                                            using namespace std::this_thread; // sleep_for, sleep_until
                                            using namespace std::chrono; // nanoseconds, system_clock, seconds
                                            sleep_for(nanoseconds(10));
                                            sleep_until(system_clock::now() + seconds(4));
                                            cout<<"------------------------------"<<endl;
                                            cout << "Flight is on time  " << endl;
                                            cout<<"------------------------------"<<endl;
                                        }

                                        else{
                                            cout << "Checking Status....." << endl;
                                            using namespace std::this_thread; // sleep_for, sleep_until
                                            using namespace std::chrono; // nanoseconds, system_clock, seconds
                                            sleep_for(nanoseconds(10));
                                            sleep_until(system_clock::now() + seconds(4));
                                            cout<<"------------------------------"<<endl;
                                            cout << "Flight is delayed  " << endl;
                                            cout<<"------------------------------"<<endl;
                                        }
                                        break;

                                    }
                                    case 2:{
                                        cout<<"------------------------------"<<endl;
                                        cout << "ENTER THE FLIGHT NUMBER : "<<endl;
                                        cout<<"------------------------------"<<endl;
                                        cin >> flightno;
                                        removeTicket(flightno);
                                        cout<<"------------------------------"<<endl;
                                        cout << "Flight Cancelled Successfully" << endl;
                                        cout<<"------------------------------"<<endl;
                                        break ;
                                    }
                                }

                            }
                            else {
                                cout << "Invalid username or password. Please try again." << endl;
                            }

                            return 0;
                        }
                            case 3:{
                                 cout<<"ENTER THE CHOICE : "<<endl;
                                        cout<<"------------------------------"<<endl;
                                        cout << "1. WATER" << endl;
                                        cout<<"------------------------------"<<endl;
                                        cout << "2. JUICE" << endl;
                                        cout<<"------------------------------"<<endl;
                                        cout << "3. SANDWICH" << endl;
                                        cout<<"------------------------------"<<endl;
                                        cout << "4. COFFEE" << endl;
                                        cout<<"------------------------------"<<endl;
                                        int select2;
                                        cout << "ENTER THE CHOICE : "<<endl;
                                        cout<<"------------------------------"<<endl;
                                        cin >> select2;
                                        string beverage;
                                        if (select2 == 1)
                                        {
                                            using namespace std::this_thread; // sleep_for, sleep_until
                                            using namespace std::chrono;
                                            cout << "ADDING YOUR BEVERAGE ...." << endl;
                                            sleep_for(nanoseconds(10));
                                            sleep_until(system_clock::now() + seconds(4));

                                            cout<<"------------------------------"<<endl;
                                            cout << "WATER IS ADDED TO YOUR TICKET" << endl;
                                            cout<<"------------------------------"<<endl;
                                            beverage = "WATER";
                                        }
                                        else if (select2 == 2)
                                        {
                                            using namespace std::this_thread; // sleep_for, sleep_until
                                            using namespace std::chrono;
                                            cout << "ADDING YOUR BEVERAGE ...." << endl;
                                            sleep_for(nanoseconds(10));
                                            sleep_until(system_clock::now() + seconds(4));
                                            cout<<"------------------------------"<<endl;
                                            cout << "JUICE IS ADDED TO YOUR TICKET" << endl;
                                            cout<<"------------------------------"<<endl;
                                            beverage = "JUICE";
                                        }
                                        else if (select2 == 3)
                                        {
                                            using namespace std::this_thread; // sleep_for, sleep_until
                                            using namespace std::chrono;
                                            cout << "ADDING YOUR BEVERAGE ...." << endl;
                                            sleep_for(nanoseconds(10));
                                            sleep_until(system_clock::now() + seconds(4));
                                            cout<<"------------------------------"<<endl;
                                            cout << "SANDWICH IS ADDED TO YOUR TICKET" << endl;
                                            cout<<"------------------------------"<<endl;
                                            beverage = "SANDWICH";
                                        }
                                        else if (select2 == 4)
                                        {
                                            using namespace std::this_thread; // sleep_for, sleep_until
                                            using namespace std::chrono;
                                            cout << "ADDING YOUR BEVERAGE ...." << endl;
                                            sleep_for(nanoseconds(10));
                                            sleep_until(system_clock::now() + seconds(4));
                                            cout<<"------------------------------"<<endl;
                                            cout << "COFFEE IS ADDED TO YOUR TICKET" << endl;
                                            cout<<"------------------------------"<<endl;
                                            beverage = "COFFEE";
                                        }
                                        addBeverage(beverage, "bev.txt");
                                        return 0;
                            }
                    }
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                }
                break;
            }
            case 3: {
                // Admin Login
                string username, password;
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;

                if (isLoginValid(username, password, "admins.txt")) {
                    cout << "Admin login successful!" << endl;
                    cout<<"------------------------------"<<endl;
                    cout << "1. ADD FLIGHT" << endl;
                    cout<<"------------------------------"<<endl;
                    cout << "2. VIEW ALL FLIGHTS" << endl;
                    cout<<"------------------------------"<<endl;
                    cout << "3. QUIT" << endl;
                    cout << "ENTER THE CHOICE: ";
                    int choice;
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            // Add Flight
                            addFlight();
                            break;
                        }
                        case 2: {
                            // View All Flights
                            viewAllFlights();
                            break;
                        }
                        case 3: {
                            // Quit
                            cout << "Thank you for using the Login/Register System. Goodbye!" << endl;
                            return 0;
                        }
                        default: {
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                    }
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                }
                break;
            }
            case 4: {
                // Quit
                cout << "Thank you for using the Login/Register System. Goodbye!" << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}