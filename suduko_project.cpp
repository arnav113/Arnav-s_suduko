#include<iostream>
#include <stdlib.h>
using namespace std;
#define n 9

void display(int a[n][n])
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<<a[i][j]<<"   ";

        cout<<endl;
	}
}

int valid(int m[n][n], int r, int c, int num)
{
	for (int k = 0;k<= 8;k++)
		if (m[r][k] == num)
			return 0;
	for (int k = 0;k<= 8; k++)
		if (m[k][c] == num)
			return 0;
	int Row = r - r % 3, 
				Col = c - c % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (m[i + Row][j + 
						Col] == num)
				return 0;

	return 1;
}

int operate(int m[n][n], int r, int c)
{
		if (r == n - 1 && c== n)
		return 1;
	if (c == n) 
	{
		r++;
		c = 0;
	}
	if (m[r][c] > 0)
		return operate(m, r, c + 1);
	for (int i= 1;i<= n;i++) 
	{
		if (valid(m, r, c,i)==1) 
		{
			m[r][c] = i;
			if (operate(m, r, c + 1) ==1)
				return 1;
		}
		m[r][c] = 0;
	}
	return 0;
}

int main()
{
	int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }
	if (operate(m, 0, 0)==1)
		display(m);
	else
        cout<<"Enter a valid sudoku!!!"<<endl;
	return 0;
	

}