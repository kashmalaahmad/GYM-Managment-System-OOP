#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include <windows.h>
#include <sstream>
using namespace std;
class base {
public:
	virtual void add() = 0;
	virtual void update(int id) = 0;
	virtual void view() = 0;
	virtual void search(int id) = 0;
};

class User : public base {
protected:
	int ID;
	string name, email;
	string phone;
	string gender;
	string dateOfBirth;

public:
	User() {
		name = "";
		ID = 0;
		email = "";
		phone = "";
		gender = "";
		dateOfBirth = "";
	}

	User(int ID, string name, string email, string phone, string gender, string dateOfBirth) {
		this->name = name;
		this->ID = ID;
		this->email = email;
		this->phone = phone;
		this->gender = gender;
		this->dateOfBirth = dateOfBirth;
	}

	void add() {
		ofstream out("user_data.txt", ios::app);
		if (!out.is_open()) {
			cout << "Unable to open the file." << endl;
			return;
		}

		try {
			cout << "Enter ID: ";
			cin >> ID;
			cin.ignore();
			cout << "Enter name: ";
			getline(cin, name);
			cout << "Enter email: ";
			getline(cin, email);
			cout << "Enter phone: ";
			getline(cin, phone);
			cout << "Enter gender: ";
			getline(cin, gender);
			cout << "Enter date of birth: ";
			getline(cin, dateOfBirth);

			out << ID << endl;
			out << name << endl;
			out << email << endl;
			out << phone << endl;
			out << gender << endl;
			out << dateOfBirth << endl;

			cout << "User added successfully." << endl;
		}
		catch (...) {
			cout << "An error occurred while adding the user." << endl;
		}

		out.close();
	}

	void removeUser(int id) {
		ifstream in("user_data.txt");
		ofstream out("temp.txt");
		bool found = false;
		int tempID;
		string tempName, tempEmail, tempPhone, tempGender, tempDOB;

		while (in >> tempID) {
			getline(in >> ws, tempName);
			getline(in >> ws, tempEmail);
			getline(in >> ws, tempPhone);
			getline(in >> ws, tempGender);
			getline(in >> ws, tempDOB);

			if (id == tempID) {
				found = true;
				continue; // Skip writing the user to the temporary file
			}

			out << tempID << endl;
			out << tempName << endl;
			out << tempEmail << endl;
			out << tempPhone << endl;
			out << tempGender << endl;
			out << tempDOB << endl;
		}

		in.close();
		out.close();

		if (found) {
			if (remove("user_data.txt") == 0 && rename("temp.txt", "user_data.txt") == 0) {
				cout << "User removed successfully." << endl;
			}
			else {
				cout << "Error occurred while removing the user." << endl;
			}
		}
		else {
			cout << "User not found." << endl;
		}
	}

	void search(int searchID) {
		ifstream in("user_data.txt");
		int id1;
		string name1, email1, phone1, gender1, dob1;
		bool found = false;
		try {
			while (in >> id1) {
				getline(in >> ws, name1);
				getline(in >> ws, email1);
				getline(in >> ws, phone1);
				getline(in >> ws, gender1);
				getline(in >> ws, dob1);

				if (searchID == id1) {
					found = true;
					cout << "ID: " << id1 << endl;
					cout << "Name: " << name1 << endl;
					cout << "Email: " << email1 << endl;
					cout << "Phone: " << phone1 << endl;
					cout << "Gender: " << gender1 << endl;
					cout << "Date of Birth: " << dob1 << endl;
					break;
				}
			}
			in.close();

			if (!found) {
				cout << "User not found." << endl;
			}
		}
		catch (...) {
			cout << "An error occurred while searching for the user." << endl;
		}
	}

	void update(int id) {
		fstream file("user_data.txt");
		fstream temp("temp.txt", ios::out | ios::trunc);
		bool found = false;
		int ID;
		string name, email, phone, gender, dob;

		try {
			while (file >> ID) {
				getline(file >> ws, name);
				getline(file >> ws, email);
				getline(file >> ws, phone);
				getline(file >> ws, gender);
				getline(file >> ws, dob);

				if (id == ID) {
					found = true;
					cout << "Enter new name: ";
					getline(cin, name);
					cout << "Enter new email: ";
					getline(cin, email);
					cout << "Enter new phone: ";
					getline(cin, phone);
					cout << "Enter new gender: ";
					getline(cin, gender);
					cout << "Enter new date of birth: ";
					getline(cin, dob);
				}

				temp << ID << endl;
				temp << name << endl;
				temp << email << endl;
				temp << phone << endl;
				temp << gender << endl;
				temp << dob << endl;
			}
			file.close();
			temp.close();

			if (found) {
				remove("user_data.txt");
				rename("temp.txt", "user_data.txt");
				cout << "User updated successfully." << endl;
			}
			else {
				cout << "User not found." << endl;
			}
		}
		catch (...) {
			cout << "An error occurred while updating the user." << endl;
		}
	}

	void view() {
		ifstream in("user_data.txt");
		int id1;
		string name1, email1, phone1, gender1, dob1;

		try {
			while (in >> id1) {
				getline(in >> ws, name1);
				getline(in >> ws, email1);
				getline(in >> ws, phone1);
				getline(in >> ws, gender1);
				getline(in >> ws, dob1);

				cout << "ID: " << id1 << endl;
				cout << "Name: " << name1 << endl;
				cout << "Email: " << email1 << endl;
				cout << "Phone: " << phone1 << endl;
				cout << "Gender: " << gender1 << endl;
				cout << "Date of Birth: " << dob1 << endl;
				cout << endl;
			}
			in.close();
		}
		catch (...) {
			cout << "An error occurred while viewing users.";
		}
	}

