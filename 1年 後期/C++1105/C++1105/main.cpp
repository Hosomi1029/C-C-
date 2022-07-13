#include<iostream>

/*
* ゲームのキャラクタークラス
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
* ゲームの敵クラス
* 継承でCharacterを引き継ぐ
*/
class Enemy :public Character {
private:
public:
	/*
	* 継承する場合はデストラクタもvirtualをつける
	*/
	virtual ~Enemy(){}
	
	/*
	* 敵の動作関数
	* 多様性の実現（virtualをつける）
	* 仮想関数、継承先で動作を上書きできる
	*/
	/*
	* 純粋仮想関数、仮想関数の定義を書かずに　=0
	*/

	virtual void Update() = 0;

};

/*
* クリボークラス
* 継承でEnemyを引き継ぐ
*/
class Kuribo :public Enemy {
private:
public:
	/*
	* クリボーの動作関数
	* 仮想関数を上書き(override)しているという目印
	*/

	void Update() override{
		std::cout << "クリボー！！" << std::endl;
	}

};

/*
* ノコノコクラス
* 継承でEnemyを引き継ぐ
*/
class Nokonoko :public Enemy {
private:
public:

	/*
	* 敵の動作関数
	*/

	void Update() override{
		std::cout << "ノコノコ！！" << std::endl;
	}

};


int main()
{
	//敵の配列
	//継承（is A）の関係のため
	//基になるクラスのポインタで指し示すことができる
	Enemy* pEnArray[] = {
		new Kuribo(),		//クリボーも敵なので代入可能
		new Nokonoko()		//ノコノコも敵なので代入可能
	};

	//範囲ベースの繰り返しで実行
	//pEnArrayの要素を一つずつitに取り出す
	for (auto& it : pEnArray)
	{
		it->Update();
	}

	return 0;
}