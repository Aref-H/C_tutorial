/*
C is a general-purpose programming language that has been around for nearly 50 years.
C has been used to write everything from operating systems (including Windows and many others)
to complex programs like the Python interpreter, Git, Oracle database, and more.
The versatility of C is by design. It is a low-level language that relates closely
to the way machines work while still being easy to learn.


Some important lessons and examples in c language
developer: Aref


//****As when learning any new language, the place to start is with the classic "Hello World!"

#include <stdio.h>

int main()
{
	printf("Hello world!");
	return 0;
}


//****Data Types
//C supports the following basic data types :

#include <stdio.h>
int main()
{
	int forUpd;

	for (forUpd = 0; forUpd < 5; forUpd++)
	{
		switch (forUpd)
		{
		case 1:
			printf("Size of int = %d\n", sizeof(int));
			break;
		case 2:
			printf("Size of float = %d\n", sizeof(float));
			break;
		case 3:
			printf("Size of double = %d\n", sizeof(double));
			break;
		case 4:
			printf("Size of char = %d\n", sizeof(char));
			break;
		default:
			break;
		}
	}
	return 0;
}


//****Conditional Expressions

#include <stdio.h>

int main()
{
	int numInpute;

	scanf_s("%d", &numInpute);

	numInpute % 2 == 0 ? printf("even") : printf("odd");
	return 0;
}


//****Pointers

#include <stdio.h>

int main()
{
	int num = 10;
	int* p = NULL;

	p = &num;

	printf("Address of num is %x \n", &num);
	printf("p contains address %x \n", p);
	printf("The value that num contain is %d \n", num);
	printf("The value of the address that p contains is %d \n", *p);

	return 0;
}


//****pointers and array

#include <stdio.h>

int main()
{
	int numArray[2][3] = { {1,2,3}, {4,5,6} };
	int forUp1, forUp2, forUp3, forUp4;
	int (*p) [] = NULL;

	p = numArray;

	for (forUp1 = 0; forUp1 < 2; forUp1++)
	{
		for (forUp2 = 0; forUp2 < 3; forUp2++)
		{
			printf("%d", numArray[forUp1][forUp2]);
		}
		printf("\n");
	}
	printf("\n\n");

	for (forUp3 = 0; forUp3 < 2; forUp3++)
	{
		for (forUp4 = 0; forUp4 < 3; forUp4++)
		{
			printf("%d", *(*p + forUp3) + forUp4 );
		}
		printf("\n");
	}

	return 0;
}


//***Function Pointers

#include <stdio.h>

void printArash(int numTimes);
int main()
{
	void (*funPtr)(int);
	funPtr = printArash;

	funPtr(2);

	return 0;
}

void printArash(int numTimes)
{
	int loopUp = 0;
	for (loopUp = 0; loopUp < numTimes; loopUp++)
	{
		printf("Arash\n");
	}
}


//***Array of Function Pointers

#include <stdio.h>

int add(int x, int y);
int subtract(int x, int y);
int main()
{
	int x, y, choice, result;

	int (*op[2])(int, int);
	op[0] = add;
	op[1] = subtract;

	printf("Enter two integer:\n");
	scanf_s("%d %d", &x, &y);

	printf("Enter 0 for add and 1 for subtract\n");
	scanf_s("%d", &choice);

	result = op[choice](x, y);
	printf("%d", result);

	return 0;
}

int add(int x, int y)
{
	return (x + y);
}

int subtract(int x, int y)
{
	return (x - y);
}


//***The void Pointer

#include <stdio.h>

int main()
{
	int numInt = 133;
	float numFloat = 122;
	char charecter = 'a';
	void* ptr;

	ptr = &numInt;
	printf("ptr is pointing to %d\n", *((int*)ptr)); //We should typecast the void pointer to integer pointer.

	ptr = &numFloat;
	printf("ptr is pointing to %f\n", *((float*)ptr));

	ptr = &charecter;
	printf("ptr is pointing to %c\n", *((char*)ptr));

	return 0;
}


//***Functions Using void Pointers

#include <stdio.h>

void *square(const void *num);

int main()
{
	int x, sq_int;
	x = 6;
	
	sq_int = square(&x);

	printf("Square of %d is %d\n", x, sq_int);

	return 0;
}

void *square(const void *num)
{
	int result;
	result = (*(int*)num) * (*(int*)num);
	return result;
}


//***Function Pointers as Arguments

int compare(const void* elem1, const void* elem2);

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[5] = {50, 23, 4, 12, 33};
	int num, width, count;

	num = sizeof(arr) / sizeof(arr[0]);
	width = sizeof(arr[0]);

	qsort((void *)arr, num, width, compare);
	
	for (count = 0; count < num; count++)
	{
		printf("%d\n", arr[count]);
	}
	return 0;
}

int compare(const void* elem1, const void* elem2)
{
	if ((*(int*)elem1) == (*(int*)elem2))
	{
		return 0;
	}
	else if ((*(int*)elem1) > (*(int*)elem2))
	{
		return 1;
	}
	else if ((*(int*)elem1) < (*(int*)elem2))
	{
		return -1;
	}
}


//***Declarations Using Structures

#include <stdio.h>

struct student
{
	int age;
	int grad;
	char name[40];
};

int main()
{
	struct student s1;
	struct student s2;


	//**other ways of declration
	//struct student s1 = {10, 1, "Aref"};

	//struct student s1;
	//s1 = (struct student) {10, 1, "Aref"};

	//struct student s1 = { .age = 10, .grad = 1, .name = "Aref"};
	//**

	s1.age = 10;
	s1.grad = 1;
	sprintf_s(s1.name, 40, "Aref");

	s2.age = 11;
	s2.grad = 2;
	sprintf_s(s2.name, 40, "Aref1");

	printf("Student name : %s\nStudent age : %d\nStudent grad : %d", s1.name, s1.age, s1.grad);
	printf("\n\n");
	printf("Student name : %s\nStudent age : %d\nStudent grad : %d", s2.name, s2.age, s2.grad);

	return 0;
}


//***Using typedef

#include <stdio.h>

 typedef struct
{
	int age;
	int grad;
	char name[40];
} student;

int main()
{
	student s1;
	student s2;


	//**other ways of declration
	//student s1 = { 10, 1, "Aref" };

	//student s1;
	//s1 = (student){ 10, 1, "Aref" };

	//student s1 = { .age = 10, .grad = 1, .name = "Aref" };
	//**

	s1.age = 10;
	s1.grad = 1;
	sprintf_s(s1.name, 40, "Aref");

	s2.age = 11;
	s2.grad = 2;
	sprintf_s(s2.name, 40, "Aref1");

	printf("Student name : %s\nStudent age : %d\nStudent grad : %d", s1.name, s1.age, s1.grad);
	printf("\n\n");
	printf("Student name : %s\nStudent age : %d\nStudent grad : %d", s2.name, s2.age, s2.grad);

	return 0;
}


//***Pointers to Structures

#include <stdio.h>

typedef struct
{
	int age;
	int grad;
	char name[30];
} student;

void showStData(student* st);

int main()
{
	student s1 = { .age = 10, .grad = 1, .name = "Aref"};

	showStData(&s1);

	return 0;
}

void showStData(student *st)
{
	printf("Student name : %s\n", st->name);
	printf("Student age  : %d\n", st->age);
	printf("Student grad : %d\n", st->grad);
}


//***Array of Structures

#include <stdio.h>

typedef struct
{
	int age;
	int grad;
	char name[30];
} student;

void showStData(student* st);

int main()
{
	student s1[3] = {{.age=10, .grad=1, .name="Aref"}
	                ,{.age=11, .grad=2, .name="Aref1"}
	                ,{.age=12, .grad=3, .name="Aref2"}};

	showStData(&s1[0]);
	showStData(&s1[1]);
	showStData(&s1[2]);

	return 0;
}

void showStData(student* st)
{
	printf("Student name : %s\n", st->name);
	printf("Student age  : %d\n", st->age);
	printf("Student grad : %d\n", st->grad);
	printf("\n\n");
}


//***Union is like struct but it will store different data types in the same memory location.
//***However, a union variable uses the same memory location for all its member's and only
//***one member at a time can occupy the memory location.


//***Structures With Unions

#include <stdio.h>

typedef struct
{
	char carCompany[40];
	char carName[40];
	int unitType;//0 for mph and 1 for kph
	union 
	{
		int carSpeed;
		char unitT[2][20];
	}type;
}vehicle;

int main()
{
	vehicle car1 = {.carCompany = "Ford", .carName = "Mustang", .unitType = 0};

	printf("Car: %s %s\n", car1.carCompany, car1.carName);
	
	car1.type.carSpeed = 160;
	printf("Speed: %d", car1.type.carSpeed);
	
	sprintf_s(car1.type.unitT[0], 20, "mph", car1.type.unitT[1], 20, "kph");
	printf (" %s\n", car1.unitType == 0 ? car1.type.unitT[0] : car1.type.unitT[1]);
	
	return 0;
}


//***memory management
//sizeof
#include <stdio.h>

int main()
{
	int x;
	int arr[10];

	printf("x : %d\n", sizeof(x));
	printf("arr : %d", sizeof(arr));

	return 0;
}


//***malloc
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr;

	ptr = malloc(10 * sizeof(*ptr));

	if (ptr != NULL)
	{
		*(ptr + 2) = 50;
	}

	printf("3rd element of ptr is equal to %d", *(ptr + 2));

	return 0;
}


//***free()
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr;

	ptr = malloc(10 * sizeof(*ptr));

	if (ptr != NULL)
	{
		*(ptr + 2) = 50;
	}

	printf("3rd element of ptr is : %d", *(ptr + 2));

	free(ptr);

	return 0;
}


//***calloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;
	char *info;
} record;

int main()
{
	record *racs;
	int numRacs = 2;
	int k;
	char str[] = { "This is information" };

	racs = calloc(numRacs, sizeof(record));

	if (racs != NULL)
	{
		for (k = 0; k < numRacs; k++)
		{
			(racs[k]).num = k;
			(racs[k]).info = malloc(sizeof(str));
			strcpy_s((racs[k]).info, sizeof(str), str);
		}
	}

	for (k = 0; k < numRacs; k++)
	{
		printf("%d\t%s\n", (racs[k]).num, (racs[k]).info);
	}

	return 0;
}


//***realloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int* ptr;

	ptr = malloc(10 * sizeof(*ptr));

	if (ptr != NULL)
	{
		*(ptr + 2) = 50;
	}
	printf("%d\n", *(ptr + 2));

	int* tempPtr = realloc(ptr, 100 * sizeof(*ptr));

	if (ptr != NULL)
	{
		*(ptr + 50) = 70;
	}
	printf("%d\n", *(ptr + 50));

	return 0;
}


//***Allocating memory for string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char aString[] = "12345";
	char* str = NULL;

	str = malloc(strlen(aString) + 1);
	strcpy_s(str, 6, aString);

	printf("%s\n", str);

	return 0;
}


//***Dynamic array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* elemnts;
	int size;
	int cap;
}dynaArr;

int main()
{
	dynaArr arr;
	int loopUp;
	char* tmp = NULL;

	arr.size = 0;
	arr.elemnts = calloc(1, sizeof(arr.elemnts));
	arr.cap = 1;

	tmp = realloc(arr.elemnts, (5 + arr.cap) * sizeof(arr.elemnts));
	arr.cap += 5;

	if (arr.size < arr.cap)
	{
		arr.elemnts[arr.size] = 50;
		arr.size++;
	}

	else
	{
		printf("Need to expand array!");
	}

	for (loopUp = 0; loopUp < arr.cap; loopUp++)
	{
		printf("Elemnt %d : %d\n", loopUp, arr.elemnts[loopUp]);
	}
	return 0;
}


//***Opening and closing file
#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* fptr;
	errno_t err;
	char fileName[] = "Myfile.txt";

	err = fopen_s(&fptr, fileName, "w");

	if (err != 0)
	{
		printf("Error opening file!\n");
		return -1;
	}
	fclose(fptr);

	return 0;
}


//***writing to file and reading from it
#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* fptr;
	errno_t err;
	char buff;

	//write to file
	err = fopen_s(&fptr, "myFile.txt", "w");
	if (err != 0)
	{
		printf("Error opening file!\n");
		return -1;
	}
	else
	{
		fprintf(fptr, "Inventory :\n");
		fprintf(fptr, "%d %s %.2f\n", 100, "widget", 0.29);
		fputs("End of file!", fptr);
		fclose(fptr);
	}

	//read from file
	err = fopen_s(&fptr, "myFile.txt", "r");

	while ((buff = fgetc(fptr)) != EOF)
	{
		printf("%c", buff);
	}
	fclose(fptr);

		return 0;
}


//***writing to and reading from binary files
#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* fptr;
	errno_t err;

	int arr[10];
	int x[10];
	int loopUp;

	//generating array
	for (loopUp = 0; loopUp < 10; loopUp++)
	{
		arr[loopUp] = loopUp;
	}


	//Writing to binary file
	err = fopen_s(&fptr, "DataFile.bin", "wb");

	//We should use "if(err != 0 or fptr == NULL)" i skipped that part 
	fwrite(arr, sizeof(arr[0]), sizeof arr / sizeof(arr[0]), fptr);
	fclose(fptr);



	//Reading from binary file
	err = fopen_s(&fptr, "DataFile.bin", "rb");

	//We should use "if(err != 0 or fptr == NULL)" i skipped that part
	fread(x, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fptr);
	fclose(fptr);

	//printing 
	for (loopUp = 0; loopUp < 10; loopUp++)
	{
		printf("%d\n", x[loopUp]);
	}

	return 0;
}


//***controlling the location of the file pointer in a binary file
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct
{
	char name[20];
	int age;
}person;

int main()
{
	FILE* fptr;
	errno_t err;

	person first, second, forBuffer;

	//Making record
	strcpy_s(first.name, 20, "Aref");
	first.age = 15;
	strcpy_s(second.name, 20, "Arash");
	second.age = 20;

	//writing record to file
	err = fopen_s(&fptr, "DataFile.dat", "wb");
	if (err != 0 || fptr == NULL) //We can use one of these conditions
	{
		printf("Error opening file!");
		return -1;
	}
	fwrite(&first, 1, sizeof(first), fptr);
	fwrite(&second, 1, sizeof(second), fptr);
	fclose(fptr);

	//Opening file for reading
	err = fopen_s(&fptr, "DataFile.dat", "rb");
	if (err != 0 || fptr == NULL)
	{
		printf("Error opening file!");
		return -1;
	}
	//Seeking second record
	fseek(fptr, 1 * sizeof(person), SEEK_SET);
	fread(&forBuffer, 1, sizeof(person), fptr);
	fclose(fptr);

	printf("Name : %s\tAge : %d\n", forBuffer.name, forBuffer.age);

	return 0;
}*/


