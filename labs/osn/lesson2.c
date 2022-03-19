#include <stdio.h>
char arr[256] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

char count_ones(unsigned long long n)
{
    char w = 0;
    while (n > 0)
    {                      // не может быть более 8 итераций
        w += arr[n & 255]; // n % 256
        // логическое умножение на маску 0b11111111
        n = n >> 8;
    }
    return w;
}
void main()
{
    int mass[9] = {0};
    unsigned int n_32 = 0;
    unsigned long long n_64 = 0;
    printf("zero 32: %d\n", count_ones(n_32));
    printf("zero 64: %d\n", count_ones(n_64));

    n_32 = 0xffffffff;         // 4294967295
    n_64 = 0xffffffffffffffff; // 1844674407370955161
    printf("test 32: %d\n", count_ones(n_32));
    printf("test 64: %d\n", count_ones(n_64));

    n_32 = 42;
    n_64 = 4242424242424242;
    printf("rand 32: %d\n", count_ones(n_32));
    printf("rand 64: %d\n", count_ones(n_64));

    int n_7 = 7;
    int n_28 = 28;
    printf("n_7: %d\n", count_ones(n_7));
    printf("b_28: %d\n", count_ones(n_28));


    // Пусть числа содержат l-разрядов
    // массив А[l+1] = {0};
    // цикл для i от 0 до 2**l:
    // индекс = счёт_один(i) // определение числа единиц в числе i
    // A[индекс] = A[индекс] + 1; // увеличиваем счётчик по индексу в зависимости от числа единиц.
    // вывод массива А;
    for (int i = 0; i < 256; i++)
    {
        mass[count_ones(i)]++;
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", mass[i]);
    }
}