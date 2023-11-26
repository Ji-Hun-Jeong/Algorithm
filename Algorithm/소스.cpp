#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[100];
	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
		arr[i] = rand() % 100;
	for (int i = 0; i < 99; ++i)
	{
		for (int j = 0; j < 100 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 100; ++i)
		cout << arr[i] << "\n";
}