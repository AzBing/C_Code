#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//初始化通讯录
//void InitContact(Contact* pc)
//{
//	memset(pc->data, 0, sizeof(pc->data));
//	pc->sz = 0;
//}
int Capacity(Contact* pc);

void LoadContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("Contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	PeoInfo ret = { 0 };
	while (fread(&ret, sizeof(PeoInfo), 1, pf))
	{
		if ((Capacity(pc)) == 0)
		{
			return;
		}
		pc->data[pc->sz] = ret;
		pc->sz++;
	}


	//关闭文件
	fclose(pf);
	pf = NULL;
}


//动态版本
void InitContact(Contact* pc)
{
	assert(pc);
	pc->data = (PeoInfo*)malloc(3 * (sizeof(PeoInfo)));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = 3;

	//文件保存的信息提前保存到通讯录中
	LoadContact(pc);

}

//静态版本
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法添加\n");
//		return ;
//	}
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->data[pc->sz].addr);
//
//
//	pc->sz++;
//	printf("成功添加联系人\n");
//}

int Capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ret = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (ret == NULL)
		{
			perror("Capacity");

			return 0;
		}
		else
		{
			pc->data = ret;
			pc->capacity += 2;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;

}

//动态版本
void AddContact(Contact* pc)
{
	if (0 == Capacity(pc))
	{
		return;
	}

	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);


	pc->sz++;
	printf("成功添加联系人\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%12s\t%20s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%5d\t%5s\t%12s\t%20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}

}

int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除联系人的姓名:>");
	scanf("%s", name);
	//查找联系人
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("要删除的联系人不存在\n");	
		return;
	}
	int i = 0;
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;

	printf("成功删除联系人\n");
}


void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找联系人的名字:>");
	scanf("%s", name);
	int sear = FindByName(pc, name);
	if (sear == -1)
	{
		printf("要查找人不存在\n");
		return;
	}
	else
	{
		printf("%10s\t%5s\t%5s\t%12s\t%20s\n", "姓名", "年龄", "性别", "电话", "地址");

		printf("%10s\t%5d\t%5s\t%12s\t%20s\n",
				pc->data[sear].name,
				pc->data[sear].age,
				pc->data[sear].sex,
				pc->data[sear].tele,
				pc->data[sear].addr);
	}

}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改联系人的名字:>");
	scanf("%s", name);
	int sear = FindByName(pc, name);
	if (sear == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[sear].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[sear].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[sear].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[sear].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[sear].addr);

		printf("修改成功\n");
	}

}


int cmp_str_name(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);

}

void SortContact(Contact* pc)
{
	assert(pc);
	//按姓名排序
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_str_name);
	printf("排序成功\n");
}


void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;

}


void SaveContact(Contact* pc)
{
	FILE* pf = fopen("Contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

