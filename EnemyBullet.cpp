#include "DxLib.h"
#include "Define.h"
#include "Enemy.h"
#include "EnemyBullet.h"

EnemyBulletStruct EnemyBullet[EnemyBulletNum]; //“G’eƒXƒe[ƒ^ƒX‚ÌéŒ¾

//“G’e‚Ì‰Šúİ’è
void EnemyBulletInit(){
	for(int i=0; i<EnemyBulletNum; i++){
		EnemyBullet[i].flag = false;
		EnemyBullet[i].interval = GetRand(5)*60;
	}
}

//“G’e‚ÌƒCƒ“ƒ^[ƒoƒ‹‚Ìˆ—
void EnemyBulletInterval(){
	for(int i=0; i<EnemyBulletNum; i++){
		if(EnemyBullet[i].interval == 0)
			EnemyBulletCreate(i);
		if(EnemyBullet[i].interval > 0)
			EnemyBullet[i].interval--;
	}
}

//“G’e‚Ì¶¬ˆ—
void EnemyBulletCreate(int i){
	int r,c,k=1;
	while(k){
		r = 0+GetRand(EnemyNumRow);
		c = 0+GetRand(EnemyNumColumn);
		if(Enemy[r][c].flag == true){
			EnemyBullet[i].x = Enemy[r][c].x;
			EnemyBullet[i].y = Enemy[r][c].y+Enemystatus.size;
			EnemyBullet[i].flag = true;
			EnemyBullet[i].interval--;
			k--;
		}
	}
}

//“G’e‚ÌˆÚ“®ˆ—
void EnemyBulletMove(){
	for(int i=0; i<EnemyBulletNum; i++){
		if(EnemyBullet[i].y > FieldBottom){
			EnemyBullet[i].x = 0;
			EnemyBullet[i].y = 0;
			EnemyBullet[i].flag = false;
			EnemyBullet[i].interval = GetRand(5)*60;
		}
		if(EnemyBullet[i].flag == true)
			EnemyBullet[i].y = EnemyBullet[i].y+2;
	}
}

//“G’e‚Ì•\¦
void DrawEnemyBullet(){
	for(int i=0; i<EnemyBulletNum; i++)
		if(EnemyBullet[i].flag == true){
			DrawLine((int)EnemyBullet[i].x, (int)EnemyBullet[i].y, (int)EnemyBullet[i].x, (int)(EnemyBullet[i].y-10), GetColor(255,0,0));
			DrawTriangle((int)EnemyBullet[i].x, (int)(EnemyBullet[i].y+5), (int)(EnemyBullet[i].x-3), (int)EnemyBullet[i].y, (int)(EnemyBullet[i].x+3), (int)EnemyBullet[i].y, GetColor(255, 0, 0), TRUE);
		}
}
