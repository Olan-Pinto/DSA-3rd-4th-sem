#include <iostream>
using namespace std;

class MaxHeap
{
private:
	
	int n;
	int arr[100];
	
	void swap(int, int);
	
public:
	
	MaxHeap();
	
	void siftUp(int);
	void siftDown(int);
	
	void insert(int);
	
	int getMax();
	void extractMax();
	
	void deleteHeap();
};

MaxHeap::MaxHeap()
{
	n = 0;
}

void MaxHeap::swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void MaxHeap::siftUp(int index)
{
	int parent = (index-1)/2;
	
	if (arr[parent] < arr[index])
	{
		swap(parent, index);
		siftUp(parent);
	}
}

void MaxHeap::siftDown(int index)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	
	if (lchild < n && arr[lchild] > arr[max])
	{
		max = lchild;
	}
	
	if (rchild < n && arr[rchild] > arr[max])
	{
		max = rchild;
	}
	
	if (max != index)
	{
		swap(max, index);
		siftDown(max);
	}
}

void MaxHeap::insert(int data)
{
	if (n >= 100)
	{
		return;
	}
	
	arr[n] = data;
	siftUp(n++);
}

int MaxHeap::getMax()
{
	if (n == 0)
	{
		return 0;
	}
	
	return arr[0];
}

void MaxHeap::extractMax()
{
	if (n == 0)
	{
		return;
	}
	
	swap(0, n-1);
	n--;
	siftDown(0);
}

void MaxHeap::deleteHeap()
{
	n = 0;
}

int main()
{
	MaxHeap h;
	
	int choice = -1;
	while (choice != 5)
	{
		cout << "1. Build Heap\n2. Insert\n3. Get Max\n4. Extract Max\n5. Exit\n";
		cout << "Enter Choice: ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				h.deleteHeap();
				int temp1, temp2;
				cout << "Enter Number of Elements: ";
				cin >> temp1;
				for (int a = 0; a < temp1; a++)
				{
					cout << "Enter Element: ";
					cin >> temp2;
					h.insert(temp2);
				}
				break;
				
			case 2:
				int temp;
				cout << "Enter Element: ";
				cin >> temp;
				h.insert(temp);
				break;
				
			case 3:
				cout << h.getMax() << endl;
				break;
				
			case 4:
				h.extractMax();
				break;
				
			case 5:
				break;
				
			default:
				cout << "Invalid" << endl;
				break;
		}
		
		cout << endl;
	}
}

