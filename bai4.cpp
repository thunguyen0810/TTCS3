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

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void LuuKQ(int a[], int n)
{
	f.open("dulieu2.txt", ios::out | ios::app);
	for(int i = 0; i < n; i++)
		f << a[i] << " ";
	f << endl;
	f.close();
}

int main()
{
	int a[20], b[20], c[20];
	
	DocFile(a, b, c);

	cout << "Thu tu sua chua o to de giao dung han " << endl;
	cout << endl;
	
	SapXep(a, b, c, 5);
	XuatMang(a, 5);
	LuuKQ(a, 5);
	XuatMang(b, 5);
	LuuKQ(b, 5);
	XuatMang(c, 5);
	LuuKQ(c, 5); 
	
}
