#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//ポインタ型の引数を使った足し算関数
void CalcA(int a, int b, int* Add)
{
	*Add = a + b;
}

struct Result
{
	char Name[20];
	int Score;
	float Time;
};


void PrintResult(Result* re)
{
	//構造体のポインタの場合は . ではなく
	//-> アロー演算子を使って中の値にアクセスする
	printf("%s\n", re->Name);
	printf("%d\n", re->Score);
	printf("%f\n", re->Time);

}

int main()
{
	int id = 10;
	float fd = 20.5f;

	//変数のアドレスを保存する
	//ポインタ型変数
	//保存したいアドレスの対応した型の後に ＊ をつける
	int* ip = &id;
	float* fp = &fd;

	printf("idの値:%d\n", id);
	printf("fdの値:%f\n", fd);
	printf("\n");

//変数のアドレスを知るには名前の前に & をつける
	printf("idのアドレス:%x\n", &id);
	printf("fdのアドレス:%x\n", &fd);
	printf("\n");

	//ポインタの値の表示
	printf("ipのアドレス:%x\n", ip);
	printf("fpのアドレス:%x\n", fp);
	printf("\n");

	//ポインタの参照先の値の表示
	//ポインタの参照先の値にアクセスするためには
	//ポインタ型の変数の名前の前に * をつける
	printf("ipの値:%d\n", *ip);
	printf("fp値:%f\n", *fp);
	printf("\n");

	//ポインタの参照先への代入
	*ip = 1000;
	printf("idの値:%d\n", id);
	printf("\n");


	return 0;
}