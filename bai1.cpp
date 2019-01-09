#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <windows.h>
using namespace std;

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void SapXep(int a[8])
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if(a[i] < a[j])
				swap(a[i], a[j]);
}

void Vietllot(int a[6])
{
	srand(time(NULL));
    for(int i = 0; i < 6; i++)
    {
    	a[i + 1] = rand() % 56;
	}
	SapXep(a);
	for(int i = 0; i < 6; i++)
	{
		textcolor(12);
		cout << a[i] << "\t";
		textcolor(15);
	}
}

void KiemTra(int a[7],int b[7],int sdb)
{
	int m = 0, kt = 0; 
	for(int i = 0; i < 6 ; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(a[i] == b[j])
				m++;		
		}
	}
	if(m == 6)
		cout << "BAN DA TRUNG JACKPOT 1!" << endl;
	else
		if(m == 4) 
			cout << "BAN DA TRUNG GIAI NHI!" << endl;
		else
			if(m == 3) 
				cout << "BAN DA TRUNG GIAI BA!" << endl;
			else
				if(m == 5)
				{
					for(int i = 0; i < 6; i++)
					{
						if(b[i] == sdb)
						{
							cout << "BAN DA TRUNG JACKPOT 2!" << endl;
							break;
						}
						else
							cout << "BAN DA TRUNG GIAI NHAT!" << endl;
					}
				}
				else
					cout << "CHUC BAN MAY MAN LAN SAU !!!!!!" << endl;
}

int main()
{
	int a[6];
	int b[6];
	
	textcolor(11);
	cout << "Ket qua Vietllot hom nay : " << "\n";
	textcolor(15);
	Vietllot(a);
	int sdb = 1 + rand() % 55;
	
	textcolor(12);
	cout << " |\t";
	textcolor(15);
	textcolor(14);
	cout << sdb << endl;
	textcolor(15);
	
	textcolor(13);
	cout << "Nhap vao cac so trong ve cua ban ";
	cout << endl;
	for(int i = 1; i < 7; i++)
	{
		do
		{
			cout << "So thu " << i << " : ";
			cin >> b[i];
		}
		while((b[i] >= 55) || (b[i] < 0));
	}
	
	cout << "Day so cua ban la : " << endl;
	for(int i = 1; i < 7; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	
	KiemTra(a, b, sdb);
	
	cout << "\n";
    cout << "---------------------------------------------------------------" << endl;
}
