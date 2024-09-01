#include <iostream>
using namespace std;

// Function to traverse the array
void traverse(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Function to search an element
void searching(int arr[], int size)
{
	int key;
	cout << endl << "Enter the element you want to search : ";
	cin >> key;
	
	int index = -1;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == key){
			index = i;
		}
	}
	if(index != -1)
	{
		cout << "Element " << key << " found at index " << index << endl;
	}
	else
	{
		cout << "Element " << key << " found at index " << endl;
	}
}

// Function to insert an element
void insertion(int arr[], int size)
{
	int element, position;
	again :
	cout << endl << "Enter the position you want to insert your element : ";
	cin >> position;
	// if position is out of boundaries
	if(position < 0 || position > size + 1)
	{
		cout << "Can not insert the element. Position out of boundaries." << endl;
		goto again;
	}
	
	// Element to be inserted
	cout << "Enter the element you want to insert : ";
	cin >> element;
	
	// Insert at the beginning
	if(position == 0){
		for(int i = size; i > 0; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[0] = element;
	}
	
	// Insert at the end
	else if(position == size)
	{
		arr[position] = element;
	}
	
	// Insert in between
	else
	{
		for(int i = size; i > position; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[position] = element;
	}
	
	// Printing the array
	size += 1;
	cout << "After inserting " << element << " at position " << position << " : ";
	traverse(arr, size);
}

// Function to delete an element
void deletion(int arr[], int size)
{
	int position;
	again :
	cout << endl << "Enter the position where you want to delete : ";
	cin >> position;
	// if position is out of boundaries
	if(position < 0 || position > size + 1)
	{
		cout << "Can not delete any element. Position out of boundaries." << endl;
		goto again;
	}
	
	// Delete at the beginning
	if(position == 0)
	{
		for(int i = 0; i < size; i++)
		{
			arr[i] = arr[i+1];
		}
		size -= 1;
	}
	
	// Delete at the end
	else if(position == size)
	{
		size -= 1;
	}
	
	// Delete in between
	else
	{
		for(int i = position; i < size; i++)
		{
			arr[i] = arr[i+1];
		}
		size -= 1;
	}
	
	// Print the array
	cout << "After deleting the element at position " << position << " : ";
	traverse(arr, size);
}

// a. Delete all the occurrences of an element from the array
void removeAllOccurrences(int arr[], int& size) 
{
	int valueToRemove;
	cout << endl << "Enter the element you want to remove the occurences : ";
	cin >> valueToRemove;
	
	bool isPresent = false;
	for (int i = 0; i < size; i++)
	{
        if (arr[i] == valueToRemove)
		{
        	isPresent = true;
        }
    }
    if(isPresent)
	{
    	int newSize = 0;
	    for (int i = 0; i < size; i++) 
		{
	        if (arr[i] != valueToRemove) 
			{
	            arr[newSize++] = arr[i];
	        }
	    }
		size = newSize;
		cout << "After removing all occurrences of " << valueToRemove << " : ";
		traverse(arr, size);
	}
	else
	{
		cout << "Element is not in the array" << endl;
	}
    
}

// b. Obtain the frequency (or count) of all the elements in the array
void countFrequencies(int arr[], int size) 
{
	string choice;
    again : 
	cout << endl << "Do you want to display frequency of all elements in the array (y/n)? ";
	cin >> choice;
	if(choice == "y")
	{
		cout << "Frequency of all elements in the array : " << endl;
	}
	else if(choice == "n")
	{
		cout << "Request canceled." << endl;
		return;
	}
	else
	{
		cout << "Invalid input." << endl;
		goto again;
	}
    for (int i = 0; i < size; i++) 
	{
        int count = 1;
        if (arr[i] != -1) 
		{
            for (int j = i + 1; j < size; j++) 
			{
                if (arr[j] == arr[i]) 
				{
                    count++;
                    arr[j] = -1;
                }
            }
            cout << "Element " << arr[i] << " : " << count << " times." << endl;
        }
    }
}


int main()
{
	
	int arr[] = {3, 7, 2, 8, 3, 5, 9, 7, 1, 3, 6, 8, 4, 7, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	// Display the original array
	cout << "Original array : ";
	traverse(arr, size);
	
	// Search an element
	searching(arr, size);
	
	// Inserting an element
	insertion(arr, size);
	size += 1;
	
	// Deleting an element
	deletion(arr, size);
	size -= 1;
	
	// Remove all occurrences of an element
	removeAllOccurrences(arr, size);
	
	// Frequency of all elements in the array
	countFrequencies(arr, size);
	
	return 0;
}




