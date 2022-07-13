/*
 * ���̃v���O�����̓Q�[���̐퓬��ʂł�
 * �i�P�j�`�i�U�j�̊e�ݖ�ɑΉ������v���O�������쐬���Ȃ���
 *
 * �i�P�j�X�e�[�^�X�\���̃v���O�������ɂR�x�ق�
 *       ���L�̃��C���������v���O�������L�q���Ă���
 *
 *			printf("|");
 *			for (int i = 0; i < FRAMEWIDTH; i++)
 *			{
 *					printf("-");
 *			}
 *			printf("|");
 *
 *		���C��������������Line�֐��Ƃ��Ċ֐��ɂ��Ȃ���
 *
 *
 * �i�Q�j���݂̃��C�������������� "-" �̐���FRAMEWIDTH�ɂȂ��Ă���
 *		Line�֐��Ɉ�����ǉ����A�����Ɏw�肵�������� "-" �ŁA
 *		���C���������悤�Ƀv���O������ύX���Ȃ����B
 *
 *
 * �i�R�j���L�̃v���O�����Ō��݂̃J�[�\���ʒu��ύX���A
 *		�w�肵���ʒu�ɕ�����}�����邱�Ƃ��ł���
 *
 *			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
 *			COORD pos = { �\��������X�ʒu, �\��������Y�ʒu };
 *			SetConsoleCursorPosition(hStdout, pos);
 *
 *		x,y�̈ʒu�������Ƃ��Ď󂯎��A�w�肳�ꂽ�ʒu�ɕ�����ǉ��ł���悤�ɂ���A
 *		SetCursorPosition�֐����쐬���Ȃ����B
 *
 *
 * �i�S�j�X�e�[�^�X�̕\����ShowStatus�֐��Ƃ��āA
 *		�����ɕ\��������Unit�A�\��������X�ʒu�A�\��������Y�ʒu���󂯎��A
 *		���̈ʒu�ɃX�e�[�^�X��\������֐��ɂ��Ȃ����B
 *
 *
 * �i�T�jUnit�^�̔z��ŉ��L�̕ϐ���ǉ����A
 *		ShowStatus�֐����g�p���ĕ\�����Ȃ���
 *		Unit Enemy[3] = {
 *		 	{ "�G�P", 50, 15, 10 },
 *		 	{ "�G�Q", 50, 15, 10 },
 *		 	{ "�G�R", 50, 15, 10 },
 *		};
 *
 *
 * �i�U�j08.cpp�̃��j���[�������g���A�h���N�G���̐퓬�����������Ȃ����B
 */
#include	<stdio.h>
#include	<conio.h>			//_kbhit�A_getch���g�����߂ɒǉ�
#include	<windows.h>			//system�ASleep���g�����߂ɒǉ�

 //�g�̕�
#define			FRAMEWIDTH		16

 //�L�����N�^�[�̃X�e�[�^�X
struct Unit {
	char Name[32];
	int HP;
	int STR;
	int DEF;
};

void Line(int w)
{
	printf("|");
	for (int i = 0; i < w; i++)
		{
		printf("-");
		
	}
	printf("|\n");
}

void SetCursorPosition(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hStdout, pos);
}


void ShowStatus(int x, int y, Unit un)
{
	SetCursorPosition(x, y);
	Line(FRAMEWIDTH);


	//���O���Z���^�����O�ŕ\��
	int slen = strlen(un.Name);
	int h = (FRAMEWIDTH - slen) / 2;

	SetCursorPosition(x, y + 1);
	printf("|%*s%*s|\n", slen + h, un.Name, h, "");

	//���O�ƃX�e�[�^�X�̊Ԃ̐��\��
	SetCursorPosition(x, y+2);
	Line(FRAMEWIDTH);

	//�X�e�[�^�X�̕\��
	SetCursorPosition(x, y+3);
	printf("|HP%14d|\n", un.HP);

	SetCursorPosition(x, y+4);
	printf("|STR%13d|\n", un.STR);
	
	SetCursorPosition(x, y+5);
	printf("|DEF%13d|\n", un.DEF);

	//���̐��\��
	SetCursorPosition(x, y + 6);
	Line(FRAMEWIDTH);

}

int main(void) {
	//�v���C���[�L�����N�^�[
	Unit Player = { "�v���C���[", 100, 20, 10 };
	ShowStatus(10, 50,  Player);
	return 0;
}