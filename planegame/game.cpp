#define _CRT_SECURE_NO_WARNINGS 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <cwchar>
#include "struct.h"
#define DEBUG
using namespace std;
extern plane yellow[5], red[5], blue[5], green[5];
extern Map map[20];
extern Airport airport[5][7];
int get_dice(){
#ifdef DEBUG
	{int b;
cin >> b;
return b;
}
#else
	{srand((unsigned)time(NULL));
int a = rand() % 6 + 1;
return a;
}
#endif
}

plane *transform(char color)
{
	switch (color)
	{
	case 'Y':
		return yellow;
		break;
	case 'R':
		return red;
		break;
	case 'B':
		return blue;
		break;
	case 'G':
		return green;
		break;
	default:
		break;
	}
}
void judge_overlay(int num, plane *plane, int x)
{
	if (plane[x].num < 20)
	{
		if (map[plane[x].num].plane_num > 1)
		{
			int i;
			for (i = 1; i < 5; i++)
			{
				if (transform(map[plane[x].num].plane_color)[i].num == plane[x].num && transform(map[plane[x].num].plane_color) != plane)
				{
					transform(map[plane[x].num].plane_color)[i].flag = 0;
					transform(map[plane[x].num].plane_color)[i].num = 0;
					map[plane[x].num].plane_num = 1;
				}
			}
		}
	}
	else
	{
		if (airport[color_num(plane[x].color)][plane[x].num - 20].plane_num > 1)
		{
			int i;
			for (i = 1; i < 5; i++)
			{
				if (transform(airport[color_num(plane[x].color)][plane[x].num - 20].color)[i].num == plane[x].num && transform(airport[color_num(plane[x].color)][plane[x].num - 20].color) != plane)
				{
					transform(airport[color_num(plane[x].color)][plane[x].num - 20].color)[i].flag = 0;
					transform(airport[color_num(plane[x].color)][plane[x].num - 20].color)[i].num = 0;
					airport[color_num(plane[x].color)][plane[x].num - 20].plane_num = 1;
				}
			}
		}
	}
}
void change(plane plane[], int dicepoint, bool is_computer)
{
	if (!is_computer)
	{
		if (plane[1].flag != 1 && plane[2].flag != 1 && plane[3].flag != 1 && plane[4].flag != 1)
		{
			if (dicepoint == 6)
			{
				int x;
				while (1)
				{
					cout << "请选择一个棋子出发:>";
					cin >> x;
					if (x > 0 && x < 5 && plane[x].flag == 0)
					{
						plane[x].flag = 1;
						int dice;
						cout << "请再投掷一次骰子" << endl;
						system("pause");
						dice = get_dice();
						plane[x].num += dice;
						cout << "棋子" << x << "号前进" << dice << "格" << endl;
						if (plane[x].num < 20)
						{
							map[plane[x].num].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							map[plane[x].num].flag = 1;
							map[plane[x].num].plane_color = plane[x].color;
						}
						if (plane[x].num >= 20)
						{
							if (plane[x].num < 26)
							{
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
								airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
							}
							else if (plane[x].num == 26)
							{
								plane[x].flag = 2;
								cout << "棋子" << x << "到达终点" << endl;
							}
							else
							{
								plane[x].num = 52 - plane[x].num;
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
								airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
							}
						}
						break;
					}
					else
					{
						cout << "请选择1~4之间的一个数字,且该数字对应的棋子未出发" << endl;
					}
				}
			}
			else
				cout << "运气不好，无法出发，请等待" << endl;
		}
		else
		{
			if (dicepoint == 6)
			{
				int x;
				if (plane[1].flag == 0 || plane[2].flag == 0 || plane[3].flag == 0 || plane[4].flag == 0)
				{
					while (1)
					{
						cout << "请选择一个棋子出发:>";
						cin >> x;
						if (x > 0 && x < 5 && plane[x].flag == 0)
						{
							plane[x].flag = 1;
							int dice;
							cout << "请再投掷一次骰子" << endl;
							system("pause");
							dice = get_dice();
							plane[x].num += dice;
							cout << "棋子" << x << "号前进" << dice << "格" << endl;
							if (plane[x].num < 20)
							{
								map[plane[x].num].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								map[plane[x].num].flag = 1;
								map[plane[x].num].plane_color = plane[x].color;
							}
							if (plane[x].num >= 20)
							{
								if (plane[x].num < 26)
								{
									airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
									airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
								}
								else if (plane[x].num == 26)
								{
									plane[x].flag = 2;
									cout << "棋子" << x << "到达终点" << endl;
								}
								else
								{
									plane[x].num = 52 - plane[x].num;
									airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
									airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
								}
							}
							break;
						}
						else
						{
							cout << "请选择1~4之间的一个数字,且该数字对应的棋子未出发" << endl;
						}
					}
				}
				else
				{
					while (1)
					{
						cout << "请选择一个棋子前进:>";
						cin >> x;
						if (x > 0 && x < 5 && plane[x].flag == 1)
						{
							if (plane[x].num < 20)
							{
								map[plane[x].num].plane_num--;
								if (map[plane[x].num].plane_num == 0)
									map[plane[x].num].flag = 0;
								plane[x].num += dicepoint;
								if (plane[x].num < 20)
								{
									map[plane[x].num].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									map[plane[x].num].flag = 1;
									map[plane[x].num].plane_color = plane[x].color;
								}
								if (plane[x].num >= 20)
								{
									if (plane[x].num < 26)
									{
										airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
										judge_overlay(plane[x].num, plane, x);
										airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
										airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
									}
									else if (plane[x].num == 26)
									{
										plane[x].flag = 2;
										cout << "棋子" << x << "到达终点" << endl;
									}
									else
									{
										plane[x].num = 52 - plane[x].num;
										airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
										judge_overlay(plane[x].num, plane, x);
										airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
										airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
									}
								}
							}
							else
							{
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num--;
								if (airport[color_num(plane[x].color)][plane[x].num - 20].plane_num == 0)
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 0;
								plane[x].num += dicepoint;
								if (plane[x].num < 26)
								{
									airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
									airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
								}
								else if (plane[x].num == 26)
								{
									plane[x].flag = 2;
									cout << "棋子" << x << "到达终点" << endl;
								}
								else
								{
									plane[x].num = 52 - plane[x].num;
									airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
									airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
								}
							}
							break;
						}
						else
							cout << "请选择1~4之间的一个数字:>";
					}
				}
			}
			else
			{
				int x;
				while (1)
				{
					cout << "请选择一个棋子前进:>";
					cin >> x;
					if (x > 0 && x < 5 && plane[x].flag == 1)
					{
						if (plane[x].num < 20)
						{
							map[plane[x].num].plane_num--;
							if (map[plane[x].num].plane_num == 0)
								map[plane[x].num].flag = 0;
							plane[x].num += dicepoint;
							if (plane[x].num < 20)
							{
								map[plane[x].num].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								map[plane[x].num].flag = 1;
								map[plane[x].num].plane_color = plane[x].color;
							}
							if (plane[x].num >= 20)
							{
								if (plane[x].num < 26)
								{
									airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
									airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
								}
								else if (plane[x].num == 26)
								{
									plane[x].flag = 2;
									cout << "棋子" << x << "到达终点" << endl;
								}
								else
								{
									plane[x].num = 52 - plane[x].num;
									airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
									judge_overlay(plane[x].num, plane, x);
									airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
									airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
								}
							}
						}
						else
						{
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num--;
							if (airport[color_num(plane[x].color)][plane[x].num - 20].plane_num == 0)
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 0;
							plane[x].num += dicepoint;
							if (plane[x].num < 26)
							{
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
								airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
							}
							else if (plane[x].num == 26)
							{
								plane[x].flag = 2;
								cout << "棋子" << x << "到达终点" << endl;
							}
							else
							{
								plane[x].num = 52 - plane[x].num;
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
								airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
							}
						}
						break;
					}
					else
						cout << "请选择1~4之间的一个数字,且该数字对应的棋子已经出发:>";
				}
			}
		}
	}
	else
	{
		srand((unsigned)time(NULL));
		if (plane[1].flag != 1 && plane[2].flag != 1 && plane[3].flag != 1 && plane[4].flag != 1)
		{
			if (dicepoint == 6)
			{
				int x = rand() % 4 + 1;
				cout << "电脑选择了" << x << "棋子出发" << endl;
				plane[x].flag = 1;
				int dice;
				cout << "请电脑再投掷一次骰子" << endl;
				Sleep(1000);
				dice = get_dice();
				plane[x].num += dice;
				cout << "棋子" << x << "号前进" << dice << "格" << endl;
				if (plane[x].num < 20)
				{
					map[plane[x].num].plane_num++;
					judge_overlay(plane[x].num, plane, x);
					map[plane[x].num].flag = 1;
					map[plane[x].num].plane_color = plane[x].color;
				}
				if (plane[x].num >= 20)
				{
					if (plane[x].num < 26)
					{
						airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
						judge_overlay(plane[x].num, plane, x);
						airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
						airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
					}
					else if (plane[x].num == 26)
					{
						plane[x].flag = 2;
						cout << "棋子" << x << "到达终点" << endl;
					}
					else
					{
						plane[x].num = 52 - plane[x].num;
						airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
						judge_overlay(plane[x].num, plane, x);
						airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
						airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
					}
				}
			}
			else
				cout << "运气不好，无法出发，请等待" << endl;
		}
		else
		{
			if (dicepoint == 6)
			{
				if (plane[1].flag == 0 || plane[2].flag == 0 || plane[3].flag == 0 || plane[4].flag == 0)
				{
					int x = rand() % 4 + 1;
					while (1)
					{
						if (plane[x].flag == 0)
						{
							cout << "电脑选择了" << x << "棋子出发" << endl;
							plane[x].flag = 1;
							break;
						}
						else
							x = rand() % 4 + 1;
					}
					int dice;
					cout << "请电脑再投掷一次骰子" << endl;
					Sleep(1000);
					dice = get_dice();
					plane[x].num += dice;
					cout << "棋子" << x << "号前进" << dice << "格" << endl;
					if (plane[x].num < 20)
					{
						map[plane[x].num].plane_num++;
						judge_overlay(plane[x].num, plane, x);
						map[plane[x].num].flag = 1;
						map[plane[x].num].plane_color = plane[x].color;
					}
					if (plane[x].num >= 20)
					{
						if (plane[x].num < 26)
						{
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
							airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
						}
						else if (plane[x].num == 26)
						{
							plane[x].flag = 2;
							cout << "棋子" << x << "到达终点" << endl;
						}
						else
						{
							plane[x].num = 52 - plane[x].num;
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
							airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
						}
					}
				}
				else
				{
					int x = rand() % 4 + 1;
					while (1)
					{
						if (plane[x].flag == 1)
						{
							cout << "电脑选择了棋子" << x << "号前进" << endl;
							break;
						}
						else
						{
							x = rand() % 4 + 1;
						}
					}
					if (plane[x].num < 20)
					{
						map[plane[x].num].plane_num--;
						if (map[plane[x].num].plane_num == 0)
							map[plane[x].num].flag = 0;
						plane[x].num += dicepoint;
						if (plane[x].num < 20)
						{
							map[plane[x].num].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							map[plane[x].num].flag = 1;
							map[plane[x].num].plane_color = plane[x].color;
						}
						if (plane[x].num >= 20)
						{
							if (plane[x].num < 26)
							{
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
								airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
							}
							else if (plane[x].num == 26)
							{
								plane[x].flag = 2;
								cout << "棋子" << x << "到达终点" << endl;
							}
							else
							{
								plane[x].num = 52 - plane[x].num;
								airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
								judge_overlay(plane[x].num, plane, x);
								airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
								airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
							}
						}
					}
					if (plane[x].num >= 20 && plane[x].num < 26)
					{
						airport[color_num(plane[x].color)][plane[x].num - 20].plane_num--;
						if (airport[color_num(plane[x].color)][plane[x].num - 20].plane_num == 0)
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 0;
						plane[x].num += dicepoint;
						if (plane[x].num < 26)
						{
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
							airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
						}
						else if (plane[x].num == 26)
						{
							plane[x].flag = 2;
							cout << "棋子" << x << "到达终点" << endl;
						}
						else
						{
							plane[x].num = 52 - plane[x].num;
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
							airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
						}
					}
				}
			}
			else
			{
				int x = rand() % 4 + 1;
				while (1)
				{
					if (plane[x].flag == 1)
					{
						cout << "电脑选择了棋子" << x << "号前进" << endl;
						break;
					}
					else
					{
						x = rand() % 4 + 1;
					}
				}
				if (plane[x].num < 20)
				{
					map[plane[x].num].plane_num--;
					if (map[plane[x].num].plane_num == 0)
						map[plane[x].num].flag = 0;
					plane[x].num += dicepoint;
					if (plane[x].num < 20)
					{
						map[plane[x].num].plane_num++;
						judge_overlay(plane[x].num, plane, x);
						map[plane[x].num].flag = 1;
						map[plane[x].num].plane_color = plane[x].color;
					}
					if (plane[x].num >= 20)
					{
						if (plane[x].num < 26)
						{
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
							airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
						}
						else if (plane[x].num == 26)
						{
							plane[x].flag = 2;
							cout << "棋子" << x << "到达终点" << endl;
						}
						else
						{
							plane[x].num = 52 - plane[x].num;
							airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
							judge_overlay(plane[x].num, plane, x);
							airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
							airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
						}
					}
				}
				else
				{
					airport[color_num(plane[x].color)][plane[x].num - 20].plane_num--;
					if (airport[color_num(plane[x].color)][plane[x].num - 20].plane_num == 0)
						airport[color_num(plane[x].color)][plane[x].num - 20].flag = 0;
					plane[x].num += dicepoint;
					if (plane[x].num < 26)
					{
						airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
						judge_overlay(plane[x].num, plane, x);
						airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
						airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
					}
					else if (plane[x].num == 26)
					{
						plane[x].flag = 2;
						cout << "棋子" << x << "到达终点" << endl;
					}
					else
					{
						plane[x].num = 52 - plane[x].num;
						airport[color_num(plane[x].color)][plane[x].num - 20].plane_num++;
						judge_overlay(plane[x].num, plane, x);
						airport[color_num(plane[x].color)][plane[x].num - 20].flag = 1;
						airport[color_num(plane[x].color)][plane[x].num - 20].color = plane[x].color;
					}
				}
			}
		}
	}
}
void move(int player, bool is_computer)
{
	int dice = 0;
	switch (player)
	{
	case 0:
		dice = get_dice();
		cout << "玩家" << player + 1 << "掷出了" << dice << endl;
		system("pause");
		change(yellow, dice, is_computer);
		break;
	case 1:
		dice = get_dice();
		cout << "玩家" << player + 1 << "掷出了" << dice << endl;
		system("pause");
		change(red, dice, is_computer);
		break;
	case 2:
		dice = get_dice();
		cout << "玩家" << player + 1 << "掷出了" << dice << endl;
		system("pause");
		change(blue, dice, is_computer);
		break;
	case 3:
		dice = get_dice();
		cout << "玩家" << player + 1 << "掷出了" << dice << endl;
		system("pause");
		change(green, dice, is_computer);
		break;
	default:
		break;
	}
}
bool judge()
{
	bool judge = false;
	if (yellow[1].flag == 2 && yellow[2].flag == 2 && yellow[3].flag == 2 && yellow[4].flag == 2)
		judge = true;
	if (red[1].flag == 2 && red[2].flag == 2 && red[3].flag == 2 && red[4].flag == 2)
		judge = true;
	if (blue[1].flag == 2 && blue[2].flag == 2 && blue[3].flag == 2 && blue[4].flag == 2)
		judge = true;
	if (green[1].flag == 2 && green[2].flag == 2 && green[3].flag == 2 && green[4].flag == 2)
		judge = true;
	return judge;
}
void game()
{
	int players;
	int computers;
	int number = 0;
	bool game_ends = false;
	cout << "##############################################################################\n\n";
	cout << "##############################################################################\n\n";
	cout << "                              欢  乐  飞  行  棋\n\n";
	cout << "##############################################################################\n\n";
	cout << "##############################################################################\n\n";
	Sleep(1000);
	system("cls");
	while (1)
	{
		cout << "请输入玩家个数:>";
		cin >> players;
		cout << "请输入电脑个数:>";
		cin >> computers;
		if ((players + computers == 2 || players + computers == 3 || players + computers == 4) && players > 0 && computers > 0)
			break;
		else
		{
			system("cls");
			cout << "输入错误，请重新输入。" << endl;
		}
	}
	system("cls");
	cout << "游戏开始" << endl;
	system("pause");
	system("cls");
	init_plane(players + computers);
	init_map(players + computers);
	while (!game_ends)
	{
		number < players ? move(number, 0) : move(number, 1);
		Sleep(1500);
		system("cls");
		print_plane(players + computers);
		print_map(players + computers);
		number = (number + 1) % (players + computers);
		game_ends = judge();
	}
	system("cls");
	cout << "游戏结束!" << endl;
	Sleep(800);
}
int main()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 17; // Width of each character in the font
	cfi.dwFontSize.Y = 34; // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	game();
	return 0;
}