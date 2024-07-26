//#include <iostream>
//#include <fstream>
//#include <string>
//#include<cstdlib>
//#include <windows.h>
//#include<iomanip>
//
//using namespace std;
//class Report {
//public:
//	virtual void generateReport() = 0;
//};
//class User {
//private:
//	int ID;
//	string name, email;
//	string phone;
//	string gender;
//	string dateOfBirth;
//
//public:
//	User() {
//		name = "";
//		ID = 0;
//		email = "";
//		phone = "";
//		gender = "";
//		dateOfBirth = "";
//	}
//
//	User(int ID, string name, string email, string phone, string gender, string dateOfBirth) {
//		this->name = name;
//		this->ID = ID;
//		this->email = email;
//		this->phone = phone;
//		this->gender = gender;
//		this->dateOfBirth = dateOfBirth;
//	}
//
//	void addUser() {
//		ofstream out("user_data.txt", ios::app);
//		if (out.is_open()) {
//			cout << "Enter ID: ";
//			cin >> ID;
//			out << ID << endl;
//			cin.ignore();
//			cout << "Enter name: ";
//			getline(cin, name);
//			out << name << endl;
//			cout << "Enter email: ";
//			getline(cin, email);
//			out << email << endl;
//			cout << "Enter phone: ";
//			getline(cin, phone);
//			out << phone << endl;
//			cout << "Enter gender: ";
//			getline(cin, gender);
//			out << gender << endl;
//			cout << "Enter date of birth: ";
//			getline(cin, dateOfBirth);
//			out << dateOfBirth << endl;
//			cout << "User added successfully." << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//		out.close();
//	}
//
//	void removeUser() {
//		ID = 0;
//		name = "";
//		email = "";
//		phone = "";
//		gender = "";
//		dateOfBirth = "";
//	}
//
//	void searchUser(int searchID) {
//		ifstream in("user_data.txt");
//		int id1;
//		string name1, email1, phone1, gender1, dob1;
//		bool found = false;
//		while (in >> id1 >> name1 >> email1 >> phone1 >> gender1 >> dob1) {
//			if (id1 == searchID) {
//				cout << "ID: " << id1 << endl;
//				cout << "Name: " << name1 << endl;
//				cout << "Email: " << email1 << endl;
//				cout << "Phone: " << phone1 << endl;
//				cout << "Gender: " << gender1 << endl;
//				cout << "Date of birth: " << dob1 << endl;
//				found = true;
//				break;
//			}
//		}
//		if (!found) {
//			cout << "User not found." << endl;
//		}
//		in.close();
//	}
//
//	void updateUser() {
//		ifstream in("user_data.txt");
//		ofstream temp("temp.txt");
//		int id1;
//		string name1, email1, phone1, gender1, dob1;
//		bool found = false;
//		cout << "Enter ID: ";
//		cin >> ID;
//		while (in >> id1 >> name1 >> email1 >> phone1 >> gender1 >> dob1) {
//			if (id1 == ID) {
//				found = true;
//				cout << "Enter name: ";
//				cin.ignore();
//				getline(cin, name);
//				cout << "Enter email: ";
//				getline(cin, email);
//				cout << "Enter phone: ";
//				getline(cin, phone);
//				cout << "Enter gender: ";
//				getline(cin, gender);
//				cout << "Enter date of birth: ";
//				getline(cin, dateOfBirth);
//				temp << ID << endl;
//				temp << name << endl;
//				temp << email << endl;
//				temp << phone << endl;
//				temp << gender << endl;
//				temp << dateOfBirth << endl;
//				cout << "User updated successfully." << endl;
//			}
//			else {
//				temp << id1 << endl;
//				temp << name1 << endl;
//				temp << email1 << endl;
//				temp << phone1 << endl;
//				temp << gender1 << endl;
//				temp << dob1 << endl;
//			}
//		}
//		if (!found) {
//			cout << "User not found." << endl;
//		}
//		in.close();
//		temp.close();
//		remove("user_data.txt");
//		rename("temp.txt", "user_data.txt");
//	}
//
//	void displayUser() {
//		ifstream in("user_data.txt");
//		int id1;
//		string name1, email1, phone1, gender1, dob1;
//		cout << "User List:" << endl;
//		while (in >> id1 >> name1 >> email1 >> phone1 >> gender1 >> dob1) {
//			cout << "ID: " << id1 << endl;
//			cout << "Name: " << name1 << endl;
//			cout << "Email: " << email1 << endl;
//			cout << "Phone: " << phone1 << endl;
//			cout << "Gender: " << gender1 << endl;
//			cout << "Date of birth: " << dob1 << endl;
//			cout << endl;
//		}
//		in.close();
//	}
//};
//
//
//class Trainer {
//private:
//	int trainerID;
//	string name;
//	string email;
//	string phone;
//	string specialization;
//	string shift;
//	double salary;
//
//public:
//	Trainer() {}
//
//	Trainer(int trainerID, string name, string email, string phone, string specialization, string shift, double salary) {
//		this->trainerID = trainerID;
//		this->name = name;
//		this->email = email;
//		this->phone = phone;
//		this->specialization = specialization;
//		this->shift = shift;
//		this->salary = salary;
//	}
//
//	void addTrainer() {
//		cout << "Enter ID: ";
//		cin >> trainerID;
//		cin.ignore(); // Ignore the newline character after cin
//		cout << "Enter name: ";
//		getline(cin, name);
//		cout << "Enter email: ";
//		getline(cin, email);
//		cout << "Enter phone: ";
//		getline(cin, phone);
//		cout << "Enter Specialization: ";
//		getline(cin, specialization);
//		cout << "Enter Shift: ";
//		getline(cin, shift);
//		cout << "Enter salary: ";
//		cin >> salary;
//	}
//
//	void removeTrainer() {
//		trainerID = 0;
//		name = "";
//		email = "";
//		phone = "";
//		specialization = "";
//		shift = "";
//		salary = 0.00;
//	}
//
//	void searchTrainer(int mID) {
//		if (trainerID == mID) {
//			cout << "Trainer ID: " << trainerID << endl;
//			cout << "Name: " << name << endl;
//			cout << "Email: " << email << endl;
//			cout << "Phone: " << phone << endl;
//			cout << "Specialization: " << specialization << endl;
//			cout << "Shift: " << shift << endl;
//			cout << "Salary: " << salary << endl;
//		}
//		else {
//			cout << "Trainer not found!" << endl;
//		}
//	}
//
//	void updateTrainer(int mID) {
//		if (trainerID == mID) {
//			cin.ignore(); // Ignore the newline character after cin
//			cout << "Enter name: ";
//			getline(cin, name);
//			cout << "Enter email: ";
//			getline(cin, email);
//			cout << "Enter phone: ";
//			getline(cin, phone);
//			cout << "Enter Specialization: ";
//			getline(cin, specialization);
//			cout << "Enter Shift: ";
//			getline(cin, shift);
//			cout << "Enter salary: ";
//			cin >> salary;
//		}
//		else {
//			cout << "Trainer not found!" << endl;
//		}
//	}
//
//	void viewTrainer() {
//		cout << "Trainer ID: " << trainerID << endl;
//		cout << "Name: " << name << endl;
//		cout << "Email: " << email << endl;
//		cout << "Phone: " << phone << endl;
//		cout << "Specialization: " << specialization << endl;
//		cout << "Shift: " << shift << endl;
//		cout << "Salary: " << salary << endl;
//	}
//	void writeTrainerToFile() {
//		ofstream outFile("trainers.txt", ios::app);
//		if (outFile.is_open()) {
//			outFile << trainerID << "\n";
//			outFile << name << "\n";
//			outFile << email << "\n";
//			outFile << phone << "\n";
//			outFile << specialization << "\n";
//			outFile << shift << "\n";
//			outFile << salary << "\n";
//			outFile.close();
//			cout << "Trainer details have been written to file." << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//	static Trainer readTrainerFromFile(ifstream& inFile) {
//		Trainer trainer;
//		if (inFile.is_open()) {
//			string line;
//			if (getline(inFile, line)) {
//				trainer.trainerID = stoi(line);
//			}
//			if (getline(inFile, line)) {
//				trainer.name = line;
//			}
//			if (getline(inFile, line)) {
//				trainer.email = line;
//			}
//			if (getline(inFile, line)) {
//				trainer.phone = line;
//			}
//			if (getline(inFile, line)) {
//				trainer.specialization = line;
//			}
//			if (getline(inFile, line)) {
//				trainer.shift = line;
//			}
//			if (getline(inFile, line)) {
//				trainer.salary = stod(line);
//			}
//		}
//		return trainer;
//	}
//};
//
//class Staff:public User {
//private:
//	int staffID;
//	string hireDate;
//	string jobTitle;
//	double salary;
//
//public:
//	Staff() {}
//
//	Staff(int staffID, string hireDate, string jobTitle, double salary) {
//		this->staffID = staffID;
//		this->hireDate = hireDate;
//		this->jobTitle = jobTitle;
//		this->salary = salary;
//	}
//
//	void addStaff() {
//		cout << "Enter Staff ID: ";
//		cin >> staffID;
//		cout << "Enter Hiring Date (YYYY-MM-DD): ";
//		cin >> hireDate;
//		cin.ignore(); // Ignore the newline character after cin
//		cout << "Enter Job Title: ";
//		getline(cin, jobTitle);
//		cout << "Enter Salary: ";
//		cin >> salary;
//	}
//
//	void removeStaff() {
//		staffID = 0;
//		hireDate = "";
//		jobTitle = "";
//		salary = 0;
//	}
//
//	void searchStaff(int mID) {
//		if (staffID == mID) {
//			cout << "Staff ID: " << staffID << endl;
//			cout << "Hiring Date: " << hireDate << endl;
//			cout << "Job Title: " << jobTitle << endl;
//			cout << "Salary: " << salary << endl;
//		}
//		else {
//			cout << "Member not found!" << endl;
//		}
//	}
//
//	void updateStaff(int mID) {
//		if (staffID == mID) {
//			cout << "Enter Hiring Date (YYYY-MM-DD): ";
//			cin >> hireDate;
//			cin.ignore(); // Ignore the newline character after cin
//			cout << "Enter Job Title: ";
//			getline(cin, jobTitle);
//			cout << "Enter Salary: ";
//			cin >> salary;
//		}
//		else {
//			cout << "Member not found!" << endl;
//		}
//	}
//
//	void viewStaff() {
//		cout << "Staff ID: " << staffID << endl;
//		cout << "Hiring Date: " << hireDate << endl;
//		cout << "Job Title: " << jobTitle << endl;
//		cout << "Salary: " << salary << endl;
//	}
//	void writeStaffToFile() {
//		ofstream outFile("staff.txt", ios::app);
//		if (outFile.is_open()) {
//			outFile << staffID << "," << hireDate << "," << jobTitle << "," << salary << endl;
//			outFile.close();
//			cout << "Staff information has been written to the file." << endl;
//		}
//		else {
//			cout << "Unable to open file." << endl;
//		}
//	}
//	void readStaffFromFile() {
//		ifstream inFile("staff.txt");
//		if (inFile.is_open()) {
//			string line;
//			while (getline(inFile, line)) {
//				string staffIDStr, hireDate, jobTitle, salaryStr;
//
//				// Read staff ID
//				string::size_type commaPos = line.find(',');
//				if (commaPos != string::npos) {
//					staffIDStr = line.substr(0, commaPos);
//					line.erase(0, commaPos + 1);
//				}
//
//				// Read hire date
//				commaPos = line.find(',');
//				if (commaPos != string::npos) {
//					hireDate = line.substr(0, commaPos);
//					line.erase(0, commaPos + 1);
//				}
//
//				// Read job title
//				commaPos = line.find(',');
//				if (commaPos != string::npos) {
//					jobTitle = line.substr(0, commaPos);
//					line.erase(0, commaPos + 1);
//				}
//
//				// Read salary
//				salaryStr = line;
//
//				// Convert string values to appropriate types
//				int staffID = stoi(staffIDStr);
//				double salary = stod(salaryStr);
//
//				// Create Staff object and display information
//				Staff staff(staffID, hireDate, jobTitle, salary);
//				staff.viewStaff();
//			}
//
//			inFile.close();
//		}
//		else {
//			cout << "Unable to open file." << endl;
//		}
//	}
//
//};
//class WorkoutPackage
//{
//private:
//	int packageID;
//	string title;
//	string description;
//	double price;
//	int duration;
//
//public:
//	WorkoutPackage() {}
//	WorkoutPackage(int pID, string t, string d, double p, int dur) {
//		packageID = pID;
//		title = t;
//		description = d;
//		price = p;
//		duration = dur;
//	}
//
//	void addPackage() {
//		cout << "Enter Package ID: ";
//		cin >> packageID;
//		cout << "Enter Title: ";
//		cin.ignore();
//		getline(cin, title);
//		cout << "Enter Description: ";
//		getline(cin, description);
//		cout << "Enter Price: ";
//		cin >> price;
//		cout << "Enter Duration (in days): ";
//		cin >> duration;
//	}
//
//	void removePackage() {
//		packageID = 0;
//		title = "";
//		description = "";
//		price = 0.0;
//		duration = 0;
//	}
//
//	void searchPackage(int pID) {
//		if (packageID == pID) {
//			cout << "Package ID: " << packageID << endl;
//			cout << "Title: " << title << endl;
//			cout << "Description: " << description << endl;
//			cout << "Price: " << price << endl;
//			cout << "Duration: " << duration << " days" << endl;
//		}
//		else {
//			cout << "Package not found!" << endl;
//		}
//	}
//
//	void updatePackage(int pID) {
//		if (packageID == pID) {
//			cout << "Enter Title: ";
//			cin.ignore();
//			getline(cin, title);
//			cout << "Enter Description: ";
//			getline(cin, description);
//			cout << "Enter Price: ";
//			cin >> price;
//			cout << "Enter Duration (in days): ";
//			cin >> duration;
//		}
//		else {
//			cout << "Package not found!" << endl;
//		}
//	}
//
//	void viewPackage() {
//		cout << "Package ID: " << packageID << endl;
//		cout << "Title: " << title << endl;
//		cout << "Description: " << description << endl;
//		cout << "Price: " << price << endl;
//		cout << "Duration: " << duration << " days" << endl;
//	}
//	void writeToFile(const string& filename) {
//		ofstream outFile(filename);
//		if (outFile.is_open()) {
//			outFile << packageID << endl;
//			outFile << title << endl;
//			outFile << description << endl;
//			outFile << price << endl;
//			outFile << duration << endl;
//			outFile.close();
//			cout << "Data written to the file successfully." << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//	void readFromFile(const string& filename) {
//		ifstream inFile(filename);
//		if (inFile.is_open()) {
//			inFile >> packageID;
//			inFile.ignore();
//			getline(inFile, title);
//			getline(inFile, description);
//			inFile >> price;
//			inFile >> duration;
//			inFile.close();
//			cout << "Data read from the file successfully." << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//};
//class Member:public User {
//private:
//	int membershipID;
//	string startDate;
//	string endDate;
//	string membershipStatus;
//	int packageID;
//	int trainerID;
//	double amount;
//	string paymentMethod; int memberID;
//	string memberName;
//	int age;
//	string gender;
//	WorkoutPackage package; 
//
//public:
//	Member() {}
//	Member(int mID, string sDate, string eDate, string mStatus, int pID, int tID, double amt, string pMethod) {
//		membershipID = mID;
//		startDate = sDate;
//		endDate = eDate;
//		membershipStatus = mStatus;
//		packageID = pID;
//		trainerID = tID;
//		amount = amt;
//		paymentMethod = pMethod;
//	}
//	void addMember() {
//		cout << "Enter Member ID: ";
//		cin >> memberID;
//		cout << "Enter Member Name: ";
//		cin.ignore();
//		getline(cin, memberName);
//		cout << "Enter Member Age: ";
//		cin >> age;
//		cout << "Enter Member Gender: ";
//		cin.ignore();
//		getline(cin, gender);
//		package.addPackage();
//		cout << "Enter Membership ID: ";
//		cin >> membershipID;
//		cout << "Enter Start Date (YYYY-MM-DD): ";
//		cin >> startDate;
//		cout << "Enter End Date (YYYY-MM-DD): ";
//		cin >> endDate;
//		cout << "Enter Membership Status: ";
//		cin >> membershipStatus;
//		cout << "Enter Package ID: ";
//		cin >> packageID;
//		cout << "Enter Trainer ID: ";
//		cin >> trainerID;
//		cout << "Enter Amount: ";
//		cin >> amount;
//		cout << "Enter Payment Method: ";
//		cin >> paymentMethod;
//	}
//
//	void removeMember() {
//		membershipID = 0;
//		startDate = "";
//		endDate = "";
//		membershipStatus = "";
//		packageID = 0;
//		trainerID = 0;
//		amount = 0.0;
//		paymentMethod = "";
//	}
//
//	void searchMember(int mID) {
//		if (membershipID == mID) {
//			cout << "Membership ID: " << membershipID << endl;
//			cout << "Start Date: " << startDate << endl;
//			cout << "End Date: " << endDate << endl;
//			cout << "Membership Status: " << membershipStatus << endl;
//			cout << "Package ID: " << packageID << endl;
//			cout << "Trainer ID: " << trainerID << endl;
//			cout << "Amount: " << amount << endl;
//			cout << "Payment Method: " << paymentMethod << endl;
//		}
//		else {
//			cout << "Member not found!" << endl;
//		}
//	}
//
//	void updateMember(int mID) {
//		if (membershipID == mID) {
//			cout << "Enter Start Date (YYYY-MM-DD): ";
//			cin >> startDate;
//			cout << "Enter End Date (YYYY-MM-DD): ";
//			cin >> endDate;
//			cout << "Enter Membership Status: ";
//			cin >> membershipStatus;
//			cout << "Enter Package ID: ";
//			cin >> packageID;
//			cout << "Enter Trainer ID: ";
//			cin >> trainerID;
//			cout << "Enter Amount: ";
//			cin >> amount;
//			cout << "Enter Payment Method: ";
//			cin >> paymentMethod;
//		}
//		else {
//			cout << "Member not found!" << endl;
//		}
//	}
//
//	void viewMember() {
//		cout << "Membership ID: " << membershipID << endl;
//		cout << "Start Date: " << startDate << endl;
//		cout << "End Date: " << endDate << endl;
//		cout << "Membership Status: " << membershipStatus << endl;
//		cout << "Package ID: " << packageID << endl;
//		cout << "Trainer ID: " << trainerID << endl;
//		cout << "Amount: " << amount << endl;
//		cout << "Payment Method: " << paymentMethod << endl;
//	}
//	void writeMembersToFile() {
//		ofstream outFile("members.txt", ios::app);
//		if (outFile.is_open()) {
//			Member member;
//			member.addMember();
//
//			// Write member information to the file
//			outFile << member.membershipID << "," << member.startDate << "," << member.endDate << ","
//				<< member.membershipStatus << "," << member.packageID << "," << member.trainerID << ","
//				<< member.amount << "," << member.paymentMethod << endl;
//
//			outFile.close();
//			cout << "Member information has been written to the file." << endl;
//		}
//		else {
//			cout << "Unable to open file." << endl;
//		}
//	}
//};
//
//class Equipment {
//private:
//	int equipmentID;
//	string name;
//	string type;
//	double quantity;
//	string Pdate;
//	double price;
//
//
//public:
//	Equipment() {}
//	Equipment(int equipmentID, string name, string type, double quantity, string Pdate, double price) {
//		this->equipmentID = equipmentID;
//		this->name = name;
//		this->type = type;
//		this->quantity = quantity;
//		this->Pdate = Pdate;
//		this->price = price;
//	}
//
//	void addEquipment() {
//		cout << "Enter Equipment ID: ";
//		cin >> equipmentID;
//		cout << "Enter Name: ";
//		cin.ignore();
//		getline(cin, name);
//		cout << "Enter Type: ";
//		getline(cin, type);
//		cout << "Enter Quantity: ";
//		cin >> quantity;
//		cout << "Enter Purchasing Date: ";
//		cin.ignore();
//		getline(cin, Pdate);
//		cout << "Enter Price: ";
//		cin >> price;
//	}
//
//	void removeEquipment() {
//		equipmentID = 0;
//		name = "";
//		type = "";
//		quantity = 0.0;
//		Pdate = "";
//		price = 0.0;
//	}
//
//	void searchEquipment(int mID) {
//		if (equipmentID == mID) {
//			cout << "Equipment ID: " << equipmentID << endl;
//			cout << "Name: " << name << endl;
//			cout << "Type: " << type << endl;
//			cout << "Quantity: " << quantity << endl;
//			cout << "Purchasing Date: " << Pdate << endl;
//			cout << "Price: " << price << endl;
//		}
//		else {
//			cout << "Equipment not found!" << endl;
//		}
//	}
//
//	void updateEquipment(int mID) {
//		if (equipmentID == mID) {
//			cout << "Enter Equipment ID: ";
//			cin >> equipmentID;
//			cout << "Enter Name: ";
//			cin.ignore();
//			getline(cin, name);
//			cout << "Enter Type: ";
//			getline(cin, type);
//			cout << "Enter Quantity: ";
//			cin >> quantity;
//			cout << "Enter Purchasing Date: ";
//			cin.ignore();
//			getline(cin, Pdate);
//			cout << "Enter Price: ";
//			cin >> price;
//		}
//		else {
//			cout << "Equipment not found!" << endl;
//		}
//	}
//
//	void viewEquipment() {
//		cout << "Equipment ID: " << equipmentID << endl;
//		cout << "Name: " << name << endl;
//		cout << "Type: " << type << endl;
//		cout << "Quantity: " << quantity << endl;
//		cout << "Purchasing Date: " << Pdate << endl;
//		cout << "Price: " << price << endl;
//	}
//	void writeToFile(const string& filename) {
//		ofstream outFile(filename, ios::app);
//		if (outFile.is_open()) {
//			outFile << equipmentID << endl;
//			outFile << name << endl;
//			outFile << type << endl;
//			outFile << quantity << endl;
//			outFile << Pdate << endl;
//			outFile << price << endl;
//
//			outFile.close();
//			cout << "Data written to the file successfully." << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//	void readFromFile(const string& filename) {
//		ifstream inFile(filename);
//		if (inFile.is_open()) {
//			while (inFile >> equipmentID) {
//				inFile.ignore();
//				getline(inFile, name);
//				getline(inFile, type);
//				inFile >> quantity;
//				inFile.ignore();
//				getline(inFile, Pdate);
//				inFile >> price;
//				inFile.ignore();
//			}
//
//			inFile.close();
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//
//};
//class Attendance{
//private:
//	int attendanceID;
//	int userID;
//	string date;
//	string timeIn;
//	string timeOut;
//	string memberName;
//	Equipment equipment; // Composition: Attendance has an Equipment
//
//	void markAttendance() {
//		cout << "Enter Attendance ID: ";
//		cin >> attendanceID;
//		cout << "Enter Member Name: ";
//		cin.ignore();
//		getline(cin, memberName);
//		equipment.addEquipment();
//	}
//
//public:
//	Attendance() {}
//	Attendance(int aID, int uID, string d, string tIn, string tOut) {
//		attendanceID = aID;
//		userID = uID;
//		date = d;
//		timeIn = tIn;
//		timeOut = tOut;
//	}
//
//	void addAttendance() {
//		cout << "Enter Attendance ID: ";
//		cin >> attendanceID;
//		cout << "Enter User ID: ";
//		cin >> userID;
//		cout << "Enter Date (in yyyy-mm-dd format): ";
//		cin >> date;
//		cout << "Enter Time In (in hh:mm:ss format): ";
//		cin >> timeIn;
//		cout << "Enter Time Out (in hh:mm:ss format): ";
//		cin >> timeOut;
//	}
//
//	void removeAttendance() {
//		attendanceID = 0;
//		userID = 0;
//		date = "";
//		timeIn = "";
//		timeOut = "";
//	}
//
//	void searchAttendance(int aID) {
//		if (attendanceID == aID) {
//			cout << "Attendance ID: " << attendanceID << endl;
//			cout << "User ID: " << userID << endl;
//			cout << "Date: " << date << endl;
//			cout << "Time In: " << timeIn << endl;
//			cout << "Time Out: " << timeOut << endl;
//		}
//		else {
//			cout << "Attendance not found!" << endl;
//		}
//	}
//
//	void updateAttendance(int aID) {
//		if (attendanceID == aID) {
//			cout << "Enter User ID: ";
//			cin >> userID;
//			cout << "Enter Date (in yyyy-mm-dd format): ";
//			cin >> date;
//			cout << "Enter Time In (in hh:mm:ss format): ";
//			cin >> timeIn;
//			cout << "Enter Time Out (in hh:mm:ss format): ";
//			cin >> timeOut;
//		}
//		else {
//			cout << "Attendance not found!" << endl;
//		}
//	}
//
//	void viewAttendance() {
//		cout << "Attendance ID: " << attendanceID << endl;
//		cout << "User ID: " << userID << endl;
//		cout << "Date: " << date << endl;
//		cout << "Time In: " << timeIn << endl;
//		cout << "Time Out: " << timeOut << endl;
//	}
//	void writeToFile(const string& filename) {
//		ofstream aoutFile(filename);
//		if (aoutFile.is_open()) {
//			aoutFile << attendanceID << endl;
//			aoutFile << userID << endl;
//			aoutFile << date << endl;
//			aoutFile << timeIn << endl;
//			aoutFile << timeOut << endl;
//			aoutFile.close();
//			cout << "Data written to the file successfully." << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//	void readFromFile(const string& filename) {
//		ifstream attendanceFile(filename);
//		if (attendanceFile.is_open()) {
//			attendanceFile >> attendanceID;
//			attendanceFile >> userID;
//			attendanceFile.ignore();
//			getline(attendanceFile, date);
//			getline(attendanceFile, timeIn);
//			getline(attendanceFile, timeOut);
//			attendanceFile.close();
//			cout << "Data Read from File" << endl;
//		}
//		else {
//			cout << "Unable to open the file." << endl;
//		}
//	}
//};
//bool authenticate(const string& username, const string& password) {
//	if (username == "admin" && password == "password") {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//class RevenueReport : public Report {
//public:
//	void generateReport() override {
//		cout << "Generating revenue report..." << endl;
//		double revenueData[] = { 1000.0, 1500.0, 1200.0, 1800.0, 2000.0 };
//		double totalRevenue = 0.0;
//		for (int i = 0; i < sizeof(revenueData) / sizeof(revenueData[0]); i++) {
//			totalRevenue += revenueData[i];
//		}
//		cout << "==========================" << endl;
//		cout << "      Revenue Report      " << endl;
//		cout << "==========================" << endl;
//		cout << "Date          Revenue    " << endl;
//		cout << "--------------------------" << endl;
//		for (int i = 0; i < sizeof(revenueData) / sizeof(revenueData[0]); i++) {
//			cout << "2023-01-0" << i + 1 << " | " << fixed << setprecision(2) << revenueData[i] << endl;
//		}
//		cout << "--------------------------" << endl;
//		cout << "Total Revenue: " << fixed << setprecision(2) << totalRevenue << endl;
//		cout << "==========================" << endl;
//	}
//};
//class AttendanceReport : public Report{
//public:
//	void generateReport() override {
//		cout << "Generating attendance report..." << endl;
//
//		int attendanceData[] = { 25, 30, 28, 32, 29 };
//		int totalAttendance = 0;
//		for (int i = 0; i < sizeof(attendanceData) / sizeof(attendanceData[0]); i++) {
//			totalAttendance += attendanceData[i];
//		}
//		cout << "==========================" << endl;
//		cout << "    Attendance Report     " << endl;
//		cout << "==========================" << endl;
//		cout << "Date         | Attendance " << endl;
//		cout << "--------------------------" << endl;
//		for (int i = 0; i < sizeof(attendanceData) / sizeof(attendanceData[0]); i++) {
//			cout << "2023-01-0" << i + 1 << " | " << attendanceData[i] << " members" << endl;
//		}
//		cout << "--------------------------" << endl;
//		cout << "Total Attendance: " << totalAttendance << " members" << endl;
//		cout << "==========================" << endl;
//	}
//};
//class EquipmentReport : public Report ,public Equipment{
//public:
//	void generateReport() override {
//		cout << "Generating equipment report..." << endl;
//		cout << "Equipment ID: 1" << endl;
//		cout << "Name: Treadmill" << endl;
//		cout << "Quantity: 5" << endl;
//		cout << endl;
//
//		cout << "Equipment ID: 2" << endl;
//		cout << "Name: Dumbbells" << endl;
//		cout << "Quantity: 10" << endl;
//		cout << endl;
//		Equipment e;
//		e.viewEquipment();
//	}
//};
//class UserReport : public Report,public User {
//public:
//	void generateReport() override {
//		cout << "Generating user report..." << endl;
//		User user;
//		user.displayUser();
//	}
//};
//int main()
//{
//	int choice1, choice;
//	User user;
//	string username, password;
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	cout << "=== Login Page ===" << endl;
//	cout << "Please enter your credentials." << endl;
//	cout << "Username: ";
//	cin >> username;
//	cout << "Password: ";
//	cin >> password;
//
//	if (authenticate(username, password)) {
//		system("cls");
//		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//		cout << "***************Login successful! Welcome " << username << "***************" << endl;
//		cout << endl << endl << "                      MENU                   " << endl;
//		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
//		cout << "Enter 1 to Manage Members\nEnter 2 To Manage Staff\nEnter 3 to Manage Trainers\nEnter 4 To Manage Equipments\nEnter 5 to Manage Packages\nEnter 6 to Manage Attendance\nEnter 7 to Manage User\nEnter 8 TO Generate Reports\nEnter 0 to Quit\n";
//		cin >> choice1;
//		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//		while (choice1 != 0)
//		{
//			system("cls");
//			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//			switch (choice1)
//			{
//			case 1:
//			{
//				Member member;
//				system("cls");
//				cout << "=== Membership Management System ===" << endl;
//				cout << "1. Add Member" << endl;
//				cout << "2. Remove Member" << endl;
//				cout << "3. Search Member" << endl;
//				cout << "4. Update Member" << endl;
//				cout << "5. View Member" << endl;
//				cout << "0. Exit" << endl;
//
//				do {
//					cout << "Enter your choice: ";
//					cin >> choice;
//
//					switch (choice) {
//					case 1:
//						member.writeMembersToFile();
//						break;
//					case 2:
//						member.removeMember();
//						cout << "Member removed successfully." << endl;
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter Membership ID to search: ";
//						cin >> searchID;
//						member.searchMember(searchID);
//						break;
//					case 4:
//						int updateID;
//						cout << "Enter Membership ID to update: ";
//						cin >> updateID;
//						member.updateMember(updateID);
//						cout << "Member updated successfully." << endl;
//						break;
//					case 5:
//						int viewID;
//						cout << "Enter Membership ID to view: ";
//						cin >> viewID;
//						member.searchMember(viewID);
//						break;
//					case 0:
//						cout << "Exiting the program..." << endl;
//						break;
//					default:
//						cout << "Invalid choice. Please try again." << endl;
//						break;
//					}
//				} while (choice != 0);
//				break;
//			}
//			case 2:
//			{
//				Staff staff;
//				system("cls");
//				cout << "=== Staff Management System ===" << endl;
//				cout << "1. Add Staff" << endl;
//				cout << "2. Remove Staff" << endl;
//				cout << "3. Search Staff" << endl;
//				cout << "4. Update Staff" << endl;
//				cout << "5. View Staff" << endl;
//				cout << "0. Exit" << endl;
//
//				do {
//					cout << "Enter your choice: ";
//					cin >> choice;
//
//					switch (choice) {
//					case 1:
//						staff.addStaff();
//						staff.writeStaffToFile();
//						break;
//					case 2:
//						staff.removeStaff();
//						cout << "Staff removed successfully." << endl;
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter Staff ID to search: ";
//						cin >> searchID;
//						staff.searchStaff(searchID);
//						break;
//					case 4:
//						int updateID;
//						cout << "Enter Staff ID to update: ";
//						cin >> updateID;
//						staff.updateStaff(updateID);
//						cout << "Staff updated successfully." << endl;
//						break;
//					case 5:
//						staff.readStaffFromFile();
//						break;
//					case 0:
//						cout << "Exiting the program..." << endl;
//						break;
//					default:
//						cout << "Invalid choice. Please try again." << endl;
//						break;
//					}
//				} while (choice != 0);
//				break;
//			}
//			case 3:
//			{
//				Trainer trainer;
//
//				cout << "=== Trainer Management System ===" << endl;
//				cout << "1. Add Trainer" << endl;
//				cout << "2. Remove Trainer" << endl;
//				cout << "3. Search Trainer" << endl;
//				cout << "4. Update Trainer" << endl;
//				cout << "5. View Trainer" << endl;
//				cout << "0. Exit" << endl;
//
//				do {
//					cout << "Enter your choice: ";
//					cin >> choice;
//
//					switch (choice) {
//					case 1:
//						trainer.addTrainer();
//						trainer.writeTrainerToFile();
//						break;
//					case 2:
//						trainer.removeTrainer();
//						cout << "Trainer removed successfully." << endl;
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter Trainer ID to search: ";
//						cin >> searchID;
//						trainer.searchTrainer(searchID);
//						break;
//					case 4:
//						int updateID;
//						cout << "Enter Trainer ID to update: ";
//						cin >> updateID;
//						trainer.updateTrainer(updateID);
//						cout << "Trainer updated successfully." << endl;
//						break;
//					case 5:
//						trainer.viewTrainer();
//						break;
//					case 0:
//						cout << "Exiting the program..." << endl;
//						break;
//					default:
//						cout << "Invalid choice. Please try again." << endl;
//						break;
//					}
//				} while (choice != 0);
//				break;
//			}
//
//			case 4:
//			{
//				system("cls");
//				Equipment e1;
//				int choice;
//				do {
//					cout << "Enter Choice:\n";
//					cout << "1. Add Equipment\n";
//					cout << "2. Remove Equipment\n";
//					cout << "3. Search Equipment\n";
//					cout << "4. Update Equipment\n";
//					cout << "5. View Equipment\n";
//					cout << "6. Exit\n";
//					cin >> choice;
//					switch (choice) {
//					case 1:
//						e1.addEquipment();
//						break;
//					case 2:
//						e1.removeEquipment();
//						break;
//					case 3:
//						int id;
//						cout << "Enter Equipment ID to search: ";
//						cin >> id;
//						e1.searchEquipment(id);
//						break;
//					case 4:
//						int mID;
//						cout << "Enter Equipment ID to update: ";
//						cin >> mID;
//						e1.updateEquipment(mID);
//						break;
//					case 5:
//						e1.viewEquipment();
//						break;
//					case 6:
//						cout << "Exiting Program..." << endl;
//						break;
//					default:
//						cout << "Invalid Choice!" << endl;
//						break;
//					}
//				} while (choice != 6);
//				break;
//			}
//
//			case 5:
//			{
//				system("cls");
//				WorkoutPackage package;
//
//				cout << "=== Workout Package Management System ===" << endl;
//				cout << "1. Add Package" << endl;
//				cout << "2. Remove Package" << endl;
//				cout << "3. Search Package" << endl;
//				cout << "4. Update Package" << endl;
//				cout << "5. View Package" << endl;
//				cout << "0. Exit" << endl;
//
//				do {
//					cout << "Enter your choice: ";
//					cin >> choice;
//
//					switch (choice) {
//					case 1:
//						package.addPackage();
//						package.writeToFile("packages.txt");
//						break;
//					case 2:
//						package.removePackage();
//						cout << "Package removed successfully." << endl;
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter Package ID to search: ";
//						cin >> searchID;
//						package.searchPackage(searchID);
//						break;
//					case 4:
//						int updateID;
//						cout << "Enter Package ID to update: ";
//						cin >> updateID;
//						package.updatePackage(updateID);
//						cout << "Package updated successfully." << endl;
//						break;
//					case 5:
//						int viewID;
//						cout << "Enter Package ID to view: ";
//						cin >> viewID;
//						package.searchPackage(viewID);
//						break;
//					case 0:
//						cout << "Exiting the program..." << endl;
//						break;
//					default:
//						cout << "Invalid choice. Please try again." << endl;
//						break;
//					}
//				} while (choice != 0);
//				break;
//			}
//			case 6:
//			{
//				system("cls");
//				Attendance attendance;
//
//				cout << "=== Attendance Management System ===" << endl;
//				cout << "1. Add Attendance" << endl;
//				cout << "2. Remove Attendance" << endl;
//				cout << "3. Search Attendance" << endl;
//				cout << "4. Update Attendance" << endl;
//				cout << "5. View Attendance" << endl;
//				cout << "0. Exit" << endl;
//
//				do {
//					cout << "Enter your choice: ";
//					cin >> choice;
//
//					switch (choice) {
//					case 1:
//						attendance.addAttendance();
//						attendance.writeToFile("attendance.txt");
//						break;
//					case 2:
//						attendance.removeAttendance();
//						cout << "Attendance removed successfully." << endl;
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter Attendance ID to search: ";
//						cin >> searchID;
//						attendance.searchAttendance(searchID);
//						break;
//					case 4:
//						int updateID;
//						cout << "Enter Attendance ID to update: ";
//						cin >> updateID;
//						attendance.updateAttendance(updateID);
//						cout << "Attendance updated successfully." << endl;
//						break;
//					case 5:
//						int viewID;
//						cout << "Enter Attendance ID to view: ";
//						cin >> viewID;
//						attendance.searchAttendance(viewID);
//						break;
//					case 0:
//						cout << "Exiting the program..." << endl;
//						break;
//					default:
//						cout << "Invalid choice. Please try again." << endl;
//						break;
//					}
//				} while (choice != 0);
//				break;
//			}
//
//			case 7:
//			{
//				system("cls");
//				cout << "=== User Management System ===" << endl;
//				cout << "1. Add User" << endl;
//				cout << "2. Remove User" << endl;
//				cout << "3. Search User" << endl;
//				cout << "4. Update User" << endl;
//				cout << "5. Display All Users" << endl;
//				cout << "0. Exit" << endl;
//
//				do {
//					cout << "Enter your choice: ";
//					cin >> choice;
//					switch (choice) {
//					case 1:
//						user.addUser();
//						break;
//					case 2:
//						user.removeUser();
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter ID to search: ";
//						cin >> searchID;
//						user.searchUser(searchID);
//						break;
//					case 4:
//						user.updateUser();
//						break;
//					case 5:
//						user.displayUser();
//						break;
//					case 0:
//						cout << "Exiting the program..." << endl;
//						break;
//					default:
//						cout << "Invalid choice. Please try again." << endl;
//						break;
//					}
//				} while (choice != 0);
//				break;
//			}
//
//			case 8:
//			{
//				system("cls");
//				cout << "Enter 1 to Generate Revenue Report" << endl;
//				cout << "Enter 2 to Generate Attendance Report " << endl;
//				cout << "Enter 3 to Generate Equipment Report" << endl;
//				cout << "Enter 4 to Generate User Report" << endl;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1:
//				{
//					Report *report=new RevenueReport;
//					report->generateReport();
//					break;
//				}
//				case 2:
//				{
//					Report* report = new AttendanceReport;
//					report->generateReport();
//					break;
//				}
//				case 3:
//				{
//					Report* report = new EquipmentReport;
//					report->generateReport();
//					break;
//				}
//				case 4:
//				{
//					Report* report = new UserReport;
//					report->generateReport();
//					break;
//				}
//				default:
//					cout << "Invalid choice." << endl;
//					break;
//				}
//				break;
//			}
//			default:
//				cout << "Invalid Entry";
//			}	
//			if (choice == 0)
//			{
//				system("cls");
//				cout << endl << endl << "                      MENU                   " << endl;
//				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
//				cout << "Enter 1 to Manage Members\nEnter 2 To Manage Staff\nEnter 3 to Manage Trainers\nEnter 4 To Manage Equipments\nEnter 5 to Manage Packages\nEnter 6 to Manage Attendance\nEnter 7 to Manage User\nEnter 0 to Quit\n";
//				cin >> choice1;
//			}
//
//		}
//
//	}
//	else {
//		cout << "Login failed! Invalid credentials." << endl;
//		cout << "Cannot proceed further       " << endl;
//
//		system("pause");
//	}
//}
//	
//
