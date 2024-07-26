//#include <iostream>
//#include <fstream>
//#include <string>
//#include<cstdlib>
//#include <windows.h>
//
//using namespace std;
//
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
//class Staff {
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
//class Member {
//private:
//	int membershipID;
//	string startDate;
//	string endDate;
//	string membershipStatus;
//	int packageID;
//	int trainerID;
//	double amount;
//	string paymentMethod;
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
//
//	void addMember() {
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
//	void readMembersFromFile() {
//		ifstream inFile("members.txt");
//		if (inFile.is_open()) {
//			string membershipID, startDate, endDate, membershipStatus, packageID, trainerID, amount, paymentMethod;
//
//			while (getline(inFile, membershipID, ',')) {
//				getline(inFile, startDate, ',');
//				getline(inFile, endDate, ',');
//				getline(inFile, membershipStatus, ',');
//				getline(inFile, packageID, ',');
//				getline(inFile, trainerID, ',');
//				getline(inFile, amount, ',');
//				getline(inFile, paymentMethod);
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
//	class WorkoutPackage
//	{
//	private:
//		int packageID;
//		string title;
//		string description;
//		double price;
//		int duration;
//
//	public:
//		WorkoutPackage() {}
//		WorkoutPackage(int pID, string t, string d, double p, int dur) {
//			packageID = pID;
//			title = t;
//			description = d;
//			price = p;
//			duration = dur;
//		}
//
//		void addPackage() {
//			cout << "Enter Package ID: ";
//			cin >> packageID;
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
//
//		void removePackage() {
//			packageID = 0;
//			title = "";
//			description = "";
//			price = 0.0;
//			duration = 0;
//		}
//
//		void searchPackage(int pID) {
//			if (packageID == pID) {
//				cout << "Package ID: " << packageID << endl;
//				cout << "Title: " << title << endl;
//				cout << "Description: " << description << endl;
//				cout << "Price: " << price << endl;
//				cout << "Duration: " << duration << " days" << endl;
//			}
//			else {
//				cout << "Package not found!" << endl;
//			}
//		}
//
//		void updatePackage(int pID) {
//			if (packageID == pID) {
//				cout << "Enter Title: ";
//				cin.ignore();
//				getline(cin, title);
//				cout << "Enter Description: ";
//				getline(cin, description);
//				cout << "Enter Price: ";
//				cin >> price;
//				cout << "Enter Duration (in days): ";
//				cin >> duration;
//			}
//			else {
//				cout << "Package not found!" << endl;
//			}
//		}
//
//		void viewPackage() {
//			cout << "Package ID: " << packageID << endl;
//			cout << "Title: " << title << endl;
//			cout << "Description: " << description << endl;
//			cout << "Price: " << price << endl;
//			cout << "Duration: " << duration << " days" << endl;
//		}
//		void writeToFile(const string& filename) {
//			ofstream outFile(filename);
//			if (outFile.is_open()) {
//				outFile << packageID << endl;
//				outFile << title << endl;
//				outFile << description << endl;
//				outFile << price << endl;
//				outFile << duration << endl;
//				outFile.close();
//				cout << "Data written to the file successfully." << endl;
//			}
//			else {
//				cout << "Unable to open the file." << endl;
//			}
//		}
//		void readFromFile(const string& filename) {
//			ifstream inFile(filename);
//			if (inFile.is_open()) {
//				inFile >> packageID;
//				inFile.ignore();
//				getline(inFile, title);
//				getline(inFile, description);
//				inFile >> price;
//				inFile >> duration;
//				inFile.close();
//				cout << "Data read from the file successfully." << endl;
//			}
//			else {
//				cout << "Unable to open the file." << endl;
//			}
//		}
//	};
//	class Equipment {
//	private:
//		int equipmentID;
//		string name;
//		string type;
//		double quantity;
//		string Pdate;
//		double price;
//
//	public:
//		Equipment() {}
//		Equipment(int equipmentID, string name, string type, double quantity, string Pdate, double price) {
//			this->equipmentID = equipmentID;
//			this->name = name;
//			this->type = type;
//			this->quantity = quantity;
//			this->Pdate = Pdate;
//			this->price = price;
//		}
//
//		void addEquipment() {
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
//
//		void removeEquipment() {
//			equipmentID = 0;
//			name = "";
//			type = "";
//			quantity = 0.0;
//			Pdate = "";
//			price = 0.0;
//		}
//
//		void searchEquipment(int mID) {
//			if (equipmentID == mID) {
//				cout << "Equipment ID: " << equipmentID << endl;
//				cout << "Name: " << name << endl;
//				cout << "Type: " << type << endl;
//				cout << "Quantity: " << quantity << endl;
//				cout << "Purchasing Date: " << Pdate << endl;
//				cout << "Price: " << price << endl;
//			}
//			else {
//				cout << "Equipment not found!" << endl;
//			}
//		}
//
//		void updateEquipment(int mID) {
//			if (equipmentID == mID) {
//				cout << "Enter Equipment ID: ";
//				cin >> equipmentID;
//				cout << "Enter Name: ";
//				cin.ignore();
//				getline(cin, name);
//				cout << "Enter Type: ";
//				getline(cin, type);
//				cout << "Enter Quantity: ";
//				cin >> quantity;
//				cout << "Enter Purchasing Date: ";
//				cin.ignore();
//				getline(cin, Pdate);
//				cout << "Enter Price: ";
//				cin >> price;
//			}
//			else {
//				cout << "Equipment not found!" << endl;
//			}
//		}
//
//		void viewEquipment() {
//			cout << "Equipment ID: " << equipmentID << endl;
//			cout << "Name: " << name << endl;
//			cout << "Type: " << type << endl;
//			cout << "Quantity: " << quantity << endl;
//			cout << "Purchasing Date: " << Pdate << endl;
//			cout << "Price: " << price << endl;
//		}
//		void writeToFile(const string& filename) {
//			ofstream outFile(filename, ios::app);
//			if (outFile.is_open()) {
//				outFile << equipmentID << endl;
//				outFile << name << endl;
//				outFile << type << endl;
//				outFile << quantity << endl;
//				outFile << Pdate << endl;
//				outFile << price << endl;
//
//				outFile.close();
//				cout << "Data written to the file successfully." << endl;
//			}
//			else {
//				cout << "Unable to open the file." << endl;
//			}
//		}
//		void readFromFile(const string& filename) {
//			ifstream inFile(filename);
//			if (inFile.is_open()) {
//				while (inFile >> equipmentID) {
//					inFile.ignore();
//					getline(inFile, name);
//					getline(inFile, type);
//					inFile >> quantity;
//					inFile.ignore();
//					getline(inFile, Pdate);
//					inFile >> price;
//					inFile.ignore();
//				}
//
//				inFile.close();
//			}
//			else {
//				cout << "Unable to open the file." << endl;
//			}
//		}
//
//};
//	class Attendance {
//	private:
//		int attendanceID;
//		int userID;
//		string date;
//		string timeIn;
//		string timeOut;
//
//	public:
//		Attendance() {}
//		Attendance(int aID, int uID, string d, string tIn, string tOut) {
//			attendanceID = aID;
//			userID = uID;
//			date = d;
//			timeIn = tIn;
//			timeOut = tOut;
//		}
//
//		void addAttendance() {
//			cout << "Enter Attendance ID: ";
//			cin >> attendanceID;
//			cout << "Enter User ID: ";
//			cin >> userID;
//			cout << "Enter Date (in yyyy-mm-dd format): ";
//			cin >> date;
//			cout << "Enter Time In (in hh:mm:ss format): ";
//			cin >> timeIn;
//			cout << "Enter Time Out (in hh:mm:ss format): ";
//			cin >> timeOut;
//		}
//
//		void removeAttendance() {
//			attendanceID = 0;
//			userID = 0;
//			date = "";
//			timeIn = "";
//			timeOut = "";
//		}
//
//		void searchAttendance(int aID) {
//			if (attendanceID == aID) {
//				cout << "Attendance ID: " << attendanceID << endl;
//				cout << "User ID: " << userID << endl;
//				cout << "Date: " << date << endl;
//				cout << "Time In: " << timeIn << endl;
//				cout << "Time Out: " << timeOut << endl;
//			}
//			else {
//				cout << "Attendance not found!" << endl;
//			}
//		}
//
//		void updateAttendance(int aID) {
//			if (attendanceID == aID) {
//				cout << "Enter User ID: ";
//				cin >> userID;
//				cout << "Enter Date (in yyyy-mm-dd format): ";
//				cin >> date;
//				cout << "Enter Time In (in hh:mm:ss format): ";
//				cin >> timeIn;
//				cout << "Enter Time Out (in hh:mm:ss format): ";
//				cin >> timeOut;
//			}
//			else {
//				cout << "Attendance not found!" << endl;
//			}
//		}
//
//		void viewAttendance() {
//			cout << "Attendance ID: " << attendanceID << endl;
//			cout << "User ID: " << userID << endl;
//			cout << "Date: " << date << endl;
//			cout << "Time In: " << timeIn << endl;
//			cout << "Time Out: " << timeOut << endl;
//		}
//		void writeToFile(const string& filename) {
//			ofstream aoutFile(filename);
//			if (aoutFile.is_open()) {
//				aoutFile << attendanceID << endl;
//				aoutFile << userID << endl;
//				aoutFile << date << endl;
//				aoutFile << timeIn << endl;
//				aoutFile << timeOut << endl;
//				aoutFile.close();
//				cout << "Data written to the file successfully." << endl;
//			}
//			else {
//				cout << "Unable to open the file." << endl;
//			}
//		}
//		void readFromFile(const string& filename) {
//			ifstream attendanceFile(filename);
//			if (attendanceFile.is_open()) {
//				attendanceFile>> attendanceID;
//				attendanceFile>> userID;
//				attendanceFile.ignore();
//				getline(attendanceFile, date);
//				getline(attendanceFile, timeIn);
//				getline(attendanceFile, timeOut);
//				attendanceFile.close();
//				cout << "Data Read from File" << endl;
//			}
//			else {
//				cout << "Unable to open the file." << endl;
//			}
//		}
//};
//bool authenticate(const string& username, const string& password) {
//	if (username == "admin" && password == "password") {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int main() {
//	int choice1, choice;
//	char key;
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
//		cout << "*************** Login successful! Welcome " << username << " ***************" << endl;
//		cout << endl << endl << "                      MENU                   " << endl;
//
//		do {
//			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
//			cout << "Enter 1 to Manage Members" << endl;
//			cout << "Enter 2 to Manage Staff" << endl;
//			cout << "Enter 3 to Manage Trainers" << endl;
//			cout << "Enter 4 to Manage Equipments" << endl;
//			cout << "Enter 5 to Manage Packages" << endl;
//			cout << "Enter 6 to Manage Attendance" << endl;
//			cout << "Enter 7 to Manage User" << endl;
//			cout << "Enter 0 to Quit" << endl;
//			cin >> choice1;
//			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//
//			switch (choice1) {
//			case 1: {
//				// Manage Members
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
//						member.addMember();
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
//						member.viewMember();
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
//			case 2: {
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
//						// Implement writeStaffToFile() function
//						break;
//					case 2:
//						staff.removeStaff();
//						cout << "Staff removed successfully." << endl;
//						break;
//					case 3:
//						int searchID;
//						cout << "Enter Staff ID to search: ";
//						cin >> searchID;
//						// Implement searchStaff() function
//						break;
//					case 4:
//						int updateID;
//						cout << "Enter Staff ID to update: ";
//						cin >> updateID;
//						// Implement updateStaff() function
//						cout << "Staff updated successfully." << endl;
//						break;
//					case 5:
//						int viewID;
//						cout << "Enter Staff ID to view: ";
//						cin >> viewID;
//						// Implement viewStaff() function
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
//				// Manage Trainers
//				// Implement Trainer class and its operations
//				break;
//			case 4:
//				// Manage Equipments
//				// Implement Equipment class and its operations
//				break;
//			case 5:
//				// Manage Packages
//				// Implement Package class and its operations
//				break;
//			case 6:
//				// Manage Attendance
//				// Implement Attendance class and its operations
//				break;
//			case 7:
//				// Manage User
//				// Implement User class and its operations
//				break;
//			case 0:
//				cout << "Exiting the program..." << endl;
//				break;
//			default:
//				cout << "Invalid choice. Please try again." << endl;
//				break;
//			}
//		} while (choice1 != 0);
//
//		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//		cout << "*************** Thank you for using the program! ***************" << endl;
//		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//	}
//	else {
//		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//		cout << "Invalid credentials. Access denied." << endl;
//		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//	}
//
//	return 0;
//}
//
