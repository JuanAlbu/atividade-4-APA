#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	int m = getMax(arr, n);

	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

int main() {

    char arquivo[30]; 
    cout << "Digite o nome do arquivo para o teste: " << endl;
    cin >> arquivo;

    int array[100000]; 
    int tamanho = 0; 

    ifstream myReadFile;
    myReadFile.open(arquivo);
    char output[1000];
    if (myReadFile.is_open()) 
    {
        while (!myReadFile.eof()) 
        {
            myReadFile >> output;
            array[tamanho] = atoi(output);
            tamanho++;
        }
    }
    
    myReadFile.close();  

    radixsort(array, tamanho);

    for(int x=0; x<=(tamanho-1); x++)
    {
        cout << array[x] << endl;
    }
}


