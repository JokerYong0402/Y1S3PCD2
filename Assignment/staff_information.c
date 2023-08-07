//// staff information module 
//// by: ryan moey kai xiang
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <string.h>
//#pragma warning (disable:4996)
//#define COM_RATE 0.05
//
////function declaration
//void staffLogin();
//void staffMenu();
//void staffCreate();
//void staffDisplay();
//void staffDisplayStaff();
//void staffModify();
//void staffModifyStaff();
//void staffSearch();
//void staffDelete();
//void staffReport();
//void staffReportStaff();
//void staffRestore();
//void staffHeader(int type);
//
////global structure 
//struct Date {
//	int day, month, year;
//};
//
//typedef struct {
//	char staffid[10];
//	char name[30];
//	char gender;
//	char email[30];
//	char password[30];
//	char phnum[20];
//	char ic[20];
//	char position[20];
//	struct Date date;
//}staffs;
//
//staffs staff;
//staffs staffarr[100];
//char loginStaffID[10];
//
//void main() {
//	staffLogin();
//}
//
//void staffLogin() {
//	FILE* file;
//	int scount = 0;
//	int choice;
//	char loginpassword[30];
//	int found = 0;
//
//	file = fopen("staff.dat", "rb");
//	if (file == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//
//	/*printf("-----------------\n");
//	printf("apapunada company\n");
//	printf("-----------------\n\n");*/
//	printf("  Staff portal  \n");
//	printf("=================\n");
//	printf("| 1 - Log in    |\n");
//	printf("| 2 - Sign up   |\n");
//	printf("| 3 - Exit      |\n");
//	printf("=================\n");
//	printf("Enter your choice > ");
//	rewind(stdin);
//	scanf("%d", &choice);
//	switch (choice) {
//	case 1:
//		printf("Enter staff id : ");
//		rewind(stdin);
//		scanf("%[^\n]", &loginStaffID);
//
//		rewind(file);
//		while (fread(&staff, sizeof(staffs), 1, file) != 0) {
//			if (strcmp(staff.staffid, loginStaffID) == 0) {
//				found = 1;
//				printf("Enter password : ");
//				rewind(stdin);
//				scanf("%[^\n]", loginpassword);
//				if (strcmp(staff.password, loginpassword) == 0) {
//					printf("Login successful!\n\n");
//					staffMenu();
//					fclose(file);
//				}
//				else {
//					printf("**Incorrect password**\n\n");
//					staffLogin();
//				}
//			}
//		}
//		if (found != 1) {
//			printf("**Incorrect staff id**\n\n");
//			staffLogin();
//		}
//
//		break;
//	case 2:
//		staffCreate();
//		printf("Sign up successfully!\n\n");
//		return staffLogin();
//		break;
//	case 3:
//		exit(0);
//	default:
//		printf("**Enter valid input!**\n\n");
//		return staffLogin();
//	}
//}
//
//void staffMenu() {
//	int staffmchoice;
//
//	//printf("\n    apapunada company\n");
//	printf("\n        Staff Menu\n");
//	printf("=============================\n");
//	printf("| 1 - Add staff             |\n");
//	printf("| 2 - Display staff info    |\n");
//	printf("| 3 - Modify staff info     |\n");
//	printf("| 4 - Search staff          |\n");
//	printf("| 5 - Delete staff          |\n");
//	printf("| 6 - Display staff report  |\n");
//	printf("| 7 - Restore staff acc     |\n");
//	printf("| 8 - Log out               |\n");
//	printf("=============================\n");
//	printf("Enter your choice > ");
//	rewind(stdin);
//	scanf("%d", &staffmchoice);
//	do {
//		switch (staffmchoice) {
//		case 1:
//			staffCreate();
//			break;
//		case 2:
//			staffDisplay();
//			//staffDisplayStaff();
//			break;
//		case 3:
//			staffModify();
//			//staffModifyStaff();
//			break;
//		case 4:
//			staffSearch();
//			break;
//		case 5:
//			staffDelete();
//			break;
//		case 6:
//			staffReport();
//			//staffReportStaff();
//			break;
//		case 7:
//			staffRestore();
//			break;
//		case 8:
//			system("cls");
//			return staffLogin();
//			break;
//		default:
//			printf("**Please enter correct option!**\n");
//		}
//		//printf("\n    apapunada company\n");
//		printf("\n        Staff Menu\n");
//		printf("=============================\n");
//		printf("| 1 - Add staff             |\n");
//		printf("| 2 - Display staff info    |\n");
//		printf("| 3 - Modify staff info     |\n");
//		printf("| 4 - Search staff          |\n");
//		printf("| 5 - Delete staff          |\n");
//		printf("| 6 - Display staff report  |\n");
//		printf("| 7 - Restore staff acc     |\n");
//		printf("| 8 - Log out               |\n");
//		printf("=============================\n");
//		printf("Enter your choice > ");
//		rewind(stdin);
//		scanf("%d", &staffmchoice);
//	} while (staffmchoice > 1 || staffmchoice < 7);
//}
//
//void staffCreate() {
//	FILE* addfile, * readfile, * readbinfile;
//	int scount = 0, stotal = 0;
//	char addchoice, confirmation;
//	int i = 0, staffpositionchoice;
//	SYSTEMTIME time;
//	staffs checkstaff[50];
//
//	readfile = fopen("staff.dat", "rb");
//	if (readfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//
//	addfile = fopen("staff.dat", "ab");
//	if (addfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//
//	readbinfile = fopen("staffbin.dat", "rb");
//	if (readbinfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, readfile) != 0) {
//		strcpy(checkstaff[scount].staffid, staff.staffid);
//		strcpy(checkstaff[scount].name, staff.name);
//		checkstaff[scount].gender = staff.gender;
//		strcpy(checkstaff[scount].email, staff.email);
//		strcpy(checkstaff[scount].password, staff.password);
//		strcpy(checkstaff[scount].phnum, staff.phnum);
//		strcpy(checkstaff[scount].ic, staff.ic);
//		strcpy(checkstaff[scount].position, staff.position);
//		checkstaff[scount].date.day = staff.date.day;
//		checkstaff[scount].date.month = staff.date.month;
//		checkstaff[scount].date.year = staff.date.year;
//		scount++;
//		stotal++;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, readbinfile) != 0) {
//		stotal++;
//	}
//	fclose(readbinfile);
//
//	do {
//		printf("\nAdd new staff account\n");
//		printf("---------------------\n");
//		sprintf(staff.staffid, "ST%03d", stotal);
//		stotal++;
//
//		do {
//			printf("Enter staff name : ");
//			rewind(stdin);
//			scanf("%[^\n]", &staff.name);
//			for (i = 0; i < scount; i++) { //compare the name that user enter and name exist in the file to prevent duplicated name
//				if (strcmp(checkstaff[i].name, staff.name) == 0) {
//					printf("**Name had been used. Please try again.**\n");
//					break;
//				}
//			}
//		} while (strcmp(checkstaff[i].name, staff.name) == 0);
//
//		do {
//			printf("Enter staff gender ( M / F ) : ");
//			rewind(stdin);
//			scanf("%c", &staff.gender);
//			staff.gender = toupper(staff.gender);
//			if (staff.gender != 'M' && staff.gender != 'F') {	//check whether gender entered is only M or F
//				printf("invalid gender entered.please enter 'M' or 'F'\n");
//			}
//		} while (staff.gender != 'M' && staff.gender != 'F');
//
//		do {
//			printf("Enter staff email : ");
//			rewind(stdin);
//			scanf("%[^\n]", &staff.email);
//			for (i = 0; i < scount; i++) {//compare the email that user enter and email exist in the file to prevent duplicated email
//				if (strcmp(checkstaff[i].email, staff.email) == 0) {
//					printf("email had been used.please change\n");
//					break;
//				}
//			}
//		} while (strcmp(checkstaff[i].email, staff.email) == 0);
//
//		do {
//			printf("Enter staff password : ");
//			rewind(stdin);
//			scanf("%[^\n]", &staff.password);
//			for (i = 0; i < scount; i++) {//compare the password that user enter and password exist in the file to prevent duplicated password
//				if (strcmp(checkstaff[i].password, staff.password) == 0) {
//					printf("email had been used.please change\n");
//					break;
//				}
//			}
//		} while (strcmp(checkstaff[i].password, staff.password) == 0);
//
//		do {
//			printf("Enter staff phone number : ");
//			rewind(stdin);
//			scanf("%[^\n]", &staff.phnum);
//			if (strlen(staff.phnum) > 11 || strlen(staff.phnum) < 10) {//check whether the phone number entered fullfilled the stringlength more than 11 and less than 10
//				printf("Invalid phone number.enter again!\n");
//			}
//			for (i = 0; i < scount; i++) {//compare the phone number that user enter and phone number exist in the file to prevent duplicated phone number
//				if (strcmp(checkstaff[i].phnum, staff.phnum) == 0) {
//					printf("phone number had been used.please change\n");
//					break;
//				}
//			}
//		} while (strlen(staff.phnum) > 11 || strlen(staff.phnum) < 10 || strcmp(checkstaff[i].phnum, staff.phnum) == 0);
//
//		do {
//			printf("Enter staff ic : ");
//			rewind(stdin);
//			scanf("%[^\n]", &staff.ic);
//			if (strlen(staff.ic) != 12) {//check whether the ic entered fullfilled the stringlength of 12
//				printf("invalid ic.enter again!\n");
//			}
//			for (i = 0; i < scount; i++) {//compare the ic that user enter and ic exist in the file to prevent duplicated ic
//				if (strcmp(checkstaff[i].ic, staff.ic) == 0) {
//					printf("phone number had been used.please change\n");
//					break;
//				}
//			}
//		} while (strlen(staff.ic) != 12 || strcmp(checkstaff[i].ic, staff.ic) == 0);
//
//		printf("Choose staff position\n");
//		printf("------------\n");
//		printf("1 - Manager \n");
//		printf("2 - Staff \n");
//		printf("3 - Intern \n");
//		printf("------------\n");
//		printf("Position > ");
//		rewind(stdin);
//		scanf("%d", &staffpositionchoice);
//
//		do {
//			switch (staffpositionchoice) {//let user choose position based on number
//			case 1:
//				strcpy(staff.position, "Manager");
//				break;
//			case 2:
//				strcpy(staff.position, "Staff");
//				break;
//			case 3:
//				strcpy(staff.position, "Intern");
//				break;
//			default:
//				printf("enter valid input\n");
//			}
//		} while (staffpositionchoice < 1 || staffpositionchoice > 3);
//
//		printf("Confirm add this staff information? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &confirmation);
//		if (toupper(confirmation) == 'Y') {
//			//save the time of new account created
//			GetLocalTime(&time);
//			staff.date.day = time.wDay;
//			staff.date.month = time.wMonth;
//			staff.date.year = time.wYear;
//			fwrite(&staff, sizeof(staffs), 1, addfile);
//			printf("[ Staff id '%s' created successfully on %02d-%02d-%d ]\n\n", staff.staffid, staff.date.day, staff.date.month, staff.date.year);
//		}
//		else {
//			printf("Not saved\n\n");
//		}
//		printf("Add another staff account? ( Y = yes / N = no ) > ");
//
//		rewind(stdin);
//		scanf("%c", &addchoice);
//	} while (toupper(addchoice) == 'Y');
//
//	fclose(addfile);
//}
//
//void staffDisplay() {
//	FILE* displayfile;
//	int staffcount = 0, scount = 0;
//
//	displayfile = fopen("staff.dat", "rb");
//	if (displayfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//	
//	while (fread(&staff, sizeof(staffs), 1, displayfile) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	
//	printf("\n                                                             Apapunada company staff information\n");
//	printf("                                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
//	staffHeader(1);
//	for (int i = 0; i < scount; i++) {
//		printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, staffarr[i].phnum, staffarr[i].ic,
//			staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//	}
//	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
//	printf("< %d staff listed >\n\n", scount);
//
//	fclose(displayfile);
//}
//
//void staffDisplayStaff() {
//	FILE* displayfile;
//	int staffcount = 0, scount = 0;
//
//	displayfile = fopen("staff.dat", "rb");
//	if (displayfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, displayfile) != 0)
//	{
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	for (int i = 0; i < scount; i++) {
//		if (strcmp(loginStaffID, staffarr[i].staffid) == 0) {
//			printf("\n          %s Staff Profile\n", staffarr[i].staffid);
//			printf("-----------------------------------------\n");
//			printf("Staff id     : %s\n", staffarr[i].staffid);
//			printf("Name         : %s\n", staffarr[i].name);
//			printf("Gender       : %c\n", staffarr[i].gender);
//			printf("Email        : %s\n", staffarr[i].email);
//			printf("Password     : %s\n", staffarr[i].password);
//			printf("Phone number : %s\n", staffarr[i].phnum);
//			printf("IC number    : %s\n", staffarr[i].ic);
//			printf("Position     : %s\n", staffarr[i].position);
//			printf("Date joined  : %02d-%02d-%d\n", staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//			printf("-----------------------------------------\n\n");
//			break;
//		}
//	}
//
//	fclose(displayfile);
//}
//
//void staffModify() {
//	FILE* modifyfile1, * modifyfile2;
//	int scount = 0, modifychoice, modifycount = 0;
//	char modifyid[10], confirmation;
//	char newname[30], newgender, newemail[30], newpassword[30], newph[20], newic[20], newposition[30];
//	int newpositionchoice;
//	char anothermchoice, modifyagain;
//	int i;
//
//	modifyfile1 = fopen("staff.dat", "rb");
//	if (modifyfile1 == NULL) {
//		printf("Error while opening the file\n");
//		return -1;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, modifyfile1) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//
//	fclose(modifyfile1);
//
//	do {
//		printf("=====================\n");
//		printf("| Modify staff info |\n");
//		printf("=====================\n");
//		printf("Enter staff id that you want to modify > "); //if position == manager then all else self
//		rewind(stdin);
//		scanf("%s", &modifyid);
//		for (i = 0; i < scount; i++) {
//			
//			if (strcmp(staffarr[i].staffid, modifyid) == 0) {
//
//				printf("\nStaff detail of staff id :%s\n\n", modifyid);
//				staffHeader(1);
//				printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", 
//					staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, 
//					staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//				staffHeader(0);
//				printf("\n");
//				do {
//					printf("         Modify choices\n");
//					printf("=================================\n");
//					printf("| 1 - Modify staff name         |\n");
//					printf("| 2 - Modify staff gender       |\n");
//					printf("| 3 - Modify staff email        |\n");
//					printf("| 4 - Modify staff password     |\n");
//					printf("| 5 - Modify staff phone number |\n");
//					printf("| 6 - Modify staff ic           |\n");
//					printf("| 7 - Modify staff position     |\n");
//					printf("| 8 - Back                      |\n");
//					printf("=================================\n");
//					printf("Enter your modify choice > ");
//					scanf("%d", &modifychoice);
//					switch (modifychoice) {
//					case 1://edit name
//						do {
//							printf("Enter new staff name > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newname);
//						} while (strcmp(newname, staffarr[i].name) == 0);
//						printf("Confirm modify ( Y = yes ) ? > \n");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].name, newname);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 2://edit gender
//						do {
//							printf("Enter new staff gender ( M / F ) > ");
//							rewind(stdin);
//							scanf("%c", &newgender);
//							newgender = toupper(newgender);
//							if (newgender != 'M' && newgender != 'F') {
//								printf("**Invalid gender. Please enter 'M' or 'F'**\n");
//							}
//						} while (newgender != 'M' && newgender != 'F');
//						printf("Confirm modify ( Y = yes ) ? > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							staffarr[i].gender = newgender;
//							printf("Modify successfully!\n");
//							modifycount++;
//						}
//						break;
//
//					case 3://edit email
//						printf("Enter new staff email > ");
//						rewind(stdin);
//						scanf("%[^\n]", &newemail);
//						printf("Confirm modify ( Y = yes ) ? > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].email, newemail);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 4://edit password
//						do {
//							printf("Enter new staff password > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newpassword);
//						} while (strcmp(newpassword, staffarr[i].password) == 0);
//						printf("Confirm modify ( Y = yes ) ? > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].password, newpassword);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 5://edit phone number
//						do {
//							printf("Enter new staff phone number > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newph);
//							if (strlen(newph) > 11 || strlen(newph) < 10) {
//								printf("**Invalid phone number.enter again!**\n");
//							}
//							for (i = 0; i < scount; i++) {
//								if (strcmp(staffarr[i].phnum, newph) == 0) {
//									printf("**Phone number had been used. Please try again.**\n");
//									break;
//								}
//							}
//						} while (strlen(newph) > 11 || strlen(newph) < 10 || strcmp(staffarr[i].phnum, newph) == 0);
//						printf("Confirm modify? ( Y = yes ) > \n");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].phnum, newph);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 6://edit ic
//						do {
//							printf("Enter new staff ic > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newic);
//							if (strlen(newic) != 12) {
//								printf("**Invalid IC number. Please try again.**\n");
//							}
//							for (i = 0; i < scount; i++) {
//								if (strcmp(staffarr[i].ic, newic) == 0) {
//									printf("**IC number had been used. Please try again.**\n");
//									break;
//								}
//							}
//						} while (strlen(newic) != 12 || strcmp(staffarr[i].ic, newic) == 0);
//
//						printf("Confirm modify? ( Y = yes ) > \n");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].ic, newic);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 7://edit position
//						printf("Choose new staff position\n");
//						printf("------------\n");
//						printf("1 - Manager \n");
//						printf("2 - Staff   \n");
//						printf("3 - Intern  \n");
//						printf("------------\n");
//						printf("Position > ");
//						rewind(stdin);
//						scanf("%d", &newpositionchoice);
//						switch (newpositionchoice) {
//						case 1:
//							strcpy(newposition, "Manager");
//							printf("Confirm modify ( Y = yes ) ? > "); 
//							rewind(stdin);
//							scanf("%c", &confirmation);
//							if (toupper(confirmation) == 'Y') {
//								strcpy(staffarr[i].position, newposition);
//								printf("Modify successfully !\n");
//								modifycount++;
//							}
//							break;
//						case 2:
//							strcpy(newposition, "Staff");
//							printf("Confirm modify ( Y = yes ) ? > ");
//							rewind(stdin);
//							scanf("%c", &confirmation);
//							if (toupper(confirmation) == 'Y') {
//								strcpy(staffarr[i].position, newposition);
//								printf("Modify successfully !\n");
//								modifycount++;
//							}
//							break;
//						case 3:
//							strcpy(newposition, "Intern");
//							printf("Confirm modify ( Y = yes ) ? > ");
//							rewind(stdin);
//							scanf("%c", &confirmation);
//							if (toupper(confirmation) == 'Y') {
//								strcpy(staffarr[i].position, newposition);
//								printf("Modify successfully !\n");
//								modifycount++;
//							}
//							break;
//						default:
//							printf("**Invalid input.**\n");
//						}
//						break;
//					case 8:
//						return staffMenu();
//						break;
//					default:
//						printf("**Please enter valid input!**\n\n");
//					}
//				} while (modifychoice >= 9 || modifychoice <= 0);
//				i = scount;
//				break;
//			}
//			else if (i == (scount-1)) {
//				printf("**Staff id you entered is not exist.**\n");
//			}
//		}
//
//		if (modifycount > 0) {
//			modifyfile2 = fopen("staff.dat", "wb");
//			if (modifyfile2 == NULL) {
//				printf("Error while opening the file\n");
//				return -1;
//			}
//			for (int i = 0; i < scount; i++) {
//				fwrite(&staffarr[i], sizeof(staffs), 1, modifyfile2);
//			}
//			printf("\n****All modifications saved!****\n\n");
//			fclose(modifyfile2);
//		}
//
//		printf("Modify another record ? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &anothermchoice);
//	} while (toupper(anothermchoice) == 'Y');
//}
//
//void staffModifyStaff() {
//	FILE* modifyfile1, * modifyfile2;
//	int scount = 0, modifychoice, modifycount = 0;
//	char modifyid[10], confirmation;
//	char newname[30], newgender, newemail[30], newpassword[30], newph[20], newic[20], newposition[30];
//	int newpositionchoice;
//	char anothermchoice, modifyagain;
//	int i;
//
//	modifyfile1 = fopen("staff.dat", "rb");
//	if (modifyfile1 == NULL) {
//		printf("error while opening the file\n");
//		return -1;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, modifyfile1) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//
//	fclose(modifyfile1);
//
//	do {
//		printf("=====================\n");
//		printf("| Modify staff info |\n");
//		printf("=====================\n");
//		for (i = 0; i < scount; i++) {
//
//			if (strcmp(loginStaffID, staffarr[i].staffid) == 0) {
//
//				printf("\nStaff detail of staff id : %s\n\n", loginStaffID);
//				staffHeader(1);
//				printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n",
//					staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, staffarr[i].phnum, staffarr[i].ic, staffarr[i].position,
//					staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//				staffHeader(0);
//				printf("\n");
//				do {
//					printf("=================================\n");
//					printf("         Modify choices\n");
//					printf("=================================\n");
//					printf("| 1 - Modify staff name         |\n");
//					printf("| 2 - Modify staff gender       |\n");
//					printf("| 3 - Modify staff email        |\n");
//					printf("| 4 - Modify staff password     |\n");
//					printf("| 5 - Modify staff phone number |\n");
//					printf("| 6 - Modify staff ic           |\n");
//					printf("| 7 - Modify staff position     |\n");
//					printf("| 8 - Back                      |\n");
//					printf("=================================\n");
//					printf("Enter your modify choice > ");
//					scanf("%d", &modifychoice);
//					switch (modifychoice) {
//					case 1://edit name
//						do {
//							printf("Enter new staff name > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newname);
//						} while (strcmp(newname, staffarr[i].name) == 0);
//						printf("Confirm modify ( Y = yes ) ? > \n");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].name, newname);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 2://edit gender
//						do {
//							printf("Enter new staff gender ( M / F ) > ");
//							rewind(stdin);
//							scanf("%c", &newgender);
//							newgender = toupper(newgender);
//							if (newgender != 'M' && newgender != 'F') {
//								printf("**Invalid gender. Please enter 'M' or 'F'.**\n");
//							}
//						} while (newgender != 'M' && newgender != 'F');
//						printf("Confirm modify ( Y = yes ) ? > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							staffarr[i].gender = newgender;
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 3://edit email
//						printf("Enter new staff email > ");
//						rewind(stdin);
//						scanf("%[^\n]", &newemail);
//						printf("Confirm modify ( Y = yes ) ? > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].email, newemail);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 4://edit password
//						do {
//							printf("Enter new staff password > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newpassword);
//						} while (strcmp(newpassword, staffarr[i].password) == 0);
//						printf("Confirm modify ( Y = yes ) ? > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].password, newpassword);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 5://edit phone number
//						do {
//							printf("Enter new staff phone number > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newph);
//							if (strlen(newph) > 11 || strlen(newph) < 10) {
//								printf("**Invalid phone number. Please try again.**\n");
//							}
//							for (i = 0; i < scount; i++) {
//								if (strcmp(staffarr[i].phnum, newph) == 0) {
//									printf("**Phone number had been used. Please try again.**\n");
//									break;
//								}
//							}
//						} while (strlen(newph) > 11 || strlen(newph) < 10 || strcmp(staffarr[i].phnum, newph) == 0);
//						printf("Confirm modify? ( Y = yes ) > ");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].phnum, newph);
//							printf("Modify successfully!\n");
//							modifycount++;
//						}
//						break;
//
//					case 6://edit ic
//						do {
//							printf("Enter new staff ic > ");
//							rewind(stdin);
//							scanf("%[^\n]", &newic);
//							if (strlen(newic) != 12) {
//								printf("**Invalid IC number. Please try again.**\n");
//							}
//							for (i = 0; i < scount; i++) {
//								if (strcmp(staffarr[i].ic, newic) == 0) {
//									printf("**IC number had been used. Please try again.**\n");
//									break;
//								}
//							}
//						} while (strlen(newic) != 12 || strcmp(staffarr[i].ic, newic) == 0);
//
//						printf("Confirm modify? ( Y = yes ) > \n");
//						rewind(stdin);
//						scanf("%c", &confirmation);
//						if (toupper(confirmation) == 'Y') {
//							strcpy(staffarr[i].ic, newic);
//							printf("Modify successfully !\n");
//							modifycount++;
//						}
//						break;
//
//					case 7://edit position
//						printf("Choose new staff position\n");
//						printf("------------\n");
//						printf("1 - Manager \n");
//						printf("2 - Staff   \n");
//						printf("3 - Intern  \n");
//						printf("------------\n");
//						printf("Position > ");
//						rewind(stdin);
//						scanf("%d", &newpositionchoice);
//						switch (newpositionchoice) {
//						case 1:
//							strcpy(newposition, "Manager");
//							printf("Confirm modify ( Y = yes ) ? > ");
//							rewind(stdin);
//							scanf("%c", &confirmation);
//							if (toupper(confirmation) == 'Y') {
//								strcpy(staffarr[i].position, newposition);
//								printf("Modify successfully !\n");
//								modifycount++;
//							}
//							break;
//						case 2:
//							strcpy(newposition, "Staff");
//							printf("Confirm modify ( Y = yes ) ? > ");
//							rewind(stdin);
//							scanf("%c", &confirmation);
//							if (toupper(confirmation) == 'Y') {
//								strcpy(staffarr[i].position, newposition);
//								printf("Modify successfully !\n");
//								modifycount++;
//							}
//							break;
//						case 3:
//							strcpy(newposition, "Intern");
//							printf("Confirm modify ( Y = yes ) ? > ");
//							rewind(stdin);
//							scanf("%c", &confirmation);
//							if (toupper(confirmation) == 'Y') {
//								strcpy(staffarr[i].position, newposition);
//								printf("Modify successfully !\n");
//								modifycount++;
//							}
//							break;
//						default:
//							printf("**Please enter valid input!**\n");
//						}
//						break;
//					case 8:
//						return staffMenu();
//						break;
//					default:
//						printf("**Please enter valid input!**\n\n");
//					}
//				} while (modifychoice >= 9 || modifychoice <= 0);
//				i = scount;
//				break;
//			}
//		}
//
//		if (modifycount > 0) {
//			modifyfile2 = fopen("staff.dat", "wb");
//			if (modifyfile2 == NULL) {
//				printf("Error while opening the file\n");
//				return -1;
//			}
//			for (int i = 0; i < scount; i++) {
//				fwrite(&staffarr[i], sizeof(staffs), 1, modifyfile2);
//			}
//			printf("\n****All modifications saved!****\n\n");
//			fclose(modifyfile2);
//		}
//
//		printf("Modify another record ? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &anothermchoice);
//	} while (toupper(anothermchoice) == 'Y');
//}
//
//void staffSearch() {
//	FILE* searchfile;
//	int scount = 0, searchchoice;
//	char anotherschoice;
//	char searchid[10], searchname[30], searchgender, searchphnum[10], searchpositionw[30];
//	int searchposition, searchday, searchmonth, searchyear;
//	int i, staffcount = 0;
//	int foundm = 0, founds = 0, foundi = 0;
//
//	searchfile = fopen("staff.dat", "rb");
//	if (searchfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//	while (fread(&staff, sizeof(staffs), 1, searchfile) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	fclose(searchfile);
//
//	do {
//		printf("\n            Search choices\n");
//		printf("======================================\n");
//		printf("| 1 - Search by staffs' id           |\n");
//		printf("| 2 - Search by staffs' name         |\n");
//		printf("| 3 - Search by staffs' gender       |\n");
//		printf("| 4 - Search by staffs' phone number |\n");
//		printf("| 5 - Search by staffs' position     |\n");
//		printf("| 6 - Search by staffs' date joined  |\n");
//		printf("| 7 - Back                           |\n");
//		printf("======================================\n");
//		printf("enter your choice > ");
//		rewind(stdin);
//		scanf("%d", &searchchoice);
//
//		switch (searchchoice) {
//		case 1:
//			printf("\n============================\n");
//			printf("|Search based on staffs' id|\n");
//			printf("============================\n");
//			printf("Enter staff id : ");
//			rewind(stdin);
//			scanf("%s", &searchid);
//			int foundid = 0;
//			for (i = 0; i < scount; i++) {
//				if (strcmp(searchid, staffarr[i].staffid) == 0) {
//					foundid = 1;
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//				}
//			}
//			if (foundid != 1) {
//				printf("**Staff id < %s > not found**\n\n", searchid);
//			}
//			break;
//		case 2:
//			printf("\n==============================\n");
//			printf("|Search based on staffs' name|\n");
//			printf("==============================\n");
//			printf("Enter staff name : ");
//			rewind(stdin);
//			scanf("%[^\n]", &searchname);
//			int foundname = 0;
//			for (i = 0; i < scount; i++) {
//				if (strcmp(searchname, staffarr[i].name) == 0) {
//					foundname = 1;
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//				}
//			}
//			if (foundname != 1) {
//				printf("**Staff name < %s > not found**\n\n", searchname);
//			}
//			break;
//		case 3:
//			printf("\n================================\n");
//			printf("|Search based on staffs' gender|\n");
//			printf("================================\n");
//			printf("Enter staff gender : ");
//			rewind(stdin);
//			scanf("%c", &searchgender);
//			int foundgender = 0;
//			for (int i = 0; i < scount; i++) {
//				if (toupper(searchgender) == staffarr[i].gender) {
//					foundgender = 1;
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//				}
//			}
//			if (foundgender != 1) {
//				printf("**Staff gender < %c > not found**\n\n", searchgender);
//			}
//			break;
//		case 4:
//			printf("\n======================================\n");
//			printf("|Search based on staffs' phone number|\n");
//			printf("======================================\n");
//			printf("Enter staff phone number : ");
//			rewind(stdin);
//			scanf("%s", &searchphnum);
//			int foundphnum = 0;
//			for (int i = 0; i < scount; i++) {
//				if (strcmp(searchphnum, staffarr[i].phnum) == 0) {
//					foundphnum = 1;
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//				}
//			}
//			if (foundphnum != 1) {
//				printf("**Staff phone number < %s > not found**\n\n", searchphnum);
//			}
//			break;
//		case 5:
//			printf("\n==================================\n");
//			printf("|Search based on staffs' position|\n");
//			printf("==================================\n");
//			printf("Choose staff position\n");
//			printf("------------\n");
//			printf("1 - Manager \n");
//			printf("2 - Staff   \n");
//			printf("3 - Intern  \n");
//			printf("------------\n");
//			rewind(stdin);
//			scanf("%d", &searchposition);
//			switch (searchposition) {
//			case 1:
//				strcpy(searchpositionw, "Manager");
//				staffHeader(1);
//				for (int i = 0; i < scount; i++) {
//					if (strcmp(searchpositionw, staffarr[i].position) == 0) {
//						foundm = 1;
//						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//
//					}
//				}
//				staffHeader(0);
//				if (foundm != 1) {
//					printf("**Staff position < %s > not found**\n\n", searchpositionw);
//				}
//				break;
//			case 2:
//				strcpy(searchpositionw, "Staff");
//				staffHeader(1);
//				for (int i = 0; i < scount; i++) {
//					if (strcmp(searchpositionw, staffarr[i].position) == 0) {
//						founds = 1;
//						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					}
//				}
//				staffHeader(0);
//				if (founds != 1) {
//					printf("**Staff position < %s > not found**\n\n", searchpositionw);
//				}
//				break;
//			case 3:
//				strcpy(searchpositionw, "Intern");
//				staffHeader(1);
//				for (int i = 0; i < scount; i++) {
//					if (strcmp(searchpositionw, staffarr[i].position) == 0) {
//						foundi = 1;
//						printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//							staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					}
//				}
//				staffHeader(0);
//				if (foundi != 1) {
//					printf("**Staff position < %s > not found**\n\n", searchpositionw);
//				}
//				break;
//			default:
//				printf("**Please enter valid input!**\n");
//				return staffSearch();
//				break;
//			}
//			break;
//		case 6:
//			printf("\n=====================================\n");
//			printf("|Search based on staffs' date joined|\n");
//			printf("=====================================\n");
//			printf("Enter staff joined day :");
//			rewind(stdin);
//			scanf("%d", &searchday);
//			printf("Enter staff joined month :");
//			rewind(stdin);
//			scanf("%d", &searchmonth);
//			printf("Enter staff joined year :");
//			rewind(stdin);
//			scanf("%d", &searchyear);
//			int founddate = 0;
//			for (int i = 0; i < scount; i++) {
//				if (searchday == staffarr[i].date.day && searchmonth == staffarr[i].date.month && searchyear == staffarr[i].date.year) {
//					founddate = 1;
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//				}
//				if (founddate != 1) {
//					printf("**Staff date joined < %02d-%02d-%d > not found.**\n\n", searchday, searchmonth, searchyear);
//				}
//			}
//			break;
//		case 7:
//			return;
//			break;
//		default:
//			printf("**Please enter valid choice!**\n");
//			return staffSearch();
//			break;
//		}
//		printf("Search again? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &anotherschoice);
//
//	} while (toupper(anotherschoice) == 'Y');
//
//}
//
//void staffDelete() {
//	FILE* dltfile, * dltfile2, * binfile;
//	char dltid[10];
//	int scount = 0, dltcount = 0;
//	char confirmation, anotherdchoice;
//	staffs modifiedstaff[10], deletedstaff[10];
//	int i = 0, n = 0, d = 0;
//
//
//	dltfile = fopen("staff.dat", "rb");
//	if (dltfile == NULL) {
//		printf("Error while opening the file\n");
//		return;
//	}
//	//read all the staff info into array
//	while (fread(&staff, sizeof(staffs), 1, dltfile) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	fclose(dltfile);
//	staffHeader(1);
//	for (int i = 0; i < scount; i++) {
//			printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//				staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//	}
//	staffHeader(0);
//
//	printf("\n=====================\n");
//	printf("| Delete staff info | \n");
//	printf("=====================\n");
//	printf("Enter staff id to delete :");
//	rewind(stdin);
//	scanf("%[^\n]", &dltid);
//
//	if (strcmp(loginStaffID, dltid) == 0) {
//		printf("**Can't delete yourself!**\n\n");
//	}
//	else {
//		for (int i = 0; i < scount; i++) {
//			if (strcmp(dltid, staffarr[i].staffid) == 0) {
//				staffHeader(1);
//				printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%2d-%d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//					staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//				staffHeader(0);
//				break;
//			}
//			else if (i == (scount - 1)) {
//				printf("**Staff id < %s > does not exist.**\n\n", dltid);
//				return;
//			}
//		}
//
//		printf("\nConfirm delete this staff account? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &confirmation);
//		if (toupper(confirmation) == 'Y') {
//			for (int i = 0; i < scount; i++) {
//				printf("%d\n", i);
//				//copy the data information of staff into modified array except the delete staff data
//				if (strcmp(dltid, staffarr[i].staffid) != 0) {
//					strcpy(modifiedstaff[n].staffid, staffarr[i].staffid);
//					strcpy(modifiedstaff[n].name, staffarr[i].name);
//					modifiedstaff[n].gender = staffarr[i].gender;
//					strcpy(modifiedstaff[n].email, staffarr[i].email);
//					strcpy(modifiedstaff[n].password, staffarr[i].password);
//					strcpy(modifiedstaff[n].phnum, staffarr[i].phnum);
//					strcpy(modifiedstaff[n].ic, staffarr[i].ic);
//					strcpy(modifiedstaff[n].position, staffarr[i].position);
//					modifiedstaff[n].date.day = staffarr[i].date.day;
//					modifiedstaff[n].date.month = staffarr[i].date.month;
//					modifiedstaff[n].date.year = staffarr[i].date.year;
//					n++;
//
//					dltfile2 = fopen("staff.dat", "wb");
//					if (dltfile == NULL) {
//						printf("Error while opening the file\n");
//						return -1;
//					}
//					if (toupper(confirmation) == 'Y') {
//						//write the data back to the binary file
//						for (int i = 0; i < n; i++) {
//							fwrite(&modifiedstaff[i], sizeof(staffs), 1, dltfile2);
//						}
//						;
//						fclose(dltfile2);
//					}
//					else {
//						dltcount++;
//					}
//				}
//				else {
//					//save the deleted staff data into deletedstaff array
//					strcpy(deletedstaff[d].staffid, staffarr[i].staffid);
//					strcpy(deletedstaff[d].name, staffarr[i].name);
//					deletedstaff[d].gender = staffarr[i].gender;
//					strcpy(deletedstaff[d].email, staffarr[i].email);
//					strcpy(deletedstaff[d].password, staffarr[i].password);
//					strcpy(deletedstaff[d].phnum, staffarr[i].phnum);
//					strcpy(deletedstaff[d].ic, staffarr[i].ic);
//					strcpy(deletedstaff[d].position, staffarr[i].position);
//					deletedstaff[d].date.day = staffarr[i].date.day;
//					deletedstaff[d].date.month = staffarr[i].date.month;
//					deletedstaff[d].date.year = staffarr[i].date.year;
//					d++;
//
//					binfile = fopen("staffbin.dat", "ab");
//					if (binfile == NULL) {
//						printf("Error while opening the file\n");
//						return -1;
//					}
//					//save the deleted staff data into bin binary file
//					for (int j = 0; j < d; j++) {
//						fwrite(&deletedstaff[j], sizeof(staffs), 1, binfile);
//					}
//					printf("%d account added to bin\n", d);
//					fclose(binfile);
//				}
//
//			}
//			printf("Staff id :%s deleted.\n", dltid);
//			printf("%d staff account had been deleted.\n", scount - n);
//		}
//		else {
//			printf("**Cancelled**\n");
//			return;
//		}
//	}
//
//	return staffMenu();
//}
//
//void staffReport() {
//	FILE* reportfile;
//	SYSTEMTIME time;
//	int scount = 0, choice;
//	char anotherrchoice, monthword[20];
//	int monthlyr, monthlyryear, monthlyrcount = 0, yearlyr, yearlyrcount = 0;
//	char staffidr[6], curra;
//	double commision;
//
//	reportfile = fopen("staff.dat", "rb");
//	if (reportfile == NULL) {
//		printf("Error while opening the file\n");
//		return -1;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, reportfile) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	fclose(reportfile);
//
//	GetLocalTime(&time);
//
//	do {
//		printf("\n");
//		printf("             Report\n");
//		printf("=================================\n");
//		printf("| 1 - New staff monthly report  |\n");
//		printf("| 2 - New staff yearly report   |\n");
//		printf("| 3 - Personal commision report |\n");
//		printf("| 4 - Back                      |\n");
//		printf("=================================\n");
//		printf("Enter your choice > ");
//		rewind(stdin);
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			do {
//				printf("Enter year : ");
//				rewind(stdin);
//				scanf("%d", &monthlyryear);
//				if (monthlyryear < 2000 || monthlyryear > 2024) {
//					printf("**Invalid year**\n");
//				}
//			} while (monthlyryear < 2000 || monthlyryear > 2024);
//			do {
//				printf("Enter month : ");
//				rewind(stdin);
//				scanf("%d", &monthlyr);
//				if (monthlyr > 12 || monthlyr <= 0) {
//					printf("**Invalid month**\n");
//				}
//			} while (monthlyr > 12 || monthlyr <= 0);
//
//			switch (monthlyr) {
//			case 1:
//				strcpy(monthword, "January");
//				break;
//			case 2:
//				strcpy(monthword, "February");
//				break;
//			case 3:
//				strcpy(monthword, "March");
//				break;
//			case 4:
//				strcpy(monthword, "April");
//				break;
//			case 5:
//				strcpy(monthword, "May");
//				break;
//			case 6:
//				strcpy(monthword, "June");
//				break;
//			case 7:
//				strcpy(monthword, "July");
//				break;
//			case 8:
//				strcpy(monthword, "August");
//				break;
//			case 9:
//				strcpy(monthword, "September");
//				break;
//			case 10:
//				strcpy(monthword, "October");
//				break;
//			case 11:
//				strcpy(monthword, "November");
//				break;
//			case 12:
//				strcpy(monthword, "December");
//				break;
//			default:
//				strcpy(monthword, "**Error**");
//				break;
//			}
//			int foundrmdate = 0;
//			printf("----------------------------\n");
//			printf("| New staff monthly report |\n");
//			printf("----------------------------\n\n");
//			printf("                                                    List of new joined staff at month of %s-%d\n", monthword, monthlyryear);
//			printf("                                                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
//			printf("===================                                                                                                                  ================\n");
//			printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
//				time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
//			printf("===================                                                                                                                  ================\n\n");
//			staffHeader(1);
//			for (int i = 0; i < scount; i++) {
//				if (monthlyr == staffarr[i].date.month && monthlyryear == staffarr[i].date.year) {
//					foundrmdate = 1;
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, 
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					monthlyrcount++;
//				}
//			}
//			staffHeader(0);
//			if (foundrmdate != 1) {
//				printf("\n**Date < %s-%d > no staff join**\n\n", monthword, monthlyryear);
//			}
//			break;
//		case 2:
//			do {
//				printf("Enter year : ");
//				rewind(stdin);
//				scanf("%d", &yearlyr);
//				if (yearlyr < 2000 || yearlyr > 2024) {
//					printf("**Invalid year**\n");
//				}
//			} while (yearlyr < 2000 || yearlyr > 2024);
//			int foundrydate = 0;
//			printf("---------------------------\n");
//			printf("| New staff yearly report |\n");
//			printf("---------------------------\n\n");
//			printf("                                               List of new joined staff at year of %d\n", yearlyr);
//			printf("                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
//			printf("===================                                                                                                                  ================\n");
//			printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
//				time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
//			printf("===================                                                                                                                  ================\n\n");
//			staffHeader(1);
//			for (int i = 0; i < scount; i++) {
//				if (yearlyr == staffarr[i].date.year) {
//					foundrydate = 1;
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, 
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					yearlyrcount++;
//				}
//			}
//			staffHeader(0);
//			if (foundrydate != 1) {
//				printf("\n**Date < %d > no staff join**\n\n", yearlyr);
//			}
//			break;
//		case 3:
//			//enter user id
//			for (int i = 0; i < scount; i++) {
//				if (strcmp(loginStaffID, staffarr[i].staffid) == 0) {
//
//					printf("Personal commission report\n");
//					printf("--------------------------\n\n");
//					printf("                                                      '%s' personal commission report\n", loginStaffID);
//					printf("                                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
//
//					printf("===================                                                                                                                  ================\n");
//					printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
//						time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
//					printf("===================                                                                                                                  ================\n\n");
//
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, 
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//					break;
//				}
//			}
//			//display sales of this staff
//			return staffMenu();
//			break;
//		case 4:
//			return staffMenu();
//			break;
//		default:
//			printf("**Please enter valid choice.**\n");
//			return staffReport();
//			break;
//		}
//
//		printf("View another report? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &anotherrchoice);
//	} while (toupper(anotherrchoice) == 'Y');
//}
//
//void staffReportStaff() {
//	FILE* reportfile;
//	SYSTEMTIME time;
//	int scount = 0, choice;
//	char anotherrchoice, monthword[20];
//	int monthlyr, monthlyryear, monthlyrcount = 0, yearlyr, yearlyrcount = 0;
//	char staffidr[6], curra;
//	double commision;
//
//	reportfile = fopen("staff.dat", "rb");
//	if (reportfile == NULL) {
//		printf("E while opening the file\n");
//		return -1;
//	}
//
//	while (fread(&staff, sizeof(staffs), 1, reportfile) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	fclose(reportfile);
//
//	GetLocalTime(&time);
//
//	do {
//		printf("\n");
//		printf("             Report\n");
//		printf("=================================\n");
//		printf("| 1 - Personal Commision Report |\n");
//		printf("| 2 - Back                      |\n");
//		printf("=================================\n");
//		printf("Enter your choice > ");
//		rewind(stdin);
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			//enter user id
//			for (int i = 0; i < scount; i++) {
//				if (strcmp(loginStaffID, staffarr[i].staffid) == 0) {
//
//					printf("Personal commission report\n");
//					printf("--------------------------\n\n");
//					printf("                                                      '%s' personal commission report\n", loginStaffID);
//					printf("                                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
//
//					printf("===================                                                                                                                  ================\n");
//					printf("| Date: %02d-%02d-%d |                                                                                                                 | Time: %d:%02d  |\n",
//						time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
//					printf("===================                                                                                                                  ================\n\n");
//
//					staffHeader(1);
//					printf("%-10s%-25s%-8c%-30s%-20s%-15s%-20s%-10s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password,
//						staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//					staffHeader(0);
//					break;
//				}
//			}
//			//display sales of this staff
//			return staffMenu();
//			break;
//		case 2:
//			return staffMenu();
//			break;
//		default:
//			printf("**Please enter valid choice!**\n");
//			return staffReport();
//			break;
//		}
//
//		printf("View another report? ( Y = yes / N = no ) >");
//		rewind(stdin);
//		scanf("%c", &anotherrchoice);
//	} while (toupper(anotherrchoice) == 'Y');
//}
//
//void staffRestore() {
//	FILE* restorefile, * addfile, * dltrestorefile, * clearfile;
//	int scount = 0;
//	char dltdstaffid[10];
//	char confirmation;
//	int i = 0, found = 0;
//	staffs binstaff[10];
//	int n = 0;
//	int restorechoice;
//	char confirmation2;
//
//	restorefile = fopen("staffbin.dat", "rb");
//	if (restorefile == NULL) {
//		printf("Error while opening the file\n");
//		exit(0);
//	}
//	//store deleted staff details into staff array
//	while (fread(&staff, sizeof(staffs), 1, restorefile) != 0) {
//		strcpy(staffarr[scount].staffid, staff.staffid);
//		strcpy(staffarr[scount].name, staff.name);
//		staffarr[scount].gender = staff.gender;
//		strcpy(staffarr[scount].email, staff.email);
//		strcpy(staffarr[scount].password, staff.password);
//		strcpy(staffarr[scount].phnum, staff.phnum);
//		strcpy(staffarr[scount].ic, staff.ic);
//		strcpy(staffarr[scount].position, staff.position);
//		staffarr[scount].date.day = staff.date.day;
//		staffarr[scount].date.month = staff.date.month;
//		staffarr[scount].date.year = staff.date.year;
//		scount++;
//	}
//	printf("             Restore Menu\n");
//	printf("=====================================\n");
//	printf("| 1 - Restore deleted staff account |\n");
//	printf("| 2 - Back                          |\n");
//	printf("=====================================\n");
//	printf("Enter your choice > ");
//	scanf("%d", &restorechoice);
//	switch (restorechoice) {
//	case 1:
//		printf("                                                                Deleted account list \n");
//		printf("                                                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
//		staffHeader(1);
//		for (i = 0; i < scount; i++) {
//			printf("%-10s%-25s%-8c%-35s%-10s%-20s%-15s%-15s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, 
//				staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//		}
//		staffHeader(0);
//
//		printf("=================================\n");
//		printf("| Restore deleted staff account |\n");
//		printf("=================================\n");
//		printf("Enter staff id to restore staff : ");
//		rewind(stdin);
//		scanf("%[^\n]", &dltdstaffid);
//		//run whole array to check selected staff id
//		for (i = 0; i < scount; i++) {
//			if (strcmp(dltdstaffid, staffarr[i].staffid) == 0) {
//				found = 1;
//				break;
//			}
//		}
//		//if staff id not found
//		if (found != 1) {
//			printf("**< %s > does not exist in bin file.**\n", dltdstaffid);
//			return staffMenu();
//		}
//		staffHeader(1);
//		//prompt selected staff details
//		for (i = 0; i < scount; i++) {
//			if (strcmp(dltdstaffid, staffarr[i].staffid) == 0) {
//				printf("%-10s%-25s%-8c%-35s%-10s%-20s%-15s%-15s%02d-%02d-%d\n", staffarr[i].staffid, staffarr[i].name, staffarr[i].gender, staffarr[i].email, staffarr[i].password, 
//					staffarr[i].phnum, staffarr[i].ic, staffarr[i].position, staffarr[i].date.day, staffarr[i].date.month, staffarr[i].date.year);
//			}
//		}
//		staffHeader(0);
//		printf("\nConfirm restore this deleted staff account? ( Y = yes / N = no ) > ");
//		rewind(stdin);
//		scanf("%c", &confirmation);
//		if (toupper(confirmation) == 'Y') {
//			//append selected staff details back to staff file
//			addfile = fopen("staff.dat", "ab");
//			if (addfile == NULL) {
//				printf("Error while opening the file\n");
//				exit(0);
//			}
//			for (i = 0; i < scount; i++) {
//				if (strcmp(dltdstaffid, staffarr[i].staffid) == 0) {
//					fwrite(&staffarr[i], sizeof(staffs), 1, addfile);
//					printf("Account had restore successfully!\n");
//					fclose(addfile);
//				}
//				else {
//					//copy the staff info that not selected by user based on deletedstaddid the a new array call binstaff
//					strcpy(binstaff[n].staffid, staffarr[i].staffid);
//					strcpy(binstaff[n].name, staffarr[i].name);
//					binstaff[n].gender = staffarr[i].gender;
//					strcpy(binstaff[n].email, staffarr[i].email);
//					strcpy(binstaff[n].password, staffarr[i].password);
//					strcpy(binstaff[n].phnum, staffarr[i].phnum);
//					strcpy(binstaff[n].ic, staffarr[i].ic);
//					strcpy(binstaff[n].position, staffarr[i].position);
//					binstaff[n].date.day = staffarr[i].date.day;
//					binstaff[n].date.month = staffarr[i].date.month;
//					binstaff[n].date.year = staffarr[i].date.year;
//					n++;
//				}
//			}
//
//			dltrestorefile = fopen("staffbin.dat", "wb");
//			if (dltrestorefile == NULL) {
//				printf("Error while opening the file\n");
//				return -1;
//			}
//			for (int i = 0; i < n; i++) {
//				// write back the staff data that into the bin file that have to remain inside
//				fwrite(&binstaff[i], sizeof(staffs), 1, dltrestorefile);
//			}
//			fclose(dltrestorefile);
//		}
//		else {
//			printf("**Cancelled**\n");
//		}
//		break;
//	case 2:
//		return staffMenu();
//		break;
//	default:
//		printf("**Please enter valid input!**\n");
//		return staffRestore();
//	}
//}
//
//void staffHeader(int type) {
//	if (type == 1) {
//		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		printf("%-10s%-25s%-8s%-30s%-20s%-15s%-20s%-10s%-10s\n", "Staff ID", "Name", "Gender", "Email", "Password", "Phone Number", "IC No", "Position", "Date Joined");
//		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//	else {
//		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//}