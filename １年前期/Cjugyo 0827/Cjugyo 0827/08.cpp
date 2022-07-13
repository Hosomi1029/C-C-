/*
 * このプログラムはゲームのメニュー画面です
 * （１）～（4）の各設問に対応したプログラムを作成しなさい
 *
 * （１）Enterキーを押してメニューを決定した際に
 *		switch文を使用して選んでいるメニューに応じて、
 *		「始める」と「オプション」を選択した場合はprintfでメッセージを表示、
 *		「終わる」を選択した場合はアプリを終了するように作成しなさい
 *
 *
 * （２）switch文のcase条件をenumの定数を使用するように条件を変更しなさい。
 *
 *
 * （３）「始める」を選択し決定した場合は現状のメニューと同様の処理で
 *		ステージ１～４と「メニューに戻る」を選択で選べるように処理を作成し、
 *		ステージ１～４を決定した場合は決定したステージ番号をprintfで表示、
 *		「メニューに戻る」を決定した場合は元のメニューに戻るように処理を作成しなさい。
 *
 *
 * （４）Game関数とOption関数を作成し、Game関数内では（３）の処理を実行する
 *		「始める」「オプション」を決定した場合、
 *		それぞれの関数を実行するようにプログラムを変更しなさい。
 */
#include	<stdio.h>
#include	<conio.h>			//_kbhit、_getchを使うために追加
#include	<windows.h>			//system、Sleepを使うために追加

enum item {
	Start,
	Option,
	End,
	TitleMenuCount
};

enum Stage {
	Sta1,
	Sta2,
	Sta3,
	Sta4,
	Menu,
	StaCount
};

enum Seane {
	Title,
	Game
};

int main(void) {
	//選択
	int sel = 0;
	int Routine = Title;

	//選択項目
	const char* item[] = {
		"始める",
		"オプション",
		"終わる",
	};

	const char* Stage[] =
	{
		"ステージ 1",
		"ステージ 2",
		"ステージ 3",
		"ステージ 4",
		"メニューに戻る"
	};

	switch (Routine)
	{
	  case Title:
		//項目表示
		system("cls");  //コンソールキーの文字をすべて消す
		for (int i = 0; i < TitleMenuCount; i++)
		{
			if (sel == i)
			{
				printf("\033[33m");		//色変更  \033[（色の指定）
				printf("->%s\n", item[i]);
				printf("\033[0m");
			}
			else
			{
				printf("  %s\n", item[i]);
			}
		}

		while (1)
		{
			//Sleepで1msec待機
			Sleep(1);

			//キー入力がある場合
			if (_kbhit())		//_kbhit　ボタンを押したことだけを判断する
			{
				//入力キーの取得
				int key = _getch();

				//上下キーで選択
				if (key == 72)
				{
					if (sel > 0)
					{
						sel--;
					}
				}
				else if (key == 80)
				{
					if (sel < TitleMenuCount - 1)
					{
						sel++;
					}
				}

				//画面クリア
				system("cls");
				//項目表示
				for (int i = 0; i < TitleMenuCount; i++)
				{
					if (sel == i)
					{
						printf("\033[33m");
						printf("->%s\n", item[i]);
						printf("\033[0m");
					}
					else
					{
						printf("  %s\n", item[i]);
					}
				}

				//Enterキーで決定
				if (key == 13)
				{
					//switch : 条件分岐の構文
					//大なり等の比較が入ったとき switchは使わない
					//かつ　＆＆　が入ったときも避ける

					//enum : 列挙体を作成するための構文
					//enum タグ名
					//{列挙定数,...}

					switch (sel)
					{
					case Start:

						break;

					case Option:
						printf("オプションです\n");
						break;

					case End:
						printf("ゲームを終了します\n");
						return 0;
					}
				}
			}
		}

	  case Game:
		  //項目表示
		  system("cls");  //コンソールキーの文字をすべて消す
		  for (int i = 0; i < TitleMenuCount; i++)
		  {
			  if (sel == i)
			  {
				  printf("\033[33m");		//色変更  \033[（色の指定）
				  printf("->%s\n", item[i]);
				  printf("\033[0m");
			  }
			  else
			  {
				  printf("  %s\n", item[i]);
			  }
		  }

		  while (1)
		  {
			  //Sleepで1msec待機
			  Sleep(1);

			  //キー入力がある場合
			  if (_kbhit())		//_kbhit　ボタンを押したことだけを判断する
			  {
				  //入力キーの取得
				  int key = _getch();

				  //上下キーで選択
				  if (key == 72)
				  {
					  if (sel > 0)
					  {
						  sel--;
					  }
				  }
				  else if (key == 80)
				  {
					  if (sel < TitleMenuCount - 1)
					  {
						  sel++;
					  }
				  }

				  //画面クリア
				  system("cls");
				  //項目表示
				  for (int i = 0; i < TitleMenuCount; i++)
				  {
					  if (sel == i)
					  {
						  printf("\033[33m");
						  printf("->%s\n", item[i]);
						  printf("\033[0m");
					  }
					  else
					  {
						  printf("  %s\n", item[i]);
					  }
				  }

				  //Enterキーで決定
				  if (key == 13)
				  {
					  //switch : 条件分岐の構文
					  //大なり等の比較が入ったとき switchは使わない
					  //かつ　＆＆　が入ったときも避ける

					  //enum : 列挙体を作成するための構文
					  //enum タグ名
					  //{列挙定数,...}

					  switch (sel)
					  {
					  case Start:

						  break;

					  case Option:
						  printf("オプションです\n");
						  break;

					  case End:
						  printf("ゲームを終了します\n");
						  return 0;
					  }
				  }
			  }
		  }


	}


	return 0;
}