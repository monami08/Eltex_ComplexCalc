/* Cтруктура для хранения комплексных чисел */
struct ComplexNum {
    double real;
    double img;
};
/* Операция сложения. Результат возвращает в структуру - третий параметр */
void actSUMComplex (struct ComplexNum *, struct ComplexNum *, struct ComplexNum *);
/* Операция вычитания. Результат возвращает в структуру - третий параметр */
void actMINComplex (struct ComplexNum *, struct ComplexNum *, struct ComplexNum *);
/* Операция умножения. Результат возвращает в структуру - третий параметр */
void actMULComplex (struct ComplexNum *, struct ComplexNum *, struct ComplexNum *);
/* Операция деления. Результат возвращает в структуру - третий параметр */
void actDEVComplex (struct ComplexNum *, struct ComplexNum *, struct ComplexNum *);
