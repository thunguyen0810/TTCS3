#include<iostream>
#include<fstream>
using namespace std;

fstream f;

void NhapMT(int a[10][10], int n, int m)
{
	cout << "Nhap n : ";
	cin >> n;
	
	cout << endl;
	
	cout << "Nhap m : ";
	cin >> m;
	
	cout << endl;
	
	f.open("input2.txt", ios::out | ios::app);
	cout << "Nhap cac phan tu trong ma tran : " << endl;
	cout << endl;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << "a[" << i << "][" << j << "] : ";
			cin >> a[i][j];
			f << a[i][j] << " ";
		}
		f << endl;
	}
	f << "---------------------------" << endl;
	f.close();
}

void XuatMT(int a[10][10], int n, int m)
{
	string s;
	ifstream f("input2.txt");
	getline(f, s);// lay phan so tu file input2.txt
	// vong lap
	do
	{
		cout << s << endl;
		getline(f, s);
	}while(s.compare("") != 0);// neu dong cuoi cung trong file khong co gi het thi ket thuc viet doc
	f.close();	
}

void DocFile(int a[10][10], int n, int m)
{
	f.open("input2.txt", ios::in); 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			f >> a[i][j];
	f.close();
}

void LuuKQ(int a[10][10], int n, int m)
{
	f.open("output2.txt", ios::out | ios::app);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			f << a[i][j] << " ";
		f << endl;
	}
	f.close();
}

void CongMT(int a[10][10], int b[10][10], int c[10][10], int n, int m)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i][j] = a[i][j] + b[i][j];
	LuuKQ(c, n, m);
}

void TruMT(int a[10][10], int b[10][10], int c[10][10], int n, int m)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i][j] = a[i][j] - b[i][j];
	LuuKQ(c, n, m);
}

void NhanMT(int a[10][10], int b[10][10], int c[10][10], int n, int m)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			c[i][j] = 0;
			for(int k = 0; k < m; k++)
				c[i][j] += a[i][j] * b[i][j];
		}
	LuuKQ(c, n, m);
}

int main()
{
	int A[10][10], B[10][10], C[10][10], n, m;
	
	cout << "Ma tran thu nhat : " << endl;
	cout << endl;
	NhapMT(A, n, m);
	
	DocFile(A, n, m);
	
	cout << "Ma tran thu hai : " << endl;
	cout << endl;
	NhapMT(B, n, m);
	
	DocFile(B, n, m);
	
	CongMT(A, B, C, n, m);
	
	TruMT(A, B, C, n, m);
	
	NhanMT(A, B, C, n, m);
}
