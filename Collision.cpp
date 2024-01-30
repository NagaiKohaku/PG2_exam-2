#include "Collision.h"
#include "math.h"

void Collision::CheckCollision(Player* player, Enemy* enemy) {
	PlayerToEnemy(player, enemy);
	BulletToEnemy(player, enemy);
}

//プレイヤーからエネミーへの当たり判定
void Collision::PlayerToEnemy(Player* player, Enemy* enemy) {

	//エネミーの生存フラグがtrueだった場合は当たり判定をとる
	if (enemy->GetIsAlive()) {

		/*プレイヤーとエネミーの距離を求める*/

		//X軸
		float p2eX = powf((player->GetPos().x - enemy->GetPos().x), 2.0f);
		//Y軸
		float p2eY = powf((player->GetPos().y - enemy->GetPos().y), 2.0f);
		//半径
		float p2eR = powf((player->GetRadius() + enemy->GetRadius()), 2.0f);

		//プレイヤーとエネミーが接していたらプレイヤーの生存フラグをfalseにする
		if (p2eR >= p2eX + p2eY) {
			player->SetIsAlive(false);
		}
	}
}

//弾からエネミーへの当たり判定
void Collision::BulletToEnemy(Player* player, Enemy* enemy) {

	for (int i = 0; i < 30; i++) {

		//弾の発射フラグがtrueだった場合は当たり判定をとる
		if (player->GetBullet(i)->GetIsShot()) {

			/*弾とエネミーの距離を求める*/

			//X軸
			float b2eX = powf((player->GetBullet(i)->GetPos().x - enemy->GetPos().x), 2.0f);
			//Y軸
			float b2eY = powf((player->GetBullet(i)->GetPos().y - enemy->GetPos().y), 2.0f);
			//半径
			float b2eR = powf((player->GetBullet(i)->GetRadius() + enemy->GetRadius()), 2.0f);

			//弾とエネミーが接していたらエネミーの生存フラグをfalseにする
			if (b2eR >= b2eX + b2eY) {
				enemy->SetIsAlive(false);
				return;
			}
		}
	}
}