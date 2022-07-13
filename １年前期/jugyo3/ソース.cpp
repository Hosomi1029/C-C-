#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int Data1;
	int Data2;

	printf("成績1を入力してください\n");

	scanf("%d", &Data1);

	printf("成績２を入力してください\n");

	scanf("%d", &Data2);


	if (Data1 >= 80)
	{
		//条件にあてはまる場合の処理を記述

		printf("◎\n");
	}
	else if (Data1 >= 60)
	{
		//ifの条件があてはまらず
		//eles ifの条件にあてはまる場合の処理を記述
		printf("〇\n");

	}
	else
	{
        //条件にあてはまらない場合の処理を記述
		printf("×\n");
		
	}
		
	
	//ifの条件をみたした場合にさらにif文を記述することで
	//処理を作成することをネストという
	if (Data1 >= 80)
	{
		//Data1が８０以上の場合にさらに条件判定
		if (Data2 >= 80)
		{
			//Data１が８０以上かつData2が８０以上の場合のみここにくる
			printf("〇\n");
		}
		else
		{
			//Data2の条件にあてはまらない場合の処理を記述
			printf("×\n");
		}
	}
	else
	{
		printf("×\n");
	}
	
	//複合条件
	//&& AND かつ
	//左と右の条件両方を満たしていれば真、違うなら偽
	if (Data1 >= 80 && Data2 >= 80)
	{
		printf("◎\n");
	}
	else
	{
		printf("×\n");
	}

	return 0;
}