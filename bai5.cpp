#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    initwindow(900,300); //kich thuoc man hinh
  	settextstyle(1,0,1); // phong, huong, co chu
   	setcolor(14); // mau khung
	rectangle(20,20,850,100); // toa do kich thuoc hinh chu nhat
	
    char s[100]; 
    int DoDai, a;
    
    cout<<"Nhap vao dong van ban: "; 
	cin.getline(s,100);
	setcolor(13); //mau chu
	outtextxy(100,30,s); // hien thi van ban
	DoDai= textwidth(s);// kiem tra do dai chuoi s
	
	outtextxy(30 + DoDai,30,"");
	Sleep(350);
    getch();
    return 0;
}
