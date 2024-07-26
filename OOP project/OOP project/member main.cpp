//int main() {
//	Member member;
//	int choice, mID;
//	while (true) {
//		cout << "1. Add Member\n";
//		cout << "2. Remove Member\n";
//		cout << "3. Search Member\n";
//		cout << "4. Update Member\n";
//		cout << "5. View Member\n";
//		cout << "6. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			member.addMember();
//			break;
//		case 2:
//			cout << "Enter Membership ID to remove: ";
//			cin >> mID;
//			member.removeMember();
//			break;
//		case 3:
//			cout << "Enter Membership ID to search: ";
//			cin >> mID;
//			member.searchMember(mID);
//			break;
//		case 4:
//			cout << "Enter Membership ID to update: ";
//			cin >> mID;
//			member.updateMember(mID);
//			break;
//		case 5:
//			member.viewMember();
//			break;
//		case 6:
//			exit(0);
//		default:
//			cout << "Invalid choice!\n";
//		}
//	}
//	return 0;
//}