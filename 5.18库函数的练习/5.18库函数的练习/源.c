#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

//strtokµÄÓ¦ÓÃ
//int main()
//{
//	char str[] = "hello world,hello*bit";
//	char *p = strtok(str, " ,*");
//	while (NULL != p)
//	{
//		printf("sub:%s\n", p);
//		p = strtok(NULL, " ,*");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{	
//	char str[] = "- This, a sample string.";
//	char * pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	FILE * pFile;
//	pFile = fopen("unexist.ent", "r");
//	if (pFile == NULL)
//	{
//		printf("%d  Error opening file unexist.ent: %s\n", errno,strerror(errno));
//	}
//		
//	//errno: Last error number
//	system("pause");
//	return 0;
//}

int main()
{
	char str[] = "can be very useful......";
	memmove(str+1, str, 11);
	puts(str);
	system("pause");
	return 0;
}


