#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//乱数の種を時間で初期化
	srand(time(NULL));

	int Sum = 0;

	/*for(繰り返しの最初にやりたいこと;
		  繰り返しを続ける条件;
		  繰り返すたびにやりたいこと)
		  ｛繰り返す処理｝
	*/
	for (int Ct = 1; Ct < 6; Ct++)
	{
		printf("%d個目のパラメーター\n", Ct);

		for (int Count = 1; Count < 4; Count++)
		{

			//ここが乱数の決定部分
			//1〜６のランダムな数字をNumに代入
			int Num = 1 + rand() % 6;


			printf("%d回目のダイスの目は%dです\n", Count, Num);

			Sum += Num;


		}

		printf("パラメーターの値は%dです\n\n", Sum);

	}
	return 0;
}