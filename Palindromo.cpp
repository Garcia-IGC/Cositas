#include <iostream>
#include <stack>
using namespace std;

bool esPalindrimo(string numero){

    stack<char> s1;

    int t = numero.size();

    for(int i = 0; i<t/2;i++){

        s1.push(numero[i]);

    }

    bool r = true;

    int m = 0;

    if(t%2!=0){m++;}

    for(int i = (t/2) + m; i<t;i++){

        if(numero[i]!=s1.top()){return false;}

        s1.pop();

    }

    return r;

}


int main(){


    cout<<esPalindrimo("100667595766001")<<endl;




return 0;
}