		void deleteUser(int id) {
			fstream file("user_data.txt");
			fstream temp("temp.txt", ios::out | ios::trunc);
			bool found = false;
			int ID;
			string name, email, phone, gender, dob;

			try {
				while (file >> ID) {
					getline(file >> ws, name);
					getline(file >> ws, email);
					getline(file >> ws, phone);
					getline(file >> ws, gender);
					getline(file >> ws, dob);

					if (id == ID) {
						found = true;
						continue;
					}

					temp << ID << endl;
					temp << name << endl;
					temp << email << endl;
					temp << phone << endl;
					temp << gender << endl;
					temp << dob << endl;
				}
				file.close();
				temp.close();

				if (found) {
					remove("user_data.txt");
					rename("temp.txt", "user_data.txt");
					cout << "User deleted successfully." << endl;
				}
				else {
					cout << "User not found." << endl;
				}
			}
			catch (...) {
				cout << "An error occurred while deleting the user." << endl;
			}
		}
	};

	class Trainer : public base {
	private:
		int trainerID;
		string name;
		string email;
		string phone;
		string specialization;
		string shift;
		double salary;

	public:
		Trainer() {}

		Trainer(int trainerID, string name, string email, string phone, string specialization, string shift, double salary) {
			this->trainerID = trainerID;
			this->name = name;
			this->email = email;
			this->phone = phone;
			this->specialization = specialization;
			this->shift = shift;
			this->salary = salary;
		}

		void add() {
			ofstream out("trainer.txt", ios::app);
			if (out.is_open()) {
				cout << "Enter ID: ";
				cin >> trainerID;
				cin.ignore();
				cout << "Enter name: ";
				getline(cin, name);
				cout << "Enter email: ";
				getline(cin, email);
				cout << "Enter phone: ";
				getline(cin, phone);
				cout << "Enter specialization: ";
				getline(cin, specialization);
				cout << "Enter shift: ";
				getline(cin, shift);
				cout << "Enter salary: ";
				cin >> salary;
				cin.ignore();

				out << trainerID << endl;
				out << name << endl;
				out << email << endl;
				out << phone << endl;
				out << specialization << endl;
				out << shift << endl;
				out << salary << endl;

				cout << "Trainer added successfully." << endl;
				out.close();
			}
			else {
				cout << "Unable to open the file." << endl;
			}
		}

		void removeTrainer(int id) {
			ifstream inFile("trainer.txt");
			ofstream outFile("temp.txt");
			bool found = false;

			while (inFile >> trainerID) {
				inFile.ignore();
				getline(inFile, name);
				getline(inFile, email);
				getline(inFile, phone);
				getline(inFile, specialization);
				getline(inFile, shift);
				inFile >> salary;
				inFile.ignore();

				if (id == trainerID) {
					found = true;
					continue;
				}

				outFile << trainerID << endl;
				outFile << name << endl;
				outFile << email << endl;
				outFile << phone << endl;
				outFile << specialization << endl;
				outFile << shift << endl;
				outFile << salary << endl;
			}
			inFile.close();
			outFile.close();

			if (found) {
				remove("trainer.txt");
				rename("temp.txt", "trainer.txt");
				cout << "Trainer removed successfully." << endl;
			}
			else {
				cout << "Trainer not found." << endl;
			}
		}


		void view() {
			ifstream in("trainer.txt");
			if (in.is_open()) {
				while (in >> trainerID) {
					in.ignore();
					getline(in, name);
					getline(in, email);
					getline(in, phone);
					getline(in, specialization);
					getline(in, shift);
					in >> salary;
					in.ignore();

					cout << "Trainer ID: " << trainerID << endl;
					cout << "Name: " << name << endl;
					cout << "Email: " << email << endl;
					cout << "Phone: " << phone << endl;
					cout << "Specialization: " << specialization << endl;
					cout << "Shift: " << shift << endl;
					cout << "Salary: " << salary << endl;
					cout << endl;
				}
				in.close();
			}
			else {
				cout << "Unable to open the file." << endl;
			}
		}

		void update(int id) {
			ifstream inFile("trainer.txt");
			if (!inFile) {
				cout << "Unable to open the file." << endl;
				return;
			}

			ofstream outFile("temp.txt");
			if (!outFile) {
				cout << "Unable to create temporary file." << endl;
				inFile.close();
				return;
			}

			bool found = false;

			while (inFile >> trainerID) {
				inFile.ignore();
				getline(inFile, name);
				getline(inFile, email);
				getline(inFile, phone);
				getline(inFile, specialization);
				getline(inFile, shift);
				inFile >> salary;
				inFile.ignore();

				if (id == trainerID) {
					found = true;
					cout << "Trainer found. Enter the updated details:" << endl;
					cout << "Enter name: ";
					getline(cin, name);
					cout << "Enter email: ";
					getline(cin, email);
					cout << "Enter phone: ";
					getline(cin, phone);
					cout << "Enter specialization: ";
					getline(cin, specialization);
					cout << "Enter shift: ";
					getline(cin, shift);
					cout << "Enter salary: ";
					cin >> salary;
					cin.ignore();
				}

				outFile << trainerID << endl;
				outFile << name << endl;
				outFile << email << endl;
				outFile << phone << endl;
				outFile << specialization << endl;
				outFile << shift << endl;
				outFile << salary << endl;
			}

			inFile.close();
			outFile.close();

			if (!found) {
				cout << "Trainer not found." << endl;
			}
			else {
				remove("trainer.txt");
				rename("temp.txt", "trainer.txt");
				cout << "Trainer details updated successfully." << endl;
			}
		}



		void search(int id) {
			ifstream in("trainer.txt");
			bool found = false;

			while (in >> trainerID) {
				in.ignore();
				getline(in, name);
				getline(in, email);
				getline(in, phone);
				getline(in, specialization);
				getline(in, shift);
				in >> salary;
				in.ignore();

				if (id == trainerID) {
					found = true;
					cout << "Trainer found:" << endl;
					cout << "Trainer ID: " << trainerID << endl;
					cout << "Name: " << name << endl;
					cout << "Email: " << email << endl;
					cout << "Phone: " << phone << endl;
					cout << "Specialization: " << specialization << endl;
					cout << "Shift: " << shift << endl;
					cout << "Salary: " << salary << endl;
					cout << endl;
					break;
				}
			}
			in.close();

			if (!found) {
				cout << "Trainer not found." << endl;
			}
		}

	};

