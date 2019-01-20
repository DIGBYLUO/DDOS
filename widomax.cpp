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
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            int ch = _getch();//使用_getch()函数获取按下的键值
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
    printf("请输入对手等级 (0~15)\n");
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
        printf("1.逃跑        2.进攻\n");
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
        printf("对手对你造成了%lf点伤害\n",l);
        wj_health-=l;
        printf("你当前剩余血量：%lf\n",wj_health);
        if(wj_health<=0)
            cend();
        double o=wj_shanghai*((rand()%2)+1)+double(rand()%10/10);
        boss-=o;
        printf("你对对手造成了%lf点伤害\n",o);
        printf("对手当前剩余血量：%lf\n\n",boss);
        if(boss<=0)
        {
            printf("胜利！\n获得%lf金币\n\n当前剩余血量：%lf\n",shanghai[k]+3,wj_health);
            wj_money+=shanghai[k]+3;
            printf("\n余额：%lf\n",wj_money);
            getch();
            if(k==15)
            {
                printf("恭喜玩家！游戏胜利！\n");
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
    printf("1.商店 2.战斗 3.回血 4.状态\n");
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
            printf("回血成功！\n");
            getch();
            system("cls");
            goto PO;
        }
        else
        {
            printf("余额不足！\n");
            getch();
            system("cls");
            goto PO;
        }
    }
    if(k=='4')
    {
        chushihua(); 
        system("cls");
        printf("生命值：%lf\n",wj_health);
        printf("最大生命值：%lf\n",wj_max_health);
        printf("攻击力：%lf\n",wj_shanghai);
        printf("金币：%lf\n",wj_money); 
        getch();
        system("cls");
        goto PO;
    }
    if(k=='5')
    {
        string a;
        system("cls");
        printf("输入密码！\n");
        cin>>a;
        if(a=="songyudashuaibi"||a=="PI")
        {
            wj_money-=1000;
            printf("外挂生效\n");
            Sleep(1000);
            system("cls");
            goto PO;
        }
        printf("外挂失败\n");
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
    printf("1.购买 2.返回主界面\n");
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
    printf("1.攻击 2.防御 3.返回主界面\n");
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
    printf("0.返回上界面\n");
    printf("1.返回主界面\n");
    printf("2.匕首 5金币\n");
    printf("3.菜刀 17金币\n");
    printf("4.剑 68金币\n");
    printf("5.圣剑 210金币\n");
    printf("提醒：金币价格与伤害成正比\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
        getch();
        goto OP;
    }
}
void fangyu()
{
    OP:
    system("cls");
    printf("0.返回上界面\n");
    printf("1.返回主界面\n");
    printf("2.帽子 7金币\n");
    printf("3.头盔 21金币\n");
    printf("4.护盾 49金币\n");
    printf("5.盔甲 89金币\n");
    printf("6.圣盾 210金币\n");
    printf("提醒：金币价格与伤害成正比\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
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
        printf("余额不足！\n");
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
		cout << "请输入账号" << endl;
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
		if(acc =="注册"&& zq == false){
			system("start https://passport.jisuanke.com/?n=http://www.jisuanke.com#/reg/");			
			}else{
		cout << "无效的账号" <<	endl;
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
		cout << "请输入密码" << endl;
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
			cout << "无效的密码" <<	endl;
				}
			}	
	cout << "无效的密码" <<	endl;	
	system("pause");
	star();
	}
}
int bai(){
	string ba;
	system("cls");
	cout << "欢迎您进入百科" << endl;
	Sleep(3000);
	system("cls");
	cout << "1 = 元素周期表 ESC = 退出" << endl;
	cin >> ba;
	if(ba == "1"){
		cout << "氢(qīng) 氦(hài) 锂(lǐ) 铍(pí) 硼(péng)" << endl <<"碳(tàn) 氮(dàn) 氧(yǎng) 氟(fú) 氖(nǎi)"<<endl<<"钠(nà) 镁(měi) 铝(lǚ) 硅(guī) 磷(lín) " << endl <<"硫(liú) 氯(lǜ) 氩(yà)钾(jiǎ) 钙(gài)" << endl <<"钪(kàng) 钛(tài) 钒(fán) 铬(gè) 锰(měng)" << endl << "铁(tiě) 钴(gǔ) 镍(niè) 铜(tóng) 锌(xīn) "<< endl << "铁(tiě) 钴(gǔ) 镍(niè) 铜(tóng) 锌(xīn) "<< endl <<"镓(jiā) 锗(zhě) 砷(shēn) 硒(xī) 溴(xiù)" << endl << "氪(kè)铷(rú) 锶(sī) 钇(yǐ) 锆(gào)" << endl << "铌(ní) 钼(mù) 锝(dé) 钌(liǎo) 铑(lǎo)" << endl <<"钯(pá) 银(yín) 镉(gé) 铟(yīn) 锡(xī) " <<endl;
		cout << "锑(tī) 碲(dì) 碘(diǎn) 氙(xiān)铯(sè) " << endl << "钡(bèi) 镧(lán) 铪(hā) 钽(tǎn) 钨(wū) " << endl <<"铼(lái) 锇(é) 铱(yī) 铂(bó) 金(jīn) " << endl <<"汞(gǒng) 铊(tā) 铅(qiān) 铋(bì) 钋(pō)" << endl <<"砹(ài) 氡(dōng)钫(fāng) 镭(léi) 锕(ā)"  << endl << "钅卢(lú) 钅杜(dù) 钅喜(xǐ) 钅波(bō) 钅黑(hēi)" << endl <<"钅麦(mài) 钅达(dá) 钅仑(lún) 镧(lán) 铈(shì) " << endl <<"镨(pǔ) 钕(nǚ) 钷(pǒ) 钐(shān) 铕(yǒu)" <<endl << "钆(gá) 铽(tè) 镝(dí) 钬(huǒ) 铒(ěr) " << endl << "铥(diū) 镱(yì) 镥(lǔ)锕(ā) 钍(tǔ) " << endl << "镤(pú) 铀(yóu) 镎(ná) 钚(bù) 镅(méi)" << endl << "锔(jū) 锫(péi) 锎(kāi) 锿(āi) 镄(fèi) " <<endl << "锔(jū) 锫(péi) 锎(kāi) 锿(āi) 镄(fèi) " <<endl; 
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
	cout << "请输入数字" << endl; 
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
	long long ja , jb ;        //定义变量
    char op;
    for (int q = 0;q <=0 ;q++){ 
	    cout << "已经进入计算器" <<endl; 
	    cout << "输入数字( + = 加 - = 减 * = 乘  / = 除  % = 模 退出 r) 例子: a + b" <<endl;
	    cin >> ja >> op >> jb;//输入
	    if (op == 'r'){      //判断
	        return 0;
	    }
	    for (int i = 0;i <= 10;i++){
	        cout << "计算中" << i << "0%..." << endl;
	        system("cls"); 
	    }
	    if(op != '+'&&op != '-'&&op != '*'&&op != '/'&&op != '%'){
	    	cout << "出错" <<endl;
	    	system("pause");
			system("cls");
			return 0; 
		}
	    if (op =='+'){      //判断
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
	    cout << endl << "计算完毕" << endl << "——by Digby";
	    system("pause");
		system("cls");
	} 
	return 0;
}  
string admin(){
	string ba;
	system("cls");
	cout << "欢迎您进入管理员模式" << endl;
	cout << "已登录" << peo << "次" << endl;
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
string acc = "    ";                      // 账号
string ba = "    "; 					//搬运工 
bool lock = false;              //解锁状态 
bool zq = false;				//用户名t/f
int wh;
int Password; 
		for(int i = 0;i <= 10;i++){
			cout << "已加载" << i  <<'0'<< '%' <<endl;
			Sleep(5);
			system("cls"); 
		} 
	system("cls"); 	
	cout << "加载成功" <<endl;
	system("pause");
	wh = star();
	star2(wh);
	cout << "                                       欢迎";
			Sleep(1000);
			system("cls");
	string hui_da[9]={"计算器","归一","关机","重启","打开计蒜客","无","百科","锁定","退出"};
	int diji = 0; 
	while(1){
		ba = diji; 
		system("cls");
		cout <<"您好" << abb  << "    版本:V.1.2.0"<< endl ;
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
			cout << "                                       欢迎";
			Sleep(1000);
			system("cls");	
		} 
		if(ba == "out"){
			return 0;
		}
		if(ba == "game"){
			system("cls");
			system("title game");
    		print("打怪");
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
