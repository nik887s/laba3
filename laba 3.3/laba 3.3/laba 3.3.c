#include <stdio.h>
#include <time.h>
int main() {
    int massiv1[100], massiv2[100];
    int n=10;
    int x,y, j = 0, k = 0, sum = 0, proizvedenie = 1;
    printf("to enter array elements from the keyboard, click 1\n");
    printf("to enter in the array elements randomly, click 2\n");
    while (scanf_s("%d", &x) != 1 || x < 1 || x>2 || getchar() != '\n')//выбираем метод заполнения 
    {
        printf("incorrect enter\n");
        rewind(stdin);
    }
    switch (x)
    {
    case 1:
        printf(" enter %d  elements array: \n", n);//колличество элементов массива
        for (int i = 0; i < n; i++) // number колличество элементов в массиве
        {
            printf(" %d  elements array: ", i + 1);//выводит элементы массива
            while (scanf_s("%d", &massiv1[i]) != 1 || getchar() != '\n')//вводим элементы массива
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
            massiv1[i] = rand() % 100; //рандомное заполнение массива
            printf(" %d  elements array %d \n", i + 1, massiv1[i]);
        }
        break;
    default:
        printf("error\n");
        return 0;
    }
    printf("to enter array elements from the keyboard, click 1\n");
    printf("to enter in the array elements randomly, click 2\n");
    while (scanf_s("%d", &y) != 1 || y < 1 || y>2 || getchar() != '\n')//выбираем метод заполнения 
    {
        printf("incorrect enter\n");
        rewind(stdin);
    }
    switch (y)
    {
    case 1:
        printf(" enter %d  elements array: \n", n);//колличество элементов массива
        for (int i = 0; i < n; i++) 
        {
            printf(" %d  elements array: ", i + 1);//выводит элементы массива
            while (scanf_s("%d", &massiv2[i]) != 1 || getchar() != '\n')//вводим элементы массива
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
            massiv2[i] = rand() % 100; //рандомное заполнение массива
            printf(" %d  elements array %d \n", i + 1, massiv2[i]);
        }
        break;
    default:
        printf("error\n");
        return 0;
    }
    int flag = 0;
    int min = 999;
    for (int i = 0; i < n; i++) //пробег по 1 массиву
    {
        for (int j = 0; j < n; j++) //пробег по 2 массиву
        {
            if (massiv1[i] == massiv2[j]) // сравнение значений
                flag = 1;
        }
        if (flag == 0 && massiv1[i] < min) //присваивание минимального значения
        {
            min = massiv1[i];
        }
        else
            flag = 0;
    }
    printf("the minimal element is %d", min);
}
