#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contr_sum1, contr_sum2;// задание переменных сравнения контрольной суммы

// Функция сортировки прямым выбором
void selectionSort(int *num, int size) {
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++) {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        temp = num[i];      // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = temp;
    }
}

// Функция сортировки методом Шелла
void shellSort(int *num, int size) {
    int increment = 3;    // начальное приращение сортировки
    while (increment > 0)  // пока существует приращение
    {
        for (int i = 0; i < size; i++)  // для всех элементов массива
        {
            int j = i;          // сохраняем индекс и элемент
            int temp = num[i];
            // просматриваем остальные элементы массива, отстоящие от j-ого
            // на величину приращения
            while ((j >= increment) && (num[j - increment] > temp)) {  // пока отстоящий элемент больше текущего
                num[j] = num[j - increment]; // перемещаем его на текущую позицию
                j = j - increment;       // переходим к следующему отстоящему элементу
            }
            num[j] = temp; // на выявленное место помещаем сохранённый элемент
        }
        if (increment > 1)      // делим приращение на 2
            increment = increment / 2;
        else if (increment == 1)   // последний проход завершён,
            break;  // выходим из цикла
    }
}

// Функция "просеивания" через кучу - формирование кучи (включена в пирамидальную сортировку)
void siftDown(int *numbers, int root, int bottom) {
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else // иначе
            done = 1; // пирамида сформирована
    }
}

// Функция пирамидальной сортировки
void PyramidSort(int *numbers, int array_size) {
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

int main() {
    int n, *a;
    int select; //переменная для выбора метода сортировки
    int error_select = -1944767; //заразервированное число для выдачи ошибки в меню
    //ввод колличества элементов массива
    printf("insert size your massive: ");
    scanf_s("%d", &n);
    //задание функции задания случайных чисел
    srand(time(0));
    a = malloc(n * sizeof(int));
    printf("finish massive:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // диапазон случайных чисед от 0 до 99
        printf("%d ", a[i]);
        contr_sum1 += a[i];
    }
    printf("\ncontr sum1 = %d", contr_sum1);
    printf("\nSelect method of sort you massive:\n 1-descending order\n 2- in ascending order\n");
    scanf_s("%d", &select);
    //меню выбора сортирвки
    switch (select) {
        case 1: // сортировка по возрастанию
            printf("\nSelect function of sort you massive:\n 1- Method direct sort\n 2- Method of Shell\n 3- Method of pyramidal sort\n");
            scanf_s("%d", &select);
            switch (select) {
                case 1:
                    selectionSort(a, n);  // вызываем функцию сортировки прямым выбором
                    printf("Array output after applying the direct sort method:\n");
                    break;
                case 2:
                    shellSort(a, n); // вызываем функцию сортировки методом Шелла
                    printf("Array output after applying the Shell sort method:\n");
                    break;
                case 3:
                    PyramidSort(a, n); // вызов функции пирамидальной сортировки
                    printf("Array output after applying the pyramid sort method:\n");
                    break;
                default:
                    printf("restart the program and enter the correct value\n");
                    select = error_select;
                    break;
            }
            break;
        case 2: // сортировка по убыванию
            printf("\nSelect function of sort you massive:\n 1- Method direct sort\n 2- Method of Shell\n 3- Method of pyramidal sort\n");
            scanf_s("%d", &select);
            switch (select) {
                case 1 :
                    break;
                default:
                    select = error_select;
                    break;
            }
            break;
        default:
            select = error_select;
            break;
    }
    if (select != error_select) {
        // Выводим отсортированные элементы массива
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
            contr_sum2 += a[i];
        }
        if (contr_sum1 == contr_sum2)
            printf("\nAll work done!\n Please, press button 'Enter' on you keyboard!\n Thanks!");
        else printf("\nwe are have problem! contr-sum have error\n");
    } else printf("restart the program and enter the correct value\n");
    getchar();
    putchar('\n');
    free(a);
    return 0;
}