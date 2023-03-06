#ifndef STRUCT_H
#define STRUCT_H

class plane {
	public:
	int num;//棋子在棋盘上的编号
	int flag;//棋子所处位置（0：起始位置；1：路途中；2：到达目的地）
	char color;//棋子颜色
};
class Map{
	public:
	bool flag;//格子上是否有棋子
	int plane_num;//格子上有几个棋子
	char plane_color;//如果有棋子，棋子对应的颜色
};
class Airport//分流后的跑道
{
	public:
	bool flag;//格子上是否有棋子
	int plane_num;//格子上有几个棋子
	char color;//如果有棋子，棋子对应颜色
};
void color(int x);//设置字体颜色
int color_num(char ch); 
int print_color1(char color);
int print_color2(int a);
void print_plane(int sum);
void print_map(int sum);
void init_plane(int sum);
void init_map(int sum);
#endif