//Написать программу, которая определяет количество уникальных
//элементов в заданном целочисленном массиве
//1. Найти максимальный элемент в массиве
//2. Определить маркер (notExist), которое больше максимума
//3. Перебрать массив: для каждого элемента найти все его дубликаты справа
//и заменить их на значение-маркер
//4. Подсчитать количество элементов, которые не равны маркеру


#include <stdio.h>


int main()
{
    const int szz = 10;
    int array[szz] = {5,5,7,3,3,2,2,1,1,10};
    int max = array[0];
    for(int i=1;i < szz;i++)
        if(array[i] > max) max = array[i];
    bool unique = true;
    int notExist = max+1;
    int countEl=0;
    for(int i=0;i < szz;i++)
    {
        int jx = i+1;
        if(array[i]!= notExist)
        {
            unique = true;
            while(jx < szz)
            {
                if(array[jx]!= notExist)
                {
                    if(array[i] == array[jx])
                    {
                        array[jx] = notExist;

                    }
                }
                jx++;
            }
        }
        else
            unique = false;
        if(unique)
            countEl++;
        else
            array[i] = notExist;
    }

    printf("countEl = %d", countEl);
}
