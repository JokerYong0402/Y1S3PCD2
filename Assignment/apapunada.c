#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#pragma warning (disable: 4996)

//function declaration
//member
int memberLogin();
void memberCreate();
void memberDisplay(char type[10]);
void memberModify(char type[10]);
void memberSearch();
void memberDelete();
void memberReport();

//staff
int staffLogin();
void staffCreate();
void staffDisplay(char type[10]);
void staffModify(char type[10]);
void staffSearch();
void staffDelete();
void staffReport(char type[10]);
void staffRestore();
void staffHeader(int type);

//sales
void salesOrder(char type[10]);
void salesSearch(char type[10]);
void salesModify();
void salesDisplay();
void salesDelete();
void salesReport();
void salesRestore();
void changeLog(char changes[100], char id[10]);
void displayLog();
void salesHeader();
void salesFooter(int c);
void reportHeader(char type[10], int year, int month, int day);
int stockValidation(char itemCode[5]);

//stock
void addStock();
void searchStock();
void modifyStock(char staffId[10]);
void displayStock();
void reportStock(char staffId[10]);
void deleteStock();
void modifyHistory();
void deleteHistory();
void reorderStock(char itemCode[10], int qty);
int valid();
int valid1();
char valid2();
int valid3();
int valid4();
int valid5();

//structure and variable
char loginStaffPosition[20];
char current_memberId[10], current_staffId[10];

//date 
struct Date {
	int day, month, year;
};

//member
typedef struct Member {
	char memberID[20], memberName[51], memberGender;
	char memberEmail[51], memberPassword[51], memberIC[20], memberContactNo[20];
	struct Date date; //nested structure
}Member;

Member m;
Member mem[20];

//staff
typedef struct Staff {
	char staffid[10], name[30], gender, email[30], password[30], phnum[20], ic[20], position[20];
	struct Date date; //nested structure
}staffs;

staffs staff;
staffs staffarr[100];

//sales
typedef struct Sales {
	char orderId[5], itemCode[10];
	int qty;
	double price;
	char memberId[10], staffId[10];
	double commission;
	struct Date date; //nested structure
	char time[11];
	char status[10];
} Sales;

Sales record;

//stock
typedef struct Quantity {
	int qtyInStock, minLvl, reorderQty;
} Quantity;

struct Stock {
	char itemCode[5], itemName[30], itemCategory[20];
	Quantity quantity;
	double itemPrice;
} records;

struct Stock item;
struct Stock store[100];
char v;

//main
void main() {
	int roleChoice;
	int memberChoice;
	int staffChoice, staffProfile, staffMember, staffStaff, staffSales, staffStock;
	int mLogin, mLogin2, sLogin;
	char memberid[20];

	do {
		//logo
		printf("                       ______________                             \n");
		printf("        ----          |              |         ----               \n");
		printf("       /    \\         |    ------    |        /    \\            \n");
		printf("      /      \\        |   |      |   |       /      \\           \n");
		printf("     /   /\\   \\       |    ------    |      /   /\\   \\        \n");
		printf("    /   /  \\   \\      |    __________|     /   /  \\   \\       \n");
		printf("   /   /____\\   \\     |   |               /   /____\\   \\      \n");
		printf("  /    ______    \\    |   |              /    ______    \\       \n");
		printf(" /   /        \\   \\   |   |             /   /       \\    \\    \n");
		printf("/___/          \\___\\  |___|            /___/         \\____\\   \n");
		printf(" ______________    ____         ____    ______       ____        \n");
		printf("|              |  |    |       |    |  |      \\     |    |       \n");
		printf("|    ------    |  |    |       |    |  |       \\    |    |       \n");
		printf("|   |      |   |  |    |       |    |  |        \\   |    |       \n");
		printf("|    ------    |  |    |       |    |  |         \\  |    |       \n");
		printf("|    __________|  |    |       |    |  |    |\\    \\ |    |      \n");
		printf("|   |             |    |       |    |  |    | \\    \\|    |      \n");
		printf("|   |             |    |_______|    |  |    |  \\         |       \n");
		printf("|   |             |                 |  |    |   \\        |       \n");
		printf("|___|             |_________________|  |____|    \\_______|       \n");
		printf("                       _____________                              \n");
		printf("        ----          |             \\          ----              \n");
		printf("       /    \\         |    ------    \\        /    \\           \n");
		printf("      /      \\        |   |      |   |       /      \\           \n");
		printf("     /   /\\   \\       |   |      |   |      /   /\\   \\        \n");
		printf("    /   /  \\   \\      |   |      |   |     /   /  \\   \\       \n");
		printf("   /   /____\\   \\     |   |      |   |    /   /____\\   \\      \n");
		printf("  /    ______    \\    |   |      |   |   /    ______    \\       \n");
		printf(" /   /        \\   \\   |    ------    /  /   /       \\    \\    \n");
		printf("/___/          \\___\\  |_____________/  /___/         \\____\\   \n");
		printf("\n                   Welcome to 'ApaPunAda'\n\n");
		printf("--------------------\n");
		printf("     Login Page\n");
		printf("====================\n");
		printf("| 1. Member        |\n");
		printf("| 2. Staff         |\n");
		printf("====================\n");
		printf("Choice > ");
		scanf("%d", &roleChoice);
		printf("\n");

		switch (roleChoice) {
		case 1: //login member
			do {
				mLogin = memberLogin();
				switch(mLogin) {
				case 1:
					system("cls");
					printf("=================\n");
					printf("| MEMBER PORTAL |\n");
					printf("=================\n\n");
					do {
						printf("             Menu\n");
						printf("==============================\n");
						printf("| 1. Profile                 |\n");
						printf("| 2. Edit Profile            |\n");
						printf("| 3. Stock Availability      |\n");
						printf("| 4. Create order            |\n");
						printf("| 5. Display ordered sales   |\n");
						printf("| 6. Log Out                 |\n");
						printf("==============================\n");
						printf("Please enter your choice > ");
						rewind(stdin);
						scanf("%d", &memberChoice);
						//Scan the option that user choose and bring them to there

						switch (memberChoice) {
						case 1:
							system("cls");
							printf("================\n");
							printf("| ACCOUNT INFO |\n");
							printf("================\n");
							memberDisplay("self");
							break;
						case 2:
							system("cls");
							printf("================================\n");
							printf("| ACCOUNT DETAILS MODIFICATION |\n");
							printf("================================\n");
							memberModify("self");
							break;
						case 3:
							system("cls");
							printf("======================\n");
							printf("| STOCK AVAILABILITY |\n");
							printf("======================\n");
							displayStock();
							break;
						case 4:
							system("cls");
							printf("======================\n");
							printf("| CREATE SALES ORDER |\n");
							printf("======================\n");
							salesOrder("member"); // for member input upline 
							break;
						case 5:
							system("cls");
							printf("=================\n");
							printf("| ORDERED SALES |\n");
							printf("=================\n\n");
							salesSearch("self");
							break;
						case 6:
							system("cls");
							break;
						default:
							system("cls");
							printf("Please select the correct option.\n");
							break;
						}
					} while (memberChoice != 6);
					break;
				case 2:
					system("cls");
					printf("==================\n");
					printf("| MEMBER SIGN UP |\n");
					printf("==================\n");
					memberCreate();
					printf("Your Member ID : '%s'\n\n", m.memberID);
					printf("Repeat member ID to continue.\n");
					do {
						printf("Member ID : ");
						scanf("%s", memberid);
						printf("\n");
						if (strcmp(m.memberID, memberid) != 0)
							printf("Please refer to the member ID provided.\n");
					} while (strcmp(m.memberID, memberid) != 0);
					system("cls");
					break;
				}
			} while (mLogin == 0);
			break;
		case 2: //login staff
			do {
				sLogin = staffLogin();
				//if login successful and position is manager
				if (sLogin == 1 && (strcmp(loginStaffPosition, "Manager") == 0)) {
					system("cls");
					printf("================\n");
					printf("| STAFF PORTAL |\n");
					printf("================\n\n");
					do {
						printf("        Menu\n");
						printf("====================\n");
						printf("| 1. Profile       |\n");
						printf("| 2. Staff         |\n");
						printf("| 3. Member        |\n");
						printf("| 4. Sales         |\n");
						printf("| 5. Stock         |\n");
						printf("| 6. Log Out       |\n");
						printf("====================\n");
						printf("Choice > ");
						scanf("%d", &staffChoice);

						switch (staffChoice) {
						case 1:
							system("cls");
							printf("===========\n");
							printf("| PROFILE |\n");
							printf("===========\n\n");
							do {
								printf("           Profile Menu\n");
								printf("===================================\n");
								printf("| 1. Display profile              |\n");
								printf("| 2. Modify profile               |\n");
								printf("| 3. Personal commission report   |\n");
								printf("| 4. Back                         |\n");
								printf("===================================\n");
								printf("Choice > ");
								scanf("%d", &staffProfile);

								switch (staffProfile) {
								case 1:
									system("cls");
									printf("================\n");
									printf("| ACCOUNT INFO |\n");
									printf("================\n");
									staffDisplay("self");
									break;
								case 2:
									system("cls");
									printf("================================\n");
									printf("| ACCOUNT DETAILS MODIFICATION |\n");
									printf("================================\n");
									staffModify("self");
									break;
								case 3:
									system("cls");
									printf("==============================\n");
									printf("| PERSONAL COMMISSION REPORT |\n");
									printf("==============================\n");
									staffReport("self");
									break;
								case 4:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffProfile != 4);
							break;
						case 2:
							system("cls");
							printf("=========\n");
							printf("| STAFF |\n");
							printf("=========\n\n");
							do {
								printf("          Staff Menu\n");
								printf("===============================\n");
								printf("| 1. Create staff             |\n");
								printf("| 2. Display staff            |\n");
								printf("| 3. Search staff             |\n");
								printf("| 4. Modify staff             |\n");
								printf("| 5. Delete staff             |\n");
								printf("| 6. Restore staff            |\n");
								printf("| 7. Generate staff report    |\n");
								printf("| 8. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffStaff);

								switch (staffStaff) {
								case 1:
									system("cls");
									printf("==================\n");
									printf("| STAFF CREATION |\n");
									printf("==================\n");
									staffCreate();
									break;
								case 2:
									system("cls");
									printf("=====================\n");
									printf("| STAFF INFORMATION |\n");
									printf("=====================\n");
									staffDisplay("manage");
									break;
								case 3:
									system("cls");
									printf("================\n");
									printf("| STAFF SEARCH |\n");
									printf("================\n");
									staffSearch();
									break;
								case 4:
									system("cls");
									printf("==============================\n");
									printf("| STAFF DETAILS MODIFICATION |\n");
									printf("==============================\n");
									staffModify("manage");
									break;
								case 5:
									system("cls");
									printf("==================\n");
									printf("| STAFF DELETION |\n");
									printf("==================\n");
									staffDelete();
									break;
								case 6:
									system("cls");
									printf("=====================\n");
									printf("| STAFF RESTORATION |\n");
									printf("=====================\n");
									staffRestore();
									break;
								case 7:
									system("cls");
									printf("================\n");
									printf("| STAFF REPORT |\n");
									printf("================\n");
									staffReport("manage");
									break;
								case 8:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffStaff != 8);
							break;
						case 3:
							system("cls");
							printf("==========\n");
							printf("| MEMBER |\n");
							printf("==========\n\n");
							do {
								printf("          Member Menu\n");
								printf("===============================\n");
								printf("| 1. Create member            |\n");
								printf("| 2. Display member           |\n");
								printf("| 3. Search member            |\n");
								printf("| 4. Modify member            |\n");
								printf("| 5. Delete member            |\n");
								printf("| 6. Generate member report   |\n");
								printf("| 7. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffMember);

								switch (staffMember) {
								case 1:
									system("cls");
									printf("===================\n");
									printf("| MEMBER CREATION |\n");
									printf("===================\n");
									memberCreate();
									break;
								case 2:
									system("cls");
									printf("=====================\n");
									printf("| MEMBER INFOMATION |\n");
									printf("=====================\n");
									memberDisplay("manage");
									break;
								case 3:
									system("cls");
									printf("=================\n");
									printf("| MEMBER SEARCH |\n");
									printf("=================\n");
									memberSearch();
									break;
								case 4:
									system("cls");
									printf("===============================\n");
									printf("| MEMBER DETAILS MODIFICATION |\n");
									printf("===============================\n");
									memberModify("manage");
									break;
								case 5:
									system("cls");
									printf("===================\n");
									printf("| MEMBER DELETION |\n");
									printf("===================\n");
									memberDelete();
									break;
								case 6:
									system("cls");
									printf("=================\n");
									printf("| MEMBER REPORT |\n");
									printf("=================\n");
									memberReport();
									break;
								case 7:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffMember != 7);
							break;
						case 4:
							system("cls");
							printf("=========\n");
							printf("| SALES |\n");
							printf("=========\n\n");
							do {
								printf("          Sales Menu\n");
								printf("===============================\n");
								printf("| 1. Create sales             |\n");
								printf("| 2. Display sales            |\n");
								printf("| 3. Search sales             |\n");
								printf("| 4. Modify sales             |\n");
								printf("| 5. Delete sales             |\n");
								printf("| 6. Restore sales            |\n");
								printf("| 7. Generate sales report    |\n");
								printf("| 8. Display Log              |\n");
								printf("| 9. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffSales);

								switch (staffSales) {
								case 1:
									system("cls");
									printf("========================\n");
									printf("| SALES ORDER CREATION |\n");
									printf("========================\n");
									salesOrder("staff");
									break;
								case 2:
									system("cls");
									printf("===========================\n");
									printf("| SALES ORDER INFORMATION |\n");
									printf("===========================\n");
									salesDisplay();
									break;
								case 3:
									system("cls");
									printf("======================\n");
									printf("| SALES ORDER SEARCH |\n");
									printf("======================\n");
									salesSearch("manage");
									break;
								case 4:
									system("cls");
									printf("====================================\n");
									printf("| SALES ORDER DETAILS MODIFICATION |\n");
									printf("====================================\n");
									salesModify();
									break;
								case 5:
									system("cls");
									printf("========================\n");
									printf("| SALES ORDER DELETION |\n");
									printf("========================\n");
									salesDelete();
									break;
								case 6:
									system("cls");
									printf("===========================\n");
									printf("| SALES ORDER RESTORATION |\n");
									printf("===========================\n");
									salesRestore();
									break;
								case 7:
									system("cls");
									printf("======================\n");
									printf("| SALES ORDER REPORT |\n");
									printf("======================\n");
									salesReport();
									break;
								case 8:
									system("cls");
									printf("==========================\n");
									printf("| SALES ORDER CHANGE LOG |\n");
									printf("==========================\n");
									displayLog();
									break;
								case 9:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffSales != 9);
							break;
						case 5:
							system("cls");
							printf("=========\n");
							printf("| STOCK |\n");
							printf("=========\n\n");
							do {
								printf("          Stock Menu\n");
								printf("===============================\n");
								printf("| 1. Create stock             |\n");
								printf("| 2. Display stock            |\n");
								printf("| 3. Search stock             |\n");
								printf("| 4. Modify stock             |\n");
								printf("| 5. Delete stock             |\n");
								printf("| 6. Generate stock report    |\n");
								printf("| 7. Modify stock history     |\n");
								printf("| 8. Delete stock history     |\n");
								printf("| 9. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffStock);

								switch (staffStock) {
								case 1:
									system("cls");
									printf("==================\n");
									printf("| STOCK CREATION |\n");
									printf("==================\n");
									addStock();
									break;
								case 2:
									system("cls");
									printf("=====================\n");
									printf("| STOCK INFORMATION |\n");
									printf("=====================\n");
									displayStock();
									break;
								case 3:
									system("cls");
									printf("================\n");
									printf("| STOCK SEARCH |\n");
									printf("================\n");
									searchStock();
									break;
								case 4:
									system("cls");
									printf("==============================\n");
									printf("| STOCK DETAILS MODIFICATION |\n");
									printf("==============================\n");
									modifyStock(current_staffId);
									break;
								case 5:
									system("cls");
									printf("==================\n");
									printf("| STOCK DELETION |\n");
									printf("==================\n");
									deleteStock();
									break;
								case 6:
									system("cls");
									printf("================\n");
									printf("| STOCK REPORT |\n");
									printf("================\n");
									reportStock(current_staffId);
									break;
								case 7:
									system("cls");
									printf("========================\n");
									printf("| STOCK MODIFY HISTORY |\n");
									printf("========================\n");
									modifyHistory();
									break;
								case 8:
									system("cls");
									printf("==========================\n");
									printf("| STOCK DELETION HISTORY |\n");
									printf("==========================\n");
									deleteHistory();
									break;
								case 9:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffStock != 9);
							break;
						case 6:
							system("cls");
							break;
						default:
							system("cls");
							printf("**Invalid input. Please select again.**\n\n");
							break;
						}
					} while (staffChoice != 6);
				}
				//if login successful (staff and intern)
				else if (sLogin == 1) {
					system("cls");
					printf("==================\n");
					printf("| MANAGER PORTAL |\n");
					printf("==================\n\n");
					do {
						printf("       Menu\n");
						printf("====================\n");
						printf("| 1. Profile       |\n");
						printf("| 2. Member        |\n");
						printf("| 3. Sales         |\n");
						printf("| 4. Stock         |\n");
						printf("| 5. Log Out       |\n");
						printf("====================\n");
						printf("Choice > ");
						scanf("%d", &staffChoice);

						switch (staffChoice) {
						case 1:
							system("cls");
							printf("===========\n");
							printf("| PROFILE |\n");
							printf("===========\n\n");
							do {
								printf("           Profile Menu\n");
								printf("===================================\n");
								printf("| 1. Display profile              |\n");
								printf("| 2. Modify profile               |\n");
								printf("| 3. Personal commission report   |\n");
								printf("| 4. Back                         |\n");
								printf("===================================\n");
								printf("Choice > ");
								scanf("%d", &staffProfile);

								switch (staffProfile) {
								case 1:
									system("cls");
									printf("================\n");
									printf("| ACCOUNT INFO |\n");
									printf("================\n");
									staffDisplay("self");
									break;
								case 2:
									system("cls");
									printf("================================\n");
									printf("| ACCOUNT DETAILS MODIFICATION |\n");
									printf("================================\n");
									staffModify("self");
									break;
								case 3:
									system("cls");
									printf("==============================\n");
									printf("| PERSONAL COMMISSION REPORT |\n");
									printf("==============================\n");
									staffReport("self");
									break;
								case 4:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffProfile != 4);
							break;
						case 2:
							system("cls");
							printf("==========\n");
							printf("| MEMBER |\n");
							printf("==========\n\n");
							do {
								printf("          Member Menu\n");
								printf("===============================\n");
								printf("| 1. Create member            |\n");
								printf("| 2. Display member           |\n");
								printf("| 3. Search member            |\n");
								printf("| 4. Modify member            |\n");
								printf("| 5. Delete member            |\n");
								printf("| 6. Generate member report   |\n");
								printf("| 7. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffMember);

								switch (staffMember) {
								case 1:
									system("cls");
									printf("===================\n");
									printf("| MEMBER CREATION |\n");
									printf("===================\n");
									memberCreate();
									break;
								case 2:
									system("cls");
									printf("=====================\n");
									printf("| MEMBER INFOMATION |\n");
									printf("=====================\n");
									memberDisplay("manage");
									break;
								case 3:
									system("cls");
									printf("=================\n");
									printf("| MEMBER SEARCH |\n");
									printf("=================\n");
									memberSearch();
									break;
								case 4:
									system("cls");
									printf("===============================\n");
									printf("| MEMBER DETAILS MODIFICATION |\n");
									printf("===============================\n");
									memberModify("manage");
									break;
								case 5:
									system("cls");
									printf("===================\n");
									printf("| MEMBER DELETION |\n");
									printf("===================\n");
									memberDelete();
									break;
								case 6:
									system("cls");
									printf("=================\n");
									printf("| MEMBER REPORT |\n");
									printf("=================\n");
									memberReport();
									break;
								case 7:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffMember != 7);
							break;
						case 3:
							system("cls");
							printf("=========\n");
							printf("| SALES |\n");
							printf("=========\n\n");
							do {
								printf("          Sales Menu\n");
								printf("===============================\n");
								printf("| 1. Create sales             |\n");
								printf("| 2. Display sales            |\n");
								printf("| 3. Search sales             |\n");
								printf("| 4. Modify sales             |\n");
								printf("| 5. Delete sales             |\n");
								printf("| 6. Restore sales            |\n");
								printf("| 7. Generate sales report    |\n");
								printf("| 8. Display Log              |\n");
								printf("| 9. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffSales);

								switch (staffSales) {
								case 1:
									system("cls");
									printf("========================\n");
									printf("| SALES ORDER CREATION |\n");
									printf("========================\n");
									salesOrder("staff");
									break;
								case 2:
									system("cls");
									printf("===========================\n");
									printf("| SALES ORDER INFORMATION |\n");
									printf("===========================\n");
									salesDisplay();
									break;
								case 3:
									system("cls");
									printf("======================\n");
									printf("| SALES ORDER SEARCH |\n");
									printf("======================\n");
									salesSearch("manage");
									break;
								case 4:
									system("cls");
									printf("====================================\n");
									printf("| SALES ORDER DETAILS MODIFICATION |\n");
									printf("====================================\n");
									salesModify();
									break;
								case 5:
									system("cls");
									printf("========================\n");
									printf("| SALES ORDER DELETION |\n");
									printf("========================\n");
									salesDelete();
									break;
								case 6:
									system("cls");
									printf("===========================\n");
									printf("| SALES ORDER RESTORATION |\n");
									printf("===========================\n");
									salesRestore();
									break;
								case 7:
									system("cls");
									printf("======================\n");
									printf("| SALES ORDER REPORT |\n");
									printf("======================\n");
									salesReport();
									break;
								case 8:
									system("cls");
									printf("==========================\n");
									printf("| SALES ORDER CHANGE LOG |\n");
									printf("==========================\n");
									displayLog();
									break;
								case 9:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffSales != 9);
							break;
						case 4:
							system("cls");
							printf("=========\n");
							printf("| STOCK |\n");
							printf("=========\n\n");
							do {
								printf("          Stock Menu\n");
								printf("===============================\n");
								printf("| 1. Create stock             |\n");
								printf("| 2. Display stock            |\n");
								printf("| 3. Search stock             |\n");
								printf("| 4. Modify stock             |\n");
								printf("| 5. Delete stock             |\n");
								printf("| 6. Generate stock report    |\n");
								printf("| 7. Modify stock history     |\n");
								printf("| 8. Delete stock history     |\n");
								printf("| 9. Back                     |\n");
								printf("===============================\n");
								printf("Choice > ");
								scanf("%d", &staffStock);

								switch (staffStock) {
								case 1:
									system("cls");
									printf("==================\n");
									printf("| STOCK CREATION |\n");
									printf("==================\n");
									addStock();
									break;
								case 2:
									system("cls");
									printf("=====================\n");
									printf("| STOCK INFORMATION |\n");
									printf("=====================\n");
									displayStock();
									break;
								case 3:
									system("cls");
									printf("================\n");
									printf("| STOCK SEARCH |\n");
									printf("================\n");
									searchStock();
									break;
								case 4:
									system("cls");
									printf("==============================\n");
									printf("| STOCK DETAILS MODIFICATION |\n");
									printf("==============================\n");
									modifyStock(current_staffId);
									break;
								case 5:
									system("cls");
									printf("==================\n");
									printf("| STOCK DELETION |\n");
									printf("==================\n");
									deleteStock();
									break;
								case 6:
									system("cls");
									printf("================\n");
									printf("| STOCK REPORT |\n");
									printf("================\n");
									reportStock(current_staffId);
									break;
								case 7:
									system("cls");
									printf("========================\n");
									printf("| STOCK MODIFY HISTORY |\n");
									printf("========================\n");
									modifyHistory();
									break;
								case 8:
									system("cls");
									printf("==========================\n");
									printf("| STOCK DELETION HISTORY |\n");
									printf("==========================\n");
									deleteHistory();
									break;
								case 9:
									system("cls");
									break;
								default:
									system("cls");
									printf("**Invalid input. Please select again.**\n\n");
									break;
								}
							} while (staffStock != 9);
							break;
						case 5:
							system("cls");
							break;
						default:
							system("cls");
							printf("**Invalid input. Please select again.**\n\n");
							break;
						}
					} while (staffChoice != 5);
				}
			} while (sLogin == 0);
			break;
		default:
			system("cls");
			printf("**Invalid input. Please select again.**\n\n");
			break;
		}
	} while (TRUE);
}

//Member Information Module
//By: Yoong Hong Sheng
int memberLogin() {
	FILE* file;
	int choice;
	char loginpassword[30];
	int found = 0;

	file = fopen("member.dat", "rb");
	if (file == NULL) {
		printf("Error while opening the file\n");
		exit(-1);
	}

	printf("  Member portal  \n");
	printf("=================\n");
	printf("| 1 - Log in    |\n");
	printf("| 2 - Sign Up   |\n");
	printf("| 3 - Back      |\n");
	printf("=================\n");
	printf("Enter your choice > ");
	rewind(stdin);
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		printf("Enter member id : ");
		rewind(stdin);
		scanf("%[^\n]", &current_memberId);

		rewind(file);
		while (fread(&m, sizeof(Member), 1, file) != 0) {
			if (strcmp(m.memberID, current_memberId) == 0) {
				found = 1;
				printf("Enter password : ");
				rewind(stdin);
				scanf("%[^\n]", loginpassword);

				if (strcmp(m.memberPassword, loginpassword) == 0) {
					printf("Login Successful\n\n");
					fclose(file);
					return 1;
				}
				else {
					printf("**Incorrect password**\n\n");
					fclose(file);
					return 0;
				}
			}
		}
		if (found != 1) {
			printf("**Incorrect member id**\n\n");
			return 0;
		}
		break;
	case 2:
		return 2;
	case 3:
		break;
	default:
		printf("**Enter valid input!**\n\n");
		return 0;
		break;
	}
}

void memberCreate() {
	char ans;
	char confirmation;
	int i = 0, mcreate = 0, z = 0, n = 0, id;
	Member arr[50];

	FILE* file, *rfile;

	//Open the member file for appendding
	file = fopen("member.dat", "ab");
	if (file == NULL) {
		printf("Error while opening the file.");
		exit(-1);
	}

	//Read the member file for checking
	rfile = fopen("member.dat", "rb");
	if (rfile == NULL) {
		printf("Error while opening the file.");
		exit(-1);
	}

	//Read the member file
	while (fread(&m, sizeof(Member), 1, rfile) != 0) {
		arr[n] = m;
		n++;
	}
	fclose(rfile);
	
	sscanf(arr[n-1].memberID, "M%d", &id);
	sprintf(m.memberID, "M%03d", id + 1);

	printf("Enter member name > ");
	rewind(stdin);
	scanf("%[^\n]", &m.memberName);
	do {
		printf("Enter member gender (M/F) > ");
		rewind(stdin);
		scanf("%c", &m.memberGender);

		//Check if the gender user enter is male or female
		if (toupper(m.memberGender) != 'F' && toupper(m.memberGender) != 'M') {
			printf("**Please enter the correct gender!**\n");
		}
		//Loop again if user enter the wrong data
	} while (toupper(m.memberGender) != 'F' && toupper(m.memberGender) != 'M');
	do {
		printf("Enter member IC (without '-') > ");
		rewind(stdin);
		scanf("%[^\n]", &m.memberIC);

		//Check if the format of the IC is correct or not
		if (strlen(m.memberIC) != 12) {
			printf("**Please enter the correct IC!**\n");
		}
		//Loop again if the user enter the wrong IC format
	} while (strlen(m.memberIC) != 12);
	printf("Enter member email > ");
	rewind(stdin);
	scanf("%[^\n]", &m.memberEmail);
	printf("Enter member password > ");
	rewind(stdin);
	scanf("%[^\n]", &m.memberPassword);
	do {
		printf("Enter member contact number > ");
		rewind(stdin);
		scanf("%[^\n]", &m.memberContactNo);

		//Check if the contact number range is 10 or 11
		if (strlen(m.memberContactNo) > 11 || strlen(m.memberContactNo) < 10) {
			printf("**Please enter the correct contact number!**\n");
		}
		//Loop again if the contact number range is wrong
	} while (strlen(m.memberContactNo) > 11 || strlen(m.memberContactNo) < 10);
	printf("Are your sure you want to add this new member into system? (Y = Yes) > ");
	rewind(stdin);
	scanf("%c", &confirmation);

	//Write all the data into the Member file
	if (toupper(confirmation) == 'Y') {
		SYSTEMTIME time;
		GetLocalTime(&time);
		m.date.day = time.wDay;
		m.date.month = time.wMonth;
		m.date.year = time.wYear;
		m.memberGender = toupper(m.memberGender);
		fwrite(&m, sizeof(Member), 1, file);
		printf("[ Member '%s' had added successfully on %d/%d/%d! ]\n\n", m.memberID, m.date.day, m.date.month, m.date.year);
	}
	else {
		printf("Not saved!\n");
	}

	//Close the file
	fclose(file);
}

void memberDisplay(char type[10]) {
	if (strcmp(type, "manage") == 0) {
		FILE* file;
		file = fopen("member.dat", "rb");
		if (file == NULL) {
			printf("Error while opening the file.");
			exit(-1);
		}

		printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
		printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
		//Read the member file and print all out
		while (fread(&m, sizeof(Member), 1, file) != 0) {
			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", m.memberID, m.memberName, m.memberPassword, m.memberEmail, m.memberContactNo, m.memberIC, m.memberGender, m.date.day, m.date.month, m.date.year);
		}
		fclose(file);
	}
	else if (strcmp(type, "self") == 0) {
		int i = 0, mdisplay = 0;
		FILE* file;
		file = fopen("member.dat", "rb");
		if (file == NULL) {
			printf("Error while opening the file.");
			exit(-1);
		}

		//Copy the whole member file info into member array
		while (fread(&m, sizeof(Member), 1, file) != 0) {
			mem[mdisplay] = m;
			mdisplay++;
		}
		fclose(file);

		//Get the current user info and print out
		for (i = 0; i < mdisplay; i++) {
			if (strcmp(current_memberId, mem[i].memberID) == 0) {
				printf("\n          Member Profile\n");
				printf("-----------------------------------------\n");
				printf("Staff ID     : %s\n", mem[i].memberID);
				printf("Name         : %s\n", mem[i].memberName);
				printf("Password     : %s\n", mem[i].memberPassword);
				printf("Email        : %s\n", mem[i].memberEmail);
				printf("Contact No   : %s\n", mem[i].memberContactNo);
				printf("IC No        : %s\n", mem[i].memberIC);
				printf("Gender       : %c\n", mem[i].memberGender);
				printf("Date Joined  : %02d-%02d-%d\n", mem[i].date.day, mem[i].date.month, mem[i].date.year);
				printf("-----------------------------------------\n\n");
				break;
			}
		}
	}
}

void memberModify(char type[10]) {
	if (strcmp(type, "manage") == 0) {
		char newmemberName[51], newmemberGender, newmemberEmail[51], newmemberPassword[51], newmemberIC[20], newmemberContactNo[20], memName[51], confirmation, manother = 'N';
		int mcount = 0, i = 0, modifyCount = 0, mchoice, z = 0;
		FILE* file;
		file = fopen("member.dat", "rb");
		if (file == NULL) {
			printf("Error while opening the file.");
			exit(-1);
		}

		//Copy the whole member file info into member array
		while (fread(&m, sizeof(Member), 1, file) != 0) {
			mem[mcount] = m;
			mcount++;
		}
		fclose(file);

		memberDisplay("manage");
		printf("Enter member ID > ");
		rewind(stdin);
		scanf("%[^\n]", memName);
		//Find the member ID in the member file
		for (i = 0; i < mcount; i++) {
			//If the member ID same in the member file, print out the info
			if (strcmp(memName, mem[i].memberID) == 0) {
				do {
					do {
						printf("\n");
						printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
						printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
						printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
						printf("1. Modify Member Name\n");
						printf("2. Modify Member Password\n");
						printf("3. Modify Member Email\n");
						printf("4. Modify Member Contact No.\n");
						printf("5. Modify Member IC\n");
						printf("6. Modify Member Gender\n");
						printf("7. Back\n");
						printf("Enter the choice you want to modify > ");
						rewind(stdin);
						scanf("%d", &mchoice);
						//Let user to choose the data they want to modify
						switch (mchoice) {
						case 1:
							printf("Enter new member name > ");
							rewind(stdin);
							scanf("%[^\n]", &newmemberName);
							printf("Are you sure you want to modify your name? (Y = Yes) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(mem[i].memberName, newmemberName);
								printf("Modify Successfully!\n");
								modifyCount++;
							}
							else {
								printf("Modify Unsuccessfully!\n");
							}
							break;
						case 2:
							printf("Enter new member Password > ");
							rewind(stdin);
							scanf("%[^\n]", &newmemberPassword);
							printf("Are you sure you want to modify your password? (Y = Yes) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(mem[i].memberPassword, newmemberPassword);
								printf("Modify Successfully!\n");
								modifyCount++;
							}
							else {
								printf("Modify Unsuccessfully!\n");
							}
							break;
						case 3:
							printf("Enter new member email > ");
							rewind(stdin);
							scanf("%[^\n]", newmemberEmail);
							printf("Are you sure you want to modify your email? (Y = Yes) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(mem[i].memberEmail, newmemberEmail);
								printf("Modify Successfully!\n");
								modifyCount++;
							}
							else {
								printf("Modify Unsuccessfully!\n");
							}
							break;
						case 4:
							do {
								printf("Enter new contact number > ");
								rewind(stdin);
								scanf("%[^\n]", &newmemberContactNo);
								if (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10) {
									printf("Please enter the correct contact number!\n");
								}
							} while (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10);
							printf("Are you sure you want to modify your contact number? (Y = Yes) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(mem[i].memberContactNo, newmemberContactNo);
								printf("Modify Successfully!\n");
								modifyCount++;
							}
							else {
								printf("Modify Unsuccessfully!\n");
							}
							break;
						case 5:
							do {
								printf("Enter new member IC > ");
								rewind(stdin);
								scanf("%[^\n]", &newmemberIC);
								if (strlen(newmemberIC) != 12) {
									printf("Please enter the correct IC!\n");
								}
							} while (strlen(newmemberIC) != 12);
							printf("Are you sure you want to modify your IC? (Y = Yes) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(mem[i].memberIC, newmemberIC);
								printf("Modify Successfully!\n");
								modifyCount++;
							}
							else {
								printf("Modify Unsuccessfully!\n");
							}
							break;
						case 6:
							do {
								printf("Enter new gender (M/F) > ");
								rewind(stdin);
								scanf("%c", &newmemberGender);
								if (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M') {
									printf("Please enter the correct gender!\n");
								}
							} while (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M');
							printf("Are you sure you want to modify your gender? (Y = Yes) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								mem[i].memberGender = toupper(newmemberGender);
								printf("Modify Successfully!\n");
								modifyCount++;
							}
							else {
								printf("Modify Unsuccessfully!\n");
							}
							break;
						case 7:
							break;
						default:
							printf("**Please select the correct option.**\n");
							break;
						}
						//Loop again if the choice user enter is not in the range 1 to 6
					} while (!(mchoice >= 1 && mchoice <= 7));
					if (mchoice != 7 && modifyCount != 0) {
						printf("Modify Another record? (Y = Yes) > ");
						rewind(stdin);
						scanf("%c", &manother);
					}
					//Loop again if the user need to modify other data
				} while (toupper(manother) == 'Y');
			}
		}

		FILE* ptr;
		//Open the member file for writing
		ptr = fopen("member.dat", "wb");
		//Rewrite all the new data into the Member file
		for (int i = 0; i < mcount; i++) {
			fwrite(&mem[i], sizeof(Member), 1, ptr);
		}
		printf("%d field(s) modified.\n\n", modifyCount);

		fclose(ptr);
	}
	else if (strcmp(type, "self") == 0) {
		char memName[51], newmemberName[51], newmemberGender, newmemberEmail[51], newmemberPassword[51], newmemberIC[20], newmemberContactNo[20], confirmation, manother = 'N';
		int mdfcount = 0, i = 0, modifyCount = 0, mchoice;
		FILE* file;
		file = fopen("member.dat", "rb");
		if (file == NULL) {
			printf("Error while opening the file.");
				exit(-1);
		}

		//Copy the whole member file into member array
		while (fread(&m, sizeof(Member), 1, file) != 0) {
			mem[mdfcount] = m;
			mdfcount++;
		}
		fclose(file);


		//Let user to choose what they want to modify
		do {
			printf("\n");
			//Scan the current member ID
			scanf("%[^\n]", &current_memberId);

			for (i = 0; i < mdfcount; i++) {
				//Find the member ID in the member array and print out
				if (strcmp(current_memberId, mem[i].memberID) == 0) {
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
					printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
					break;
				}
			}

			do {
				printf("1. Modify Member Name\n");
				printf("2. Modify Member Password\n");
				printf("3. Modify Member Email\n");
				printf("4. Modify Member Contact No.\n");
				printf("5. Modify Member IC\n");
				printf("6. Modify Member Gender\n");
				printf("7. Back\n");
				printf("Enter the choice you want to modify > ");
				rewind(stdin);
				scanf("%d", &mchoice);

				switch (mchoice) {
				case 1:
					printf("Enter new member name > ");
					rewind(stdin);
					scanf("%[^\n]", &newmemberName);
					printf("Are you sure you want to modify your name? (Y = Yes) > ");
					rewind(stdin);
					scanf("%c", &confirmation);
					if (toupper(confirmation) == 'Y') {
						strcpy(mem[i].memberName, newmemberName);
						printf("Modify Successfully!\n");
						modifyCount++;
					}
					else {
						printf("Modify Unsuccessfully!\n");
					}
					break;
				case 2:
					printf("Enter new member Password > ");
					rewind(stdin);
					scanf("%[^\n]", &newmemberPassword);
					printf("Are you sure you want to modify your password? (Y = Yes) > ");
					rewind(stdin);
					scanf("%c", &confirmation);
					if (toupper(confirmation) == 'Y') {
						strcpy(mem[i].memberPassword, newmemberPassword);
						printf("Modify Successfully!\n");
						modifyCount++;
					}
					else {
						printf("Modify Unsuccessfully!\n");
					}
					break;
				case 3:
					printf("Enter new member email > ");
					rewind(stdin);
					scanf("%[^\n]", newmemberEmail);
					printf("Are you sure you want to modify your email? (Y = Yes) > ");
					rewind(stdin);
					scanf("%c", &confirmation);
					if (toupper(confirmation) == 'Y') {
						strcpy(mem[i].memberEmail, newmemberEmail);
						printf("Modify Successfully!\n");
						modifyCount++;
					}
					else {
						printf("Modify Unsuccessfully!\n");
					}
					break;
				case 4:
					do {
						printf("Enter new contact number > ");
						rewind(stdin);
						scanf("%[^\n]", &newmemberContactNo);
						if (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10) {
							printf("**Please enter the correct contact number!**\n");
						}
					} while (strlen(newmemberContactNo) > 11 || strlen(newmemberContactNo) < 10);
					printf("Are you sure you want to modify your contact number? (Y = Yes) > ");
					rewind(stdin);
					scanf("%c", &confirmation);
					if (toupper(confirmation) == 'Y') {
						strcpy(mem[i].memberContactNo, newmemberContactNo);
						printf("Modify Successfully!\n");
						modifyCount++;
					}
					else {
						printf("Modify Unsuccessfully!\n");
					}
					break;
				case 5:
					do {
						printf("Enter new member IC > ");
						rewind(stdin);
						scanf("%[^\n]", &newmemberIC);
						if (strlen(newmemberIC) != 12) {
							printf("Please enter the correct IC!\n");
						}
					} while (strlen(newmemberIC) != 12);
					printf("Are you sure you want to modify your IC? (Y = Yes) > ");
					rewind(stdin);
					scanf("%c", &confirmation);
					if (toupper(confirmation) == 'Y') {
						strcpy(mem[i].memberIC, newmemberIC);
						printf("Modify Successfully!\n");
						modifyCount++;
					}
					else {
						printf("Modify Unsuccessfully!\n");
					}
					break;
				case 6:
					do {
						printf("Enter new gender (M/F) > ");
						rewind(stdin);
						scanf("%c", &newmemberGender);
						if (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M') {
							printf("**Please enter the correct gender!**\n");
						}
					} while (toupper(newmemberGender) != 'F' && toupper(newmemberGender) != 'M');
					printf("Are you sure you want to modify your gender? (Y = Yes) > ");
					rewind(stdin);
					scanf("%c", &confirmation);
					if (toupper(confirmation) == 'Y') {
						mem[i].memberGender = toupper(newmemberGender);
						printf("Modify Successfully!\n");
						modifyCount++;
					}
					else {
						printf("Modify Unsuccessfully!\n");
					}
					break;
				case 7:
					break;
				default:
					printf("Please select the correct option.\n\n");
					break;
				}
				//Loop again choice user choose is not in the range 1 to 6
			} while (mchoice < 1 || mchoice > 7);
			if (mchoice != 7 && modifyCount != 0) {
				printf("Modify Another record? (Y = Yes) > ");
				rewind(stdin);
				scanf("%c", &manother);
			}
			//Loop again if the user want to modify again
		} while (toupper(manother) == 'Y');

		FILE* ptr;
		//Open the file for writing
		ptr = fopen("member.dat", "wb");

		//Rewrite all the new data into the Member file
		for (int i = 0; i < mdfcount; i++) {
			fwrite(&mem[i], sizeof(Member), 1, ptr);
		}
		printf("%d field(s) modified.\n\n", modifyCount);

		fclose(ptr);
	}
}

void memberSearch() {
	char name[51], contactNo[20], gender, ans;
	int i = 0, msearch = 0, choice;
	FILE* ptr;
	ptr = fopen("member.dat", "rb");
	if (ptr == NULL) {
		printf("Error while opening the file.");
		exit(-1);
	}

	//Copy all the data in the Member file into member array
	while (fread(&m, sizeof(Member), 1, ptr) != 0) {
		mem[msearch] = m;
		msearch++;
	}
	fclose(ptr);

	do {
		printf("1. Member Name\n");
		printf("2. Member Contact Number\n");
		printf("3. Member Gender\n");
		printf("4. Back\n");
		do {
			printf("Select field > ");
			rewind(stdin);
			scanf("%d", &choice);
			if (!(choice >= 1 && choice <= 4)) {
				printf("Please select again.\n");
			}
		} while (!(choice >= 1 && choice <= 4));

		//Let user to choose how they want to search the member
		switch (choice) {
		case 1:
			printf("Enter member name > ");
			rewind(stdin);
			scanf("%[^\n]", &name);

			for (i = 0; i < msearch; i++) {
				//Compare the name user enter with the name in the member array, if same then print out all the info about the member
				if (strcmp(name, mem[i].memberName) == 0) {
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
					printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
					break;
				}
			}
			//If the name user enter is not in the member array, an error message came out
			if (strcmp(name, mem[i].memberName) != 0) {
				printf("**Name not found!**\n");
			}
			break;
		case 2:
			do {
				printf("Enter member contact number > ");
				rewind(stdin);
				scanf("%[^\n]", &contactNo);
				if (strlen(contactNo) > 11 || strlen(contactNo) < 10) {
					printf("**Please enter the correct contact number!**\n");
				}
			} while (strlen(contactNo) > 11 || strlen(contactNo) < 10);

			for (i = 0; i < msearch; i++) {
				//Compare the contact number with the contac number in the member array, if same then print out all the info about the member
				if (strcmp(contactNo, mem[i].memberContactNo) == 0) {
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
					printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
					break;
				}
			}
			//If the contact number user enter is not same in the member array, an error message came out
			if (strcmp(contactNo, mem[i].memberContactNo) != 0) {
				printf("**Contact number not found!**\n");
			}
			break;
		case 3:
			do {
				printf("Enter member gender (M/F) > ");
				rewind(stdin);
				scanf("%c", &gender);
				//Check if the user had enter the correct gender or not, male of female
				if (toupper(gender) != 'F' && toupper(gender) != 'M') {
					printf("Please enter the correct gender!\n");
				}
			} while (toupper(gender) != 'F' && toupper(gender) != 'M');

			gender = toupper(gender);
			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
			int run = 0;
			//Print out all the info about the member if the gender is same with the member array
			for (i = 0; i < msearch; i++) {
				if (gender == mem[i].memberGender) {
					run++;
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
				}
			}
			if (run == 0) {
				printf("**Gender not found!**\n");
			}
			break;
		case 4:
			break;
		default:
			printf("**Please select again.**\n");
			break;
		}
		printf("Do you want to search again? (Y = yes) > ");
		rewind(stdin);
		scanf("%c", &ans);
	} while (toupper(ans) == 'Y');
}

void memberDelete() {
	char memdlt[20], confirm, ans;
	int dlt = 0, i = 0, n = 0, found;
	Member memdelete[20];

	FILE* file;
	file = fopen("member.dat", "rb");
	if (file == NULL) {
		printf("Error while opening the file.");
		exit(-1);
	}

	//Copy all the data in to Member file into member array
	while (fread(&m, sizeof(Member), 1, file) != 0) {
		mem[dlt] = m;
		dlt++;
	}
	fclose(file);

	printf("\n");
	memberDisplay("manage");
	printf("Enter the member ID to delete account > ");
	rewind(stdin);
	scanf("%[^\n]", &memdlt);
	printf("\n");

	found = 0;
	for (i = 0; i < dlt; i++) {
		//Compare the member ID with the member array
		if (strcmp(memdlt, mem[i].memberID) == 0) {
			found = 1;
			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n",
				mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
			printf("\n");
			printf("Are you sure you want to delete this account? (Y = Yes) > ");
			rewind(stdin);
			scanf("%c", &confirm);
			if (toupper(confirm) == 'Y') {
				for (i = 0; i < dlt; i++) {
					//If the member ID not same with the array, copy the whole member info into another array
					if (strcmp(memdlt, mem[i].memberID) != 0) {
						memdelete[n] = mem[i];
						n++;
					}
				}
				FILE* ptr;
				ptr = fopen("member.dat", "wb");
				for (int n = 0; n < dlt-1; n++) {
					//Write all the not remain data into the Member file
					fwrite(&memdelete[n], sizeof(Member), 1, ptr);
				}
				fclose(ptr);
				printf("Member '%s' deleted.\n\n", memdlt);
			}
		}
	}
	if (found == 0) {
		printf("**Member record not found.**\n\n");
	}
}

void memberReport() {
	char writeMonth[30], choose;
	int rpcount = 0, i = 0, choice, memberMonth, memberYear, findDate, memberRYear;
	int cDay, cMonth, cYear, cHour, cMinute, cSecond;
	SYSTEMTIME time;
	FILE* file;
	file = fopen("member.dat", "rb");
	if (file == NULL) {
		printf("Error while opening the file.");
		exit(-1);
	}

	//Copy all the data in to Member file into member array
	while (fread(&m, sizeof(Member), 1, file) != 0) {
		mem[rpcount] = m;
		rpcount++;
	}
	fclose(file);

	do {
		printf("        Type of report \n");
		printf("================================\n");
		printf("| 1. New Member Monthly Report |\n");
		printf("| 2. New Member Yearly Report  |\n");
		printf("| 3. Back                      |\n");
		printf("================================\n");
		printf("Please enter your choice > ");
		rewind(stdin);
		scanf("%d", &choice);

		//Let user to choose the type of report
		switch (choice) {
		case 1:
			do {
				printf("Please enter the year (2000-2023) > ");
				rewind(stdin);
				scanf("%d", &memberYear);
				if (memberYear > 2023 || memberYear < 2000) {
					printf("**Invalid year!**\n");
				}
			} while (memberYear > 2023 || memberYear < 2000);

			do {
				printf("Please enter the month (1-12) > ");
				rewind(stdin);
				scanf("%d", &memberMonth);
				if (memberMonth > 12 || memberMonth < 1) {
					printf("**Invalid month!**\n");
				}
			} while (memberMonth > 12 || memberMonth < 1);

			//Change the month in number into a word
			switch (memberMonth) {
			case 1:
				strcpy(writeMonth, "JANUARY");
				break;
			case 2:
				strcpy(writeMonth, "FEBRUARY");
				break;
			case 3:
				strcpy(writeMonth, "MARCH");
				break;
			case 4:
				strcpy(writeMonth, "APRIL");
				break;
			case 5:
				strcpy(writeMonth, "MAY");
				break;
			case 6:
				strcpy(writeMonth, "JUNE");
				break;
			case 7:
				strcpy(writeMonth, "JULY");
				break;
			case 8:
				strcpy(writeMonth, "AUGUST");
				break;
			case 9:
				strcpy(writeMonth, "SEPTEMBER");
				break;
			case 10:
				strcpy(writeMonth, "OCTOBER");
				break;
			case 11:
				strcpy(writeMonth, "NOVEMBER");
				break;
			case 12:
				strcpy(writeMonth, "DECEMBER");
				break;
			default:
				strcpy(writeMonth, "Error");
				break;
			}
			findDate = 0;

			GetLocalTime(&time);
			cDay = time.wDay;
			cMonth = time.wMonth;
			cYear = time.wYear;
			cHour = time.wHour;
			cMinute = time.wMinute;
			cSecond = time.wSecond;

			printf("=============================\n");
			printf("| NEW MEMBER MONTHLY REPORT |\n");
			printf("=============================\n");
			printf("List of New Member Joined in %-9s %d\n", writeMonth, memberYear);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Date: %02d-%02d-%d %122s: %02d:%02d:%02d\n\n", cDay, cMonth, cYear, "Time", cHour, cMinute, cSecond);
			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
			//Print all the member that join in the month and year user entered
			for (i = 0; i < rpcount; i++) {
				if (memberMonth == mem[i].date.month && memberYear == mem[i].date.year) {
					findDate = 1;
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
				}
			}
			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
			if (findDate != 1) {
				printf("No Member Join In %s %d\n", writeMonth, memberYear);
			}
			break;

		case 2:
			do {
				printf("Please enter the year (2000-2023) > ");
				rewind(stdin);
				scanf("%d", &memberRYear);
				if (memberRYear > 2024 || memberRYear < 2000) {
					printf("**Invalid year!**\n");
				}
			} while (memberRYear > 2024 || memberRYear < 2000);
			findDate = 0;

			GetLocalTime(&time);
			cDay = time.wDay;
			cMonth = time.wMonth;
			cYear = time.wYear;
			cHour = time.wHour;
			cMinute = time.wMinute;
			cSecond = time.wSecond;

			printf("============================\n");
			printf("| NEW MEMBER YEARLY REPORT |\n");
			printf("============================\n");
			printf("List of New Member Joined in Year %d\n", memberRYear);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Date: %02d-%02d-%d %122s: %02d:%02d:%02d\n\n", cDay, cMonth, cYear, "Time", cHour, cMinute, cSecond);
			printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15s %-16s\n", "Member ID", "Member Name", "Member Password", "Member Email", "Member Contact No.", "Member IC", "Member Gender", "Member Join Date");
			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
			for (i = 0; i < rpcount; i++) {
				if (memberRYear == mem[i].date.year) {
					findDate = 1;
					printf("%-10s %-20s %-20s %-30s %-19s %-13s %-15c %d/%d/%d\n", mem[i].memberID, mem[i].memberName, mem[i].memberPassword, mem[i].memberEmail, mem[i].memberContactNo, mem[i].memberIC, mem[i].memberGender, mem[i].date.day, mem[i].date.month, mem[i].date.year);
				}
			}
			printf("========== ==================== ==================== ============================== =================== ============= =============== ================\n");
			if (findDate != 1) {
				printf("No Member Join In Year %d\n", memberRYear);
			}
			break;

		case 3:
			break;

		default:
			printf("**Please select the correct option.**\n");
			break;
		}

		printf("Do you want to view another report (Y = Yes) > ");
		rewind(stdin);
		scanf("%c", &choose);
	} while (toupper(choose) == 'Y');
}

//Staff Information Module
//By: Ryan Moey Kai Xiang
int staffLogin() {
	FILE* file;
	int scount = 0;
	int choice;
	char loginpassword[30];
	int found = 0;

	file = fopen("staff.dat", "rb");
	if (file == NULL) {
		printf("Error while opening the file\n");
		exit(-1);
	}

	printf("  Staff portal  \n");
	printf("=================\n");
	printf("| 1 - Log in    |\n");
	printf("| 2 - Back      |\n");
	printf("=================\n");
	printf("Enter your choice > ");
	rewind(stdin);
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		printf("Enter staff id : ");
		rewind(stdin);
		scanf("%s", &current_staffId);

		rewind(file);
		while (fread(&staff, sizeof(staffs), 1, file) != 0) {
			if (strcmp(staff.staffid, current_staffId) == 0) {
				found = 1;
				printf("Enter password : ");
				rewind(stdin);
				scanf("%[^\n]", loginpassword);
				if (strcmp(staff.password, loginpassword) == 0) {
					strcpy(loginStaffPosition, staff.position);
					printf("Login successful!\n\n");
					fclose(file);
					return 1;
				}
				else {
					printf("**Incorrect password**\n\n");
					fclose(file);
					return 0;
				}
			}
		}
		if (found != 1) {
			printf("**Incorrect staff id**\n\n");
			return 0;
		}
		break;
	case 2:
		break;
	default:
		printf("**Enter valid input!**\n\n");
		return 0;
		break;
	}
}

void staffCreate() {
	FILE* addfile, * readfile, * readbinfile;
	int scount = 0, stotal = 0;
	char addchoice, confirmation;
	int i = 0, staffpositionchoice;
	SYSTEMTIME time;
	staffs checkstaff[50];

	readfile = fopen("staff.dat", "rb");
	addfile = fopen("staff.dat", "ab");
	readbinfile = fopen("staffbin.dat", "rb");
	if (readfile == NULL || addfile == NULL || readbinfile == NULL) {
		printf("Error while opening the file\n");
		exit(-1);
	}

	while (fread(&staff, sizeof(staffs), 1, readfile) != 0) {
		checkstaff[scount] = staff;
		scount++;
		stotal++;
	}

	while (fread(&staff, sizeof(staffs), 1, readbinfile) != 0) {
		stotal++;
	}
	fclose(readbinfile);

	do {
		printf("\nAdd new staff account\n");
		printf("---------------------\n");
		sprintf(staff.staffid, "ST%03d", stotal);
		stotal++;

		do {
			printf("Enter staff name : ");
			rewind(stdin);
			strcpy(staff.name, "");
			scanf("%[^\n]", &staff.name);
			if (strlen(staff.name) == 0) {
				printf("**Name is null. Please try again.**\n");
			}
		} while (strlen(staff.name) == 0);

		do {
			printf("Enter staff gender ( M / F ) : ");
			rewind(stdin);
			scanf("%c", &staff.gender);
			staff.gender = toupper(staff.gender);
			if (staff.gender != 'M' && staff.gender != 'F') {	//check whether gender entered is only M or F
				printf("**Invalid gender. Please enter 'M' or 'F'.**\n");
			}
		} while (staff.gender != 'M' && staff.gender != 'F');

		do {
			printf("Enter staff email : ");
			rewind(stdin);
			scanf("%[^\n]", &staff.email);
			for (i = 0; i < scount; i++) {//compare the email that user enter and email exist in the file to prevent duplicated email
				if (strcmp(checkstaff[i].email, staff.email) == 0) {
					printf("**Invalid email. Please try again.**\n");
					break;
				}
			}
		} while (strcmp(checkstaff[i].email, staff.email) == 0);

		do {
			printf("Enter staff password : ");
			rewind(stdin);
			strcpy(staff.password, "");
			scanf("%[^\n]", &staff.password);
			if (strlen(staff.password) == 0) {
				printf("**Name is null. Please try again.**\n");
			}
		} while (strlen(staff.password) == 0);

		do {
			printf("Enter staff phone number : ");
			rewind(stdin);
			scanf("%[^\n]", &staff.phnum);
			if (strlen(staff.phnum) > 11 || strlen(staff.phnum) < 10) {//check whether the phone number entered fullfilled the stringlength more than 11 and less than 10
				printf("Invalid phone number.enter again!\n");
			}
			for (i = 0; i < scount; i++) {//compare the phone number that user enter and phone number exist in the file to prevent duplicated phone number
				if (strcmp(checkstaff[i].phnum, staff.phnum) == 0) {
					printf("**Phone number had been used. Please try again.**\n");
					break;
				}
			}
		} while (strlen(staff.phnum) > 11 || strlen(staff.phnum) < 10 || strcmp(checkstaff[i].phnum, staff.phnum) == 0);

		do {
			printf("Enter staff ic : ");
			rewind(stdin);
			scanf("%[^\n]", &staff.ic);
			if (strlen(staff.ic) != 12) {//check whether the ic entered fullfilled the stringlength of 12
				printf("**Invalid IC number. Please try again!**\n");
			}
			for (i = 0; i < scount; i++) {//compare the ic that user enter and ic exist in the file to prevent duplicated ic
				if (strcmp(checkstaff[i].ic, staff.ic) == 0) {
					printf("**Phone number had been used. Please try again.**\n");
					break;
				}
			}
		} while (strlen(staff.ic) != 12 || strcmp(checkstaff[i].ic, staff.ic) == 0);

		printf("Choose staff position\n");
		printf("------------\n");
		printf("1 - Manager \n");
		printf("2 - Staff \n");
		printf("3 - Intern \n");
		printf("------------\n");
		printf("Position > ");
		rewind(stdin);
		scanf("%d", &staffpositionchoice);

		do {
			switch (staffpositionchoice) {//let user choose position based on number
			case 1:
				strcpy(staff.position, "Manager");
				break;
			case 2:
				strcpy(staff.position, "Staff");
				break;
			case 3:
				strcpy(staff.position, "Intern");
				break;
			default:
				printf("enter valid input\n");
			}
		} while (staffpositionchoice < 1 || staffpositionchoice > 3);

		printf("Confirm add this staff information? ( Y = yes / N = no ) > ");
		rewind(stdin);
		scanf("%c", &confirmation);
		if (toupper(confirmation) == 'Y') {
			//save the time of new account created
			GetLocalTime(&time);
			staff.date.day = time.wDay;
			staff.date.month = time.wMonth;
			staff.date.year = time.wYear;
			fwrite(&staff, sizeof(staffs), 1, addfile);
			printf("[ Staff id '%s' created successfully on %02d-%02d-%d ]\n\n", staff.staffid, staff.date.day, staff.date.month, staff.date.year);
		}
		else {
			printf("Not saved\n\n");
		}
		printf("Add another staff account? ( Y = yes / N = no ) > ");

		rewind(stdin);
		scanf("%c", &addchoice);
	} while (toupper(addchoice) == 'Y');

	fclose(addfile);
}

void staffDisplay(char type[10]) {
	if (strcmp(type, "manage") == 0) {
		FILE* displayfile;
		int staffcount = 0, scount = 0;

		displayfile = fopen("staff.dat", "rb");
		if (displayfile == NULL) {
			printf("Error while opening the file\n");
			exit(-1);
		}

		while (fread(&staff, sizeof(staffs), 1, displayfile) != 0) {
			staffarr[scount] = staff;
			scount++;
		}

		printf("\n                                                             Apapunada company staff information\n");
		printf("                                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		staffHeader(1);
		for (int i = 0; i < scount; i++) {
			printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, staffarr[i].phnum, staffarr[i].ic,
				staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
		}
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("< %d staff listed >\n\n", scount);

		fclose(displayfile);
	}
	else if (strcmp(type, "self") == 0) {
		FILE* displayfile;
		int staffcount = 0, scount = 0;

		displayfile = fopen("staff.dat", "rb");
		if (displayfile == NULL) {
			printf("Error while opening the file\n");
			exit(-1);
		}

		while (fread(&staff, sizeof(staffs), 1, displayfile) != 0) {
			staffarr[scount] = staff;
			scount++;
		}
		for (int i = 0; i < scount; i++) {
			if (strcmp(current_staffId, staffarr[i].staffid) == 0) {
				printf("\n          %s Staff Profile\n", staffarr[i].staffid);
				printf("-----------------------------------------\n");
				printf("Staff id     : %s\n", staffarr[i].staffid);
				printf("Name         : %s\n", staffarr[i].name);
				printf("Gender       : %c\n", staffarr[i].gender);
				printf("Email        : %s\n", staffarr[i].email);
				printf("Password     : %s\n", staffarr[i].password);
				printf("Phone number : %s\n", staffarr[i].phnum);
				printf("IC number    : %s\n", staffarr[i].ic);
				printf("Position     : %s\n", staffarr[i].position);
				printf("Date joined  : %02d-%02d-%d\n", staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				printf("-----------------------------------------\n\n");
				break;
			}
		}
		fclose(displayfile);
	}
}

void staffModify(char type[10]) {
	if (strcmp(type, "manage") == 0) {
		FILE* modifyfile1, * modifyfile2;
		int scount = 0, modifychoice, modifycount = 0;
		char modifyid[10], confirmation;
		char newname[30], newgender, newemail[30], newpassword[30], newph[20], newic[20], newposition[30];
		int newpositionchoice;
		char anothermchoice, modifyagain;
		int i, n;

		modifyfile1 = fopen("staff.dat", "rb");
		if (modifyfile1 == NULL) {
			printf("Error while opening the file\n");
			return -1;
		}

		while (fread(&staff, sizeof(staffs), 1, modifyfile1) != 0) {
			staffarr[scount] = staff;
			scount++;
		}

		fclose(modifyfile1);

		do {
			staffDisplay("manage");
			printf("Enter staff id that you want to modify > "); //if position == manager then all else self
			rewind(stdin);
			scanf("%s", &modifyid);
			for (i = 0; i < scount; i++) {

				if (strcmp(staffarr[i].staffid, modifyid) == 0) {

					printf("\nStaff detail of staff id :%s\n\n", modifyid);
					staffHeader(1);
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n",
						staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, staffarr[i].phnum, staffarr[i].ic, staffarr[i].position,
						staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
					staffHeader(0);
					printf("\n");
					do {
						printf("         Modify choices\n");
						printf("=================================\n");
						printf("| 1 - Modify staff name         |\n");
						printf("| 2 - Modify staff gender       |\n");
						printf("| 3 - Modify staff email        |\n");
						printf("| 4 - Modify staff password     |\n");
						printf("| 5 - Modify staff phone number |\n");
						printf("| 6 - Modify staff ic           |\n");
						printf("| 7 - Modify staff position     |\n");
						printf("| 8 - Back                      |\n");
						printf("=================================\n");
						printf("Enter your modify choice > ");
						scanf("%d", &modifychoice);
						switch (modifychoice) {
						case 1://edit name
							do {
								printf("Enter new staff name > ");
								rewind(stdin);
								scanf("%[^\n]", &newname);
								if (strlen(newname) == 0) {
									printf("**New name is null. Please try again.**\n");
								}
							} while (strlen(newname) == 0);
							printf("Confirm modify ( Y = yes ) ? > \n");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].name, newname);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 2://edit gender
							do {
								printf("Enter new staff gender ( M / F ) > ");
								rewind(stdin);
								scanf("%c", &newgender);
								newgender = toupper(newgender);
								if (newgender != 'M' && newgender != 'F') {
									printf("**Invalid gender. Please enter 'M' or 'F'**\n");
								}
							} while (newgender != 'M' && newgender != 'F');
							printf("Confirm modify ( Y = yes ) ? > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								staffarr[i].gender = newgender;
								printf("Modify successfully!\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 3://edit email
							printf("Enter new staff email > ");
							rewind(stdin);
							scanf("%[^\n]", &newemail);
							printf("Confirm modify ( Y = yes ) ? > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].email, newemail);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 4://edit password
							do {
								printf("Enter new staff password > ");
								rewind(stdin);
								scanf("%[^\n]", &newpassword);
								if (strlen(newpassword) == 0) {
									printf("New password is null. Please try again.**\n");
								}
							} while (strlen(newpassword) == 0);
							printf("Confirm modify ( Y = yes ) ? > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].password, newpassword);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 5://edit phone number
							do {
								printf("Enter new staff phone number > ");
								rewind(stdin);
								scanf("%[^\n]", &newph);
								if (strlen(newph) > 11 || strlen(newph) < 10) {
									printf("**Invalid phone number.enter again!**\n");
								}
								for (n = 0; n < scount; n++) {
									if (strcmp(staffarr[n].phnum, newph) == 0) {
										printf("**Phone number had been used. Please try again.**\n");
										break;
									}
								}
							} while (strlen(newph) > 11 || strlen(newph) < 10 || strcmp(staffarr[i].phnum, newph) == 0);
							printf("Confirm modify? ( Y = yes ) > \n");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].phnum, newph);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 6://edit ic
							do {
								printf("Enter new staff ic > ");
								rewind(stdin);
								scanf("%[^\n]", &newic);
								if (strlen(newic) != 12) {
									printf("**Invalid IC number. Please try again.**\n");
								}
								for (n = 0; n < scount; n++) {
									if (strcmp(staffarr[n].ic, newic) == 0) {
										printf("**IC number had been used. Please try again.**\n");
										break;
									}
								}
							} while (strlen(newic) != 12 || strcmp(staffarr[i].ic, newic) == 0);

							printf("Confirm modify? ( Y = yes ) > \n");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].ic, newic);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 7://edit position
							printf("Choose new staff position\n");
							printf("------------\n");
							printf("1 - Manager \n");
							printf("2 - Staff   \n");
							printf("3 - Intern  \n");
							printf("------------\n");
							printf("Position > ");
							rewind(stdin);
							scanf("%d", &newpositionchoice);
							switch (newpositionchoice) {
							case 1:
								strcpy(newposition, "Manager");
								printf("Confirm modify ( Y = yes ) ? > ");
								rewind(stdin);
								scanf("%c", &confirmation);
								if (toupper(confirmation) == 'Y') {
									strcpy(staffarr[i].position, newposition);
									printf("Modify successfully !\n");
									modifycount++;
								}
								else {
									printf("Modify unsuccessfully!\n");
								}
								break;
							case 2:
								strcpy(newposition, "Staff");
								printf("Confirm modify ( Y = yes ) ? > ");
								rewind(stdin);
								scanf("%c", &confirmation);
								if (toupper(confirmation) == 'Y') {
									strcpy(staffarr[i].position, newposition);
									printf("Modify successfully !\n");
									modifycount++;
								}
								else {
									printf("Modify unsuccessfully!\n");
								}
								break;
							case 3:
								strcpy(newposition, "Intern");
								printf("Confirm modify ( Y = yes ) ? > ");
								rewind(stdin);
								scanf("%c", &confirmation);
								if (toupper(confirmation) == 'Y') {
									strcpy(staffarr[i].position, newposition);
									printf("Modify successfully !\n");
									modifycount++;
								}
								else {
									printf("Modify unsuccessfully!\n\n");
								}
								break;
							default:
								printf("**Invalid input.**\n");
							}
							break;
						case 8:
							break;
						default:
							printf("**Please enter valid input!**\n\n");
						}
					} while (modifychoice != 8);
					i = scount;
					break;
				}
				else if (i == (scount - 1)) {
					printf("**Staff id you entered is not exist.**\n");
				}
			}

			if (modifycount > 0) {
				modifyfile2 = fopen("staff.dat", "wb");
				if (modifyfile2 == NULL) {
					printf("Error while opening the file\n");
					return -1;
				}
				for (int i = 0; i < scount; i++) {
					fwrite(&staffarr[i], sizeof(staffs), 1, modifyfile2);
				}
				printf("\n****All modifications saved!****\n\n");
				fclose(modifyfile2);
			}

			printf("Modify another record ? ( Y = yes / N = no ) > ");
			rewind(stdin);
			scanf("%c", &anothermchoice);
		} while (toupper(anothermchoice) == 'Y');
	}
	else if (strcmp(type, "self") == 0) {
		FILE* modifyfile1, * modifyfile2;
		int scount = 0, modifychoice, modifycount = 0;
		char modifyid[10], confirmation;
		char newname[30], newgender, newemail[30], newpassword[30], newph[20], newic[20], newposition[30];
		int newpositionchoice;
		char anothermchoice, modifyagain;
		int i, n;

		modifyfile1 = fopen("staff.dat", "rb");
		if (modifyfile1 == NULL) {
			printf("error while opening the file\n");
			return -1;
		}

		while (fread(&staff, sizeof(staffs), 1, modifyfile1) != 0) {
			staffarr[scount] = staff;
			scount++;
		}

		fclose(modifyfile1);

		do {
			for (i = 0; i < scount; i++) {

				if (strcmp(current_staffId, staffarr[i].staffid) == 0) {

					printf("\nStaff detail of staff id : %s\n\n", current_staffId);
					staffHeader(1);
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n",
						staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, staffarr[i].phnum, staffarr[i].ic, staffarr[i].position,
						staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
					staffHeader(0);
					printf("\n");
					do {
						printf("         Modify choices\n");
						printf("=================================\n");
						printf("| 1 - Modify staff name         |\n");
						printf("| 2 - Modify staff gender       |\n");
						printf("| 3 - Modify staff email        |\n");
						printf("| 4 - Modify staff password     |\n");
						printf("| 5 - Modify staff phone number |\n");
						printf("| 6 - Modify staff ic           |\n");
						printf("| 7 - Back                      |\n");
						printf("=================================\n");
						printf("Enter your modify choice > ");
						scanf("%d", &modifychoice);
						switch (modifychoice) {
						case 1://edit name
							do {
								printf("Enter new staff name > ");
								rewind(stdin);
								scanf("%[^\n]", &newname);
								if (strlen(newname) == 0) {
									printf("**New password is null. Please try again.**\n");
								}
							} while (strlen(newname) == 0);
							printf("Confirm modify ( Y = yes ) ? > \n");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].name, newname);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 2://edit gender
							do {
								printf("Enter new staff gender ( M / F ) > ");
								rewind(stdin);
								scanf("%c", &newgender);
								newgender = toupper(newgender);
								if (newgender != 'M' && newgender != 'F') {
									printf("**Invalid gender. Please enter 'M' or 'F'.**\n");
								}
							} while (newgender != 'M' && newgender != 'F');
							printf("Confirm modify ( Y = yes ) ? > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								staffarr[i].gender = newgender;
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 3://edit email
							printf("Enter new staff email > ");
							rewind(stdin);
							scanf("%[^\n]", &newemail);
							printf("Confirm modify ( Y = yes ) ? > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].email, newemail);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 4://edit password
							do {
								printf("Enter new staff password > ");
								rewind(stdin);
								scanf("%[^\n]", &newpassword);
								if (strlen(newpassword) == 0) {
									printf("New password is null. Please try again.**\n");
								}
							} while (strlen(newpassword) == 0);
							printf("Confirm modify ( Y = yes ) ? > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].password, newpassword);
								printf("Modify successfully !\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 5://edit phone number
							do {
								printf("Enter new staff phone number > ");
								rewind(stdin);
								scanf("%[^\n]", &newph);
								if (strlen(newph) > 11 || strlen(newph) < 10) {
									printf("**Invalid phone number. Please try again.**\n");
								}
								for (n = 0; n < scount; n++) {
									if (strcmp(staffarr[n].phnum, newph) == 0) {
										printf("**Phone number had been used. Please try again.**\n");
										break;
									}
								}
							} while (strlen(newph) > 11 || strlen(newph) < 10 || strcmp(staffarr[i].phnum, newph) == 0);
							printf("Confirm modify? ( Y = yes ) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].phnum, newph);
								printf("Modify successfully!\n");
								modifycount++;
							}
							else {
								printf("Modify unsuccessfully!\n");
							}
							break;

						case 6://edit ic
							do {
								printf("Enter new staff ic > ");
								rewind(stdin);
								scanf("%[^\n]", &newic);
								if (strlen(newic) != 12) {
									printf("**Invalid IC number. Please try again.**\n");
								}
								for (n = 0; n < scount; n++) {
									if (strcmp(staffarr[n].ic, newic) == 0) {
										printf("**IC number had been used. Please try again.**\n");
										break;
									}
								}
							} while (strlen(newic) != 12 || strcmp(staffarr[i].ic, newic) == 0);

							printf("Confirm modify? ( Y = yes ) > ");
							rewind(stdin);
							scanf("%c", &confirmation);
							if (toupper(confirmation) == 'Y') {
								strcpy(staffarr[i].ic, newic);
								printf("Modify successfully !\n");
								modifycount++;
							}else {
								printf("Modify unsuccessfully!\n");
							}
							break;
						case 7:
							break;
						default:
							printf("**Please enter valid input!**\n\n");
							break;
						}
					} while (modifychoice != 7);
					i = scount;
					break;
				}
			}

			if (modifycount > 0) {
				modifyfile2 = fopen("staff.dat", "wb");
				if (modifyfile2 == NULL) {
					printf("Error while opening the file\n");
					return -1;
				}
				for (int i = 0; i < scount; i++) {
					fwrite(&staffarr[i], sizeof(staffs), 1, modifyfile2);
				}
				printf("****All modifications saved!****\n\n");
				fclose(modifyfile2);
			}

			printf("Modify another record ? ( Y = yes / N = no ) > ");
			rewind(stdin);
			scanf("%c", &anothermchoice);
		} while (toupper(anothermchoice) == 'Y');
	}
}

void staffSearch() {
	FILE* searchfile;
	int scount = 0, searchchoice;
	char anotherschoice;
	char searchid[10], searchname[30], searchgender, searchphnum[10], searchpositionw[30];
	int searchposition, searchday, searchmonth, searchyear;
	int i, staffcount = 0;
	int foundm = 0, founds = 0, foundi = 0;

	searchfile = fopen("staff.dat", "rb");
	if (searchfile == NULL) {
		printf("Error while opening the file\n");
		exit(-1);
	}
	while (fread(&staff, sizeof(staffs), 1, searchfile) != 0) {
		staffarr[scount] = staff;
		scount++;
	}
	fclose(searchfile);

	do {
		printf("\n            Search choices\n");
		printf("======================================\n");
		printf("| 1 - Search by staffs' id           |\n");
		printf("| 2 - Search by staffs' name         |\n");
		printf("| 3 - Search by staffs' gender       |\n");
		printf("| 4 - Search by staffs' phone number |\n");
		printf("| 5 - Search by staffs' position     |\n");
		printf("| 6 - Search by staffs' date joined  |\n");
		printf("| 7 - Back                           |\n");
		printf("======================================\n");
		printf("enter your choice > ");
		rewind(stdin);
		scanf("%d", &searchchoice);

		switch (searchchoice) {
		case 1:
			printf("============================\n");
			printf("|Search based on staffs' id|\n");
			printf("============================\n");
			printf("Enter staff id : ");
			rewind(stdin);
			scanf("%s", &searchid);
			int foundid = 0;

			printf("\n");
			staffHeader(1);
			for (i = 0; i < scount; i++) {
				if (strcmp(searchid, staffarr[i].staffid) == 0) {
					foundid = 1;
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				}
			}
			staffHeader(0);
			printf("\n");
			if (foundid != 1) {
				printf("**Staff id < %s > not found**\n\n", searchid);
			}
			break;
		case 2:
			printf("==============================\n");
			printf("|Search based on staffs' name|\n");
			printf("==============================\n");
			printf("Enter staff name : ");
			rewind(stdin);
			scanf("%[^\n]", &searchname);
			int foundname = 0;

			printf("\n");
			staffHeader(1);
			for (i = 0; i < scount; i++) {
				if (strcmp(searchname, staffarr[i].name) == 0) {
					foundname = 1;
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				}
			}
			staffHeader(0);
			printf("\n");
			if (foundname != 1) {
				printf("**Staff name < %s > not found**\n\n", searchname);
			}
			break;
		case 3:
			printf("================================\n");
			printf("|Search based on staffs' gender|\n");
			printf("================================\n");
			printf("Enter staff gender : ");
			rewind(stdin);
			scanf("%c", &searchgender);
			int foundgender = 0;

			printf("\n");
			staffHeader(1);
			for (int i = 0; i < scount; i++) {
				if (toupper(searchgender) == staffarr[i].gender) {
					foundgender = 1;
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				}
			}
			staffHeader(0);
			printf("\n");
			if (foundgender != 1) {
				printf("**Staff gender < %c > not found**\n\n", searchgender);
			}
			break;
		case 4:
			printf("======================================\n");
			printf("|Search based on staffs' phone number|\n");
			printf("======================================\n");
			printf("Enter staff phone number : ");
			rewind(stdin);
			scanf("%s", &searchphnum);
			int foundphnum = 0;

			printf("\n");
			staffHeader(1);
			for (int i = 0; i < scount; i++) {
				if (strcmp(searchphnum, staffarr[i].phnum) == 0) {
					foundphnum = 1;
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				}
			}
			staffHeader(0);
			printf("\n");
			if (foundphnum != 1) {
				printf("**Staff phone number < %s > not found**\n\n", searchphnum);
			}
			break;
		case 5:
			printf("==================================\n");
			printf("|Search based on staffs' position|\n");
			printf("==================================\n");
			printf("Choose staff position\n");
			printf("------------\n");
			printf("1 - Manager \n");
			printf("2 - Staff   \n");
			printf("3 - Intern  \n");
			printf("------------\n");
			rewind(stdin);
			scanf("%d", &searchposition);
			switch (searchposition) {
			case 1:
				strcpy(searchpositionw, "Manager");
				printf("\n");
				staffHeader(1);
				for (int i = 0; i < scount; i++) {
					if (strcmp(searchpositionw, staffarr[i].position) == 0) {
						foundm = 1;
						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);

					}
				}
				staffHeader(0);
				printf("\n");
				if (foundm != 1) {
					printf("**Staff position < %s > not found**\n\n", searchpositionw);
				}
				break;
			case 2:
				strcpy(searchpositionw, "Staff");
				printf("\n");
				staffHeader(1);
				for (int i = 0; i < scount; i++) {
					if (strcmp(searchpositionw, staffarr[i].position) == 0) {
						founds = 1;
						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
					}
				}
				staffHeader(0);
				printf("\n");
				if (founds != 1) {
					printf("**Staff position < %s > not found**\n\n", searchpositionw);
				}
				break;
			case 3:
				strcpy(searchpositionw, "Intern");
				printf("\n");
				staffHeader(1);
				for (int i = 0; i < scount; i++) {
					if (strcmp(searchpositionw, staffarr[i].position) == 0) {
						foundi = 1;
						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
					}
				}
				staffHeader(0);
				printf("\n");
				if (foundi != 1) {
					printf("**Staff position < %s > not found**\n\n", searchpositionw);
				}
				break;
			default:
				printf("**Please enter valid input!**\n");
				return staffSearch();
				break;
			}
			break;
		case 6:
			printf("=====================================\n");
			printf("|Search based on staffs' date joined|\n");
			printf("=====================================\n");
			printf("Enter staff joined day :");
			rewind(stdin);
			scanf("%d", &searchday);
			printf("Enter staff joined month :");
			rewind(stdin);
			scanf("%d", &searchmonth);
			printf("Enter staff joined year :");
			rewind(stdin);
			scanf("%d", &searchyear);
			int founddate = 0;

			printf("\n");
			staffHeader(1);
			for (int i = 0; i < scount; i++) {
				if (searchday == staffarr[i].date.day && searchmonth == staffarr[i].date.month && searchyear == staffarr[i].date.year) {
					founddate = 1;
					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				}
			}
			staffHeader(0);
			printf("\n");
			if (founddate != 1) {
				printf("**Staff date joined < %02d-%02d-%d > not found.**\n\n", searchday, searchmonth, searchyear);
			}
			break;
		case 7:
			exit(-1);
			break;
		default:
			printf("**Please enter valid choice!**\n");
			return staffSearch();
			break;
		}
		printf("Search again? ( Y = yes / N = no ) > ");
		rewind(stdin);
		scanf("%c", &anotherschoice);

	} while (toupper(anotherschoice) == 'Y');

}

void staffDelete() {
	FILE* dltfile, * dltfile2, * binfile;
	char dltid[10];
	int scount = 0, dltcount = 0;
	char confirmation, anotherdchoice;
	staffs modifiedstaff[10], deletedstaff[10];
	int i = 0, n = 0, d = 0;


	dltfile = fopen("staff.dat", "rb");
	if (dltfile == NULL) {
		printf("Error while opening the file\n");
		exit(-1);
	}
	//read all the staff info into array
	while (fread(&staff, sizeof(staffs), 1, dltfile) != 0) {
		staffarr[scount] = staff;
		scount++;
	}
	fclose(dltfile);
	staffHeader(1);
	for (int i = 0; i < scount; i++) {
		printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
			staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
	}
	staffHeader(0);

	printf("\n=====================\n");
	printf("| Delete staff info | \n");
	printf("=====================\n");
	printf("Enter staff id to delete :");
	rewind(stdin);
	scanf("%[^\n]", &dltid);

	if (strcmp(current_staffId, dltid) == 0) {
		printf("**Can't delete yourself!**\n\n");
	}
	else {
		for (int i = 0; i < scount; i++) {
			if (strcmp(dltid, staffarr[i].staffid) == 0) {
				staffHeader(1);
				printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
					staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				staffHeader(0);
				break;
			}
			else if (i == (scount - 1)) {
				printf("**Staff id < %s > does not exist.**\n\n", dltid);
				exit(-1);
			}
		}

		printf("\nConfirm delete this staff account? ( Y = yes / N = no ) > ");
		rewind(stdin);
		scanf("%c", &confirmation);
		if (toupper(confirmation) == 'Y') {
			for (int i = 0; i < scount; i++) {
				//copy the data information of staff into modified array except the delete staff data
				if (strcmp(dltid, staffarr[i].staffid) != 0) {
					modifiedstaff[n] = staffarr[i];
					n++;

					dltfile2 = fopen("staff.dat", "wb");
					if (dltfile == NULL) {
						printf("Error while opening the file\n");
						return -1;
					}
					if (toupper(confirmation) == 'Y') {
						//write the data back to the binary file
						for (int i = 0; i < n; i++) {
							fwrite(&modifiedstaff[i], sizeof(staffs), 1, dltfile2);
						}
						;
						fclose(dltfile2);
					}
					else {
						dltcount++;
					}
				}
				else {
					//save the deleted staff data into deletedstaff array
					deletedstaff[d] = staffarr[i];
					d++;

					binfile = fopen("staffbin.dat", "ab");
					if (binfile == NULL) {
						printf("Error while opening the file\n");
						return -1;
					}
					//save the deleted staff data into bin binary file
					for (int j = 0; j < d; j++) {
						fwrite(&deletedstaff[j], sizeof(staffs), 1, binfile);
					}
					printf("%d account added to bin\n", d);
					fclose(binfile);
				}

			}
			printf("\nStaff id :%s deleted.\n", dltid);
			printf("%d staff account had been deleted.\n", scount - n);
		}
		else {
			printf("**Cancelled**\n");
			exit(-1);
		}
	}
}

void staffReport(char type[10]) {
	if (strcmp(type, "manage") == 0) {
		FILE* reportfile, * salesfile;
		SYSTEMTIME time;
		int scount = 0, choice, count = 0;
		char anotherrchoice, monthword[20];
		int monthlyr, monthlyryear, monthlyrcount = 0, yearlyr, yearlyrcount = 0;
		char staffidr[6], curra;
		double totalCommission = 0.0;

		reportfile = fopen("staff.dat", "rb");
		if (reportfile == NULL) {
			printf("Error while opening the file\n");
			return -1;
		}

		while (fread(&staff, sizeof(staffs), 1, reportfile) != 0) {
			staffarr[scount] = staff;
			scount++;
		}
		fclose(reportfile);

		GetLocalTime(&time);

		do {
			printf("\n");
			printf("              Report\n");
			printf("==================================\n");
			printf("| 1 - New staff monthly report   |\n");
			printf("| 2 - New staff yearly report    |\n");
			printf("| 3 - Staff commission report    |\n");
			printf("| 4 - Back                       |\n");
			printf("==================================\n");
			printf("Enter your choice > ");
			rewind(stdin);
			scanf("%d", &choice);
			switch (choice) {
			case 1:
				do {
					printf("Enter year : ");
					rewind(stdin);
					scanf("%d", &monthlyryear);
					if (monthlyryear < 2000 || monthlyryear > 2024) {
						printf("**Invalid year**\n");
					}
				} while (monthlyryear < 2000 || monthlyryear > 2024);
				do {
					printf("Enter month : ");
					rewind(stdin);
					scanf("%d", &monthlyr);
					if (monthlyr > 12 || monthlyr <= 0) {
						printf("**Invalid month**\n");
					}
				} while (monthlyr > 12 || monthlyr <= 0);

				switch (monthlyr) {
				case 1:
					strcpy(monthword, "January");
					break;
				case 2:
					strcpy(monthword, "February");
					break;
				case 3:
					strcpy(monthword, "March");
					break;
				case 4:
					strcpy(monthword, "April");
					break;
				case 5:
					strcpy(monthword, "May");
					break;
				case 6:
					strcpy(monthword, "June");
					break;
				case 7:
					strcpy(monthword, "July");
					break;
				case 8:
					strcpy(monthword, "August");
					break;
				case 9:
					strcpy(monthword, "September");
					break;
				case 10:
					strcpy(monthword, "October");
					break;
				case 11:
					strcpy(monthword, "November");
					break;
				case 12:
					strcpy(monthword, "December");
					break;
				default:
					strcpy(monthword, "**Error**");
					break;
				}
				int foundrmdate = 0;
				printf("----------------------------\n");
				printf("| New staff monthly report |\n");
				printf("----------------------------\n\n");
				printf("                                                    List of new joined staff at month of %s-%d\n", monthword, monthlyryear);
				printf("                                                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				printf("===================                                                                                                                  ================\n");
				printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
					time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
				printf("===================                                                                                                                  ================\n\n");
				staffHeader(1);
				for (int i = 0; i < scount; i++) {
					if (monthlyr == staffarr[i].date.month && monthlyryear == staffarr[i].date.year) {
						foundrmdate = 1;
						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
						monthlyrcount++;
					}
				}
				staffHeader(0);
				if (foundrmdate != 1) {
					printf("\n**Date < %s-%d > no staff join**\n\n", monthword, monthlyryear);
				}
				break;
			case 2:
				do {
					printf("Enter year : ");
					rewind(stdin);
					scanf("%d", &yearlyr);
					if (yearlyr < 2000 || yearlyr > 2024) {
						printf("**Invalid year**\n");
					}
				} while (yearlyr < 2000 || yearlyr > 2024);
				int foundrydate = 0;
				printf("---------------------------\n");
				printf("| New staff yearly report |\n");
				printf("---------------------------\n\n");
				printf("                                               List of new joined staff at year of %d\n", yearlyr);
				printf("                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				printf("===================                                                                                                                  ================\n");
				printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
					time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
				printf("===================                                                                                                                  ================\n\n");
				staffHeader(1);
				for (int i = 0; i < scount; i++) {
					if (yearlyr == staffarr[i].date.year) {
						foundrydate = 1;
						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
						yearlyrcount++;
					}
				}
				staffHeader(0);
				if (foundrydate != 1) {
					printf("\n**Date < %d > no staff join**\n\n", yearlyr);
				}
				break;
			case 3:
				count = 0;
				//enter user id
				staffDisplay("manage");
				printf("Enter staff ID : ");
				rewind(stdin);
				scanf("%s", staffidr);

				int foundstaffidr = 0;
				totalCommission = 0;
				for (int i = 0; i < scount; i++) {
					if (strcmp(staffidr, staffarr[i].staffid) == 0) {
						printf("Personal commission report\n");
						printf("--------------------------\n\n");
						printf("                                                      '%s' personal commission report\n", staffidr);
						printf("                                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
						printf("===================                                                                                                                  ================\n");
						printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
							time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
						printf("===================                                                                                                                  ================\n\n");

						staffHeader(1);
						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
						staffHeader(0);
						foundstaffidr = 1;
						printf("\n");
						salesHeader();
						salesfile = fopen("salesOrder.txt", "r");

						while (fscanf(salesfile, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
							record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

							if (strcmp(record.staffId, staffidr) == 0) {

								printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
									record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day ,record.date.month, record.date.year, record.time, record.status);
								totalCommission += record.commission;
								count++;
							}
						}
						fclose(salesfile);
						printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
							"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
						printf("%69s%8.2f\n", "Total commission = RM", totalCommission);
						salesFooter(count);

						break;
					}
				}
				if (foundstaffidr != 1) {
					printf("\n**Staff ID '%s' not found**\n\n", staffidr);
				}
				break;
			case 4:
				break;
			default:
				printf("**Please enter valid choice.**\n");
				break;
			}

			if (choice != 4) {
				printf("View another report? ( Y = yes / N = no ) > ");
				rewind(stdin);
				scanf("%c", &anotherrchoice);
			}
			else {
				break;
			}
		} while (toupper(anotherrchoice) == 'Y' || choice != 4);
	}
	else if (strcmp(type, "self") == 0) {
		FILE* reportfile, * salesfile;
		SYSTEMTIME time;
		int scount = 0, count = 0;
		double totalCommission = 0.0;

		reportfile = fopen("staff.dat", "rb");
		if (reportfile == NULL) {
			printf("Error while opening the file\n");
			return -1;
		}

		while (fread(&staff, sizeof(staffs), 1, reportfile) != 0) {
			staffarr[scount] = staff;
			scount++;
		}
		fclose(reportfile);

		GetLocalTime(&time);

		for (int i = 0; i < scount; i++) {
			if (strcmp(current_staffId, staffarr[i].staffid) == 0) {

				printf("Personal commission report\n");
				printf("--------------------------\n\n");
				printf("                                                      '%s' personal commission report\n", current_staffId);
				printf("                                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

				printf("===================                                                                                                                  ================\n");
				printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
					time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
				printf("===================                                                                                                                  ================\n\n");

				staffHeader(1);
				printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
					staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				staffHeader(0);
				printf("\n");
				salesHeader();
				salesfile = fopen("salesOrder.txt", "r");

				while (fscanf(salesfile, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					if (strcmp(record.staffId, current_staffId) == 0) {
						
						printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
							record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
						totalCommission += record.commission;
						count++;
					}
				}
				fclose(salesfile);
				printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
					"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
				printf("%69s%8.2f\n", "Total commission = RM", totalCommission);
				salesFooter(count);
				break;
			}
		}
	}
}

void staffRestore() {
	FILE* restorefile, * addfile, * dltrestorefile, * clearfile;
	int scount = 0;
	char dltdstaffid[10];
	char confirmation;
	int i = 0, found = 0;
	staffs binstaff[10];
	int n = 0;
	int restorechoice;
	char confirmation2;

	restorefile = fopen("staffbin.dat", "rb");
	if (restorefile == NULL) {
		printf("Error while opening the file\n");
		exit(0);
	}
	//store deleted staff details into staff array
	while (fread(&staff, sizeof(staffs), 1, restorefile) != 0) {
		staffarr[scount] = staff;
		scount++;
	}

	do {
		printf("             Restore Menu\n");
		printf("=====================================\n");
		printf("| 1 - Restore deleted staff account |\n");
		printf("| 2 - Back                          |\n");
		printf("=====================================\n");
		printf("Enter your choice > ");
		scanf("%d", &restorechoice);
		switch (restorechoice) {
		case 1:
			printf("                                                                Deleted account list \n");
			printf("                                                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
			staffHeader(1);
			for (i = 0; i < scount; i++) {
				printf("%-10s%-25s%-8c%-35s%-10s%-20s%-15s%-15s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
					staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
			}
			staffHeader(0);

			printf("=================================\n");
			printf("| Restore deleted staff account |\n");
			printf("=================================\n");
			printf("Enter staff id to restore staff : ");
			rewind(stdin);
			scanf("%[^\n]", &dltdstaffid);
			//run whole array to check selected staff id
			for (i = 0; i < scount; i++) {
				if (strcmp(dltdstaffid, staffarr[i].staffid) == 0) {
					found = 1;
					break;
				}
			}
			//if staff id not found
			if (found != 1) {
				printf("**< %s > does not exist in bin file.**\n", dltdstaffid);
				break;
			}
			staffHeader(1);
			//prompt selected staff details
			for (i = 0; i < scount; i++) {
				if (strcmp(dltdstaffid, staffarr[i].staffid) == 0) {
					printf("%-10s%-25s%-8c%-35s%-10s%-20s%-15s%-15s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
				}
			}
			staffHeader(0);
			printf("\nConfirm restore this deleted staff account? ( Y = yes / N = no ) > ");
			rewind(stdin);
			scanf("%c", &confirmation);
			if (toupper(confirmation) == 'Y') {
				//append selected staff details back to staff file
				addfile = fopen("staff.dat", "ab");
				if (addfile == NULL) {
					printf("Error while opening the file\n");
					exit(0);
				}
				for (i = 0; i < scount; i++) {
					if (strcmp(dltdstaffid, staffarr[i].staffid) == 0) {
						fwrite(&staffarr[i], sizeof(staffs), 1, addfile);
						printf("Account had restore successfully!\n");
						fclose(addfile);
					}
					else {
						//copy the staff info that not selected by user based on deletedstaddid the a new array call binstaff
						binstaff[n] = staffarr[i];
						n++;
					}
				}

				dltrestorefile = fopen("staffbin.dat", "wb");
				if (dltrestorefile == NULL) {
					printf("Error while opening the file\n");
					return -1;
				}
				for (int i = 0; i < n; i++) {
					// write back the staff data that into the bin file that have to remain inside
					fwrite(&binstaff[i], sizeof(staffs), 1, dltrestorefile);
				}
				fclose(dltrestorefile);
			}
			else {
				printf("**Cancelled**\n");
			}
			break;
		case 2:
			break;
		default:
			printf("**Please enter valid input!**\n");
			break;
		}
	} while (restorechoice != 2);
}

void staffHeader(int type) {
	if (type == 1) {
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("%-10s%-25s%-8s%-30s%-20s%-15s%-20s%-10s%-10s\n", "Staff ID", "Name", "Gender", "Email", "Password", "Phone Number", "IC No", "Position", "Date Joined");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	else {
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

//Sales Information Module
//By: Yong Jia Ying
void salesOrder(char type[10]) {
	//one for member, one for staff
	if (strcmp(type, "member") == 0) {
		char repeat, confirmation, changes[100], order_staffid[10];
		int countSales = 0;

		FILE* fptr, * fptr2, * fptr3, * fptr4, * fptr5;
		fptr = fopen("salesOrder.txt", "r"); //to calculate number of current sales order
		fptr2 = fopen("salesOrder.txt", "a"); //to append new sales order
		fptr3 = fopen("salesBin.txt", "r"); //to calculate number of deleted sales order

		if (fptr == NULL || fptr2 == NULL) {
			printf("Error while opening \"salesOrder.txt\" file.\n");
			exit(1);
		}
		if (fptr3 == NULL) {
			printf("Error while opening \"salesBin.txt\" file.\n");
			exit(1);
		}

		//count number of current sales order
		while (fscanf(fptr, "%s %s %d %lf %s %s %lf %02d-%02d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {
			countSales++;
		}

		//count number of deleted sales order
		while (fscanf(fptr3, "%s %s %d %lf %s %s %lf %02d-%02d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {
			countSales++;
		}

		do {
			sprintf(record.orderId, "S%03d", countSales + 1); //current sales order id

			fptr5 = fopen("staff.dat", "rb");
			if (fptr5 == NULL) {
				printf("Error while opening the file.");
				exit(-1);
			}
			printf("\n%-10s %-20s\n", "Staff ID", "Name");
			printf("---------- --------------------\n");
			while (fread(&staff, sizeof(staffs), 1, fptr5) != 0) {
				printf("%-10s %-20s\n", staff.staffid, staff.name);
			}
			printf("---------- --------------------\n\n");

			int scheck = 0, valid = 0;
			do {
				printf("Staff ID (Upline) : ");
				rewind(stdin);
				scanf("%s", order_staffid);
				rewind(fptr5);
				//check if staff exists
				while (fread(&staff, sizeof(staffs), 1, fptr5) != 0) {
					if (strcmp(staff.staffid, order_staffid) == 0) {
						scheck = 1;
						break;
					}
				}
				if (scheck == 0) {
					printf("---Please enter a valid staff ID---\n\n");
				}
			} while (scheck != 1);
			fclose(fptr5);

			//prompt and get item code
			displayStock();
			do {
				printf("Item Code : ");
				scanf("%s", record.itemCode);
				rewind(stdin);
				valid = stockValidation(record.itemCode);
				if (valid == 0) {
					printf("---Please enter a valid item code---\n\n");
				}
			} while (valid != 1);

			//prompt and get quantity
			do {
				printf("Quantity (1-10): ");
				scanf("%d", &record.qty);
				rewind(stdin);
				if (record.qty <= 0 || record.qty > 10) {
					printf("---Please enter quantity within 1 to 10---\n\n");
				}
			} while (record.qty <= 0 || record.qty > 10);

			//confirmation to place order
			printf("Confirm to place order? (Y = yes) > ");
			scanf("%c", &confirmation);
			rewind(stdin);
			printf("\n");

			if (toupper(confirmation) == 'Y') {
				//read stock file to get item price
				fptr4 = fopen("stock.txt", "r");
				if (fptr4 == NULL) {
					printf("Error while opening \"stock.txt\" file.\n");
					exit(1);
				}

				//calculate total Price
				while (fscanf(fptr4, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
					item.itemCode, item.itemName, item.itemCategory, &item.itemPrice, &item.quantity.qtyInStock, &item.quantity.minLvl, &item.quantity.reorderQty) != EOF) {
					if (strcmp(item.itemCode, record.itemCode) == 0) {
						record.price = (double)record.qty * item.itemPrice;
					}
				}

				//calculate commission
				record.commission = record.price * 0.05;

				fclose(fptr4);

				//get current time
				SYSTEMTIME t;
				GetLocalTime(&t);
				record.date.day = t.wDay;
				record.date.month = t.wMonth;
				record.date.year = t.wYear;
				sprintf(record.time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);

				//append sales order into file
				fprintf(fptr2, "%s %s %d %.2f %s %s %.2f %02d-%02d-%d %s %s\n",
					record.orderId, record.itemCode, record.qty, record.price, current_memberId, order_staffid, record.commission, record.date.day, record.date.month, record.date.year, record.time, "Pending");

				//prompt info to user
				salesHeader();
				printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
					record.orderId, record.itemCode, record.qty, record.price, current_memberId, order_staffid, record.commission, record.date.day, record.date.month, record.date.year, record.time, "Pending");
				salesFooter(1);

				reorderStock(record.itemCode, record.qty);
				printf("---Order ID '%s' is successfully added---\n\n", record.orderId);
				sprintf(changes, "Order ID '%s' is added.", record.orderId);
				changeLog(changes, current_memberId);
				countSales++;
			}
			else {
				printf("---Order Declined---\n\n");
			}

			//confirmation to repeat order
			printf("Order again? (Y = yes) > ");
			scanf("%c", &repeat);
			rewind(stdin);
			printf("\n");

		} while (toupper(repeat) == 'Y');

		fclose(fptr);
		fclose(fptr2);
	}
	else if (strcmp(type, "staff") == 0) {
		char repeat, confirmation, changes[100], order_memberid[10];
		int countSales = 0;

		FILE* fptr, * fptr2, * fptr3, * fptr4, * fptr5;
		fptr = fopen("salesOrder.txt", "r"); //to calculate number of current sales order
		fptr2 = fopen("salesOrder.txt", "a"); //to append new sales order
		fptr3 = fopen("salesBin.txt", "r"); //to calculate number of deleted sales order

		if (fptr == NULL || fptr2 == NULL) {
			printf("Error while opening \"salesOrder.txt\" file.\n");
			exit(1);
		}
		if (fptr3 == NULL) {
			printf("Error while opening \"salesBin.txt\" file.\n");
			exit(1);
		}

		//count number of current sales order
		while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {
			countSales++;
		}

		//count number of deleted sales order
		while (fscanf(fptr3, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {
			countSales++;
		}

		do {
			sprintf(record.orderId, "S%03d", countSales + 1); //current sales order id

			fptr5 = fopen("member.dat", "rb");
			if (fptr5 == NULL) {
				printf("Error while opening the file.");
				exit(-1);
			}

			printf("\n%-10s %-20s\n", "MemberID", "Name");
			printf("---------- --------------------\n");
			while (fread(&m, sizeof(Member), 1, fptr5) != 0) {
				printf("%-10s %-20s\n", m.memberID, m.memberName);
			}
			printf("---------- --------------------\n\n");

			int mcheck = 0, valid = 0;
			do {

				printf("Member ID : ");
				rewind(stdin);
				scanf("%s", order_memberid);
				rewind(fptr5);
				while (fread(&m, sizeof(Member), 1, fptr5) != 0) {
					if (strcmp(m.memberID, order_memberid) == 0) {
						mcheck = 1;
						break;
					}
				}
				if (mcheck == 0) {
					printf("---Please enter a valid member ID---\n\n");
				}
			} while (mcheck != 1);
			fclose(fptr5);
					
			//prompt and get item code
			displayStock();
			do {
				printf("Item Code : ");
				scanf("%s", record.itemCode);
				rewind(stdin);
				valid = stockValidation(record.itemCode);
				if (valid == 0) {
					printf("---Please enter a valid item code---\n\n");
				}
			} while (valid != 1);

			//prompt and get quantity
			do {
				printf("Quantity (1-10): ");
				scanf("%d", &record.qty);
				rewind(stdin);
				if (record.qty <= 0 || record.qty > 10) {
					printf("---Please enter quantity within 1 to 10---\n\n");
				}
			} while (record.qty <= 0 || record.qty > 10);

			//confirmation to place order
			printf("Confirm to place order? (Y = yes) > ");
			scanf("%c", &confirmation);
			rewind(stdin);
			printf("\n");

			if (toupper(confirmation) == 'Y') {

				//read stock file to get item price
				fptr4 = fopen("stock.txt", "r");
				if (fptr4 == NULL) {
					printf("Error while opening \"stock.txt\" file.\n");
					exit(1);
				}

				//calculate total Price
				while (fscanf(fptr4, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
					item.itemCode, item.itemName, item.itemCategory, &item.itemPrice, &item.quantity.qtyInStock, &item.quantity.minLvl, &item.quantity.reorderQty) != EOF) {
					if (strcmp(item.itemCode, record.itemCode) == 0) {
						record.price = (double)record.qty * item.itemPrice;
					}
				}

				//calculate commission
				record.commission = record.price * 0.05;

				fclose(fptr4);

				//get current time
				SYSTEMTIME t;
				GetLocalTime(&t);
				record.date.day = t.wDay;
				record.date.month = t.wMonth;
				record.date.year = t.wYear;
				sprintf(record.time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);

				//append sales order into file
				fprintf(fptr2, "%s %s %d %.2f %s %s %.2f %02d-%02d-%d %s %s\n",
					record.orderId, record.itemCode, record.qty, record.price, order_memberid, current_staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, "Pending");

				//prompt info to user
				salesHeader();
				printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
					record.orderId, record.itemCode, record.qty, record.price, order_memberid, current_staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, "Pending");
				salesFooter(1);

				reorderStock(record.itemCode, record.qty);
				printf("---Order ID '%s' is successfully added---\n\n", record.orderId);
				sprintf(changes, "Order ID '%s' is added.", record.orderId);
				changeLog(changes, current_staffId);
				countSales++;
			}
			else {
				printf("---Order Declined---\n\n");
			}

			//confirmation to repeat order
			printf("Order again? (Y = yes) > ");
			scanf("%c", &repeat);
			rewind(stdin);
			printf("\n");

		} while (toupper(repeat) == 'Y');

		fclose(fptr);
		fclose(fptr2);
	}
}

void salesSearch(char type[10]) {
	int count = 0, choice, statusChoice;
	char orderId[5], itemCode[10], memberId[10], staffId[10], status[10];

	FILE* fptr;
	fptr = fopen("salesOrder.txt", "r"); //to search specific sales order

	if (fptr == NULL) {
		printf("Error while opening \"salesOrder.txt\" file.\n");
		exit(1);
	}

	if (strcmp(type, "manage") == 0) {
		do {
			count = 0;
			//prompt and get field to search
			printf("Field to Search: \n");
			printf("========================\n");
			printf("| 1. Order ID          |\n");
			printf("| 2. Item Code         |\n");
			printf("| 3. Member ID         |\n");
			printf("| 4. Staff ID          |\n");
			printf("| 5. Status            |\n");
			printf("| 6. Back              |\n");
			printf("========================\n");

			printf("Select > ");
			scanf("%d", &choice);
			printf("\n");

			switch (choice) {
			case 1:
				salesDisplay();
				//search by sales order id
				printf("Search by Sales Order ID : ");
				scanf("%s", orderId);
				rewind(stdin);

				salesHeader();
				rewind(fptr);
				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					if (strcmp(record.orderId, orderId) == 0) {

						printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
							record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
						count++;
					}
				}
				salesFooter(count);
				break;
			case 2:
				displayStock();
				//search by item code
				printf("Search by Item Code : ");
				scanf("%s", itemCode);
				rewind(stdin);

				salesHeader();
				rewind(fptr);
				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					if (strcmp(record.itemCode, itemCode) == 0) {

						printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
							record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
						count++;
					}
				}
				salesFooter(count);
				break;
			case 3:
				memberDisplay("manage");
				//search by member id
				printf("Search by Member ID : ");
				scanf("%s", memberId);
				rewind(stdin);

				salesHeader();
				rewind(fptr);
				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					if (strcmp(record.memberId, memberId) == 0) {

						printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
							record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
						count++;
					}
				}
				salesFooter(count);
				break;
			case 4:
				staffDisplay("manage");
				//search by staff id
				printf("Search by Staff ID : ");
				scanf("%s", staffId);
				rewind(stdin);

				salesHeader();
				rewind(fptr);
				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					if (strcmp(record.staffId, staffId) == 0) {

						printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
							record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
						count++;
					}
				}
				salesFooter(count);
				break;
			case 5:
				//search by status
				printf("Search by Status : \n");
				printf("=================\n");
				printf("|1. Pending     |\n");
				printf("|2. Shipping    |\n");
				printf("|3. Completed   |\n");
				printf("=================\n");
				do {
					printf("Status > ");
					scanf("%d", &statusChoice);
					rewind(stdin);
					if (statusChoice < 1 || statusChoice > 3) {
						printf("---Please select between 1 to 3---\n\n");
					}
					else if (statusChoice == 1) {
						strcpy(status, "Pending");
					}
					else if (statusChoice == 2) {
						strcpy(status, "Shipping");
					}
					else if (statusChoice == 3) {
						strcpy(status, "Completed");
					}
				} while (statusChoice < 1 || statusChoice > 3);

				salesHeader();
				rewind(fptr);
				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					if (strcmp(record.status, status) == 0) {

						printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
							record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
						count++;
					}
				}
				salesFooter(count);
				break;
			case 6:
				break;
			default:
				printf("---Please select between 1 to 6---\n\n");
			}
		} while (choice != 6);
		fclose(fptr);
	}
	else if (strcmp(type, "self") == 0) {

		salesHeader();
		while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

			if (strcmp(record.memberId, current_memberId) == 0) {

				printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
					record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
				count++;
			}
		}
		salesFooter(count);
		fclose(fptr);
	}
}

void salesModify() {
	int i = 0, choice, choiceStatus, found = 0, valid = 0;
	char orderId[5], changes[100], field[10], confirmation = 'N';
	Sales original;
	Sales modified[100];

	FILE* fptr, * fptr2, * fptr3;
	fptr = fopen("salesOrder.txt", "r"); //to validate

	if (fptr == NULL) {
		printf("Error while opening \"salesOrder.txt\" file.\n");
		exit(1);
	}

	salesDisplay();

	//prompt and get order id to modify
	do {
		printf("Enter Order ID to modify : ");
		scanf("%s", orderId);
		found = salesValidation(orderId);
		if (found != 1) {
			printf("---Please enter a valid order ID---\n\n");
		}
	} while (found != 1);

	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

		if (strcmp(record.orderId, orderId) != 0) {

			//copy non-modified value to modified array
			modified[i] = record;
			i++;
		}
		else if (strcmp(record.orderId, orderId) == 0) {
			//copy original array for prompt info purpose
			original = record;

			//prompt selected sales order
			salesHeader();
			printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
				record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
			salesFooter(1);

			do {
				//prompt menu of field to modify
				printf("Field to Modify: \n");
				printf("===================\n");
				printf("|1. Item Code     |\n");
				printf("|2. Quantity      |\n");
				printf("|3. Status        |\n");
				printf("|4. Back          |\n");
				printf("===================\n");
				printf("Select > ");
				scanf("%d", &choice);
				printf("\n");

				//get modified value
				switch (choice) {
				case 1:
					displayStock();
					do {
						printf("New item code : ");
						scanf("%s", record.itemCode);
						strcpy(field, "item code");
						valid = stockValidation(record.itemCode);
						if (valid != 1) {
							printf("---Please enter a valid item code---\n\n");
						}
					} while (valid != 1);
					break;
				case 2:
					do {
						printf("New Quantity (1-10) : ");
						scanf("%d", &record.qty);
						if (record.qty < 1 || record.qty > 10)
							printf("---Please enter between 1 to 10---\n\n");
					} while (record.qty < 1 || record.qty > 10);
					strcpy(field, "quantity");
					break;
				case 3:
					printf("     Status\n");
					printf("=================\n");
					printf("|1. Pending     |\n");
					printf("|2. Shipping    |\n");
					printf("|3. Completed   |\n");
					printf("=================\n");

					do {
						printf("New Status > ");
						scanf("%d", &choiceStatus);
						if (choiceStatus < 1 || choiceStatus > 3) {
							printf("---Please select between 1 to 3---\n\n");
						}
						else if (choiceStatus == 1) {
							strcpy(record.status, "Pending");
						}
						else if (choiceStatus == 2) {
							strcpy(record.status, "Shipping");
						}
						else if (choiceStatus == 3) {
							strcpy(record.status, "Completed");
						}
					} while (choiceStatus < 1 || choiceStatus > 3);

					strcpy(field, "status");
					break;
				case 4:
					break;
				default:
					printf("---Please select between 1 to 4---\n\n");
					break;
				}
			} while (choice < 1 || choice > 4);

			if (choice >= 1 && choice <= 3) {
				rewind(stdin);
				printf("Confirm to modify (Y = yes) ? > ");
				scanf("%c", &confirmation);
				rewind(stdin);


				if (toupper(confirmation) == 'Y') {
					//read product file
					fptr2 = fopen("stock.txt", "r");
					if (fptr2 == NULL) {
						printf("Error while opening \"stock.txt\" file.\n");
						exit(1);
					}

					//get item price to calculate price
					while (fscanf(fptr2, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
						item.itemCode, item.itemName, item.itemCategory, &item.itemPrice, &item.quantity.qtyInStock, &item.quantity.minLvl, &item.quantity.reorderQty) != EOF) {
						if (strcmp(item.itemCode, record.itemCode) == 0) {
							record.price = (double)record.qty * item.itemPrice;
						}
					}

					record.commission = record.price * 0.05; //calculate commission
					fclose(fptr2);

					//copy modified value to modidified array
					modified[i] = record;
					i++;

					printf("Record before modification : \n");
					salesHeader();
					printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
						original.orderId, original.itemCode, original.qty, original.price, original.memberId, original.staffId, original.commission, original.date.day, original.date.month, original.date.year, original.time, original.status);
					printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n\n",
						"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");

					//append changes to change log
					if (strcmp("item code", field) == 0) {
						printf("---Order ID '%s', %s is modified to '%s'---\n\n", orderId, field, record.itemCode);
						sprintf(changes, "Order ID '%s', %s is modified to '%s'.", orderId, field, record.itemCode);
					}
					else if (strcmp("quantity", field) == 0) {
						printf("---Order ID '%s', %s is modified to '%d'---\n\n", orderId, field, record.qty);
						sprintf(changes, "Order ID '%s', %s is modified to '%d'.", orderId, field, record.qty);
					}
					else if (strcmp("status", field) == 0) {
						printf("---Order ID '%s', %s is modified to '%s'---\n\n", orderId, field, record.status);
						sprintf(changes, "Order ID '%s', %s is modified to '%s'.", orderId, field, record.status);
					}
					changeLog(changes, current_staffId);

					printf("Record after modification : \n");
					salesHeader();
					printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
					printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n\n",
						"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");

				}
				else {
					printf("---No changes made---\n\n");
				}
			}
		}
	}

	if (toupper(confirmation) == 'Y') {
		fptr3 = fopen("salesOrder.txt", "w");
		if (fptr3 == NULL) {
			printf("Error while opening \"salesOrder.txt\" file.\n");
			exit(1);
		}

		//write modified sales order to file
		for (int n = 0; n < i; n++) {
			fprintf(fptr3, "%s %s %d %.2f %s %s %.2f %02d-%02d-%d %s %s\n",
				modified[n].orderId, modified[n].itemCode, modified[n].qty, modified[n].price, modified[n].memberId, modified[n].staffId, modified[n].commission,
				modified[n].date.day, modified[n].date.month, modified[n].date.year, modified[n].time, modified[n].status);
		}
		printf("---Successfully modified---\n\n");
		fclose(fptr3);
	}

	fclose(fptr);
}

void salesDisplay() {
	int count = 0;
	FILE* fptr;
	fptr = fopen("salesOrder.txt", "r"); //to get all sales order

	if (fptr == NULL) {
		printf("Error while opening \"salesOrder.txt\" file.\n");
		exit(1);
	}

	salesHeader();

	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

		//display all sales order		
		printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
			record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
		count++;
	}

	salesFooter(count);
	fclose(fptr);
}

void salesDelete() {
	int i = 0, found = 0;
	char orderId[5], confirmation, changes[100];
	Sales modified[100], delete;

	FILE* fptr, * fptr2, * fptr3;
	fptr = fopen("salesOrder.txt", "r"); //to validate
	fptr2 = fopen("salesBin.txt", "a"); //to append deleted sales order

	salesDisplay();
	printf("Enter Order ID to delete : ");
	rewind(stdin);
	scanf("%s", orderId);
	rewind(stdin);
	printf("\n");

	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

		//record orderId not equal to input orderId save to modified array
		if (strcmp(record.orderId, orderId) != 0) {
			modified[i] = record;
			i++;
		}
		//selected order id save to bin file
		else if (strcmp(record.orderId, orderId) == 0) {
			delete = record;
			found = 1;
		}
	}

	rewind(fptr);
	if (found == 1) {
		while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {
			if (strcmp(record.orderId, orderId) == 0) {
				//show selected sales record
				salesHeader();
				printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
					record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
				salesFooter(1);

				//confirmation to delete
				printf("Are you sure to delete this sales order? (Y : yes) > ");
				scanf("%c", &confirmation);
				rewind(stdin);

				if (toupper(confirmation) == 'Y') {
					fprintf(fptr2, "%s %s %d %.2f %s %s %.2f %d-%d-%d %s %s\n",
						delete.orderId, delete.itemCode, delete.qty, delete.price, delete.memberId, delete.staffId, delete.commission, delete.date.day, delete.date.month, delete.date.year, delete.time, delete.status);

					//write modified array back to sales file
					fptr3 = fopen("salesOrder.txt", "w");
					for (int n = 0; n < i; n++) {
						fprintf(fptr3, "%s %s %d %.2f %s %s %.2f %d-%d-%d %s %s\n",
							modified[n].orderId, modified[n].itemCode, modified[n].qty, modified[n].price, modified[n].memberId, modified[n].staffId, modified[n].commission,
							modified[n].date.day, modified[n].date.month, modified[n].date.year, modified[n].time, modified[n].status);
					}
					printf("---Order ID '%s' is deleted---\n\n", orderId);
					sprintf(changes, "Order ID '%s' is deleted.", orderId);
					changeLog(changes, current_staffId);
					fclose(fptr3);
				}
				else {
					printf("---Delete Unsuccessful---\n\n");
				}
			}
		}
	}
	else {
		printf("---Order ID not found---\n\n");
	}
	fclose(fptr);
	fclose(fptr2);
}

void salesReport() {
	int count = 0, type, summary;
	int in_year, in_month, in_day; //input
	char title[20], cat;
	int code;
	int cFood, cDrink, cShirt, cPants, cShoes; //count of sales order
	int nFood, nDrink, nShirt, nPants, nShoes; //number of quantity sold
	double tFood, tDrink, tShirt, tPants, tShoes; //total price

	do {
		FILE* fptr;
		fptr = fopen("salesOrder.txt", "r");

		if (fptr == NULL) {
			printf("Error while opening \"salesOrder.txt\" file.\n");
			exit(1);
		}

		//prompt and get type of report
		printf("Types of report: \n");
		printf("=================================\n");
		printf("| 1. Summary Sales Report       |\n");
		printf("| 2. Categorized Sales Report   |\n");
		printf("| 3. Back                       |\n");
		printf("=================================\n");
		printf("Select > ");
		scanf("%d", &type);
		printf("\n");

		switch (type) {
		case 1:
			do {
				count = 0;
				double totalSales = 0, totalCommission = 0;
				//prompt and get type of summary report
				printf("Types of summary report: \n");
				printf("============================\n");
				printf("| 1. Yearly Sales Report   |\n");
				printf("| 2. Monthly Sales Report  |\n");
				printf("| 3. Daily Sales Report    |\n");
				printf("| 4. Back                  |\n");
				printf("============================\n");

				printf("Select > ");
				scanf("%d", &summary);
				printf("\n");

				switch (summary) {
				case 1:
					//Yearly Sales Report
					printf("Enter Year : ");
					scanf("%d", &in_year);
					rewind(stdin);
					printf("\n");

					reportHeader("Yearly", in_year, NULL, NULL);

					rewind(fptr);
					while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

						if (in_year == record.date.year) {

							printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
								record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
							totalSales += record.price;
							totalCommission += record.commission;
							count++;
						}
					}
					printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
						"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
					printf("%35s%9.2f %24s%8.2f\n", "Total sales = RM", totalSales, "Total commission = RM", totalCommission);
					salesFooter(count);

					break;
				case 2:
					//Monthly Sales Report
					printf("Enter Year : ");
					scanf("%d", &in_year);
					rewind(stdin);
					printf("Enter Month (1-12) : ");
					scanf("%d", &in_month);
					rewind(stdin);

					reportHeader("Monthly", in_year, in_month, NULL);

					rewind(fptr);
					while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

						if (in_year == record.date.year && in_month == record.date.month) {

							printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
								record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
							totalSales += record.price;
							totalCommission += record.commission;
							count++;
						}
					}
					printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
						"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
					printf("%35s%9.2f %24s%8.2f\n", "Total sales = RM", totalSales, "Total commission = RM", totalCommission);
					salesFooter(count);

					break;
				case 3:
					//Daily Sales Report
					printf("Enter Year : ");
					scanf("%d", &in_year);
					rewind(stdin);
					printf("Enter Month (1-12) : ");
					scanf("%d", &in_month);
					rewind(stdin);
					printf("Enter Day   (1-31) : ");
					scanf("%d", &in_day);
					rewind(stdin);

					reportHeader("Daily", in_year, in_month, in_day);

					rewind(fptr);
					while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

						if (in_year == record.date.year && in_month == record.date.month && in_day == record.date.day) {

							printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
								record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
							totalSales += record.price;
							totalCommission += record.commission;
							count++;
						}
					}
					printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
						"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
					printf("%35s%9.2f %24s%8.2f\n", "Total sales = RM", totalSales, "Total commission = RM", totalCommission);
					salesFooter(count);

					break;
				case 4:
					break;
				default:
					printf("---Please select between 1 to 4---\n\n");
				}
			} while (summary != 4);
			break;
		case 2:
			cFood = cDrink = cShirt = cPants = cShoes = 0;
			nFood = nDrink = nShirt = nPants = nShoes = 0;
			tFood = tDrink = tShirt = tPants = tShoes = 0;
			double totalSales = 0;

			rewind(fptr);
			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

				sscanf(record.itemCode, "%c%d", &cat, &code);
				if (cat == 'A') {
					cFood++;
					nFood += record.qty;
					tFood += record.price;
				}
				else if (cat == 'B') {
					cDrink++;
					nDrink += record.qty;
					tDrink += record.price;
				}
				else if (cat == 'C') {
					cShirt++;
					nShirt += record.qty;
					tShirt += record.price;
				}
				else if (cat == 'D') {
					cPants++;
					nPants += record.qty;
					tPants += record.price;
				}
				else if (cat == 'E') {
					cShoes++;
					nShoes += record.qty;
					tShoes += record.price;
				}
				totalSales += record.price;
			}

			reportHeader("Categorized", NULL, NULL, NULL);
			
			printf("%-10s %-15s %-16s %-15s %-12s\n", "----------", "---------------", "----------------", "---------------", "------------");
			printf("%-10s %-15s %-16s %-15s %-12s\n", "Item Code", "Category", "Number of sales", "Quantity sold", "Total Price");
			printf("%-10s %-15s %-16s %-15s %-12s\n", "----------", "---------------", "----------------", "---------------", "------------");
			printf("%-10s %-15s %-16d %-15d %-2s%10.2f\n", "A", "Food", cFood, nFood, "RM", tFood);
			printf("%-10s %-15s %-16d %-15d %-2s%10.2f\n", "B", "Drink", cDrink, nDrink, "RM", tDrink);
			printf("%-10s %-15s %-16d %-15d %-2s%10.2f\n", "C", "Shirt", cShirt, nShirt, "RM", tShirt);
			printf("%-10s %-15s %-16d %-15d %-2s%10.2f\n", "D", "Pants", cPants, nPants, "RM", tPants);
			printf("%-10s %-15s %-16d %-15d %-2s%10.2f\n", "E", "Shoes", cShoes, nShoes, "RM", tShoes);
			printf("%-10s %-15s %-16s %-15s %-12s\n", "----------", "---------------", "----------------", "---------------", "------------");
			printf("%62s%10.2f\n", "Total sales = RM", totalSales);
			printf("%-10s %-15s %-16s %-15s %-12s\n\n", "----------", "---------------", "----------------", "---------------", "------------");
			break;
		case 3:
			break;
		default:
			printf("---Please select between 1 to 3---\n\n");
		}
		fclose(fptr);
	} while (type != 3);
}

void salesRestore() {
	int i = 0, n = 0, count = 0, once = 0, found = 0;
	int restore_orderId, record_orderId;
	char orderId[5], changes[100], confirmation;
	Sales deleted[50];
	Sales restore;
	Sales modified[50];

	FILE* fptr, * fptr2, * fptr3, * fptr4;
	fptr = fopen("salesBin.txt", "r"); //to get all delete history log and validation
	if (fptr == NULL) {
		printf("Error while opening \"salesBin.txt\" file.\n");
		exit(1);
	}

	//display delete history log
	printf("Sales Order Delete History Log\n");
	salesHeader();
	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

		printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
			record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
		count++;
	}
	salesFooter(count);
	rewind(fptr);

	if (count > 0) {
		printf("Restore by Sales Order ID : ");
		scanf("%s", orderId);
		rewind(stdin);

		while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

			if (strcmp(record.orderId, orderId) == 0) {

				fseek(fptr, 0, SEEK_SET);
				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

					//record orderId not equal to input orderId save to deleted array
					if (strcmp(record.orderId, orderId) != 0) {
						deleted[i] = record;
						i++;
					}
					//record orderId equal to input orderId copy to sturcture
					else if (strcmp(record.orderId, orderId) == 0) {
						restore = record;
					}
				}

				fclose(fptr);

				fptr2 = fopen("salesOrder.txt", "r"); //to validate
				if (fptr2 == NULL) {
					printf("Error while opening \"salesOrder.txt\" file.\n");
					exit(1);
				}

				//confirmation to delete
				printf("Are you sure to restore this sales order? (Y = yes) > ");
				scanf("%c", &confirmation);
				rewind(stdin);

				if (toupper(confirmation) == 'Y') {

					sscanf(restore.orderId, "S%d", &restore_orderId);

					while (fscanf(fptr2, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

						sscanf(record.orderId, "S%d", &record_orderId);

						//reallocate the sequence of order ID
						if (record_orderId < restore_orderId) {
							modified[n] = record;
							n++;
						}
						else if (record_orderId > restore_orderId) {
							if (once == 0) {
								modified[n] = restore;
								once++;
								n++;

								modified[n] = record;
							}
							else {
								modified[n] = record;
							}
							n++;
						}
					}
					fclose(fptr2);

					//write modified sales order to file
					fptr3 = fopen("salesOrder.txt", "w");
					if (fptr3 == NULL) {
						printf("Error while opening \"salesOrder.txt\" file.\n");
						exit(1);
					}

					for (int m = 0; m < n; m++) {
						fprintf(fptr3, "%s %s %d %.2f %s %s %.2f %02d-%02d-%d %s %s\n",
							modified[m].orderId, modified[m].itemCode, modified[m].qty, modified[m].price, modified[m].memberId, modified[m].staffId, modified[m].commission,
							modified[m].date.day, modified[m].date.month, modified[m].date.year, modified[m].time, modified[m].status);
					}
					printf("---Order ID '%s' is restored---\n\n", restore.orderId);
					sprintf(changes, "Order ID '%s' is restored.", restore.orderId);
					changeLog(changes, current_staffId);
					fclose(fptr3);

					fptr4 = fopen("salesBin.txt", "w");
					if (fptr4 == NULL) {
						printf("Error while opening \"salesOrder.txt\" file.\n");
						exit(1);
					}

					for (int n = 0; n < i; n++) {
						fprintf(fptr4, "%s %s %d %.2f %s %s %.2f %02d-%02d-%d %s %s\n",
							deleted[n].orderId, deleted[n].itemCode, deleted[n].qty, deleted[n].price, deleted[n].memberId, deleted[n].staffId, deleted[n].commission,
							deleted[n].date.day, deleted[n].date.month, deleted[n].date.year, deleted[n].time, deleted[n].status);
					}
					fclose(fptr4);
				}
				else {
					printf("---Restore Unsuccessful---\n\n");
				}
				found = 1;
			}
		}
		if (found != 1) {
			printf("---Order ID not found---\n\n");
		}
	}
	else {
		printf("---Nothing to restore---\n\n");
	}
}

void changeLog(char changes[100], char id[10]) {
	char date[11], time[10];
	FILE* fptr;
	fptr = fopen("salesLog.txt", "a"); //to append changes

	if (fptr == NULL) {
		printf("Error while opening 'salesLog.txt' file.\n");
		exit(1);
	}

	//get current date and time 
	SYSTEMTIME t;
	GetLocalTime(&t);
	sprintf(date, "%02d-%02d-%02d", t.wDay, t.wMonth, t.wYear);
	sprintf(time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);

	fprintf(fptr, "%s | %s | %s | %s \n", changes, id, date, time); //append changes into change log file

	fclose(fptr);
}

void displayLog() {
	int type, count = 0;
	char log[100], id[10], date[11], time[9];
	FILE* fptr, * fptr2;
	fptr = fopen("salesLog.txt", "r"); //to get all change log
	fptr2 = fopen("salesBin.txt", "r"); //to get all deleted sales order

	if (fptr == NULL) {
		printf("Error while opening 'salesLog.txt' file.\n");
		exit(1);
	}
	if (fptr2 == NULL) {
		printf("Error while opening 'salesOrder.txt' file.\n");
		exit(1);
	}

	do {
		//prompt and get type of log
		printf("Types of Log: \n");
		printf("===========================\n");
		printf("| 1. Change Log           |\n");
		printf("| 2. Delete History Log   |\n");
		printf("| 3. Back                 |\n");
		printf("===========================\n");
		printf("Select > ");
		scanf("%d", &type);
		printf("\n");

		switch (type) {
		case 1:
			//change log
			printf("%-55s %-10s %7s %9s\n", "Sales Order Change Log", "ID", "Date", "Time");
			printf("------------------------------------------------------- ---------- ---------- --------\n");
			while (fscanf(fptr, "%[^\|] | %s | %s | %s \n", log, id, date, time) != EOF) {

				//display change log
				printf("%-55s %-10s %s %s\n", log, id, date, time);
			}

			printf("\n");
			break;
		case 2:
			//delete history log
			printf("Sales Order Delete History Log\n");
			salesHeader();
			while (fscanf(fptr2, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

				//display deleted sales order
				printf("%-10s %-10s %-10d RM%9.2f %-10s %-10s RM%8.2f %02d-%02d-%d %-10s %-10s\n",
					record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date.day, record.date.month, record.date.year, record.time, record.status);
				count++;
			}
			salesFooter(count);
			printf("\n");
			break;
		case 3:
			break;
		default:
			printf("---Please select between 1 to 3---\n\n");
			break;
		}
	} while (type != 3);

	fclose(fptr);
}

void salesHeader() {
	//display header
	printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
		"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
	printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
		"Order ID", "Item Code", "Quantity", "Price", "Member ID", "Staff ID", "Commission", "Order Date", "Order Time", "Status");
	printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
		"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
}

void salesFooter(int c) {
	//display footer
	printf("%-10s %-10s %-10s %-11s %-10s %-10s %-10s %-10s %-10s %-10s\n",
		"==========", "==========", "==========", "===========", "==========", "==========", "==========", "==========", "==========", "==========");
	printf("< ");
	if (c == 0) {
		printf("No record found.");
	}
	else if (c == 1) {
		printf("%d record listed.", c);
	}
	else if (c > 1) {
		printf("%d records listed.", c);
	}
	else {
		printf("Error.");
	}
	printf(" >\n\n");
}

void reportHeader(char type[10], int year, int month, int day) {
	//display report header
	char current_date[11], current_time[9], staffName[30];

	SYSTEMTIME t;
	GetLocalTime(&t);
	sprintf(current_date, "%02d-%02d-%04d", t.wDay, t.wMonth, t.wYear);
	sprintf(current_time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);

	if (strcmp("Yearly", type) == 0) {
		printf("\n-------------------------------------------- %s Sales Report --------------------------------------------\n", type);
		printf("%53s , %d\n", "Year", year);
	}
	else if (strcmp("Monthly", type) == 0) {
		printf("\n------------------------------------------- %s Sales Report --------------------------------------------\n", type);
		printf("%51s , %02d-%d\n", "Month", month, year);
	}
	else if (strcmp("Daily", type) == 0) {
		printf("\n--------------------------------------------- %s Sales Report ---------------------------------------------\n", type);
		printf("%50s , %02d-%02d-%d\n", "Day", day, month, year);
	}
	else if (strcmp("Categorized", type) == 0) {
		printf("\n----------------------- %s Sales Report -----------------------\n", type);
	}
	printf("Staff ID: %s\n", current_staffId);

	FILE* fptr;
	fptr = fopen("staff.dat", "rb");
	if (fptr == NULL) {
		printf("Error while opening \"staff.dat\" file.\n");
		exit(-1);
	}
	while (fread(&staff, sizeof(staffs), 1, fptr) != 0) {
		if (strcmp(staff.staffid, current_staffId) == 0) {
			strcpy(staffName, staff.name);
			break;
		}
	}
	fclose(fptr);

	printf("Staff Name: %s\n", staffName);

	if (strcmp("Categorized", type) != 0) {
		printf("Date: %s %77s Time: %s\n\n", current_date, " ", current_time);
		salesHeader();
	}
	else {
		printf("Date: %s %40s Time: %s\n\n", current_date, " ", current_time);
	}
}

int salesValidation(char orderId[5]) {
	FILE* fptr;
	fptr = fopen("salesOrder.txt", "r"); //to validate
	if (fptr == NULL) {
		printf("Error while opening \"salesOrder.txt\" file.\n");
		exit(1);
	}

	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %d-%d-%d %s %s",
		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, &record.date.day, &record.date.month, &record.date.year, record.time, record.status) != EOF) {

		//validate if order id exist
		if (strcmp(record.orderId, orderId) == 0) {
			return 1;  //true
		}
	}
	return 0; //false
}

int stockValidation(char itemCode[5]) {
	FILE* fptr;
	fptr = fopen("stock.txt", "r"); //to validate
	if (fptr == NULL) {
		printf("Error while opening \"stock.txt\" file.\n");
		exit(1);
	}

	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
		item.itemCode, item.itemName, item.itemCategory, &item.itemPrice, &item.quantity.qtyInStock, &item.quantity.minLvl, &item.quantity.reorderQty) != EOF) {

		//validate if item code exist
		if (strcmp(item.itemCode, itemCode) == 0) {
			fclose(fptr);
			return 1; //found
		}
	}
	fclose(fptr);
	return 0; //not found
}

//Stock Information Module
//By: Kong Weng Cheng
void addStock() {
	char ans2, ans;
	int count = 0, i = 0, cat;

	FILE* stock;
	stock = fopen("stock.txt", "a"); //to store the new stock records

	if (stock == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	printf("\nAdd Stock Record Function");
	printf("\n=========================\n");

	do {
		do {
			FILE* check;
			check = fopen("stock.txt", "r");//to check the 

			if (check == NULL) {
				printf("Error while opening the file");
				exit(-1);
			}

			//store in a array as a record
			while (fscanf(check, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
				store[i].itemCode, store[i].itemName, store[i].itemCategory, &store[i].itemPrice, &store[i].quantity.qtyInStock, &store[i].quantity.minLvl, &store[i].quantity.reorderQty) != EOF) {
				i++;
			}

			printf("Enter Item Code > ");
			rewind(stdin);
			scanf("%s", records.itemCode);

			//check whether the item code is exist in the array
			for (int n = 0; n < i; n++) {
				if (strcmp(records.itemCode, store[n].itemCode) == 0) {
					printf("Stock %s has been added. Please retry.\n", records.itemCode);
					v = 'I';
					n = i;
				}
				else {
					v = 'V';
				}
			}
			fclose(check);
			//update the value of i back to original
			i = 0;
		} while (v == 'I');

		printf("Enter Item Name > ");
		rewind(stdin);
		scanf("%[^\n]", records.itemName);
		printf("Category\n");
		printf("---------------------\n");
		printf("1. Food\n");
		printf("2. Drink\n");
		printf("3. Shirt\n");
		printf("4. Pants\n");
		printf("5. Shoes\n");
		printf("---------------------\n");
		printf("Enter Item Category > ");
		rewind(stdin);
		cat = valid5();
		switch (cat) {
		case 1:
			strcpy(records.itemCategory, "food");
			break;
		case 2:
			strcpy(records.itemCategory, "drink");
			break;
		case 3:
			strcpy(records.itemCategory, "shirt");
			break;
		case 4:
			strcpy(records.itemCategory, "pants");
			break;
		case 5:
			strcpy(records.itemCategory, "shoes");
			break;
		}
		printf("Enter Item Price > ");
		rewind(stdin);
		scanf("%lf", &records.itemPrice);
		printf("Enter Quantity in Stock > ");
		rewind(stdin);
		scanf("%d", &records.quantity.qtyInStock);
		printf("Enter Minimum Level > ");
		rewind(stdin);
		scanf("%d", &records.quantity.minLvl);
		printf("Enter Reorder Quantity > ");
		rewind(stdin);
		scanf("%d", &records.quantity.reorderQty);
		printf("\nAre you sure you want to add this stock? (Y=Yes|N=No) > ");
		ans = valid2();
		//if user confirm to add the stock
		if (toupper(ans) == 'Y') {
			//append the new stock record into the file
			fprintf(stock, "%s|%s|%s|%.2lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
			printf("\nStock %s added successfully!\n\n", records.itemCode);
			count++;//for number of new record added
		}
		else {
			printf("\nAdd Stock Record Failed\n\n");
		}
		printf("Add another record? (Y=Yes|N=No) >");
		ans2 = valid2();
	} while (toupper(ans2) == 'Y');

	printf("\n%d record(s) added!\n\n", count);
	fclose(stock);
}

void searchStock() {
	char ans1;
	int n = 0, ans, cat;

	struct Search {
		char itemCode[5], itemName[30], itemCategory[20];
		int qtyInStock, minLvl, reorderQty;
		double itemPrice;
	}search;

	printf("\nSearch Stock Function\n");
	printf("=====================\n");
	do {
		FILE* stock;
		stock = fopen("stock.txt", "r");

		if (stock == NULL) {
			printf("Error while opening the file");
			exit(-1);
		}

		printf("Select a field to search for the stock :\n");
		printf("========================================\n");
		printf("Item Code         -> 1\n");
		printf("Item Name         -> 2\n");
		printf("Item Category     -> 3\n");
		printf("Item Price        -> 4\n");
		printf("Quantity In Stock -> 5\n");
		printf("Minimum Level     -> 6\n");
		printf("Reorder Stock     -> 7\n");
		printf("Back              -> 8\n");
		printf("Field > ");
		ans = valid();
		switch (ans) {
		case 1:
			printf("Enter Item Code > ");
			rewind(stdin);
			scanf("%s", search.itemCode);
			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				//read from the file
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				//if the item code of the record that user wanted to search for same as the item record in the record
				if (strcmp(search.itemCode, records.itemCode) == 0) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;//calculate number of stock record
				}
			}
			switch (n) {
			case 0://if no record found
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 2:
			printf("Enter Item Name > ");
			rewind(stdin);
			scanf("%[^\n]", search.itemName);
			printf("Item code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				if (strcmp(search.itemName, records.itemName) == 0) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;
				}
			}
			switch (n) {
			case 0:
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 3:
			printf("Category\n");
			printf("---------------------\n");
			printf("1. food\n");
			printf("2. drink\n");
			printf("3. shirt\n");
			printf("4. pants\n");
			printf("5. shoes\n");
			printf("---------------------\n");
			printf("Enter Item Category > ");
			rewind(stdin);
			cat = valid5();
			switch (cat) {
			case 1:
				strcpy(search.itemCategory, "food");
				break;
			case 2:
				strcpy(search.itemCategory, "drink");
				break;
			case 3:
				strcpy(search.itemCategory, "shirt");
				break;
			case 4:
				strcpy(search.itemCategory, "pants");
				break;
			case 5:
				strcpy(search.itemCategory, "shoes");
				break;
			}

			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				if (strcmp(search.itemCategory, records.itemCategory) == 0) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;
				}
			}
			switch (n) {
			case 0:
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 4:
			printf("Enter Item Price > ");
			rewind(stdin);
			scanf("%lf", &search.itemPrice);
			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				if (search.itemPrice == records.itemPrice) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;
				}
			}
			switch (n) {
			case 0:
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 5:
			printf("Enter Quantity in Stock > ");
			rewind(stdin);
			scanf("%d", &search.qtyInStock);
			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				if (search.qtyInStock == records.quantity.qtyInStock) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;
				}
			}
			switch (n) {
			case 0:
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 6:
			printf("Enter Minimum Level > ");
			rewind(stdin);
			scanf("%d", &search.minLvl);
			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				if (search.minLvl == records.quantity.minLvl) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;
				}
			}
			switch (n) {
			case 0:
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 7:
			printf("Enter Reorder Quantity > ");
			rewind(stdin);
			scanf("%d", &search.reorderQty);
			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
			printf("================================================================================================================\n");
			while (!feof(stock)) {
				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
				if (search.reorderQty == records.quantity.reorderQty) {
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					n++;
				}
			}
			switch (n) {
			case 0:
				printf("\nNo record found !\n");
				break;
			default:
				printf("\n%d record(s) found\n", n);
			}
			break;
		case 8:
			break;
		}
		n = 0;//update the number of record back to original value

		fclose(stock);

		if (ans >= 1 && ans <= 7) {
			printf("\nSearch for another record? (Y=Yes|N=No) > ");
			ans = valid2();
		}
	} while (toupper(ans) == 'Y');//when user want to search for another record
}

void modifyStock(char staffId[10]) {
	int i = 0, ans, count = 0, c = 0, cat;
	char modifyItemCode[10], ans1 = 'N', ans2, timeStr[25];

	FILE* stock, * modified;
	stock = fopen("stock.txt", "r");//read from the file
	modified = fopen("stockModifiedHistory.txt", "a");//to append the modified records into the file

	if (stock == NULL || modified == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	//store the current records into an array
	while (!feof(stock)) {
		fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", store[i].itemCode, store[i].itemName, store[i].itemCategory, &store[i].itemPrice, &store[i].quantity.qtyInStock, &store[i].quantity.minLvl, &store[i].quantity.reorderQty);
		i++;
	}

	fclose(stock);

	FILE* name;
	name = fopen("staff.dat", "rb");

	if (name == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	char staffName[50];

	while (fread(&staff, sizeof(staffs), 1, name) != 0) {
		if (strcmp(staff.staffid, staffId) == 0) {
			strcpy(staffName, staff.name);
		}
	}

	printf("\nMODIFY STOCK RECORDS\n");
	printf("====================\n");
	do {
		displayStock();
		do {
			printf("Enter Item Code ( X = Exit ) > ");
			rewind(stdin);
			scanf("%s", modifyItemCode);
			if (strcmp(modifyItemCode, "X") == 0) {
				break;
			}
			else {
				FILE* checking;
				checking = fopen("stock.txt", "r");//to read from the file

				if (checking == NULL) {
					printf("Error while opening the file");
					exit(-1);
				}

				//to check the item code of the record that user want to
				while (fscanf(checking, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
					records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty) != EOF) {
					if (strcmp(modifyItemCode, records.itemCode) == 0) {//if the item code of the record that the user wanted to modify is same as the item code of the record
						c++;//increase the number of record found
					}
				}
				if (c == 0) {//if no record found
					printf("Stock %s does not exist !\nTry Again\n", modifyItemCode);
				}
				fclose(checking);
			}
		} while (c == 0);//loop until the item code of user wanted to modify is exist in the file

		if (strcmp(modifyItemCode, "X") != 0) {
			for (int n = 0; n < i; n++) {
				if (strcmp(modifyItemCode, store[n].itemCode) == 0) {//if the item code of the record that the user wanted to modify is same as the record
					printf("\nItem Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
					printf("================================================================================================================\n");
					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].quantity.qtyInStock, store[n].quantity.minLvl, store[n].quantity.reorderQty);
					printf("\n-------------------------------\n");
					printf("Item Name         -> 1\n");
					printf("Item Category     -> 2\n");
					printf("Item Price        -> 3\n");
					printf("Quantity In Stock -> 4\n");
					printf("Minimum Level     -> 5\n");
					printf("Reorder Stock     -> 6\n");
					printf("-------------------------------\n");
					printf("Select a field to be modified > ");
					ans = valid4();
					switch (ans) {
					case 1:
						do {
							printf("\nEnter New Item Name >");
							rewind(stdin);
							scanf("%[^\n]", &records.itemName);
							if (strcmp(records.itemName, store[n].itemName) == 0)
								printf("\nDo not use back the same name. Try again.\n");
						} while (strcmp(records.itemName, store[n].itemName) == 0);

						printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
						ans2 = valid2();
						if (toupper(ans2) == 'Y') {
							SYSTEMTIME t;

							GetLocalTime(&t);//get current time

							sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);//store the current time into a string
							printf("================================================================================================================");
							printf("\nName of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("\nStock %s before modify:", modifyItemCode);
							printf("\nItem Code\tName\n");
							printf("================================\n");
							printf("%-16s%-16s\n", store[n].itemCode, store[n].itemName);
							printf("\nStock %s after modify:", modifyItemCode);
							printf("\nItem Code\tName\n");
							printf("================================\n");
							printf("%-16s%-16s\n", store[n].itemCode, records.itemName);
							printf("\n================================================================================================================");
							//write the modified record into modify file
							fprintf(modified, "Name of Stock %s has changed from %s to %s on %s\n", store[n].itemCode, store[n].itemName, records.itemName, timeStr, staffName);
							//store the modified record into record
							strcpy(store[n].itemName, records.itemName);
							count++;//increase the total number of modified record

						}
						else {
							printf("\nModify Stock Record Failed\n\n");
						}
						break;
					case 2:
						do {
							printf("Category\n");
							printf("---------------------\n");
							printf("1. food\n");
							printf("2. drink\n");
							printf("3. shirt\n");
							printf("4. pants\n");
							printf("5. shoes\n");
							printf("---------------------\n");
							printf("Enter Item Category > ");
							rewind(stdin);
							cat = valid5();
							switch (cat) {
							case 1:
								strcpy(records.itemCategory, "food");
								break;
							case 2:
								strcpy(records.itemCategory, "drink");
								break;
							case 3:
								strcpy(records.itemCategory, "shirt");
								break;
							case 4:
								strcpy(records.itemCategory, "pants");
								break;
							case 5:
								strcpy(records.itemCategory, "shoes");
								break;
							}
							if (strcmp(store[n].itemCategory, records.itemCategory) == 0)
								printf("\nDo not use back the same category. Try again.\n\n");
						} while (strcmp(store[n].itemCategory, records.itemCategory) == 0);


						printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
						ans2 = valid2();
						if (toupper(ans2) == 'Y') {
							SYSTEMTIME t;

							GetLocalTime(&t);

							sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("================================================================================================================");
							printf("\nCategory of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("\nStock %s before modify:", modifyItemCode);
							printf("\nItem Code\tCategory\n");
							printf("================================\n");
							printf("%-16s%-16s\n", store[n].itemCode, store[n].itemCategory);
							printf("\nStock %s after modify:", modifyItemCode);
							printf("\nItem Code\tCategory\n");
							printf("================================\n");
							printf("%-16s%-16s\n", store[n].itemCode, records.itemCategory);
							printf("\n================================================================================================================");
							fprintf(modified, "Category of Stock %s has changed from %s to %s on %s by %s\n", store[n].itemCode, store[n].itemCategory, records.itemCategory, timeStr, staffName);
							strcpy(store[n].itemCategory, records.itemCategory);
							count++;

						}
						else {
							printf("\nModify Stock Record Failed\n\n");
						}
						break;
					case 3:
						do {
							printf("\nEnter New Item Price >");
							rewind(stdin);
							scanf("%lf", &records.itemPrice);
							if (store[n].itemPrice == records.itemPrice)
								printf("\nDo not use back the same price. Try again.\n");
						} while (store[n].itemPrice == records.itemPrice);

						printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
						ans2 = valid2();
						if (toupper(ans2) == 'Y') {
							SYSTEMTIME t;

							GetLocalTime(&t);

							sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("================================================================================================================");
							printf("\nPrice of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("\nStock %s before modify:", modifyItemCode);
							printf("\nItem Code\tPrice\n");
							printf("================================\n");
							printf("%-16s%RM%10.2lf\n", store[n].itemCode, store[n].itemPrice);
							printf("\nStock %s after modify:", modifyItemCode);
							printf("\nItem Code\tPrice\n");
							printf("================================\n");
							printf("%-16s%RM%10.2lf\n", store[n].itemCode, records.itemPrice);
							printf("\n================================================================================================================");
							fprintf(modified, "Price of Stock %s has changed from RM%.2lf to RM%.2lf on %s by %s\n", store[n].itemCode, store[n].itemPrice, records.itemPrice, timeStr, staffName);
							store[n].itemPrice = records.itemPrice;
							count++;

						}
						else {
							printf("\nModify Stock Record Failed\n\n");
						}
						break;
					case 4:
						do {
							printf("\nEnter New Quantity In Stock >");
							rewind(stdin);
							scanf("%d", &records.quantity.qtyInStock);
							if (store[n].quantity.qtyInStock == records.quantity.qtyInStock)
								printf("\nDo not use back the same quantity. Try again.\n");
						} while (store[n].quantity.qtyInStock == records.quantity.qtyInStock);
						printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
						ans2 = valid2();
						if (toupper(ans2) == 'Y') {
							SYSTEMTIME t;

							GetLocalTime(&t);

							sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("================================================================================================================");
							printf("\nQuantity of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("\nStock %s before modify:", modifyItemCode);
							printf("\nItem Code\tQuantity\n");
							printf("================================\n");
							printf("%-16s%-16d\n", store[n].itemCode, store[n].quantity.qtyInStock);
							printf("\nStock %s after modify:", modifyItemCode);
							printf("\nItem Code\tQuantity\n");
							printf("================================\n");
							printf("%-16s%-16d\n", store[n].itemCode, records.quantity.qtyInStock);
							printf("\n================================================================================================================");
							fprintf(modified, "Quantity of Stock %s has changed from %d to %d on %s by %s\n", store[n].itemCode, store[n].quantity.qtyInStock, records.quantity.qtyInStock, timeStr, staffName);
							store[n].quantity.qtyInStock = records.quantity.qtyInStock;
							count++;

						}
						else {
							printf("\nModify Stock Record Failed\n\n");
						}
						break;
					case 5:
						do {
							printf("\nEnter New Minimum Level >");
							rewind(stdin);
							scanf("%d", &records.quantity.minLvl);
							if (records.quantity.minLvl == store[n].quantity.minLvl)
								printf("\nDo not use back the same minimum level. Try again.\n");
						} while (records.quantity.minLvl == store[n].quantity.minLvl);

						printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
						ans2 = valid2();
						if (toupper(ans2) == 'Y') {
							SYSTEMTIME t;

							GetLocalTime(&t);

							sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("================================================================================================================");
							printf("\nMinimum Level of Stock %s modified successfully!\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("\nStock %s before modify:", modifyItemCode);
							printf("\nItem Code\tMinimum Level\n");
							printf("================================\n");
							printf("%-16s%-16d\n", store[n].itemCode, store[n].quantity.minLvl);
							printf("\nStock %s after modify:", modifyItemCode);
							printf("\nItem Code\tMinimum Level\n");
							printf("================================\n");
							printf("%-16s%-16d\n", store[n].itemCode, records.quantity.minLvl);
							printf("\n================================================================================================================");
							fprintf(modified, "Minimum Level of Stock %s has changed from %d to %d on %s by %s\n", store[n].itemCode, store[n].quantity.minLvl, records.quantity.minLvl, timeStr, staffName);
							store[n].quantity.minLvl = records.quantity.minLvl;
							count++;

						}
						else {
							printf("\nModify Stock Record Failed\n\n");
						}
						break;
					case 6:
						do {
							printf("\nEnter New Reorder Quantity >");
							rewind(stdin);
							scanf("%d", &records.quantity.reorderQty);
							if (records.quantity.reorderQty == store[n].quantity.reorderQty)
								printf("\nDo not use back the same quantity. Try again.\n");
						} while (records.quantity.reorderQty == store[n].quantity.reorderQty);

						printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
						ans2 = valid2();
						if (toupper(ans2) == 'Y') {
							SYSTEMTIME t;

							GetLocalTime(&t);

							sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("================================================================================================================");
							printf("\nReorder Quantity of Stock %s modified successfully!\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
							printf("\nStock %s before modify:", modifyItemCode);
							printf("\nItem Code\tReorder Quantity\n");
							printf("================================\n");
							printf("%-16s%-16d\n", store[n].itemCode, store[n].quantity.reorderQty);
							printf("\nStock %s after modify:", modifyItemCode);
							printf("\nItem Code\tReorder Quantity\n");
							printf("================================\n");
							printf("%-16s%-16d\n", store[n].itemCode, records.quantity.reorderQty);
							printf("\n================================================================================================================");
							fprintf(modified, "Reorder Quantity of Stock %s has changed from %d to %d on %s by %s\n", store[n].itemCode, store[n].quantity.reorderQty, records.quantity.reorderQty, timeStr, staffName);
							store[n].quantity.reorderQty = records.quantity.reorderQty;
							count++;

						}
						else {
							printf("\nModify Stock Record Failed\n\n");
						}
						break;
					}
				}
			}
			printf("\nDo you want to modify another record? (Y=Yes|N=No) >");
			ans1 = valid2();
			c = 0;
		}
	} while (toupper(ans1) == 'Y');

	FILE* fptr;
	fptr = fopen("stock.txt", "w");

	if (fptr == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	//write all the records with modified record 
	for (int n = 0; n < i; n++) {
		fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n", store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].quantity.qtyInStock, store[n].quantity.minLvl, store[n].quantity.reorderQty);
	}

	fclose(fptr);
	fclose(modified);

	printf("\n%d record(s) have been modified!\n\n", count);
}

void displayStock() {
	FILE* stock;
	stock = fopen("stock.txt", "r");

	if (stock == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
	printf("================================================================================================================\n");
	while (!feof(stock)) {
		fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty);
		printf("%-16s%-16s%-16sRM%10.2lf    %-16d%-16d%-16d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
	}
	printf("\n");

	fclose(stock);

}

void reportStock(char staffId[10]) {
	int count = 0, ans, a = 0, b = 0, c = 0, d = 0, e = 0;

	SYSTEMTIME t;

	GetLocalTime(&t);//get current time

	struct Stock food[50], drink[50], shirt[50], pants[50], shoes[50];

	FILE* stock;
	stock = fopen("stock.txt", "r");

	if (stock == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	FILE* name;
	name = fopen("staff.dat", "rb");

	if (name == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	int i = 0;
	char staffName[50];

	while (fread(&staff, sizeof(staffs), 1, name) != 0) {
		if (strcmp(staff.staffid,staffId) == 0) {
			strcpy(staffName,staff.name);
		}
		i++;
	}

	printf("GENERATE STOCK REPORT\n");
	printf("=====================\n");
	printf("Select a type of report:\n");
	printf("========================\n");
	printf("Stock Records Summary Report     -> 1\n");
	printf("Stock Records Categorized Report -> 2\n");
	printf(">");
	ans = valid3();
	switch (ans) {
	case 1:
		printf("\n\t\t\t\t\tSTOCK RECORDS SUMMARY REPORT\n");
		printf("================================================================================================================\n");
		printf("DATE: %d-%d-%d\t\t\t\t\t\t\t\t\t\t\t     TIME: %d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
		printf("Prepared by : \n");
		printf("Staff Id: %s\t\t\t\t\t\t\t\t\t\t\t     Name:  %s\n",staffId,staffName);
		printf("================================================================================================================\n");
		printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
		printf("================================================================================================================\n");
		while (fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
			records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty) != EOF) {
			printf("%-16s%-16s%-16sRM%-14.2lf%-16d%-16d%-16d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
			count++;
		}
		printf("=================================================================================================================\n");
		printf("TOTAL %d RECORD(S) OF STOCK\n", count);
		printf("=================================================================================================================\n\n");
		break;
	case 2:
		printf("\n\t\t\t\t\tSTOCK RECORDS CATEGORIZED REPORT\n");
		printf("================================================================================================================\n");
		printf("DATE: %d-%d-%d\t\t\t\t\t\t\t\t\t\t\t     TIME: %d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
		printf("Prepared by : \n");
		printf("Staff Id: %s\t\t\t\t\t\t\t\t\t\t\t     Name:  %s\n", staffId, staffName);
		printf("================================================================================================================\n");
		printf("Item Code\tName\t\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
		printf("================================================================================================================\n");
		while (fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
			records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty) != EOF) {
			//differentiate the records by their category
			if (strcmp(records.itemCategory, "food") == 0) {
				strcpy(food[a].itemCode, records.itemCode);
				strcpy(food[a].itemName, records.itemName);
				strcpy(food[a].itemCategory, records.itemCategory);
				food[a].itemPrice = records.itemPrice;
				food[a].quantity.qtyInStock = records.quantity.qtyInStock;
				food[a].quantity.reorderQty = records.quantity.reorderQty;
				food[a].quantity.minLvl = records.quantity.minLvl;
				a++;
			}
			else if (strcmp(records.itemCategory, "drink") == 0) {
				strcpy(drink[b].itemCode, records.itemCode);
				strcpy(drink[b].itemName, records.itemName);
				strcpy(drink[b].itemCategory, records.itemCategory);
				drink[b].itemPrice = records.itemPrice;
				drink[b].quantity.qtyInStock = records.quantity.qtyInStock;
				drink[b].quantity.reorderQty = records.quantity.reorderQty;
				drink[b].quantity.minLvl = records.quantity.minLvl;
				b++;
			}
			else if (strcmp(records.itemCategory, "shirt") == 0) {
				strcpy(shirt[c].itemCode, records.itemCode);
				strcpy(shirt[c].itemName, records.itemName);
				strcpy(shirt[c].itemCategory, records.itemCategory);
				shirt[c].itemPrice = records.itemPrice;
				shirt[c].quantity.qtyInStock = records.quantity.qtyInStock;
				shirt[c].quantity.reorderQty = records.quantity.reorderQty;
				shirt[c].quantity.minLvl = records.quantity.minLvl;
				c++;
			}
			else if (strcmp(records.itemCategory, "pants") == 0) {
				strcpy(pants[d].itemCode, records.itemCode);
				strcpy(pants[d].itemName, records.itemName);
				strcpy(pants[d].itemCategory, records.itemCategory);
				pants[d].itemPrice = records.itemPrice;
				pants[d].quantity.qtyInStock = records.quantity.qtyInStock;
				pants[d].quantity.reorderQty = records.quantity.reorderQty;
				pants[d].quantity.minLvl = records.quantity.minLvl;
				d++;
			}
			else if (strcmp(records.itemCategory, "shoes") == 0) {
				strcpy(shoes[e].itemCode, records.itemCode);
				strcpy(shoes[e].itemName, records.itemName);
				strcpy(shoes[e].itemCategory, records.itemCategory);
				shoes[e].itemPrice = records.itemPrice;
				shoes[e].quantity.qtyInStock = records.quantity.qtyInStock;
				shoes[e].quantity.reorderQty = records.quantity.reorderQty;
				shoes[e].quantity.minLvl = records.quantity.minLvl;
				e++;
			}
		}
		printf("\nCategory : Food\n");
		printf("================================================================================================================\n");
		for (int k = 0; k < a; k++) {
			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", food[k].itemCode, food[k].itemName, food[k].itemPrice, food[k].quantity.qtyInStock, food[k].quantity.minLvl, food[k].quantity.reorderQty);
		}
		printf("\nTotal amount of Food Category : %d\n", a);
		printf("================================================================================================================\n");
		printf("\nCategory : Drink\n");
		printf("================================================================================================================\n");
		for (int k = 0; k < b; k++) {
			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", drink[k].itemCode, drink[k].itemName, drink[k].itemPrice, drink[k].quantity.qtyInStock, drink[k].quantity.minLvl, drink[k].quantity.reorderQty);
		}
		printf("\nTotal amount of Drink Category : %d\n", b);
		printf("================================================================================================================\n");
		printf("\nCategory : Shirt\n");
		printf("================================================================================================================\n");
		for (int k = 0; k < c; k++) {
			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", shirt[k].itemCode, shirt[k].itemName, shirt[k].itemPrice, shirt[k].quantity.qtyInStock, shirt[k].quantity.minLvl, shirt[k].quantity.reorderQty);
		}
		printf("\nTotal amount of Shirt Category : %d\n", c);
		printf("================================================================================================================\n");
		printf("\nCategory : Pants\n");
		printf("================================================================================================================\n");
		for (int k = 0; k < d; k++) {
			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", pants[k].itemCode, pants[k].itemName, pants[k].itemPrice, pants[k].quantity.qtyInStock, pants[k].quantity.minLvl, pants[k].quantity.reorderQty);
		}
		printf("\nTotal amount of Pants Category : %d\n", d);
		printf("================================================================================================================\n");
		printf("\nCategory : Shoes\n");
		printf("================================================================================================================\n");
		for (int k = 0; k < e; k++) {
			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", shoes[k].itemCode, shoes[k].itemName, shoes[k].itemPrice, shoes[k].quantity.qtyInStock, shoes[k].quantity.minLvl, shoes[k].quantity.reorderQty);
		}
		printf("\nTotal amount of Shoes Category : %d\n", e);
		printf("================================================================================================================\n\n");
		//generate bar chart
		printf("\t\t\t\t\tBar Chart of Number of Stock Record\n\n");
		printf("\t\335\n");
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				printf("Food");
			}
			printf("\t");
			for (int k = 0; k <= a; k++) {
				printf("\335");
				if (i == 1 && k == a) {
					printf(" [%d]", a);
				}
			}
			printf("\n");
		}
		printf("\t\335\n");
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				printf("Drink");
			}
			printf("\t");
			for (int k = 0; k <= b; k++) {
				printf("\335");
				if (i == 1 && k == b) {
					printf(" [%d]", b);
				}
			}
			printf("\n");
		}
		printf("\t\335\n");
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				printf("Shirt");
			}
			printf("\t");
			for (int k = 0; k <= c; k++) {
				printf("\335");
				if (i == 1 && k == c) {
					printf(" [%d]", c);
				}
			}
			printf("\n");
		}
		printf("\t\335\n");
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				printf("Pants");
			}
			printf("\t");
			for (int k = 0; k <= d; k++) {
				printf("\335");
				if (i == 1 && k == d) {
					printf(" [%d]", d);
				}
			}
			printf("\n");
		}
		printf("\t\335\n");
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				printf("Shoes");
			}
			printf("\t");
			for (int k = 0; k <= e; k++) {
				printf("\335");
				if (i == 1 && k == e) {
					printf(" [%d]", e);
				}
			}
			printf("\n");
		}
		printf("\t\335\n\t\335");
		int k = 10;
		while (k <= 50) {
			printf("---------\335");
			k += 10;
		}
		printf("-->Number of record\n\t0");
		int l = 10;
		while (l <= 50) {
			printf("        %d", l);
			l += 10;
		}
		printf("\n");
		break;
	}
	fclose(stock);
}

void deleteStock() {
	int i = 0, count = 0, c = 0;
	char deleteItemCode[10], ans2 = 'N', timeStr[25];

	FILE* deleted;
	deleted = fopen("stockDeletedHistory.txt", "a");//open deleted record file

	if (deleted == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	printf("DELETE STOCK RECORD\n");
	printf("===================\n");
	do {
		displayStock();
		FILE* stock;
		stock = fopen("stock.txt", "r");

		if (stock == NULL) {
			printf("Error while opening the file");
			exit(-1);
		}

		do {
			printf("Enter Item Code ( X = Exit ) > ");
			rewind(stdin);
			scanf("%s", deleteItemCode);
			if (strcmp(deleteItemCode, "X") == 0) {
				break;
			}
			else {
				FILE* checking;
				checking = fopen("stock.txt", "r");//open and read to check the record that user wanted to delete is exist 
				while (fscanf(checking, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
					records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty) != EOF) {
					if (strcmp(deleteItemCode, records.itemCode) == 0) {
						c++;//increase number of record
						printf("\nItem Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
						printf("================================================================================================================\n");
						printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n",
							records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
					}
				}
				if (c == 0) {//if no record found
					printf("Stock %s does not exist !\nTry Again\n", deleteItemCode);
				}
				fclose(checking);
			}
		} while (c == 0);

		if (strcmp(deleteItemCode, "X") != 0) {
			printf("\nAre you sure you want to delete this record? (Y=Yes|N=No) >");
			ans2 = valid2();
			if (toupper(ans2) == 'Y') {
				while (fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n",
					records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty) != EOF) {
					if (strcmp(deleteItemCode, records.itemCode) != 0) {
						strcpy(store[i].itemCode, records.itemCode);
						strcpy(store[i].itemName, records.itemName);
						strcpy(store[i].itemCategory, records.itemCategory);
						store[i].itemPrice = records.itemPrice;
						store[i].quantity.qtyInStock = records.quantity.qtyInStock;
						store[i].quantity.reorderQty = records.quantity.reorderQty;
						store[i].quantity.minLvl = records.quantity.minLvl;
						i++;
					}
					else {
						SYSTEMTIME t;

						GetLocalTime(&t);//get current time

						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);//store current time into a string
						fprintf(deleted, "%s|%s|%s|%.2lf|%d|%d|%d|%s\n",
							records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty, timeStr);
					}
				}

				fclose(stock);

				FILE* fptr;
				fptr = fopen("stock.txt", "w");//open the stock file to rewrite all record

				if (fptr == NULL) {
					printf("Error while opening the file");
					exit(-1);
				}

				for (int n = 0; n < i; n++) {
					fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n",
						store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].quantity.qtyInStock, store[n].quantity.minLvl, store[n].quantity.reorderQty);
				}
				printf("\nStock %s is deleted!\n\n", deleteItemCode);
				count++;
				fclose(fptr);
			}
			else {
				printf("\nStock %s fail to delete !\n\n", deleteItemCode);
			}
			printf("Do you want to delete another record? (Y=Yes|N=No) >");
			ans2 = valid2();
			//update the value of i and c to their original value
			i = 0;
			c = 0;
		}
	} while (toupper(ans2) == 'Y');

	fclose(deleted);

	printf("\n%d record(s) have been deleted.\n\n", count);
}

void modifyHistory() {
	int i = 0, c = 0, count = 0;
	char ans2, restoreItemCode[5], message[150];

	FILE* modified;
	modified = fopen("stockModifiedHistory.txt", "r");//open and read the modified record file

	if (modified == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	printf("MODIFIED HISTORY\n");
	printf("================\n\n");
	while (fscanf(modified, "%[^\n]\n", message) != EOF) {
		printf("%s\n\n", message);
		i++;//increase the number of modified record
	}

	if (i == 0) {//if no record been modified
		printf("\nNo record modified!\n\n");
	}
	else {
		printf("\n%d record(s) modified\n\n", i);
	}

	fclose(modified);
}

void deleteHistory() {
	struct Stock {
		char itemCode[5], itemName[30], itemCategory[20], timeStr[25];
		Quantity quantity;
		double itemPrice;
	}records;

	struct Stock store[100];

	int i = 0, n = 0, count = 0, c = 0;
	char ans2, restoreItemCode[5];

	FILE* deleted;
	deleted = fopen("stockDeletedHistory.txt", "r");//open and read the deleted record file

	if (deleted == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}
	printf("\nDELETED HISTORY\n");
	printf("===============\n\n");
	printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\tDate and Time\n");
	printf("==========================================================================================================================================\n");
	while (fscanf(deleted, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d|%[^\n]\n",
		records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty, records.timeStr) != EOF) {
		printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%-23d%-16s\n",
			records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty, records.timeStr);
		i++;//increase the number of deleted record
	}
	fclose(deleted);

	if (i == 0) {//if no record been deleted
		printf("\nNo record deleted!\n\n");
	}
	else {
		printf("\n%d record(s) deleted\n\n", i);

		//update the number of deleted record
		i = 0;

		FILE* restore;
		restore = fopen("stockDeletedHistory.txt", "r");//open and read again the deleted record file

		if (restore == NULL) {
			printf("Error while opening the file");
			exit(-1);
		}

		FILE* fptr;
		fptr = fopen("stock.txt", "a");//open to add back the deleted record into the stock file

		if (fptr == NULL) {
			printf("Error while opening the file");
			exit(-1);
		}

		printf("Do you want to restore any history? (Y=Yes|N=No) >");
		ans2 = valid2();
		while (toupper(ans2) == 'Y') {
			do {
				printf("\nEnter the item code ( X = Exit ) : ");
				rewind(stdin);
				scanf("%[^\n]", restoreItemCode);
				if (strcmp(restoreItemCode, "X") == 0)
					break;
				FILE* checking;
				checking = fopen("stockDeletedHistory.txt", "r");//open and read the deleted record file
				while (fscanf(checking, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d|%[^\n]\n",
					records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty, records.timeStr) != EOF) {
					if (strcmp(restoreItemCode, records.itemCode) == 0) {
						c++;//increase the number of record found
					}
				}
				if (c == 0) {//if no record found
					printf("Stock %s does not exist !\nTry Again\n", restoreItemCode);
				}
				fclose(checking);
			} while (c == 0);
			printf("\nAre you sure you want to restore Stock %s ? (Y=Yes|N=No) >", restoreItemCode);
			ans2 = valid2();
			if (toupper(ans2) == 'Y') {
				while (fscanf(restore, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d|%[^\n]\n",
					records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.quantity.qtyInStock, &records.quantity.minLvl, &records.quantity.reorderQty, records.timeStr) != EOF) {
					if (strcmp(restoreItemCode, records.itemCode) != 0) {
						strcpy(store[i].itemCode, records.itemCode);
						strcpy(store[i].itemName, records.itemName);
						strcpy(store[i].itemCategory, records.itemCategory);
						store[i].itemPrice = records.itemPrice;
						store[i].quantity.qtyInStock = records.quantity.qtyInStock;
						store[i].quantity.reorderQty = records.quantity.reorderQty;
						store[i].quantity.minLvl = records.quantity.minLvl;
						strcpy(store[i].timeStr, records.timeStr);
						i++;
					}
					else {
						fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n",
							records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.quantity.qtyInStock, records.quantity.minLvl, records.quantity.reorderQty);
						count++;
					}
				}
				FILE* fptr2;
				fptr2 = fopen("stockDeletedHistory.txt", "w");//open and rewrite all the records with the restored record

				if (fptr2 == NULL) {
					printf("Error while opening the file");
					exit(-1);
				}

				for (int c = 0; c < i; c++) {
					fprintf(fptr2, "%s|%s|%s|%.2lf|%d|%d|%d|%s\n",
						store[c].itemCode, store[c].itemName, store[c].itemCategory, store[c].itemPrice, store[c].quantity.qtyInStock, store[c].quantity.minLvl, store[c].quantity.reorderQty, store[c].timeStr);
				}

				fclose(fptr2);
				ans2 = 'N';
			}
			printf("\nStock %s restore successfully!\n\n", restoreItemCode);
		}

		fclose(restore);
		fclose(fptr);
	}
}

void reorderStock(char itemCode[10], int qty) {
	int i = 0;
	FILE* stock;
	stock = fopen("stock.txt", "r");

	if (stock == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	while (!feof(stock)) {
		fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", store[i].itemCode, store[i].itemName, store[i].itemCategory, &store[i].itemPrice, &store[i].quantity.qtyInStock, &store[i].quantity.minLvl, &store[i].quantity.reorderQty);
		i++;
	}
	fclose(stock);

	for (int n = 0; n < i; n++) {
		if (strcmp(store[n].itemCode, itemCode) == 0) {
			store[n].quantity.qtyInStock -= qty;
			if (store[n].quantity.qtyInStock < store[n].quantity.minLvl) {
				store[n].quantity.qtyInStock += store[n].quantity.reorderQty;
			}
		}
	}

	FILE* fptr;
	fptr = fopen("stock.txt", "w");//open the stock file to rewrite all record

	if (fptr == NULL) {
		printf("Error while opening the file");
		exit(-1);
	}

	for (int n = 0; n < i; n++) {
		fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n",
			store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].quantity.qtyInStock, store[n].quantity.minLvl, store[n].quantity.reorderQty);
	}

	fclose(fptr);
}

