#include<windows.h>
#include<cstdio>
#include<iostream>
#include<conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;

HWND hwnd=GetForegroundWindow();//ʹhwnd������ǰ�˵Ĵ���
int main(){
	system("title ����"); 
	system("mode con cols=8 lines=3");
	int result = 7; 
	//ShowWindow(hwnd,SW_MAXIMIZE);
	ShowWindow(hwnd,SW_MINIMIZE);
	int WINAPI MessageBox(HWND hWnd,LPCTSTR lpText,LPCTSTR lpCaption,UINT uType);
		while(result == 7){ 
		result = 0;
		 result =MessageBox( NULL,TEXT("�ż�����Ů�ģ�") , TEXT("����") , MB_ICONQUESTION|MB_YESNO);
} 
result =MessageBox( NULL , TEXT("YES") , TEXT("��ȷ") , MB_ICONSTOP|MB_OK);
	return 0;
}
