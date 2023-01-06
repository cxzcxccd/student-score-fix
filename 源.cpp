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
	//����ѧ������
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
	printf("��ѡ�����Ĳ�ѯ��ʽ   1. ѧ��  2 . ����  3.����");
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
   //��ӡ����Ҫ�鳭ѧ�������
   for (int i = 0; i < j; i++)   printf("%d ", res[i]+1);   
}
void DEL()
{
   //����ѧ��ѧ��  
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
	//ѧ����������ȥһ
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
	printf("������ѧ��������Ϊ%d", t);
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

	printf("ѧ�����ܳɼ�Ϊ%d\n", sum);
	printf("ѧ����ƽ���ɼ�Ϊ%d\n", sum / n);
	printf("��߷���Ϣ\n");
	printf("%s ", sb[maxk].Snu);
	printf("%s ", sb[maxk].name);
	printf("%s ", sb[maxk].pnum);
	printf("%s ", sb[maxk].jiguan);
	printf("%s ", sb[maxk].zhuzhi);
	printf("%d\n", sb[maxk].score);
	printf("��ͷ���Ϣ\n");
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
	printf("����a ͨ������¼��ѧ����Ϣ\n");
	printf("����b ͨ��ѧ�Ż������򼮹��ѯ���ѧ����Ϣ\n");
	printf("����c ͨ��ѧ��ɾ��ѧ����Ϣ\n");
	printf("����d ��ʾ����ѧ������Ϣ\n");
	printf("����e  ��ѧ���ɼ��Ӹߵ��׽������򣨴��棩\n");
	printf("����f  ��ӡ��������ѧ���������ͳɼ�(����)\n");
	printf("����g   ͳ�Ʋ�����Ļ��ӡ��ƽ�������ܷ֣�����Ļ��ӡ��߷���ͷ�ѧ����Ϣ\n");
	char c;
	scanf_s("%c", &c);
	if (c == 'a')  READIN();//ͨ�����������¼��ѧ����Ϣ����׷�ӵ�ѧ�������ļ�������������20��ѧ����Ϣ��
	if (c == 'b')  FIND();//ͨ��ѧ�Ż������򼮹ᣨ�����ж��������ͬѧ�����ɲ�ѯ���ѧ����Ϣ��
	if (c == 'c')  DEL();//ͨ��ѧ��ɾ��ѧ����Ϣ��ɾ��ѧ�������ļ��е���Ϣ����
	if (c == 'd') PRINT();//��ʾ����ѧ����Ϣ��
	if (c == 'e')   SORT();//�Խ��гɼ����򣨴Ӹߵ��ͣ�������������ʾ���洢���ļ�sort.txt��
	if (c == 'f')   PRINTFAIL();//����Ļ�ϴ�ӡ��������ѧ��������������ѧ����Ϣ������������ѧ����Ϣ�洢���ļ�fail.txt��
	if (c == 'g')      PRINTEXL();//ͳ�Ʋ�����Ļ��ӡ��ƽ�������ܷ֡�����Ļ��ӡ��߷���ͷ�ѧ����Ϣ��
	return 0;
}