
#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char arr1[6] = {'5', '3', '7', '1', '9', '3'};
    char arr2[6] = {'1', '2', '3', '4', '5', '6'};
    int *result = (int *) malloc(sizeof(int));




    int count_result = 0;
    count_result = max(sizeof(arr1), sizeof(arr2)) + 1;
    result = (int *) realloc(result, count_result * sizeof(int));
    for (int i = 0; i < count_result; i++)
    {
        result[i] = 0;
    }



    summ(arr1, arr2, result, count_result);
    return 0;
}
// О, Максимка, а ты знаешь что я тебя люблю? вот, а я тебя люблю, да! И ещё
// Сегодня мы пойдем ловить мумий. У тебя прекрасная улыбка :3 Я вот знаю что ты читаешь это и улыбаешься
// Вот, улыбайся всегда <3 Бип. Боб. Я твоя программа, и я умею говорить,да...
// Ты главное не переживай, у тебя все получится :з Я знаю, ты очень умный мальчик 
// Кусь кусь кусь. Это что бы не расслаблялся с: