#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getch.h>
#include "master.h"
#include "teacher.h"
#include <stdlib.h>
#include "tools.h"

#define COUNT_MAX 100

int count=0;

//获取校长的用户名和密码
/*
先给Mas.pass
*/

void get_in(void)
{
	strcpy(Mas.tmp_pass,"admin");
//	strcpy(Mas.true_pass,"admin");
	char name[10]={};
	char mima[10]={};
	printf("请输入一个用户名:\n");
	scanf("%s", name);
	printf("请输入密码:\n");
	scanf("%s", mima);
	if(0 == strcmp(Mas.true_pass,mima))
	{
 		if(0 == strcmp("admin",mima))
		{
			rebuilt_self();
		}
		else
		{
			show_msg("登录成功!\n");
			mas_menu();
		}
	}
	else 
	{
		show_msg("输入的密码有误!\n");
	}
}
//重置自己的密码
void rebuilt_self(void)
{
	char tmp_mima1[10];
	char tmp_mima2[10];
	char tmp_mima[10];
//	char mima[10];
//	strcpy(mima,Mas.tmp_pass);//取出结构体里面的值
	printf("请输入原来的密码:");
	scanf("%s", tmp_mima);
	while(1)
	{
		if(strcmp(Mas.tmp_pass,tmp_mima)==0)//与原始的密码对比
		{
			printf("\t密码正确!\n");
			printf("请输入一个新密码:\n");
			scanf("%s", tmp_mima1);
			printf("请再次输入密码:\n");
			scanf("%s", tmp_mima2);
			if(strcmp(tmp_mima1,tmp_mima2)==0)
			{
				show_msg("修改密码成功!\n");
				strcpy(Mas.true_pass,tmp_mima1);//新密码代替旧密码
				getch();//获取字符
				break;
			}
			else
			{
				show_msg("两次输入的密码不一致!修改失败\n!");
				break;
			}
		}
		else
		{
			show_msg("输入的密码有误!\n");
			break;
		}
	}
}
//显示所有在职教师
void tch_in(void)
{
	for(int i=0;i<100;i++)
	{
		if(tch[i].sex)
		{
			printf("%s %s %d\n",tch[i].name,'w'==tch[i].sex?"女":"男",tch[i].id);
		}
	}
	anykey_continue();

}
//能重置教师的密码
void rebuilt_tch(void)
{
	char same[]="666666";
	char name[10];
	printf("请输入要重置教师的姓名:");
	scanf("%s", name);
	for(int i=0;i<100;i++)
	{
		if(0 == strcmp(tch[i].name,name))
		{
			strcpy(tch[i].pass,same);
		}
	}
	show_msg("教师密码已经重置!\n");
}


//添加教师
void add_tch(void)
{
	if(count>COUNT_MAX)
	{
		show_msg("系统正在升级,请稍后\n");
		return;
	}
	int i=0;
	while(tch[i].sex)
	{
		i++;
	}
	printf("请输入教师的姓名 性别　工号:");
	scanf("%s %c %d", tch[i].name,&tch[i].sex,&tch[i].id);
	count++;

	show_msg("添加教师成功!\n");
}
//删除教师 按名字删除
void del_tch(void)
{	int j=0;
	char name[20]={};
	printf("请输入要删除的教师姓名:");
	scanf("%s", name);
	
	for(int i=0;i<COUNT_MAX;i++)
	{
		if(0 == strcmp(name,tch[i].name))
		{
            while(0 != tch2[j].sex)	j++;//
			tch2[j]=tch[i];
			show_msg("删除联系人成功!\n");
			tch[i].sex=0;
			count--;
			return;
		}
	}
	
	show_msg("该教师不存在!\n");
}
//显示所有离职教师
void tch_out()
{
	for(int i=0;i<100;i++)
	{
		if(tch2[i].sex)
		{
			printf("%s %s %d\n",tch2[i].name,'w'==tch2[i].sex?"女":"男",tch2[i].id);
		}
	}
	anykey_continue();
}
char mas_menu(void)
{
	system("clear");
	printf("-----------校长------------\n");
	printf("1.重置教师密码\n");
	printf("2.添加教师\n");
	printf("3.删除教师\n");
	printf("4.显示所有在职教师\n");
	printf("5.显示所有离职教师\n");
	printf("6.退出学生管理系统\n");
	printf("7.输入用户名和密码:\n");
	printf("---------------------------\n");
	printf("请输入指令:");
	char cmd=getch();
	printf("%c\n",cmd);
	return cmd;
}
int main(int argc,const char* argv[])
{
	strcpy(Mas.true_pass,"admin");
	for(;;)
	{
		switch(mas_menu())
		{
			case '1': rebuilt_tch();break;
			case '2': add_tch();break;
			case '3': del_tch();break;
			case '4': tch_in();break; 
			case '5': tch_out();break;
			case '6': return 0;
			case '7': get_in();break;
		}
	}
}
