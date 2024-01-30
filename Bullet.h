#pragma once
#include "Vector2.h"

class Bullet {

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
	//弾発射フラグ
	bool isShoot;

public:

	//コンストラクタ
	Bullet();
	//デストラクタ
	~Bullet();

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
	//フラグのゲッター
	bool GetIsShot() { return isShoot; };

	//座標のセッター
	void SetPos(Vector2 pos) { pos_ = pos; };
	//フラグのセッター
	void SetIsShot(bool flag) { isShoot = flag; };
};