int valid() {
	int ans;

	//loop until the user input correctly
	do {
		rewind(stdin);
		scanf("%d", &ans);
		switch (ans) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			v = 'V';
			break;
		default:
			printf("Invalid input. Try again.\n");
			printf(">");
			v = 'I';
		}
	} while (v == 'I');

	return ans;
}

int valid1() {
	int ans;

	//loop until the user input correctly
	do {
		rewind(stdin);
		scanf("%d", &ans);
		switch (ans) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			v = 'V';
			break;
		default:
			printf("Invalid input. Try again.\n");
			printf(">");
			v = 'I';
		}
	} while (v == 'I');

	return ans;
}

char valid2() {
	char ans2 = 'N';

	//loop until the user input correctly
	do {
		rewind(stdin);
		scanf("%c", &ans2);
		switch (ans2) {
		case 'Y':
		case 'y':
		case 'N':
		case 'n':
			v = 'V';
			break;
		default:
			printf("Invalid input. Try again.\n");
			printf(">");
			v = 'I';
		}
	} while (v == 'I');
	return ans2;
}

int valid3() {
	int ans;

	//loop until the user input correctly
	do {
		rewind(stdin);
		scanf("%d", &ans);
		switch (ans) {
		case 1:
		case 2:
			v = 'V';
			break;
		default:
			printf("Invalid input. Try again.\n");
			printf(">");
			v = 'I';
		}
	} while (v == 'I');

	return ans;
}

int valid4() {
	int ans;

	//loop until the user input correctly
	do {
		rewind(stdin);
		scanf("%d", &ans);
		switch (ans) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			v = 'V';
			break;
		default:
			printf("Invalid input. Try again.\n");
			printf(">");
			v = 'I';
		}
	} while (v == 'I');

	return ans;
}

int valid5() {
	int ans;

	//loop until the user input correctly
	do {
		rewind(stdin);
		scanf("%d", &ans);
		switch (ans) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			v = 'V';
			break;
		default:
			printf("Invalid input. Try again.\n");
			printf(">");
			v = 'I';
		}
	} while (v == 'I');

	return ans;
}