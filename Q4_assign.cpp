#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int short1 = 2;		
vector<string> v1;

int perm(string x) {		
    int bread = x.length();
    sort(x.begin(), x.end());
    while(1) {			
        v1.push_back(x);
        int y = bread - 1;
        while(x[y-1] >= x[y]){	
            if(--y == 0) {
                return 0;
            }
        }	
        int z = bread - 1;
        while(z > y && x[z] <= x[y-1]) {
            z--;
        }
        swap(x[y-1],x[z]);
        reverse(x.begin()+y, x.end());
    }
    
}

void least(char *S1, char *S2, int a, int b) {	
    int leastrix[a + 1][b + 1];		
    for (int k = 0; k <= a; k++) {
        for (int l = 0; l <= b; l++) {
            if (k == 0 || l == 0) {
                leastrix[k][l] = 0;
            }
            else if (S1[k - 1] == S2[l - 1]) {
                leastrix[k][l] = leastrix[k - 1][l - 1] + 1;
            }
            else {
                leastrix[k][l] = max(leastrix[k - 1][l], leastrix[k][l - 1]);
            }
        }
    }
        int indice = leastrix[a][b];
        char lcs[indice + 1];
        lcs[indice] = '\0';
        int  k = a, l = b;
        while (k > 0 && l > 0) {		
            if (S1[k - 1] == S2[l - 1]) {
                lcs[indice - 1] = S1[l - 1];
                k--;
                l--;
                indice--;
            }
            else if (leastrix[k - 1][l] > leastrix[k][l - 1]) {
                k--;
            }
            else {
                l--;
            }
        }
        if(strlen(lcs) > short1) {
            short1 = strlen(lcs);
        }
        if(strlen(S1) > 2 && strlen(S2) > 2) {
            cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcs << endl;
            cout << "Shortest pair of permutations : " << short1 << endl;
        }    
}

int main()
{
    string q;
    cout << "Enter string" << endl;
    cin >> q;
    int loung = q.length();
    if(q.length() == 1 || q.length() == 0) {
        cout << "Please Check the string" << endl;
        return 0;
    }
    if(q.length() == 2) {
        cout << q << endl;
        cout << "Only two characters so No Result" << endl;
        return 0;
    }
    cout << "For this string, the permutations are:" << endl;
    perm(q);
    for(int i=0;i<v1.size();i++) {
        cout << v1[i] << endl;
    }
    cout << "For each pair of possible permutations:" << endl;
    string aa,aaa;
    for(int i=0;i<v1.size();i++) {
        if(i+1 < v1.size()) {
        aa = v1[i];
        aaa = v1[i+1];
        char c[aa.length()+1], d[aaa.length()+1];
        strcpy(c, aa.c_str());
        strcpy(d,aaa.c_str());
        least(c,d,strlen(c),strlen(d));
        }
        
    }
    cout << "Shortest LCS will be: " << short1 << endl;
    return 0;
}
