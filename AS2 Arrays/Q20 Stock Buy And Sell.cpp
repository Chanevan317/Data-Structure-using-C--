#include <iostream>
using namespace std;

void stockBuySell(int arr[], int size) 
{
    int maxProfit = 0;
    int buyDay, SellDay;
    for (int i = 0; i < size; i++) 
    {
        int profit = 0;
        for (int j = i+1; j < size; j++) 
        {
            profit = arr[j] - arr[i];
            if(profit > maxProfit)
            {
                maxProfit = profit;
                buyDay = i;
                SellDay = j;
            }
        }
    }
    cout << "Best day to buy : " << buyDay+1 << endl;
    cout << "Best day to sell : " << SellDay+1 << endl;
    cout << "Profit : " << maxProfit << endl;
}

int main()
{
    int stock[] = {7 , 1, 5, 3, 6, 4};
    int size = sizeof(stock) / sizeof(stock[0]);
    stockBuySell(stock, size);
    return 0;
}

