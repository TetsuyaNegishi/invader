#include "DxLib.h"
#include "Define.h"
#include "ScoreLevelGame.h"
#include "Keyboard.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Collision.h"
#include "Game.h"

//ゲーム初期設定
void GameInit(){
	SetFontSize(20) ;                             //サイズを64に変更
    ChangeFont("ＭＳ ゴシック") ;                     //種類をMSゴシックに変更
	game = start;
}

//スタート画面処理
void GameStart(){
    DrawString(FieldBottom/2,200,"PUSH [SPACE] KEY",GetColor(255,255,255));
	if(Key[KEY_INPUT_SPACE] >= 1){
		game = playing;
		score = 0;
		PlayerInit();
		EnemyInit();
		EnemyBulletInit();
	}
}

//ゲームメイン処理
void GamePlaying(){
	PlayerMove();
	PlayerBulletMove();
	EnemyMove();
	EnemyBulletInterval();
	EnemyBulletMove();
	PlayerBulletCollision();
	EnemyBulletCollision();
	DrawPlayer();
	DrawPlayerBullet();
	DrawEnemy();
	DrawEnemyBullet();
	DrawFormatString(0,0,GetColor(255,255,255),"Score:%d",score);
}

//ゲームオーバー画面処理
void GameOver(){
	DrawFormatString(FieldBottom/2,170,GetColor(255,255,255),"SCORE:%d",score);
	DrawString(FieldBottom/2,200,"REPLAY PUSH [R] KEY",GetColor(255,255,255));
	if(Key[KEY_INPUT_R] >= 1)
		game = start;
}