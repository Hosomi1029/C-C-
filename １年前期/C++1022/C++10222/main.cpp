#include <iostream>
#include <cstdio>
#include <iomanip>

int main()
{
	//Cのprintfを使う場合
	std::printf("Hello World\n");

	int no = 100;

	std::cout << std::dec << no << std::endl;
	std::cout << std::hex << no << std::endl;

	float fd = 10.5f;
	std::cout << std::defaultfloat << fd << std::endl;
	std::cout << std::fixed << std::setprecision(2)
		<< fd << std::endl;

	std::string Name("細見　優弥");
	int Age = 18;

	std::cout << "私の名前は" << Name << "で" << std::dec<<Age << "歳です" << std::endl;

	std::cout << "Hello World"<<std::endl;

	int d;
	float f;
	std::string Myname;

	std::cout << "整数を入力:";
	std::cin >> d;

	std::cout << "少数を入力:";
	std::cin >> f;

	std::cout << "名前を入力:";
	std::cin >> Myname;

	std::cout << std::dec << d << std::endl;
	std::cout << f << std::endl;
	std::cout<<  Myname << std::endl;

	//右辺の関数の自動指定
	//auto d = 10;
	auto f1 = 20.5;
	auto ff1 = 20.5f;

	int a[10];
	for (auto ap : a)
	{
	}

	//ラムダ式による変数指定
	auto func = [](){};
	func();


	return 0;
}