class Staff : public User {
private:
	int ID;
	string name;
	string email;
	string phone;
	string hireDate;
	string jobTitle;
	double salary;

public:
	Staff() {}

	Staff(int ID, string name, string email, string phone, string hireDate, string jobTitle, double salary,
		string username, string password)
		: ID(ID), name(name), email(email), phone(phone), hireDate(hireDate), jobTitle(jobTitle), salary(salary)
	  {}

	void add() {
		ofstream out("staff.txt", ios::app);
		if (out.is_open()) {
			cout << "Enter ID: ";
			cin >> ID;
			cin.ignore();
			cout << "Enter name: ";
			getline(cin, name);
			cout << "Enter email: ";
			getline(cin, email);
			cout << "Enter phone: ";
			getline(cin, phone);
			cout << "Enter hiring date (YYYY-MM-DD): ";
			getline(cin, hireDate);
			cout << "Enter job title: ";
			getline(cin, jobTitle);
			cout << "Enter salary: ";
			cin >> salary;

			out << ID << endl;
			out << name << endl;
			out << email << endl;
			out << phone << endl;
			out << hireDate << endl;
			out << jobTitle << endl;
			out << salary << endl;

			cout << "Staff added successfully." << endl;
		}
		else {
			cout << "Unable to open the file." << endl;
		}
		out.close();
	}

	void removeStaff(int id) {
		ifstream inFile("staff.txt");
		ofstream outFile("temp.txt");

		bool found = false;
		while (inFile >> ID >> name >> email >> phone >> hireDate >> jobTitle >> salary ) {
			if (id == ID) {
				found = true;
				ID = 0;
				name = "";
				email = "";
				phone = "";
				hireDate = "";
				jobTitle = "";
				salary = 0.00;
				outFile << ID << endl;
				outFile << name << endl;
				outFile << email << endl;
				outFile << phone << endl;
				outFile << hireDate << endl;
				outFile << jobTitle << endl;
				outFile << salary << endl;
			}
			else {
				outFile << ID << endl;
				outFile << name << endl;
				outFile << email << endl;
				outFile << phone << endl;
				outFile << hireDate << endl;
				outFile << jobTitle << endl;
				outFile << salary << endl;
			}
		}
		inFile.close();
		outFile.close();

		if (found) {
			remove("staff.txt");
			rename("temp.txt", "staff.txt");
			cout << "Staff removed successfully." << endl;
		}
		else {
			cout << "Staff not found." << endl;
		}
	}

	void search(int searchID) {
		ifstream inFile("staff.txt");
		ifstream in("user.txt");
		bool found = false;

		while (in >> ID >> name >> email >> phone >> dateOfBirth) {
			// Check if the ID matches the searchID
			if (ID == searchID) {
				// Display user details
				cout << "User ID: " << ID << endl;
				cout << "Name: " << name << endl;
				cout << "Email: " << email << endl;
				cout << "Phone: " << phone << endl;
				cout << "Date of Birth: " << dateOfBirth << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "User not found." << endl;
		}
		in.close();

		found = false; // Reset found flag for staff search

					   // Search for staff details
		while (inFile >> ID >> hireDate >> jobTitle >> salary) {
			// Check if the ID matches the searchID
			if (ID == searchID) {
				// Display staff details
				cout << "Staff ID: " << ID << endl;
				cout << "Hiring Date: " << hireDate << endl;
				cout << "Job Title: " << jobTitle << endl;
				cout << "Salary: " << salary << endl;
				found = true;
				break;
			}
		}

		inFile.close();

		if (!found) {
			cout << "Staff not found." << endl;
		}
	}


	void update(int searchID) {
		ifstream inFile("staff.txt");
		ofstream tempFile("temp.txt");
		User::update(searchID);
		bool found = false;
		while (inFile >> ID >> name >> email >> phone >> hireDate >> jobTitle >> salary ) {
			if (ID == searchID) {
				found = true;
				cin.ignore(); // Ignore the newline character after cin
				cout << "Enter Hiring Date (YYYY-MM-DD): ";
				getline(cin, hireDate);
				cout << "Enter Job Title: ";
				getline(cin, jobTitle);
				cout << "Enter Salary: ";
				cin >> salary;
			}
			tempFile << ID << endl;
			tempFile << name << endl;
			tempFile << email << endl;
			tempFile << phone << endl;
			tempFile << hireDate << endl;
			tempFile << jobTitle << endl;
			tempFile << salary << endl;
		}

		if (!found) {
			cout << "Staff not found." << endl;
		}

		inFile.close();
		tempFile.close();

		remove("staff.txt");
		rename("temp.txt", "staff.txt");
	}
	void view() {
		ifstream inFile("staff.txt");
		ifstream in("user.txt");
		User::view();
		if (inFile.is_open()) {
			while(in>>ID>>name>>email>>phone>>gender>>dateOfBirth)
			while (inFile >>hireDate >> jobTitle >> salary ) {
				cout << "Staff ID: " << ID << endl;
				cout << "Staff Name: " << name << endl;
				cout << "Hiring Date: " << hireDate << endl;
				cout << "Job Title: " << jobTitle << endl;
				cout << "Salary: " << salary << endl;
				cout << endl;
				cout << "Staff email: " << email << endl;
				cout << "Staff Phone no: " << phone << endl;
			}
			inFile.close();
		}
		else {
			cout << "Unable to open file." << endl;
		}
	}

};

class WorkoutPackage:public base
{
private:
	int packageID;
	string title;
	string description;
	double price;
	int duration;

public:
	WorkoutPackage() {}
	WorkoutPackage(int pID, string t, string d, double p, int dur) {
		packageID = pID;
		title = t;
		description = d;
		price = p;
		duration = dur;
	}

