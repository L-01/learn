#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getch.h>
#include <string.h>
#include "student.h"

struct Student stu[100];
static int count = 0;
static int cnt=0;
void show_msg(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

void anykey_continue(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	puts("任意键继续……");
	getch();
}

void rebuilt_self();

void in(void)
{
	if(count >= 100)

{
		puts("系统正在升级,请等待……");
		return;
	}
	printf("新用户初始密码为123456\n");
	strcpy(stu[0].code_1,"123456");
	char name[10]={};
	char code[10]={};
	printf("请输入用户名\n");
	scanf("%s",name);
	printf("请输入密码：\n");
	scanf("%s",code);
	if(0 == strcmp(code,stu[0].code_1))
	{
		strcpy(stu[0].name,name);
		strcpy(stu[0].code,stu[0].code_1);
		rebuilt_self();
	}
	else
	{
		printf("输入的密码有误！\n");
		return;
	}
	count++;
}
void show_infor(void)
{
	char sex1[10]={};
	printf("请输入性别和学号\n");
	scanf("%c %d",&sex1,&stu[0].id);
	printf("%s %s %d\n",stu[0].name,'w'==stu[0].sex?"女":"男",stu[0].id);
	anykey_continue();
}
void get_in(void)
{
	char name[10]={};
	char code[10]={};
	if(cnt>3)
	{
		show_msg("账户已锁，请找老师解锁!",0.5);
		return;
	}
	else
	{
	printf("请登录并输入姓名:\n");
	scanf("%s",name);
	if(0 != strcmp(name,stu[0].name))
	{
		show_msg("输入的用户名不对,程序结束！\n",0.5);
	return;
	}
	printf("请输入密码：\n");
	scanf("%s",code);
	if(0 == strcmp(code,stu[0].code))
	{
		show_msg("正确\n",0.5);
		return;
	}
	else
	{
		cnt++;
		show_msg("输入的密码有误，请重新登录！\n",0.5);
		return;
	}
}
}
void rebuilt_self(/*char* str*/)
{
	char tmp_mima1[10];
	char tmp_mima2[10];
	char tmp_mima[10];
	char mima[10];
	char name[10];
	printf("请输入姓名：");
	scanf("%s",name);
	if(0 != strcmp(name,stu[0].name))
	{
		show_msg("输入的姓名不正确!",0.5);
		return;
	}
	printf("请输入原来的密码:\n");
	scanf("%s", tmp_mima);
	while(1)
	{
	if(strcmp(tmp_mima,stu[0].code)==0)//与原始的密码对比
	{
		printf("\t密码正确!\n");
		printf("\t请输入一个新密码:\n");
		scanf("%s", tmp_mima1);
		printf("\t请再次输入密码:\n");
		scanf("%s", tmp_mima2);
		if(strcmp(tmp_mima1,tmp_mima2)==0)
	{
		printf("修改密码正确!\n");
		strcpy(stu[0].code,tmp_mima2);//新密码代替旧密码
		getch();//获取字符
		get_in();
		break;
	}
	else
	{
		printf("两次输入的密码不一致!修改失败\n!");
		break;
	}	
	}
	else
	{	
		printf("输入的密码有误!\n");
		break;
}
}
}
void find_grade()
{
	int tch_chinese=0,tch_math=0,tch_english=0, max=0,min=0;
	int avg =0;
	printf("请输入语文、数学、英语的成绩:\n");
	scanf("%d %d %d",&tch_chinese,&tch_math,&tch_english);
	if(tch_chinese > tch_math)
	{
		if(tch_math > tch_english)
		{
			printf("最高分为语文:%d，最低分英语为:%d\n",tch_chinese,tch_english);
		}
		else if(tch_chinese > tch_english && tch_english > tch_math)
		{
			printf("最高分为语文:%d，最低分为数学:%d\n",tch_chinese,tch_math);
		}
		else
		{
			printf("最高分为英语:%d,最低分为数学:%d\n",tch_english,tch_math);
		}
	}
	else
	{
		if(tch_chinese > tch_english)
		{
			printf("最高分为数学:%d,最低分为英语:%d\n",tch_math,tch_english);
		}
		else if(tch_english > tch_chinese && tch_math > tch_english)
		{
			printf("最高分为数学:%d,最低分为语文:%d\n",tch_math,tch_chinese);
		}
		else
		{
			printf("最高分为英语:%d,最低分为语文:%d\n",tch_english,tch_chinese);
		}
	}
	printf("平均分为:%d",avg=(tch_chinese+tch_math+tch_english)/3);
	fflush(stdout);
	sleep(2);
	return;
}
char stu_menu(void)
{
	system("clear");
	puts("1、初始登录");
	puts("2、登录");
	puts("3、查询成绩");
	puts("4、修改密码");
	puts("5、查看个人信息");
	puts("6、退出");
	puts("------------------");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;
}

int main(int argc,const char* argv[])
{
	for(;;)
	{
	    switch(stu_menu())
	{
	    case '1':in();break;
	    case '2':get_in();break;
	    case '3':find_grade();break;
		case '4':rebuilt_self();break;
		case '5':show_infor();break;
		case '6':return 0;
	}
	}

}
