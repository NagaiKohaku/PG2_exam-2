#include "Player.h"
#include "Novice.h"

//コンストラクタ
Player::Player() {

	/*メンバ変数の初期化*/

	//座標
	pos_ = { 640.0f,520.0f };
	//大きさ
	radius_ = 30.0f;
	//移動速度
	speed_ = 5.0f;
	//色
	color_ = WHITE;
	//生存フラグ
	isAlive_ = true;
	//弾クラスからインスタンスを生成
	for (int i = 0; i < 30; i++) {
		bullet_[i] = new Bullet();
	}
	//タイマー
	timer_ = 0;
	//弾発射のクールタイム
	coolTime_ = 3;
}

//デストラクタ
Player::~Player() {

	//メモリ開放
	for (int i = 0; i < 30; i++) {
		delete bullet_[i];
	}
}

//初期化処理
void Player::Initialize() {

	/*メンバ変数の初期化*/

	//座標
	pos_ = { 640.0f,520.0f };
	//生存フラグ
	isAlive_ = true;
	//弾を初期化
	for (int i = 0; i < 30; i++) {
		bullet_[i]->Initialize();
	}
	//タイマー
	timer_ = 0;
}

//更新処理
void Player::Update() {

	if (isAlive_) {
		//移動処理
		Move();

		//弾発射処理
		Shot();

		//弾の処理
		for (int i = 0; i < 30; i++) {

			//弾の更新処理
			bullet_[i]->Update();

			//弾の描画処理
			bullet_[i]->Draw();
		}

		//タイマーを進める
		timer_++;
	}
}

//描画処理
void Player::Draw() {

	if (isAlive_) {
		//円で描画
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
void Player::Move() {

	/*キーが押されたら対応した方向に移動する*/

	//Wキーが押されたら上に移動する
	if (Novice::CheckHitKey(DIK_W)) {
		pos_.y -= speed_;
	}

	//Aキーが押されたら左に移動する
	if (Novice::CheckHitKey(DIK_A)) {
		pos_.x -= speed_;
	}

	//Sキーが押されたら下に移動する
	if (Novice::CheckHitKey(DIK_S)) {
		pos_.y += speed_;
	}

	//Dキーが押されたら右に移動する
	if (Novice::CheckHitKey(DIK_D)) {
		pos_.x += speed_;
	}
}

//弾発射処理
void Player::Shot() {

	//スペースキーが押されていたら弾を発射する
	if (Novice::CheckHitKey(DIK_SPACE)) {

		//タイマーがクールタイムを越えていたら弾を発射する
		if (timer_ > coolTime_) {

			for (int i = 0; i < 30; i++) {

				//弾の発射フラグがfalseであったら弾を発射する
				if (!bullet_[i]->GetIsShot()) {

					//弾発射フラグをtrueにする
					bullet_[i]->SetIsShot(true);
					
					//弾の座標をプレイヤーの座標に設定する
					bullet_[i]->SetPos(pos_);

					//タイマーのリセット
					timer_ = 0;

					return;
				}
			}
		}
	}
}