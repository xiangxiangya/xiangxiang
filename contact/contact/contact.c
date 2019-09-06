#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

static int IsFull(contact_p ct)//ÅÐ¶ÏÍ¨Ñ¶Â¼ÊÇ·ñÂú
{
	return ct->size == ct->cap ? 1 : 0;
}

static int Inc(contact_pp _ctpp)
{
	int new_size = sizeof(contact_t)+((*_ctpp)->size + INC_SIZE)*sizeof(person_t);
	contact_p p = realloc(*_ctpp, new_size);
	if (!p)
	{
		printf("Inc error!\n");
		return 0;
	}
	p->cap = (*_ctpp)->cap + INC_SIZE;
	*_ctpp = p;
	printf("debug:Inc Contzct Sucess!\n");
	return 1;
}





//0 ¡ª¡ª>false
void InitContact(contact_pp _ctpp)
{ 
	*_ctpp = malloc(sizeof(contact_t)+sizeof(person_t)*LIST_DEFAULT);
	if (!_ctpp)
	{
		printf("%d:%s", errno, strerror(errno));
		exit(1);//ÖÕÖ¹³ÌÐò
	}
	(*_ctpp)->cap = LIST_DEFAULT;
	(*_ctpp)->size = 0;
	printf("debug:Init Contact Sucess!\n");
}

void Show(contact_p ct)
{
	int top = ct->size;
	int i = 0;
	person_p p = ct->list;
	for (i = 0; i < top; i++)
	{
		printf("|%-6s|%-2c|%-3d|%-12s|%-16s|\n", p[i].name, p[i].sex, p[i].age, p[i].tlephone, p[i].address);
	}
}

void AddContact(contact_pp ct)
{
	if (!IsFull(*ct) || Inc(ct))
	{
		person_p p = &((*ct)->list[(*ct)->cap]);
		printf("Please Enter Name:");
		scanf(" %s", p->name);
		printf("Please Enter Sex:");
		scanf(" %c", &(p->sex));
		printf("Please Enter Age:");
		scanf(" %s",&( p->age));
		printf("Please Enter Telphone:");
		scanf(" %s", p->tlephone);
		printf("Please Enter Address:");
		scanf(" %s", p->address);
		((*ct)->size)++;
	}
	else
	{
		printf("realloc error!\n");
		return;
	}
	
}

