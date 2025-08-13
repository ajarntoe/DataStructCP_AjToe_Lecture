#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<float> data;
    for (int i = 0; i < n; i++)
    {
        float val;
        scanf("%f", &val);
        data.push_back(val);
    }
    
    sort(data.begin(), data.end());
    
    for (int k = 0; k < m; k++)
    {
        float val;
        scanf("%f", &val);

        bool found = false;
        int startInx = 0;
        for (int i = 0; i < n; i++)
        {
            if (startInx <= i) startInx++;
            if (startInx == n) startInx--;
            float sum = data[i] + data[startInx];
            if (sum == val)
                found = true;
            else if (sum > val)
            {
                for (startInx--; startInx > i; startInx--)
                {
                    sum = data[i] + data[startInx];
                    if (sum == val)
                    {
                        found = true;
                        break;
                    }
                    if (sum < val) break;
                }
            }
            else
            {
                for (startInx++; startInx < n; startInx++)
                {
                    float sum = data[i] + data[startInx];
                    if (sum == val)
                    {
                        found = true;
                        break;
                    }
                    if (sum > val) break;
                }
            }
            if (found) break;
        }
        if (found)
            printf("YES\n");
        else printf("NO\n");
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}
