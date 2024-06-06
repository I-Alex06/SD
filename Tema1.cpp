#include <iostream>
//Pui minimul in fata si repeti pentru restul vectorului
void SelecSort(int v[],int l){
    int min,i2;
    for(int i=0;i<l-1;i++){
        min=v[i];i2=i;
        for(int j=i;j<l;j++){
            if(v[j]<min){
                min=v[j];
                i2=j;
            }
        }
        if(i2!=i){
            v[i2]=v[i];v[i]=min;
        }
    }
};

//Arbore binar in care fiecare nod este mai mare decat copiii sai
void MaxHeap(int v[],int len, int i){
    int max=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<len && v[left]>v[max]){
        max=left;
    }
    if(right<len && v[right]>v[max]){
        max=right;
    }
    if(max!=i){
        int aux=v[i];
        v[i]=v[max];
        v[max]=aux;
        MaxHeap(v,len,max);
    }
};
//Elimini radacina prin swap cu primul element si refaci arborele cu maxheap, repeti pana cand nu mai ai elemente
void HeapSort(int v[],int l){
    for(int i=l/2-1;i>=0;i--){
        MaxHeap(v,l,i);
    }
    for(int i=l-1;i>=0;i--){
        int aux=v[0];
        v[0]=v[i];
        v[i]=aux;
        MaxHeap(v,i,0);
    }

};
int main(){
    int v[]={5,2,67,23,652,43,465,23,62,7};
    for(int i=0;i<sizeof(v)/sizeof(*v);i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
    SelecSort(v,sizeof(v)/sizeof(*v));
    for(int i=0;i<sizeof(v)/sizeof(*v);i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
    int v2[]={5,2,67,23,652,43,465,23,62,7};
    HeapSort(v2,sizeof(v2)/sizeof(*v2));
    for(int i=0;i<sizeof(v2)/sizeof(*v2);i++){
        std::cout<<v2[i]<<" ";
    }
    std::cout<<"\n";

    return 0;
}