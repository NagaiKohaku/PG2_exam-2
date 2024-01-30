#include "Enemy.h"
#include "Novice.h"
#include "math.h"

Enemy::Enemy() {

	/*メンバ変数の初期化*/

	//座標
	pos_ = { 640.0f,180.0f };
	//大きさ
	radius_ = 30.0f;
	//移動速度
	speed_ = 5.0f;
	//移動方向
	direction_ = 1;
	//色
	color_ = RED;
	//生存フラグ
	isAlive_ = true;
	//リスポーンに必要な時間(秒)
	reSpawnTime_ = 1;
	//タイマー
	timer_ = reSpawnTime_ * 60;
}

//デストラクタ
Enemy::~Enemy() {
}

//初期化処理
void Enemy::Initialize() {

	/*メンバ変数の初期化*/

	//座標
	pos_ = { 640.0f,180.0f };
	//移動方向
	direction_ = 1;
	//生存フラグ
	isAlive_ = true;
	//タイマー
	timer_ = reSpawnTime_ * 60;
}

//更新処理
void Enemy::Update() {

	//生存フラグがtrueの場合は移動処理をする
	if (isAlive_) {
		Move();
	}

	//生存フラグがfalseの場合はリスポーン処理をする
	if (!isAlive_) {

		//タイマーを減らしていく
		timer_--;

		//タイマーが0以下になったら再度生存フラグをtrueにしてタイマーをリセットする
		if (timer_ < 0) {

			isAlive_ = true;
			timer_ = reSpawnTime_ * 60;
		}
	}
}

//描画処理
void Enemy::Draw() {

	//生存フラグがtrueの場合は描画をする
	if (isAlive_) {
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
void Enemy::Move() {

	//X軸上で移動させる
	pos_.x += speed_ * direction_;

	//画面端に達したら移動方向を反転させる
	if (pos_.x < 0.0f + radius_ || pos_.x > 1280.0f - radius_) {
		direction_ *= -1.0f;
	}
}