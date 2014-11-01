#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H

//プレイヤーの処理
typedef struct{
	double x, y; //プレイヤーの中心座標
	double x1, y1, x2, y2, x3, y3; //プレイヤーの上点、右点、左点の座標
	double speed; //プレイヤーの移動スピード
	int size; //プレイヤーの大きさ
	double bulletx,bullety; //プレイヤーの弾の中心座標
	double bulletspeed; //プレイヤーの弾の移動スピード
	bool bulletflag; //フィールド上のプレイヤーの弾の有無
}PlayerStruct; //プレイヤーの構造体

extern PlayerStruct Player; //プレイヤーの宣言

void PlayerInit();   //初期設定
void PlayerPointCalc(); //プレイヤーの座標(x1,y1,x2,y2,x3,y3)の計算
void PlayerMove(); //プレイヤーの中心座標(x,y)の移動処理
void PlayerBulletMove(); //プレイヤーの弾の座標処理
void DrawPlayer(); //プレイヤーの表示
void DrawPlayerBullet(); //プレイヤーの弾の表示

#endif 