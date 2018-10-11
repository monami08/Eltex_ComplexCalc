#include <stdio.h>
#include "operations.h"
#include "interface.h"

int main()
{
    int n = 0;
/* создаются три комплексных числа. Третье для сохранения результата */
    struct ComplexNum A;
    struct ComplexNum B;
    struct ComplexNum C;

    while (1)
    {
	/* Спрашивает о действии и возвращает ответ */
	n = interFace();			
	switch ( n ) 
	{
	    case 1:
		/* Запрашивает и сохраняет комплексные числа в структуры*/
		getComplexNums(&A, &B);	
		/* Операция сложения. Результат возвращает в структуру - третий параметр */
		actSUMComplex (&A, &B, &C);
		/* Вывод результата */
		showResult (C);
		break;
	    case 2:
		/* Запрашивает и сохраняет комплексные числа в структуры*/
		getComplexNums(&A, &B);
		/* Операция вычитания. Результат возвращает в структуру - третий параметр */
		actMINComplex (&A, &B, &C);
		/* Вывод результата */
		showResult (C);
		break;
	    case 3:
		/* Запрашивает и сохраняет комплексные числа в структуры*/
		getComplexNums(&A, &B);
		/* Операция умножения. Результат возвращает в структуру - третий параметр */
		actMULComplex (&A, &B, &C);
		/* Вывод результата */
		showResult (C);
		break;
	    case 4:
		/* Запрашивает и сохраняет комплексные числа в структуры*/
		getComplexNums(&A, &B);
		/* Операция деления. Результат возвращает в структуру - третий параметр */
		actDEVComplex (&A, &B, &C);
		/* Вывод результата */
		showResult (C);
		break;
	    case 5:
		return 0;
		break;
	    default:
		printf("!!!ERROR!!! Please enter a number between 1 and 5\n");
		getchar();
		break;
	};
    };
};