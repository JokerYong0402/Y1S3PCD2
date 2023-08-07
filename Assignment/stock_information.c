//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <windows.h>
//#pragma warning (disable : 4996)
//
//void addStock();
//void searchStock();
//void modifyStock();
//void displayStock();
//void reportStock();
//void deleteStock();
//void modifyHistory();
//void deleteHistory();
//int valid();
//int valid1();
//char valid2();
//int valid3();
//int valid4();
//int valid5();
//
//char v;
//
//struct Stock {
//	char itemCode[5], itemName[30], itemCategory[20];
//	int qtyInStock, minLvl, reorderQty;
//	double itemPrice;
//}records;
//
//struct Stock store[100];
//
//void main() {
//	int ans;
//	//printf("WELCOME TO STOCK INFORMATION MODULE!\n");
//	//printf("====================================\n\n");
//	do {
//		printf("        Stock Menu \n");
//		printf("============================\n");
//		printf("Add Stock Record      -> 1\n");
//		printf("Search Stock Records  -> 2\n");
//		printf("Modify Stock Records  -> 3\n");
//		printf("Display Stock Records -> 4\n");
//		printf("Create Stock Reports  -> 5\n");
//		printf("Delete Stock Records  -> 6\n");
//		printf("Modify Stock History  -> 7\n");
//		printf("Delete Stock History  -> 8\n");
//		printf("Exit Program          -> 9\n");
//		printf("============================\n");
//		printf("Select > ");
//		ans = valid1();
//		switch (ans) {
//		case 1:
//			addStock();
//			break;
//		case 2:
//			searchStock();
//			break;
//		case 3:
//			modifyStock();
//			break;
//		case 4:
//			displayStock();
//			break;
//		case 5:
//			reportStock();
//			break;
//		case 6:
//			deleteStock();
//			break;
//		case 7:
//			modifyHistory();
//			break;
//		case 8:
//			deleteHistory();
//			break;
//		case 9:
//			exit(-1);
//			break;
//
//		}
//	} while (ans != 9);
//}
//
//void addStock() {
//	char ans2, ans;
//	int count = 0, i = 0, cat;
//
//	FILE* stock;
//	stock = fopen("stock.txt", "a"); //to store the new stock records
//
//	if (stock == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	printf("\nAdd Stock Record Function");
//	printf("\n=========================\n");
//
//	do {
//		do {
//			FILE* check;
//			check = fopen("stock.txt", "r");//to check the 
//
//			if (check == NULL) {
//				printf("Error while opening the file");
//				exit(-1);
//			}
//
//			//store in a array as a record
//			while (fscanf(check, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", 
//				store[i].itemCode, store[i].itemName, store[i].itemCategory, &store[i].itemPrice, &store[i].qtyInStock, &store[i].minLvl, &store[i].reorderQty) != EOF) {
//				i++;
//			}
//
//			printf("Enter Item Code > ");
//			rewind(stdin);
//			scanf("%s", records.itemCode);
//
//			//check whether the item code is exist in the array
//			for (int n = 0; n < i; n++) {
//				if (strcmp(records.itemCode, store[n].itemCode) == 0) {
//					printf("Stock %s has been added. Please retry.\n", records.itemCode);
//					v = 'I';
//					n = i;
//				}
//				else {
//					v = 'V';
//				}
//			}
//			fclose(check);
//			//update the value of i back to original
//			i = 0;
//		} while (v == 'I');
//
//		printf("Enter Item Name > ");
//		rewind(stdin);
//		scanf("%[^\n]", records.itemName);
//		printf("Category\n");
//		printf("---------------------\n");
//		printf("1. food\n");
//		printf("2. drink\n");
//		printf("3. shirt\n");
//		printf("4. pants\n");
//		printf("5. shoes\n");
//		printf("---------------------\n");
//		printf("Enter Item Category > ");
//		rewind(stdin);
//		cat = valid5();
//		switch (cat) {
//		case 1:
//			strcpy(records.itemCategory, "Food");
//			break;
//		case 2:
//			strcpy(records.itemCategory, "Drink");
//			break;
//		case 3:
//			strcpy(records.itemCategory, "Shirt");
//			break;
//		case 4:
//			strcpy(records.itemCategory, "Pants");
//			break;
//		case 5:
//			strcpy(records.itemCategory, "Shoes");
//			break;
//		}
//		printf("Enter Item Price > ");
//		rewind(stdin);
//		scanf("%lf", &records.itemPrice);
//		printf("Enter Quantity in Stock > ");
//		rewind(stdin);
//		scanf("%d", &records.qtyInStock);
//		printf("Enter Minimum Level > ");
//		rewind(stdin);
//		scanf("%d", &records.minLvl);
//		printf("Enter Reorder Quantity > ");
//		rewind(stdin);
//		scanf("%d", &records.reorderQty);
//		printf("\nAre you sure you want to add this stock? (Y=Yes|N=No) > ");
//		ans = valid2();
//		//if user confirm to add the stock
//		if (toupper(ans) == 'Y') {
//			//append the new stock record into the file
//			fprintf(stock, "%s|%s|%s|%.2lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//			printf("\nStock %s added successfully!\n\n", records.itemCode);
//			count++;//for number of new record added
//		}
//		else {
//			printf("\nAdd Stock Record Failed\n\n");
//		}
//		printf("Add another record? (Y=Yes|N=No) >");
//		ans2 = valid2();
//	} while (toupper(ans2) == 'Y');
//
//	printf("\n%d record(s) added!\n\n", count);
//	fclose(stock);
//}
//
//void searchStock() {
//	char ans1;
//	int n = 0, ans, cat;
//
//	struct Search {
//		char itemCode[5], itemName[30], itemCategory[20];
//		int qtyInStock, minLvl, reorderQty;
//		double itemPrice;
//	}search;
//
//	printf("\nSearch Stock Function\n");
//	printf("=====================\n");
//	do {
//		FILE* stock;
//		stock = fopen("stock.txt", "r");
//
//		if (stock == NULL) {
//			printf("Error while opening the file");
//			exit(-1);
//		}
//
//		printf("Select a field to search for the stock :\n");
//		printf("========================================\n");
//		printf("Item Code         -> 1\n");
//		printf("Item Name         -> 2\n");
//		printf("Item Category     -> 3\n");
//		printf("Item Price        -> 4\n");
//		printf("Quantity In Stock -> 5\n");
//		printf("Minimum Level     -> 6\n");
//		printf("Reorder Stock     -> 7\n");
//		printf("Back              -> 8\n");
//		printf("Field > ");
//		ans = valid();
//		switch (ans) {
//		case 1:
//			printf("Enter Item Code > ");
//			rewind(stdin);
//			scanf("%s", search.itemCode);
//			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				//read from the file
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				//if the item code of the record that user wanted to search for same as the item record in the record
//				if (strcmp(search.itemCode, records.itemCode) == 0) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;//calculate number of stock record
//				}
//			}
//			switch (n) {
//			case 0://if no record found
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 2:
//			printf("Enter Item Name > ");
//			rewind(stdin);
//			scanf("%[^\n]", search.itemName);
//			printf("Item code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				if (strcmp(search.itemName, records.itemName) == 0) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;
//				}
//			}
//			switch (n) {
//			case 0:
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 3:
//			printf("Category\n");
//			printf("---------------------\n");
//			printf("1. food\n");
//			printf("2. drink\n");
//			printf("3. shirt\n");
//			printf("4. pants\n");
//			printf("5. shoes\n");
//			printf("---------------------\n");
//			printf("Enter Item Category > ");
//			rewind(stdin);
//			cat = valid5();
//			switch (cat) {
//			case 1:
//				strcpy(search.itemCategory, "food");
//				break;
//			case 2:
//				strcpy(search.itemCategory, "drink");
//				break;
//			case 3:
//				strcpy(search.itemCategory, "shirt");
//				break;
//			case 4:
//				strcpy(search.itemCategory, "pants");
//				break;
//			case 5:
//				strcpy(search.itemCategory, "shoes");
//				break;
//			}
//
//			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				if (strcmp(search.itemCategory, records.itemCategory) == 0) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;
//				}
//			}
//			switch (n) {
//			case 0:
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 4:
//			printf("Enter Item Price > ");
//			rewind(stdin);
//			scanf("%lf", &search.itemPrice);
//			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				if (search.itemPrice == records.itemPrice) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;
//				}
//			}
//			switch (n) {
//			case 0:
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 5:
//			printf("Enter Quantity in Stock > ");
//			rewind(stdin);
//			scanf("%d", &search.qtyInStock);
//			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				if (search.qtyInStock == records.qtyInStock) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;
//				}
//			}
//			switch (n) {
//			case 0:
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 6:
//			printf("Enter Minimum Level > ");
//			rewind(stdin);
//			scanf("%d", &search.minLvl);
//			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				if (search.minLvl == records.minLvl) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;
//				}
//			}
//			switch (n) {
//			case 0:
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 7:
//			printf("Enter Reorder Quantity > ");
//			rewind(stdin);
//			scanf("%d", &search.reorderQty);
//			printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//			printf("================================================================================================================\n");
//			while (!feof(stock)) {
//				fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//				if (search.reorderQty == records.reorderQty) {
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					n++;
//				}
//			}
//			switch (n) {
//			case 0:
//				printf("\nNo record found !\n");
//				break;
//			default:
//				printf("\n%d record(s) found\n", n);
//			}
//			break;
//		case 8:
//			break;
//		}
//		n = 0;//update the number of record back to original value
//
//		fclose(stock);
//
//		printf("\nSearch for another record? (Y=Yes|N=No) > ");
//		ans = valid2();
//	} while (toupper(ans) == 'Y');//when user want to search for another record
//}
//
//void modifyStock() {
//	int i = 0, ans, count = 0, c = 0, cat;
//	char modifyItemCode[10], ans1, ans2, timeStr[25];
//
//	FILE* stock;
//	stock = fopen("stock.txt", "r");//read from the file
//
//	FILE* modified;
//	modified = fopen("stockModifiedHistory.txt", "a");//to append the modified records into the file
//
//	if (stock == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	if (modified == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	//store the current records into an array
//	while (!feof(stock)) {
//		fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", store[i].itemCode, store[i].itemName, store[i].itemCategory, &store[i].itemPrice, &store[i].qtyInStock, &store[i].minLvl, &store[i].reorderQty);
//		i++;
//	}
//
//	fclose(stock);
//
//	printf("\nMODIFY STOCK RECORDS\n");
//	printf("====================\n");
//	do {
//		do {
//			printf("Enter Item Code ( X = Exit ) > ");
//			rewind(stdin);
//			scanf("%s", modifyItemCode);
//			if (strcmp(modifyItemCode, "X") == 0)
//				main();
//
//			FILE* checking;
//			checking = fopen("stock.txt", "r");//to read from the file
//
//			if (checking == NULL) {
//				printf("Error while opening the file");
//				exit(-1);
//			}
//
//			//to check the item code of the record that user want to
//			while (fscanf(checking, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", 
//				records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty) != EOF) {
//				if (strcmp(modifyItemCode, records.itemCode) == 0) {//if the item code of the record that the user wanted to modify is same as the item code of the record
//					c++;//increase the number of record found
//				}
//			}
//			if (c == 0) {//if no record found
//				printf("Stock %s does not exist !\nTry Again\n", modifyItemCode);
//			}
//			fclose(checking);
//		} while (c == 0);//loop until the item code of user wanted to modify is exist in the file
//
//		for (int n = 0; n < i; n++) {
//			if (strcmp(modifyItemCode, store[n].itemCode) == 0) {//if the item code of the record that the user wanted to modify is same as the record
//				printf("\nItem Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//				printf("================================================================================================================\n");
//				printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].qtyInStock, store[n].minLvl, store[n].reorderQty);
//				printf("\n-------------------------------\n");
//				printf("Item Name         -> 1\n");
//				printf("Item Category     -> 2\n");
//				printf("Item Price        -> 3\n");
//				printf("Quantity In Stock -> 4\n");
//				printf("Minimum Level     -> 5\n");
//				printf("Reorder Stock     -> 6\n");
//				printf("-------------------------------\n");
//				printf("Select a field to be modified > ");
//				ans = valid4();
//				switch (ans) {
//				case 1:
//					do {
//						printf("\nEnter New Item Name >");
//						rewind(stdin);
//						scanf("%[^\n]", &records.itemName);
//						if (strcmp(records.itemName, store[n].itemName) == 0)
//							printf("\nDo not use back the same name. Try again.\n");
//					} while (strcmp(records.itemName, store[n].itemName) == 0);
//
//					printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
//					ans2 = valid2();
//					if (toupper(ans2) == 'Y') {
//						SYSTEMTIME t;
//
//						GetLocalTime(&t);//get current time
//
//						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);//store the current time into a string
//						printf("================================================================================================================");
//						printf("\nName of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("\nStock %s before modify:", modifyItemCode);
//						printf("\nItem Code\tName\n");
//						printf("================================\n");
//						printf("%-16s%-16s\n", store[n].itemCode, store[n].itemName);
//						printf("\nStock %s after modify:", modifyItemCode);
//						printf("\nItem Code\tName\n");
//						printf("================================\n");
//						printf("%-16s%-16s\n", store[n].itemCode, records.itemName);
//						printf("\n================================================================================================================");
//						//write the modified record into modify file
//						fprintf(modified, "Name of Stock %s has changed from %s to %s on %s\n", store[n].itemCode, store[n].itemName, records.itemName, timeStr);
//						//store the modified record into record
//						strcpy(store[n].itemName, records.itemName);
//						count++;//increase the total number of modified record
//
//					}
//					else {
//						printf("\nModify Stock Record Failed\n\n");
//					}
//					break;
//				case 2:
//					do {
//						printf("Category\n");
//						printf("---------------------\n");
//						printf("1. food\n");
//						printf("2. drink\n");
//						printf("3. shirt\n");
//						printf("4. pants\n");
//						printf("5. shoes\n");
//						printf("---------------------\n");
//						printf("Enter Item Category > ");
//						rewind(stdin);
//						cat = valid5();
//						switch (cat) {
//						case 1:
//							strcpy(records.itemCategory, "food");
//							break;
//						case 2:
//							strcpy(records.itemCategory, "drink");
//							break;
//						case 3:
//							strcpy(records.itemCategory, "shirt");
//							break;
//						case 4:
//							strcpy(records.itemCategory, "pants");
//							break;
//						case 5:
//							strcpy(records.itemCategory, "shoes");
//							break;
//						}
//						if (strcmp(store[n].itemCategory, records.itemCategory) == 0)
//							printf("\nDo not use back the same category. Try again.\n\n");
//					} while (strcmp(store[n].itemCategory, records.itemCategory) == 0);
//
//
//					printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
//					ans2 = valid2();
//					if (toupper(ans2) == 'Y') {
//						SYSTEMTIME t;
//
//						GetLocalTime(&t);
//
//						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("================================================================================================================");
//						printf("\nCategory of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("\nStock %s before modify:", modifyItemCode);
//						printf("\nItem Code\tCategory\n");
//						printf("================================\n");
//						printf("%-16s%-16s\n", store[n].itemCode, store[n].itemCategory);
//						printf("\nStock %s after modify:", modifyItemCode);
//						printf("\nItem Code\tCategory\n");
//						printf("================================\n");
//						printf("%-16s%-16s\n", store[n].itemCode, records.itemCategory);
//						printf("\n================================================================================================================");
//						fprintf(modified, "Category of Stock %s has changed from %s to %s on %s\n", store[n].itemCode, store[n].itemCategory, records.itemCategory, timeStr);
//						strcpy(store[n].itemCategory, records.itemCategory);
//						count++;
//
//					}
//					else {
//						printf("\nModify Stock Record Failed\n\n");
//					}
//					break;
//				case 3:
//					do {
//						printf("\nEnter New Item Price >");
//						rewind(stdin);
//						scanf("%lf", &records.itemPrice);
//						if (store[n].itemPrice == records.itemPrice)
//							printf("\nDo not use back the same price. Try again.\n");
//					} while (store[n].itemPrice == records.itemPrice);
//
//					printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
//					ans2 = valid2();
//					if (toupper(ans2) == 'Y') {
//						SYSTEMTIME t;
//
//						GetLocalTime(&t);
//
//						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("================================================================================================================");
//						printf("\nPrice of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("\nStock %s before modify:", modifyItemCode);
//						printf("\nItem Code\tPrice\n");
//						printf("================================\n");
//						printf("%-16s%RM%10.2lf\n", store[n].itemCode, store[n].itemPrice);
//						printf("\nStock %s after modify:", modifyItemCode);
//						printf("\nItem Code\tPrice\n");
//						printf("================================\n");
//						printf("%-16s%RM%10.2lf\n", store[n].itemCode, records.itemPrice);
//						printf("\n================================================================================================================");
//						fprintf(modified, "Price of Stock %s has changed from RM%.2lf to RM%.2lf on %s\n", store[n].itemCode, store[n].itemPrice, records.itemPrice, timeStr);
//						store[n].itemPrice = records.itemPrice;
//						count++;
//
//					}
//					else {
//						printf("\nModify Stock Record Failed\n\n");
//					}
//					break;
//				case 4:
//					do {
//						printf("\nEnter New Quantity In Stock >");
//						rewind(stdin);
//						scanf("%d", &records.qtyInStock);
//						if (store[n].qtyInStock == records.qtyInStock)
//							printf("\nDo not use back the same quantity. Try again.\n");
//					} while (store[n].qtyInStock == records.qtyInStock);
//					printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
//					ans2 = valid2();
//					if (toupper(ans2) == 'Y') {
//						SYSTEMTIME t;
//
//						GetLocalTime(&t);
//
//						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("================================================================================================================");
//						printf("\nQuantity of Stock %s modified successfully!\t\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("\nStock %s before modify:", modifyItemCode);
//						printf("\nItem Code\tQuantity\n");
//						printf("================================\n");
//						printf("%-16s%-16d\n", store[n].itemCode, store[n].qtyInStock);
//						printf("\nStock %s after modify:", modifyItemCode);
//						printf("\nItem Code\tQuantity\n");
//						printf("================================\n");
//						printf("%-16s%-16d\n", store[n].itemCode, records.qtyInStock);
//						printf("\n================================================================================================================");
//						fprintf(modified, "Quantity of Stock %s has changed from %d to %d on %s\n", store[n].itemCode, store[n].qtyInStock, records.qtyInStock, timeStr);
//						store[n].qtyInStock = records.qtyInStock;
//						count++;
//
//					}
//					else {
//						printf("\nModify Stock Record Failed\n\n");
//					}
//					break;
//				case 5:
//					do {
//						printf("\nEnter New Minimum Level >");
//						rewind(stdin);
//						scanf("%d", &records.minLvl);
//						if (records.minLvl == store[n].minLvl)
//							printf("\nDo not use back the same minimum level. Try again.\n");
//					} while (records.minLvl == store[n].minLvl);
//
//					printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
//					ans2 = valid2();
//					if (toupper(ans2) == 'Y') {
//						SYSTEMTIME t;
//
//						GetLocalTime(&t);
//
//						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("================================================================================================================");
//						printf("\nMinimum Level of Stock %s modified successfully!\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("\nStock %s before modify:", modifyItemCode);
//						printf("\nItem Code\tMinimum Level\n");
//						printf("================================\n");
//						printf("%-16s%-16d\n", store[n].itemCode, store[n].minLvl);
//						printf("\nStock %s after modify:", modifyItemCode);
//						printf("\nItem Code\tMinimum Level\n");
//						printf("================================\n");
//						printf("%-16s%-16d\n", store[n].itemCode, records.minLvl);
//						printf("\n================================================================================================================");
//						fprintf(modified, "Minimum Level of Stock %s has changed from %d to %d on %s\n", store[n].itemCode, store[n].minLvl, records.minLvl, timeStr);
//						store[n].minLvl = records.minLvl;
//						count++;
//
//					}
//					else {
//						printf("\nModify Stock Record Failed\n\n");
//					}
//					break;
//				case 6:
//					do {
//						printf("\nEnter New Reorder Quantity >");
//						rewind(stdin);
//						scanf("%d", &records.reorderQty);
//						if (records.reorderQty == store[n].reorderQty)
//							printf("\nDo not use back the same quantity. Try again.\n");
//					} while (records.reorderQty == store[n].reorderQty);
//
//					printf("\nAre you sure you want to modify this stock? (Y=Yes|N=No) >");
//					ans2 = valid2();
//					if (toupper(ans2) == 'Y') {
//						SYSTEMTIME t;
//
//						GetLocalTime(&t);
//
//						sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("================================================================================================================");
//						printf("\nReorder Quantity of Stock %s modified successfully!\t\t\t\tDate:%04d-%02d-%02d\tTime:%02d:%02d:%02d\n", modifyItemCode, t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
//						printf("\nStock %s before modify:", modifyItemCode);
//						printf("\nItem Code\tReorder Quantity\n");
//						printf("================================\n");
//						printf("%-16s%-16d\n", store[n].itemCode, store[n].reorderQty);
//						printf("\nStock %s after modify:", modifyItemCode);
//						printf("\nItem Code\tReorder Quantity\n");
//						printf("================================\n");
//						printf("%-16s%-16d\n", store[n].itemCode, records.reorderQty);
//						printf("\n================================================================================================================");
//						fprintf(modified, "Reorder Quantity of Stock %s has changed from %d to %d on %s\n", store[n].itemCode, store[n].reorderQty, records.reorderQty, timeStr);
//						store[n].reorderQty = records.reorderQty;
//						count++;
//
//					}
//					else {
//						printf("\nModify Stock Record Failed\n\n");
//					}
//					break;
//				}
//			}
//		}
//		printf("\nDo you want to modify another record? (Y=Yes|N=No) >");
//		ans1 = valid2();
//		c = 0;
//	} while (toupper(ans1) == 'Y');
//
//	FILE* fptr;
//	fptr = fopen("stock.txt", "w");
//
//	if (fptr == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	//write all the records with modified record 
//	for (int n = 0; n < i; n++) {
//		fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n", store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].qtyInStock, store[n].minLvl, store[n].reorderQty);
//	}
//
//	fclose(fptr);
//	fclose(modified);
//
//	printf("\n\n%d record(s) have been modified!\n\n", count);
//}
//
//void displayStock() {
//	FILE* stock;
//	stock = fopen("stock.txt", "r");
//
//	if (stock == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//	printf("================================================================================================================\n");
//	while (!feof(stock)) {
//		fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty);
//		printf("%-16s%-16s%-16sRM%10.2lf    %-16d%-16d%-16d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//	}
//	printf("\n");
//
//	fclose(stock);
//
//}
//
//void reportStock() {
//	int count = 0, ans, a = 0, b = 0, c = 0, d = 0, e = 0;
//
//	SYSTEMTIME t;
//
//	GetLocalTime(&t);//get current time
//
//	struct Stock food[50], drink[50], shirt[50], pants[50], shoes[50];
//
//	FILE* stock;
//	stock = fopen("stock.txt", "r");
//
//	if (stock == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	printf("GENERATE STOCK REPORT\n");
//	printf("=====================\n");
//	printf("Select a type of report:\n");
//	printf("========================\n");
//	printf("Stock Records Summary Report     -> 1\n");
//	printf("Stock Records Categorized Report -> 2\n");
//	printf(">");
//	ans = valid3();
//	switch (ans) {
//	case 1:
//		printf("\n\t\t\t\t\tSTOCK RECORDS SUMMARY REPORT\n");
//		printf("================================================================================================================\n");
//		printf("DATE: %d-%d-%d\t\t\t\t\t\t\t\t\t\t\t     TIME: %d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
//		printf("================================================================================================================\n");
//		printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//		printf("================================================================================================================\n");
//		while (fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", 
//			records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty) != EOF) {
//			printf("%-16s%-16s%-16sRM%-14.2lf%-16d%-16d%-16d\n", records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//			count++;
//		}
//		printf("=================================================================================================================\n");
//		printf("TOTAL %d RECORD(S) OF STOCK\n", count);
//		printf("=================================================================================================================\n\n");
//		break;
//	case 2:
//		printf("\n\t\t\t\t\tSTOCK RECORDS CATEGORIZED REPORT\n");
//		printf("================================================================================================================\n");
//		printf("DATE: %d-%d-%d\t\t\t\t\t\t\t\t\t\t\t     TIME: %d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
//		printf("================================================================================================================\n");
//		printf("Item Code\tName\t\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//		printf("================================================================================================================\n");
//		while (fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", 
//			records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty) != EOF) {
//			//differentiate the records by their category
//			if (strcmp(records.itemCategory, "food") == 0) {
//				strcpy(food[a].itemCode, records.itemCode);
//				strcpy(food[a].itemName, records.itemName);
//				strcpy(food[a].itemCategory, records.itemCategory);
//				food[a].itemPrice = records.itemPrice;
//				food[a].qtyInStock = records.qtyInStock;
//				food[a].reorderQty = records.reorderQty;
//				food[a].minLvl = records.minLvl;
//				a++;
//			}
//			else if (strcmp(records.itemCategory, "drink") == 0) {
//				strcpy(drink[b].itemCode, records.itemCode);
//				strcpy(drink[b].itemName, records.itemName);
//				strcpy(drink[b].itemCategory, records.itemCategory);
//				drink[b].itemPrice = records.itemPrice;
//				drink[b].qtyInStock = records.qtyInStock;
//				drink[b].reorderQty = records.reorderQty;
//				drink[b].minLvl = records.minLvl;
//				b++;
//			}
//			else if (strcmp(records.itemCategory, "shirt") == 0) {
//				strcpy(shirt[c].itemCode, records.itemCode);
//				strcpy(shirt[c].itemName, records.itemName);
//				strcpy(shirt[c].itemCategory, records.itemCategory);
//				shirt[c].itemPrice = records.itemPrice;
//				shirt[c].qtyInStock = records.qtyInStock;
//				shirt[c].reorderQty = records.reorderQty;
//				shirt[c].minLvl = records.minLvl;
//				c++;
//			}
//			else if (strcmp(records.itemCategory, "pants") == 0) {
//				strcpy(pants[d].itemCode, records.itemCode);
//				strcpy(pants[d].itemName, records.itemName);
//				strcpy(pants[d].itemCategory, records.itemCategory);
//				pants[d].itemPrice = records.itemPrice;
//				pants[d].qtyInStock = records.qtyInStock;
//				pants[d].reorderQty = records.reorderQty;
//				pants[d].minLvl = records.minLvl;
//				d++;
//			}
//			else if (strcmp(records.itemCategory, "shoes") == 0) {
//				strcpy(shoes[e].itemCode, records.itemCode);
//				strcpy(shoes[e].itemName, records.itemName);
//				strcpy(shoes[e].itemCategory, records.itemCategory);
//				shoes[e].itemPrice = records.itemPrice;
//				shoes[e].qtyInStock = records.qtyInStock;
//				shoes[e].reorderQty = records.reorderQty;
//				shoes[e].minLvl = records.minLvl;
//				e++;
//			}
//		}
//		printf("\nCategory : Food\n");
//		printf("================================================================================================================\n");
//		for (int k = 0; k < a; k++) {
//			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", food[k].itemCode, food[k].itemName, food[k].itemPrice, food[k].qtyInStock, food[k].minLvl, food[k].reorderQty);
//		}
//		printf("\nTotal amount of Food Category : %d\n", a);
//		printf("================================================================================================================\n");
//		printf("\nCategory : Drink\n");
//		printf("================================================================================================================\n");
//		for (int k = 0; k < b; k++) {
//			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", drink[k].itemCode, drink[k].itemName, drink[k].itemPrice, drink[k].qtyInStock, drink[k].minLvl, drink[k].reorderQty);
//		}
//		printf("\nTotal amount of Drink Category : %d\n", b);
//		printf("================================================================================================================\n");
//		printf("\nCategory : Shirt\n");
//		printf("================================================================================================================\n");
//		for (int k = 0; k < c; k++) {
//			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", shirt[k].itemCode, shirt[k].itemName, shirt[k].itemPrice, shirt[k].qtyInStock, shirt[k].minLvl, shirt[k].reorderQty);
//		}
//		printf("\nTotal amount of Shirt Category : %d\n", c);
//		printf("================================================================================================================\n");
//		printf("\nCategory : Pants\n");
//		printf("================================================================================================================\n");
//		for (int k = 0; k < d; k++) {
//			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", pants[k].itemCode, pants[k].itemName, pants[k].itemPrice, pants[k].qtyInStock, pants[k].minLvl, pants[k].reorderQty);
//		}
//		printf("\nTotal amount of Pants Category : %d\n", d);
//		printf("================================================================================================================\n");
//		printf("\nCategory : Shoes\n");
//		printf("================================================================================================================\n");
//		for (int k = 0; k < e; k++) {
//			printf("%-16s%-16s%RM%-14.2lf%-16d%-16d%-16d\n", shoes[k].itemCode, shoes[k].itemName, shoes[k].itemPrice, shoes[k].qtyInStock, shoes[k].minLvl, shoes[k].reorderQty);
//		}
//		printf("\nTotal amount of Shoes Category : %d\n", e);
//		printf("================================================================================================================\n\n");
//		//generate bar chart
//		printf("\t\t\t\t\tBar Chart of Number of Stock Record\n\n");
//		printf("\t\335\n");
//		for (int i = 0; i < 3; i++) {
//			if (i == 1) {
//				printf("Food");
//			}
//			printf("\t");
//			for (int k = 0; k <= a; k++) {
//				printf("\335");
//				if (i == 1 && k == a) {
//					printf(" [%d]", a);
//				}
//			}
//			printf("\n");
//		}
//		printf("\t\335\n");
//		for (int i = 0; i < 3; i++) {
//			if (i == 1) {
//				printf("Drink");
//			}
//			printf("\t");
//			for (int k = 0; k <= b; k++) {
//				printf("\335");
//				if (i == 1 && k == b) {
//					printf(" [%d]", b);
//				}
//			}
//			printf("\n");
//		}
//		printf("\t\335\n");
//		for (int i = 0; i < 3; i++) {
//			if (i == 1) {
//				printf("Shirt");
//			}
//			printf("\t");
//			for (int k = 0; k <= c; k++) {
//				printf("\335");
//				if (i == 1 && k == c) {
//					printf(" [%d]", c);
//				}
//			}
//			printf("\n");
//		}
//		printf("\t\335\n");
//		for (int i = 0; i < 3; i++) {
//			if (i == 1) {
//				printf("Pants");
//			}
//			printf("\t");
//			for (int k = 0; k <= d; k++) {
//				printf("\335");
//				if (i == 1 && k == d) {
//					printf(" [%d]", d);
//				}
//			}
//			printf("\n");
//		}
//		printf("\t\335\n");
//		for (int i = 0; i < 3; i++) {
//			if (i == 1) {
//				printf("Shoes");
//			}
//			printf("\t");
//			for (int k = 0; k <= e; k++) {
//				printf("\335");
//				if (i == 1 && k == e) {
//					printf(" [%d]", e);
//				}
//			}
//			printf("\n");
//		}
//		printf("\t\335\n\t\335");
//		int k = 10;
//		while (k <= 50) {
//			printf("---------\335");
//			k += 10;
//		}
//		printf("-->Number of record\n\t0");
//		int l = 10;
//		while (l <= 50) {
//			printf("        %d", l);
//			l += 10;
//		}
//		printf("\n");
//		break;
//	}
//	fclose(stock);
//}
//
//void deleteStock() {
//	int i = 0, count = 0, c = 0;
//	char deleteItemCode[10], ans2, timeStr[25];
//
//	FILE* deleted;
//	deleted = fopen("stockDeletedHistory.txt", "a");//open deleted record file
//
//	if (deleted == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	printf("DELETE STOCK RECORD\n");
//	printf("===================\n");
//	do {
//		FILE* stock;
//		stock = fopen("stock.txt", "r");
//
//		if (stock == NULL) {
//			printf("Error while opening the file");
//			exit(-1);
//		}
//
//		do {
//			printf("Enter Item Code ( X = Exit ) > ");
//			rewind(stdin);
//			scanf("%s", deleteItemCode);
//			if (strcmp(deleteItemCode, "X") == 0)
//				main();
//			FILE* checking;
//			checking = fopen("stock.txt", "r");//open and read to check the record that user wanted to delete is exist 
//			while (fscanf(checking, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", 
//				records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty) != EOF) {
//				if (strcmp(deleteItemCode, records.itemCode) == 0) {
//					c++;//increase number of record
//					printf("\nItem Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\n");
//					printf("================================================================================================================\n");
//					printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%d\n", 
//						records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//				}
//			}
//			if (c == 0) {//if no record found
//				printf("Stock %s does not exist !\nTry Again\n", deleteItemCode);
//			}
//			fclose(checking);
//		} while (c == 0);
//
//		printf("\nAre you sure you want to delete this record? (Y=Yes|N=No) >");
//		ans2 = valid2();
//		if (toupper(ans2) == 'Y') {
//			while (fscanf(stock, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d\n", 
//				records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty) != EOF) {
//				if (strcmp(deleteItemCode, records.itemCode) != 0) {
//					strcpy(store[i].itemCode, records.itemCode);
//					strcpy(store[i].itemName, records.itemName);
//					strcpy(store[i].itemCategory, records.itemCategory);
//					store[i].itemPrice = records.itemPrice;
//					store[i].qtyInStock = records.qtyInStock;
//					store[i].reorderQty = records.reorderQty;
//					store[i].minLvl = records.minLvl;
//					i++;
//				}
//				else {
//					SYSTEMTIME t;
//
//					GetLocalTime(&t);//get current time
//
//					sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);//store current time into a string
//					fprintf(deleted, "%s|%s|%s|%.2lf|%d|%d|%d|%s\n", 
//						records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty, timeStr);
//				}
//			}
//
//			fclose(stock);
//
//			FILE* fptr;
//			fptr = fopen("stock.txt", "w");//open the stock file to rewrite all record
//
//			if (fptr == NULL) {
//				printf("Error while opening the file");
//				exit(-1);
//			}
//
//			for (int n = 0; n < i; n++) {
//				fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n", 
//					store[n].itemCode, store[n].itemName, store[n].itemCategory, store[n].itemPrice, store[n].qtyInStock, store[n].minLvl, store[n].reorderQty);
//			}
//			printf("\nStock %s is deleted!\n\n", deleteItemCode);
//			count++;
//			fclose(fptr);
//		}
//		else {
//			printf("\nStock %s fail to delete !\n\n", deleteItemCode);
//		}
//		printf("Do you want to delete another record? (Y=Yes|N=No) >");
//		ans2 = valid2();
//		//update the value of i and c to their original value
//		i = 0;
//		c = 0;
//	} while (toupper(ans2) == 'Y');
//
//	fclose(deleted);
//
//	printf("\n%d record(s) have been deleted.\n\n", count);
//}
//
//void modifyHistory() {
//	int i = 0, c = 0, count = 0;
//	char ans2, restoreItemCode[5], message[150];
//
//	FILE* modified;
//	modified = fopen("stockModifiedHistory.txt", "r");//open and read the modified record file
//
//	if (modified == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	printf("MODIFIED HISTORY\n");
//	printf("================\n\n");
//	while (fscanf(modified, "%[^\n]\n", message) != EOF) {
//		printf("%s\n\n", message);
//		i++;//increase the number of modified record
//	}
//
//	if (i == 0) {//if no record been modified
//		printf("\nNo record modified!\n\n");
//	}
//	else {
//		printf("\n%d record(s) modified\n\n", i);
//	}
//
//	fclose(modified);
//}
//
//void deleteHistory() {
//	struct Stock {
//		char itemCode[5], itemName[30], itemCategory[20], timeStr[25];
//		int qtyInStock, minLvl, reorderQty;
//		double itemPrice;
//	}records;
//
//	struct Stock store[100];
//
//	int i = 0, n = 0, count = 0, c = 0;
//	char ans2, restoreItemCode[5];
//
//	FILE* deleted;
//	deleted = fopen("stockDeletedHistory.txt", "r");//open and read the deleted record file
//
//	if (deleted == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//	printf("\nDELETED HISTORY\n");
//	printf("===============\n\n");
//	printf("Item Code\tName\t\tCategory\tPrice\t\tQuantity\tMinimum Level\tReorder Quantity\tDate and Time\n");
//	printf("==========================================================================================================================================\n");
//	while (fscanf(deleted, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d|%[^\n]\n", 
//		records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty, records.timeStr) != EOF) {
//		printf("%-16s%-16s%-10s\tRM%10.2lf    %-16d%-16d%-23d%-16s\n", 
//			records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty, records.timeStr);
//		i++;//increase the number of deleted record
//	}
//
//	if (i == 0) {//if no record been deleted
//		printf("\nNo record deleted!\n\n");
//	}
//	else {
//		printf("\n%d record(s) deleted\n\n", i);
//	}
//
//	//update the number of deleted record
//	i = 0;
//
//	fclose(deleted);
//
//	FILE* restore;
//	restore = fopen("stockDeletedHistory.txt", "r");//open and read again the deleted record file
//
//	if (restore == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	FILE* fptr;
//	fptr = fopen("stock.txt", "a");//open to add back the deleted record into the stock file
//
//	if (fptr == NULL) {
//		printf("Error while opening the file");
//		exit(-1);
//	}
//
//	printf("Do you want to restore any history? (Y=Yes|N=No) >");
//	ans2 = valid2();
//	while (toupper(ans2) == 'Y') {
//		do {
//			printf("\nEnter the item code ( X = Exit ) : ");
//			rewind(stdin);
//			scanf("%[^\n]", restoreItemCode);
//			if (strcmp(restoreItemCode, "X") == 0)
//				main();
//			FILE* checking;
//			checking = fopen("stockDeletedHistory.txt", "r");//open and read the deleted record file
//			while (fscanf(checking, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d|%[^\n]\n", 
//				records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty, records.timeStr) != EOF) {
//				if (strcmp(restoreItemCode, records.itemCode) == 0) {
//					c++;//increase the number of record found
//				}
//			}
//			if (c == 0) {//if no record found
//				printf("Stock %s does not exist !\nTry Again\n", restoreItemCode);
//			}
//			fclose(checking);
//		} while (c == 0);
//		printf("\nAre you sure you want to restore Stock %s ? (Y=Yes|N=No) >", restoreItemCode);
//		ans2 = valid2();
//		if (toupper(ans2) == 'Y') {
//			while (fscanf(restore, "%[^\|]|%[^\|]|%[^\|]|%lf|%d|%d|%d|%[^\n]\n", 
//				records.itemCode, records.itemName, records.itemCategory, &records.itemPrice, &records.qtyInStock, &records.minLvl, &records.reorderQty, records.timeStr) != EOF) {
//				if (strcmp(restoreItemCode, records.itemCode) != 0) {
//					strcpy(store[i].itemCode, records.itemCode);
//					strcpy(store[i].itemName, records.itemName);
//					strcpy(store[i].itemCategory, records.itemCategory);
//					store[i].itemPrice = records.itemPrice;
//					store[i].qtyInStock = records.qtyInStock;
//					store[i].reorderQty = records.reorderQty;
//					store[i].minLvl = records.minLvl;
//					strcpy(store[i].timeStr, records.timeStr);
//					i++;
//				}
//				else {
//					fprintf(fptr, "%s|%s|%s|%.2lf|%d|%d|%d\n", 
//						records.itemCode, records.itemName, records.itemCategory, records.itemPrice, records.qtyInStock, records.minLvl, records.reorderQty);
//					count++;
//				}
//			}
//			FILE* fptr2;
//			fptr2 = fopen("stockDeletedHistory.txt", "w");//open and rewrite all the records with the restored record
//
//			if (fptr2 == NULL) {
//				printf("Error while opening the file");
//				exit(-1);
//			}
//
//			for (int c = 0; c < i; c++) {
//				fprintf(fptr2, "%s|%s|%s|%.2lf|%d|%d|%d|%s\n", 
//					store[c].itemCode, store[c].itemName, store[c].itemCategory, store[c].itemPrice, store[c].qtyInStock, store[c].minLvl, store[c].reorderQty, store[c].timeStr);
//			}
//
//			fclose(fptr2);
//			ans2 = 'N';
//		}
//		printf("\nStock %s restore successfully!\n\n", restoreItemCode);
//	}
//
//	fclose(restore);
//	fclose(fptr);
//}
//
//int valid() {
//	int ans;
//
//	//loop until the user input correctly
//	do {
//		rewind(stdin);
//		scanf("%d", &ans);
//		switch (ans) {
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//		case 6:
//		case 7:
//		case 8:
//			v = 'V';
//			break;
//		default:
//			printf("Invalid input. Try again.\n");
//			printf(">");
//			v = 'I';
//		}
//	} while (v == 'I');
//
//	return ans;
//}
//
//int valid1() {
//	int ans;
//
//	//loop until the user input correctly
//	do {
//		rewind(stdin);
//		scanf("%d", &ans);
//		switch (ans) {
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//		case 6:
//		case 7:
//		case 8:
//		case 9:
//			v = 'V';
//			break;
//		default:
//			printf("Invalid input. Try again.\n");
//			printf(">");
//			v = 'I';
//		}
//	} while (v == 'I');
//
//	return ans;
//}
//
//char valid2() {
//	char ans2;
//
//	//loop until the user input correctly
//	do {
//		rewind(stdin);
//		scanf("%c", &ans2);
//		switch (ans2) {
//		case 'Y':
//		case 'y':
//		case 'N':
//		case 'n':
//			v = 'V';
//			break;
//		default:
//			printf("Invalid input. Try again.\n");
//			printf(">");
//			v = 'I';
//		}
//	} while (v == 'I');
//	return ans2;
//}
//
//int valid3() {
//	int ans;
//
//	//loop until the user input correctly
//	do {
//		rewind(stdin);
//		scanf("%d", &ans);
//		switch (ans) {
//		case 1:
//		case 2:
//			v = 'V';
//			break;
//		default:
//			printf("Invalid input. Try again.\n");
//			printf(">");
//			v = 'I';
//		}
//	} while (v == 'I');
//
//	return ans;
//}
//
//int valid4() {
//	int ans;
//
//	//loop until the user input correctly
//	do {
//		rewind(stdin);
//		scanf("%d", &ans);
//		switch (ans) {
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//		case 6:
//			v = 'V';
//			break;
//		default:
//			printf("Invalid input. Try again.\n");
//			printf(">");
//			v = 'I';
//		}
//	} while (v == 'I');
//
//	return ans;
//}
//
//int valid5() {
//	int ans;
//
//	//loop until the user input correctly
//	do {
//		rewind(stdin);
//		scanf("%d", &ans);
//		switch (ans) {
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			v = 'V';
//			break;
//		default:
//			printf("Invalid input. Try again.\n");
//			printf(">");
//			v = 'I';
//		}
//	} while (v == 'I');
//
//	return ans;
//}