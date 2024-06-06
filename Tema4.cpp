#include <bits/stdc++.h>

void adauga(std::map<char,std::vector<std::string>>& dict, std::string s){
    char c=std::tolower(s[0]);
    dict[c].push_back(s);
    std::sort(dict[c].begin(),dict[c].end());
    //hashtable cu cheie litera si valoare vector de cuvinte, adaugi cuvantul in vectorul corespunzator literei si il sortezi
}

int main(){

    std::map<char,std::vector<std::string>> dict;
    char s[]="Ana arta mere mure multe Andale proaspat abstract conopida Alex frumos";
    char *p=strtok(s," ");
    while(p!=NULL){

        adauga(dict,p);
        p=strtok(NULL," ");
    }

    for(auto& lit:dict){
        std::cout<<lit.first<<": ";
        for(auto& cuv:lit.second){
            std::cout<<cuv<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}