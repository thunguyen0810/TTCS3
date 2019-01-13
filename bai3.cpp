#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <Windows.h> 
#include <conio.h>
using namespace std;

fstream f1 ("NVVP.txt");
fstream f2 ("NVSX.txt");

const int dinhmucvang = 10;
const int giaphat = 50000;
const int dinhmucsp = 200;
const int dongiasp = 100000;
const int lcb = 5000000;

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

class NV
{
	public:
		string hoten;
		bool gioitinh;
		int namvaolam;
		float hsl;
		int socon;
	
		
		void NhapNV()
		{
			cout << "Nhap ten nhan vien : ";
			cin >> hoten;
			fflush(stdin);
			cout << "Nhap gioi tinh (Neu la nu nhap 1, nam nhap 0) : ";
			cin >> gioitinh;
			cout << "Nhap nam vao lam : ";
			cin >> namvaolam;
			cout << "Nhap he so luong : ";
			cin >> hsl;
			cout << "Nhap so con : ";
			cin >> socon;
		}
		
		int TinhThuong()
		{
			int sonam = 2019 - namvaolam;
			return sonam * 1000000;
		}
		
		void XuatNV()
		{
			cout << "---------------------------------------------";
			cout << endl;
			cout << "Ho va ten nhan vien : " << hoten << endl;
			if(gioitinh == 1)
				cout << "Gioi tinh : Nu" << endl;
			else
			cout << "Gioi tinh : Nam" << endl;
			cout << "Nam nhan vien vao lam : " << namvaolam << endl;
			cout << "He so luong : " << hsl << endl;
			cout << "So con : " << socon << endl;
			cout << "Luong co ban : " << lcb << endl;
			cout << "Tien thuong : " << TinhThuong() << endl;
		}
};

class NVVP : public NV
{
	public:
		int songayvang;
		
		void NhapVP()
		{
			NV :: NhapNV();
			cout << "Nhap so ngay nhan vien vang : ";
			cin >> songayvang ;
			cout << endl;
		}
		
		void NhapNVVP()
		{
			string s;
			
			getline(f1, s);
			hoten = s;
			getline(f1, s);
			gioitinh = atoi(s.c_str());
			getline(f1, s);
			namvaolam = atoi(s.c_str());
			getline(f1, s);
			hsl = strtof((s).c_str(), 0);
			getline(f1, s);
			socon = atoi(s.c_str());
			getline(f1, s);
			songayvang = atoi(s.c_str());
		}
		
		int TinhPhat()
		{
			if(songayvang > dinhmucvang)
				return (songayvang - dinhmucvang) * giaphat;
			else
				return 0;
		}
		
		int TinhTroCap()
		{
			if(gioitinh == 1)
				return 200000 * socon * 1.5;
			else
				return 200000 * socon;
		}
		
		int TinhLuong()
		{
			return lcb * hsl - TinhPhat();
		}		
		void XuatNVVP()
		{
			NV :: XuatNV();
			cout << "So ngay nhan vien vang : " << songayvang << endl;
			if(TinhPhat() != 0)
				cout << "Tien bi phat thang nay : " << TinhPhat() << endl;
			if(TinhTroCap() != 0)
				cout << "Tien tro cap cua nhan vien van phong thang nay: " << TinhTroCap() << endl;
			cout << "Tien luong cua nhan vien van phong thang nay : " << TinhLuong() << endl;
		}
};

class NVSX : public NV
{
	public:
		int sosp;
		void NhapSX()
		{
			NV :: NhapNV();
			cout << "Nhap so san pham nhan vien lam duoc trong thang nay : ";
			cin >> sosp;
		}
		
		void NhapNVSX()
		{
			string s;
			
			getline(f2, s);
			hoten = s;
			getline(f2, s);
			gioitinh = atoi(s.c_str());
			getline(f2, s);
			namvaolam = atoi(s.c_str());
			getline(f2, s);
			hsl = strtof((s).c_str(), 0);
			getline(f2, s);
			socon = atoi(s.c_str());
			getline(f2, s);
			sosp = atoi(s.c_str());
		}
		
		int TinhThuong1()
		{
			if(sosp > dinhmucsp)
				return (sosp - dinhmucsp) * dongiasp * 0.03;
			else
				return 0;
		}
		
		int TinhTroCap()
		{
			return socon * 120000;
		}
		
		int TinhLuong()
		{
			return (sosp * dongiasp) + TinhThuong();
		}
	
		void XuatNVSX()
		{
			NV :: XuatNV();
			cout << "So san pham nhan vien san xuat lam duoc trong nam : " << sosp << endl;
			if(TinhThuong() != 0)
				cout << "Tien thuong thang nay cua nhan vien san xuat : " << TinhThuong() << endl;
			if(TinhTroCap() != 0)
				cout << "Tien tro cap thang nay cua nhan vien san xuat : " << TinhTroCap() << endl;
			cout << "Tien luong thang nay cua nhan vien san xuat : " << TinhLuong() << endl;
		}
};

