#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//�����̎�����Ԃŏ�����
	srand(time(NULL));

	int Sum = 0;

	/*for(�J��Ԃ��̍ŏ��ɂ�肽������;
		  �J��Ԃ��𑱂������;
		  �J��Ԃ����тɂ�肽������)
		  �o�J��Ԃ������p
	*/
	for (int Ct = 1; Ct < 6; Ct++)
	{
		printf("%d�ڂ̃p�����[�^�[\n", Ct);

		for (int Count = 1; Count < 4; Count++)
		{

			//�����������̌��蕔��
			//1�`�U�̃����_���Ȑ�����Num�ɑ��
			int Num = 1 + rand() % 6;


			printf("%d��ڂ̃_�C�X�̖ڂ�%d�ł�\n", Count, Num);

			Sum += Num;


		}

		printf("�p�����[�^�[�̒l��%d�ł�\n\n", Sum);

	}
	return 0;
}