#include <stdio.h>
#include <math.h>
#include "operations.h"

/* Спрашивает о действии и возвращает ответ */
int interFace()
{
    int num;
    printf("\033[2J\033[0;0f");
    printf("Choose action for a Complex Numbers:\n");
    printf("1) SUM\t-\t+\n");
    printf("2) MIN\t-\t-\n");
    printf("3) MUL\t-\t*\n");
    printf("4) DEV\t-\t/\n");
    printf("5) Quit\n");
    printf(">  ");
    scanf("%d", &num);
    getchar();
    return num;
};

/* Запрашивает и сохраняет комплексное число в структуру*/
void getComplexNum(struct ComplexNum * CN)
{

    char str[25];
    char a[10],b[10];
    char sign1 = '+';
    char sign2;
    int i = 0;
    int temp;
    /* Функция вывода ошибки ввода */
    void Err()
    {
	printf ("ERROR type! Try again.\n\n");
	getComplexNum( CN );
    };
    /* Считываем строку - комплексное число */
    printf("Please Enter a complex number in the classical form (a + bi):\n");
    fgets (str, 25, stdin);
    

    for (i; str[i] == ' '; i++);	/* пропускаем в строке все пробелы */
    if (str[i] == '-')			/* Если есть записываем знак первого числа */
    {
	sign1 = str[i];
	i++;
    };
    /* Считываем первое число в отдельную строку*/
    for (i; ((str[i] >= '0')&&(str[i] <= '9')); i++)
	a[i] = str[i];
    if (i == 0)
    {
	Err();
	return;
    };
    a[i] = 0;	/* завершаем строку с первым числом */

    for (i; str[i] == ' '; i++);	/* далее пропускаем в строке все пробелы */
    /* Считываем знак второго числа в переменную sign2, если тут что-то кроме +/-, то ошибка */
    if ((str[i] != '+')&&(str[i] != '-'))
    {
	Err();
	return;
    };
    sign2 = str[i];
    i++;

    for (i; str[i] == ' '; i++);	/* далее пропускаем в строке все пробелы */
    /* Считываем второе число в отдельную строку*/
    temp = i;
    for (i; ((str[i] >= '0')&&(str[i] <= '9')); i++)
	b[i - temp] = str[i];
    if ((i - temp) == 0)
    {
	Err();
	return;
    };
    b[i - temp] = 0;

    /* Если в конце не стоит мнимая единица "i", то - ошибка ввода */
    if (str[i] != 'i')
    {
	Err();
	return;
    };

    /* Перевод первого числа из строки в число */
    temp = 0;
    for (i = 0; a[i] != 0; i++);
    for (int p = 0; i != 0; p++)
    {
	i--;
	temp = temp + ((int)a[i] - (int)'0') * pow(10, p);
    };
    if (sign1 == '+')
    	CN->real = (double)temp;
    else
	CN->real = (double)(temp * (-1));

    /* Перевод второго числа из строки в число */
    temp = 0;
    for (i = 0; b[i] != 0; i++);
    for (int p = 0; i != 0; p++)
    {
	i--;
	temp = temp + ((int)b[i] - (int)'0') * pow(10, p);
    };
    if (sign2 == '+')
    	CN->img = (double)temp;
    else
	CN->img = (double)(temp * (-1));
};

/* Запрашивает и сохраняет комплексные числа в структуры*/
void getComplexNums(struct ComplexNum * A, struct ComplexNum * B)
{
    printf ("First complex number.\n");
    getComplexNum ( A );
    printf ("Second complex number.\n");
    getComplexNum ( B );
};

/* Выводит результат */
void showResult (struct ComplexNum CN)
{
    printf ("\nResult: ");
    if (CN.img >= 0)
	printf ("%f + %fi", CN.real, CN.img);
    else
	printf ("%f - %fi", CN.real, CN.img * (-1));
    getchar();
};




















