#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void) {

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start, end; // объявляем переменные для определения времени выполнения

    int i = 0, j = 0, r;
    int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE], elem_c;

    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    while (i < SIZE)
    {
        while (j < SIZE)
        {
            a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
            j++;
        }
        i++;
    }
    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    i = 0; j = 0;
    while (i < SIZE)
    {
        while (j < SIZE)
        {
            b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
            j++;
        }
        i++;
    }

    start = clock(); // запускаемтаймер

    for (i = 0;i < SIZE;i++)
    {
        for (j = 0;j < SIZE;j++)
        {
            elem_c = 0;
            for (r = 0;r < SIZE;r++)
            {
                elem_c = elem_c + a[i][r] * b[r][j];
                c[i][j] = elem_c;
            }
        }
    }

    end = clock(); // останавливаемтаймер

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Времявыполнения: %f секунд\n", cpu_time_used);

    return(0);

}

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i< count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
items[j + gap] = items[j];
items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызовфункции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



i = left; j = right;

     выбор компаранда 
x = items[(left + right) / 2];

do {
    while ((items[i] < x) && (i < right)) i++;
    while ((x < items[j]) && (j > left)) j--;

    if (i <= j) {
        y = items[i];
        items[i] = items[j];
        items[j] = y;
        i++; j--;
    }
} while (i <= j);

if (left < j) qs(items, left, j);
if (i < right) qs(items, i, right);
}

void measureSortingTime(int* items, int count, const char* sortingAlgorithm)
{
    clock_tstart_time = clock();

    if (strcmp(sortingAlgorithm, "shell") == 0) {
        shell(items, count);
    }
    else if (strcmp(sortingAlgorithm, "quick") == 0) {
        qs(items, 0, count - 1);
    }

    clock_tend_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Времявыполнения %s сортировки: %fсекунд\n", sortingAlgorithm, time_taken);
}

void randomArraySortingTime()
{
    int count = 100000; // Размермассива
    int items[100000];
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        items[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
    }

    measureSortingTime(items, count, "shell");
    measureSortingTime(items, count, "quick");
}

void ascendingArraySortingTime()
{
    int count = 100000; // Размермассива
    int items[100000];
    for (int i = 0; i < count; i++) {
        items[i] = i;
    }

    measureSortingTime(items, count, "shell");
    measureSortingTime(items, count, "quick");
}

void descendingArraySortingTime()
{
    int count = 100000; // Размермассива
    int items[100000];
    for (int i = 0; i < count; i++) {
        items[i] = count - i;
    }

    measureSortingTime(items, count, "shell");
    measureSortingTime(items, count, "quick");
}

void mixedArraySortingTime()
{
    int count = 100000; // Размермассива
    int items[100000];
    for (int i = 0; i < count / 2; i++) {
        items[i] = i;
    }
    for (int i = count / 2; i < count; i++) {
        items[i] = count - i;
    }

    measureSortingTime(items, count, "shell");
    measureSortingTime(items, count, "quick");
}

int main() {
    setlocale(LC_ALL, "Rus");
    printf("Случайныймассив:\n");
    randomArraySortingTime();

    printf("\nВозрастающиймассив:\n");
    ascendingArraySortingTime();

    printf("\nУбывающиймассив:\n");
    descendingArraySortingTime();

    printf("\nМассив с возрастающей и убывающей последовательностями:\n");
    mixedArraySortingTime();
    return 0;
}
*/

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#defineSIZE 100000 

// Функциясравнениядляqsort
int compare(const void* a, const void* b) {
    return ((int)a - (int)b);
}

void fill_random(int array[], int size) {
    for (int i = 0; i< size; i++) {
        array[i] = rand() % size;
    }
}

void fill_ascending(int array[], int size) {
    for (int i = 0; i< size; i++) {
        array[i] = i;
    }
}

void fill_descending(int array[], int size) {
    for (int i = 0; i< size; i++) {
        array[i] = size - i;
    }
}

void fill_halfs(int array[], int size) {
    for (int i = 0; i< size / 2; i++) {
        array[i] = i;
    }
    for (int i = size / 2; i< size; i++) {
        array[i] = size - i;
    }
}

void measure_qsort(void (*fill)(int[], int)) {
    int array[SIZE];
fill(array, SIZE);

clock_t start = clock();
qsort(array, SIZE, sizeof(int), compare);
clock_t end = clock();

printf("Прошловремени: %f\n", ((double)end - start) / CLOCKS_PER_SEC);
}

int main() {
setlocale(LC_ALL, "Rus");
srand(time(NULL)); // Инициализация генератора случайных чисел

printf("Случайныймассив: ");
measure_qsort(fill_random);

printf("Возрастающиймассив: ");
measure_qsort(fill_ascending);

printf("Убывающиймассив: ");
measure_qsort(fill_descending);

printf("Половина возрастает, половина убывает: ");
measure_qsort(fill_halfs);

    return 0;
}
*/