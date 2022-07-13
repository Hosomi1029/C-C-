#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//乱数の種を時間で初期化
	srand(time(NULL));

	//パラメーターの数だけ繰り返す
	for (int pcnt = 0; pcnt < 8; pcnt++)
	{
		//合計を保存するための変数を作成
		int Sum = 0;

		//ダイスを降る数
		int dice = 3;
		//6個目と７個目だけ数を変える
		if (pcnt == 5 || pcnt == 6)
		{
			dice = 2;
			Sum = 6;
		}
		//8個目は最初から＋３
		else if (pcnt == 7)
		{
			Sum = 3;
		}
		//繰り返し(for)
		// for( 繰り返しの最初にやりたいこと ;
		//		繰り返しを続ける条件 ;
		//		繰り返すごとにやりたいこと )
		//		{ 繰り返したい処理 }
		for (int Count = 0; Count < dice; Count++)
		{
			//ここが乱数の決定部分
			//１～６のランダムな数字をNumに代入
			int Num = 1 + rand() % 6;

			//さいころの目を足す
			Sum += Num;

			//ダイスの目を表示する
			printf("%d回目のダイスは%dです\n",
				Count + 1, Num);
		}
		//合計を表示
		printf("パラメーターは%dです\n\n", Sum);
	}

	//繰り返し(while)
	// while( 繰り返しを続ける条件 )
	//		{ 繰り返したい処理 }
	//int Count = 0;
	//while (Count < 3)
	//{
	//	Count++;
	//}
	return 0;
}