	void add() {
		cout << "Enter Package ID: ";
		cin >> packageID;
		cout << "Enter Title: ";
		cin.ignore();
		getline(cin, title);
		cout << "Enter Description: ";
		getline(cin, description);
		cout << "Enter Price: ";
		cin >> price;
		cout << "Enter Duration (in days): ";
		cin >> duration;
	}

	void removePackage() {
		packageID = 0;
		title = "";
		description = "";
		price = 0.0;
		duration = 0;
	}

	void search(int pID) {
		ifstream inFile("package.txt");
		bool found = false;
		while (inFile >> packageID >> title >> description >> price >> duration)
		{
			if (packageID == pID) {
				found = true;
				cout << "Package ID: " << packageID << endl;
				cout << "Title: " << title << endl;
				cout << "Description: " << description << endl;
				cout << "Price: " << price << endl;
				cout << "Duration: " << duration << " days" << endl;
			}
		}
		if(!found) {
			cout << "Package not found!" << endl;
		}
	}

	void update(int pID) {
		ifstream inFile("package.txt");
		ofstream outFile("package.txt", ios::app);
		bool found = false;
		while (inFile >> packageID >> title >> description >> price >> duration)

		{
			if (packageID == pID) {
				found = true;
				cout << "Enter Id: ";
				cin >> packageID;
				cout << "Enter Title: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter Description: ";
				getline(cin, description);
				cout << "Enter Price: ";
				cin >> price;
				cout << "Enter Duration (in days): ";
				cin >> duration;
				outFile << packageID << endl;
				outFile << title << endl;
				outFile << description << endl;
				outFile << price << endl;
				outFile << duration << endl;
				
			}
		}
		if(!found){
			cout << "Package not found!" << endl;
		}
	}

	void view() {
		ifstream inFile("package.txt");
		while (inFile >> packageID >> title >> description >> price >> duration)
		{
			cout << "Package ID: " << packageID << endl;
			cout << "Title: " << title << endl;
			cout << "Description: " << description << endl;
			cout << "Price: " << price << endl;
			cout << "Duration: " << duration << " days" << endl;
		}
	}
	void writeToFile(const string& filename) {
		ofstream outFile(filename);
		if (outFile.is_open()) {
			outFile << packageID << endl;
			outFile << title << endl;
			outFile << description << endl;
			outFile << price << endl;
			outFile << duration << endl;
			outFile.close();
			cout << "Data written to the file successfully." << endl;
		}
		else {
			cout << "Unable to open the file." << endl;
		}
	}
	void readFromFile(const string& filename) {
		ifstream inFile(filename);
		if (inFile.is_open()) {
			inFile >> packageID;
			inFile.ignore();
			getline(inFile, title);
			getline(inFile, description);
			inFile >> price;
			inFile >> duration;
			inFile.close();
			cout << "Data read from the file successfully." << endl;
		}
		else {
			cout << "Unable to open the file." << endl;
		}
	}
};
class Member :public User, public base {
private:
	int membershipID;
	string startDate;
	string endDate;
	string membershipStatus;
	int packageID;
	int trainerID;
	double amount;
	string paymentMethod; int memberID;
	string memberName;
	int age;
	string gender;
	WorkoutPackage package;

public:
	Member() {}
	Member(int mID, string sDate, string eDate, string mStatus, int pID, int tID, double amt, string pMethod) {
		membershipID = mID;
		startDate = sDate;
		endDate = eDate;
		membershipStatus = mStatus;
		packageID = pID;
		trainerID = tID;
		amount = amt;
		paymentMethod = pMethod;
	}
	void add() {
		cout << "Enter Member Name: ";
		cin.ignore();
		getline(cin, memberName);
		cout << "Enter Member Age: ";
		cin >> age;
		cout << "Enter Member Gender: ";
		cin.ignore();
		getline(cin, gender);

		cout << "Enter Membership ID: ";
		cin >> membershipID;
		cout << "Enter Start Date (YYYY-MM-DD): ";
		cin >> startDate;
		cout << "Enter End Date (YYYY-MM-DD): ";
		cin >> endDate;
		cout << "Enter Membership Status: ";
		cin >> membershipStatus;
		cout << "Enter Package ID: ";
		cin >> packageID;
		cout << "Enter Trainer ID: ";
		cin >> trainerID;
		cout << "Enter Amount: ";
		cin >> amount;
		cout << "Enter Payment Method: ";
		cin >> paymentMethod;
	}

	void removeMember(int id) {
		ifstream inFile("members.txt");
		ofstream outFile("temp.txt");
		bool found = false;

		while (inFile >> membershipID >> startDate >> endDate >> membershipStatus >> packageID >> trainerID >> amount >> paymentMethod) {
			if (membershipID == id) {
				found = true;
				continue; // Skip writing the record to the temporary file
			}
			outFile << membershipID << " " << startDate << " " << endDate << " " << membershipStatus << " "
				<< packageID << " " << trainerID << " " << amount << " " << paymentMethod << endl;
		}

		inFile.close();
		outFile.close();

		if (found) {
			remove("members.txt");
			rename("temp.txt", "members.txt");
			cout << "Member removed successfully." << endl;
		}
		else {
			cout << "Member not found." << endl;
		}
	}

