// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;

// A structure to represent a job
struct Job
{
char id;	 // Job Id
int dead; // Deadline of job
int profit; // Profit if job is over before or on deadline
};

// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns minimum number of platforms required
void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, comparison);
    int result[n];
    bool slots[n] = {false};

    for(int i=0; i<n;i++){
        for(int j=min(n, arr[i].dead)-1;j>=0;j--){
            if(slots[j]==false){
                result[j] = i;
                slots[j]=true;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(slots[i]){
            cout << arr[result[i]].id << " ";
        }
    }

}

// Driver code
int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
				{'d', 1, 25}, {'e', 3, 15}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs \n";

	// Function call
	printJobScheduling(arr, n);
	return 0;
}
