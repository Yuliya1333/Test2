#include <iostream>
using namespace std;
#include <cstdlib>

char a[3][3];

// ������ �������
void print ()
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << a[i][j] <<' ' ;
		}
		cout << endl;
	}
}

void player()
{
	
	int i,j;
	do
	{
		cout <<"Tvoi hod!"<< endl;
		cin >> i >> j;
	}	
	while(a[i][j]!='.');
	
	a[i][j] = 'x';
}

void computer()
{
	int i,j;
	// ������� ��������� ������� ��� ������
	do 
	{
		i = rand() % 3; // 0,1,2 ?
		j = rand() % 3; // 0,1,2 ?
	}
	while(a[i][j]!='.'); // ���� �� ������� � ������ ������
	
	a[i][j] = 'o';
}

// ��������� ����������� �� ����
bool end()
{
	for (int i=0; i<3; i++) 
	{
		for (int j=0; j<3; j++)
		{
			if(a[i][j] == '.') 
				return false;// ���� �� �����������
		}
	}
	return true;// �����������
}
int i,j;
bool win(char c)
{
	if(a[0][0]==c && a[0][1] == c && a[0][2]==c)
		return true;
	if(a[1][0]==c && a[1][1] == c && a[1][2]==c)
		return true;
	if(a[2][0]==c && a[2][1] == c && a[2][2]==c)
		return true;
	if(a[0][0]==c && a[1][0] == c && a[2][0]==c)
		return true;
	if(a[0][1]==c && a[1][1] == c && a[2][1]==c)
		return true;
	if(a[0][2]==c && a[1][2] == c && a[2][2]==c)
		return true;
	if(a[0][0]==c && a[1][1] == c && a[2][2]==c)
		return true;
	if(a[0][2]==c && a[1][1] == c && a[2][0]==c)
		return true;
	return false;
}



int main()
{
	int i, j;
	
	//������������� �������
	for (int i=0; i<3; i++) 
	{
		for (int j=0; j<3; j++)
		{
			a[i][j] = '.';
		}
	}
	// ������ �������, ������� ���� �� ���� �������� �� �����, ������� ������ �������� ���� �����������, ������� ��� ����� �������� �� �����
	print();

	for(int k=0; k<=4; k++)// ������� �����
	{
		player();
		if(win('x')) { cout << "x won!"; break; }
		if(end()) { cout << "draw!"; break; }
		
		computer();				
		
		if(win('o')) { cout << "o won!"; break; }
		if(end()) { cout << "draw!"; break; }
		
		print();
	}
	
	cout << endl;
	print();
}



