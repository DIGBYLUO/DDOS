#include<bits/stdc++.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<string>
#include <fstream>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
int peo = 0;
double shanghai[20]={0.6,1.1,2,3.16,5.5,7,10,20,50,100,146.23,254.13,312,403,601,1023};
double bosshealth[20]={2,3,4,5.9,8,14,19,32,73,157,200,403,801,1200,3630,20123};
double wj_shanghai=1,wj_health=10,wj_max_health=10,boss,wj_money;
bool OFF = true;
void chushihua();
void game();
void gongji();
void goumai();
void shangdian();
void zhujiemian();
void fangyu();
void cend();
void chushou();
void print(char[]);
string abb;
int bishou=0,caidao=0,jian=0,shenjian=0;
double bishou_1=5,caidao_1=17,jian_1=58,shenjian_1=123.1;
int hat=0,douhui=0,hudun=0,hunjia=0,shendun=0;
double hat_1=7,douhui_1=21,hudun_1=49,hunjia_1=89,shendun_1=210.4;
int cj(){
	while (1){
        if (_kbhit()){//����а������£���_kbhit()����������
            int ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            return ch;
        }
    }
}
void cend()
{
    system("cls");
    print("GAME OVER");
    exit(1);
}
void game()
{
    int k;
    chushihua();
    IO:
    printf("��������ֵȼ� (0~15)\n");
    scanf("%d",&k);
    if(k>15||k<0)
    {
        system("cls");
        goto IO;
    }
    boss=bosshealth[k];
    system("cls");
    while(wj_health>=0)
    {
        srand(time(NULL));
        QP:
        printf("1.����        2.����\n");
        char s=getch();
        if(s<'1'||s>'2')
        {
            system("cls");
            goto QP;
        }
        if(s=='1')
        {
            system("cls");
            zhujiemian();
        }
        system("cls");
        double l=shanghai[k]*((rand()%2)+1)+fabs(double(rand()%100/100-2));
        printf("���ֶ��������%lf���˺�\n",l);
        wj_health-=l;
        printf("�㵱ǰʣ��Ѫ����%lf\n",wj_health);
        if(wj_health<=0)
            cend();
        double o=wj_shanghai*((rand()%2)+1)+double(rand()%10/10);
        boss-=o;
        printf("��Զ��������%lf���˺�\n",o);
        printf("���ֵ�ǰʣ��Ѫ����%lf\n\n",boss);
        if(boss<=0)
        {
            printf("ʤ����\n���%lf���\n\n��ǰʣ��Ѫ����%lf\n",shanghai[k]+3,wj_health);
            wj_money+=shanghai[k]+3;
            printf("\n��%lf\n",wj_money);
            getch();
            if(k==15)
            {
                printf("��ϲ��ң���Ϸʤ����\n");
                getch();
                exit(1);
            }
            system("cls");
            zhujiemian();
        }
    }
}
void zhujiemian()
{
    PO:
    printf("1.�̵� 2.ս�� 3.��Ѫ 4.״̬\n");
    char k=getch();
    if(k>'4'||k<'1')
    {
        system("cls");
        goto PO;
    }
    if(k=='1')
    {
        system("cls");
        shangdian();
        return;
    }
    if(k=='2')
    {
        system("cls");
        game();
        return;
    }
    if(k=='3')
    {
        system("cls");
        if(wj_money>0)
        {
            wj_money=wj_money*4/5-1;
            chushihua();
            wj_health=wj_max_health;
            printf("��Ѫ�ɹ���\n");
            getch();
            system("cls");
            goto PO;
        }
        else
        {
            printf("���㣡\n");
            getch();
            system("cls");
            goto PO;
        }
    }
    if(k=='4')
    {
        chushihua(); 
        system("cls");
        printf("����ֵ��%lf\n",wj_health);
        printf("�������ֵ��%lf\n",wj_max_health);
        printf("��������%lf\n",wj_shanghai);
        printf("��ң�%lf\n",wj_money); 
        getch();
        system("cls");
        goto PO;
    }
    if(k=='5')
    {
        string a;
        system("cls");
        printf("�������룡\n");
        cin>>a;
        if(a=="songyudashuaibi"||a=="PI")
        {
            wj_money-=1000;
            printf("�����Ч\n");
            Sleep(1000);
            system("cls");
            goto PO;
        }
        printf("���ʧ��\n");
        Sleep(1000);
        system("cls");
        goto PO;
    	if(k=='6'){
    		return;
		} 
	}
    
}
void shangdian()
{
    LK:
    printf("1.���� 2.����������\n");
    char k=getch();
    if(k!='1'&&k!='2')
    {
        system("cls");
        goto LK;
    }
    if(k=='1')
    {
        system("cls");
        goumai();
        goto LK;
    }
    if(k=='2')
    {
        system("cls");
        zhujiemian();
        return;
    }
}
void goumai()
{
    ML:
    printf("1.���� 2.���� 3.����������\n");
    char k=getch();
    if(k!='1'&&k!='2'&&k!='3')
    {
        system("cls");
        goto ML;
    }
    if(k=='1')
    {
        system("cls");
        gongji();
        goto ML;
    }
    if(k=='3')
    {
        system("cls");
        zhujiemian();
        return;
    }
    if(k=='2')
    {
        fangyu();
    }
} 
void gongji()
{
    OP:
    system("cls");
    printf("0.�����Ͻ���\n");
    printf("1.����������\n");
    printf("2.ذ�� 5���\n");
    printf("3.�˵� 17���\n");
    printf("4.�� 68���\n");
    printf("5.ʥ�� 210���\n");
    printf("���ѣ���Ҽ۸����˺�������\n");
    char k=getch();
    if(k<'0'||k>'5')
    {
        system("cls");
        goto OP;
    }
    if(k=='0')
    {
        system("cls");
        goumai();
        return;
    }
    if(k=='1')
    {
        system("cls");
        zhujiemian();
        return;
    }
    if(k=='2')
    {
        if(wj_money>=bishou_1)
        {
            chushihua();
            system("cls");
            wj_money-=bishou_1;
            bishou++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        system("cls");
        goto OP;
    }
    if(k=='3')
    {
        if(wj_money>=caidao_1)
        {
            chushihua();
            system("cls");
            wj_money-=caidao_1;
            caidao++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
    if(k=='4')
    {
        if(wj_money>=jian_1)
        {
            chushihua();
            system("cls");
            wj_money-=jian_1;
            jian++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
    if(k=='5')
    {
        if(wj_money>=shenjian_1)
        {
            chushihua();
            system("cls");
            wj_money-=shenjian_1;
            shenjian++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
}
void fangyu()
{
    OP:
    system("cls");
    printf("0.�����Ͻ���\n");
    printf("1.����������\n");
    printf("2.ñ�� 7���\n");
    printf("3.ͷ�� 21���\n");
    printf("4.���� 49���\n");
    printf("5.���� 89���\n");
    printf("6.ʥ�� 210���\n");
    printf("���ѣ���Ҽ۸����˺�������\n");
    char k=getch();
    if(k<'0'||k>'6')
    {
        system("cls");
        goto OP;
    }
    if(k=='0')
    {
        system("cls");
        goumai();
        return;
    }
    if(k=='1')
    {
        system("cls");
        zhujiemian();
        return;
    }
    if(k=='2')
    {
        if(wj_money>=hat_1)
        {
            chushihua();
            system("cls");
            wj_money-=hat_1;
            hat++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        system("cls");
        goto OP;
    }
    if(k=='3')
    {
        if(wj_money>=douhui_1)
        {
            chushihua();
            system("cls");
            wj_money-=douhui_1;
            douhui++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
    if(k=='4')
    {
        if(wj_money>=hudun_1)
        {
            chushihua();
            system("cls");
            wj_money-=hudun_1;
            hudun++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
    if(k=='5')
    {
            chushihua();
        if(wj_money>=hunjia_1)
        {
            system("cls");
            wj_money-=hunjia_1;
            hunjia++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
    if(k=='6')
    {
        if(wj_money>=shendun_1)
        {
            chushihua();
            system("cls");
            wj_money-=shendun_1;
            shendun++;
            goto OP;
        }
        system("cls");
        printf("���㣡\n");
        getch();
        goto OP;
    }
}
void chushihua()
{
    wj_max_health=hat*hat_1+douhui*douhui_1+hudun*hudun_1+hunjia*hunjia_1+shendun*shendun_1+10;
    wj_shanghai=bishou*bishou_1+caidao*caidao_1+jian*jian_1+shenjian*shenjian_1+1;
}
void print(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        Sleep(400);
    }
    getch(); 
    system("cls");
}
int star(){
	string ac[2];
	ac [0] = "Digby";
	ac [1] = "test";
	string acc;
	int wh = 0;
	system("cls");  
	for(int i = 0 ;i > -1;i){
		system("cls");
		bool zq = false;
		cout << "�������˺�" << endl;
		cin >> acc;
		abb = acc;
		for(int j = 0;j < 2 ;i++){
			if(acc == ac[j]){
				zq = true;
				}
			if(zq = true){
				wh = i;
				break;
			}
		}
		if(acc =="ע��"&& zq == false){
			system("start https://passport.jisuanke.com/?n=http://www.jisuanke.com#/reg/");			
			}else{
		cout << "��Ч���˺�" <<	endl;
			}				
		if(zq == true){
			return i;
		}
	system("pause");
	}
}
int star2(int wh){
	system("cls");
	bool zq = false;
	int Password;
	for(int i = 0 ;i > -1;i){
		system("cls");
		cout << "����������" << endl;
		cin >> Password;
		if((Password == 103 && wh == 0 )||(Password == 0 && wh != 0)){
			zq = true;
			peo++;
			system("cls");	
			return 0;
			}
			if(zq = false){
				if(Password == 0 && wh != 0){
				zq = true;
				system("cls");	
				return 0;
				}else{
			cout << "��Ч������" <<	endl;
				}
			}	
	cout << "��Ч������" <<	endl;	
	system("pause");
	star();
	}
}
int bai(){
	string ba;
	system("cls");
	cout << "��ӭ������ٿ�" << endl;
	Sleep(3000);
	system("cls");
	cout << "1 = Ԫ�����ڱ� ESC = �˳�" << endl;
	cin >> ba;
	if(ba == "1"){
		cout << "��(q��ng) ��(h��i) �(l��) ��(p��) ��(p��ng)" << endl <<"̼(t��n) ��(d��n) ��(y��ng) ��(f��) ��(n��i)"<<endl<<"��(n��) þ(m��i) ��(l��) ��(gu��) ��(l��n) " << endl <<"��(li��) ��(l��) �(y��)��(ji��) ��(g��i)" << endl <<"��(k��ng) ��(t��i) ��(f��n) ��(g��) ��(m��ng)" << endl << "��(ti��) ��(g��) ��(ni��) ͭ(t��ng) п(x��n) "<< endl << "��(ti��) ��(g��) ��(ni��) ͭ(t��ng) п(x��n) "<< endl <<"��(ji��) ��(zh��) ��(sh��n) ��(x��) ��(xi��)" << endl << "�(k��)�(r��) ��(s��) ��(y��) �(g��o)" << endl << "��(n��) ��(m��) �(d��) ��(li��o) ��(l��o)" << endl <<"��(p��) ��(y��n) ��(g��) ��(y��n) ��(x��) " <<endl;
		cout << "��(t��) ��(d��) ��(di��n) �(xi��n)�(s��) " << endl << "��(b��i) ��(l��n) ��(h��) ��(t��n) ��(w��) " << endl <<"�(l��i) �(��) ҿ(y��) ��(b��) ��(j��n) " << endl <<"��(g��ng) ��(t��) Ǧ(qi��n) ��(b��) ��(p��)" << endl <<"��(��i) �(d��ng)��(f��ng) ��(l��i) �(��)"  << endl << "��¬(l��) �Ķ�(d��) ��ϲ(x��) �Ĳ�(b��) �ĺ�(h��i)" << endl <<"����(m��i) �Ĵ�(d��) ����(l��n) ��(l��n) ��(sh��) " << endl <<"��(p��) ��(n��) ��(p��) ��(sh��n) ��(y��u)" <<endl << "��(g��) �(t��) ��(d��) ��(hu��) ��(��r) " << endl << "��(di��) ��(y��) ��(l��)�(��) ��(t��) " << endl << "��(p��) ��(y��u) ��(n��) ��(b��) ��(m��i)" << endl << "�(j��) ��(p��i) �(k��i) ��(��i) ��(f��i) " <<endl << "�(j��) ��(p��i) �(k��i) ��(��i) ��(f��i) " <<endl; 
	system("pause");
	}
	return 0; 
}
int hj(){
	system("cls");
	cout << "test" << endl;
	Sleep(3000);
	system("cls");  
	cout << "test1" << endl;
	Sleep(3000);
	system("cls");	
}
int wan(){
	return 0;	
}
int san(){
    int sann;
    cin >> sann;
    for(int i = sann; i > 0; i--){
        for(int j = i * 2; j > 0; j--){
            cout << 'A';
        }
        cout << endl;
    }
    return 0;
} 
int gy(){
	cout << "����������" << endl; 
    int gn;
    cin >> gn;
    system("cls");
    cout << gn << endl;
    while(gn != 1){
        if(gn % 2 ==0){
            gn = gn / 2;
        }else{
            gn = 3 * gn + 1; 
        }
        cout << gn << endl;
    }
    system("pause");
	return 0;
}
int jisuan(){
	long long ja , jb ;        //�������
    char op;
    for (int q = 0;q <=0 ;q++){ 
	    cout << "�Ѿ����������" <<endl; 
	    cout << "��������( + = �� - = �� * = ��  / = ��  % = ģ �˳� r) ����: a + b" <<endl;
	    cin >> ja >> op >> jb;//����
	    if (op == 'r'){      //�ж�
	        return 0;
	    }
	    for (int i = 0;i <= 10;i++){
	        cout << "������" << i << "0%..." << endl;
	        system("cls"); 
	    }
	    if(op != '+'&&op != '-'&&op != '*'&&op != '/'&&op != '%'){
	    	cout << "����" <<endl;
	    	system("pause");
			system("cls");
			return 0; 
		}
	    if (op =='+'){      //�ж�
	        cout << ja << " + " << jb << " = " << ja + jb;
	    }
	    if (op == '-'){
	        cout << ja << " - " << jb << " = " << ja - jb;
	    }
	    if (op == '*'){
	        cout << ja << " * " << jb << " = " << ja * jb;
	    }
	    if (op == '/'){
	        cout << ja << " / "<< jb << " = " << ja / jb;
	    }
	    if (op == '%'){
	        cout << ja << " % "<< jb << " = " << ja % jb;
	    }
	    cout << endl << "�������" << endl << "����by Digby";
	    system("pause");
		system("cls");
	} 
	return 0;
}  
string admin(){
	string ba;
	system("cls");
	cout << "��ӭ���������Աģʽ" << endl;
	cout << "�ѵ�¼" << peo << "��" << endl;
	cin >> ba;
	if(ba == "OFF"||ba == "off"){
		return "OFF";
	}else{
		return "no";
	}
} 
int main(){	
ST:
string ch;
system("title winmaxos");
print("winmaxos");
system("title winmaxos");
string acc = "    ";                      // �˺�
string ba = "    "; 					//���˹� 
bool lock = false;              //����״̬ 
bool zq = false;				//�û���t/f
int wh;
int Password; 
		for(int i = 0;i <= 10;i++){
			cout << "�Ѽ���" << i  <<'0'<< '%' <<endl;
			Sleep(5);
			system("cls"); 
		} 
	system("cls"); 	
	cout << "���سɹ�" <<endl;
	system("pause");
	wh = star();
	star2(wh);
	cout << "                                       ��ӭ";
			Sleep(1000);
			system("cls");
	string hui_da[9]={"������","��һ","�ػ�","����","�򿪼����","��","�ٿ�","����","�˳�"};
	int diji = 0; 
	while(1){
		ba = diji; 
		system("cls");
		cout <<"����" << abb  << "    �汾:V.1.2.0"<< endl ;
		for (int i = 0;i <9;i++){
			if(i == diji){
			cout << ">";
			} 
			cout << hui_da[i]<< " ";	
			if(i == 5){
				cout << endl << " ";
			}
		}
		int hhhhhhhh ;
		hhhhhhhh = cj();
		if(hhhhhhhh == 22477 && diji != 8){
			diji++	;
		}else if(hhhhhhhh== 22475 && diji != 0){
			diji = diji - 1;
		}
		
		if(ba =="j"){
			system("cls");
			jisuan();		
		}
		if(ba =="g"){
			system("cls");
			gy();		
		}
		if(ba =="OFF"){
			if(OFF == true){ 
				wh = star();
				star2(wh);
				system("SHUTDOWN -s -t 0");
				return 0;
			}		
		}
		if(ba =="ag"){
			if(OFF == true){ 
				wh = star();
				star2(wh);
				system("SHUTDOWN -r -t 5");	
				return 0;
			}	
		}
		if(ba =="js"){
			system("start www.jisuanke.com");		
		}
		if(ba =="wa"){
			wan();			
		}
		if(ba =="ji"){
			system("start www.iqiyi.com/w_19rqto7g3l.html");				
		}
		if(ba =="hj"){
			hj();				
		}
		if(ba =="ba"){
			bai();				
		}
		if(ba == "4399"){
			system("start www.4399.com");
		}
		if(ba == "loock"){
			wh = star();
			star2(wh);
			cout << "                                       ��ӭ";
			Sleep(1000);
			system("cls");	
		} 
		if(ba == "out"){
			return 0;
		}
		if(ba == "game"){
			system("cls");
			system("title game");
    		print("���");
    		zhujiemian();
			system("cls");
		}
		if(ba == "wg"){
			wj_money+=10000000000;
			}
		if(ba == "admin"){
			ch = admin();
			if(ch == "OFF"){
				OFF = false;
				} 
	} 
	}
}
