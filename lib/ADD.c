#include "../struct.h"

void info(char * func)
{
    func[0] = 'A';
    func[1] = 'D';
    func[2] = 'D';
    func[3] = 0;
};
/* Операция сложения. Результат возвращает в структуру - третий параметр */
void ADD (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = A->real + B->real;
	C->img = A->img + B->img;
};