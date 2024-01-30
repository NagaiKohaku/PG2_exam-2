#pragma once
#include "Vector2.h"

class Enemy {

private:

	/*メンバ変数*/

	//座標
	Vector2 pos_;
	//大きさ
	float radius_;
	//移動速度
	float speed_;
	//移動方向
	float direction_;
	//色
	unsigned int color_;
	//生存フラグ
	bool isAlive_;
	//リスポーンに必要な時間(秒)
	int reSpawnTime_;
	//タイマー
	int timer_;

public:

	//コンストラクタ
	Enemy();
	//デストラクタ
	~Enemy();

	//初期化処理
	void Initialize();

	//更新処理
	void Update();
	//描画処理
	void Draw();

	//移動処理
	void Move();

	/*アクセッサ*/

	//座標のゲッター
	Vector2 GetPos() { return pos_; };
	//大きさのゲッター
	float GetRadius() { return radius_; };
	//生存フラグのゲッター
	bool GetIsAlive() { return isAlive_; };

	//生存フラグのセッター
	void SetIsAlive(bool flag) { isAlive_ = flag; };
};