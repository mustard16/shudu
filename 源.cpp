#include <iostream>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include<windows.h>
#include<fstream>
using namespace std;
int a[15][15], ans_pre, ans[15][15], b[15][15];
bool square[10][10], col[10][10], row[10][10], flag[15][15];
bool check;
bool f[15];
int c[15];
int difficult;

void SetColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor | BackGroundColor);
}//用于设置控制台输出文本的颜色
int ge(int x, int y)
{
	return(((x - 1) / 3) * 3 + (y - 1) / 3 + 1);
}//给定坐标所在的小九宫格的编号

int print() {
	SetColor(15);
	printf("╔━━━┳━━━┳━━━");
	SetColor(9);
	printf("┳");
	SetColor(15);
	printf("━━━┳━━━┳━━━");
	SetColor(9);
	printf("┳");
	SetColor(15);
	printf("━━━┳━━━┳━━━┓\n");
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (a[i][j] == 0)
			{
				if (j == 4 || j == 7) SetColor(9);
				cout << "┃   ";
				SetColor(15);
				if (j == 9)  cout << "┃";
			}
			else
			{
				if (j == 4 || j == 7) SetColor(9);
				cout << "┃ ";
				SetColor(15);
				if (b[i][j] == 0) SetColor(4);
				cout << a[i][j] << " ";
				SetColor(15);
				if (j == 9) cout << "┃";
			}
		}
		cout << endl;
		if (i == 3 || i == 6)
		{
			SetColor(9);
			cout << "┣━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━┫";
			cout << endl;
			continue;
		}
		if (i != 9)
		{
			cout << "┣━━━╋━━━╋━━━";
			SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━";
			SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━┫";
			cout << endl;
		}

		else
		{
			SetColor(15);
			printf("┗━━━┻━━━┻━━━");
			SetColor(9);
			printf("┻");
			SetColor(15);
			printf("━━━┻━━━┻━━━");
			SetColor(9);
			printf("┻");
			SetColor(15);
			printf("━━━┻━━━┻━━━┛\n");
		}
		SetColor(15);
	}
	return 0;
}

int print_y() {
	SetColor(15);
	printf("╔━━━┳━━━┳━━━");
	SetColor(9);
	printf("┳");
	SetColor(15);
	printf("━━━┳━━━┳━━━");
	SetColor(9);
	printf("┳");
	SetColor(15);
	printf("━━━┳━━━┳━━━┓\n");
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (ans[i][j] == 0)
			{
				if (j == 4 || j == 7) SetColor(9);
				cout << "┃   ";
				SetColor(15);
				if (j == 9)  cout << "┃";
			}
			else
			{
				if (j == 4 || j == 7) SetColor(9);
				cout << "┃ ";
				SetColor(15);
				if (b[i][j] == 0) SetColor(4);
				cout << ans[i][j] << " ";
				SetColor(15);
				if (j == 9) cout << "┃";
			}
		}
		cout << endl;
		if (i == 3 || i == 6)
		{
			SetColor(9);
			cout << "┣━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━┫";
			cout << endl;
			continue;
		}
		if (i != 9)
		{
			cout << "┣━━━╋━━━╋━━━";
			SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━";
			SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━┫";
			cout << endl;
		}

		else
		{
			SetColor(15);
			printf("┗━━━┻━━━┻━━━");
			SetColor(9);
			printf("┻");
			SetColor(15);
			printf("━━━┻━━━┻━━━");
			SetColor(9);
			printf("┻");
			SetColor(15);
			printf("━━━┻━━━┻━━━┛\n");
		}
		SetColor(15);
	}
	return 0;
}
int dfs(int x, int y)
{
	if (!check) return 0;
	if (x == 0 && y == 9)
	{
		check = false;
		return 0;
	}
	if (a[x][y] == 0)
		for (int j = 1; j <= 9; j++)
		{
			int i = c[j];
			if (square[ge(x, y)][i] && col[y][i] && row[x][i])
			{
				square[ge(x, y)][i] = false;
				col[y][i] = false;
				row[x][i] = false;
				ans[x][y] = i;

				if (y == 1)
				{
					dfs(x - 1, 9);
				}
				else 
					dfs(x, y - 1);

				square[ge(x, y)][i] = true;
				col[y][i] = true;
				row[x][i] = true;
				if (!check) return 0;
			}
		}
	if (!check) return 0;
	if (a[x][y] != 0)
	{
		if (y == 1) 
			dfs(x - 1, 9);
		else dfs(x, y - 1);
	}
}//通过判断当前格子是否为空，然后尝试填入数字并进行递归调用。如果填充成功，就继续填充下一个格子

int work(int x) {
	if (x == 10)
	{
		return 0;
	}
	int i = 1;
	int y = rand() % 9 + 1;
	while (!f[y]) 
		y = rand() % 9 + 1;
	f[y] = false;
	c[x] = y;
	work(x + 1);
}//生成一个随机的数独初始状态，通过随机选择数字填充格子，保证每个数字在每行每列每个小九宫格中只出现一次。

void init() {
	srand(time(NULL));
	memset(a, 0, sizeof(a));
	memset(col, true, sizeof(col));
	memset(row, true, sizeof(row));
	memset(square, true, sizeof(square));
	memset(f, true, sizeof(f));
	check = true;
	work(1);
	memset(a, sizeof(a), 0);
	check = true;
	dfs(9, 9);
	memcpy(a, ans, sizeof(ans));
	
}//生成随机初始状态和设置游戏难度
void run() {
	int sum = 0;
	switch (difficult) {
	case 1:sum = 20;
		break;
	case 2:sum = 40;
		break;
	case 3:sum = 60;
		break;

	}
	int i = 1;
	while (i <= sum)
	{
		int x, y;
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		while (a[x][y] == 0)
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
		}
		a[x][y] = 0;
		i++;
	}
}//根据设定的游戏难度，随机挖空一些格子，形成玩家需要填写的数独题目

void generateSudokuToFile(const string& filename, int num)
{
	ofstream outFile(filename);
	if (!outFile)
	{
		cout << "Failed to open the file." << endl;
		return;
	}

	for (int k = 0; k < num; k++)
	{
		init();
		run();
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (a[i][j] != 0) {
					outFile << a[i][j] << " ";
				}
				else
					outFile << '_' << " ";
			}
			outFile << endl;
		}

		outFile << endl;
	}

	outFile.close();
}

int main()
{
	int num;
	cout << "Enter the number of Sudoku puzzles to generate: ";
	cin >> num;

	printf("Please Keydowm the Difficulty you like 1~3\n");
	difficult = 0;
	while (difficult > 3 || difficult < 1) cin >> difficult;

	string filename = "sudoku_puzzles.txt";
	generateSudokuToFile(filename, num);

	cout << "Sudoku puzzles generated and saved to file !" << endl;
	return 0;
}
 


