#include "../struct.h"
void info(char * func)
{
    func[0] = 'M';
    func[1] = 'U';
    func[2] = 'L';
    func[3] = 0;
};
/* Операция умножения. Результат возвращает в структуру - третий параметр */
void MUL (struct ComplexNum *A, struct ComplexNum *B, struct ComplexNum *C)
{
	C->real = (A->real * B->real) - (A->img * B->img);
	C->img = (A->real * B->img) + (A->img * B->real);
};