#include "DxLib.h"
#include <math.h>
#include "Define.h"
#include "Keyboard.h"
#include "Player.h"

PlayerStruct Player; //プレイヤーの宣言

//プレイヤーの初期設定
void PlayerInit(){
	Player.x = Centerx;
	Player.y = FieldBottom - 20;
	Player.speed = 3;
	Player.size = 20;
	PlayerPointCalc();
	Player.bulletspeed = 5;
	Player.bulletflag = false;
}

//プレイヤーの座標(x1,y1,x2,y2,x3,y3)の計算
void PlayerPointCalc(){
	Player.x1 = Player.x;
	Player.y1 = Player.y-Player.size;
	Player.x2 = Player.x+Player.size*cos(PI/6);
	Player.y2 = Player.y+Player.size*sin(PI/6);
	Player.x3 = Player.x+Player.size*cos(PI*5/6);
	Player.y3 = Player.y+Player.size*sin(PI*5/6);
}

//プレイヤーの中心座標(x,y)の移動処理
void PlayerMove(){
	if(Key[KEY_INPUT_RIGHT] >= 1)
		Player.x += Player.speed;
	if(Key[KEY_INPUT_LEFT] >= 1)
		Player.x -= Player.speed;
	if(Player.x > FieldRight - Player.size*cos(PI/6))
		Player.x = FieldRight - Player.size*cos(PI/6);
	if(Player.x < FieldLeft - Player.size*cos(PI*5/6))
		Player.x = FieldLeft - Player.size*cos(PI*5/6);
	PlayerPointCalc();
}

//プレイヤーの弾の座標処理
void PlayerBulletMove(){
	if(Player.bulletflag == true)
		Player.bullety -= Player.bulletspeed;
	if(Key[KEY_INPUT_Z] >= 1 && Player.bulletflag == false){
		Player.bulletx = Player.x1;
		Player.bullety = Player.y1;
		Player.bulletflag = true;
	}
	if(Player.bullety <= FieldTop)
		Player.bulletflag = false;
}

//プレイヤーの表示
void DrawPlayer(){
	DrawTriangle((int)Player.x1, (int)Player.y1, (int)Player.x2, (int)Player.y2, (int)Player.x3, (int)Player.y3, GetColor(255, 255, 255), TRUE);
}

//プレイヤーの弾の表示
void DrawPlayerBullet(){
	if(Player.bulletflag == true)
		DrawCircle((int)Player.bulletx, (int)Player.bullety, 1, GetColor(255, 255, 255), TRUE);
}