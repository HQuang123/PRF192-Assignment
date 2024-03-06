#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXN 100

//Menu
int menu(){
	int choice;
	printf("\nParallel Array of Drinks:");
	printf("\n1 - Add a new Drink");
	printf("\n2 - Edit information: price of a drink by its code");
	printf("\n3 - Edit information: name of a drink by its code");
	printf("\n4 - Delete a drink by its code");
	printf("\n5 - Arrange the drink list by drink type (descending)");
	printf("\n6 - Arrange the drink list by price (ascending)");
	printf("\n7 - Print the drink list");
	printf("\n8 - Print the drink by its code");
	printf("\n9 - Print the drink list by price condition");
	printf("\n10 - Print the average, highest and lowest drink price ");
	printf("\nOther - Quit");
	printf("\nPlease choose: ");
	scanf("%d%*c", &choice); //remove enter key
	return choice;
}

/* Check if array is full */
int isFull(char drink_name[][50], int n){
	return n==MAXN;	
};

/* Check if array is empty or not*/
int isEmpty(char drink_name[][50], int n){
	return n==0;
}; 

//ADD
void add(char drink_code[50], char drink_name[50], char drink_type, int unit, double price,char drink_codes[][50],char drink_names[][50],char drink_types[], int units[], double prices[], int *pn)
{
	strcpy(drink_codes[*pn], drink_code); //add instance to the end of the array
	strcpy(drink_names[*pn], drink_name);
	drink_types[*pn] = drink_type;
	units[*pn] = unit;
	prices[*pn] = price;
	*pn = *pn + 1; //increase the number of elements use 
}

//EDIT PRICE
void edit_price(char drink_code[50], double price,char drink_codes[][50],char drink_names[][50],char drink_types[][50], int units[], double prices[],int *pn){
	int i;
	int result = MAXN + 1;
	for(i=0;i<= *pn; i++){
		if(drink_codes[i] == drink_code){
			result = i;
		}
		};
	if(result != MAXN + 1) {
		prices[result] = price;
	}
	else
	{printf("The code is not existed");
	}
	}

//EDIT name
void edit_name(char drink_code[50], double price,char drink_codes[][50],char drink_names[][50],char drink_types[][50], int units[], char drink_name[50], int *pn){
	int i;
	int result = MAXN + 1;
	for(i=0;i<= *pn; i++){
		if(drink_codes[i] == drink_code){
			result = i;
		}
		};
	if(result != MAXN + 1) {
		strcpy(drink_names[result], drink_name);
	}
	else
	{printf("The code is not existed");
	}
	}
	
	
int delete_drink(char drink_code[50], double prices[], char drink_codes[][50],char drink_names[][50],char drink_types[], int units[], char drink_name[50], int *pn){
	int i;
	int pos = MAXN + 1;
	int result;
	for(i=0;i<= *pn; i++){
		if(drink_codes[i] == drink_code){
			pos = i;
		}
		};
	if(pos != MAXN + 1) {
		for(i = pos; i< *pn -1;i++) {
			strcpy(drink_codes[i], drink_codes[i+1]);
			strcpy(drink_names[i], drink_names[i+1]);
			drink_types[i] = drink_types[i+1];
			units[i] = units[i+1];
			prices[i] = prices[i+1];
		}
		*pn = *pn - 1;
		result = 1;//successfully
	}
	else
	{printf("The code is not existed");
	 result = 0;//unsuccesfully
	};
	return result;
	}