//***Error Handling
/*
**In summary, exit(EXIT_FAILURE); is typically used at the end of main() to indicate 
**a program-wide failure, while return -1; is used within a function to signal an error locally. 
**Choose the one that best fits your context!
*//*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int age = 20;

	if (age > 7 && age <= 15)
	{
		printf("Welcome to child's park!\n");
	}
	else
	{
		printf("Your age is greater than arranged age!\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}


//***Using Error Codes
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fptr;
	errno_t err;
	errno = 0;
	char buffer[50];

	err = fopen_s(&fptr, "nonExistenceFile.txt", "r");
	if (err != 0 || fptr == NULL)
	{
		printf("First model  : Error opening file!\n");
		printf("Second model : Error opening file! Error code : %d\n", errno);
		
		printf("Third model  : ");
		perror("Error");

		printf("Forth model  : ");
		strerror_s(&buffer, 50, errno);
		printf("%s\n", buffer);

		exit(EXIT_FAILURE);
	}

	return 0;
}


//***Listing error codes
#include <stdio.h>
#include <errno.h>

int main()
{
	//int loopUp;
	for (errno = 0; errno <= 140; errno++)
	{
		printf("%d - ", errno);
		perror("Error");
	}

	return 0;
}*/
//***There is also :

//***EDOM and ERANGE Error Codes :
//EDOM when a domain is out of range.
//ERANGE macro value is used when there is a range error.

