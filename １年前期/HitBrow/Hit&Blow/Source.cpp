#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	//�����̎�����Ԃŏ�����
	srand(time(NULL));
	//�����������̌��蕔��
	//�P�`�U�̃����_���Ȑ�����Num�ɑ��
	int Num = 1 + rand() % 6;
	
	//�����̌���
	constexpr int anscnt = 3;

	//�z��ŉ𓚗p�̕ϐ���p�ӂ���
	// �^ ���O [ �p�ӂ�������(�v�f��) ] = 
	// { ��ڂ̗v�f�̒l, ��ڂ̗v�f�̒l, ... }
	int ans[anscnt];// = { rand() % 10,rand() % 10,rand() % 10 };

	//�z��Ƀ����_���Ȑ�����������
	printf("Answer : ");
	for (int no = 0; no < anscnt; no++)
	{
		//�z��̕ϐ��̗��p
		// ���O [ �g�������v�f�̔ԍ� ];
		ans[no] = rand() % 10;
		printf("%d,", ans[no]);
	}
	printf("\n");

	//10��J��Ԃ��V��
	for (int playcnt = 0; playcnt < 10; playcnt++)
	{
		//�Q�[���񐔂̕\��
		printf("%d��ڂ̉�\n", playcnt);

		//���͗p�̕ϐ���z��ō쐬
		int inp[anscnt];

		//�z��ɐ�������͂�����
		printf("Input : \n");
		for (int no = 0; no < anscnt; no++)
		{
			//scanf�ɂ����
			scanf("%d", &inp[no]);
		}
		//���͂��ꂽ�����̕\��
		printf("Input : ");
		for (int no = 0; no < anscnt; no++)
		{
			printf("%d,", inp[no]);
		}
		printf("\n");

		//��������ł̔��f
		int Hit = 0;
		int Blow = 0;
		for (int ano = 0; ano < anscnt; ano++)
		{
			for (int ino = 0; ino < anscnt; ino++)
			{
				//�𓚂Ɠ��͂̒l�̔�r
				if (ans[ano] == inp[ino])
				{
					//�ꏊ����v�����Hit
					if (ano == ino)
					{
						Hit++;
					}
					//�Ⴆ��Blow
					else
					{
						Blow++;
					}
				}
			}
		}
		//���ʂ̕\��
		printf("Hit : %d, Blow : %d\n", Hit, Blow);

		//Hit�̐����𓚂̐��ƈ�v�����琳��
		if (Hit == anscnt)
		{
			printf("����!!\n");
			break;
		}
	}
	return 0;
}
