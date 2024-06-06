#include <bits/stdc++.h>

using namespace std;
//BST copil stanga < root < copil dreapta (si succesorii)
//Echilibrat daca inaltimea subarborilor difera maxima cu 1, subarborii sunt echilibrati
struct BST{
    int val;
    BST* left;
    BST* right;

    BST(int val) : val(val), left(nullptr), right(nullptr) {}
};

BST* vs_to_BST(vector<int>&v,int l,int r){
    if(l>r)
        return nullptr;
    int mid=(l+r)/2;
    //cout<<"ook20\n";
    BST* x=new BST(v[mid]);
    //cout<<"ook10\n";
    x->left=vs_to_BST(v,l,mid-1);
    x->right=vs_to_BST(v,mid+1,r);
    //cout<<"ook2";
    return x;

    //pui val din mijloc in nodul curent si apelezi functia pe jumatatea din stanga si pe jumatatea din dreapta
}
void Print_BST(BST* x){
    if(x==nullptr)
        return;
    Print_BST(x->left);
    cout<<x->val<<" ";
    Print_BST(x->right);
}

void InOrder(BST* x, vector<int>&v){
    if(x==nullptr)
        return;
    InOrder(x->left,v);
    v.push_back(x->val);
    InOrder(x->right,v);
    //stanga val dreapta pt inorder(vector sortat)
}

BST* interclasare(BST* x, BST* y){
    vector<int> v1,v2;
    InOrder(x,v1);
    InOrder(y,v2);
    v1.insert(v1.end(),v2.begin(),v2.end());
    sort(v1.begin(),v1.end());
    return vs_to_BST(v1,0,v1.size()-1);
    //transformi in vectori , concatenare, sortare, transformare in BST(BinarySearchTree(Balanced))
}

void kthlargest2(BST* x,int k,int &i,int& val){
    if(x==nullptr||i>k)
        return;
    kthlargest2(x->right,k,i,val);
    i++;
    if(i==k){
        val=x->val;i++;return;}
    kthlargest2(x->left,k,i,val);
    //aplici inorder inversat si te opresti la k fara a salva tot vectorul
}
int kthlargest(BST* x,int k,int i){
    int val;
    kthlargest2(x,k,i,val);
    return val;
}
int countpairs(BST* x,BST* y,int sum){
    vector<int> v1,v2;
    InOrder(x,v1);
    InOrder(y,v2);
    int i=0,j=v2.size()-1;
    int count=0;
    while(i<v1.size()&&j>=0){
        if(v1[i]+v2[j]==sum){
            count++;
            i++;
            j--;
        }
        else if(v1[i]+v2[j]<sum)
            i++;
        else
            j--;
    }
    return count;
    //aplici inorder pe ambele si apoi mergi cu 2 pointeri pe vectori(2 pointer aproach)
}

int main(){

    vector<int> v={1,2,3,4,5,6,7,8,9,10,14,15,16,28,39,41,99};
    vector<int> v2={13,18,19,20,24,40,86,129};
    BST* x=vs_to_BST(v,0,v.size()-1);
    Print_BST(x);
    cout<<"\n\n\n";

    BST* y=vs_to_BST(v2,0,v2.size()-1);
    BST* z=interclasare(x,y);
    Print_BST(z);

    cout<<"\n\n\n"<<kthlargest(x,5,0);
    cout<<"\n"<<kthlargest(y,3,0);
    cout<<"\n"<<kthlargest(z,25,0)<<"\n";

    cout<<"\n\n"<<countpairs(x,y,25)<<"\n";

    return 0;
}