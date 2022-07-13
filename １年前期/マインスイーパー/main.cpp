#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�s�E��̐�
#define COUNT		10
//�S���̃}�X�̐�
#define	ALL			(COUNT * COUNT)

int main ( )
{
	//���e�̐�
	int bombs = 10;

	// �X�e�[�W�f�[�^�p�z��B
	// -1�Ȃ甚�e�A����ȊO�̐��Ȃ����8�}�X�ɂ��锚�e�̐�
	int map[COUNT][COUNT] = {0};

	// �J�������ǂ�����ێ�����z��
	int map_open[COUNT][COUNT] = {0};

	// �I���t���O
	int endflag = 0;

	// �����_���ɔ��e�z�u
	// �����̎�����ݎ����ɐݒ�
	srand((unsigned)time(NULL));
	for ( int i = 0; i < bombs; i++ )
	{
		while(1)
		{
			// �������Q�擾
			int c = rand() % COUNT;
			int r = rand() % COUNT;

			// ���łɐݒu�ς݂̏ꏊ�łȂ����m�F
			if ( map[r][c] == 0 )
			{
				// �ݒu���Ă��Ȃ��ꏊ�Ȃ̂ŁA���e�z�u
				map[r][c] = -1;
				break;
			}
		}
	}

	// �}�b�v�̔��e�̐����}�X�ɓ����
	for ( int r = 0; r < COUNT; r++ )
	{
		for ( int c = 0; c < COUNT; c++ )
		{
			// ���̃}�X�����e���������́A���͂̃}�X�ɔ��e�̐��P�𑝂₷
			if ( map[r][c] == -1 )
			{
				// ���͂̂R�~�R�̃}�X�𒲂ׂ�
				for ( int y = -1; y <= 1; y++ )
				{
					for ( int x= -1; x <= 1; x++ )
					{
						// �z��͈͓̔����`�F�b�N
						if ( c + x >= 0 && c + x < COUNT && r + y >= 0 && r + y < COUNT )
						{
							// ���Z�Ώۂ̃}�X���̂����e�łȂ����1���Z����
							if( map[r + y][c + x] != -1)
							{
								map[r + y][c + x]++;
							}
						}
					}
				}
			}
		}
	}


	// �Q�[�����[�v
	while( 1 )
	{
		// ��g�o��
		printf("   ��");
		for ( int c = 0; c < COUNT; c++ )
		{
			printf("����");
			if( c != COUNT - 1 )
			{
				printf("��");
			}
		}
		printf("��\n");
		printf("��������");
		for ( int c = 0; c < COUNT; c++ )
		{
			printf("%2d��",c);
		}
		printf("\n");		

		// 1�s���o��
		for ( int r = 0; r < COUNT; r++ )
		{
			// ���g����
			printf("��������");
			for ( int c = 0; c < COUNT; c++ )
			{
				printf("����");
				if( c != COUNT-1 )
				{
					printf("��");
				}
			}
			printf("��\n");
			printf("��%2d��",r);

			// �e�}�X����
			for ( int c = 0; c < COUNT; c++ )
			{
				// �Q�[�����I�����Ă���Ƃ��͔��e�̈ʒu���o��
				if ( endflag != 0 && map[r][c] == -1 )
				{
					printf("��");
				}
				// �J���Ă��Ȃ��Ƃ���́�
				else if ( map_open[r][c] == 0 )
				{
					printf("��");
				}
				// �J���Ă��Ĕ��e�Ɗ֌W�Ȃ��ꏊ�͋�
				else if( map[r][c] == 0 )
				{
					printf("  ");
				}
				// ���͂ɔ��e������ꍇ�A���̌����o��
				else
				{
					printf("%2d",map[r][c]);
				}
				printf("��");
			}
			printf("\n");
		}

		// ���g
		printf("��������");
		for ( int c = 0; c < COUNT; c++ )
		{
			printf("����");
			if( c != COUNT - 1 )
			{
				printf("��");
			}
		}
		printf("��\n");

		// �I������
		if ( endflag != 0 )
		{
			break;
		}
		
		// ���̓��[�v
		while(1)
		{
			// �J����ꏊ�̓���
			printf("�s,��F");
			int r = 0;
			int c = 0;
			int res = scanf("%d,%d",&r,&c);

			// ���͂��ꂽ�l��1�����̂Ƃ�
			if ( res == 1 )
			{
				// ���͂��ꂽ�l���I���R�[�h(-1)�������Ƃ�
				if ( r == -1 )
				{
					endflag = 1;
					break;
				}
			}
			// �����������Ă��Ȃ��Ƃ�
			if ( res != 2 )
			{
				// ���̓o�b�t�@���N���A
				scanf("%*s");
				scanf("%*s");
				continue;
			}
			if (r < 0 || r >= COUNT || c < 0 || r >= COUNT)
			{
				printf("�͈͓��̐������w�肵�Ă��������B\n");
				continue;
			}

			// ���łɃI�[�v�����ꂽ�ꏊ�������Ƃ�
			if ( map_open[r][c] == 1 )
			{
				printf("���łɃI�[�v������Ă��܂��B\n");
				continue;
			}

			// ���e�̏ꏊ���J������Q�[���I�[�o�[
			if ( map[r][c] == -1 )
			{
				printf("Game Over!\n");
				endflag = 1;
				break;
			}

			// ���e�Ɗ֌W�Ȃ��ꏊ�������ꍇ
			if ( map[r][c] == 0 )
			{
				// �^���ċN�����p�X�^�b�N
				int stack[ALL * 2][2] = { 0 };
				// �X�^�b�N�Ɍ��݂̍s�E����L�^���Ă���
				int pt = 0;
				stack[pt][0] = c;
				stack[pt][1] = r;
				pt++;

				// �X�^�b�N������ԌJ��Ԃ��i�^���ċN�����B�ċN�֐����g����ꍇ�A������̂ق����Ȍ��ɏ�����j
				while ( pt > 0 )
				{
					// �X�^�b�N����1���o��
					pt--;
					int x = stack[pt][0];
					int y = stack[pt][1];

					// ���o�����ꏊ���܂��J���ĂȂ���ΊJ��
					if ( map_open[y][x] == 0 )
					{
						map_open[y][x] = 1;
						// ���e�Ɗ֌W�Ȃ��ꍇ���͂��J��
						if (map[y][x] == 0)
						{
							// ���͂̂R�~�R�̃}�X�𒲂ׂ�
							for (int ty = -1; ty <= 1; ty++)
							{
								for (int tx = -1; tx <= 1; tx++)
								{
									if (x + tx >= 0 && x + tx < COUNT &&
										y + ty >= 0 && y + ty < COUNT &&
										map_open[y + ty][x + tx] == 0)
									{
										stack[pt][0] = x + tx;
										stack[pt][1] = y + ty;
										pt++;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				map_open[r][c] = 1;
			}
			break;
		}

		//�J�����}�X�̐����J�E���g
		int ocnt = 0;
		for ( int r = 0; r < COUNT; r++ )
		{
			for ( int c = 0; c < COUNT; c++ )
			{
				if ( map_open[r][c] == 1 )
				{
					ocnt++;
				}
			}
		}
		//�i���}�X�� - �J�����}�X�� - ���e���j��0�Ȃ�N���A
		if ( (ALL - ocnt) - bombs == 0 )
		{
			endflag = 1;
			printf("clear!!!\n");
			continue;
		}
		printf("�c��A%d\n", (ALL - ocnt) - bombs);
	}
	//���̓o�b�t�@���N���A
	scanf("%*s");

	return 0;
}