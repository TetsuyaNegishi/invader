#ifndef DEF_ENEMYBULLET_H
#define DEF_ENEMYBULLET_H

typedef struct{
	double x,y; //�G�e�̍��W
	bool flag; //�G�e�̑��݂̗L��
	int interval; //�G�e�̔����C���^�[�o��
}EnemyBulletStruct;

extern EnemyBulletStruct EnemyBullet[EnemyBulletNum]; //�G�e�X�e�[�^�X�̐錾
void EnemyBulletInit(); //�G�e�̏����ݒ�
void EnemyBulletInterval(); //�G�e�̃C���^�[�o���̏���
void EnemyBulletCreate(int i); //�G�e�̐�������
void EnemyBulletMove(); //�G�e�̈ړ�����
void DrawEnemyBullet(); //�G�e�̕\��

#endif