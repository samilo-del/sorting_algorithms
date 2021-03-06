#include "sort.h"

/**
 * partition - create partition of quick sort
 * @cadena: the array
 * @menor: low digit of array
 * @mayor: max num in the array
 * @size: size of the array
 * Return: the position of pivote
 */

int partition(int *cadena, int menor, int mayor, size_t size)
{
int i = 0, j;
int pivot = 0, tmp = 0;

i = menor - 1;
pivot = cadena[mayor];
for (j = menor; j <= mayor - 1; j++)
{
if (cadena[j] < pivot)
{
i++;
tmp = cadena[i];
cadena[i] = cadena[j];
cadena[j] = tmp;
if (i != j)
print_array(cadena, size);
}
}
if (cadena[i + 1] != cadena[mayor])
{
tmp = cadena[i + 1];
cadena[i + 1] = cadena[mayor];
cadena[mayor] = tmp;
if (i + 1 != j)
print_array(cadena, size);
}
return (i + 1);
}

/**
 * execute - execute the program, create a recursive function
 * to create the tree of process
 * @cadenas: the array
 * @menor: min number of array
 * @mayor: max number of arrat
 * @size: the size of array
 */

void execute(int *cadenas, int menor, int mayor, size_t size)
{
int pivote = 0;

if (menor < mayor)
{
pivote = partition(cadenas, menor, mayor, size);
execute(cadenas, menor, pivote - 1, size);
execute(cadenas, pivote + 1, mayor, size);
}
}

/**
 * quick_sort - create the algorithm of quick sort
 * @array: the array
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
int mayor = 0, menor = 0;

if (array == NULL)
return;
if (size < 2)
return;
mayor = size - 1;
execute(array, menor, mayor, size);
}
