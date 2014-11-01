#include "DxLib.h"
#include "Define.h"
#include "ScoreLevelGame.h"
#include "Enemy.h"

EnemyStatus Enemystatus; //“GƒXƒe[ƒ^ƒX‚ÌéŒ¾
EnemyStruct Enemy[EnemyNumRow][EnemyNumColumn]; //Še“G‚ÌÀ•W”z—ñ‚ÌéŒ¾

//“G‚Ì‰Šúİ’è
void EnemyInit(){
	Enemystatus.num = EnemyNumRow * EnemyNumColumn;
	Enemystatus.speed = 5;
	Enemystatus.moveinterval = 20;
	Enemystatus.size = 10;
	Enemystatus.space = 30;
	Enemystatus.down = 10;
	for(int i=0; i<EnemyNumRow; i++){
		for(int k=0; k<EnemyNumColumn; k++){
			Enemy[i][k].x = Centerx + Enemystatus.space*(k - EnemyNumColumn/2);
			Enemy[i][k].y = Centery-100 + Enemystatus.space*(i - EnemyNumRow/2) + level*20;
			Enemy[i][k].flag = true;
		}
	}
	Enemystatus.numleft = 0;
	Enemystatus.numtop = 0;
	Enemystatus.numright = EnemyNumColumn-1;
	Enemystatus.numbottom = EnemyNumRow-1;
	Enemystatus.bottom = EnemyNumColumn-1;
	Enemystatus.left = Enemy[0][0].x - Enemystatus.size;
	Enemystatus.right = Enemy[EnemyNumRow-1][EnemyNumColumn-1].x + Enemystatus.size;
	Enemystatus.top = Enemy[0][0].y - Enemystatus.size;
	Enemystatus.bottom = Enemy[EnemyNumRow-1][EnemyNumColumn-1].y + Enemystatus.size;
}

//“G‚ÌˆÚ“®ˆ—
void EnemyMove(){
	if(Enemystatus.moveinterval != 0){
		Enemystatus.moveinterval--;
		return;
	}
	if(Enemystatus.left <= FieldLeft || Enemystatus.right >= FieldRight){
		Enemystatus.speed = -Enemystatus.speed;
		Enemystatus.top += Enemystatus.down;
		Enemystatus.bottom += Enemystatus.down;
		if(Enemystatus.bottom > LimitLine)
			game = gameover;
		for(int i=0; i<EnemyNumRow; i++)
			for(int k=0; k<EnemyNumColumn; k++)
				Enemy[i][k].y += Enemystatus.down;
	}
	for(int i=Enemystatus.numtop; i<=Enemystatus.numbottom; i++)
		for(int k=Enemystatus.numleft; k<=Enemystatus.numright; k++)
				Enemy[i][k].x += Enemystatus.speed;
	Enemystatus.left = Enemy[Enemystatus.numtop][Enemystatus.numleft].x - Enemystatus.size;
	Enemystatus.right = Enemy[Enemystatus.numbottom][Enemystatus.numright].x + Enemystatus.size;
	if(Enemystatus.num > 25)
		Enemystatus.moveinterval = 20;
	else if(Enemystatus.num > 15)
		Enemystatus.moveinterval = 15;
	else if(Enemystatus.num > 10)
		Enemystatus.moveinterval = 10;
	else if(Enemystatus.num > 5)
		Enemystatus.moveinterval = 5;
	else if(Enemystatus.num >= 2)
		Enemystatus.moveinterval = 2;
	else 
		Enemystatus.moveinterval = 1;
}

//“G‚Ì•\¦
void DrawEnemy(){
	for(int i=0; i<EnemyNumRow; i++)
		for(int k=0; k<EnemyNumColumn; k++)
			if(Enemy[i][k].flag == true)
					DrawBox((int)(Enemy[i][k].x-Enemystatus.size), (int)(Enemy[i][k].y-Enemystatus.size), (int)(Enemy[i][k].x+Enemystatus.size), (int)(Enemy[i][k].y+Enemystatus.size), GetColor(255, 0, 0), TRUE);
}

//“GW’c‚Ì¶ã‚Æ‰E‰º‚ÌÀ•WŒŸõ
void EdgeSearch(){
	int r,c,row,column,left,right,top,bottom;
	left = Enemystatus.numleft;
	right = Enemystatus.numright;
	top = Enemystatus.numtop;
	bottom = Enemystatus.numbottom;
	row = top;
	column = left;

	//“GW’c‚Ì¶ã‚ÌÀ•WŒŸõ
	for(r=top; r<=bottom; r++)
		for(c=left; c<=right; c++)			
			if(Enemy[r][c].flag == true){
				row = r;
				goto end1;
			}
end1:
	for(c=left; c<=right; c++)
		for(r=top; r<=bottom; r++)		
			if(Enemy[r][c].flag == true){
				column = c;
				goto end2;
			}
end2:
	Enemystatus.numleft = column;
	Enemystatus.numtop = row;
	Enemystatus.left = Enemy[row][column].x - Enemystatus.size;
	Enemystatus.top = Enemy[row][column].y - Enemystatus.size;

	//“GW’c‚Ì‰E‰º‚ÌÀ•WŒŸõ
	for(r=bottom; r>=top; r--)
		for(c=right; c>=left; c--)			
			if(Enemy[r][c].flag == true){
				row = r;
				goto end3;
			}
end3:
	for(c=right; c>=left; c--)
		for(r=bottom; r>=top; r--)		
			if(Enemy[r][c].flag == true){
				column = c;
				goto end4;
			}
end4:
	Enemystatus.numright = column;
	Enemystatus.numbottom = row;
	Enemystatus.right = Enemy[row][column].x + Enemystatus.size;
	Enemystatus.bottom = Enemy[row][column].y + Enemystatus.size;	
}

