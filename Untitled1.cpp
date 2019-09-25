#include <stdio.h>
#include <stdlib.h>
char string[256];

struct profile{
	char name[15] = "huy";
	int age = 19;
	char gender[10] = "male";
};

struct profile user;
int main()
{ 
	printf("name: %s\nage: %d\ngender: %s\n", user.name, user.age, user.gender);
	printf("Nhap cau tra loi ");
	fgets(string, 256, stdin);
	printf("ban da tra loi: %s", string);
}