//***The feof and ferror Functions
//feof(fp) Returns a nonzero value if the end of stream has been reached, 0 otherwise. feof also sets EOF.
//ferror(fp) Returns a nonzero value if there is an error, 0 for no error.


//***Preprocessor directive
/*
**#include Including header files.
**#define, #undef Defining and undefining macros.
**#ifdef, #ifndef, #if, #else, #elif, #endif Conditional compilation.
**#pragma Implementation and compiler specific.
**#error, #warning Output an error or warning message An error halts compilation.



//***Define
#include <stdio.h>

#define PI 3.14
#define AREA(r) ((PI)*(r)*(r)) //Pay attention to calculation
#define AREA_NOT_IN_CORRECT_WAY(r) (PI * r * r) //If we add "+1" to radius its going to be like\
                                                  this (PI*r+1*r+1). See last printf Answer.

int main()
{
	double radius = 2;
	
	printf("PI is equal to : %.2f\n", PI);
	printf("Area with radius %.2f is equal to : %.3f\n", radius, AREA(radius));
	printf("Area with radius %.2f is equal to : %.3f\n", radius + 1, AREA(radius + 1));
	printf("Area with radius %.2f is equal to : %.3f  <- This one is wrong\n", radius + 1,\
    AREA_NOT_IN_CORRECT_WAY(radius + 1));

	return 0;
}


//***Predefined Macro Definitions
#include <stdio.h>
#include <string.h>

int main()
{
	char currTime[20];
	char currDate[20];

	strcpy_s(currTime, 20, __TIME__);
	strcpy_s(currDate, 20, __DATE__);

	printf("Current time is : %s\n", currTime);
	printf("Current date is : %s\n", currDate);

	return 0;
}


//***The #ifdef, #ifndef, and #undef Directives
#include <stdio.h>

#define PI 3.14
#define AREA

int main()
{
	float radius = 2;

	#ifdef AREA
		#undef AREA
		#define AREA(r) ((PI) * (r) * (r))
	#else
		#define AREA ((PI) * (r) * (r))    
	#endif 

	printf("PI is equal to : %.2f\n", PI);
	printf("Area with radius %.2f is equal to : %.2f", radius, AREA(radius));

	return 0;
}


//***TO_STR
#include <stdio.h>

#define TO_STR(x) #x

int main()
{
	printf("%s\n", TO_STR(125 * 125));

	return 0;
}*/

