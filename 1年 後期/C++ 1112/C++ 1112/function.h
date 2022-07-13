#pragma once
#include <iostream>

//足し算を行うテンプレート関数
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

//二つの型の違う足し算を行うテンプレート関数
//decltype :　型を式から決めてくれる
template<typename T1, typename T2>
auto Add(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}

//足し算の関数の特殊化
//const char* （文字列）の場合
//新規でメモリを確保して文字列を連結して返す
template< >
 const char* Add<const char*>(const char* a, const char* b)
{
	 char* re = new char[strlen(a) + strlen(b) + 1];
	 strcpy(re, a);
	 strcat(re, b);
	 return re;
}



//クラスのテンプレート
template<typename T>
class Calc {
private:
	//クラステンプレートで指定したテンプレート仮引数は
	//クラス内であれば
	T	Num;
public:
	Calc(T n)
	:Num(n) {
	}

	void Printf() {
		std::cout << Num << std::endl;
	}
};
