//int main() {
//	int choice, staffID;
//	Staff staff;
//
//	do {
//		cout << "----------------------------------------------" << endl;
//		cout << " Staff Management System " << endl;
//		cout << "----------------------------------------------" << endl;
//		cout << "1. Add Staff" << endl;
//		cout << "2. Remove Staff" << endl;
//		cout << "3. Search Staff" << endl;
//		cout << "4. Update Staff" << endl;
//		cout << "5. View All Staff" << endl;
//		cout << "6. Exit" << endl;
//		cout << "Enter your choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			staff.addStaff();
//			break;
//		case 2:
//			cout << "Enter Staff ID: ";
//			cin >> staffID;
//			staff.removeStaff();
//			break;
//		case 3:
//			cout << "Enter Staff ID: ";
//			cin >> staffID;
//			staff.searchMember(staffID);
//			break;
//		case 4:
//			cout << "Enter Staff ID: ";
//			cin >> staffID;
//			staff.updateMember(staffID);
//			break;
//		case 5:
//			staff.viewMember();
//			break;
//		case 6:
//			cout << "Exiting the program..." << endl;
//			break;
//		default:
//			cout << "Invalid choice. Please try again." << endl;
//			break;
//		}
//	} while (choice != 6);
//
//	return 0;
//}