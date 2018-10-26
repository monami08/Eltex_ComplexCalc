#include "../struct.h"
#include <math.h>

void info(char * func)
{
    func[0] = 'D';
    func[1] = 'E';
    func[2] = 'V';
    func[3] = 0;
};

/* Операция деления. Результат возвращает в структуру - третий параметр */
void DEV (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = (A->real * B->real + A->img * B->img) / (pow(B->real, 2) + pow(B->img, 2));
	C->img = (B->real * A->img - A->real * B->img) / (pow(B->real, 2) + pow(B->img, 2));
};