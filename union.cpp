//Modified from  https://www.tutorialspoint.com/cprogramming/c_unions.htm

#include <stdio.h>
#include <string.h>


//primitive data type
union Data {
	int i;
	float f;
	char str[20];
};

//Diff from a struct
struct DataS {
	int i;
	float f;
	char str[20];
};

int main() {

	union Data data;

	data.i = 10;
	printf("data.i : %d\n", data.i);

	data.f = 220.5;
	printf("data.f : %f\n", data.f);

	strcpy(data.str, "C Programming");
	printf("data.str : %s\n", data.str);

	printf("Size of union data %d \n", sizeof(data));

	printf("Size of struct data %d \n", sizeof(DataS));

	return 0;
}