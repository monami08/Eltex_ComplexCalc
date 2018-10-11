#include "operations.h"
#include <math.h>
/* Операция сложения. Результат возвращает в структуру - третий параметр */
void actSUMComplex (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = A->real + B->real;
	C->img = A->img + B->img;
};
/* Операция вычитания. Результат возвращает в структуру - третий параметр */
void actMINComplex (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = A->real - B->real;
	C->img = A->img - B->img;
};
/* Операция умножения. Результат возвращает в структуру - третий параметр */
void actMULComplex (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = (A->real * B->real) - (A->img * B->img);
	C->img = (A->real * B->img) + (A->img * B->real);
};
/* Операция деления. Результат возвращает в структуру - третий параметр */
void actDEVComplex (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = (A->real * B->real + A->img * B->img) / (pow(B->real, 2) + pow(B->img, 2));
	C->img = (B->real * A->img - A->real * B->img) / (pow(B->real, 2) + pow(B->img, 2));
};
