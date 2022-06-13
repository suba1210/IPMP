#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct {
   int v;
   int w;
   float d;
} Item;

void input(Item items[],int sizeOfItems) {
   cout << "Enter total "<< sizeOfItems <<" item's profit and weight" <<
   endl;
   for(int i = 0; i < sizeOfItems; i++) {
      cout << "Enter Item "<< i+1 << " Profit ";
      cin >> items[i].v;
      cout << "Enter Item "<< i+1 << " Weight ";
      cin >> items[i].w;
   }
}

void display(Item items[], int sizeOfItems) {
   int i;
   cout << "profit: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].v << "\t";
   }
   cout << endl << "weight: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl;
}

bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}

float knapsack(Item items[], int sizeOfItems, int W) {
   int i, totalWeight=0, totalValue=0;
   for(i=0;i<sizeOfItems;i++){
      items[i].d = items[i].v/items[i].w;
   }
   sort(items,items+sizeOfItems,compare);

   for(i=0;i<sizeOfItems;i++){
      if(totalWeight+items[i].w<=W){
         totalWeight += items[i].w;
         totalValue += items[i].v;
      }
      else{
         int wt = W - totalWeight;
         totalValue += (wt*items[i].d);
         totalWeight+=wt;
         break;
      }
   }
   cout<<"\nTotal Weight in bag : "<<totalWeight<<endl;
   return totalValue;
}

int main() {
   int W, noOfItems;
   cout<<"Enter the total number of items : ";
   cin>>noOfItems;
   Item items[noOfItems];
   input(items, noOfItems);
   cout << "Entered data \n";
   display(items,noOfItems);
   cout<< "Enter Knapsack weight \n";
   cin >> W;
   float mxVal = knapsack(items, noOfItems, W);
   cout << "Max value for "<< W <<" weight is "<< mxVal;
}
