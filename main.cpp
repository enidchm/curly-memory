#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct xsxx            
{
	char name[100];		
	int xh;				
	int age;	  		
	float cj;			
	float tz;			
	float sg;			
	struct xsxx* next;	
};

void chao_zhuo()
{
	printf("接下来的操作\n输入学生：		按1\n");
	printf("删除学生：		按2\n");
	printf("查询学生：		按3\n");
	printf("打印所有学生：		按4\n");
	printf("退出程序：		按5\n");
}

int main()
{
	struct xsxx s[100];
	struct xsxx* curNode = &s[0];
	int a = 0, b = 0, c, d, e = 0, f = 0, g=0;
	
	printf("欢迎使用简易学生管理系统！输入进行接下来的操作：\n");
	while (1)
	{
		chao_zhuo();
		scanf("%d", &d);

		if (d == 1)
		{
			printf("请输入学生数\n");
			scanf("%d", &a);
			if (a <= 0)
			{
				printf("输入学生数不正确\n");
				continue;
			}
			f = f + a;
			for (; e < f; e++)
			{
				printf("请输入第%d个学生的信息(名字 学号 年龄 成绩 体重(kg) 身高(m))\n", e + 1);
				scanf("%s %d %d %f %f %f", &s[e].name, &s[e].xh, &s[e].age, &s[e].cj, &s[e].tz, &s[e].sg);
				
				if (e >= 1)
				{
					if (s[e].xh == s[e - 1].xh)
					{
						printf("输入有误！（学号出现相同！）\n");
						break;
					}
				}
				if (e + 1 == f)
				{
					s[e].next = NULL;
					printf("\n储存完毕！\n\n");
					continue;
				}
				else
				{
					s[e].next = &s[e + 1];
				}
			}
			continue;
		}

		else if (d == 2)
		{
			printf("输入要删除学生学号：\n");
			scanf("%d",&c);
			if(f == 0)
			{
				printf("当前没有学生\n\n");
				continue;
			}
			for (b = 0; b < f; b++)
			{
				if (c == curNode->xh)
				{
					if (b >= 1)
					{
						s[b - 1].next = curNode->next;
					}
					else
					{
						curNode = curNode->next;
						g++;
					}
					s[b].next = NULL;
					printf("删除成功！\n\n");
					
					break;
				}
				else if(curNode==NULL)
				{
					printf("没有该学生!\n\n");
				}
			}
			continue;
		}

		else if (d == 3)
		{
			printf("输入查询学生学号：\n");
			scanf("%d", &c);
			struct xsxx* curNode = &s[0];
			if (f == 0)
			{
				printf("当前没有学生!\n\n");
				continue;
			}
			for (b = 0; b < f; b++)
			{
				if (c == curNode->xh)
				{
					printf("\n名字:%s\n学号:%d\n 年龄:%d\n 成绩:%f\n 体重(kg):%f\n 身高(m):%f\n\n", s[b].name, s[b].xh, s[b].age, s[b].cj, s[b].tz, s[b].sg);
					break;
				}
				else if(f==b+1)
				{
					printf("没有查询到该生！\n\n");
				}
				curNode = curNode->next;
			}
			continue;
		}
	}

	return 0;
}