#include "Scene.h"
#include "Novice.h"

//コンストラクタ
Scene::Scene() {

	/*メンバ変数の初期化*/

	//現在のシーン
	nowScene = GAMEOVER;

	//プレイヤーのインスタンスを生成
	player = new Player();

	//エネミーのインスタンスを生成
	enemy = new Enemy();
}

Scene::~Scene() {

	//メモリ開放
	delete player;
	delete enemy;
}

void Scene::Update() {

	//現在のシーンに合わせて処理を変える
	switch (nowScene) {

	case TITLE:

		//タイトルシーン
		Title();

		break;

	case INGAME:

		//ゲームシーン
		InGame();

		break;

	case GAMEOVER:

		//ゲームオーバーシーン
		GameOver();

		break;

	default:

		break;
	}
}

//タイトルシーンの処理
void Scene::Title() {

	//Rキーが押されたらゲームシーンに移行する
	if (Novice::CheckHitKey(DIK_SPACE)) {

		//現在のシーンをゲームシーンに変更
		nowScene = INGAME;

		//プレイヤーの初期化
		player->Initialize();

		//エネミーの初期化
		enemy->Initialize();

		return;
	}

	Novice::ScreenPrintf(615, 335, "Title");

	Novice::ScreenPrintf(580, 365, "Space : Start");

}

//ゲームシーンの処理
void Scene::InGame() {

	//ESCキーが押されたらタイトルシーンに移行する
	if (Novice::CheckHitKey(DIK_ESCAPE)) {

		//現在のシーンをタイトルシーンに変更する
		nowScene = TITLE;

		return;
	}

	//プレイヤーがやられたらゲームオーバーシーンに移行する
	if (!player->GetIsAlive()) {

		//現在のシーンをゲームオーバーシーンに変更する
		nowScene = GAMEOVER;

		return;
	}

	//プレイヤーの更新処理
	player->Update();

	//エネミーの更新処理
	enemy->Update();

	//当たり判定処理
	Collision::CheckCollision(player, enemy);

	//エネミーの描画処理
	enemy->Draw();

	//プレイヤーの描画処理
	player->Draw();

	Novice::ScreenPrintf(10, 10, "WASD : Move");
	Novice::ScreenPrintf(10, 30, "Space : Shot");
	Novice::ScreenPrintf(10, 50, "ESC : Title");

}

//ゲームオーバーシーンの処理
void Scene::GameOver() {

	//Rキーが押されたらゲームシーンに移行する
	if (Novice::CheckHitKey(DIK_SPACE)) {

		//現在のシーンをゲームシーンに変更する
		nowScene = INGAME;

		//プレイヤーの初期化
		player->Initialize();

		//エネミーの初期化
		enemy->Initialize();

		return;
	}

	//ESCキーが押されたらタイトルシーンに移行する
	if (Novice::CheckHitKey(DIK_ESCAPE)) {

		//現在のシーンをタイトルシーンに変更する
		nowScene = TITLE;

		return;
	}

	Novice::ScreenPrintf(600, 315, "GameOver");
	Novice::ScreenPrintf(580, 350, "Space : Retry");
	Novice::ScreenPrintf(598, 375, "ESC : Title");
}