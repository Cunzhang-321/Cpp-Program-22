#include <iostream>
#include <windows.h>
#include "struct.h"
using namespace std;
plane yellow[5], red[5], blue[5], green[5];
Map map[20];
Airport airport[5][7];
void color(int x) //设置字体颜色
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int color_num(char ch) {
	switch (ch)
	{
	case 'Y':return 0; break;
	case 'R':return 1; break;
	case 'B':return 2; break;
	case 'G':return 3; break;
	default:break;
	}
}
int print_color1(char color)
{
	switch (color)
	{
	case 'Y':return 6; break;
	case 'R':return 4; break;
	case 'B':return 1; break;
	case 'G':return 2; break;
	default:
		break;
	}
}
int print_color2(int a)
{
	switch (a)
	{
	case 0:return 6; break;
	case 1:return 4; break;
	case 2:return 1; break;
	case 3:return 2; break;
	default:
		break;
	}
}
void print_plane(int sum)
{
	switch (sum){
	case 2:
		color(6);
		yellow[1].flag == 0 ? cout << yellow[1].color : cout << "O";
		yellow[2].flag == 0 ? cout << yellow[2].color : cout << "O";
		cout << " ";
		color(4);
		red[1].flag == 0 ? cout << red[1].color : cout << "O";
		red[2].flag == 0 ? cout << red[2].color : cout << "O";
		cout << endl;
		color(6);
		yellow[3].flag == 0 ? cout << yellow[3].color : cout << "O";
		yellow[4].flag == 0 ? cout << yellow[4].color : cout << "O";
		cout << " ";
		color(4);
		red[3].flag == 0 ? cout << red[3].color : cout << "O";
		red[4].flag == 0 ? cout << red[4].color : cout << "O";
		cout << endl;
		color(15);
		break;
	case 3:
		color(6);
		yellow[1].flag == 0 ? cout << yellow[1].color : cout << "O";
		yellow[2].flag == 0 ? cout << yellow[2].color : cout << "O";
		cout << " ";
		color(4);
		red[1].flag == 0 ? cout << red[1].color : cout << "O";
		red[2].flag == 0 ? cout << red[2].color : cout << "O";
		cout << " ";
		color(1);
		blue[1].flag == 0 ? cout << blue[1].color : cout << "O";
		blue[2].flag == 0 ? cout << blue[2].color : cout << "O";
		cout << endl;
		color(6);
		yellow[3].flag == 0 ? cout << yellow[3].color : cout << "O";
		yellow[4].flag == 0 ? cout << yellow[4].color : cout << "O";
		cout << " ";
		color(4);
		red[3].flag == 0 ? cout << red[3].color : cout << "O";
		red[4].flag == 0 ? cout << red[4].color : cout << "O";
		cout << " ";
		color(1);
		blue[3].flag == 0 ? cout << blue[3].color : cout << "O";
		blue[4].flag == 0 ? cout << blue[4].color : cout << "O";
		cout << endl;
		color(15);
		break;
	case 4:
		color(6);
		yellow[1].flag == 0 ? cout << yellow[1].color : cout << "O";
		yellow[2].flag == 0 ? cout << yellow[2].color : cout << "O";
		cout << " ";
		color(4);
		red[1].flag == 0 ? cout << red[1].color : cout << "O";
		red[2].flag == 0 ? cout << red[2].color : cout << "O";
		cout << " ";
		color(1);
		blue[1].flag == 0 ? cout << blue[1].color : cout << "O";
		blue[2].flag == 0 ? cout << blue[2].color : cout << "O";
		cout << " ";
		color(2);
		green[1].flag == 0 ? cout << green[1].color : cout << "O";
		green[2].flag == 0 ? cout << green[2].color : cout << "O";
		cout << endl;
		color(6);
		yellow[3].flag == 0 ? cout << yellow[3].color : cout << "O";
		yellow[4].flag == 0 ? cout << yellow[4].color : cout << "O";
		cout << " ";
		color(4);
		red[3].flag == 0 ? cout << red[3].color : cout << "O";
		red[4].flag == 0 ? cout << red[4].color : cout << "O";
		cout << " ";
		color(1);
		blue[3].flag == 0 ? cout << blue[3].color : cout << "O";
		blue[4].flag == 0 ? cout << blue[4].color : cout << "O";
		cout << " ";
		color(2);
		green[3].flag == 0 ? cout << green[3].color : cout << "O";
		green[4].flag == 0 ? cout << green[4].color : cout << "O";
		cout << endl;
		color(15);
		break;
	default:
		break;
	}
	for (int i = 0; i < 40; i++) {
		cout << '-';
	}
	cout << endl;
}
void print_map(int sum)
{
	int a = 0;
	for (int i = 0; i < 20; i++) {
		if (map[i].flag == 0)
			cout << "□";
		else
		{
			color(print_color1(map[i].plane_color));
			cout << map[i].plane_color;
			color(15);
		}
	}
	cout << endl ;
	for (int i = 0; i < 20; i++) {
		if (map[i].plane_num > 1)
cout << "在第"<<i+1<<"格上有" << map[i].plane_num << "个相同颜色的棋子" << endl;	}
	for (int i = 0; i < 40; i++) {
		cout << '-';
	}
	cout << endl;
	for (int i = 0; i < sum; i++) {
		for (int j = 0; j < 6; j++) {
			if (airport[i][j].flag == 0)
				cout << "〇";
			else {
				color(print_color2(i));
				cout <<" " << airport[i][j].color;
				color(15);
			}
		}
		color(print_color2(a));
		a++;
		cout << " DESTINATION";
		color(15);
		cout << endl;
	}
	for (int i = 0; i < sum; i++) {
		for (int j = 0; j < 6; j++) {
			if (airport[i][j].plane_num > 1) {
				cout<< "在第"<<i+1<<"行，第" << j + 1 << "格上有" << airport[i][j].plane_num << "个相同颜色的棋子" << endl;
			}
		}
	}
	for (int i = 0; i < 40; i++) {
		cout << '-';
	}
	cout << endl;
	for (int i = 1; i < 5; i++) {
		if (yellow[i].flag == 2)cout << "黄色第" << i << "个棋子已到达终点"<<endl;
		if (red[i].flag == 2)cout << "红色第" << i << "个棋子已到达终点"<<endl;
		if (blue[i].flag == 2)cout << "蓝色第" << i << "个棋子已到达终点"<<endl;
		if (green[i].flag == 2)cout << "绿色第" << i << "个棋子已到达终点"<<endl;
	}
	for (int i = 0; i < 40; i++) {
		cout << '-';
	}
	cout << endl;
}
void init_plane(int sum)
{
	for (int i = 1; i <= 4; i++){
		yellow[i] = {0, 0,'Y'};
		red[i] = {0, 0,'R' };
		blue[i] = {0, 0,'B' };
		green[i] = {0, 0,'G' };
	}
	print_plane(sum);
}
void init_map(int sum)
{
	for (int i = 0; i < 20; i++){
		map[i].flag = 0;
		map[i].plane_num = 0;
	}
	for (int i = 0; i < 6; i++){
		airport[0][i].flag = 0;
		airport[1][i].flag = 0;
		airport[2][i].flag = 0;
		airport[3][i].flag = 0;
	}
	print_map(sum);
}