class DSNVVP : public NVVP
{
	int n; 
	vector<NVVP> dsnvvp;
	public:
		void Nhapdsvp() 
		{	
			if (f1.fail())
				cout << "Mo file that bai !" << endl;
			else 
			{	
				string s;
				getline(f1, s); 
				n = atoi(s.c_str()); 
				dsnvvp.resize(n); 		
				for (int i = 0; i < dsnvvp.size(); i++) 
				{
					dsnvvp[i].NhapNVVP();
				}
			}
			f1.close();				
		}
		
		int TinhLuongTB()
		{
			int tong = 0;
			for (int i = 0; i < dsnvvp.size(); i++) 
			{
				tong += dsnvvp[i].TinhLuong();
			}
			return tong/dsnvvp.size();
		}
		
		void Xuatdsvp() 
		{
			for (int i = 0; i < dsnvvp.size(); i++) 
			{
				dsnvvp[i].XuatNVVP();
			}
			cout << "Luong trung binh cua nhan vien van phong : " << TinhLuongTB();
		}		
};

class DSNVSX
{
	int n; 
	vector <NVSX> dsnvsx;
	public:
		void Nhapdssx() 
		{	
		
			if (f2.fail())
				cout << "Mo file that bai !" << endl;
			else 
			{	
				string s;
				getline(f2, s); 
				n = atoi(s.c_str()); 
				dsnvsx.resize(n); 		
				for (int i = 0; i < dsnvsx.size(); i++) 
				{
					dsnvsx[i].NhapNVSX();
				}
			}
			f2.close();
							
		}
		
		void Xuatdssx() 
		{
			for (int i = 0; i < dsnvsx.size(); i++) 
			{
				dsnvsx[i].XuatNVSX();
			}
		}	
};

int main()
{
	int chon = 0;
	int chon1 = 0;
	int chon2 = 0;
	DSNVVP vp;
	DSNVSX sx;
	NVVP nvvp;
	NVSX nvsx;
	do
	{
		Menu :
		{
			textcolor(11);
			cout << "\t\t\t ============================MENU================\n";
			cout << "\t\t\t |1. Nhan vien van phong                        |\n";
			cout << "\t\t\t |2. Nhan vien san xuat                         |\n";
			cout << "\t\t\t |3. Thoat                                      |\n";
			cout << "\t\t\t ================================================\n";
			textcolor(15);
			textcolor(12);
			cout << "Ban chon chuc nang so : ";
			textcolor(15);
			cin >> chon;
		}
	
		switch(chon)
		{
			case 1:
				do
				{
					cout << endl;
					textcolor(14);
					cout << "\t\t\t ============================MENU================\n";
					cout << "\t\t\t |1. Nhap thong tin nhan vien van phong         |\n";
					cout << "\t\t\t |2. Xem danh sach nhan vien van phong          |\n";
					cout << "\t\t\t |3. Thoat                                      |\n";
					cout << "\t\t\t ================================================\n";
					textcolor(15);
					textcolor(12);
					cout << "Ban chon chuc nang so : ";
					textcolor(15);
					cin >> chon1;
					switch(chon1)
					{
						case 1:
							fflush(stdin);
							nvvp.NhapVP();
							nvvp.TinhLuong();
							nvvp.TinhThuong();
							nvvp.TinhPhat();
							nvvp.TinhTroCap();
							nvvp.XuatNV();
							nvvp.XuatNVVP();
							break;
						case 2:
							vp.Nhapdsvp();
							vp.Xuatdsvp();
							break;
						case 3:
							goto Menu;
							break;
					}
				}
				while(chon1 != 3);
			case 2:
				do
				{
					cout << endl;
					textcolor(13);
					cout << "\t\t\t ============================MENU================\n";
					cout << "\t\t\t |1. Nhap thong tin nhan vien san xuat          |\n";
					cout << "\t\t\t |2. Xem danh sach nhan vien san xuat           |\n";
					cout << "\t\t\t |3. Thoat                                      |\n";
					cout << "\t\t\t ================================================\n";
					textcolor(15);
					textcolor(12);
					cout << "Ban chon chuc nang so : ";
					textcolor(15);
					cin >> chon2;
					switch(chon2)
					{
						case 1:
							fflush(stdin);
							nvsx.NhapSX();
							nvsx.TinhLuong();
							nvsx.TinhThuong1();
							nvsx.TinhTroCap();
							nvsx.XuatNV();
							nvsx.XuatNVSX();
							break;
						case 2:
							sx.Nhapdssx();
							sx.Xuatdssx();
						case 3:
							goto Menu;
							break;
					}
				}
				while(chon2 != 3);
			case 3:
				break;
		}
	}
	while(chon != 3);
}
