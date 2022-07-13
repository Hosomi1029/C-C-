#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Student {
	char Name[20];
	int Age;
	float Height;
	float Weight;
};

Student* AddStudent()
{
	Student* add = new Student;

	printf("名前は？");
	scanf("%s", add->Name);
	printf("年齢は？");
	scanf("%d", &add->Age);
	printf("身長は？");
	scanf("%f", &add->Height);
	printf("体重は？");
	scanf("%f", &add->Weight);

	return add;

}

int main()
{
	int EMAX = 3;
	Student* sarray = new Student[EMAX];

	Student* st = AddStudent();
	printf("%s\n",st->Name);
	printf("%d\n", st->Age);
	printf("%f\n", st->Height);
	printf("%f\n", st->Weight);

	delete st;	//Destory

	return 0;
}