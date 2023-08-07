//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<ctype.h>
//#include<windows.h>
//#pragma warning (disable : 4996)
//
////sales
//void salesOrder();
//void salesSearch();
//void salesModify();
//void salesDisplay();
//void salesDelete();
//void salesReport();
//void salesRestore();
//void changeLog(char changes[100]);
//void displayLog();
//void salesHeader();
//void salesFooter(int c);
//void reportHeader(char type[10], int year, int month, int day);
//int stockValidation(char itemCode[5]);
//
//typedef struct Sales {
//	char orderId[5], itemCode[10];
//	int qty;
//	double price;
//	char memberId[10], staffId[10];
//	double commission;
//	char date[11], time[11];
//	char status[10];
//} Sales;
//
//typedef struct Product {
//	char itemCode[10];
//	double itemPrice;
//} Product;
//
//Sales record;
//Product item;
//
//char current_memberId[10], current_staffId[10];
//
//main() {
//	int choice;
//
//	//temp
//	printf("Get member ID : ");
//	scanf("%s", current_memberId); //should be pass from member table
//	rewind(stdin);
//
//	printf("Upline (staff ID) : ");
//	scanf("%s", current_staffId);
//	rewind(stdin);
//
//	printf("\n");
//
//	do {
//		printf("SALES MENU\n");
//		printf("1. Create Sales Order\n");
//		printf("2. Search Sales Order\n");
//		printf("3. Modify Sales Order\n");
//		printf("4. Display Sales Order\n");
//		printf("5. Delete Sales Order\n");
//		printf("6. Generate Sales Report\n");
//		printf("7. Display Log\n");
//		printf("8. Restore\n");
//		printf("9. Exit\n"); //back
//		printf("Option > ");
//		scanf("%d", &choice);
//		printf("\n");
//
//		switch (choice) {
//		case 1:
//			salesOrder();
//			break;
//		case 2:
//			salesSearch();
//			break;
//		case 3:
//			salesModify();
//			break;
//		case 4:
//			salesDisplay();
//			break;
//		case 5:
//			salesDelete();
//			break;
//		case 6:
//			salesReport();
//			break;
//		case 7:
//			displayLog();
//			break;
//		case 8:
//			salesRestore();
//			break;
//		case 9:
//			exit(0);
//			break;
//		default:
//			printf("Please select between 1 to 9.\n\n");
//		}
//	} while (TRUE);
//}
//
////Main Module
//void salesOrder() {
//	char repeat, confirmation, changes[100];
//	int countSales = 0, valid = 0;
//
//	FILE* fptr, * fptr2, * fptr3, * fptr4;
//	fptr = fopen("salesOrder.txt", "r"); //to calculate number of current sales order
//	fptr2 = fopen("salesOrder.txt", "a"); //to append new sales order
//	fptr3 = fopen("salesBin.txt", "r"); //to calculate number of deleted sales order
//
//	if (fptr == NULL || fptr2 == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//	if (fptr3 == NULL) {
//		printf("Error while opening \"salesBin.txt\" file.\n");
//		exit(1);
//	}
//
//	//count number of current sales order
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//		countSales++;
//	}
//
//	//count number of deleted sales order
//	while (fscanf(fptr3, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//		countSales++;
//	}
//
//	do {
//		sprintf(record.orderId, "S%03d", countSales + 1); //current sales order id
//
//		//prompt and get item code
//		while (valid != 1) {
//			printf("Item Code : ");
//			scanf("%s", record.itemCode);
//			rewind(stdin);
//			valid = stockValidation(record.itemCode);
//		};
//
//		//prompt and get quantity
//		do {
//			printf("Quantity : ");
//			scanf("%d", &record.qty);
//			rewind(stdin);
//		} while (record.qty <= 0 || record.qty > 10);
//
//		//confirmation to place order
//		printf("Confirm to place order? (Y : yes) > ");
//		scanf("%c", &confirmation);
//		rewind(stdin);
//		printf("\n");
//
//		if (toupper(confirmation) == 'Y') {
//
//			//read stock file to get item price
//			fptr4 = fopen("product.txt", "r");
//			if (fptr4 == NULL) {
//				printf("Error while opening \"product.txt\" file.\n");
//				exit(1);
//			}
//
//			//calculate total Price
//			while (fscanf(fptr4, "%s %lf", &item.itemCode, &item.itemPrice) != EOF) {
//				if (strcmp(item.itemCode, record.itemCode) == 0) {
//					record.price = (double)record.qty * item.itemPrice;
//				}
//			}
//
//			//calculate commission
//			record.commission = record.price * 0.05;
//
//			fclose(fptr4);
//
//			//get current time
//			SYSTEMTIME t;
//			GetLocalTime(&t);
//			sprintf(record.date, "%02d-%02d-%04d", t.wDay, t.wMonth, t.wYear);
//			sprintf(record.time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);
//
//			//append sales order into file
//			fprintf(fptr2, "%s %s %d %.2f %s %s %.2f %s %s %s\n",
//				record.orderId, record.itemCode, record.qty, record.price, current_memberId, current_staffId, record.commission, record.date, record.time, "Pending");
//			printf("---Order ID '%s' is successfully added.---\n\n", record.orderId);
//			sprintf(changes, "Order ID '%s' is added.", record.orderId);
//			changeLog(changes);
//			countSales++;
//		}
//		else {
//			printf("---Order Declined.---\n\n");
//		}
//
//		//confirmation to repeat order
//		printf("Order again? (Y = yes) > ");
//		scanf("%c", &repeat);
//		rewind(stdin);
//		printf("\n");
//
//	} while (toupper(repeat) == 'Y');
//
//	fclose(fptr);
//	fclose(fptr2);
//}
//
//void salesSearch() {
//	int count = 0, choice;
//	char orderId[5], itemCode[10], memberId[10], staffId[10], status[10];
//
//	FILE* fptr;
//	fptr = fopen("salesOrder.txt", "r"); //to search specific sales order
//
//	if (fptr == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//
//	do {
//		//prompt and get field to search
//		printf("Field to Search: \n");
//		printf("1. Order ID\n");
//		printf("2. Item Code\n");
//		printf("3. Member ID\n");
//		printf("4. Staff ID\n");
//		printf("5. Status\n");
//		printf("6. Back\n");
//		printf("Select > ");
//		scanf("%d", &choice);
//		printf("\n");
//
//		switch (choice) {
//		case 1:
//			//search by sales order id
//			printf("Search by Sales Order ID : ");
//			scanf("%s", orderId);
//			rewind(stdin);
//
//			salesHeader();
//
//			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				if (strcmp(record.orderId, orderId) == 0) {
//
//					printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//					count++;
//				}
//			}
//			break;
//		case 2:
//			//search by item code
//			printf("Search by Item Code : ");
//			scanf("%s", itemCode);
//			rewind(stdin);
//
//			salesHeader();
//
//			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				if (strcmp(record.itemCode, itemCode) == 0) {
//
//					printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//					count++;
//				}
//			}
//			break;
//		case 3:
//			//search by member id
//			printf("Search by Member ID : ");
//			scanf("%s", memberId);
//			rewind(stdin);
//
//			salesHeader();
//
//			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				if (strcmp(record.memberId, memberId) == 0) {
//
//					printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//					count++;
//				}
//			}
//			break;
//		case 4:
//			//search by staff id
//			printf("Search by Staff ID : ");
//			scanf("%s", staffId);
//			rewind(stdin);
//
//			salesHeader();
//
//			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				if (strcmp(record.staffId, staffId) == 0) {
//
//					printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//					count++;
//				}
//			}
//			break;
//		case 5:
//			//search by status
//			printf("Search by Status : ");
//			scanf("%s", status);
//			rewind(stdin);
//
//			salesHeader();
//
//			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				if (strcmp(record.status, status) == 0) {
//
//					printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//					count++;
//				}
//			}
//			break;
//		case 6:
//			break;
//		default:
//			printf("Please select between 1 to 6.\n\n");
//		}
//	} while (choice < 1 || choice > 6);
//
//	if (choice >= 0 && choice <= 5) {
//		salesFooter(count);
//	}
//	fclose(fptr);
//}
//
//void salesModify() { //haven't add confirmation
//	int i = 0, choice;
//	char orderId[5], changes[100], field[10];
//	Sales modified[100];
//
//	FILE* fptr, * fptr2, * fptr3;
//	fptr = fopen("salesOrder.txt", "r"); //to validate
//
//	if (fptr == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//
//	salesDisplay();
//
//	//prompt and get order id to modify
//	printf("Enter Order ID to modify : ");
//	scanf("%s", orderId);
//
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//		if (strcmp(record.orderId, orderId) != 0) {
//
//			//copy non-modified value to modidified array
//			strcpy(modified[i].orderId, record.orderId);
//			strcpy(modified[i].itemCode, record.itemCode);
//			modified[i].qty = record.qty;
//			modified[i].price = record.price;
//			strcpy(modified[i].memberId, record.memberId);
//			strcpy(modified[i].staffId, record.staffId);
//			modified[i].commission = record.commission;
//			strcpy(modified[i].date, record.date);
//			strcpy(modified[i].time, record.time);
//			strcpy(modified[i].status, record.status);
//			i++;
//		}
//		else if (strcmp(record.orderId, orderId) == 0) {
//			do {
//				//prompt selected sales order
//				salesHeader();
//				printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//					record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//				salesFooter(1);
//
//				//prompt menu of field to modify
//				printf("Field to Modify:\n");
//				printf("1. Item Code\n");
//				printf("2. Quantity\n");
//				printf("3. Status\n");
//				printf("4. Back\n");
//				printf("Select > ");
//				scanf("%d", &choice);
//				printf("\n");
//
//				//get modified value
//				switch (choice) {
//				case 1:
//					printf("New item code: ");
//					scanf("%s", record.itemCode);
//					strcpy(field, "item code");
//					break;
//				case 2:
//					printf("New Quantity: ");
//					scanf("%d", &record.qty);
//					strcpy(field, "quantity");
//					break;
//				case 3:
//					printf("New Status: ");
//					scanf("%s", record.status);
//					strcpy(field, "status");
//					break;
//				case 4:
//					break;
//				default:
//					printf("Please select between 1 to 4.\n\n");
//				}
//			} while (choice < 1 || choice > 4);
//
//			//read product file
//			fptr2 = fopen("product.txt", "r");
//			if (fptr2 == NULL) {
//				printf("Error while opening \"product.txt\" file.\n");
//				exit(1);
//			}
//
//			//get item price to calculate price
//			while (fscanf(fptr2, "%s %lf", &item.itemCode, &item.itemPrice) != EOF) {
//				if (strcmp(item.itemCode, record.itemCode) == 0) {
//					record.price = (double)record.qty * item.itemPrice;
//				}
//			}
//
//			record.commission = record.price * 0.05; //calculate commission
//			fclose(fptr2);
//
//			//copy modified value to modidified array
//			strcpy(modified[i].orderId, record.orderId);
//			strcpy(modified[i].itemCode, record.itemCode);
//			modified[i].qty = record.qty;
//			modified[i].price = record.price;
//			strcpy(modified[i].memberId, record.memberId);
//			strcpy(modified[i].staffId, record.staffId);
//			modified[i].commission = record.commission;
//			strcpy(modified[i].date, record.date);
//			strcpy(modified[i].time, record.time);
//			strcpy(modified[i].status, record.status);
//			i++;
//
//			//append changes to change log
//			if (strcmp("item code", field) == 0) {
//				printf("Order ID '%s', %s is modified to '%s'.\n\n", orderId, field, record.itemCode);
//				sprintf(changes, "Order ID '%s', %s is modified to '%s'.", orderId, field, record.itemCode);
//			}
//			else if (strcmp("quantity", field) == 0) {
//				printf("Order ID '%s', %s is modified to '%d'.\n\n", orderId, field, record.qty);
//				sprintf(changes, "Order ID '%s', %s is modified to '%d'.", orderId, field, record.qty);
//			}
//			else if (strcmp("status", field) == 0) {
//				printf("Order ID '%s', %s is modified to '%s'.\n\n", orderId, field, record.status);
//				sprintf(changes, "Order ID '%s', %s is modified to '%s'.", orderId, field, record.status);
//			}
//			changeLog(changes);
//		}
//	}
//	fclose(fptr);
//
//	fptr3 = fopen("salesOrder.txt", "w");
//	if (fptr3 == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//
//	//write modified sales order to file
//	for (int n = 0; n < i; n++) {
//		fprintf(fptr3, "%s %s %d %.2f %s %s %.2f %s %s %s\n",
//			modified[n].orderId, modified[n].itemCode, modified[n].qty, modified[n].price, modified[n].memberId, modified[n].staffId, modified[n].commission,
//			modified[n].date, modified[n].time, modified[n].status);
//	}
//	fclose(fptr3);
//	printf("\n");
//}
//
//void salesDisplay() {
//	int count = 0;
//	FILE* fptr;
//	fptr = fopen("salesOrder.txt", "r"); //to get all sales order
//
//	if (fptr == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//
//	salesHeader();
//
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//		//display all sales order		
//		printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//			record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//		count++;
//	}
//
//	salesFooter(count);
//	fclose(fptr);
//}
//
//void salesDelete() {
//	int i = 0;
//	char orderId[5], confirmation, changes[100];
//	Sales modified[100], delete;
//
//	FILE* fptr, * fptr2, * fptr3;
//	fptr = fopen("salesOrder.txt", "r"); //to validate
//	fptr2 = fopen("salesBin.txt", "a"); //to append deleted sales order
//
//	salesDisplay();
//	printf("Enter Order ID to delete : ");
//	rewind(stdin);
//	scanf("%s", orderId);
//	rewind(stdin);
//	printf("\n");
//
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//		//record orderId not equal to input orderId save to modified array
//		if (strcmp(record.orderId, orderId) != 0) {
//
//			strcpy(modified[i].orderId, record.orderId);
//			strcpy(modified[i].itemCode, record.itemCode);
//			modified[i].qty = record.qty;
//			modified[i].price = record.price;
//			strcpy(modified[i].memberId, record.memberId);
//			strcpy(modified[i].staffId, record.staffId);
//			modified[i].commission = record.commission;
//			strcpy(modified[i].date, record.date);
//			strcpy(modified[i].time, record.time);
//			strcpy(modified[i].status, record.status);
//			i++;
//		}
//		//selected order id save to bin file
//		else if (strcmp(record.orderId, orderId) == 0) {
//
//			strcpy(delete.orderId, record.orderId);
//			strcpy(delete.itemCode, record.itemCode);
//			delete.qty = record.qty;
//			delete.price = record.price;
//			strcpy(delete.memberId, record.memberId);
//			strcpy(delete.staffId, record.staffId);
//			delete.commission = record.commission;
//			strcpy(delete.date, record.date);
//			strcpy(delete.time, record.time);
//			strcpy(delete.status, record.status);
//		}
//	}
//
//	fseek(fptr, 0, SEEK_SET);
//
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//		if (strcmp(record.orderId, orderId) == 0) {
//			//show selected sales record
//			salesHeader();
//			printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//				record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//			salesFooter(1);
//
//			//confirmation to delete
//			printf("Are you sure to delete this sales order? (Y : yes) > ");
//			scanf("%c", &confirmation);
//			rewind(stdin);
//
//			if (confirmation == 'Y') {
//				fprintf(fptr2, "%s %s %d %.2f %s %s %.2f %s %s %s\n",
//					delete.orderId, delete.itemCode, delete.qty, delete.price, delete.memberId, delete.staffId, delete.commission, delete.date, delete.time, delete.status);
//
//				//write modified array back to sales file
//				fptr3 = fopen("salesOrder.txt", "w");
//				for (int n = 0; n < i; n++) {
//					fprintf(fptr3, "%s %s %d %.2f %s %s %.2f %s %s %s\n",
//						modified[n].orderId, modified[n].itemCode, modified[n].qty, modified[n].price, modified[n].memberId, modified[n].staffId, modified[n].commission,
//						modified[n].date, modified[n].time, modified[n].status);
//				}
//				printf("Order ID '%s' is deleted.\n\n", orderId);
//				sprintf(changes, "Order ID '%s' is deleted.", orderId);
//				changeLog(changes);
//				fclose(fptr3);
//			}
//			else {
//				printf("Delete Unsuccessful.\n\n");
//			}
//		}
//	}
//	fclose(fptr);
//	fclose(fptr2);
//}
//
//void salesReport() {
//	int count = 0, type, summary;
//	int in_year, in_month, in_day;
//	int sp_year, sp_month, sp_day;
//	char title[20];
//
//	FILE* fptr;
//	fptr = fopen("salesOrder.txt", "r");
//
//	if (fptr == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//
//	do {
//		//prompt and get type of report
//		printf("Types of report: \n");
//		printf("1. Summary Sales Report\n");
//		printf("2. Categorized Sales Report\n");
//		printf("3. Back\n");
//		printf("Select > ");
//		scanf("%d", &type);
//		printf("\n");
//
//		switch (type) {
//		case 1:
//			do {
//				//prompt and get type of summary report
//				printf("Types of summary report: \n");
//				printf("1. Yearly Sales Report\n");
//				printf("2. Monhtly Sales Report\n");
//				printf("3. Daily Sales Report\n");
//				printf("4. Back\n");
//				printf("Select > ");
//				scanf("%d", &summary);
//				printf("\n");
//
//				switch (summary) {
//				case 1:
//					//Yearly Sales Report
//					printf("Enter Year : ");
//					scanf("%d", &in_year);
//					rewind(stdin);
//					printf("\n");
//
//					reportHeader("Yearly", in_year, NULL, NULL);
//
//					while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//						sscanf(record.date, "%d-%d-%d", &sp_day, &sp_month, &sp_year);
//
//						if (in_year == sp_year) {
//
//							printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//								record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//							count++;
//						}
//					}
//					break;
//				case 2:
//					//Monthly Sales Report
//					printf("Enter Year : ");
//					scanf("%d", &in_year);
//					rewind(stdin);
//					printf("Enter Month (1-12) : ");
//					scanf("%d", &in_month);
//					rewind(stdin);
//
//					reportHeader("Monthly", in_year, in_month, NULL);
//
//					while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//						sscanf(record.date, "%d-%d-%d", &sp_day, &sp_month, &sp_year);
//
//						if (in_year == sp_year && in_month == sp_month) {
//
//							printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//								record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//							count++;
//						}
//					}
//					break;
//				case 3:
//					//Daily Sales Report
//					printf("Enter Year : ");
//					scanf("%d", &in_year);
//					rewind(stdin);
//					printf("Enter Month (1-12) : ");
//					scanf("%d", &in_month);
//					rewind(stdin);
//					printf("Enter Day   (1-31) : ");
//					scanf("%d", &in_day);
//					rewind(stdin);
//
//					reportHeader("Daily", in_year, in_month, in_day);
//
//					while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//						sscanf(record.date, "%d-%d-%d", &sp_day, &sp_month, &sp_year);
//
//						if (in_year == sp_year && in_month == sp_month && in_day == sp_day) {
//
//							printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//								record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//							count++;
//						}
//					}
//					break;
//				case 4:
//					break;
//				default:
//					printf("Please select between 1 to 4.\n\n");
//				}
//			} while (summary < 1 || summary > 4);
//			break;
//		case 2:
//			/*printf("Search by Staff ID : ");
//			scanf("%s", );
//			rewind(stdin);
//
//			salesHeader();
//
//			while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				if (strcmp(record.staffId, staffId) == 0) {
//
//					printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//						record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//					count++;
//				}
//			}*/
//			break;
//		case 3:
//			break;
//		default:
//			printf("Please select between 1 to 3.\n\n");
//		}
//	} while (type < 1 || type >3);
//
//	if (type >= 0 && type <= 2) {
//		salesFooter(count);
//	}
//	fclose(fptr);
//}
//
////Additional Module
//void salesRestore() {
//	int i = 0, n = 0, count = 0, once = 0;
//	int restore_orderId, record_orderId;
//	char orderId[5], changes[100], confirmation;
//	Sales deleted[50];
//	Sales restore;
//	Sales modified[50];
//
//	FILE* fptr, * fptr2, * fptr3, * fptr4;
//	fptr = fopen("salesBin.txt", "r"); //to get all delete history log and validation
//	if (fptr == NULL) {
//		printf("Error while opening \"salesBin.txt\" file.\n");
//		exit(1);
//	}
//
//	//display delete history log
//	printf("-----Sales Order Delete History Log-----\n");
//	salesHeader();
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//		printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//			record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//		count++;
//	}
//	salesFooter(count);
//	fseek(fptr, 0, SEEK_SET);
//
//	if (count > 0) {
//		printf("Restore by Sales Order ID : ");
//		scanf("%s", orderId);
//		rewind(stdin);
//	
//		while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//			record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//			if (strcmp(record.orderId, orderId) == 0) {
//
//				fseek(fptr, 0, SEEK_SET);
//				while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//					record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//					//record orderId not equal to input orderId save to deleted array
//					if (strcmp(record.orderId, orderId) != 0) {
//
//						strcpy(deleted[i].orderId, record.orderId);
//						strcpy(deleted[i].itemCode, record.itemCode);
//						deleted[i].qty = record.qty;
//						deleted[i].price = record.price;
//						strcpy(deleted[i].memberId, record.memberId);
//						strcpy(deleted[i].staffId, record.staffId);
//						deleted[i].commission = record.commission;
//						strcpy(deleted[i].date, record.date);
//						strcpy(deleted[i].time, record.time);
//						strcpy(deleted[i].status, record.status);
//						i++;
//					}
//					//record orderId equal to input orderId copy to sturcture
//					else if (strcmp(record.orderId, orderId) == 0) {
//						strcpy(restore.orderId, record.orderId);
//						strcpy(restore.itemCode, record.itemCode);
//						restore.qty = record.qty;
//						restore.price = record.price;
//						strcpy(restore.memberId, record.memberId);
//						strcpy(restore.staffId, record.staffId);
//						restore.commission = record.commission;
//						strcpy(restore.date, record.date);
//						strcpy(restore.time, record.time);
//						strcpy(restore.status, record.status);
//					}
//				}
//
//				fclose(fptr);
//
//				fptr2 = fopen("salesOrder.txt", "r"); //to validate
//				if (fptr2 == NULL) {
//					printf("Error while opening \"salesOrder.txt\" file.\n");
//					exit(1);
//				}
//
//				//confirmation to delete
//				printf("Are you sure to restore this sales order? (Y : yes) > ");
//				scanf("%c", &confirmation);
//				rewind(stdin);
//
//				if (confirmation == 'Y') {
//
//					sscanf(restore.orderId, "S%d", &restore_orderId);
//
//					while (fscanf(fptr2, "%s %s %d %lf %s %s %lf %s %s %s",
//						record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//						sscanf(record.orderId, "S%d", &record_orderId);
//
//						//reallocate the sequence of order ID
//						if (record_orderId < restore_orderId) {
//							strcpy(modified[n].orderId, record.orderId);
//							strcpy(modified[n].itemCode, record.itemCode);
//							modified[n].qty = record.qty;
//							modified[n].price = record.price;
//							strcpy(modified[n].memberId, record.memberId);
//							strcpy(modified[n].staffId, record.staffId);
//							modified[n].commission = record.commission;
//							strcpy(modified[n].date, record.date);
//							strcpy(modified[n].time, record.time);
//							strcpy(modified[n].status, record.status);
//							n++;
//						}
//						else if (record_orderId > restore_orderId) {
//							if (once == 0) {
//								strcpy(modified[n].orderId, restore.orderId);
//								strcpy(modified[n].itemCode, restore.itemCode);
//								modified[n].qty = restore.qty;
//								modified[n].price = restore.price;
//								strcpy(modified[n].memberId, restore.memberId);
//								strcpy(modified[n].staffId, restore.staffId);
//								modified[n].commission = restore.commission;
//								strcpy(modified[n].date, restore.date);
//								strcpy(modified[n].time, restore.time);
//								strcpy(modified[n].status, restore.status);
//								once++;
//								n++;
//
//								strcpy(modified[n].orderId, record.orderId);
//								strcpy(modified[n].itemCode, record.itemCode);
//								modified[n].qty = record.qty;
//								modified[n].price = record.price;
//								strcpy(modified[n].memberId, record.memberId);
//								strcpy(modified[n].staffId, record.staffId);
//								modified[n].commission = record.commission;
//								strcpy(modified[n].date, record.date);
//								strcpy(modified[n].time, record.time);
//								strcpy(modified[n].status, record.status);
//							}
//							else {
//								strcpy(modified[n].orderId, record.orderId);
//								strcpy(modified[n].itemCode, record.itemCode);
//								modified[n].qty = record.qty;
//								modified[n].price = record.price;
//								strcpy(modified[n].memberId, record.memberId);
//								strcpy(modified[n].staffId, record.staffId);
//								modified[n].commission = record.commission;
//								strcpy(modified[n].date, record.date);
//								strcpy(modified[n].time, record.time);
//								strcpy(modified[n].status, record.status);
//							}
//							n++;
//						}
//					}
//					fclose(fptr2);
//
//					//write modified sales order to file
//					fptr3 = fopen("salesOrder.txt", "w");
//					if (fptr3 == NULL) {
//						printf("Error while opening \"salesOrder.txt\" file.\n");
//						exit(1);
//					}
//
//					for (int m = 0; m < n; m++) {
//						fprintf(fptr3, "%s %s %d %.2f %s %s %.2f %s %s %s\n",
//							modified[m].orderId, modified[m].itemCode, modified[m].qty, modified[m].price, modified[m].memberId, modified[m].staffId, modified[m].commission,
//							modified[m].date, modified[m].time, modified[m].status);
//					}
//					printf("Order ID '%s' is restored.\n\n", restore.orderId);
//					sprintf(changes, "Order ID '%s' is restored.", restore.orderId);
//					changeLog(changes);
//					fclose(fptr3);
//
//					fptr4 = fopen("salesBin.txt", "w");
//					if (fptr4 == NULL) {
//						printf("Error while opening \"salesOrder.txt\" file.\n");
//						exit(1);
//					}
//
//					for (int n = 0; n < i; n++) {
//						fprintf(fptr4, "%s %s %d %.2f %s %s %.2f %s %s %s\n",
//							deleted[n].orderId, deleted[n].itemCode, deleted[n].qty, deleted[n].price, deleted[n].memberId, deleted[n].staffId, deleted[n].commission,
//							deleted[n].date, deleted[n].time, deleted[n].status);
//					}
//					fclose(fptr4);
//				}
//				else {
//					printf("Restore Unsuccessful.\n\n");
//				}
//			}
//			else {
//				printf("Order ID not found.\n\n");
//			}
//		}
//	}
//	else {
//		printf("Nothing to restore.\n\n");
//	}
//}
//
//void changeLog(char changes[100]) {
//	char date[11], time[10];
//	FILE* fptr;
//	fptr = fopen("salesLog.txt", "a"); //to append changes
//
//	if (fptr == NULL) {
//		printf("Error while opening 'salesLog.txt' file.\n");
//		exit(1);
//	}
//
//	//get current date and time 
//	SYSTEMTIME t;
//	GetLocalTime(&t);
//	sprintf(date, "%02d-%02d-%02d", t.wDay, t.wMonth, t.wYear);
//	sprintf(time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);
//
//	fprintf(fptr, "%s | %s | %s \n", changes, date, time); //append changes into change log file
//
//	fclose(fptr);
//}
//
//void displayLog() {
//	int type, count = 0;
//	char log[100], date[11], time[9];
//	FILE* fptr, * fptr2;
//	fptr = fopen("salesLog.txt", "r"); //to get all change log
//	fptr2 = fopen("salesBin.txt", "r"); //to get all deleted sales order
//
//	if (fptr == NULL) {
//		printf("Error while opening 'salesLog.txt' file.\n");
//		exit(1);
//	}
//	if (fptr2 == NULL) {
//		printf("Error while opening 'salesOrder.txt' file.\n");
//		exit(1);
//	}
//
//	do {
//		//prompt and get type of log
//		printf("Types of Log: \n");
//		printf("1. Change Log\n");
//		printf("2. Delete History Log\n");
//		printf("3. Back\n");
//		printf("Select > ");
//		scanf("%d", &type);
//		printf("\n");
//
//		switch (type) {
//		case 1:
//			//change log
//			printf("%-55s %7s %9s\n", "Sales Order Change Log", "Date", "Time");
//			printf("------------------------------------------------------- ---------- --------\n");
//			while (fscanf(fptr, "%[^\|] | %s | %s \n", log, date, time) != EOF) {
//
//				//display change log
//				printf("%-55s %s %s\n", log, date, time);
//			}
//
//			printf("\n");
//			break;
//		case 2:
//			//delete history log
//			printf("-----Sales Order Delete History Log-----\n");
//			salesHeader();
//			while (fscanf(fptr2, "%s %s %d %lf %s %s %lf %s %s %s",
//				record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//				//display deleted sales order
//				printf("%-10s %-10s %-10d RM%8.2f %-10s %-10s RM%8.2f %-10s %-10s %-10s\n",
//					record.orderId, record.itemCode, record.qty, record.price, record.memberId, record.staffId, record.commission, record.date, record.time, record.status);
//				count++;
//			}
//			salesFooter(count);
//			printf("\n");
//			break;
//		case 3:
//			break;
//		default:
//			printf("Please select between 1 to 3.\n\n");
//			break;
//		}
//	} while (type < 1 || type > 3);
//
//	fclose(fptr);
//}
//
////Reuse Purpose
//void salesHeader() {
//	//display header
//	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
//		"==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========");
//	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
//		"Order ID", "Item Code", "Quantity", "Price", "Member ID", "Staff ID", "Commission", "Order Date", "Order Time", "Status");
//	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
//		"==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========");
//}
//
//void salesFooter(int c) {
//	//display footer
//	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
//		"==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========", "==========");
//	printf("< ");
//	if (c == 0) {
//		printf("No record found.");
//	}
//	else if (c == 1) {
//		printf("%d record listed.", c);
//	}
//	else if (c > 1) {
//		printf("%d records listed.", c);
//	}
//	else {
//		printf("Error.");
//	}
//	printf(" >\n\n");
//}
//
//void reportHeader(char type[10], int year, int month, int day) {
//	//dislplay report header
//	char current_date[11], current_time[9];
//
//	SYSTEMTIME t;
//	GetLocalTime(&t);
//	sprintf(current_date, "%02d-%02d-%04d", t.wDay, t.wMonth, t.wYear);
//	sprintf(current_time, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);
//
//	if (strcmp("Yearly", type) == 0) {
//		printf("\n-------------------------------------------- %s Sales Report --------------------------------------------\n", type);
//		printf("%53s , %d\n", "Year", year);
//	}
//	else if (strcmp("Monthly", type) == 0) {
//		printf("\n------------------------------------------- %s Sales Report --------------------------------------------\n", type);
//		printf("%51s , %02d-%d\n", "Month", month, year);
//	}
//	else if (strcmp("Daily", type) == 0) {
//		printf("\n--------------------------------------------- %s Sales Report ---------------------------------------------\n", type);
//		printf("%50s , %02d-%02d-%d\n", "Day", day, month, year);
//	}
//	printf("Staff: %s\n", current_staffId);
//	printf("Date: %s %77s Time: %s\n\n", current_date, " ", current_time);
//	salesHeader();
//}
//
////Validation Purpose
//int salesValidation(char orderId[5]) {
//	FILE* fptr;
//	fptr = fopen("salesOrder.txt", "r"); //to validate
//	if (fptr == NULL) {
//		printf("Error while opening \"salesOrder.txt\" file.\n");
//		exit(1);
//	}
//
//	while (fscanf(fptr, "%s %s %d %lf %s %s %lf %s %s %s",
//		record.orderId, record.itemCode, &record.qty, &record.price, record.memberId, record.staffId, &record.commission, record.date, record.time, record.status) != EOF) {
//
//		//validate if order id exist
//		if (strcmp(record.orderId, orderId) == 0) {
//			return 1;  //true
//		}
//	}
//	return 0; //false
//}
//
//int stockValidation(char itemCode[5]) {
//	FILE* fptr;
//	fptr = fopen("product.txt", "r"); //to validate
//	if (fptr == NULL) {
//		printf("Error while opening \"product.txt\" file.\n");
//		exit(1);
//	}
//
//	while (fscanf(fptr, "%s %lf", &item.itemCode, &item.itemPrice) != EOF) {
//
//		//validate if item code exist
//		if (strcmp(item.itemCode, itemCode) == 0) {
//			return 1; //true
//		}
//	}
//	return 0; //false
//}