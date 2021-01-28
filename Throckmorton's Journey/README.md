# Question - Throckmorton's Journey

Your cousin Throckmorton is going on a journey for **_X_** days and you have agreed to take care of his dog Maxwell. Soon you realize that Maxwell requires eats a lot and it's costing a lot of money. Find the minimum amount you must spend in order to feed him till Throcky's return.

In the supermarket, you see two types of dog food - the standard and the fancy. One box of standard dog food will feed Max for one day and it costs **_M_** dollars. One box of the fancy dog food will feed Max for **_Y_** days and it costs **_N_** dollars. Maxwell must be fed for all **_X_** days.

Find the minimum cost to do so. The supermarket has an endless supply of both types of dog food.

# Solutions

## Python

    ```n,m,a,b=map(int,input().split())
    print(min(n*a,-n//m*-b,n//m*b+n%m*a))
    ```

## C++

    ```#include<iostream>
    using namespace std;

    main(){
        int a,b,c,d; cin≫a≫b≫c≫d;
        cout<<min(a*c,a/b*d+min(d,a%b*c));
    }
    ```

## Java

    ```import java.util.*;
    public  class  MainClasses  {
        public  static  void main(String[] args)  {
    	    Scanner in =  new  Scanner(System.in);
    	    int n = in.nextInt(),m=in.nextInt(),a = in.nextInt(),b = in.nextInt();
    	    System.out.println(Math.min(n*a,(n/m)*b+Math.min((n%m)*a,b)));
    	}
    }
    ```

## Javascript

    ```X=readline().split(' ').map(Number)
    n=X[0],m=X[1],a=X[2],b=X[3]
    if (1/a > m/b) print(n*a)
    else print(Math.floor(n/m)*b + Math.min((n%m)*a,b))
    ```
