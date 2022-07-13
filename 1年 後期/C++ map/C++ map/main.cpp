#include <iostream>

//std::mapを使うためのインクルード
#include <map>

int main() {
	//std::map<キー、データ>
	//キー:データの検索などに使う値
	//データ:保存させたいデータ
	std::map<std::string, int>Data;

	//mapにデータを代入する
	//配列の添え字に当たる場所[]をキーの型で指定する
	//添え字で指定した段階でなければ新しく作成される
	Data["ABC"] = 10;
	Data["DEF"] = 20;

	//mapのデータを表示する
	std::cout << Data["ABC"] << std::endl;

	//※注意
	//添え字で指定した瞬間に作られるため、
	//代入していないデータで表示などができてしまう
	std::cout << Data["XYZ"] << std::endl;

	//mapでデータがある場合だけ表示する
	//findで検索する
	auto it = Data.find("AAA");
	//最後まで見つからなければend()と一致する
	if (it == Data.end())
	{
		std::cout << "そんなデータはありません" << std::endl;
	}
	//mapの全データを表示する
	for (auto it = Data.begin(); it != Data.end(); ++it)
	{
		//it->first	 :mapのキー
		//it->second：mapのデータ

		std::cout << "key:" << it->first << "[" << it->second << "]" << std::endl;
	}

	return 0;
}