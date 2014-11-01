#include "DxLib.h"
#include <math.h>
#include "Define.h"
#include "Keyboard.h"
#include "Player.h"

PlayerStruct Player; //�v���C���[�̐錾

//�v���C���[�̏����ݒ�
void PlayerInit(){
	Player.x = Centerx;
	Player.y = FieldBottom - 20;
	Player.speed = 3;
	Player.size = 20;
	PlayerPointCalc();
	Player.bulletspeed = 5;
	Player.bulletflag = false;
}

//�v���C���[�̍��W(x1,y1,x2,y2,x3,y3)�̌v�Z
void PlayerPointCalc(){
	Player.x1 = Player.x;
	Player.y1 = Player.y-Player.size;
	Player.x2 = Player.x+Player.size*cos(PI/6);
	Player.y2 = Player.y+Player.size*sin(PI/6);
	Player.x3 = Player.x+Player.size*cos(PI*5/6);
	Player.y3 = Player.y+Player.size*sin(PI*5/6);
}

//�v���C���[�̒��S���W(x,y)�̈ړ�����
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

//�v���C���[�̒e�̍��W����
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

//�v���C���[�̕\��
void DrawPlayer(){
	DrawTriangle((int)Player.x1, (int)Player.y1, (int)Player.x2, (int)Player.y2, (int)Player.x3, (int)Player.y3, GetColor(255, 255, 255), TRUE);
}

//�v���C���[�̒e�̕\��
void DrawPlayerBullet(){
	if(Player.bulletflag == true)
		DrawCircle((int)Player.bulletx, (int)Player.bullety, 1, GetColor(255, 255, 255), TRUE);
}