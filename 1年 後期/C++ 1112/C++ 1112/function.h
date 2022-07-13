#pragma once
#include <iostream>

//�����Z���s���e���v���[�g�֐�
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

//��̌^�̈Ⴄ�����Z���s���e���v���[�g�֐�
//decltype :�@�^�������猈�߂Ă����
template<typename T1, typename T2>
auto Add(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}

//�����Z�̊֐��̓��ꉻ
//const char* �i������j�̏ꍇ
//�V�K�Ń��������m�ۂ��ĕ������A�����ĕԂ�
template< >
 const char* Add<const char*>(const char* a, const char* b)
{
	 char* re = new char[strlen(a) + strlen(b) + 1];
	 strcpy(re, a);
	 strcat(re, b);
	 return re;
}



//�N���X�̃e���v���[�g
template<typename T>
class Calc {
private:
	//�N���X�e���v���[�g�Ŏw�肵���e���v���[�g��������
	//�N���X���ł����
	T	Num;
public:
	Calc(T n)
	:Num(n) {
	}

	void Printf() {
		std::cout << Num << std::endl;
	}
};
