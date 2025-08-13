#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(deque<int> q){
    for(int i = 0; i<q.size(); i++){
        cout << q[i] << " " ;
    }
    cout << endl;
}

void reverseDeque(deque<int> &q){
    deque<int>::iterator start = q.begin();
    deque<int>::iterator finish = q.end();
    reverse(start,finish);
}

deque<int> divisible(deque<int> q, int n){
    int s = q.size();

    for(int i = 0; i< s; i++){
        int value = q.front();
        q.pop_front();
        if(value%n == 0){
            q.push_back(value);
        }
    }
    return q;
}

deque<int> sortStack(deque<int> q){
    deque<int> q2;

    while(!q.empty()){
            int size =0;
            int min = q.back();
            while(!q.empty()){
                int x = q.back();
                q.pop_back();
                if(x < min) min = x;
                q2.push_back(x);
                size++;
            }
            for(int i = 0; i < size; i++){
                int x = q2.back();
                q2.pop_back();
                if (x!= min) q.push_back(x);
            }
            q2.push_back(min);
    }

    while(!q2.empty()){
        int x = q2.back();
        q2.pop_back();
        q.push_back(x);
    }
    return q;
}

int main()
{
    deque<int> q1;

    for(int i =1; i<=12; i++)
        q1.push_back(i);




    printDeque(q1);
    deque<int> q2 = divisible(q1,4);
    printDeque(q2);

    deque<int> q3;
    q3.push_back(6);
    q3.push_back(1);
    q3.push_back(3);
    q3.push_back(5);
    q3.push_back(4);
    q3.push_back(0);
    q3.push_back(7);
    printDeque(q3);

    deque<int> q4 = sortStack(q3);
    printDeque(q4);

    ///////////////////////////
    //simple test
    std::deque<int> first (3); // deque with 3 zero-initialized ints
    std::deque<int> second (5); // deque with 5 zero-initialized ints
    second = first;
    first = std::deque<int>(); //
    cout << "The 1st queue is " << endl;
    printDeque(first);
    cout << "The 2nd queue is " << endl;
    printDeque(second);


    return 0;
}
