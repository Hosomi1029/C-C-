#pragma once
#include<iostream>

class Calc
{
private:
	/// <summary>
	/// 電卓の計算している数字
	/// </summary>
	int m_Num;

public:
	/// <summary>
	///	intの引数を1つ受け取る
	/// </summary>
	/// <param name="Num"></param>
	Calc(int Num);

	//デストラクタは標準動作
	~Calc() = default;
	/// <summary>
	/// Numをコンソールに表示する関数
	/// </summary>
	void Print();

};

