#include <iostream>
using namespace std;

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];

		// Add comma
		if (i < size - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}

void main(){
	int theArr[5] = { 1, 2, 5, 7, 9 };
	int arrSize = sizeof(theArr) / sizeof(int);
	int arrHalfSize = arrSize / 2;

	//Print start Arr
	PrintArr(theArr, 5);

	//Converting Arr
	// from here
	for (int i = 0; i < arrHalfSize; i++)
	{
		theArr[i] = theArr[i] + theArr[arrSize - 1 - i];
		theArr[arrSize -1 - i] = theArr[i] - theArr[arrSize - 1 - i];
		theArr[i] = theArr[i] - theArr[arrSize - 1 - i];
	}
	// to hrere
	
	//Print reversed Arr
	PrintArr(theArr, 5);
}