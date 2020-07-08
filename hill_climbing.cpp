#include<iostream>
using namespace std;

//This function is just getting best cost by comparing neighbouring elements.
calcCost (int no_of_seats[], const int no_of_parties) 
{
	int c = 0;
	for (int i = 0; i < no_of_parties; ++i)
	{
		for (int j = i + 1; j < no_of_parties; ++j)
		{
			if (no_of_seats[j] > no_of_seats[i])
			{
				c++;
			}
		}
	}
	return c;
}
//Here swapping is performing between neighbour and selected cost
void SwapElements (int no_of_seats[], int i, int j)
{
	int temp = no_of_seats[i];
	no_of_seats[i] = no_of_seats[j];
no_of_seats[j] = temp;
}

int main()
{   
     int party;
   
cout<<" Enter number total parties that are fighting in 2020 election: ";
	cin>>party;
	int index = 1;
	int no_of_seats[party];

	for (int i = 0; i < party; ++i)
	{
		cout << "Enter total no. of winning seats of party "  << index << endl;
		cin >> no_of_seats[i];
		++index;
	}
// currrent best cost is define
	int bestCost = calcCost(no_of_seats, party);
	int newcost = 0, swapping = 0;
	//Now here hill climbing logic is used
	while (bestCost > 0) 
	{
		for (int i = 0; i < party - 1; ++i)
		{
			SwapElements(no_of_seats, i, i + 1);
			newcost = calcCost(no_of_seats, party);
			//current_value > neigbour_value
			if (bestCost > newcost)
			{
				++swapping;
				cout << "Performing Swap: " << swapping << endl;
				for (int i = 0; i < party; ++i)
				{
					cout << no_of_seats[i] << "->";
				}

				cout << "\n";
				//current_value = neigbour_value
				bestCost = newcost;
			}
			else
			{
				SwapElements(no_of_seats, i, i + 1);
			}
		}
	}
	
	cout << "\nFinal Election Result: \n";
	for (int i = 0; i < party; i++)
	{   
		cout << no_of_seats[i] << endl;
}	}
