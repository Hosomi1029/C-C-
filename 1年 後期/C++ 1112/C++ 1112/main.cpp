#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"function.h"

int main()
{
	//auto :�^���_
	//�E���̉��̌^�Ɏ����Őݒ肵�Ă����
	auto v = Add(10, 20.5);
	std::cout << v << std::endl;

	//�N���X�e���v���[�g�̃C���X�^���X�쐬
	Calc<int> c(10);
	Calc<double> cd(20.5);

	const char* Name = "�z�\�~";
	const char* name = "���E��";
	auto n = Add(Name, name);
	std::cout << n << std::endl;

	std::cout << Add(10.5, 20.3) << std::endl;			//�ÖٓI

	std::cout << Add<double>(10, 20.3) << std::endl;	//�����I

	return 0;
}