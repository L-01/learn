#ifndef STUDENT_H
#define STUDENT_H

//初始登录
void in(void);

//正常登录
void get_in(void);

//修改密码
void rebuilt_self(void);

//查询成绩
void find_grade(void);

//查询信息
void show_infor(void);

struct Student{
    char name[20];
    char code[20];
    char code_1[20];
    char sex;
    int id;
    int g_chinese;
    int g_math;
    int g_english;
    };
extern struct Student stu[100];
#endif//STUDENT.H_H
