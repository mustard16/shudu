#include <iostream>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;
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
}//�������ÿ���̨����ı�����ɫ
int ge(int x, int y)
{
	return(((x - 1) / 3) * 3 + (y - 1) / 3 + 1);
}//�����������ڵ�С�Ź���ı��

int print() {
	SetColor(15);
	printf("�X�������ש������ש�����");
	SetColor(9);
	printf("��");
	SetColor(15);
	printf("�������ש������ש�����");
	SetColor(9);
	printf("��");
	SetColor(15);
	printf("�������ש������ש�������\n");
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (a[i][j] == 0)
			{
				if (j == 4 || j == 7) SetColor(9);
				cout << "��   ";
				SetColor(15);
				if (j == 9)  cout << "��";
			}
			else
			{
				if (j == 4 || j == 7) SetColor(9);
				cout << "�� ";
				SetColor(15);
				if (b[i][j] == 0) SetColor(4);
				cout << a[i][j] << " ";
				SetColor(15);
				if (j == 9) cout << "��";
			}
		}
		cout << endl;
		if (i == 3 || i == 6)
		{
			SetColor(9);
			cout << "�ǩ������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈������";
			cout << endl;
			continue;
		}
		if (i != 9)
		{
			cout << "�ǩ������贈�����贈����";
			SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈����";
			SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈������";
			cout << endl;
		}

		else
		{
			SetColor(15);
			printf("���������ߩ������ߩ�����");
			SetColor(9);
			printf("��");
			SetColor(15);
			printf("�������ߩ������ߩ�����");
			SetColor(9);
			printf("��");
			SetColor(15);
			printf("�������ߩ������ߩ�������\n");
		}
		SetColor(15);
	}
	return 0;
}

int print_ans(vector<vector<char>>& ans) {
	SetColor(15);
	printf("�X�������ש������ש�����");
	SetColor(9);
	printf("��");
	SetColor(15);
	printf("�������ש������ש�����");
	SetColor(9);
	printf("��");
	SetColor(15);
	printf("�������ש������ש�������\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (ans[i][j] == '_')
			{
				if (j == 3 || j == 6) SetColor(9);
				cout << "��   ";
				SetColor(15);
				if (j == 8)  cout << "��";
			}
			else
			{
				if (j == 3 || j == 6) SetColor(9);
				cout << "�� ";
				SetColor(15);
				if (b[i][j] == 0) SetColor(4);
				cout << ans[i][j] << " ";
				SetColor(15);
				if (j == 8) cout << "��";
			}
		}
		cout << endl;
		if (i == 2 || i == 5)
		{
			SetColor(9);
			cout << "�ǩ������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈������";
			cout << endl;
			continue;
		}
		if (i != 8)
		{
			cout << "�ǩ������贈�����贈����";
			SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈����";
			SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈������";
			cout << endl;
		}

		else
		{
			SetColor(15);
			printf("���������ߩ������ߩ�����");
			SetColor(9);
			printf("��");
			SetColor(15);
			printf("�������ߩ������ߩ�����");
			SetColor(9);
			printf("��");
			SetColor(15);
			printf("�������ߩ������ߩ�������\n");
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
}//ͨ���жϵ�ǰ�����Ƿ�Ϊ�գ�Ȼ�����������ֲ����еݹ���á�������ɹ����ͼ��������һ������

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
}//����һ�������������ʼ״̬��ͨ�����ѡ�����������ӣ���֤ÿ��������ÿ��ÿ��ÿ��С�Ź�����ֻ����һ�Ρ�

void init() {
	auto duration_since_epoch = system_clock::now().time_since_epoch();
	auto microseconds_since_epoch = duration_cast<microseconds>(duration_since_epoch).count();
	srand(microseconds_since_epoch);
	//srand(time(0));
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
	
}//���������ʼ״̬��������Ϸ�Ѷ�
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
}//�����趨����Ϸ�Ѷȣ�����ڿ�һЩ���ӣ��γ������Ҫ��д��������Ŀ

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

bool isValid(int row, int col, char val, vector<vector<char>>& board) {
	for (int i = 0; i < 9; i++) { // �ж������Ƿ��ظ�
		if (board[row][i] == val) {
			return false;
		}
	}
	for (int j = 0; j < 9; j++) { // �ж������Ƿ��ظ�
		if (board[j][col] == val) {
			return false;
		}
	}
	int startRow = (row / 3) * 3;
	int startCol = (col / 3) * 3;
	for (int i = startRow; i < startRow + 3; i++) { // �ж�9�������Ƿ��ظ�
		for (int j = startCol; j < startCol + 3; j++) {
			if (board[i][j] == val) {
				return false;
			}
		}
	}
	return true;
}

bool backtracking(vector<vector<char>>& board) {
	for (int i = 0; i < board.size(); i++) {        // ������
		for (int j = 0; j < board[0].size(); j++) { // ������
			if (board[i][j] != '_') continue;
			for (char k = '1'; k <= '9'; k++) {     // (i, j) ���λ�÷�k�Ƿ����
				if (isValid(i, j, k, board)) {
					board[i][j] = k;                // ����k
					if (backtracking(board)) return true; // ����ҵ�����һ�����̷���
					board[i][j] = '_';              // ���ݣ�����k
				}
			}
			return false;                           // 9�����������ˣ������У���ô�ͷ���false
		}
	}
	return true; // ������û�з���false��˵���ҵ��˺�������λ����
}

void solveSudoku(vector<vector<char>>& board) {
	backtracking(board);
}



int main()
{
	/*int num;
	cout << "Enter the number of Sudoku puzzles to generate: ";
	cin >> num;
	printf("Please Keydowm the Difficulty you like 1~3\n");
	difficult = 0;
	while (difficult > 3 || difficult < 1) cin >> difficult;

	string filename = "sudoku_puzzles.txt";
	
	generateSudokuToFile(filename, num);

	cout << "Sudoku puzzles generated and saved to file !" << endl;*/
	difficult = 0;
	while (difficult > 3 || difficult < 1) cin >> difficult;

	init();
	run();
	print();
	vector<vector<char>> board(9,vector<char>(9,'_'));
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (a[i][j] != 0)
			{
				board[i - 1][j - 1] = '0' + a[i][j];
			}
		}
	}
	solveSudoku(board);
	/*for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
	print_ans(board);
	return 0;
}
 

