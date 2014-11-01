#ifndef DEF_ENEMYBULLET_H
#define DEF_ENEMYBULLET_H

typedef struct{
	double x,y; //“G’e‚ÌÀ•W
	bool flag; //“G’e‚Ì‘¶İ‚Ì—L–³
	int interval; //“G’e‚Ì”­¶ƒCƒ“ƒ^[ƒoƒ‹
}EnemyBulletStruct;

extern EnemyBulletStruct EnemyBullet[EnemyBulletNum]; //“G’eƒXƒe[ƒ^ƒX‚ÌéŒ¾
void EnemyBulletInit(); //“G’e‚Ì‰Šúİ’è
void EnemyBulletInterval(); //“G’e‚ÌƒCƒ“ƒ^[ƒoƒ‹‚Ìˆ—
void EnemyBulletCreate(int i); //“G’e‚Ì¶¬ˆ—
void EnemyBulletMove(); //“G’e‚ÌˆÚ“®ˆ—
void DrawEnemyBullet(); //“G’e‚Ì•\¦

#endif