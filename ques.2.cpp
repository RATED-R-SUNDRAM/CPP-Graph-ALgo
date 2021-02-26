#include <bits/stdc++.h>

using namespace std;
int f1=7;
int f2=3;

int f1_counter=0;
int f2_counter=0;

int divide_check(int a,int b){
    if (a==0){
        return 1;
    }
    else if(a<0){
        return 0;
    }
    else{
        return divide_check(a-b,b);
    }
}

int hcf_by_subs(int a,int b){
    for (int i = b; i>=1; i--)
    {
        if (divide_check(a,i)==1){
            if(divide_check(b,i)==1){
               return i;
               break;
            }
        }
    }
    

    return 1;
}
int multiply(int x,int y){ 
  
    if(y == 0){ 
        return 0;
    }
    if(y > 0 ){ 
        return (x + multiply(x, y - 1));
    } 
    if(y < 0 ){ 
        return -multiply(x, -y);
    }
}
int and_check(int a,int b){
    if (a==1){
       if(b==1){
           return 1;
       }
    }
    if(b==1){
        if(a==1){
            return 1;
        }
    }
    else
    {
        return 0;
    }
    
}

int hcf(int a,int b){
    if(b==0){
        return a;
    }
    if(a<f1){
        return hcf_by_subs(a,b);
    }
    if (and_check(divide_check(a,f1),divide_check(b,f1))){
            
            f1_counter++;
            return hcf(a/f1,b/f1);
    }
    if (and_check(divide_check(a,f2),divide_check(b,f2))){
             
            f2_counter++; 
            return hcf(a/f2,b/f2);
    }
    else{
          int k= hcf_by_subs(a,b);
          if(f1_counter>0){
              k=multiply(k,multiply(f1,f1_counter));
              cout<<k<<endl;
          }
          if(f2_counter>0){
              k=multiply(k,multiply(f2,f2_counter));
              cout<<k<<endl;
          }

          return k;

          

          
    }
    return 1;
}

int main() {
    int n,m;
    cout<<"Enter 1st no.: ";
    cin>>n;
    cout<<"\nEnter 2nd no.: ";
    cin>>m;
    cout<<hcf(max(n,m),min(n,m));
    
    return 0;
    
}



