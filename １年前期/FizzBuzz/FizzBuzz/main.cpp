#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Num = 0;
	printf("��������͂��Ă�������:");
	scanf("%d", &Num);

	while (Num <= 0)
	{
		printf("1�ȏ�̐�������͂��Ă�������:");
		scanf("%d", &Num);
	}

	for (int i = 1; i <= Num; i++)
	{
		if (i % 15 == 0)
		{
			printf("  FizzBuzz\n\n");			
		}
		else if (i % 3 == 0)
		{			
			printf("  Fizz\n\n");
		}
		else if (i % 5 == 0)
		{			
			printf("  Buzz\n\n");			
		}
		else
		{
			printf("%d\n\n", i);
		}
	}
	return 0;
}