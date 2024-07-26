//int main() {
//	WorkoutPackage wp;
//	int choice;
//	int packageID;
//	bool running = true;
//
//	while (running) {
//		cout << "\n\n*** Workout Package Management System ***\n\n";
//		cout << "1. Add Package\n";
//		cout << "2. Remove Package\n";
//		cout << "3. Search Package\n";
//		cout << "4. Update Package\n";
//		cout << "5. View Package\n";
//		cout << "6. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			wp.addPackage();
//			break;
//		case 2:
//			cout << "Enter Package ID: ";
//			cin >> packageID;
//			wp.removePackage();
//			break;
//		case 3:
//			cout << "Enter Package ID: ";
//			cin >> packageID;
//			wp.searchPackage(packageID);
//			break;
//		case 4:
//			cout << "Enter Package ID: ";
//			cin >> packageID;
//			wp.updatePackage(packageID);
//			break;
//		case 5:
//			wp.viewPackage();
//			break;
//		case 6:
//			running = false;
//			break;
//		default:
//			cout << "Invalid choice. Try again.";
//		}
//	}