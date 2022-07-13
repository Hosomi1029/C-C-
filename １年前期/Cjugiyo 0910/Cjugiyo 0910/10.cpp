/*
 * このプログラムはゲームの戦闘画面です
 * （１）～（５）の各設問に対応したプログラムを作成しなさい
 *
 * （１）攻撃側のUnitと防御側のUnitを引数で受け取り、
 *		STR - DEFでダメージ値を計算し戻り値として返す、
 *		CalcDamage関数を作成し、攻撃処理を実装しなさい。
 *
 *
 * （２）攻撃、防御の数値にかかわる状態異常の効果として、衰弱・硬化・バーサクを定義し、
 *		状態異常用の構造体としてCondition構造体を継続ターンと効果の種類をもつように用意している。
 *		またUnit構造体には状態異常効果として、メンバにCondition構造体を配列で追加している。
 *		Unit構造体を引数で受け取りメンバのCondition構造体から攻撃力の倍率をfloat型で返すAtkMagnification関数と、
 *		Unit構造体を引数で受け取りメンバのCondition構造体から防御力の倍率をfloat型で返すDefMagnification関数を作成し、
 *		状態異常の場合の倍率の計算をおこないCalcDamageのダメージ計算処理を変更しなさい。
 *
 *
 *	(３) 攻撃～ダメージまでの処理をDoAttack関数として関数で処理をおこなうように変更しなさい
 *		※関数内部で値を変更しても元の値は変化しない、
 *		　そこで変数を値渡しではなく、ポインタ渡しもしくは参照渡しを使う必要がある
 *		　ポインタ渡し、参照渡しは次回ポインタで扱う
 *
 *
 * （４）Unit構造体の状態異常は配列になっているが、
 *		配列では設定した要素数以上の効果はかけられない
 *		std::vectorなどのコンテナクラスを利用して、
 *		何件でもかけられるように変更しなさい
 *
 *
 *	(５) 今回は攻撃、防御の数値にかかわる状態異常のみ実装をおこなった、
 *		他の代表的な状態異常、毒・麻痺・混乱などを実装しなさい
 */
#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<conio.h>			//_kbhit、_getchを使うために追加
#include	<windows.h>			//system、Sleepを使うために追加
#include	<string>			//std::stringを使うために追加
#include	<sstream>			//std::stringstreamを使うために追加

 //状態フラグ
enum ConditionFlag {
	Weakness,					//衰弱(Atk,Def0.5倍)
	Curing,						//硬化(Atk0.5倍,Def1.5倍)
	Berserk,					//バーサク(Atk2倍,Def0)
};

//状態異常文字
const char* ConditionString[] = {
	"衰弱",
	"硬化",
	"バーサク",
};

//キャラクターにかかっている状態異常
struct Condition {
	int Turn;					//効果継続ターン
	ConditionFlag Flag;			//効果
};

//状態異常適用数
#define			CONDITIONCOUNT	3

//キャラクターのステータス
struct Unit {
	char Name[32];
	int HP;
	int STR;
	int DEF;
	Condition Cond[CONDITIONCOUNT];
};

//枠の幅
#define			FRAMEWIDTH		24

/**
 * @brief		ラインを引く処理
 * @param[in]	c	ラインの長さ
 */
void Line(int c = FRAMEWIDTH) {
	printf("|");
	for (int i = 0; i < c; i++)
	{
		printf("-");
	}
	printf("|\n");
}

/**
 * @brief		文字を挿入するカーソル位置を設定する
 * @param[in]	x	カーソルのX位置
 * @param[in]	y	カーソルのY位置
 */
void SetCursorPosition(int x, int y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hStdout, pos);
}

/**
 * @brief		引数で指定されてUnitのステータスを表示する処理
 * @param[in]	u	表示するUnit
 * @param[in]	x	表示するX位置
 * @param[in]	y	表示するY位置
 */
