/*
 * このプログラムはゲームの戦闘画面です
 * （１）～（６）の各設問に対応したプログラムを作成しなさい
 *
 * （１）ステータス表示のプログラム中に３度ほど
 *       下記のラインを引くプログラムを記述している
 *
 *			printf("|");
 *			for (int i = 0; i < FRAMEWIDTH; i++)
 *			{
 *					printf("-");
 *			}
 *			printf("|");
 *
 *		ラインを引く処理をLine関数として関数にしなさい
 *
 *
 * （２）現在のラインを引く処理は "-" の数はFRAMEWIDTHになっている
 *		Line関数に引数を追加し、引数に指定した数だけ "-" で、
 *		ラインを引くようにプログラムを変更しなさい。
 *
 *
 * （３）下記のプログラムで現在のカーソル位置を変更し、
 *		指定した位置に文字を挿入することができる
 *
 *			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
 *			COORD pos = { 表示したいX位置, 表示したいY位置 };
 *			SetConsoleCursorPosition(hStdout, pos);
 *
 *		x,yの位置を引数として受け取り、指定された位置に文字を追加できるようにする、
 *		SetCursorPosition関数を作成しなさい。
 *
 *
 * （４）ステータスの表示をShowStatus関数として、
 *		引数に表示したいUnit、表示したいX位置、表示したいY位置を受け取り、
 *		その位置にステータスを表示する関数にしなさい。
 *
 *
 * （５）Unit型の配列で下記の変数を追加し、
 *		ShowStatus関数を使用して表示しなさい
 *		Unit Enemy[3] = {
 *		 	{ "敵１", 50, 15, 10 },
 *		 	{ "敵２", 50, 15, 10 },
 *		 	{ "敵３", 50, 15, 10 },
 *		};
 *
 *
 * （６）08.cppのメニュー処理を使い、ドラクエ風の戦闘を完成させなさい。
 */
#include	<stdio.h>
#include	<conio.h>			//_kbhit、_getchを使うために追加
#include	<windows.h>			//system、Sleepを使うために追加

 //枠の幅
#define			FRAMEWIDTH		16

 //キャラクターのステータス
struct Unit {
	char Name[32];
	int HP;
	int STR;
	int DEF;
};

void Line(int w)
{
	printf("|");
	for (int i = 0; i < w; i++)
		{
		printf("-");
		
	}
	printf("|\n");
}

void SetCursorPosition(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hStdout, pos);
}


void ShowStatus(int x, int y, Unit un)
{
	SetCursorPosition(x, y);
	Line(FRAMEWIDTH);


	//名前をセンタリングで表示
	int slen = strlen(un.Name);
	int h = (FRAMEWIDTH - slen) / 2;

	SetCursorPosition(x, y + 1);
	printf("|%*s%*s|\n", slen + h, un.Name, h, "");

	//名前とステータスの間の線表示
	SetCursorPosition(x, y+2);
	Line(FRAMEWIDTH);

	//ステータスの表示
	SetCursorPosition(x, y+3);
	printf("|HP%14d|\n", un.HP);

	SetCursorPosition(x, y+4);
	printf("|STR%13d|\n", un.STR);
	
	SetCursorPosition(x, y+5);
	printf("|DEF%13d|\n", un.DEF);

	//下の線表示
	SetCursorPosition(x, y + 6);
	Line(FRAMEWIDTH);

}

int main(void) {
	//プレイヤーキャラクター
	Unit Player = { "プレイヤー", 100, 20, 10 };
	ShowStatus(10, 50,  Player);
	return 0;
}