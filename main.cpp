#include <Novice.h>
#include "Scene.h"

const char kWindowTitle[] = "LC1B_16_ナガイ_コハク_PG2_exam-2 評価課題2";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//シーン管理クラスからインスタンスを生成
	Scene* scene = new Scene();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//シーン管理クラスの更新処理
		scene->Update();

		// フレームの終了
		Novice::EndFrame();
	}

	//メモリ開放
	delete scene;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