void ShowStatus(const Unit& un, int x, int y) {
	SetCursorPosition(x, y++);
	Line();

	SetCursorPosition(x, y++);
	int slen = strlen(un.Name);
	int h = (FRAMEWIDTH - slen) / 2;
	printf("|%*s%*s|", slen + h, un.Name, h, "");

	SetCursorPosition(x, y++);
	Line();

	SetCursorPosition(x, y++);
	printf("|HP%22d|", un.HP);

	//（２）ステータス表示にバフによる倍率を追加
	SetCursorPosition(x, y++);
	printf("|STR%21d|", un.STR);

	SetCursorPosition(x, y++);
	printf("|DEF%21d|", un.DEF);

	SetCursorPosition(x, y++);
	Line();

	SetCursorPosition(x, y++);
	std::stringstream ss;
	for (int i = 0; i < CONDITIONCOUNT; i++)
	{
		if (un.Cond[i].Turn <= 0)
		{
			continue;
		}
		ss << ConditionString[un.Cond[i].Flag] << '(' << un.Cond[i].Turn << ')';
	}
	printf("|State%19s|", ss.str().c_str());

	SetCursorPosition(x, y++);
	Line();
}

float AtkMagnification(Unit un)
{
	float re = 1;
	for (int i = 0; i < CONDITIONCOUNT; i++) {

		//ターン数切れたら無視
		if (un.Cond[i].Turn <= 0)
		{
			continue;
		}
		switch (un.Cond[i].Flag)
		{
		case Weakness:
			re *= 0.5f;
			break;

		case Curing:
			re *= 0.5f;
			break;

		case Berserk:
			re *= 2.0f;
			break;
		}
	}
	return re;
}

float DefMagnification( Unit un)
{
	float re = 1;


	for (int i = 0; i < CONDITIONCOUNT; i++) {

		//ターン数切れたら無視
		if (un.Cond[i].Turn <= 0)
		{
			continue;
		}

		switch (un.Cond[i].Flag)
		{
		case Weakness:
			re *= 0.5f;
			break;

		case Curing:
			re *= 1.5f;
			break;

		case Berserk:
			re *= 2.0f;
			break;
		}
	}

	return re;
}

int CalcDamage(Unit unSTR, Unit unDEF)
{
	return unSTR.STR - unDEF.DEF;
}


int main(void) {
	//プレイヤーキャラクター
	//Unit Player = { "プレイヤー", 100, 20, 10 };
	//（２）確認用、上の値と差し替えて使う
	Unit Player = { "プレイヤー", 100, 20, 10, {{ 3,Weakness }} };					//衰弱
	//Unit Player = { "プレイヤー", 100, 20, 10, {{ 3,Curing }} };						//硬化
	//Unit Player = { "プレイヤー", 100, 20, 10, {{ 3,Berserk }} };						//バーサク
	//Unit Player = { "プレイヤー", 100, 20, 10, {{ 3,Weakness },{ 3,Weakness }} };		//衰弱＊２
	//敵キャラクター
	Unit Enemy = { "敵", 50, 15, 10 };

	//どちらかのHPが０になるまで実行
	while (Player.HP > 0 && Enemy.HP > 0)
	{

		//ステータス表示
		ShowStatus(Player, 20, 12);
		ShowStatus(Enemy, 20, 0);
		SetCursorPosition(0, 24);
		Line(64);

		//キー入力までいったん待機
		_getch();

		//（１）ダメージ計算の関数を作成し攻撃処理を実装

		Player.HP -= CalcDamage(Player, Enemy)* AtkMagnification(Player);
		;
		Enemy.HP -= CalcDamage(Enemy, Player) * DefMagnification(Player);
		;

		// プレイヤーから敵への攻撃
		printf("%sの攻撃、%sへ%dのダメージ\n", Player.Name, Enemy.Name, CalcDamage(Player, Enemy));
		// 敵からプレイヤーへの攻撃
		printf("%sの攻撃、%sへ%dのダメージ\n", Enemy.Name, Player.Name, CalcDamage(Enemy, Player));

		//ターン経過、状態異常やバフのターンを減らす
		//可能であれば攻撃処理と同様に関数化をおこなうこと
		for (int i = 0; i < CONDITIONCOUNT; i++)
		{
			Player.Cond[i].Turn--;
			Enemy.Cond[i].Turn--;
		}
	}

	//結果表示
	if (Player.HP <= 0)
	{
		printf("\033[31m");
		printf("%sは死んでしまった\n", Player.Name);
		printf("\033[0m");

		printf("\033[41m");
		ShowStatus(Player, 20, 12);
		printf("\033[0m");
	}
	else if (Enemy.HP <= 0)
	{
		printf("\033[33m");
		printf("%sを倒した\n", Enemy.Name);
		printf("\033[0m");

		printf("\033[41m");
		ShowStatus(Enemy, 20, 0);
		printf("\033[0m");
	}
	SetCursorPosition(0, 28);
	return 0;
}