#include<iostream>

/*
* �Q�[���̃L�����N�^�[�N���X
*/

class Character {
private:
	int		PosX;
	int		PosY;
public:
	void Move(int x, int y)
	{

	}

	void SetPosX(int x) {
		PosX = x;
	}

	int GetPosY()
	{
		return PosX;
	}
};

/*
* �Q�[���̓G�N���X
* �p����Character�������p��
*/
class Enemy :public Character {
private:
public:
	/*
	* �p������ꍇ�̓f�X�g���N�^��virtual������
	*/
	virtual ~Enemy(){}
	
	/*
	* �G�̓���֐�
	* ���l���̎����ivirtual������j
	* ���z�֐��A�p����œ�����㏑���ł���
	*/
	/*
	* �������z�֐��A���z�֐��̒�`���������Ɂ@=0
	*/

	virtual void Update() = 0;

};

/*
* �N���{�[�N���X
* �p����Enemy�������p��
*/
class Kuribo :public Enemy {
private:
public:
	/*
	* �N���{�[�̓���֐�
	* ���z�֐����㏑��(override)���Ă���Ƃ����ڈ�
	*/

	void Update() override{
		std::cout << "�N���{�[�I�I" << std::endl;
	}

};

/*
* �m�R�m�R�N���X
* �p����Enemy�������p��
*/
class Nokonoko :public Enemy {
private:
public:

	/*
	* �G�̓���֐�
	*/

	void Update() override{
		std::cout << "�m�R�m�R�I�I" << std::endl;
	}

};


int main()
{
	//�G�̔z��
	//�p���iis A�j�̊֌W�̂���
	//��ɂȂ�N���X�̃|�C���^�Ŏw���������Ƃ��ł���
	Enemy* pEnArray[] = {
		new Kuribo(),		//�N���{�[���G�Ȃ̂ő���\
		new Nokonoko()		//�m�R�m�R���G�Ȃ̂ő���\
	};

	//�͈̓x�[�X�̌J��Ԃ��Ŏ��s
	//pEnArray�̗v�f�������it�Ɏ��o��
	for (auto& it : pEnArray)
	{
		it->Update();
	}

	return 0;
}