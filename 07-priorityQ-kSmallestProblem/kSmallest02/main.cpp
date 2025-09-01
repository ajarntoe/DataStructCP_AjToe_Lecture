#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue <int, vector<int>, greater<int> > gq, int k)
{
    priority_queue <int, vector<int>, greater<int> > g = gq;
    int i =0;
    while (!g.empty() && i<k)
    {
        cout << '\t' << g.top();
        g.pop();
        i++;
    }
    cout << '\n';
}

int main ()
{
    vector<int> v = {9,3,5,1,2,8,4,7,0};
    std::priority_queue<int, vector<int>, greater<int> > myq(v.begin(),v.end()) ;
    //int s = v.size();

    //for(int i = 0; i < s;i++){
    //    myq.push(v[i]);
    //}

    cout << "How many numbers do you want to print?" << endl;
    int k;
    cin >> k;
    showpq(myq,k);
    showpq(myq,k);

}


