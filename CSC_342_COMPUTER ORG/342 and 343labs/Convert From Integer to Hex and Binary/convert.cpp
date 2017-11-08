#include<iostream>
#include<bitset>

using namespace std;


int main()
{
  cout<<"Enter an integer"<<endl;
  int input,i,j;
  cin>>input;
  
  cout<<input<<" in binary is " <<bitset<32>(input)<<endl;
  cout<<input<<" In hexadecimal is 0x"<< hex << input << endl<<endl;
 
  cout<<"Enter 2 numbers"<<endl;
  
  cin>>i;
  cin>>j;
  
  cout<<"The Sum of "<<dec<<i<<" and "<< j<< " in binary is "<<bitset<32>(i + j)<<endl;
  cout<<dec<<i<<" + "<<j<<" in hexadecimal is 0x"<<hex<<i+j<<endl;
  cout<<dec<<"in decimal is "<<i+j<<endl;
	return 0;
}


  