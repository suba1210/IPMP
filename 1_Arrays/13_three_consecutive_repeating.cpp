/* Another Approach : 
Algorithm 

Create an auxiliary array smaller[0..n-1]. smaller[i] stores the index of a number which is smaller than arr[i] and is on the left side. 
The array contains -1 if there is no such element.

Create another auxiliary array greater[0..n-1]. greater[i] stores the index of a number which is greater than arr[i] and is on the right 
side of arr[i]. The array contains -1 if there is no such element.

Finally traverse both smaller[] and greater[] and find the index [i] for which both smaller[i] and greater[i] are not equal to -1.

*/

#include <bits/stdc++.h>
using namespace std;
 
// Function to find the triplet
void find3Numbers(vector<int>& nums)
{
   
  // If number of elements < 3
  // then no triplets are possible
  if (nums.size() < 3){
    cout << "No such triplet found";
    return;
  }
   
  // track best sequence length
  // (not current sequence length)
  int seq = 1;       
   
  // min number in array
  int min_num = nums[0]; 
   
  // least max number in best sequence
  // i.e. track arr[j] (e.g. in
  // array {1, 5, 3} our best sequence
  // would be {1, 3} with arr[j] = 3)
  int max_seq = INT_MIN;     
   
  // save arr[i]
  int store_min = min_num;  
   
  // Iterate from 1 to nums.size()
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] == min_num)
      continue;
     
    else if (nums[i] < min_num)
    {
      min_num = nums[i];
      continue;
    }
     
    // this condition is only hit
    // when current sequence size is 2
    else if (nums[i] < max_seq) {   
       
      // update best sequence max number
      // to a smaller value
      // (i.e. we've found a
      // smaller value for arr[j])
      max_seq = nums[i];      
       
      // store best sequence start value
      // i.e. arr[i]
      store_min = min_num;           
    }
     
    // Increase best sequence length &
    // save next number in our triplet
    else if (nums[i] > max_seq)
    {   
      seq++;
       
      // We've found our arr[k]!
      // Print the output
      if (seq == 3)
      {           
        cout << "Triplet: " << store_min <<
                 ", " << max_seq << ", " <<
                           nums[i] << endl;
        return;
      }
      max_seq = nums[i];
    }
  }
   
  // No triplet found
  cout << "No such triplet found";
}
 
// Driver Code
int main() {
  vector<int> nums {1,2,-1,7,5};
   
  // Function Call
  find3Numbers(nums);
}