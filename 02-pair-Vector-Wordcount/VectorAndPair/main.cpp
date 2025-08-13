#include <iostream>
#include <utility>
#include <vector>

using namespace std;


vector<pair<string,int> > sortVectorPair(vector<pair<string,int> > v){
    for(int i =0 ; i< v.size()-1; i++){
        for(int j =0; j<v.size()-1; j++){
            if(v[j].second>v[j+1].second){
                pair<string,int> temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }

    }

    return v;
}





int main()
{
    vector<pair<string,int>> v(4);
    v[0] = make_pair("John",15);
    v[1] = make_pair("Mark",12);
    v[2] = make_pair("Juliet",17);
    v[3] = make_pair("Samantha",9);

    v = sortVectorPair(v);
    vector<pair<string,int>>::iterator i;
    for(i = v.begin(); i != v.end(); i++)
        cout<< (*i).first << ", " << (*i).second << " --- ";



}
