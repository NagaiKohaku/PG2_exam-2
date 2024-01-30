#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

//シーン名を宣言
enum GameScene {
	TITLE,
	INGAME,
	GAMEOVER
};

class Scene {

private:

	/*メンバ変数の宣言*/

	//現在のシーン
	GameScene nowScene;

	//プレイヤーのインスタンス
	Player* player;

	//エネミーのインスタンス
	Enemy* enemy;

public:

	//コンストラクタ
	Scene();
	//デストラクタ
	~Scene();

	//更新処理
	void Update();

	//タイトルシーンの処理
	void Title();

	//ゲームシーンの処理
	void InGame();

	//ゲームオーバーシーンの処理
	void GameOver();

};