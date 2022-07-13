#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	srand(time(NULL));

	constexpr int Ans = 3;

	//配列で解答用の変数を用意する
	//型　名前　[用意したい個数（要素数）]
	//{一つ目の要素の値,二つ目の要素の値,・・・}
	int Date[Ans];

	printf("Answer:");

	for (int i=0; i < Ans; i++ )
	{
		//配列の変数の利用
		//名前[使いたい要素の利用]
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

	printf("\n\n\n３つの数字を入力してください\n");
	int Hit = 0;
	int Blow = 0;

	int An[Ans];
	for (int q = 1; q < 11; q++)
	{
		printf("%d回目の入力です\n", q);
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

		printf("Hit:%d、Blow:%d\n", Hit, Blow);

		if (Hit == Ans)
		{
			printf("正解！！");
				break;
		}

		if (q == 10)
		{
			printf("残念（泣\n");
		}

		Hit = 0;
		Blow = 0;

	}
	return 0;
}