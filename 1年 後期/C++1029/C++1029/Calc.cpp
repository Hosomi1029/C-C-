#include "Calc.h"

Calc::Calc(int Num)
	:m_Num(Num)	// == m_Num = Num
  //,m_Num2		増やす場合カンマ
{
}

void Calc::Print()
{
  std::cout << "計算結果:" << m_Num << std::endl;
}

