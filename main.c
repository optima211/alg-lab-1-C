#include <stdio.h>

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

int main() {
    int a[10]; // Объявляем массив из 10 элементов
    int select;
    // Вводим значения элементов массива
    printf("Hello! \nPlease, enter element of massive\n");
    for (int i = 0; i < 10; i++) {
        printf("a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }
    printf("Select function of sort you massive:\n 1- Method direct sort\n 2- Method of Shell\n 3- Method of pyramidal sort\n");
    scanf_s("%d", &select);
    switch (select) {
        case 1:
            selectionSort(a, 10);  // вызываем функцию сортировки
            printf("Array output after applying the direct sort method:\n");
            break;
        case 2:
            break;
        default:
            printf("restart the program and enter the correct value\n");
            select = -1944767;
            break;
    }
    if (select != -1944767) {
        // Выводим отсортированные элементы массива
        for (int i = 0; i < 10; i++)
            printf("%d ", a[i]);
        printf("All OK?\n Please, press button 'Enter' on you keyboard! Thanks!");
    }
    getchar();
    getchar();
    return 0;
}