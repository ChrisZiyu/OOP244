#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H
#include<cstddef>
#include<iostream>
using namespace std;
namespace sdds {

	template<typename arrType, typename keyType>
	int* select(const arrType arr[], const keyType& key, size_t size)
	{
		size_t count=0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i]==key) {
				count++;
			}
		}
		//store the indices found by the array
		int* result = new int[count + 1]();//+1 for the terminator -1

		//use size of the original array and not count
		size_t resultIndex = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == key) {
				//cast the result to int since resultindex and i are size_t signed and unsigned no bueno
				result[resultIndex] = static_cast<int>(i);
				resultIndex++;
			}
		}
		result[resultIndex] = -1;
		return result;
	}



	template<typename arrayType>
	void csvDisplaySelection(const char* title, const arrayType array[], const int* indices)
	{
		cout << title << endl;
		if (indices != nullptr && indices[0] != -1) {
			// Assuming -1 indicates the end of indices
			for (size_t i = 0; indices[i] != -1; i++) {
				size_t currentIndex = static_cast<size_t>(indices[i]);
				cout << array[currentIndex];
				if (indices[i + 1] != -1) {
					cout << ", ";
				}
			}
		}
		else {
			cout << "Empty";
		}
		cout << endl;
	}
}

#endif // !SDDS_SELECTION_H
