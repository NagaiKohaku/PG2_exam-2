#pragma once
#include "Player.h"
#include "Enemy.h"

class Collision {

public:

	//更新処理
	static void CheckCollision(Player* player, Enemy* enemy);

	//プレイヤーからエネミーへの当たり判定
	static void PlayerToEnemy(Player* player, Enemy* enemy);
	//弾からエネミーへの当たり判定
	static void BulletToEnemy(Player* player, Enemy* enemy);
};