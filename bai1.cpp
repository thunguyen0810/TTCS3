#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <string.h>
using namespace std;

void SapXep(int a[8])
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if(a[i] < a[j])
				swap(a[i], a[j]);
}

void Jackpot1()
{
	cout << "Giai Jackpot 1 : " << "\n";
	srand((int)time(0));
	int minN = 1;
	int maxN = 55;
	int arr[55];
	int N = maxN - minN + 1;
	for(int i = minN; i <= maxN; ++i)
        arr[i - minN] = i;
    random_shuffle(arr, arr + N);
    int take = 6;
    SapXep(arr);
    for(int i = 0; i < take; ++i)
        cout << arr[i] << " ";
}

void Jackpot2()
{
	int a[6], sdb;
	cout << "Giai Jackpot 2 : " << "\n";
	srand(time(NULL));
    for(int i = 1; i < 6; i++)
    {
    	a[1] = rand() % 56;
    	a[2] = rand() % 56;
    	a[3] = rand() % 56;
    	a[4] = rand() % 56;
    	a[5] = rand() % 56;
	}
	SapXep(a);
	for(int i = 1; i < 6; i++)
		cout << a[i] << " ";
    cout << endl;
    sdb = rand() % 56;
    cout << "So dac biet : " << endl << sdb;
}

void GiaiNhat()
{
	int a[6];
	cout << "Giai Nhat : " << "\n";
	srand(time(NULL));
    for(int i = 1; i < 6; i++)
    {
    	a[i + 1] = rand() % 56;
	}
	SapXep(a);
	for(int i = 1; i < 6; i++)
		cout << a[i] << " ";
    cout << endl;
}

void GiaiNhi()
{
	int a[5];
	cout << "Giai Nhi : " << "\n";
	srand(time(NULL));
    for(int i = 1; i < 5; i++)
    {
    	a[1] = rand() % 56;
    	a[2] = rand() % 56;
    	a[3] = rand() % 56;
    	a[4] = rand() % 56;
	}
	SapXep(a);
	for(int i = 1; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;
}

void GiaiBa()
{
	int a[4];
	cout << "Giai Ba : " << "\n";
	srand(time(NULL));
    for(int i = 1; i < 4; i++)
    {
    	a[1] = rand() % 56;
    	a[2] = rand() % 56;
    	a[3] = rand() % 56;
	}
	SapXep(a);
	for(int i = 1; i < 4; i++)
		cout << a[i] << " ";
	cout << endl;
}

void KiemTra()
{
}

int main()
{
	int a[8];
	cout << "Nhap vao cac so trong ve cua ban ";
	cout << endl;
	for(int i = 1; i < 8; i++)
	{
		cout << "So thu " << i << " : ";
		cin >> a[i];
	}
	
	cout << "Day so cua ban la : " << endl;
	for(int i = 1; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	
	cout << "\n";
    cout << "---------------------------------------------------------------" << endl;
    
    Jackpot1();
    
    cout << "\n";
    cout << "---------------------------------------------------------------" << endl;
    
    Jackpot2();
    
    cout << "\n";
    cout << "----------------------------------------------------------------" << endl;
    
   	GiaiNhat();
    
    cout << "\n";
    cout << "-----------------------------------------------------------------" << endl;
    
    GiaiNhi();
    
    cout << "\n";
    cout << "------------------------------------------------------------------" << endl;
    
  	GiaiBa();
  	
  	cout << "\n";
    cout << "------------------------------------------------------------------" << endl;
  	
  	KiemTra();
}
