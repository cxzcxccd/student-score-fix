#include<stdio.h>
#include<string.h>
typedef struct student
{
	char Snu[30];
	char name[100];
	char pnum[100];
	char jiguan[100];
	char zhuzhi[100];
	int score;
} st;
int n;
st      sb[100];
void READIN()
{
	//输入学生人数
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%s", sb->Snu);
		scanf_s("%s", sb->name);
		scanf_s("%s", sb->pnum);
		scanf_s("%s", sb->jiguan);
		scanf_s("%s", sb->zhuzhi); 
		scanf_s("%d", &sb->score);
	}
}
void FIND()
{
	printf("请选择您的查询方式   1. 学号  2 . 姓名  3.籍贯");
	int w;
	scanf_s("%d", &w);
	char s[300];
	int res[100];
	int j = 0;
   scanf_s("%s", s);
   if (w == 1)
   {
	   for (int i = 1; i <= n; i++)
	     {
		   if (strcmp(s, sb[i].Snu) == 0) res[j++] = i;
     	  }
   }
   else if (w == 2)
   {
	   for (int i = 1; i <= n; i++)
	   {
		   if (strcmp(s, sb[i].name) == 0) res[j++] = i;
	   }
   }
   else {
	   for (int i = 1; i <= n; i++)
	   {
		   if (strcmp(s, sb[i].jiguan) == 0) res[j++] = i;
	   }
   }
   //打印出想要查抄学生的序号
   for (int i = 0; i < j; i++)   printf("%d ", res[i]+1);   
}
void DEL()
{
   //输入学生学号  
	char s[300];
	scanf_s("%s", s);
	int k;
	for (int i = 1; i <= n; i++)
	{
		if (!strcmp(s, sb[i].Snu))
		{
			k = i;
			break;
		}
	}
	for (int i = k; i <= n; i++)
	{
		sb[i] = sb[i + 1];
	}
	//学生总人数减去一
	n--;
}
void PRINT()
{
	for (int i = 1; i <= n; i++)
	{
		printf("%s ", sb[i].Snu);
		printf("%s ", sb[i].name);
		printf("%s ", sb[i].pnum);
		printf("%s ", sb[i].jiguan);
		printf("%s ", sb[i].zhuzhi);
		printf("%d\n", sb[i].score);
	}
}
void SORT()
{
	for (int i = 1; i <= n-1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (sb[j].score > sb[i].score) //swap(sb[i],sb[j]);
			{
				st  ll;
				ll=sb[i];
				sb[i] = sb[j];
				sb[j] = ll;
			}
		}
	}
}
void PRINTFAIL()
{
	int t = 0;
	int res[300];
	int j = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sb[i].score < 60)
		{
			t++;
			res[j++] = i;
		}
	}
	for (int i = 0; i < j; i++)
	{
		printf("%s ", sb[res[i]].Snu);
		printf("%s ", sb[res[i]].name);
		printf("%s ", sb[res[i]].pnum);
		printf("%s ", sb[res[i]].jiguan);
		printf("%s ", sb[res[i]].zhuzhi);
		printf("%d\n", sb[res[i]].score);
	}
	printf("不及格学生的人数为%d", t);
}
void  PRINTEXL()
{
	int sum = 0;
	int maxk=1;
	int mink = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += sb[i].score;
		if (sb[i].score > sb[maxk].score) maxk = i;
		if (sb[i].score <sb[mink].score) mink = i;
	}

	printf("学生的总成绩为%d\n", sum);
	printf("学生的平均成绩为%d\n", sum / n);
	printf("最高分信息\n");
	printf("%s ", sb[maxk].Snu);
	printf("%s ", sb[maxk].name);
	printf("%s ", sb[maxk].pnum);
	printf("%s ", sb[maxk].jiguan);
	printf("%s ", sb[maxk].zhuzhi);
	printf("%d\n", sb[maxk].score);
	printf("最低分信息\n");
	printf("%s ", sb[mink].Snu);
	printf("%s ", sb[mink].name);
	printf("%s ", sb[mink].pnum);
	printf("%s ", sb[mink].jiguan);
	printf("%s ", sb[mink].zhuzhi);
	printf("%d\n", sb[mink].score);
}
int main()
{
	printf("*********************\n");
	printf("输入a 通过键盘录入学生信息\n");
	printf("输入b 通过学号或姓名或籍贯查询相关学生信息\n");
	printf("输入c 通过学号删除学生信息\n");
	printf("输入d 显示所有学生的信息\n");
	printf("输入e  对学生成绩从高到底进行排序（储存）\n");
	printf("输入f  打印出不及格学生的人数和成绩(储存)\n");
	printf("输入g   统计并在屏幕打印出平均分与总分，在屏幕打印最高分最低分学生信息\n");
	char c;
	scanf_s("%c", &c);
	if (c == 'a')  READIN();//通过键盘输入可录入学生信息，并追加到学生数据文件。（至少输入20个学生信息）
	if (c == 'b')  FIND();//通过学号或姓名或籍贯（可能有多个籍贯相同学生）可查询相关学生信息。
	if (c == 'c')  DEL();//通过学号删除学生信息（删除学生数据文件中的信息）。
	if (c == 'd') PRINT();//显示所有学生信息；
	if (c == 'e')   SORT();//对进行成绩排序（从高到低），将排序结果显示并存储在文件sort.txt；
	if (c == 'f')   PRINTFAIL();//在屏幕上打印出不及格学生人数及不及格学生信息，并将不及格学生信息存储在文件fail.txt；
	if (c == 'g')      PRINTEXL();//统计并在屏幕打印出平均分与总分、在屏幕打印最高分最低分学生信息。
	return 0;
}