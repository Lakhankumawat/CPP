

//------------------------------------PROBLEM :Tower Of Hanoi ----------------------------------
//important libraries
#include <bits/stdc++.h>
using namespace std;

 /*declaring  function TOH(n-->no of disks,src-->source from where the disk will move,helper-->help in moving disk from source to destination,
    dest-->destination where disk will go)  of returning type void(it returns nothing just prints the output*/
void TOH(int n,char src,char helper,char dest)
{
    if(n==0)
    {  //no disks left 
       return;
    }
    //if disks are more than zero
   TOH(n-1,src,dest,helper); //calling function recursily with n-1(toal disks-1)
   cout<<"Disk "<<n<<" is moved from "<<src<<" to "<<dest<<endl;   //print the output
   TOH(n-1,helper,src,dest);               // again calling funtion recursively with n-1(toal disks-1)
}

// time compexity-->O(2^n)-->exponential time taking problem

int main()
{
  //TO decrease the time of cin and cout operations 
   ios_base :: sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
    
    //printing-->enter number of disks.
 cout<<"Enter number of disks."<<endl;
int n;   //declaring a variable n-->total number of disks
cin>>n;  //taking input
TOH(n,'A','B','C');     //calling function TOH() with three arguments(n->no if disk,A->source,B->helper,C->dest)

return 0;
}




