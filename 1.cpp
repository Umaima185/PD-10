#include<iostream>
using namespace std;
bool check(int number[], int);
int main()
{
  int l,temp; 
  cout<<"Enter array length: ";
  cin>>l;
  int number[l];
  cout<<"Enter array: ";
  for(int i=0; i<l; i++)
 {
  cin>>number[i];
 }
 for(int i=0; i<l-1; i++)
 {
   for(int j=0; j<l-i-1; j++)
  {
  if(number[j]>number[j+1])
  {
   temp=number[j];
   number[j]=number[j+1];
   number[j+1]=temp;
  }
 }
 }
 cout<<check(number,l);
}
bool check(int number[], int l)
{
  for(int k=0; k<l-1; k++)
 {
  if(number[k+1]-number[k]!=1)
  {
   return false;
  }
  if(number[k]==number[k+1])
   return false;
 }
return true;
}