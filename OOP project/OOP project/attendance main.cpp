//int main() {
//	Attendance a;
//	int choice;
//	int attendanceID;
//	bool running = true;
//	while (running) {
//		cout << "\n\n*** Attendance Management System ***\n\n";
//		cout << "1. Add Attendance\n";
//		cout << "2. Remove Attendance\n";
//		cout << "3. Search Attendance\n";
//		cout << "4. Update Attendance\n";
//		cout << "5. View Attendance\n";
//		cout << "6. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			a.addAttendance();
//			break;
//		case 2:
//			cout << "Enter Attendance ID: ";
//			cin >> attendanceID;
//			a.removeAttendance();
//			break;
//		case 3:
//			cout << "Enter Attendance ID: ";
//			cin >> attendanceID;
//			a.searchAttendance(attendanceID);
//			break;
//		case 4:
//			cout << "Enter Attendance ID: ";
//			cin >> attendanceID;
//			a.updateAttendance(attendanceID);
//		}
//	}