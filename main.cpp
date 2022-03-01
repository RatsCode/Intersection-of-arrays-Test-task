#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;



vector<int> my_intersection(int* arr1, int* arr2, int size1, int size2)
{
	map<int,int> tmp;
	vector<int> intersection;

	for (int i = 0; i < size1; ++i)
	{
		if (!(tmp.emplace(arr1[i], 0)).second)
		{
			++tmp[arr1[i]];
		}
	}

	auto it = tmp.begin();
	for (int i = 0; i < size2; ++i)
	{
		if ((it = tmp.find(arr2[i])) != tmp.end())
		{
			if ((*it).second > 0)
			{
				--(*it).second;
				intersection.push_back(arr2[i]);
			}
		}
	}

	return intersection;
}



int main()
{
	vector<int> intersection;

	int size1 = rand() % 50;
	int size2 = rand() % 50;

	int *arr1 = new int[size1];
	int *arr2 = new int[size2];


	for (int i = 0; i < size1; ++i)
	{
		arr1[i] = rand() % 20;
	}
	for (int i = 0; i < size2; ++i)
	{
		arr2[i] = rand() % 20;
	}

	intersection = my_intersection(arr1, arr2, size1, size2);


	cout << "arr1 ";

	for (int i = 0; i < size1; ++i)
	{
		cout << arr1[i] << ' ';
	}

	cout << endl << "arr2 ";

	for (int i = 0; i < size2; ++i)
	{
		cout << arr2[i] << ' ';
	}

	cout << endl << "intersection ";

	for (auto i : intersection)
	{
		cout << i << ' ';
	}
}