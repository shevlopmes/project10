#include <bits/stdc++.h>

using namespace std;

template<typename T> void vyvesti_vector(vector<T> a){
    for(int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << '\n';
}
vector<vector<int>> case_1d (vector<int> a,vector<int> b){
    if(a.size()!=b.size()) return {{-3}};
    int summa1 = 0, summa2 = 0;
    for(int i = 0; i < a.size(); ++i){
        summa1+=a[i]; summa2+=b[i];
    }
    if(summa1!=summa2) return {{-2}};
    vector<int> indexa(a.size());
    for(int i = 0; i < a.size(); ++i){
        indexa[i] = i;
    }
    sort(indexa.begin(),indexa.end(),[&](int x, int y){return(a[x]<a[y]);});
    vector<int> indexb(a.size());
    for(int i = 0; i < a.size(); ++i){
        indexb[i] = i;
    }
    sort(indexb.begin(),indexb.end(),[&](int x, int y){return(b[x]<b[y]);});

    for(int i = 0; i < a.size(); ++i){
        if(a[indexa[i]]!=b[indexb[i]]) {
            return {{-1}};
        }
    }

    int koren_proizvodnoi = 0;
    vector<vector<int>> otvet(a.size());
    otvet[indexa[0]].push_back(indexb[0]);
    for(int i = 1; i < a.size(); ++i){
        if(a[indexa[i]] > a[indexa[koren_proizvodnoi]]){
            koren_proizvodnoi = i;
            otvet[indexa[i]].push_back(indexb[i]);
        }
        else {
            for(auto tmp : otvet[indexa[koren_proizvodnoi]]) otvet[indexa[i]].push_back(tmp);
            otvet[indexa[i]].push_back(indexb[i]);
            for(int j = koren_proizvodnoi; j < i; ++j){
                otvet[indexa[j]].push_back(indexb[i]);
            }
        }
    }
    return otvet;
}
signed main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    vector<vector<int>> c = case_1d(a,b);
    int kod_oshibki = c[0][0];
    if(kod_oshibki == -3){
        cout << "Code -3: sizes are not equal";
    }
    else if(kod_oshibki==-2){
        cout << "Code -2: sums are not equal";
    }
    else if(kod_oshibki == -1){
        cout << "Code -1: vectors are not equal without any obvious reason";
    }
    else{
        for(int i = 0; i < n; ++i){
            vyvesti_vector(c[i]);
        }
    }
}

