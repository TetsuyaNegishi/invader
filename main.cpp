#include "DxLib.h"
#include <math.h>
#include "Define.h"
#include "ScoreLevelGame.h"
#include "Keyboard.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	GameInit();
    // ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A
    while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0){//
		gpUpdateKey();
		
		if(game == start){
			GameStart();
		}else if(game == playing){
			GamePlaying();
		}else{
			GameOver();
		}
		
		DrawBox(FieldLeft, FieldTop, FieldRight, FieldBottom, GetColor(255, 255, 255), FALSE); //�t�B�[���h�̕\��
	}
        
    DxLib_End(); // DX���C�u�����I������
    return 0;
}
