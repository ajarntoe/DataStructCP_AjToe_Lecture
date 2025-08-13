#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <assert.h>
#include <algorithm>
#include "priority_queue.h"

class HuffMan
{
    public:
        int frequency;
        char c;
        HuffMan *left;
        HuffMan *right;

        HuffMan(int f, char ss, HuffMan *l, HuffMan *r){
            frequency = f;
            c = ss;
            left = l;
            right = r;
        }

        typedef bool(*HuffFunctor)(HuffMan*, HuffMan*); // Function pointer type
        bool CompareHuff(HuffMan *a,HuffMan *b)    // The actual comparator function matching the CompFunctor signature
        {
            return a->frequency < b->frequency;
        }

        HuffMan* buildHuffManTree(priority_queue<HuffMan*,HuffFunctor>& q){
            while(!q.empty()){
                HuffMan *n1 =  q.top();
                q.pop();
                if(q.empty()) return n1;

                HuffMan *n2 = q.top();
                q.pop();

                HuffMan *n3 = new HuffMan((n1->frequency + n2->frequency), ' ', n1, n2);
                q.push(n3);
            }
        }

    void _printCodes (HuffMan* r, char codes[], int k) {
        if (r->left == NULL && r->r ight == NULL) {
            codes[k] = '\0'  ;  //  '\0' means end of string
            cout << r->c << ": "<< codes << endl;
           // printf("%c : %s\n", r->c, codes);
        } else {
            codes[k] = '0';
            _printCodes(r->left, codes, k+1);
            codes[k] = '1';      
            _printCodes(r->right, codes, k+1);
        }
    }

    void printCodes(HuffMan *r) {
        char codes[40];
        _printCodes(r, codes, 0);
    }

    protected:
    private:
};

#endif // HUFFMAN_H
