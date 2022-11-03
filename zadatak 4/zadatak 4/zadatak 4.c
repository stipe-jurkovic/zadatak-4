#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROGRAM_SUCCESS 0
#define PROGRAM_FAILED 1
#define MAX_NAME 500
#define MAX_LASTNAME 500
#define MAX_FILE_NAME 50

typedef struct _member {

	int coefficient;
	int exponent;

} Member;

struct Cvor;

typedef struct Cvor* Position;

typedef struct Cvor {

	Member Member;
	Position Next;

} Cvor;



int Menu();
int NewEl(Position P, Member O);
int DelElByName(Position P, Member O);
int PrintEl(Position P);
Position PrevEl(Position P, Member O);
Position EndOfList(Position P);
int DelAll(Position P);
int NewElBeg(Position P, Member O);
int NewElEnd(Position P, Member O);
int NewElAfter(Position P, Member OA, Member O);
int NewElBefore(Position P, Member OB, Member O);
int PrintList(Position P);
int findLastname(Position P, char lastname[MAX_LASTNAME]);
int PrintToFile(Position P, char nameOfFile[MAX_FILE_NAME]);
int ReadFromFile(char nameOfFile[MAX_FILE_NAME]);
int NewElSort(Position P, int c, int e);
int SortByLastname(Position P);
int cmp(char str1[MAX_LASTNAME], char str2[MAX_LASTNAME]);

int main()
{
	Member Member, Member2;
	Position head;
	int p, od;

	p = 0;
	od = 1;

	head = malloc(sizeof(Cvor));
	if (head == NULL) {
		printf("Kupi RAM\n");
		return PROGRAM_FAILED;
	}

	head->Next = NULL;

	Member.exponent = 0;
	Member.coefficient = 0;

	Member2.exponent = 0;
	Member2.coefficient = 0;


	return PROGRAM_SUCCESS;
}

