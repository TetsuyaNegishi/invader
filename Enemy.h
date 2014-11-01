#ifndef DEF_ENEMY_H
#define DEF_ENEMY_H

//敵のステータス
typedef struct{
	int num; //敵の数
	double speed; //敵の移動スピード
	int moveinterval;
	int down; //敵の進軍スピード
	int size; //敵のサイズ
	int space; //敵の配置間隔
	double left,right,top,bottom; //敵集団の4端の座標
	int numleft,numright,numtop,numbottom; //敵集団の4端の行数,列数
	double bulletspeed; //敵弾のスピード
	double bulletinterval; //敵弾の生成インターバル
}EnemyStatus;

//各敵のステータス
typedef struct{
	double x,y; //敵の座標
	bool flag; //敵の存在の有無
}EnemyStruct;

extern EnemyStatus Enemystatus; //敵ステータスの宣言
extern EnemyStruct Enemy[EnemyNumRow][EnemyNumColumn]; //各敵の座標配列の宣言
void EnemyInit(); //敵の初期設定
void EnemyMove(); //敵の移動処理
void DrawEnemy(); //敵の表示
void EdgeSearch(); //敵集団の左上と右下の座標検索

#endif