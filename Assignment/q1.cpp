#include<iostream>
using namespace std ;

int main ()  {
    int n ;
    cout<<"enter a positive integer :";
    cin>>n; 
    int flag = 0 ;
    for(int i = 2 ; i <= n/2 ; i++){
        if(n%i==0){
        flag = 1 ;
        break ;
        }
    }



        if(flag==0)
        {
            cout<<n<<"is a prime number congo"<<endl;
           
           
            int next = n + 1;
            while(1)
            {
                flag = 0 ;
                for(int i =2 ; i<= next/2 ; i++)
                {
                    if(next%i==0)
                    {
                        flag =1 ;
                        break;
                    }
                }
                   
                    if(flag==0)
                    {
                        cout<<"the nxt prime no. greater is " <<next<<endl;
                        break;
                    }
                    next++;
            }
                
            }
        
    
        else
        {
            cout<<"the number u entered is not prime "<<endl;
            cout<<"the factors of "<<n<<" are : ";
            for(int i = 1 ; i<=n ; i++)
            {
                if(n%i==0){
                    cout<<i<<" ";
                }
            }
        }

    
    
    }