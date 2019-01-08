#include<iostream>
#include<fstream>
using namespace std;

fstream f;

void DocFile(int a[],int b[],int c[])
{
	f.open("dulieu.txt", ios::in);
	for(int i = 0; i < 5; i++)
		f >> a[i];
	for(int i = 0; i < 5; i++)
		f >> b[i];
	for(int i = 0; i < 5; i++)
		f >> c[i];
	f.close();
}

void SapXep(int a[], int b[], int c[], int n)
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

void XepLich(int a[], int b[], int c[], int n)
{
	f.open("dulieu2.txt", ios::out);
	SapXep(a, b, c, 5);
	int t = 0;
	t = b[0];
	f << a[0] << " ";
	for(int i = 0; i < 5; i++)
	{
		if(c[i] >= t + b[i])
		{
			t += b[i];
			f << a[i] << " ";
		}
	}
	f.close();
}

void XuatThuTu()
{
	cout << "Thu tu sua chua oto dung han :" << endl;
	string s;
	ifstream f("dulieu2.txt");
	getline(f, s);
	do
	{
		cout << s << endl;
		getline(f, s);
	}
	while(f.eof()==false);
	f.close();
}

int main()
{
	int a[20], b[20], c[20];
	
	DocFile(a, b, c);
	
	XepLich(a, b, c, 5);
	XuatThuTu();
}
