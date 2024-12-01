#include <iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y,fx,fy,score;
int tx[100], ty[100];
int nt;
enum eDirection {stop = 0, Left , Right, up , down};
eDirection dir;
void setup()
{
	gameover = false;
	dir = stop;
	x = width / 2;
	y = height / 2;
	fx = rand() % width;
	fy = rand() % height;
	score = 0;
}
void drawing()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			    cout << "#";
			if (i == y && j == x)
				cout << "o";
			else if (i == fy && j == fx)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0;k<nt;k++)
				{
					
					if (tx[k] == j && ty[k] == i)
					{
						cout << "o";
						print = true;
					}
					
				}					
				if (!print)
					cout << " ";
			}				
				if (j == width - 1)
					cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
	cout << "SCORE:" << score << endl;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = Left;
			break;
		case 's':
			dir = down;
			break;
		case 'd':
			dir = Right;
			break;
		case 'w':
			dir = up;
			break;
		case 'x':
			gameover=true;
			break;
		}
	}
}
void logic()
{
	int px = tx[0];
	int py = ty[0];
	int p2x;
	int p2y;
	tx[0] = x;
	ty[0] = y;
	for (int i = 1; i < nt; i++)
	{
		p2x = tx[0];
		p2y = ty[0];
		tx[i] = px;
		ty[i] = py;
		px = p2x;
		py = p2y;
	}
	switch (dir)
	{
	    case Left:
		x--;
		   break;
		case Right:
			x++;
			break;
		case up:
			y--;
			break;
		case down:
			y++;
			break;
		default:
			break;
	}
	if (x > width || x<0 || y>height || y < 0)
		gameover = true;
	for (int p=0; p < nt; p++)
		if (tx[p] == x && ty[p] == y)
			gameover = true;
	if (x == fx && y == fy)
	{
		score += 10;
		fx = rand() % width;
		fy = rand() % height;
		nt++;
	}
}
int main()
{
	setup();
	while (!gameover)
	{
		drawing();
		input();
		logic();
	}
	return 0;
}