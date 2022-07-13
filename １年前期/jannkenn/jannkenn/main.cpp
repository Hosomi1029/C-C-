#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//お互いの手を保存する
	int play1;
	int play2;
	
	//じゃんけんのルール
	printf("じゃんけんゲーム");
	printf("グーなら１\nチョキなら２\nパーなら３\nを入力してください\n");

	printf("player1:");
	scanf("%d", &play1);
	while (play1 < 1 || play1 > 3)
	{
		printf("間違った手です\n");
		scanf("%d", &play1);
		return 0;
	}

	printf("player2:");
	scanf("%d", &play2);
	while (play2 < 1 || play2 > 3)
	{
		printf("間違った手です\n");
		scanf("%d", &play2);

		return 0;
	}


	if (play1 == play2)
	{
		printf("あいこです\n");
	}
	else if (play1 == 1)
	{
		if (play2 == 2)
		{
			printf("player1の勝ちです\n");
		}
		else
		{
			printf("player2の勝ちです\n");
		}
	}
	else if (play1 == 2)
	{
		if (play2 == 3)
		{
			printf("player1の勝ちです\n");
		}
		else
		{
			printf("player2の勝ちです\n");
		}
	}
	else if (play1 == 3)
	{
		if (play2 == 1)
		{
			printf("player1の勝ちです\n");
		}
		else
		{
			printf("player2の勝ちです\n");
		}
	}
		
	/*
	if(play1 %3 + 1 == play2)
	{
	    printf("あなたの勝ちです")
	}
	else
	{
	   printf(あなたの負けです")
	}
	*/
	return 0;
}