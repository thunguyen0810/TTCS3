#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

fstream f;

void NhapMT(int *a, int *b, int *n, int *m)
{
	cout << "Nhap m : ";
	cin >> *m;
	
	cout << endl;
	
	cout << "Nhap n : ";
	cin >> *n;
	
	f.open("input2.txt", ios::out);
	cout << "Nhap cac phan tu trong ma tran 1: " << endl;
	cout << endl;
	
	for(int i = 0; i < *m; i++)
	{
		for(int j = 0; j < *n; j++)
		{
			cout << "a[" << i << "][" << j << "] : ";
			cin >> *(a + i * (*n) + j);
			f << *(a + i * (*n) + j) << " ";
		}
		f << endl;
	}
	f << endl;
	cout << "Nhap cac phan tu trong ma tran 2: " << endl;
	cout << endl;
	for(int i = 0; i < *m; i++)
	{
		for(int j = 0; j < *n; j++)
		{
			cout << "b[" << i << "][" << j << "] : ";
			cin >> *(b + i * (*n) + j);
			f << *(b + i * (*n) + j) << " ";
		}
		f << endl;
	}
	
	f.close();
}

void XuatMT()
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

void DocFile(int *a, int *n, int *m)
{
	f.open("input2.txt", ios::in); 
	for(int i = 0; i < *m; i++)
		for(int j = 0; j < *n; j++)
			f >> *(a + i * (*n) + j);
	f.close();
}

void LuuKQ(int *a, int *n, int *m)
{
	f.open("output2.txt", ios::out | ios::app);
	for(int i = 0; i < *m; i++)
	{
		for(int j = 0; j < *n; j++)
			f << *(a + i * (*n) + j) << " ";
		f << endl;	
	}
	f << endl;
	f.close();
}

void CongMT(int *a, int *b, int *c, int *n, int *m)
{
	for (int i = 0; i < *m; i++)
	{
        for (int j = 0; j < *n; j++)
		{
            *(c + i * (*n) + j) = *(a + i * (*n) + j) + *(b + i * (*n) + j);
        }
    }
    cout << "Hay mo file ouput2.txt de xem ket qua !\n";
    cout << endl;
}

void TruMT(int *a, int *b, int *c, int *n, int *m)
{
	for (int i=0; i<*m; i++)
	{
        for (int j=0; j<*n; j++)
		{
            *(c + i * (*n) + j) = *(a + i * (*n) + j) - *(b + i * (*n) + j);
        }
    }
    cout << "Hay mo file ouput2.txt de xem ket qua !\n";
    cout << endl;
}

void NhanMT(int *a, int *b, int *c, int *n, int *m)
{
	int sum;
	for (int i = 0; i <= *m - 1; i++) 
	{
      	for (int j = 0; j <= *n - 1; j++) 
	  	{
	  		sum = 0;
        	for (int k = 0; k <= *n - 1; k++) 
			{
        		sum +=  *(a + i * (*n) + k) * *(b + k * (*n) + j);
        	}
        	*(c + i * (*n) + j) = sum;
      	}
   	}
   	cout << "Hay mo file ouput2.txt de xem ket qua !";
   	cout << endl;
}

int main()
{
	int A[10][10], B[10][10], C[10][10], n, m;
	int chon = 0;
	
	do
	{
		cout << "\t\t\t ============================MENU================\n";
		cout << "\t\t\t |1. Nhap 2 ma tran                             |\n";
		cout << "\t\t\t |2. Cong 2 ma tran                             |\n";
		cout << "\t\t\t |3. Tru 2 ma tran                              |\n";
		cout << "\t\t\t |4. Nhan 2 ma tran                             |\n";
		cout << "\t\t\t |5. Thoat                                      |\n";
		cout << "\t\t\t ================================================\n";
		cout << "Ban chon chuc nang so : ";
		cin >> chon;
		
		switch(chon)
		{
			case 1: 
				NhapMT((int *)A, (int *)B, &m, &n);
				
				DocFile((int *)A, &m, &n);
				
				break;
			
			case 2:
				CongMT((int *)A, (int *)B, (int *)C, &m, &n);
				LuuKQ((int *)C, &m, &n);
				
				break;
				
			case 3:
				TruMT((int *)A, (int *)B, (int *)C, &m, &n);
				LuuKQ((int *)C, &m, &n);
				
				break;
				
			case 4:
				NhanMT((int *)A, (int *)B, (int *)C, &m, &n);
				LuuKQ((int *)C, &m, &n);
				
				break;
				
			case 5:
				break;
				
			default:
				cout << "Ban chon sai ! Moi ban chon lai MENU \n";
				cout << endl;
				break;
		}
	}
	while(chon != 5);
	return 0;
}
