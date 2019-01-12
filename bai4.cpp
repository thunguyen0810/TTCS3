#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

fstream f;
int n;

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void DocFile(int a[],int b[],int c[])
{
	f.open("dulieu.txt", ios::in);
	f >> n;
	for(int i = 0; i < n; i++)
		f >> a[i];
	for(int i = 0; i < n; i++)
		f >> b[i];
	for(int i = 0; i < n; i++)
		f >> c[i];
	f.close();
}

void XuatFile(int a[],int b[],int c[])
{
	f.open("dulieu.txt", ios::in);
	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << c[i] << " ";
	cout << endl;
	f.close();
}

void SapXep(int a[], int b[], int c[])
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(c[i] > c[j])
			{
				swap(b[i], b[j]);
				swap(a[i], a[j]);
				swap(c[i], c[j]);
			}
}

void XepLich(int a[], int b[], int c[])
{
	f.open("dulieu2.txt", ios::out);
	SapXep(a, b, c);
	int t = 0;
	t = b[0];
	f << a[0] << " ";
	for(int i = 0; i < n; i++)
	{
		if(c[i] >= t + b[i])
		{
			t += b[i];
			f << a[i] << " ";
			c[i] = 0;
		}
	}
	int dem = 0;
	textcolor(10);
	cout << "Xe bi tre han : " << endl;
	textcolor(15);
	for(int i = 1; i < n; i++)
	{
		if(c[i] != 0)
		{
			textcolor(11);
			cout << a[i] << endl;
			textcolor(15);
			dem ++;
			f << endl << a[i];
		}
	}
	if(dem == 0)
	{
		textcolor(11);
		cout << "Khong co xe bi tre han" << endl;;
		textcolor(15);
	}
	f.close();
}

void XuatThuTu()
{
	textcolor(10);
	cout << endl;
	cout << "Thu tu sua chua oto dung han :" << endl;
	textcolor(15);
	string s;
	ifstream f("dulieu2.txt");
	getline(f, s);
	do
	{
		textcolor(11);
		cout << s << endl;
		textcolor(15);
		getline(f, s);
	}
	while(f.eof()==false);
	f.close();
}

int main()
{
	int a[20], b[20], c[20];
	
	DocFile(a, b, c);
	textcolor(10);
	cout << "O to duoc giao sua chua" << endl;
	textcolor(15);
	XuatFile(a, b, c);
	cout << endl;
	
	XepLich(a, b, c);
	XuatThuTu();
}
