#include "Calc.h"

Calc::Calc(int Num)
	:m_Num(Num)	// == m_Num = Num
  //,m_Num2		���₷�ꍇ�J���}
{
}

void Calc::Print()
{
  std::cout << "�v�Z����:" << m_Num << std::endl;
}

