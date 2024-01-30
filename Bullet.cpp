#include "Bullet.h"
#include "Novice.h"

//コンストラクタ
Bullet::Bullet() {

	/*メンバ変数の初期化*/

	//座標
	pos_ = { 0.0f,0.0f };
	//大きさ
	radius_ = 7.5f;
	//移動速度
	speed_ = 10.0f;
	//色
	color_ = WHITE;
	//弾発射フラグ
	isShoot = false;
}

//デストラクタ
Bullet::~Bullet() {
}

//初期化処理
void Bullet::Initialize() {

	/*メンバ変数の初期化*/

	//座標
	pos_ = { 0.0f,0.0f };
	//弾発射フラグ
	isShoot = false;
}

//更新処理
void Bullet::Update() {

	//発射されていたら移動処理を開始する
	if (isShoot) {
		Move();
	}
}

//描画処理
void Bullet::Draw() {

	//発射されていたら描画を開始する
	if (isShoot) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			color_,
			kFillModeSolid
		);
	}
}

//移動処理
void Bullet::Move() {

	//上方向に移動する
	pos_.y -= speed_;

	//画面から見えなくなったらフラグをfalseにして弾を消す
	if (pos_.y <= 0.0f - radius_) {
		isShoot = false;
	}
}