#include <iostream>

//std::map���g�����߂̃C���N���[�h
#include <map>

int main() {
	//std::map<�L�[�A�f�[�^>
	//�L�[:�f�[�^�̌����ȂǂɎg���l
	//�f�[�^:�ۑ����������f�[�^
	std::map<std::string, int>Data;

	//map�Ƀf�[�^��������
	//�z��̓Y�����ɓ�����ꏊ[]���L�[�̌^�Ŏw�肷��
	//�Y�����Ŏw�肵���i�K�łȂ���ΐV�����쐬�����
	Data["ABC"] = 10;
	Data["DEF"] = 20;

	//map�̃f�[�^��\������
	std::cout << Data["ABC"] << std::endl;

	//������
	//�Y�����Ŏw�肵���u�Ԃɍ���邽�߁A
	//������Ă��Ȃ��f�[�^�ŕ\���Ȃǂ��ł��Ă��܂�
	std::cout << Data["XYZ"] << std::endl;

	//map�Ńf�[�^������ꍇ�����\������
	//find�Ō�������
	auto it = Data.find("AAA");
	//�Ō�܂Ō�����Ȃ����end()�ƈ�v����
	if (it == Data.end())
	{
		std::cout << "����ȃf�[�^�͂���܂���" << std::endl;
	}
	//map�̑S�f�[�^��\������
	for (auto it = Data.begin(); it != Data.end(); ++it)
	{
		//it->first	 :map�̃L�[
		//it->second�Fmap�̃f�[�^

		std::cout << "key:" << it->first << "[" << it->second << "]" << std::endl;
	}

	return 0;
}