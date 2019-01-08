#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;

fstream f1 ("NVVP.txt");
fstream f2 ("NVSX.txt");

const int dinhmucvang = 10;
const int giaphat = 50000;
const int dinhmucsp = 200;
const int dongiasp = 100000;

class NV
{
	public:
		string hoten;
		bool gioitinh;
		int namvaolam;
		float hsl;
		int socon;
		int lcb;
		
		void NhapNV()
		{
			cout << "Nhap ten nhan vien : ";
			getline(std :: cin, hoten);
			fflush(stdin);
			cout << "Nhap gioi tinh (Neu la nu nhap 1, nam nhap 0) : ";
			cin >> gioitinh;
			cout << "Nhap nam vao lam : ";
			cin >> namvaolam;
			cout << "Nhap he so luong : ";
			cin >> hsl;
			cout << "Nhap so con : ";
			cin >> socon;
			cout << "Nhap luong co ban : ";
			cin >> lcb;
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
			cout << "Nam nhan vien vao lam : " << endl;
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
		
		void Nhap()
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
			hsl = atoi(s.c_str());
			getline(f1, s);
			socon = atoi(s.c_str());
			getline(f1, s);
			lcb = atoi(s.c_str());
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
		void Nhap()
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
			hsl = atoi(s.c_str());
			getline(f2, s);
			socon = atoi(s.c_str());
			getline(f2, s);
			lcb = atoi(s.c_str());
			getline(f2, s);
			sosp = atoi(s.c_str());
		}
		
		int TinhThuong()
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

class DSNVVP
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
		
		void Xuatdsvp() 
		{
			for (int i = 0; i < dsnvvp.size(); i++) 
			{
				dsnvvp[i].XuatNVVP();
			}
		}	
		
		void Themnvvp()
		{
			string s;
			getline(f1, s); 
			n = atoi(s.c_str()); 
			dsnvvp.resize(n); 
			
			NVVP tam;
			tam.Nhap();
			ofstream f;
		   		f.open("NVVP.txt", ios::app);
		   	for(int i = 0; i < dsnvvp.size(); i++)
			{
				if(i == 0) 
					f << dsnvvp[i].hoten << endl;
				else
					f << endl << dsnvvp[i].hoten << endl;
					f << dsnvvp[i].gioitinh << endl;
					f << dsnvvp[i].namvaolam << endl;
					f << dsnvvp[i].hsl << endl;
					f << dsnvvp[i].socon << endl;
					f << dsnvvp[i].lcb << endl;
					f << dsnvvp[i].songayvang << endl;
			}	
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
		
		void Themnvsx()
		{
			string s;
			getline(f2, s); 
			n = atoi(s.c_str()); 
			dsnvsx.resize(n); 
			
			NVSX tam;
			tam.Nhap();
			dsnvsx.push_back(tam);
			ofstream f;
		   	f.open("NVSX.txt", ios::app);
		   	for(int i = 0; i < dsnvsx.size(); i++)
			{
				if(i == 0) 
					f << dsnvsx[i].hoten << endl;
				else
					f << endl << dsnvsx[i].hoten << endl;
					f << dsnvsx[i].gioitinh << endl;
					f << dsnvsx[i].namvaolam << endl;
					f << dsnvsx[i].hsl << endl;
					f << dsnvsx[i].socon << endl;
					f << dsnvsx[i].lcb << endl;
					f << dsnvsx[i].sosp;
			}		
		}	
};

int main()
{
	int chon = 0;
	int chon1 = 0;
	DSNVVP vp;
	DSNVSX sx;
	do
	{
		cout << "\t\t\t ============================MENU================\n";
		cout << "\t\t\t |1. Danh sach nhan vien van phong              |\n";
		cout << "\t\t\t |2. Danh sach nhan vien san xuat               |\n";
		cout << "\t\t\t |3. Thoat                                      |\n";
		cout << "\t\t\t ================================================\n";
		cout << "Ban chon chuc nang so : ";
		cin >> chon;
		
		switch(chon)
		{
			case 1:
				vp.Nhapdsvp();
				vp.Xuatdsvp();
				do
				{
					cout << "\t\t\t ============================MENU================\n";
					cout << "\t\t\t |1. Nhap them nhan vien van phong              |\n";
					cout << "\t\t\t |2. Thoat                                      |\n";
					cout << "\t\t\t ================================================\n";
					cout << "Ban chon chuc nang so : ";
					cin >> chon1;
					switch(chon1)
					{
						case 1:
							vp.Themnvvp();
							vp.Xuatdsvp();
							break;
						case 2:
							break;
					}
				}
				while(chon1 != 2);
				break;
			case 2:
				sx.Nhapdssx();
				sx.Xuatdssx();
				do
				{
					cout << "\t\t\t ============================MENU================\n";
					cout << "\t\t\t |1. Nhap them nhan vien san xuat               |\n";
					cout << "\t\t\t |2. Thoat                                      |\n";
					cout << "\t\t\t ================================================\n";
					cout << "Ban chon chuc nang so : ";
					cin >> chon1;
					switch(chon1)
					{
						case 1:
							sx.Themnvsx();
							sx.Xuatdssx();
							break;
						case 2:
							break;
					}
				}
				while(chon1 != 2);	
				break;
			case 3:
				break;
			default:
				cout << "Ban chon sai ! Moi ban chon lai MENU \n";
				cout << endl;
				break;
		}
	}
	while(chon != 3);
	return 0;
}
