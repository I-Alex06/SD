#include <bits/stdc++.h>

bool verifica(std::string s){
    std::stack<char> stiva;
    stiva.push('X');//Element de verificare daca stiva e goala
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stiva.push(s[i]);
        }
        else{
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(stiva.top()=='X')
                    return false;
                if(s[i]==')' && stiva.top()!='(')
                    return false;
                if(s[i]=='}' && stiva.top()!='{')
                    return false;
                if(s[i]==']' && stiva.top()!='[')
                    return false;
                stiva.pop();
            }
        }
    }
    return stiva.top()=='X';
    //pui pe stiva parantezele stanga si cand gasesti una dreapta, verifici daca e de acelasi tip cu cea de pe varful stivei si dai pop
    //daca la final stiva e goala, inseamna ca parantezele sunt corecte
}

struct pereche{
    int p1;
    int p2;
    pereche(int p1, int p2): p1(p1), p2(p2) {};
};

std::queue<pereche> MaiMare(int v[], int l){
    std::queue<pereche> q;
    std::stack<int> stiva;
    for(int i=0;i<l-1;i++){
        if(v[i]>=v[i+1])
            stiva.push(i);
        else{
            q.push(pereche(i,i+1));
            while(!stiva.empty()&&v[stiva.top()]<v[i+1]){
                q.push(pereche(stiva.top(),i+1));
                stiva.pop();
            }
        
        }
    }
    return q;
    //parcurgi vectorul si pui in stiva elementele care sunt mai mari decat urmatorul element
    //cand gasesti un element mai mic decat urmatorul element, pui in coada perechea de indici si scoti din stiva elementele mai mici decat urmatorul element
}

int main(){
    std::string s="({([[({})]])})";
    std::string s2="([({)}])";
    std::cout<<verifica(s2)<<std::endl;
    std::cout<<verifica(s)<<std::endl;
    std::cout<<std::endl;

    int v[]={5,400,2,67,23,652,43,465,23,62,7};
    std::queue<pereche> q=MaiMare(v,sizeof(v)/sizeof(v[0]));
    while(!q.empty()){
        std::cout<<q.front().p1<<" "<<q.front().p2<<std::endl;
        q.pop();
    }
    return 0;
}