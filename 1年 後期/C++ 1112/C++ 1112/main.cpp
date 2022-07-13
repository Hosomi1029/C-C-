#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"function.h"

int main()
{
	//auto :型推論
	//右側の価の型に自動で設定してくれる
	auto v = Add(10, 20.5);
	std::cout << v << std::endl;

	//クラステンプレートのインスタンス作成
	Calc<int> c(10);
	Calc<double> cd(20.5);

	const char* Name = "ホソミ";
	const char* name = "ユウヤ";
	auto n = Add(Name, name);
	std::cout << n << std::endl;

	std::cout << Add(10.5, 20.3) << std::endl;			//暗黙的

	std::cout << Add<double>(10, 20.3) << std::endl;	//明示的

	return 0;
}