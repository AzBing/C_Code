#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//��ʼ��ͨѶ¼
//void InitContact(Contact* pc)
//{
//	memset(pc->data, 0, sizeof(pc->data));
//	pc->sz = 0;
//}
int Capacity(Contact* pc);

void LoadContact(Contact* pc)
{
	//���ļ�
	FILE* pf = fopen("Contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//���ļ�
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


	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


//��̬�汾
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

	//�ļ��������Ϣ��ǰ���浽ͨѶ¼��
	LoadContact(pc);

}

//��̬�汾
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return ;
//	}
//	printf("����������:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("����������:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������Ա�:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("������绰:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ:>");
//	scanf("%s", pc->data[pc->sz].addr);
//
//
//	pc->sz++;
//	printf("�ɹ������ϵ��\n");
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
			printf("���ݳɹ�\n");
			return 1;
		}
	}
	return 1;

}

//��̬�汾
void AddContact(Contact* pc)
{
	if (0 == Capacity(pc))
	{
		return;
	}

	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);


	pc->sz++;
	printf("�ɹ������ϵ��\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ����ϵ�˵�����:>");
	scanf("%s", name);
	//������ϵ��
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");	
		return;
	}
	int i = 0;
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;

	printf("�ɹ�ɾ����ϵ��\n");
}


void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ������ϵ�˵�����:>");
	scanf("%s", name);
	int sear = FindByName(pc, name);
	if (sear == -1)
	{
		printf("Ҫ�����˲�����\n");
		return;
	}
	else
	{
		printf("%10s\t%5s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

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
	printf("������Ҫ�޸���ϵ�˵�����:>");
	scanf("%s", name);
	int sear = FindByName(pc, name);
	if (sear == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[sear].name);
		printf("����������:>");
		scanf("%d", &(pc->data[sear].age));
		printf("�������Ա�:>");
		scanf("%s", pc->data[sear].sex);
		printf("������绰:>");
		scanf("%s", pc->data[sear].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[sear].addr);

		printf("�޸ĳɹ�\n");
	}

}


int cmp_str_name(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);

}

void SortContact(Contact* pc)
{
	assert(pc);
	//����������
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_str_name);
	printf("����ɹ�\n");
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

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

