#pragma once
#include "Vector2.h"
#include "Bullet.h"

class Player {

private:

	/*メンバ変数*/

	//座標
	Vector2 pos_;
	//大きさ
	float radius_;
	//移動速度
	float speed_;
	//色
	unsigned int color_;
	//生存フラグ
	bool isAlive_;
	//弾
	Bullet* bullet_[30];
	//タイマー
	int timer_;
	//弾発射のクールタイム
	int coolTime_;

public:

	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//初期化処理
	void Initialize();

	//更新処理
	void Update();
	//描画処理
	void Draw();

	//移動処理
	void Move();
	//弾発射処理
	void Shot();

	/*アクセッサ*/

	//座標のゲッター
	Vector2 GetPos() { return pos_; };
	//大きさのゲッター
	float GetRadius() { return radius_; };
	//弾インスタンスのゲッター
	Bullet* GetBullet(int num) { return bullet_[num]; };
	//生存フラグのゲッター
	bool GetIsAlive() { return isAlive_; };

	//生存フラグのセッター
	void SetIsAlive(bool flag) { isAlive_ = flag; };
};