	void search(int mID) {
		ifstream inFile("members.txt");
		bool found = false;

		while (inFile >> membershipID >> startDate >> endDate >> membershipStatus >> packageID >> trainerID >> amount >> paymentMethod) {
			if (membershipID == mID) {
				found = true;
				cout << "Membership ID: " << membershipID << endl;
				cout << "Start Date: " << startDate << endl;
				cout << "End Date: " << endDate << endl;
				cout << "Membership Status: " << membershipStatus << endl;
				cout << "Package ID: " << packageID << endl;
				cout << "Trainer ID: " << trainerID << endl;
				cout << "Amount: " << amount << endl;
				cout << "Payment Method: " << paymentMethod << endl;
				break;
			}
		}

		inFile.close();

		if (!found) {
			cout << "Member not found." << endl;
		}
	}
	void update(int mID) {
		ifstream inFile("members.txt");
		ofstream outFile("temp.txt");
		bool found = false;

		while (inFile >> membershipID >> startDate >> endDate >> membershipStatus >> packageID >> trainerID >> amount >> paymentMethod) {
			if (membershipID == mID) {
				found = true;
				cout << "Enter Start Date (YYYY-MM-DD): ";
				cin >> startDate;
				cout << "Enter End Date (YYYY-MM-DD): ";
				cin >> endDate;
				cout << "Enter Membership Status: ";
				cin >> membershipStatus;
				cout << "Enter Package ID: ";
				cin >> packageID;
				cout << "Enter Trainer ID: ";
				cin >> trainerID;
				cout << "Enter Amount: ";
				cin >> amount;
				cout << "Enter Payment Method: ";
				cin >> paymentMethod;
			}
			outFile << membershipID << " " << startDate << " " << endDate << " " << membershipStatus << " "
				<< packageID << " " << trainerID << " " << amount << " " << paymentMethod << endl;
		}

		inFile.close();
		outFile.close();

		if (found) {
			remove("members.txt");
			rename("temp.txt", "members.txt");
			cout << "Member details updated successfully." << endl;
		}
		else {
			cout << "Member not found." << endl;
		}
	}

	void view() {
		ifstream inFile("members.txt");
		if (!inFile.is_open()) {
			cout << "Unable to open the file." << endl;
			return;
		}

		while (inFile >> membershipID >> startDate >> endDate >> membershipStatus >> packageID >> trainerID >> amount >> paymentMethod) {
			cout << "Membership ID: " << membershipID << endl;
			cout << "Start Date: " << startDate << endl;
			cout << "End Date: " << endDate << endl;
			cout << "Membership Status: " << membershipStatus << endl;
			cout << "Package ID: " << packageID << endl;
			cout << "Trainer ID: " << trainerID << endl;
			cout << "Amount: " << amount << endl;
			cout << "Payment Method: " << paymentMethod << endl;
			cout << endl;
		}

		inFile.close();
	}

	void writeMembersToFile() {
		ofstream outFile("members.txt", ios::app);
		if (outFile.is_open()) {
			Member member;
			member.add();

			outFile << member.membershipID << " " << member.startDate << " " << member.endDate << " "
				<< member.membershipStatus << " " << member.packageID << " " << member.trainerID << " "
				<< member.amount << " " << member.paymentMethod << endl;

			outFile.close();
			cout << "Member information has been written to the file." << endl;
		}
		else {
			cout << "Unable to open file." << endl;
		}
	}
};
class Equipment :public base {
private:
	int equipmentID;
	string name;
	string type;
	string quantity;
	string Pdate;
	string price;


public:
	Equipment() {}
	Equipment(int equipmentID, string name, string type, string quantity, string Pdate, string price) {
		this->equipmentID = equipmentID;
		this->name = name;
		this->type = type;
		this->quantity = quantity;
		this->Pdate = Pdate;
		this->price = price;
	}

	void add() {
		ofstream out("equipment.txt", ios::app);
		if (!out.is_open()) {
			cout << "Unable to open the file." << endl;
			return;
		}
		try
		{
			cout << "Enter Equipment ID: ";
			cin >> equipmentID;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Type: ";
			getline(cin, type);
			cout << "Enter Quantity: ";
			cin >> quantity;
			cout << "Enter Purchasing Date: ";
			cin.ignore();
			getline(cin, Pdate);
			cout << "Enter Price: ";
			cin >> price;

			out << equipmentID << endl;
			out << name << endl;
			out << type << endl;
			out << quantity << endl;
			out << Pdate << endl;
			out << price << endl;

			cout << "Equipment added successfully..." << endl;
		}
		catch (...) {
			cout << "An error occurred while adding the user." << endl;
		}

		out.close();
	}

	void removeEquipment(int id) {
		ifstream inFile("equipment.txt");
		ofstream out("temp.txt");
		bool found = false;
		int temp1ID;
		string temp1name, temp1type, temp1Pdate;
		double temp1quantity, temp1price;
		while (inFile >> equipmentID)
		{
			getline(inFile >> ws, temp1name);
			getline(inFile >> ws, temp1type);
			inFile >> ws, temp1quantity;
			getline(inFile >> ws, temp1Pdate);
			inFile >> ws, temp1price;
			if (id == equipmentID)
			{
				found = true;
				continue;
			}
			out << equipmentID << endl;
			out << name << endl;
			out << type << endl;
			out << quantity << endl;
			out << Pdate << endl;
			out << price << endl;
		}
		inFile.close();
		out.close();

		if (found)
		{
			if (remove("equipment.txt") == 0 && rename("temp.txt", "equipment.txt") == 0) {
				cout << "User removed successfully." << endl;
			}
			else {
				cout << "Error occurred while removing the user." << endl;
			}
		}
		else {
			cout << "User not found." << endl;
		}
	}

