#ifndef DEF_ENEMY_H
#define DEF_ENEMY_H

//�G�̃X�e�[�^�X
typedef struct{
	int num; //�G�̐�
	double speed; //�G�̈ړ��X�s�[�h
	int moveinterval;
	int down; //�G�̐i�R�X�s�[�h
	int size; //�G�̃T�C�Y
	int space; //�G�̔z�u�Ԋu
	double left,right,top,bottom; //�G�W�c��4�[�̍��W
	int numleft,numright,numtop,numbottom; //�G�W�c��4�[�̍s��,��
	double bulletspeed; //�G�e�̃X�s�[�h
	double bulletinterval; //�G�e�̐����C���^�[�o��
}EnemyStatus;

//�e�G�̃X�e�[�^�X
typedef struct{
	double x,y; //�G�̍��W
	bool flag; //�G�̑��݂̗L��
}EnemyStruct;

extern EnemyStatus Enemystatus; //�G�X�e�[�^�X�̐錾
extern EnemyStruct Enemy[EnemyNumRow][EnemyNumColumn]; //�e�G�̍��W�z��̐錾
void EnemyInit(); //�G�̏����ݒ�
void EnemyMove(); //�G�̈ړ�����
void DrawEnemy(); //�G�̕\��
void EdgeSearch(); //�G�W�c�̍���ƉE���̍��W����

#endif