//nghien cuu swap 2 generic positions
//sort the drink list based on drink type
//sap xep giam dan theo loai do uong
void printDesc(int n, char drink_codes[][50], char drink_names[][50], char drink_types[], int units[], double prices[]){
	int *addrs = (int *)calloc(n, sizeof(int));
	int i, j;
	for(i = 0; i < n; i++){
		addrs[i] = i;
	}
	int t;
	for(i = 0; i < n-1; i++){
		for(j = n-1; j > i; j--){
			char type1 = drink_types[addrs[j]];
			char type2 = drink_types[addrs[j-1]];
			if(type1 > type2){
				t = addrs[j];
				addrs[j] = addrs[j-1];
				addrs[j-1] = t;
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("Drink(code: %s, name: %s, type: %c, unit: %d, price: %.3lf)\n", drink_codes[addrs[i]], drink_names[addrs[i]], drink_types[addrs[i]], units[addrs[i]], prices[addrs[i]]);
	}
	free(addrs);
}
	
	
//sap xep tang dan theo gia tien
void printAsc(int n, char drink_codes[][50], char drink_names[][50], char drink_types[], int units[], double prices[]){
	int *addrs = (int *)calloc(n, sizeof(int));
	int i, j;
	for(i = 0; i < n; i++){
		addrs[i] = i;
	}
	int t;
	for(i = 0; i < n-1; i++){
		for(j = n-1; j > i; j--){
			double price1 = prices[addrs[j]];
			double price2 = prices[addrs[j-1]];
			if(price1 < price2){
				t = addrs[j];
				addrs[j] = addrs[j-1];
				addrs[j-1] = t;
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("Drink(code: %s, name: %s, type: %c, unit: %d, price: %.3lf)\n", drink_codes[addrs[i]], drink_names[addrs[i]], drink_types[addrs[i]], units[addrs[i]], prices[addrs[i]]);
	}
	free(addrs);
}

//In tat ca ra man hinh
void printAll(int n, char drink_codes[][50], char drink_names[][50], char drink_types[], int units[], double prices[]){
	int i;
	for(i = 0; i < n; i++){
	printf("Drink(code: %s, name: %s, type: %c, unit: %d, price: %.3lf)\n", drink_codes[i], drink_names[i], drink_types[i], units[i], prices[i]);
	}	
}



int main(){
	int choice;
	int n=0;
	char drink_codes[MAXN][50];
	char drink_names[MAXN][50];
	char drink_types[MAXN];
	int units[MAXN];
	double prices[MAXN];
	char drink_code[50];
	char drink_name[50];
	char drink_type;
	int unit;
	double price;

	do{
	choice = menu();
	switch(choice){
		case 1: //Add value
		if(isFull(drink_names,n)){
			printf("\nSorry, array is full!\n");
		}
		else{
			fflush(stdin);
			printf("Input drink code:");
			scanf("%4[^\n]", &drink_code);
			strupr(drink_code);
			
			fflush(stdin);
			printf("Name: ");
			scanf("%20[^\n]", &drink_name);
			strupr(drink_name);
			
			
			fflush(stdin);
			printf("Type: ");
			scanf("%c", &drink_type);
	
			
			fflush(stdin);
			printf("Unit:");
			scanf("%d", &unit);
			
			fflush(stdin);
			printf("Price:");
			scanf("%lf", &price);
			
			add(drink_code, drink_name, drink_type, unit, price, drink_codes, drink_names, drink_types, units, prices, &n);
			
			printf("Added!\n");
		}
			 
			break;
		case 2:
			printf("2");
			break;
		case 3:
			printf("2");
			break;
		case 4:
			printf("2");
			break;
		case 5: //sap xep giam dan theo loai do uong
			printDesc(n, drink_codes, drink_names, drink_types, units, prices);
			break;
		case 6: //sap xep tang dan theo gia tien
			printAsc(n, drink_codes, drink_names, drink_types, units, prices);
			break;
		case 7: //xuat toan bo danh sach
			printAll(n, drink_codes, drink_names, drink_types, units, prices);
			break;
		case 8:
			printf("2");
			break;
		case 9:
			printf("2");
			break;
		case 10:
			printf("2");
			break;
		default:
			printf("Quit!");
	}
	}while(choice > 0 && choice < 11);
	
	
	
	
	printf("\n");
	system("pause");
	
}
	
	


