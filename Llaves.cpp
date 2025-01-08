#include <iostream>
#include <stack>
using namespace std;



char contrario(char llave){

    if(llave == '{'){return '}';}

    if(llave == '['){return ']';}

    if(llave == '('){return ')';}

    return '\0';

}

bool estaBienCerrado(string l){



    stack<char> s1;

    int t = l.size();

    for(int i = 0 ; i<t ; i++){

        char llave = l[i];

        if(llave == '(' || llave== '[' || llave == '{'){

            s1.push(llave);

        } else if (llave == ')' || llave == ']' || llave == '}'){

            if(s1.empty()){
                return false;
            }

            if(llave == contrario(s1.top())){

                s1.pop();

            } else{
                return false;
            }

        }

    }



    return s1.empty();

    

}


int main(){



    cout<<estaBienCerrado("[[]]({[]()}[]((((())))))")<<endl;




return 0;
}