int Menu() {

	printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n");
	printf("Unesite broj one opcije koju zelite odabrati.\n");
	printf("(0)  Prekinuti program.\n");
	printf("(1)  Dinamicki dodati novi element na pocetak liste.\n");
	printf("(2)  Dinamicki dodati novi element na kraj liste.\n");
	printf("(3)  Dinamicki dodati novi element iza odredenog elementa.\n");
	printf("(4)  Dinamicki dodati novi element ispred odredenog elementa.\n");
	printf("(5)  Ispisati listu.\n");
	printf("(6)  Pronaci element u listi (po prezimenu).\n");
	printf("(7)  Obrisati element iz liste.\n");
	printf("(8)  Sortirati listu po prezimenu Member.\n");
	printf("(9)  Upisati listu u datoteku.\n");
	printf("(10) Ucitati listu iz datoteke.\n");
	printf("(11) Izbrisati listu.\n");
	printf("\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
	printf("   Unos:    ");
	return PROGRAM_SUCCESS;
}

Position EndOfList(Position P) {

	while (P->Next != NULL) {
		P = P->Next;
	}
	return P;
}
Position PrevEl(Position P, Member O) {


	while (P->Next != NULL && P->Next->Member.exponent != O.exponent
		&& strcmp(P->Next->Member.name, O.name) != 0
		&& strcmp(P->Next->Member.lastname, O.lastname) != 0)
	{
		P = P->Next;
	}

	return P;
}
int PrintEl(Position P) {
	//P = P->Next;
	printf("\nName:       %s\n", P->Member.name);
	printf("Lastname:   %s\n", P->Member.lastname);
	printf("Birthyear:  %i\n", P->Member.exponent);
	printf("Age:        %i   (calculated from birthyear)\n", 2022 - P->Member.exponent);
	printf("\n");
	return PROGRAM_SUCCESS;
}
int DelElByName(Position P, Member O) {

	Position temp = NULL;

	P = PrevEl(P, O);
	if (P->Next == NULL)
	{
		printf("\n\nElement was not found!\n\n\n");
		return PROGRAM_FAILED;
	}
	temp = P->Next;
	P->Next = P->Next->Next;

	free(temp);
	printf("\n\nDeleted 1 element!\n\n\n");
	return PROGRAM_SUCCESS;
}
int DelAll(Position P) {

	int i = 0;
	if (P->Next == NULL)
	{
		printf("\n\nLista je prazna!! Success?\n\n\n");
		return PROGRAM_SUCCESS;
	}
	while (P->Next != NULL) {
		DelElByName(P, P->Next->Member);
		i++;
	}
	printf("\n\nDeleted list! Deleted %i entries.\n\n\n", i);
	return PROGRAM_SUCCESS;
}
int NewElAfter(Position P, Member M) {

	Position Q = malloc(sizeof(struct Cvor));

	if (Q == NULL)
	{
		printf("\n\nNedovoljno memorije.\n\n\n");
		return PROGRAM_FAILED;
	}

	Q->Member.coefficient = M.coefficient;
	Q->Member.exponent = O.exponent;

	Q->Next = P->Next;
	P->Next = Q;

	return PROGRAM_SUCCESS;
}

int NewElAfter(Position P, Member OB, Member O) {

	P = PrevEl(P, OB);
	NewEl(P->Next, O);
	printf("\n\nNew element created!\n\n\n");
	return PROGRAM_SUCCESS;
}
int NewElBefore(Position P, Member OA, Member O) {

	P = PrevEl(P, OA);
	NewEl(P, O);
	printf("\n\nNew element created!\n\n\n");
	return PROGRAM_SUCCESS;
}
int PrintList(Position P) {

	P = P->Next;
	if (P == NULL)
	{
		printf("\n\nLista je prazna!!\n\n\n");
		return PROGRAM_SUCCESS;
	}
	while (P != NULL) {

		printf("\nName:       %s\n", P->Member.name);
		printf("Lastname:   %s\n", P->Member.lastname);
		printf("Birthyear:  %i\n", P->Member.exponent);
		printf("Age:        %i   (calculated from birthyear)\n", 2022 - P->Member.exponent);
		P = P->Next;
		printf("\n");
	}
	return PROGRAM_SUCCESS;
}
int findLastname(Position P, char lastname[MAX_LASTNAME]) {
	P = P->Next;

	while (P != NULL) {
		if (strcmp(P->Member.lastname, lastname) == 0) {
			PrintEl(P);
			return PROGRAM_SUCCESS;
		}
		P = P->Next;
	}
	printf("\nLastname not found!!\n\n");

	return PROGRAM_FAILED;
}

int PrintToFile(Position P, char nameOfFile[MAX_FILE_NAME]) {
	FILE* file = NULL;
	char fileName[MAX_FILE_NAME] = "";

	strcpy(fileName, nameOfFile);
	file = fopen(fileName, "w");

	if (file == NULL)
	{
		printf("\n\nNedovoljno prostora.\n\n");
		return PROGRAM_FAILED;
	}

	P = P->Next;
	if (P == NULL)
	{
		printf("\n\nLista je prazna!!\n\n\n");
		return PROGRAM_FAILED;
	}
	while (P != NULL) {

		fprintf(file, "\nName:       %s\n", P->Member.name);
		fprintf(file, "Lastname:   %s\n", P->Member.lastname);
		fprintf(file, "Birthyear:  %i\n", P->Member.exponent);
		P = P->Next;
		fprintf(file, "\n");
	}

	printf("\n\nSuccessfully added the list to list.txt\n\n");
	fclose(file);

	return PROGRAM_SUCCESS;
}

int ReadFromFile(char nameOfFile[MAX_FILE_NAME], Position Poz)
{
	FILE* file = NULL;
	int c, e, n;
	file = fopen(nameOfFile, "r");
	char buffer[MAX_LINE] = { 0 };
	char* P = buffer;
	Member M;
	M.coefficient = 0;
	M.exponent = 0;
	c = 0; e = 0; n = 0;

	if (file == NULL){
		printf("\n\nNemoguce otvoriti datoteku.\n\n");
		return PROGRAM_FAILED;
	}

	fgets(buffer, MAX_LINE, file);

	while (strlen(buffer)>0){

		sscanf(P, " %d %d %n", &M.coefficient, &M.exponent, &n);
		P += n*sizeof(char);
		NewELSort(Poz, M);
	}

	printf("\n\nKraj liste.\n\n");
	fclose(file);
	return PROGRAM_SUCCESS;
}
int NewElSort(Position P, Member M) {

	Position temp;
	while (P->Next==NULL && P->Next->Member.exponent < M.exponent) {
		P = P->Next;
	}
	NewEl(temp, M);
	return
	

}