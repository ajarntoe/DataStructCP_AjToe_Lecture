#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_queue(priority_queue<int> q, int s) {
    int z = 1;
    while(z<=s) {
        std::cout << q.top() << " ";
        q.pop();
        z++;
    }
    std::cout << '\n';
}

int main()
{
    cout << "Printing k smallest number" << endl;
    vector<int> v = {9,3,5,1,2,8,4,7,0};

    deque<int> deq;
    priority_queue<int> q;
    int size = v.size();

    int k;
    cout << "How many number do you want to print?" << endl;
    cin >> k;

    if(k<0 || k> size){
        cout << "Impossible value of k- program end" << endl;
        return 0;
    }

    for (int i=0; i<size; i++) {
        q.push(v[i]);
    }
    print_queue(q,5);

    for (int i=0; i<size; i++) {
        deq.push_front(q.top());
        q.pop();
    }

    for (int i=1; i<=k; i++) {
        cout << deq.front() << endl;
        deq.pop_front();
    }

    return 0;
}
