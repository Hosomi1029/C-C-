#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	srand(time(NULL));

	constexpr int Ans = 3;

	//�z��ŉ𓚗p�̕ϐ���p�ӂ���
	//�^�@���O�@[�p�ӂ��������i�v�f���j]
	//{��ڂ̗v�f�̒l,��ڂ̗v�f�̒l,�E�E�E}
	int Date[Ans];

	printf("Answer:");

	for (int i=0; i < Ans; i++ )
	{
		//�z��̕ϐ��̗��p
		//���O[�g�������v�f�̗��p]
		Date[i] = rand() % 10;
		if (i != 0)
		{
			for (int p = 1; p < i;p++)
			{
				if (Date[i] == Date[p])
				{
					Date[i] = 0;
					continue;
				}

			}
		}
		printf("%d",Date[i]);
		
		if (i == 2)
		{
			break;
		}
		printf(",");

		
	}

	printf("\n\n\n�R�̐�������͂��Ă�������\n");
	int Hit = 0;
	int Blow = 0;

	int An[Ans];
	for (int q = 1; q < 11; q++)
	{
		printf("%d��ڂ̓��͂ł�\n", q);
		for (int j = 0; j < Ans; j++)
		{
			scanf("%d", &An[j]);
			for (int t = 0; t < Ans; t++)
			{
				if (Date[t] == An[j])
				{
					if (t == j)
					{
						Hit++;
						break;
					}

					Blow++;
				}
			}


			if (j == 2)
			{
				break;
			}
			printf(",");
		}

		printf("Hit:%d�ABlow:%d\n", Hit, Blow);

		if (Hit == Ans)
		{
			printf("�����I�I");
				break;
		}

		if (q == 10)
		{
			printf("�c�O�i��\n");
		}

		Hit = 0;
		Blow = 0;

	}
	return 0;
}