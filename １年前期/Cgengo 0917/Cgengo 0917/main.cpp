#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//�|�C���^�^�̈������g���������Z�֐�
void CalcA(int a, int b, int* Add)
{
	*Add = a + b;
}

struct Result
{
	char Name[20];
	int Score;
	float Time;
};


void PrintResult(Result* re)
{
	//�\���̂̃|�C���^�̏ꍇ�� . �ł͂Ȃ�
	//-> �A���[���Z�q���g���Ē��̒l�ɃA�N�Z�X����
	printf("%s\n", re->Name);
	printf("%d\n", re->Score);
	printf("%f\n", re->Time);

}

int main()
{
	int id = 10;
	float fd = 20.5f;

	//�ϐ��̃A�h���X��ۑ�����
	//�|�C���^�^�ϐ�
	//�ۑ��������A�h���X�̑Ή������^�̌�� �� ������
	int* ip = &id;
	float* fp = &fd;

	printf("id�̒l:%d\n", id);
	printf("fd�̒l:%f\n", fd);
	printf("\n");

//�ϐ��̃A�h���X��m��ɂ͖��O�̑O�� & ������
	printf("id�̃A�h���X:%x\n", &id);
	printf("fd�̃A�h���X:%x\n", &fd);
	printf("\n");

	//�|�C���^�̒l�̕\��
	printf("ip�̃A�h���X:%x\n", ip);
	printf("fp�̃A�h���X:%x\n", fp);
	printf("\n");

	//�|�C���^�̎Q�Ɛ�̒l�̕\��
	//�|�C���^�̎Q�Ɛ�̒l�ɃA�N�Z�X���邽�߂ɂ�
	//�|�C���^�^�̕ϐ��̖��O�̑O�� * ������
	printf("ip�̒l:%d\n", *ip);
	printf("fp�l:%f\n", *fp);
	printf("\n");

	//�|�C���^�̎Q�Ɛ�ւ̑��
	*ip = 1000;
	printf("id�̒l:%d\n", id);
	printf("\n");


	return 0;
}