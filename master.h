#ifndef MASTER_H
#define MASTER_H
struct Master{
	char name[20];
	char tmp_pass[10];
	char true_pass[10];
}Mas;
//登录，判断密码
void get_in(void);

//重置自己的密码
void rebuilt_self(void);

//显示所有在职教师
void tch_in(void);

//能重置教师的密码
void rebuilt_tch(void);

//添加教师
void add_tch(void);

//删除教师 按名字删除
void del_tch(void);

//显示所有离职教师
void tch_out();

//菜单
char mas_menu(void);
#endif//MASTER_H
