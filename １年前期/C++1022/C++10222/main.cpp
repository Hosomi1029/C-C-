#include <iostream>
#include <cstdio>
#include <iomanip>

int main()
{
	//C��printf���g���ꍇ
	std::printf("Hello World\n");

	int no = 100;

	std::cout << std::dec << no << std::endl;
	std::cout << std::hex << no << std::endl;

	float fd = 10.5f;
	std::cout << std::defaultfloat << fd << std::endl;
	std::cout << std::fixed << std::setprecision(2)
		<< fd << std::endl;

	std::string Name("�׌��@�D��");
	int Age = 18;

	std::cout << "���̖��O��" << Name << "��" << std::dec<<Age << "�΂ł�" << std::endl;

	std::cout << "Hello World"<<std::endl;

	int d;
	float f;
	std::string Myname;

	std::cout << "���������:";
	std::cin >> d;

	std::cout << "���������:";
	std::cin >> f;

	std::cout << "���O�����:";
	std::cin >> Myname;

	std::cout << std::dec << d << std::endl;
	std::cout << f << std::endl;
	std::cout<<  Myname << std::endl;

	//�E�ӂ̊֐��̎����w��
	//auto d = 10;
	auto f1 = 20.5;
	auto ff1 = 20.5f;

	int a[10];
	for (auto ap : a)
	{
	}

	//�����_���ɂ��ϐ��w��
	auto func = [](){};
	func();


	return 0;
}