#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H

//�v���C���[�̏���
typedef struct{
	double x, y; //�v���C���[�̒��S���W
	double x1, y1, x2, y2, x3, y3; //�v���C���[�̏�_�A�E�_�A���_�̍��W
	double speed; //�v���C���[�̈ړ��X�s�[�h
	int size; //�v���C���[�̑傫��
	double bulletx,bullety; //�v���C���[�̒e�̒��S���W
	double bulletspeed; //�v���C���[�̒e�̈ړ��X�s�[�h
	bool bulletflag; //�t�B�[���h��̃v���C���[�̒e�̗L��
}PlayerStruct; //�v���C���[�̍\����

extern PlayerStruct Player; //�v���C���[�̐錾

void PlayerInit();   //�����ݒ�
void PlayerPointCalc(); //�v���C���[�̍��W(x1,y1,x2,y2,x3,y3)�̌v�Z
void PlayerMove(); //�v���C���[�̒��S���W(x,y)�̈ړ�����
void PlayerBulletMove(); //�v���C���[�̒e�̍��W����
void DrawPlayer(); //�v���C���[�̕\��
void DrawPlayerBullet(); //�v���C���[�̒e�̕\��

#endif 