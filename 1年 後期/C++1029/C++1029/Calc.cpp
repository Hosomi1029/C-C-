#include "Calc.h"

Calc::Calc(int Num)
	:m_Num(Num)	// == m_Num = Num
  //,m_Num2		‘‚â‚·ê‡ƒJƒ“ƒ}
{
}

void Calc::Print()
{
  std::cout << "ŒvZŒ‹‰Ê:" << m_Num << std::endl;
}

