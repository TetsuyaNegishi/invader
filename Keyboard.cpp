#include "DxLib.h"
#include "Keyboard.h"

int Key[256];       //�L�[�̏�Ԃ�ێ�����z��

//Key�z��̑���
void gpUpdateKey(){
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for(int i=0; i<256; i++){
		if(tmpKey[i] != 0)
			Key[i]++;
		else
			Key[i] = 0;
	}
}

