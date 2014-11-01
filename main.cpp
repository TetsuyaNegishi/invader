#include "DxLib.h"
#include <math.h>
#include "Define.h"
#include "ScoreLevelGame.h"
#include "Keyboard.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定

	GameInit();
    // 裏画面を表画面に反映, メッセージ処理, 画面クリア
    while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0){//
		gpUpdateKey();
		
		if(game == start){
			GameStart();
		}else if(game == playing){
			GamePlaying();
		}else{
			GameOver();
		}
		
		DrawBox(FieldLeft, FieldTop, FieldRight, FieldBottom, GetColor(255, 255, 255), FALSE); //フィールドの表示
	}
        
    DxLib_End(); // DXライブラリ終了処理
    return 0;
}
