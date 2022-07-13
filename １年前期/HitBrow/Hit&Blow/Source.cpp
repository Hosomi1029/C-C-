#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	//乱数の種を時間で初期化
	srand(time(NULL));
	//ここが乱数の決定部分
	//１～６のランダムな数字をNumに代入
	int Num = 1 + rand() % 6;
	
	//答えの桁数
	constexpr int anscnt = 3;

	//配列で解答用の変数を用意する
	// 型 名前 [ 用意したい個数(要素数) ] = 
	// { 一つ目の要素の値, 二つ目の要素の値, ... }
	int ans[anscnt];// = { rand() % 10,rand() % 10,rand() % 10 };

	//配列にランダムな数字を代入する
	printf("Answer : ");
	for (int no = 0; no < anscnt; no++)
	{
		//配列の変数の利用
		// 名前 [ 使いたい要素の番号 ];
		ans[no] = rand() % 10;
		printf("%d,", ans[no]);
	}
	printf("\n");

	//10回繰り返し遊ぶ
	for (int playcnt = 0; playcnt < 10; playcnt++)
	{
		//ゲーム回数の表示
		printf("%d回目の解答\n", playcnt);

		//入力用の変数を配列で作成
		int inp[anscnt];

		//配列に数字を入力させる
		printf("Input : \n");
		for (int no = 0; no < anscnt; no++)
		{
			//scanfによる代入
			scanf("%d", &inp[no]);
		}
		//入力された数字の表示
		printf("Input : ");
		for (int no = 0; no < anscnt; no++)
		{
			printf("%d,", inp[no]);
		}
		printf("\n");

		//総当たりでの判断
		int Hit = 0;
		int Blow = 0;
		for (int ano = 0; ano < anscnt; ano++)
		{
			for (int ino = 0; ino < anscnt; ino++)
			{
				//解答と入力の値の比較
				if (ans[ano] == inp[ino])
				{
					//場所が一致すればHit
					if (ano == ino)
					{
						Hit++;
					}
					//違えばBlow
					else
					{
						Blow++;
					}
				}
			}
		}
		//結果の表示
		printf("Hit : %d, Blow : %d\n", Hit, Blow);

		//Hitの数が解答の数と一致したら正解
		if (Hit == anscnt)
		{
			printf("正解!!\n");
			break;
		}
	}
	return 0;
}
