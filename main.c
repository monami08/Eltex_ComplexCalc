#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
#include "struct.h"
#include "interface.h"

#define MAX_NAME 20

int main()
{
    int chose = 100;	/* Переменная для выбора из меню */
    int numFuncs = 0;	/* Кол-во загруженных модулей */
    char * funcs;
/* создаются три комплексных числа. Третье для сохранения результата */
    struct ComplexNum A;
    struct ComplexNum B;
    struct ComplexNum C;
    DIR *dir;		/* указатель на загруженную дирректорию */
    struct dirent *dp;  /* Структура дирректории */
    int i;		/* для счетчика */

    void ** dd;		/* Массив дуказателей для подгружаемых библиотек */
    void (*Function)();	/* Универсальный указатель на функцию */


    dir=opendir("lib/");		/* Открыть деррикторию */
    while( (dp=readdir(dir)) != NULL )  /* Прочитать все файлы в ней */
    {	/* посчитав кол-во файлов *.so в дирректории */
	for (i = 0; dp->d_name[i] != 0; i++);
	if ((i > 3)&&( !strcmp(&(dp->d_name[i-3]), ".so")))
	    numFuncs++;
    }; 
    closedir(dir);		/* Закрыть дирректорию */
    /* Выделить память для имен файлов библиотек */
    funcs = (char *) malloc (numFuncs * NAME_MAX);
    /* Еще раз прочитать дирректорию и записать все имена библиотек в массив */
    numFuncs = 0;
    dir = opendir("lib/");
    while( (dp=readdir(dir)) != NULL )
    {
	for (i = 0; dp->d_name[i] != 0; i++);
	if ((i > 3)&&( !strcmp(&(dp->d_name[i-3]), ".so")))
	{
	    strcpy (&funcs[numFuncs * NAME_MAX], "lib/");
	    strcat (&funcs[numFuncs * NAME_MAX], dp->d_name);
	    numFuncs++;
	};
    }; 
    closedir(dir);

    /* массив указателей на подгруженные библиотеки */
    dd = (void *) malloc (numFuncs * sizeof(void*));

    /* подгрузить все необходимые библиотеки */
    for (i = 0; i < numFuncs; i++)
	dd[i] = dlopen(&funcs[i * NAME_MAX], RTLD_NOW);

    /* Заменить названия библиотек на названия в них содержащихся функций */
    for (i = 0; i < numFuncs; i++)
    {
	/* Используя универсальную библиотечную фун-ию void info (char *) */
	Function = dlsym(dd[i], "info");
	Function (&funcs[i * NAME_MAX]);
    };

    /* Цикл - меню выбора пока не выбран 0*/
    while (chose)
    {
	/* Вывод меню на чистом экране и выбор элемента меню*/
	printf("\033[2J\033[0;0f");
    	printf("Choose action for a Complex Numbers:\n");
	for (i = 0; i < numFuncs; i++)
	    printf("%d) %s\n", i+1, &funcs[i * NAME_MAX]);
	printf("0) EXIT\n>  ");
	scanf("%d", &chose); getchar();
	
	/* Если выбран пункт меню */
	if((chose)&&(chose <= numFuncs)){
	    /* то просьба ввести комплексные числа */
	    getComplexNums(&A, &B);
	    /* получение и выполнения функции из библиотеки */
	    Function = dlsym(dd[chose - 1], &funcs[(chose - 1) * NAME_MAX]);
	    Function(&A, &B, &C);
	    /* Вывод резулдьтата */
	    showResult (C);
	};
    };

    /* Выгрузить библиотеки */
    for (i = 0; i < numFuncs; i++)
	dlclose(dd[i]);
    /* И освободить память */
    free(dd);
    free(funcs);

    return 0;
};