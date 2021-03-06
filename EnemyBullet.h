#ifndef DEF_ENEMYBULLET_H
#define DEF_ENEMYBULLET_H

typedef struct{
	double x,y; //敵弾の座標
	bool flag; //敵弾の存在の有無
	int interval; //敵弾の発生インターバル
}EnemyBulletStruct;

extern EnemyBulletStruct EnemyBullet[EnemyBulletNum]; //敵弾ステータスの宣言
void EnemyBulletInit(); //敵弾の初期設定
void EnemyBulletInterval(); //敵弾のインターバルの処理
void EnemyBulletCreate(int i); //敵弾の生成処理
void EnemyBulletMove(); //敵弾の移動処理
void DrawEnemyBullet(); //敵弾の表示

#endif