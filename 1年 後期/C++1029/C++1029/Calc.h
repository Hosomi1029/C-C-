#pragma once
#include<iostream>

class Calc
{
private:
	/// <summary>
	/// �d��̌v�Z���Ă��鐔��
	/// </summary>
	int m_Num;

public:
	/// <summary>
	///	int�̈�����1�󂯎��
	/// </summary>
	/// <param name="Num"></param>
	Calc(int Num);

	//�f�X�g���N�^�͕W������
	~Calc() = default;
	/// <summary>
	/// Num���R���\�[���ɕ\������֐�
	/// </summary>
	void Print();

};

