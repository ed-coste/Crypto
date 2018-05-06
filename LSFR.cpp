// LSFR.cpp : définit le point d'entrée pour l'application console.
//


#include<iostream>
#include<iomanip>
#include<list>
#include<vector>

using namespace std;

bool XOR(int indice, bool Kini[], list<bool> etat_interne, int L) {
    list<bool>::iterator it = etat_interne.begin();
    for (int i = 0; i < L - 1 - indice; i++)
    {
        it++;
    }
    bool a = (Kini[indice] && *it);
    indice += 1;
    it--;
    if (indice == L)
    {
        return a ^ (Kini[indice] && *it);
    }
    return a ^ XOR(indice, Kini, etat_interne, L);
}


vector<bool> Berlekamp_Massey(vector<bool> s){
    int L=0;
    int m=-1;
    vector<bool> f(s.size());
    vector<bool> g(s.size());
    vector<bool> t(s.size());
    f[0]=1;
    g[0]=1;
    int d;
    int n=s.size();
    
    for(int N=0;N<n;N++){
        d=s[N];
        for(int i=1;i<=L;i++){
            d+=f[i]*s[N-i];
        }
        d=d%2;
        if(d==1){
            t=f;
            for(int i=0;N-m+i<n;i++){
                f[N-m+i]=f[N-m+i]^g[i];
            }
            if(2*L<=N){
                L=N+1-L;
                m=N;
                g=t;
            }
        }
        
    }
    return f;
}

int main()
{
    int const L = 5;
    bool Kini[L] = { 1, 1, 0, 1, 0 };
    
    list<bool> etat_interne = { 0, 1, 1, 0, 0 };
    for (int i = 0; i < 10; i++)
    {
        etat_interne.push_front(XOR(0, Kini, etat_interne, L));
        if (*(etat_interne.end()))
        {
            cout << "1" <<endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    cout<<"-----------"<<endl;
    cout<<"Algo de Berlekamp-Massey"<<endl;
    cout<<"Message d'entrée : 001101110"<<endl;
    cout<<"Polynome de rétroaction : "<<endl;
    
    
    
    vector<bool> message({0,0,1,1,0,1,1,1,0});
    vector<bool> poly_generateur=Berlekamp_Massey(message);
    for (int i=0; i<poly_generateur.size(); i++) {
        if(poly_generateur[i]){
            cout<<"X^"<<i<<"+";
        }
    }
    cout<<endl;
    
    system("PAUSE");
    return 0;
}



