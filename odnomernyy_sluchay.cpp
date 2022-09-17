#include <bits/stdc++.h>

using namespace std;
#define bez_vyvoda void
#define celyy int
#define razmer size
#define neskolko_raz for
#define vyvod cout
#define esli if
#define vernut return
#define uporiadochit sort
#define nachalo begin
#define konec end
#define dobavit push_back
#define v_drugom_sluchae else
#define nechto auto
#define vvod cin
template<typename T> bez_vyvoda vyvesti_vector(vector<T> a){
    neskolko_raz(celyy i = 0; i < a.razmer(); ++i){
        vyvod << a[i] << " ";
    }
    vyvod << '\n';
}
vector<vector<celyy>> odnomernyy_sluchay (vector<celyy> a,vector<celyy> b){
    esli(a.razmer()!=b.razmer()) vernut {{-3}};
    celyy summa1 = 0, summa2 = 0;
    neskolko_raz(celyy i = 0; i < a.razmer(); ++i){
        summa1+=a[i]; summa2+=b[i];
    }
    esli(summa1!=summa2) vernut {{-2}};
    vector<celyy> indexa(a.razmer());
    neskolko_raz(celyy i = 0; i < a.razmer(); ++i){
        indexa[i] = i;
    }
    uporiadochit(indexa.nachalo(),indexa.konec(),[&](celyy x, celyy y){vernut(a[x]<a[y]);});
    vector<celyy> indexb(a.razmer());
    neskolko_raz(celyy i = 0; i < a.razmer(); ++i){
        indexb[i] = i;
    }
    uporiadochit(indexb.nachalo(),indexb.konec(),[&](celyy x, celyy y){vernut(b[x]<b[y]);});

    neskolko_raz(celyy i = 0; i < a.razmer(); ++i){
        esli(a[indexa[i]]!=b[indexb[i]]) {
            vernut {{-1}};
        }
    }

    celyy koren_proizvodnoi = 0;
    vector<vector<celyy>> otvet(a.razmer());
    otvet[indexa[0]].dobavit(indexb[0]);
    neskolko_raz(celyy i = 1; i < a.razmer(); ++i){
        esli(a[indexa[i]] > a[indexa[koren_proizvodnoi]]){
            koren_proizvodnoi = i;
            otvet[indexa[i]].dobavit(indexb[i]);
        }
        v_drugom_sluchae {
            neskolko_raz(nechto tmp : otvet[indexa[koren_proizvodnoi]]) otvet[indexa[i]].dobavit(tmp);
            otvet[indexa[i]].dobavit(indexb[i]);
            neskolko_raz(celyy j = koren_proizvodnoi; j < i; ++j){
                otvet[indexa[j]].dobavit(indexb[i]);
            }
        }
    }
    vernut otvet;
}
celyy main()
{
    celyy n,m;
    vvod >> n >> m;
    vector<celyy> a(n);
    vector<celyy> b(m);
    neskolko_raz(celyy i = 0; i < n; ++i){
        vvod >> a[i];
    }
    neskolko_raz(celyy i = 0; i < m; ++i){
        vvod >> b[i];
    }
    vector<vector<celyy>> c = odnomernyy_sluchay(a,b);
    celyy kod_oshibki = c[0][0];
    esli(kod_oshibki == -3){
        vyvod << "Kod -3: razmery ne ravny";
    }
    v_drugom_sluchae esli(kod_oshibki==-2){
        vyvod << "Kod -2: summy ne ravny";
    }
    v_drugom_sluchae esli(kod_oshibki == -1){
        vyvod << "Kod -1: vectory prosto ne ravny";
    }
    v_drugom_sluchae{
        neskolko_raz(celyy i = 0; i < n; ++i){
            vyvesti_vector(c[i]);
        }
    }
}

