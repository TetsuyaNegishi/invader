#include <math.h>
#include "Define.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "ScoreLevelGame.h"
#include "Collision.h"

//プレイヤーの弾と敵との衝突判定処理
void PlayerBulletCollision(){
	if(Player.bulletflag == false)
		return;
	if(Player.bulletx < Enemystatus.left ||  Enemystatus.right < Player.bulletx || Player.bullety < Enemystatus.top || Enemystatus.bottom < Player.bullety)
		return;
	for(int i=0; i<EnemyNumRow; i++)
		for(int k=0; k<EnemyNumColumn; k++)
			if(Enemy[i][k].flag == true && abs(Enemy[i][k].x - Player.bulletx) <= Enemystatus.size && abs(Enemy[i][k].y - Player.bullety) <= Enemystatus.size){
				Player.bulletflag = false;
				Enemy[i][k].flag = false;
				Enemystatus.num--;
				score++;
				EdgeSearch();
				goto end;
			}
end:
	if(Enemystatus.num == 0){
		level++;
		EnemyInit();
	}
}

//敵弾とプレイヤーとの衝突判定処理
void EnemyBulletCollision(){
	double dx,dx1,dx2;
	for(int i=0; i<EnemyBulletNum; i++){
		if(EnemyBullet[i].flag == true && Player.y1 < EnemyBullet[i].y && EnemyBullet[i].y < Player.y2){
			dx = tan(PI/6) * (EnemyBullet[i].y-Player.y1);
			dx1 = Player.x - dx;
			dx2 = Player.x + dx;
			if(dx1 < EnemyBullet[i].x && EnemyBullet[i].x < dx2)
				game = gameover;
		}
	}
}
