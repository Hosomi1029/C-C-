#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//行・列の数
#define COUNT		10
//全部のマスの数
#define	ALL			(COUNT * COUNT)

int main ( )
{
	//爆弾の数
	int bombs = 10;

	// ステージデータ用配列。
	// -1なら爆弾、それ以外の数なら周囲8マスにある爆弾の数
	int map[COUNT][COUNT] = {0};

	// 開いたかどうかを保持する配列
	int map_open[COUNT][COUNT] = {0};

	// 終了フラグ
	int endflag = 0;

	// ランダムに爆弾配置
	// 乱数の種を現在時刻に設定
	srand((unsigned)time(NULL));
	for ( int i = 0; i < bombs; i++ )
	{
		while(1)
		{
			// 乱数を２つ取得
			int c = rand() % COUNT;
			int r = rand() % COUNT;

			// すでに設置済みの場所でないか確認
			if ( map[r][c] == 0 )
			{
				// 設置していない場所なので、爆弾配置
				map[r][c] = -1;
				break;
			}
		}
	}

	// マップの爆弾の数をマスに入れる
	for ( int r = 0; r < COUNT; r++ )
	{
		for ( int c = 0; c < COUNT; c++ )
		{
			// そのマスが爆弾だった時は、周囲のマスに爆弾の数１を増やす
			if ( map[r][c] == -1 )
			{
				// 周囲の３×３のマスを調べる
				for ( int y = -1; y <= 1; y++ )
				{
					for ( int x= -1; x <= 1; x++ )
					{
						// 配列の範囲内かチェック
						if ( c + x >= 0 && c + x < COUNT && r + y >= 0 && r + y < COUNT )
						{
							// 加算対象のマス自体が爆弾でなければ1加算する
							if( map[r + y][c + x] != -1)
							{
								map[r + y][c + x]++;
							}
						}
					}
				}
			}
		}
	}


	// ゲームループ
	while( 1 )
	{
		// 上枠出力
		printf("   ┏");
		for ( int c = 0; c < COUNT; c++ )
		{
			printf("━━");
			if( c != COUNT - 1 )
			{
				printf("┳");
			}
		}
		printf("┓\n");
		printf("┏━━┫");
		for ( int c = 0; c < COUNT; c++ )
		{
			printf("%2d┃",c);
		}
		printf("\n");		

		// 1行ずつ出力
		for ( int r = 0; r < COUNT; r++ )
		{
			// 左枠部分
			printf("┣━━╋");
			for ( int c = 0; c < COUNT; c++ )
			{
				printf("━━");
				if( c != COUNT-1 )
				{
					printf("╋");
				}
			}
			printf("┫\n");
			printf("┃%2d┃",r);

			// 各マス部分
			for ( int c = 0; c < COUNT; c++ )
			{
				// ゲームが終了しているときは爆弾の位置を出す
				if ( endflag != 0 && map[r][c] == -1 )
				{
					printf("※");
				}
				// 開いていないところは■
				else if ( map_open[r][c] == 0 )
				{
					printf("■");
				}
				// 開いていて爆弾と関係ない場所は空白
				else if( map[r][c] == 0 )
				{
					printf("  ");
				}
				// 周囲に爆弾がある場合、その個数を出す
				else
				{
					printf("%2d",map[r][c]);
				}
				printf("┃");
			}
			printf("\n");
		}

		// 下枠
		printf("┗━━┻");
		for ( int c = 0; c < COUNT; c++ )
		{
			printf("━━");
			if( c != COUNT - 1 )
			{
				printf("┻");
			}
		}
		printf("┛\n");

		// 終了判定
		if ( endflag != 0 )
		{
			break;
		}
		
		// 入力ループ
		while(1)
		{
			// 開ける場所の入力
			printf("行,列：");
			int r = 0;
			int c = 0;
			int res = scanf("%d,%d",&r,&c);

			// 入力された値が1つだけのとき
			if ( res == 1 )
			{
				// 入力された値が終了コード(-1)だったとき
				if ( r == -1 )
				{
					endflag = 1;
					break;
				}
			}
			// 正しく入っていないとき
			if ( res != 2 )
			{
				// 入力バッファをクリア
				scanf("%*s");
				scanf("%*s");
				continue;
			}
			if (r < 0 || r >= COUNT || c < 0 || r >= COUNT)
			{
				printf("範囲内の数字を指定してください。\n");
				continue;
			}

			// すでにオープンされた場所だったとき
			if ( map_open[r][c] == 1 )
			{
				printf("すでにオープンされています。\n");
				continue;
			}

			// 爆弾の場所を開いたらゲームオーバー
			if ( map[r][c] == -1 )
			{
				printf("Game Over!\n");
				endflag = 1;
				break;
			}

			// 爆弾と関係ない場所だった場合
			if ( map[r][c] == 0 )
			{
				// 疑似再起処理用スタック
				int stack[ALL * 2][2] = { 0 };
				// スタックに現在の行・列を記録しておく
				int pt = 0;
				stack[pt][0] = c;
				stack[pt][1] = r;
				pt++;

				// スタックがある間繰り返す（疑似再起処理。再起関数が使える場合、そちらのほうが簡潔に書ける）
				while ( pt > 0 )
				{
					// スタックから1つ取り出す
					pt--;
					int x = stack[pt][0];
					int y = stack[pt][1];

					// 取り出した場所をまだ開いてなければ開く
					if ( map_open[y][x] == 0 )
					{
						map_open[y][x] = 1;
						// 爆弾と関係ない場合周囲を開く
						if (map[y][x] == 0)
						{
							// 周囲の３×３のマスを調べる
							for (int ty = -1; ty <= 1; ty++)
							{
								for (int tx = -1; tx <= 1; tx++)
								{
									if (x + tx >= 0 && x + tx < COUNT &&
										y + ty >= 0 && y + ty < COUNT &&
										map_open[y + ty][x + tx] == 0)
									{
										stack[pt][0] = x + tx;
										stack[pt][1] = y + ty;
										pt++;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				map_open[r][c] = 1;
			}
			break;
		}

		//開いたマスの数をカウント
		int ocnt = 0;
		for ( int r = 0; r < COUNT; r++ )
		{
			for ( int c = 0; c < COUNT; c++ )
			{
				if ( map_open[r][c] == 1 )
				{
					ocnt++;
				}
			}
		}
		//（総マス数 - 開いたマス数 - 爆弾数）が0ならクリア
		if ( (ALL - ocnt) - bombs == 0 )
		{
			endflag = 1;
			printf("clear!!!\n");
			continue;
		}
		printf("残り、%d\n", (ALL - ocnt) - bombs);
	}
	//入力バッファをクリア
	scanf("%*s");

	return 0;
}