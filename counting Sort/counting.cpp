#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

void countSort(int arr[], int tam, int Range)
{
    int count[Range + 1], i;
    int output[tam];

    for(i = 0; i<tam ; i++)
        ++count[arr[i]];

    for (i = 1; i < Range; ++i)
        count[i] += count[i-1];

    for (i = tam-1; i>=0; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; i < tam ; i++)
        arr[i] = output[i];
}

int main() {

	char arquivo[30]; 
	cout << "Digite o nome do arquivo para o teste: " << endl;
	cin >> arquivo;

	int array[100000]; 
	int Range = 10000000;
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

	countSort(array, tamanho, Range);


    for(int x=0; x<=(tamanho-1); x++)
    {
        cout << array[x] << endl;
    }
}