	void search(int mID) {
		ifstream inFile("equipment.txt");

		bool found = false;
		try {
			while (inFile >> equipmentID)
			{
				getline(inFile >> ws, name);
				getline(inFile >> ws, type);
				getline(inFile >> ws, quantity);
				getline(inFile >> ws, Pdate);
				getline(inFile >> ws, price);
				if (equipmentID == mID) {
					found = true;
					cout << "ID: " << equipmentID << endl;
					cout << "Name: " << name << endl;
					cout << "Type: " << type << endl;
					cout << "Qunatity: " << quantity << endl;
					cout << "Pdate: " << Pdate << endl;
					cout << "Price: " << price << endl;
					break;
				}
				inFile.close();

				if (!found) {
					cout << "Equipment not found." << endl;
				}
			}
		}
		catch (...) {
			cout << "An error occurred while searching for the Equipment." << endl;
		}
	}

	void update(int mID) {
		ifstream inFile("equipment.txt");
		if (!inFile) {
			cout << "Unable to open the file." << endl;
			return;
		}

		ofstream outFile("temp.txt");
		if (!outFile) {
			cout << "Unable to create temporary file." << endl;
			inFile.close();
			return;
		}

		bool found = false;

		while (inFile >> equipmentID) {
			inFile.ignore();
			getline(inFile >> ws, name);
			getline(inFile >> ws, type);
			(inFile >> quantity);
			getline(inFile >> ws, Pdate);
			(inFile >> price);
			inFile.ignore();

			if (mID == equipmentID) {
				found = true;
				cout << "Equipment found. Enter the updated details:" << endl;
				cout << "Enter Equipment ID: ";
				cin >> equipmentID;
				cout << "Enter Name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter Type: ";
				getline(cin, type);
				cout << "Enter Quantity: ";
				cin >> quantity;
				cout << "Enter Purchasing Date: ";
				cin.ignore();
				getline(cin, Pdate);
				cout << "Enter Price: ";
				cin >> price;
			}

			outFile << equipmentID << endl;
			outFile << name << endl;
			outFile << type << endl;
			outFile << quantity << endl;
			outFile << Pdate << endl;
			outFile << price << endl;
		}

		inFile.close();
		outFile.close();

		if (!found) {
			cout << "Trainer not found." << endl;
		}
		else {
			remove("equipment.txt");
			rename("temp.txt", "equipment.txt");
			cout << "Equipment details updated successfully." << endl;
		}
	}

	void view() {
		ifstream inFile("equipment.txt");
		if (inFile.is_open()) {
			while (inFile >> equipmentID) {

				getline(inFile >> ws, name);
				getline(inFile >> ws, type);
				inFile >> ws, quantity;
				getline(inFile >> ws, Pdate);
				inFile >> ws, price;
				inFile.ignore();

				cout << "ID: " << equipmentID << endl;
				cout << "Name: " << name << endl;
				cout << "Type: " << type << endl;
				cout << "Qunatity: " << quantity << endl;
				cout << "Pdate: " << Pdate << endl;
				cout << "Price: " << price << endl;

			}
			inFile.close();
		}
		else {
			cout << "Unable to open the file." << endl;
		}
	}
	void readFromFile(const string& filename) {
		ifstream inFile(filename);
		if (inFile.is_open()) {
			while (inFile >> equipmentID) {
				inFile.ignore();
				getline(inFile, name);
				getline(inFile, type);
				inFile >> quantity;
				inFile.ignore();
				getline(inFile, Pdate);
				inFile >> price;
				inFile.ignore();
			}

			inFile.close();
		}
		else {
			cout << "Unable to open the file." << endl;
		}
	}
};
class Attendance:public base{
private:
	int attendanceID;
	int userID;
	string date;
	string timeIn;
	string timeOut;
	string memberName;
	Equipment equipment; // Composition: Attendance has an Equipment

	void markAttendance() {
		cout << "Enter Attendance ID: ";
		cin >> attendanceID;
		cout << "Enter Member Name: ";
		cin.ignore();
		getline(cin, memberName);
		equipment.add();
	}

public:
	Attendance() {}
	Attendance(int aID, int uID, string d, string tIn, string tOut) {
		attendanceID = aID;
		userID = uID;
		date = d;
		timeIn = tIn;
		timeOut = tOut;
	}

	void add() {
		cout << "Enter Attendance ID: ";
		cin >> attendanceID;
		cout << "Enter User ID: ";
		cin >> userID;
		cout << "Enter Date (in yyyy-mm-dd format): ";
		cin >> date;
		cout << "Enter Time In (in hh:mm:ss format): ";
		cin >> timeIn;
		cout << "Enter Time Out (in hh:mm:ss format): ";
		cin >> timeOut;
	}

	void removeAttendance(int id ) {
		ifstream inFile("attendance.txt");
		bool found = false;
		while (inFile >> attendanceID >> userID >> date >> timeIn >> timeOut)
		{
			if (id == attendanceID)
			{
				found = true;
				attendanceID = 0;
				userID = 0;
				date = "";
				timeIn = "";
				timeOut = "";
			}
		}
		if (!found)
			cout << "attendance not found" << endl;
	}

	void search(int aID) {
		ifstream inFile("attendance.txt");
		bool found = false;
		while (inFile >> attendanceID >> userID >> date >> timeIn >> timeOut)
		{
			if (attendanceID == aID)
			{
				found = true;
				cout << "Attendance ID: " << attendanceID << endl;
				cout << "User ID: " << userID << endl;
				cout << "Date: " << date << endl;
				cout << "Time In: " << timeIn << endl;
				cout << "Time Out: " << timeOut << endl;
			}
		}
		if(!found)
		{
			cout << "Attendance not found!" << endl;
		}
	}

