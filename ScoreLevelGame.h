#ifndef DEF_SCORELEVEL_H
#define DEF_SCORELEVEL_H

enum Game{start = 0, playing = 1, gameover = 2};
extern Game game; //ゲームステータス
extern int score; //スコア
extern int level; //レベル

#endif