#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;


stack<int> reverse(stack<int> s){
    stack<int> s2;
    while(!s.empty()){
        int data = s.top();
        s.pop();
        s2.push(data);
    }

    return s2;

}



int getKthData(stack<int> &s, int k) throw(exception) {
    if(k<0)
       throw invalid_argument( "received negative value" );
    stack<int> s2;

    int c =0;
    int ans;
    bool found = false;

    while(!s.empty() && !found){

        if(c == k){
            ans =  s.top();
            found = true;
            break;
        }else {
            int data = s.top();
            s.pop();
            s2.push(data);
            c++;
        }
    }

    while(!s2.empty()){
        int data = s2.top();
        s2.pop();
        s.push(data);
    }

    if(found){
        return ans;
    } else{
        throw invalid_argument( "argument too large for stack" );
    }
}

double calculate(vector<string> v){
    vector<string> op = {"+","-","*","/"};
    stack<double> s;


    int size = v.size();
    for(int i =0 ; i<size; i++){
        string data = v[i];
        vector<string>::iterator it = find(op.begin(),op.end(),data);
        if(it != op.end()){ // we have an operator
            double second = s.top();
            s.pop();
            double first = s.top();
            s.pop();

            double result;
            if(data == "+"){
                result = first + second;
            } else if (data == "-"){
                result = first - second;
            } else if (data == "*") {
                result = first * second;
            } else {
                result = first / second;
            }
            s.push(result);

        }else { // we have a number , originally in string form

            double d = ::strtod(data.c_str(), 0);
            //double d = stod(data);
            s.push(d);
        }
    }
    return s.top();


}



int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

   // cout << getKthData(s,-1) << endl;
    cout << getKthData(s,0) <<  endl;
    cout << getKthData(s,1) <<  endl;
    cout << getKthData(s,2) <<  endl;
    cout << getKthData(s,3) <<  endl;
    cout << getKthData(s,4) <<  endl;
   // cout << getKthData(s,5) <<  endl;

    cout << "After reverse ---" <<  endl;
    s = reverse(s);
    cout << getKthData(s,0) <<  endl;
    cout << getKthData(s,1) <<  endl;
    cout << getKthData(s,2) <<  endl;
    cout << getKthData(s,3) <<  endl;
    cout << getKthData(s,4) <<  endl;

    cout << "about to calculate expression" <<  endl;

    vector<string> v = {"15","10","3","+","4","*","+","30","-"};
    cout << calculate(v) <<  endl; // should get 37

    vector<string> v2 = {"22","13","+","4","*","3","/"};
    cout << calculate(v2) <<  endl; // should get 46.667
    return 0;
}
