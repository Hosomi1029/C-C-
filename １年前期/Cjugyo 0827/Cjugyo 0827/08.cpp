/*
 * ���̃v���O�����̓Q�[���̃��j���[��ʂł�
 * �i�P�j�`�i4�j�̊e�ݖ�ɑΉ������v���O�������쐬���Ȃ���
 *
 * �i�P�jEnter�L�[�������ă��j���[�����肵���ۂ�
 *		switch�����g�p���đI��ł��郁�j���[�ɉ����āA
 *		�u�n�߂�v�Ɓu�I�v�V�����v��I�������ꍇ��printf�Ń��b�Z�[�W��\���A
 *		�u�I���v��I�������ꍇ�̓A�v�����I������悤�ɍ쐬���Ȃ���
 *
 *
 * �i�Q�jswitch����case������enum�̒萔���g�p����悤�ɏ�����ύX���Ȃ����B
 *
 *
 * �i�R�j�u�n�߂�v��I�������肵���ꍇ�͌���̃��j���[�Ɠ��l�̏�����
 *		�X�e�[�W�P�`�S�Ɓu���j���[�ɖ߂�v��I���őI�ׂ�悤�ɏ������쐬���A
 *		�X�e�[�W�P�`�S�����肵���ꍇ�͌��肵���X�e�[�W�ԍ���printf�ŕ\���A
 *		�u���j���[�ɖ߂�v�����肵���ꍇ�͌��̃��j���[�ɖ߂�悤�ɏ������쐬���Ȃ����B
 *
 *
 * �i�S�jGame�֐���Option�֐����쐬���AGame�֐����ł́i�R�j�̏��������s����
 *		�u�n�߂�v�u�I�v�V�����v�����肵���ꍇ�A
 *		���ꂼ��̊֐������s����悤�Ƀv���O������ύX���Ȃ����B
 */
#include	<stdio.h>
#include	<conio.h>			//_kbhit�A_getch���g�����߂ɒǉ�
#include	<windows.h>			//system�ASleep���g�����߂ɒǉ�

enum item {
	Start,
	Option,
	End,
	TitleMenuCount
};

enum Stage {
	Sta1,
	Sta2,
	Sta3,
	Sta4,
	Menu,
	StaCount
};

enum Seane {
	Title,
	Game
};

int main(void) {
	//�I��
	int sel = 0;
	int Routine = Title;

	//�I������
	const char* item[] = {
		"�n�߂�",
		"�I�v�V����",
		"�I���",
	};

	const char* Stage[] =
	{
		"�X�e�[�W 1",
		"�X�e�[�W 2",
		"�X�e�[�W 3",
		"�X�e�[�W 4",
		"���j���[�ɖ߂�"
	};

	switch (Routine)
	{
	  case Title:
		//���ڕ\��
		system("cls");  //�R���\�[���L�[�̕��������ׂď���
		for (int i = 0; i < TitleMenuCount; i++)
		{
			if (sel == i)
			{
				printf("\033[33m");		//�F�ύX  \033[�i�F�̎w��j
				printf("->%s\n", item[i]);
				printf("\033[0m");
			}
			else
			{
				printf("  %s\n", item[i]);
			}
		}

		while (1)
		{
			//Sleep��1msec�ҋ@
			Sleep(1);

			//�L�[���͂�����ꍇ
			if (_kbhit())		//_kbhit�@�{�^�������������Ƃ����𔻒f����
			{
				//���̓L�[�̎擾
				int key = _getch();

				//�㉺�L�[�őI��
				if (key == 72)
				{
					if (sel > 0)
					{
						sel--;
					}
				}
				else if (key == 80)
				{
					if (sel < TitleMenuCount - 1)
					{
						sel++;
					}
				}

				//��ʃN���A
				system("cls");
				//���ڕ\��
				for (int i = 0; i < TitleMenuCount; i++)
				{
					if (sel == i)
					{
						printf("\033[33m");
						printf("->%s\n", item[i]);
						printf("\033[0m");
					}
					else
					{
						printf("  %s\n", item[i]);
					}
				}

				//Enter�L�[�Ō���
				if (key == 13)
				{
					//switch : ��������̍\��
					//��Ȃ蓙�̔�r���������Ƃ� switch�͎g��Ȃ�
					//���@�����@���������Ƃ���������

					//enum : �񋓑̂��쐬���邽�߂̍\��
					//enum �^�O��
					//{�񋓒萔,...}

					switch (sel)
					{
					case Start:

						break;

					case Option:
						printf("�I�v�V�����ł�\n");
						break;

					case End:
						printf("�Q�[�����I�����܂�\n");
						return 0;
					}
				}
			}
		}

	  case Game:
		  //���ڕ\��
		  system("cls");  //�R���\�[���L�[�̕��������ׂď���
		  for (int i = 0; i < TitleMenuCount; i++)
		  {
			  if (sel == i)
			  {
				  printf("\033[33m");		//�F�ύX  \033[�i�F�̎w��j
				  printf("->%s\n", item[i]);
				  printf("\033[0m");
			  }
			  else
			  {
				  printf("  %s\n", item[i]);
			  }
		  }

		  while (1)
		  {
			  //Sleep��1msec�ҋ@
			  Sleep(1);

			  //�L�[���͂�����ꍇ
			  if (_kbhit())		//_kbhit�@�{�^�������������Ƃ����𔻒f����
			  {
				  //���̓L�[�̎擾
				  int key = _getch();

				  //�㉺�L�[�őI��
				  if (key == 72)
				  {
					  if (sel > 0)
					  {
						  sel--;
					  }
				  }
				  else if (key == 80)
				  {
					  if (sel < TitleMenuCount - 1)
					  {
						  sel++;
					  }
				  }

				  //��ʃN���A
				  system("cls");
				  //���ڕ\��
				  for (int i = 0; i < TitleMenuCount; i++)
				  {
					  if (sel == i)
					  {
						  printf("\033[33m");
						  printf("->%s\n", item[i]);
						  printf("\033[0m");
					  }
					  else
					  {
						  printf("  %s\n", item[i]);
					  }
				  }

				  //Enter�L�[�Ō���
				  if (key == 13)
				  {
					  //switch : ��������̍\��
					  //��Ȃ蓙�̔�r���������Ƃ� switch�͎g��Ȃ�
					  //���@�����@���������Ƃ���������

					  //enum : �񋓑̂��쐬���邽�߂̍\��
					  //enum �^�O��
					  //{�񋓒萔,...}

					  switch (sel)
					  {
					  case Start:

						  break;

					  case Option:
						  printf("�I�v�V�����ł�\n");
						  break;

					  case End:
						  printf("�Q�[�����I�����܂�\n");
						  return 0;
					  }
				  }
			  }
		  }


	}


	return 0;
}