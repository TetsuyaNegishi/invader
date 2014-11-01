#include "DxLib.h"
#include "Keyboard.h"

int Key[256];       //キーの状態を保持する配列

//Key配列の操作
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

