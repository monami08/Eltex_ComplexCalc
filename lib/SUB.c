#include "../struct.h"
void info(char * func)
{
    func[0] = 'S';
    func[1] = 'U';
    func[2] = 'B';
    func[3] = 0;
};
/* Операция вычитания. Результат возвращает в структуру - третий параметр */
void SUB (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = A->real - B->real;
	C->img = A->img - B->img;
};