	void update(int aID) {
		ifstream inFile("attendance.txt");
		ofstream outFile("attendance.txt", ios::app);
		bool found = false;
		while (inFile >> attendanceID >> userID >> date >> timeIn >> timeOut)
		{
			if (attendanceID == aID)
			{
				found = true;
				cout << "Enter User ID: ";
				cin >> userID;
				cout << "Enter Date (in yyyy-mm-dd format): ";
				cin >> date;
				cout << "Enter Time In (in hh:mm:ss format): ";
				cin >> timeIn;
				cout << "Enter Time Out (in hh:mm:ss format): ";
				cin >> timeOut;
				outFile << userID << endl << date << endl << timeIn << endl << timeOut << endl;
			}
		}
		if (!found)
		{
			cout << "Attendance not found!" << endl;
		}
	}

	void view() {
		ifstream inFile("attendance.txt");
		while (inFile >> attendanceID >> userID >> date >> timeIn >> timeOut)
		{
			cout << "Attendance ID: " << attendanceID << endl;
			cout << "User ID: " << userID << endl;
			cout << "Date: " << date << endl;
			cout << "Time In: " << timeIn << endl;
			cout << "Time Out: " << timeOut << endl;
		}
	}
	void writeToFile(const string& filename) {
		ofstream aoutFile(filename);
		if (aoutFile.is_open()) {
			aoutFile << attendanceID << endl;
			aoutFile << userID << endl;
			aoutFile << date << endl;
			aoutFile << timeIn << endl;
			aoutFile << timeOut << endl;
			aoutFile.close();
			cout << "Data written to the file successfully." << endl;
		}
		else {
			cout << "Unable to open the file." << endl;
		}
	}
	void readFromFile(const string& filename) {
		ifstream attendanceFile(filename);
		if (attendanceFile.is_open()) {
			attendanceFile >> attendanceID;
			attendanceFile >> userID;
			attendanceFile.ignore();
			getline(attendanceFile, date);
			getline(attendanceFile, timeIn);
			getline(attendanceFile, timeOut);
			attendanceFile.close();
			cout << "Data Read from File" << endl;
		}
		else {
			cout << "Unable to open the file." << endl;
		}
	}
};
bool authenticate(const string& username, const string& password) {
	if (username == "admin" && password == "password") {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	int choice1, choice;
	base *ptr = NULL;
	string username, password;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "=== Login Page ===" << endl;
	cout << "Please enter your credentials." << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	if (authenticate(username, password)) {
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "***************Login successful! Welcome " << username << "***************" << endl;
		cout << endl << endl << "                      MENU                   " << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << "Enter 1 to Manage Members\nEnter 2 To Manage Staff\nEnter 3 to Manage Trainers\nEnter 4 To Manage Equipments\nEnter 5 to Manage Packages\nEnter 6 to Manage Attendance\nEnter 7 to Manage User\nEnter 0 to Quit\n";
		cin >> choice1;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		while (choice1 != 0)
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			switch (choice1)
			{
			case 1:
			{
				ptr = NULL;
				ptr = new Member;
				Member member;
			system("cls");
			cout << "=== Membership Management System ===" << endl;
			cout << "1. Add Member" << endl;
			cout << "2. Remove Member" << endl;
			cout << "3. Search Member" << endl;
			cout << "4. Update Member" << endl;
			cout << "5. View Member" << endl;
			cout << "0. Exit" << endl;

			do {
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1:
				/*	member.addMember();*/
					member.writeMembersToFile();
					break;
				case 2:
					int id;
					cout << "Enter member id to remove";
					cin >> id;
					member.removeMember(id);
					break;
				case 3:
					int searchID;
					cout << "Enter Membership ID to search: ";
					cin >> searchID;
					ptr->search(searchID);
					break;
				case 4:
					int updateID;
					cout << "Enter Membership ID to update: ";
					cin >> updateID;
					ptr->update(updateID);
					break;
				case 5:
					ptr->view();
					break;
				case 0:
					cout << "Exiting the program..." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
					break;
				}
			} while (choice != 0);
			ptr = NULL;
			break;
			}
			case 2:
			{
				Staff staff;
				ptr = NULL;
				ptr = new Staff;
				system("cls");
				cout << "=== Staff Management System ===" << endl;
				cout << "1. Add Staff" << endl;
				cout << "2. Remove Staff" << endl;
				cout << "3. Search Staff" << endl;
				cout << "4. Update Staff" << endl;
				cout << "5. View Staff" << endl;
				cout << "0. Exit" << endl;

				do {
					cout << "Enter your choice: ";
					cin >> choice;

					switch (choice) {
					case 1:
						ptr->add();
						break;
					case 2:
						int id;
						cout << "Enter staff id to remove";
						cin >> id;
						staff.removeStaff(id);
						break;
					case 3:
						int searchID;
						cout << "Enter Staff ID to search: ";
						cin >> searchID;
						ptr->search(searchID);
						break;
					case 4:
						int updateID;
						cout << "Enter Staff ID to update: ";
						cin >> updateID;
						ptr->update(updateID);
						break;
					case 5:
						ptr->view();
						break;
					case 0:
						cout << "Exiting the program..." << endl;
						break;
					default:
						cout << "Invalid choice. Please try again." << endl;
						break;
					}
				} while (choice != 0);
				ptr = NULL;
				break;
			}
			case 3:
			{
				Trainer trainer;
				ptr = new Trainer;
				cout << "=== Trainer Management System ===" << endl;
				cout << "1. Add Trainer" << endl;
				cout << "2. Remove Trainer" << endl;
				cout << "3. Search Trainer" << endl;
				cout << "4. Update Trainer" << endl;
				cout << "5. View Trainer" << endl;
				cout << "0. Exit" << endl;

				do {
					cout << "Enter your choice: ";
					cin >> choice;

					switch (choice) {
					case 1:
						ptr->add();
						break;
					case 2:
						int id;
						cout << "Enter Id of trainer to remove";
						cin >> id;
						trainer.removeTrainer(id);
						break;
					case 3:
						int searchID;
						cout << "Enter Trainer ID to search: ";
						cin >> searchID;
						ptr->search(searchID);
						break;
					case 4:
						int updateID;
						cout << "Enter Trainer ID to update: ";
						cin >> updateID;
						ptr->update(updateID);
						break;
					case 5:
						ptr->view();
						break;
					case 0:
						cout << "Exiting the program..." << endl;
						break;
					default:
						cout << "Invalid choice. Please try again." << endl;
						break;
					}
				} while (choice != 0);
				ptr = NULL;
				break;

			}
			case 4:
			{
				system("cls");
				Equipment e1;
				ptr = new Equipment;
			int choice;
			do {
				cout << "Enter Choice:\n";
				cout << "1. Add Equipment\n";
				cout << "2. Remove Equipment\n";
				cout << "3. Search Equipment\n";
				cout << "4. Update Equipment\n";
				cout << "5. View Equipment\n";
				cout << "6. Exit\n";
				cin >> choice;
				switch (choice) {
				case 1:
					ptr->add();
					break;
				case 2:
					int id;
					cout << "Enter equipment id to remove";
					cin >> id;
					e1.removeEquipment(id);
					break;
				case 3:
					cout << "Enter Equipment ID to search: ";
					cin >> id;
					ptr->search(id);
					break;
				case 4:
					int mID;
					cout << "Enter Equipment ID to update: ";
					cin >> mID;
					ptr->update(mID);
					break;
				case 5:
					ptr->view();
					break;
				case 6:
					cout << "Exiting Program..." << endl;
					break;
				default:
					cout << "Invalid Choice!" << endl;
				}
			} while (choice != 6);
			ptr = NULL;
			break;
			}
			case 5:
			{
				system("cls");
				WorkoutPackage package;
				ptr = new WorkoutPackage;
				cout << "=== Workout Package Management System ===" << endl;
				cout << "1. Add Package" << endl;
				cout << "2. Remove Package" << endl;
				cout << "3. Search Package" << endl;
				cout << "4. Update Package" << endl;
				cout << "5. View Package" << endl;
				cout << "0. Exit" << endl;

				do {
					cout << "Enter your choice: ";
					cin >> choice;

					switch (choice) {
					case 1:
						ptr->add();
						package.writeToFile("packages.txt");
						break;
					case 2:
						package.removePackage();
						break;
					case 3:
						int searchID;
						cout << "Enter Package ID to search: ";
						cin >> searchID;
						ptr->search(searchID);
						break;
					case 4:
						int updateID;
						cout << "Enter Package ID to update: ";
						cin >> updateID;
						ptr->update(updateID);
						break;
					case 5:
						ptr->view();
						break;
					case 0:
						cout << "Exiting the program..." << endl;
						break;
					default:
						cout << "Invalid choice. Please try again." << endl;
						break;
					}
				} while (choice != 0);
				ptr = NULL;
				break;

			}
			case 6:
			{system("cls");
			Attendance attendance;
			ptr = new Attendance;
			cout << "=== Attendance Management System ===" << endl;
			cout << "1. Add Attendance" << endl;
			cout << "2. Remove Attendance" << endl;
			cout << "3. Search Attendance" << endl;
			cout << "4. Update Attendance" << endl;
			cout << "5. View Attendance" << endl;
			cout << "0. Exit" << endl;

			do {
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1:
					ptr->add();
					attendance.writeToFile("attendance.txt");
					break;
				case 2:
					int id;
					cout << "Enter attendance id to remove";
					cin >> id;
					attendance.removeAttendance(id);
					break;
				case 3:
					int searchID;
					cout << "Enter Attendance ID to search: ";
					cin >> searchID;
					ptr->search(searchID);
					break;
				case 4:
					int updateID;
					cout << "Enter Attendance ID to update: ";
					cin >> updateID;
					ptr->update(updateID);
					break;
				case 5:
					ptr->view();
					break;
				case 0:
					cout << "Exiting the program..." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
					break;
				}
			} while (choice != 0);
			ptr = NULL;
			break;
			}
			case 7:
			{
				User user;
				ptr = new User;
				system("cls");
				cout << "=== User Management System ===" << endl;
				cout << "1. Add User" << endl;
				cout << "2. Remove User" << endl;
				cout << "3. Search User" << endl;
				cout << "4. Update User" << endl;
				cout << "5. Display All Users" << endl;
				cout << "0. Exit" << endl;

				do {
					cout << "Enter your choice: ";
					cin >> choice;
					switch (choice) {
					case 1:
						ptr->add();
						break;
					case 2:
						int id;
						cout << "Enter id of user to remove";
						cin >> id;
						user.removeUser(id);
						break;
					case 3:
						int searchID;
						cout << "Enter ID to search: ";
						cin >> searchID;
						ptr->search(searchID);
						break;
					case 4:
						int ID;
						cout << "Enter ID: ";
						cin >> ID;
						ptr->update(ID);
						break;
					case 5:
						user.view();
						break;
					case 0:
						cout << "Exiting the program..." << endl;

						break;
					default:
						cout << "Invalid choice. Please try again." << endl;
						break;
					}
				} while (choice != 0);
				ptr = NULL;
				break;
			}
			default: cout << "Invalid Input" << endl;;
			}
			if (choice == 0)
			{
				system("cls");
				cout << endl << endl << "                      MENU                   " << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << "Enter 1 to Manage Members\nEnter 2 To Manage Staff\nEnter 3 to Manage Trainers\nEnter 4 To Manage Equipments\nEnter 5 to Manage Packages\nEnter 6 to Manage Attendance\nEnter 7 to Manage User\nEnter 0 to Quit\n";
				cin >> choice1;
			}
		}while (choice1 != 0);
	}
	else {
		cout << "Login failed! Invalid credentials." << endl;
		cout << "Cannot proceed further       " << endl;
	}
	delete ptr;
	ptr = nullptr;
	system("pause");

}
