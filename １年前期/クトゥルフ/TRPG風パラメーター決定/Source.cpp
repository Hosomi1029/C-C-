#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//�����̎�����Ԃŏ�����
	srand(time(NULL));

	//�p�����[�^�[�̐������J��Ԃ�
	for (int pcnt = 0; pcnt < 8; pcnt++)
	{
		//���v��ۑ����邽�߂̕ϐ����쐬
		int Sum = 0;

		//�_�C�X���~�鐔
		int dice = 3;
		//6�ڂƂV�ڂ�������ς���
		if (pcnt == 5 || pcnt == 6)
		{
			dice = 2;
			Sum = 6;
		}
		//8�ڂ͍ŏ�����{�R
		else if (pcnt == 7)
		{
			Sum = 3;
		}
		//�J��Ԃ�(for)
		// for( �J��Ԃ��̍ŏ��ɂ�肽������ ;
		//		�J��Ԃ��𑱂������ ;
		//		�J��Ԃ����Ƃɂ�肽������ )
		//		{ �J��Ԃ��������� }
		for (int Count = 0; Count < dice; Count++)
		{
			//�����������̌��蕔��
			//�P�`�U�̃����_���Ȑ�����Num�ɑ��
			int Num = 1 + rand() % 6;

			//��������̖ڂ𑫂�
			Sum += Num;

			//�_�C�X�̖ڂ�\������
			printf("%d��ڂ̃_�C�X��%d�ł�\n",
				Count + 1, Num);
		}
		//���v��\��
		printf("�p�����[�^�[��%d�ł�\n\n", Sum);
	}

	//�J��Ԃ�(while)
	// while( �J��Ԃ��𑱂������ )
	//		{ �J��Ԃ��������� }
	//int Count = 0;
	//while (Count < 3)
	//{
	//	Count++;
	//}
	return 0;
}