#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//���݂��̎��ۑ�����
	int play1;
	int play2;
	
	//����񂯂�̃��[��
	printf("����񂯂�Q�[��");
	printf("�O�[�Ȃ�P\n�`���L�Ȃ�Q\n�p�[�Ȃ�R\n����͂��Ă�������\n");

	printf("player1:");
	scanf("%d", &play1);
	while (play1 < 1 || play1 > 3)
	{
		printf("�Ԉ������ł�\n");
		scanf("%d", &play1);
		return 0;
	}

	printf("player2:");
	scanf("%d", &play2);
	while (play2 < 1 || play2 > 3)
	{
		printf("�Ԉ������ł�\n");
		scanf("%d", &play2);

		return 0;
	}


	if (play1 == play2)
	{
		printf("�������ł�\n");
	}
	else if (play1 == 1)
	{
		if (play2 == 2)
		{
			printf("player1�̏����ł�\n");
		}
		else
		{
			printf("player2�̏����ł�\n");
		}
	}
	else if (play1 == 2)
	{
		if (play2 == 3)
		{
			printf("player1�̏����ł�\n");
		}
		else
		{
			printf("player2�̏����ł�\n");
		}
	}
	else if (play1 == 3)
	{
		if (play2 == 1)
		{
			printf("player1�̏����ł�\n");
		}
		else
		{
			printf("player2�̏����ł�\n");
		}
	}
		
	/*
	if(play1 %3 + 1 == play2)
	{
	    printf("���Ȃ��̏����ł�")
	}
	else
	{
	   printf(���Ȃ��̕����ł�")
	}
	*/
	return 0;
}