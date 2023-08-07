//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <Windows.h>
//#pragma warning (disable: 4996)
//
//void memberLoginMenu();
//void memberCreate();
//void memberLogin();
//void memberDisplay();
//void memberModify();
//void memberSearch();
//void memberDelete();
//void memberModifyMember();
//void memberDisplayMember();
//void memberReport();
//
//typedef struct {
//	char memberID[20], memberName[51], memberGender, memberEmail[51], memberPassword[51], memberIC[20], memberContactNo[20];
//	int day, month, year;
//}Member;
//Member m;
//Member mem[20];
//char currentMemberID[5];
//SYSTEMTIME time;
//
//void main() {
//	memberLoginMenu();
//}
//
//void memberLoginMenu() {
//	int choose;
//
//	do {
//		//printf("   WELCOME TO APAPUNADA\n");
//		printf("       Member Portal\n");
//		printf("===========================\n");
//		printf("| 1. Sign in Account      |\n");
//		printf("| 2. Log in Account       |\n");
//		printf("| 3. Exit                 |\n");
//		printf("===========================\n");
//		printf("Please enter your choice > ");
//		scanf("%d", &choose);
//
//		//Scan the option that user choose and bring them to there
//		switch (choose) {
//		case 1:
//			memberCreate();
//			break;
//		case 2:
//			memberLogin();
//			break;
//		case 3:
//			exit(0);
//			break;
//		default:
//			//Let system to clear the screen
//			printf("Please select the correct option\n\n");
//		}
//		//User can only insert the number 1 to 3
//	} while (choose <= 1 || choose >= 3);
//}
//
//void memberCreate() {
//	char ans;
//	char confirmation;
//	int i = 0, mcreate = 0, z = 0;
//	FILE* file;
//	//Open the member file for appendding
//	file = fopen("member.dat", "ab");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	printf("==================\n");
//	printf("| MEMBER SIGN UP |\n");
//	printf("==================\n");
//	do {
//		printf("\nEnter member ID > ");
//		rewind(stdin);
//		scanf("%[^\n]", &m.memberID);
//		printf("Enter member name > ");
//		rewind(stdin);
//		scanf("%[^\n]", &m.memberName);
//		do {
//			printf("Enter member gender (M/F) > ");
//			rewind(stdin);
//			scanf("%c", &m.memberGender);
//
//			//Check if the gender user enter is male or female
//			if (toupper(m.memberGender) != 'F' && toupper(m.memberGender) != 'M') {
//				printf("**Please enter the correct gender!**\n");
//			}
//			//Loop again if user enter the wrong data
//		} while (toupper(m.memberGender) != 'F' && toupper(m.memberGender) != 'M');
//		do {
//			printf("Enter member IC (without '-') > ");
//			rewind(stdin);
//			scanf("%[^\n]", &m.memberIC);
//
//			//Check if the format of the IC is correct or not
//			if (strlen(m.memberIC) != 12) {
//				printf("**Please enter the correct IC!**\n");
//			}
//			//Loop again if the user enter the wrong IC format
//		} while (strlen(m.memberIC) != 12);
//		printf("Enter member email > ");
//		rewind(stdin);
//		scanf("%[^\n]", &m.memberEmail);
//		printf("Enter member password > ");
//		rewind(stdin);
//		scanf("%[^\n]", &m.memberPassword);
//		do {
//			printf("Enter member contact number > ");
//			rewind(stdin);
//			scanf("%[^\n]", &m.memberContactNo);
//
//			//Check if the contact number range is 10 or 11
//			if (strlen(m.memberContactNo) > 11 || strlen(m.memberContactNo) < 10) {
//				printf("**Please enter the correct contact number!**\n");
//			}
//			//Loop again if the contact number range is wrong
//		} while (strlen(m.memberContactNo) > 11 || strlen(m.memberContactNo) < 10);
//		printf("Are your sure you want to add this new member into system? (Y = Yes) > ");
//		rewind(stdin);
//		scanf("%c", &confirmation);
//
//		//Write all the data into the Member file
//		if (toupper(confirmation) == 'Y') {
//			GetLocalTime(&time);
//			m.day = time.wDay;
//			m.month = time.wMonth;
//			m.year = time.wYear;
//			m.memberGender = toupper(m.memberGender);
//			fwrite(&m, sizeof(Member), 1, file);
//			printf("Account had added successfully on %d/%d/%d!\n", m.day, m.month, m.year);
//		}
//		else {
//			printf("Not saved!\n");
//		}
//		printf("Do you want to continue create a new member? (Y = yes) > ");
//		rewind(stdin);
//		scanf("%c", &ans);
//
//		//Loop again if the user need to create another member
//	} while (toupper(ans) == 'Y');
//
//	//Close the file
//	fclose(file);
//
//}
//
//void memberLogin() {
//	char checkMP[51];
//	int mcheck = 0, mcount = 0, choose;
//
//	printf("=================\n");
//	printf("| MEMBER LOG IN |\n");
//	printf("=================\n");
//	printf("Enter Member ID > ");
//	rewind(stdin);
//	scanf("%[^\n]", &currentMemberID);
//
//	FILE* file;
//	//Open the member file for reading
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Check
//	while (mcheck = 1) {
//		mcheck = 0;
//		rewind(file);
//		//Read the Member file
//		while (fread(&m, sizeof(Member), 1, file) != 0) {
//			//Compare the current member ID with the member ID in the file, if same then proceed
//			if (strcmp(m.memberID, currentMemberID) == 0) {
//				mcheck = 1;
//				printf("Enter Password > ");
//				rewind(stdin);
//				scanf("%[^\n]", checkMP);
//				//Compare the password with the member password in the file, if same then proceed
//				if (strcmp(m.memberPassword, checkMP) == 0) {
//					printf("Login Successful\n\n");
//					printf("       Member Menu\n");
//					printf("===========================\n");
//					printf("| 1. Display Account Info |\n");
//					printf("| 2. Modify Account Info  |\n");
//					printf("| 3. Search Order         |\n");
//					printf("| 4. Delete Account       |\n");
//					printf("| 5. Exit                 |\n");
//					printf("===========================\n");
//					printf("Please enter your choice > ");
//					rewind(stdin);
//					scanf("%d", &choose);
//					//Scan the option that user choose and bring them to there
//
//					do {
//						switch (choose)
//						{
//						case 1:
//							memberDisplayMember();
//							break;
//						case 2:
//							fclose(file);
//							memberModifyMember();
//							break;
//						case 3:
//							memberSearch();
//							break;
//						case 4:
//							memberDelete();
//							break;
//						case 5:
//							memberLoginMenu();
//							break;
//						default:
//							printf("Please select the correct option\n");
//							break;
//						}
//						printf("       Member Menu\n");
//						printf("===========================\n");
//						printf("| 1. Display Account Info |\n");
//						printf("| 2. Modify Account Info  |\n");
//						printf("| 3. Search Order         |\n");
//						printf("| 4. Delete Account       |\n");
//						printf("| 5. Exit                 |\n");
//						printf("===========================\n");
//						printf("Please enter your choice > ");
//						rewind(stdin);
//						scanf("%d", &choose);
//						//Scan the option that user choose and bring them to there
//						//User can only insert 1 to 5
//					} while (choose > 0 || choose < 6);
//					fclose(file);
//					return 0;
//				}
//				else {
//					printf("**Incorrect password.**\n");
//					memberLoginMenu();
//					break;
//				}
//			}
//		}
//		if (mcheck != 1) {
//			//If the member id is not in the file, user need to input again
//			printf("**Incorrent Member ID.**\n");
//			memberLoginMenu();
//		}
//	}
//}
//
//void memberDisplay() {
//	FILE* file;
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	printf("==========================\n");
//	printf("| MEMBER ACCOUNT DISPLAY |\n");
//	printf("==========================\n");
//	printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//	printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//	//Read the member file and print all out
//	while (fread(&m, sizeof(Member), 1, file) != 0) {
//		printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", m.memberID, m.memberName, m.memberPassword, m.memberEmail, m.memberContactNo, m.memberIC, m.memberGender, m.day, m.month, m.year);
//	}
//	fclose(file);
//}
//
//void memberDisplayMember() {
//	int i = 0, mdisplay = 0;
//	FILE* file;
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Copy the whole member file info into member array
//	while (fread(&m, sizeof(Member), 1, file) != 0) {
//		strcpy(mem[mdisplay].memberID, m.memberID);
//		strcpy(mem[mdisplay].memberName, m.memberName);
//		strcpy(mem[mdisplay].memberPassword, m.memberPassword);
//		strcpy(mem[mdisplay].memberEmail, m.memberEmail);
//		strcpy(mem[mdisplay].memberContactNo, m.memberContactNo);
//		strcpy(mem[mdisplay].memberIC, m.memberIC);
//		mem[mdisplay].memberGender = m.memberGender;
//		mem[mdisplay].day = m.day;
//		mem[mdisplay].month = m.month;
//		mem[mdisplay].year = m.year;
//
//		mdisplay++;
//	}
//	fclose(file);
//
//	printf("==================\n");
//	printf("| MEMBER ACCOUNT |\n");
//	printf("==================\n");
//	//Get the current user info and print out
//	for (i = 0; i < mdisplay; i++) {
//		if (strcmp(currentMemberID, mem[i].memberID) == 0) {
//			printf("\n          Member Profile\n");
//			printf("-----------------------------------------\n");
//			printf("Staff ID     : %s\n", mem[i].memberID);
//			printf("Name         : %s\n", mem[i].memberName);
//			printf("Password     : %s\n", mem[i].memberPassword);
//			printf("Email        : %s\n", mem[i].memberEmail);
//			printf("Contact No   : %s\n", mem[i].memberContactNo);
//			printf("IC No        : %s\n", mem[i].memberIC);
//			printf("Gender       : %c\n", mem[i].memberGender);
//			printf("Date Joined  : %02d-%02d-%d\n", mem[i].day, mem[i].month, mem[i].year);
//			printf("-----------------------------------------\n\n");
//			break;
//		}
//	}
//}
//
//void memberModify() {
//	char newmemberName[51], newmemberGender, newmemberEmail[51], newmemberPassword[51], newmemberIC[20], newmemberContactNo[20], memName[51], confirmation, manother;
//	int mcount = 0, i = 0, modifyCount = 0, mchoice, z = 0;
//	FILE* file;
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Copy the whole member file info into member array
//	while (fread(&m, sizeof(Member), 1, file) != 0) {
//		strcpy(mem[mcount].memberID, m.memberID);
//		strcpy(mem[mcount].memberName, m.memberName);
//		strcpy(mem[mcount].memberPassword, m.memberPassword);
//		strcpy(mem[mcount].memberEmail, m.memberEmail);
//		strcpy(mem[mcount].memberContactNo, m.memberContactNo);
//		strcpy(mem[mcount].memberIC, m.memberIC);
//		mem[mcount].memberGender = m.memberGender;
//		mem[mcount].day = m.day;
//		mem[mcount].month = m.month;
//		mem[mcount].year = m.year;
//
//		mcount++;
//	}
//	fclose(file);
//
//	printf("==========\n");
//	printf("| MODIFY |\n");
//	printf("==========\n");
//	printf("Enter member ID > ");
//	rewind(stdin);
//	scanf("%[^\n]", memName);
//	//Find the member ID in the member file
//	for (i = 0; i < mcount; i++) {
//		//If the member ID same in the member file, print out the info
//		if (strcmp(memName, mem[i].memberID) == 0) {
//			do {
//				do {
//					printf("==================\n");
//					printf("| Member Details |\n");
//					printf("==================\n");
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//					printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//					printf("1. Modify Member Name\n");
//					printf("2. Modify Member Password\n");
//					printf("3. Modify Member Email\n");
//					printf("4. Modify Member Contact No.\n");
//					printf("5. Modify Member IC\n");
//					printf("6. Modify Member Gender\n");
//					printf("7. Back\n");
//					printf("Enter the choice you want to modify > ");
//					rewind(stdin);
//					scanf("%d", &mchoice);
//					//Let user to choose the data they want to modify
//					switch (mchoice) {
//					case 1:
//						printf("Enter new member name > ");
//						rewind(stdin);
//						scanf("%[^\n]", &newmemberName);
//						printf("Are you sure you want to modify your name? (Y = Yes) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(mem[i].memberName, newmemberName);
//							printf("Modify Successfully!\n");
//							modifyCount++;
//						}
//						break;
//					case 2:
//						printf("Enter new member Password > ");
//						rewind(stdin);
//						scanf("%[^\n]", &newmemberPassword);
//						printf("Are you sure you want to modify your password? (Y = Yes) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(mem[i].memberPassword, newmemberPassword);
//							printf("Modify Successfully!\n");
//							modifyCount++;
//						}
//						break;
//					case 3:
//						printf("Enter new member email > ");
//						rewind(stdin);
//						scanf("%[^\n]", newmemberEmail);
//						printf("Are you sure you want to modify your email? (Y = Yes) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(mem[i].memberEmail, newmemberEmail);
//							printf("Modify Successfully!\n");
//							modifyCount++;
//						}
//						break;
//					case 4:
//						do {
//							printf("Enter new contact number > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newmemberContactNo);
//							if (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10) {
//								printf("Please enter the correct contact number!\n");
//							}
//						} while (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10);
//						printf("Are you sure you want to modify your contact number? (Y = Yes) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(mem[i].memberContactNo, newmemberContactNo);
//							printf("Modify Successfully!\n");
//							modifyCount++;
//						}
//						break;
//					case 5:
//						do {
//							printf("Enter new member IC > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newmemberIC);
//							if (strlen(newmemberIC) != 12) {
//								printf("Please enter the correct IC!\n");
//							}
//						} while (strlen(newmemberIC) != 12);
//						printf("Are you sure you want to modify your IC? (Y = Yes) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(mem[i].memberIC, newmemberIC);
//							printf("Modify Successfully!\n");
//							modifyCount++;
//						}
//						break;
//					case 6:
//						do {
//							printf("Enter new gender > ");
//							rewind(stdin);
//							scanf("%c", &newmemberGender);
//							if (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M') {
//								printf("Please enter the correct gender!\n");
//							}
//						} while (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M');
//						printf("Are you sure you want to modify your gender? (Y = Yes) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							mem[i].memberGender = toupper(newmemberGender);
//							printf("Modify Successfully!\n");
//							modifyCount++;
//						}
//						break;
//					case 7:
//						break;
//					default:
//						printf("**Please select the correct option.**\n");
//						break;
//					}
//					//Loop again if the choice user enter is not in the range 1 to 6
//				} while (!(mchoice >= 1 && mchoice <= 7));
//				printf("Modify Another record? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &manother);
//				//Loop again if the user need to modify other data
//			} while (toupper(manother) == 'Y');
//		}
//	}
//
//	FILE* ptr;
//	//Open the member file for writing
//	ptr = fopen("member.dat", "wb");
//	//Rewrite all the new data into the Member file
//	for (int i = 0; i < mcount; i++) {
//		fwrite(&mem[i], sizeof(Member), 1, ptr);
//	}
//	printf("%d record(s) modified.", modifyCount);
//
//	fclose(ptr);
//
//}
//
//void memberModifyMember() {
//	char memName[51], newmemberName[51], newmemberGender, newmemberEmail[51], newmemberPassword[51], newmemberIC[20], newmemberContactNo[20], confirmation, manother;
//	int mdfcount = 0, i = 0, modifyCount = 0, mchoice;
//	FILE* file;
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Copy the whole member file into member array
//	while (fread(&m, sizeof(Member), 1, file) != 0) {
//		strcpy(mem[mdfcount].memberID, m.memberID);
//		strcpy(mem[mdfcount].memberName, m.memberName);
//		strcpy(mem[mdfcount].memberPassword, m.memberPassword);
//		strcpy(mem[mdfcount].memberEmail, m.memberEmail);
//		strcpy(mem[mdfcount].memberContactNo, m.memberContactNo);
//		strcpy(mem[mdfcount].memberIC, m.memberIC);
//		mem[mdfcount].memberGender = m.memberGender;
//		mem[mdfcount].day = m.day;
//		mem[mdfcount].month = m.month;
//		mem[mdfcount].year = m.year;
//
//		mdfcount++;
//	}
//	fclose(file);
//
//
//	//Let user to choose what they want to modify
//	do {
//		printf("==========\n");
//		printf("| MODIFY |\n");
//		printf("==========\n");
//		//Scan the current member ID
//		scanf("%[^\n]", &currentMemberID);
//
//		for (i = 0; i < mdfcount; i++) {
//			//Find the member ID in the member array and print out
//			if (strcmp(currentMemberID, mem[i].memberID) == 0) {
//				printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//				printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//				printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//				break;
//			}
//		}
//
//		do {
//			printf("1. Modify Member Name\n");
//			printf("2. Modify Member Password\n");
//			printf("3. Modify Member Email\n");
//			printf("4. Modify Member Contact No.\n");
//			printf("5. Modify Member IC\n");
//			printf("6. Modify Member Gender\n");
//			printf("7. Back\n");
//			printf("Enter the choice you want to modify > ");
//			rewind(stdin);
//			scanf("%d", &mchoice);
//
//			switch (mchoice) {
//			case 1:
//				printf("Enter new member name > ");
//				rewind(stdin);
//				scanf("%[^\n]", &newmemberName);
//				printf("Are you sure you want to modify your name? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirmation);
//				if (toupper(confirmation) == 'Y') {
//					strcpy(mem[i].memberName, newmemberName);
//					printf("Modify Successfully!\n");
//					modifyCount++;
//				}
//				break;
//			case 2:
//				printf("Enter new member Password > ");
//				rewind(stdin);
//				scanf("%[^\n]", &newmemberPassword);
//				printf("Are you sure you want to modify your password? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirmation);
//				if (toupper(confirmation) == 'Y') {
//					strcpy(mem[i].memberPassword, newmemberPassword);
//					printf("Modify Successfully!\n");
//					modifyCount++;
//				}
//				break;
//			case 3:
//				printf("Enter new member email > ");
//				rewind(stdin);
//				scanf("%[^\n]", newmemberEmail);
//				printf("Are you sure you want to modify your email? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirmation);
//				if (toupper(confirmation) == 'Y') {
//					strcpy(mem[i].memberEmail, newmemberEmail);
//					printf("Modify Successfully!\n");
//					modifyCount++;
//				}
//				break;
//			case 4:
//				do {
//					printf("Enter new contact number > ");
//					rewind(stdin);
//					scanf("%[^\n]", &newmemberContactNo);
//					if (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10) {
//						printf("**Please enter the correct contact number!**\n");
//					}
//				} while (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10);
//				printf("Are you sure you want to modify your contact number? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirmation);
//				if (toupper(confirmation) == 'Y') {
//					strcpy(mem[i].memberContactNo, newmemberContactNo);
//					printf("Modify Successfully!\n");
//					modifyCount++;
//				}
//				break;
//			case 5:
//				do {
//					printf("Enter new member IC > ");
//					rewind(stdin);
//					scanf("%[^\n]", &newmemberIC);
//					if (strlen(newmemberIC) != 12) {
//						printf("Please enter the correct IC!\n");
//					}
//				} while (strlen(newmemberIC) != 12);
//				printf("Are you sure you want to modify your IC? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirmation);
//				if (toupper(confirmation) == 'Y') {
//					strcpy(mem[i].memberIC, newmemberIC);
//					printf("Modify Successfully!\n");
//					modifyCount++;
//				}
//				break;
//			case 6:
//				do {
//					printf("Enter new gender > ");
//					rewind(stdin);
//					scanf("%c", &newmemberGender);
//					if (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M') {
//						printf("**Please enter the correct gender!**\n");
//					}
//				} while (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M');
//				printf("Are you sure you want to modify your gender? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirmation);
//				if (toupper(confirmation) == 'Y') {
//					mem[i].memberGender = toupper(newmemberGender);
//					printf("Modify Successfully!\n");
//					modifyCount++;
//				}
//				break;
//			case 7:
//				break;
//			default:
//				printf("Please select the correct option.\n\n");
//				break;
//			}
//			//Loop again choice user choose is not in the range 1 to 6
//		} while (mchoice < 1 || mchoice > 7);
//		printf("Do you want to modify again? (Y = Yes) > ");
//		rewind(stdin);
//		scanf("%c", &manother);
//		//Loop again if the user want to modify again
//	} while (toupper(manother) == 'Y');
//
//	FILE* ptr;
//	//Open the file for writing
//	ptr = fopen("member.dat", "wb");
//
//	//Rewrite all the new data into the Member file
//	for (int i = 0; i < mdfcount; i++) {
//		fwrite(&mem[i], sizeof(Member), 1, ptr);
//	}
//	printf("%d record(s) modified.", modifyCount);
//
//	fclose(ptr);
//}
//
//void memberSearch() {
//	char name[51], contactNo[20], gender, ans;
//	int i = 0, msearch = 0, choice;
//	FILE* ptr;
//	ptr = fopen("member.dat", "rb");
//	if (ptr == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Copy all the data in the Member file into member array
//	while (fread(&m, sizeof(Member), 1, ptr) != 0) {
//		strcpy(mem[msearch].memberID, m.memberID);
//		strcpy(mem[msearch].memberName, m.memberName);
//		strcpy(mem[msearch].memberPassword, m.memberPassword);
//		strcpy(mem[msearch].memberEmail, m.memberEmail);
//		strcpy(mem[msearch].memberContactNo, m.memberContactNo);
//		strcpy(mem[msearch].memberIC, m.memberIC);
//		mem[msearch].memberGender = m.memberGender;
//		mem[msearch].day = m.day;
//		mem[msearch].month = m.month;
//		mem[msearch].year = m.year;
//
//		msearch++;
//	}
//	fclose(ptr);
//
//	do {
//		printf("==========\n");
//		printf("| SEARCH |\n");
//		printf("==========\n");
//		printf("1. Member Name\n");
//		printf("2. Member Contact Number\n");
//		printf("3. Member Gender\n");
//		printf("4. Back\n");
//		do {
//			printf("Select the method you want to use for searching member > ");
//			rewind(stdin);
//			scanf("%d", &choice);
//			if (!(choice >= 1 && choice <= 4)) {
//				printf("Please select again.\n");
//			}
//		} while (!(choice >= 1 && choice <= 4));
//
//		//Let user to choose how they want to search the member
//		switch (choice) {
//		case 1:
//			printf("Enter member name > ");
//			rewind(stdin);
//			scanf("%[^\n]", &name);
//
//			for (i = 0; i < msearch; i++) {
//				//Compare the name user enter with the name in the member array, if same then print out all the info about the member
//				if (strcmp(name, mem[i].memberName) == 0) {
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//					printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//					break;
//				}
//			}
//			//If the name user enter is not in the member array, an error message came out
//			if (strcmp(name, mem[i].memberName) != 0) {
//				printf("**Name not found!**\n");
//			}
//			break;
//		case 2:
//			do {
//				printf("Enter member contact number > ");
//				rewind(stdin);
//				scanf("%[^\n]", &contactNo);
//				if (strlen(contactNo) > 11 || strlen(contactNo) < 10) {
//					printf("**Please enter the correct contact number!**\n");
//				}
//			} while (strlen(contactNo) > 11 || strlen(contactNo) < 10);
//
//			for (i = 0; i < msearch; i++) {
//				//Compare the contact number with the contac number in the member array, if same then print out all the info about the member
//				if (strcmp(contactNo, mem[i].memberContactNo) == 0) {
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//					printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//					break;
//				}
//			}
//			//If the contact number user enter is not same in the member array, an error message came out
//			if (strcmp(contactNo, mem[i].memberContactNo) != 0) {
//				printf("**Contact number not found!**\n");
//			}
//			break;
//		case 3:
//			do {
//				printf("Enter member gender (M/F) > ");
//				rewind(stdin);
//				scanf("%c", &gender);
//				//Check if the user had enter the correct gender or not, male of female
//				if (toupper(gender) != 'F' && toupper(gender) != 'M') {
//					printf("Please enter the correct gender!\n");
//				}
//			} while (toupper(gender) != 'F' && toupper(gender) != 'M');
//
//			gender = toupper(gender);
//			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//			int run = 0;
//			//Print out all the info about the member if the gender is same with the member array
//			for (i = 0; i < msearch; i++) {
//				if (gender == mem[i].memberGender) {
//					run++;
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//				}
//			}
//			if (run == 0) {
//				printf("**Gender not found!**\n");
//			}
//			break;
//		default:
//			printf("**Please select again.**\n");
//			break;
//		}
//		printf("Do you want to search again? (Y = yes) > ");
//		rewind(stdin);
//		scanf("%c", &ans);
//	} while (toupper(ans) == 'Y');
//}
//
//
//void memberDelete() {
//	char memdlt[20], confirm, ans;
//	int dlt = 0, i = 0, dltcount = 0, n = 0, found;
//	Member memdelete[20];
//	FILE* file;
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Copy all the data in to Member file into member array
//	while (fread(&m, sizeof(Member), 1, file) != 0) {
//		strcpy(mem[dlt].memberID, m.memberID);
//		strcpy(mem[dlt].memberName, m.memberName);
//		strcpy(mem[dlt].memberPassword, m.memberPassword);
//		strcpy(mem[dlt].memberEmail, m.memberEmail);
//		strcpy(mem[dlt].memberContactNo, m.memberContactNo);
//		strcpy(mem[dlt].memberIC, m.memberIC);
//		mem[dlt].memberGender = m.memberGender;
//		mem[dlt].day = m.day;
//		mem[dlt].month = m.month;
//		mem[dlt].year = m.year;
//
//		dlt++;
//	}
//	fclose(file);
//
//	do {
//		printf("==========\n");
//		printf("| DELETE |\n");
//		printf("==========\n");
//		printf("Enter the member ID to delete account > ");
//		rewind(stdin);
//		scanf("%[^\n]", &memdlt);
//
//		found = 0;
//		for (i = 0; i < dlt; i++) {
//			//Compare the member ID with the member array
//			if (strcmp(memdlt, mem[i].memberID) == 0) {
//				found = 1;
//				printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//				printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//				printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n",
//					mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//
//				printf("Are you sure you want to delete this account? (Y = Yes) > ");
//				rewind(stdin);
//				scanf("%c", &confirm);
//				if (toupper(confirm) == 'Y') {
//					for (i = 0; i < dlt; i++) {
//						//If the member ID not same with the array, copy the whole member info into another array
//						if (strcmp(memdlt, mem[i].memberID) != 0) {
//							strcpy(memdelete[n].memberID, mem[i].memberID);
//							strcpy(memdelete[n].memberName, mem[i].memberName);
//							strcpy(memdelete[n].memberPassword, mem[i].memberPassword);
//							strcpy(memdelete[n].memberEmail, mem[i].memberEmail);
//							strcpy(memdelete[n].memberContactNo, mem[i].memberContactNo);
//							strcpy(memdelete[n].memberIC, mem[i].memberIC);
//							memdelete[n].memberGender = mem[i].memberGender;
//							memdelete[n].day = mem[i].day;
//							memdelete[n].month = mem[i].month;
//							memdelete[n].year = mem[i].year;
//							n++;
//						}
//					}
//					dltcount++;
//				}
//			}
//		}
//		if (found == 0) {
//			printf("**Member record not found.**\n\n");
//		}
//
//		printf("Do you want to delete another account? (Y = Yes) > ");
//		rewind(stdin);
//		scanf("%c", &ans);
//	} while (toupper(ans) == 'Y');
//
//	if (dltcount > 0) {
//		FILE* ptr;
//		ptr = fopen("member.dat", "wb");
//		for (int n = 0; n < (dlt - dltcount); n++) {
//			//Write all the not remain data into the Member file
//			fwrite(&memdelete[n], sizeof(Member), 1, ptr);
//		}
//		fclose(ptr);
//	}
//
//	printf("%d record deleted.\n", dltcount);
//}
//
//void memberReport() {
//	char writeMonth[30], choose;
//	int rpcount = 0, i = 0, choice, memberMonth, memberYear, findDate, memberRYear;
//	int cDay, cMonth, cYear, cHour, cMinute, cSecond;
//	FILE* file;
//	file = fopen("member.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file.");
//		exit(-1);
//	}
//
//	//Copy all the data in to Member file into member array
//	while (fread(&m, sizeof(Member), 1, file) != 0) {
//		strcpy(mem[rpcount].memberID, m.memberID);
//		strcpy(mem[rpcount].memberName, m.memberName);
//		strcpy(mem[rpcount].memberPassword, m.memberPassword);
//		strcpy(mem[rpcount].memberEmail, m.memberEmail);
//		strcpy(mem[rpcount].memberContactNo, m.memberContactNo);
//		strcpy(mem[rpcount].memberIC, m.memberIC);
//		mem[rpcount].memberGender = m.memberGender;
//		mem[rpcount].day = m.day;
//		mem[rpcount].month = m.month;
//		mem[rpcount].year = m.year;
//
//		rpcount++;
//	}
//	fclose(file);
//
//	do {
//		printf("=====================\n");
//		printf("| MEMBERSHIP REPORT |\n");
//		printf("================================\n");
//		printf("| 1. New Member Monthly Report |\n");
//		printf("| 2. New Member Yearly Report  |\n");
//		printf("| 3. Back                      |\n");
//		printf("================================\n");
//		printf("Please enter your choice > ");
//		rewind(stdin);
//		scanf("%d", &choice);
//
//		//Let user to choose the type of report
//		switch (choice) {
//		case 1:
//			do {
//				printf("Please enter the year (2000-2023) > ");
//				rewind(stdin);
//				scanf("%d", &memberYear);
//				if (memberYear > 2023 || memberYear < 2000) {
//					printf("**Invalid year!**\n");
//				}
//			} while (memberYear > 2023 || memberYear < 2000);
//
//			do {
//				printf("Please enter the month (1-12) > ");
//				rewind(stdin);
//				scanf("%d", &memberMonth);
//				if (memberMonth > 12 || memberMonth < 1) {
//					printf("**Invalid month!**\n");
//				}
//			} while (memberMonth > 12 || memberMonth < 1);
//
//			//Change the month in number into a word
//			switch (memberMonth) {
//			case 1:
//				strcpy(writeMonth, "JANUARY");
//				break;
//			case 2:
//				strcpy(writeMonth, "FEBRUARY");
//				break;
//			case 3:
//				strcpy(writeMonth, "MARCH");
//				break;
//			case 4:
//				strcpy(writeMonth, "APRIL");
//				break;
//			case 5:
//				strcpy(writeMonth, "MAY");
//				break;
//			case 6:
//				strcpy(writeMonth, "JUNE");
//				break;
//			case 7:
//				strcpy(writeMonth, "JULY");
//				break;
//			case 8:
//				strcpy(writeMonth, "AUGUST");
//				break;
//			case 9:
//				strcpy(writeMonth, "SEPTEMBER");
//				break;
//			case 10:
//				strcpy(writeMonth, "OCTOBER");
//				break;
//			case 11:
//				strcpy(writeMonth, "NOVEMBER");
//				break;
//			case 12:
//				strcpy(writeMonth, "DECEMBER");
//				break;
//			default:
//				strcpy(writeMonth, "Error");
//				break;
//			}
//			findDate = 0;
//
//			GetLocalTime(&time);
//			cDay = time.wDay;
//			cMonth = time.wMonth;
//			cYear = time.wYear;
//			cHour = time.wHour;
//			cMinute = time.wMinute;
//			cSecond = time.wSecond;
//
//			printf("=============================\n");
//			printf("| NEW MEMBER MONTHLY REPORT |\n");
//			printf("=============================\n");
//			printf("List of New Member Joined in %-9s %d\n", writeMonth, memberYear);
//			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//			printf("Date: %02d-%02d-%d %122s: %02d:%02d:%02d\n\n", cDay, cMonth, cYear, "Time", cHour, cMinute, cSecond);
//			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//			//Print all the member that join in the month and year user entered
//			for (i = 0; i < rpcount; i++) {
//				if (memberMonth == mem[i].month && memberYear == mem[i].year) {
//					findDate = 1;
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//				}
//			}
//			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//			if (findDate != 1) {
//				printf("No Member Join In %s %d\n", writeMonth, memberYear);
//			}
//			break;
//
//		case 2:
//			do {
//				printf("Please enter the year (2000-2023) > ");
//				rewind(stdin);
//				scanf("%d", &memberRYear);
//				if (memberRYear > 2024 || memberRYear < 2000) {
//					printf("**Invalid year!**\n");
//				}
//			} while (memberRYear > 2024 || memberRYear < 2000);
//			findDate = 0;
//
//			GetLocalTime(&time);
//			cDay = time.wDay;
//			cMonth = time.wMonth;
//			cYear = time.wYear;
//			cHour = time.wHour;
//			cMinute = time.wMinute;
//			cSecond = time.wSecond;
//
//			printf("============================\n");
//			printf("| NEW MEMBER YEARLY REPORT |\n");
//			printf("============================\n");
//			printf("List of New Member Joined in Year %d\n", memberRYear);
//			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//			printf("Date: %02d-%02d-%d %122s: %02d:%02d:%02d\n\n", cDay, cMonth, cYear, "Time", cHour, cMinute, cSecond);
//			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
//			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//			for (i = 0; i < rpcount; i++) {
//				if (memberRYear == mem[i].year) {
//					findDate = 1;
//					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].day, mem[i].month, mem[i].year);
//				}
//			}
//			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
//			if (findDate != 1) {
//				printf("No Member Join In Year %d\n", memberRYear);
//			}
//			break;
//
//		case 3:
//			return memberLoginMenu();
//			break;
//
//		default:
//			printf("**Please select the correct option.**\n");
//			return memberReport();
//			break;
//		}
//
//		printf("Do you want to view another report (Y = Yes) > ");
//		rewind(stdin);
//		scanf("%c", &choose);
//	} while (toupper(choose) == 'Y');
//}