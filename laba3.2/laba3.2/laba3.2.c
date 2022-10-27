#include <stdio.h>
#include <time.h>
int main() {
    int massiv[100];
    int n;
    int x, j = 0, k = 0, sum = 0, proizvedenie = 1;
    printf("enter the number of elements array (from 1 to 100)\n");
    while (scanf_s("%d", &n) != 1 || n > 100 || n < 1 || getchar() != '\n')//вводим количество элементов массива и проверяем на ввод
    {
        printf("error, enter the number of elements (from 1 to 100)\n");
        rewind(stdin);
    }
    printf("to enter array elements from the keyboard, click 1\n");
    printf("to enter in the array elements randomly, click 2\n");
    scanf_s("%d", &x);//выбираем метод заполнения 
    switch (x)
    {
    case 1:
        printf(" enter %d  elements array: \n", n);//колличество элементов массива
        for (int i = 0; i < n; i++) // number колличество элементов в массиве
        {
            printf(" %d  elements array: ", i + 1);//выводит элементы массива
            while (scanf_s("%d", &massiv[i]) != 1 || getchar() != '\n')//вводим элементы массива
            {
                printf("error\n");
                rewind(stdin);
            }
        }
        break;
    case 2:
        srand(time(NULL));//каждый раз новое случайное число
        for (int i = 0; i < n; i++)
        {
            massiv[i] = rand() % 100; //рандомное заполнение массива
            printf(" %d  elements array %d \n", i + 1, massiv[i]);
        }
        break;
    default:
        printf("error\n");
        return 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (massiv[i] % 2 == 0 && massiv[i] != 0)
        {
            n++;
            for (int j = n - 1; j > i; j--)
            {
                massiv[j] = massiv[j - 1];
            }
            massiv[i + 1] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", massiv[i]);
    }
    return 0;
}