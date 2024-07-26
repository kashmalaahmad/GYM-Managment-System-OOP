//int main()
//{
//	int choice, searchID;
//	User u;
//	do {
//		cout << "1. Add user\n";
//		cout << "2. Remove user\n";
//		cout << "3. Search user\n";
//		cout << "4. Update user\n";
//		cout << "5. View user\n";
//		cout << "6. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			u.addUser();
//			break;
//		case 2:
//			u.removeUser();
//			break;
//		case 3:
//			cout << "Enter ID to search: ";
//			cin >> searchID;
//			u.searchUser(searchID);
//			break;
//		case 4:
//			u.updateUser();
//			break;
//		case 5:
//			u.viewUser();
//			break;
//		case 6:
//			exit(0);
//		default:
//			cout << "Invalid choice!" << endl;
//		}
//	} while (choice != 6);
//	return 0;
//}