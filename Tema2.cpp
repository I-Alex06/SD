#include <iostream>
//simplu inlantuita doar next
//dublu inlantuita next si prev
//circulara next si prev si ultimul element pointeaza catre primul
struct Nod{
    int val;
    Nod* next;
    Nod* prev;
    Nod(int val): val(val), next(nullptr), prev(nullptr) {};
};
Nod* CreazaListaCirculara(int x){Nod* h=new Nod(x);h->next=h;h->prev=h;return h;};
Nod* CreazaLista(int x){Nod* h=new Nod(x);return h;};
void AfiseazaListaCirculara(Nod* head){
    Nod* temp=head;
    do{
        std::cout<<temp->val<<" ";//<<temp<<" "<<temp->next<<" "<<temp->prev<<std::endl;
        temp=temp->next;
    }while(temp!=head);
    std::cout<<std::endl;
}
void AfiseazaLista(Nod* head){
    Nod* temp=head;
    while(temp!=nullptr){
        std::cout<<temp->val<<" ";//<<temp<<" "<<temp->next<<" "<<temp->prev<<std::endl;
        temp=temp->next;
    }
    std::cout<<std::endl;
}
void AdaugaInListaCirculara(Nod* head, int x){
    Nod* temp=head->prev;
    Nod* nou=new Nod(x);
    temp->next=nou;
    nou->prev=temp;
    nou->next=head;
    head->prev=nou;
}
void AdaugaInListaD(Nod* head, int x){
    Nod* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Nod* nou=new Nod(x);
    temp->next=nou;
    nou->prev=temp;
}
void AdaugaInLista(Nod* head, int x){
    Nod* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Nod* nou=new Nod(x);
    temp->next=nou;
}
Nod* Cautare(Nod* head, int x){
    Nod* temp=head;
    while(temp!=nullptr){
        if(temp->val==x)
            return temp;
        temp=temp->next;
    }
    return nullptr;
}
Nod* CautareCirculara(Nod* head, int x){
    Nod* temp=head;
    do{
        if(temp->val==x)
            return temp;
        temp=temp->next;
    }while(temp!=head);
    return nullptr;
}
void StergeDinLista(Nod* head,Nod* sters){
    Nod* temp=head;
    Nod* temp2=nullptr;
    while(temp->next!=sters){
        temp2=temp;
        if(temp->next==nullptr)
            break;
        temp=temp->next;
    }
    if (temp->next==nullptr)
        temp2->next=nullptr;
    else
        temp->next=sters->next;
    delete sters;
}
void StergeDinListaD(Nod* head,Nod* sters){
    if(sters->next==nullptr){
        sters->prev->next=nullptr;
        delete sters;
        return;
    }
    if(sters->prev==nullptr){
        head=sters->next;
        sters->next->prev=nullptr;
        delete sters;
        return;
    }
    sters->prev->next=sters->next;
    sters->next->prev=sters->prev;
    delete sters;
}
void StergeDinListaCirculara(Nod* head,Nod* sters){
    sters->prev->next=sters->next;
    sters->next->prev=sters->prev;
    delete sters;
}


int main(){
    Nod* head=CreazaListaCirculara(1);
    AdaugaInListaCirculara(head,2);
    AdaugaInListaCirculara(head,3);
    AdaugaInListaCirculara(head,4);
    AdaugaInListaCirculara(head,6);
    AdaugaInListaCirculara(head,3);
    AdaugaInListaCirculara(head,5);
    AfiseazaListaCirculara(head);
    StergeDinListaCirculara(head,CautareCirculara(head,3));
    AfiseazaListaCirculara(head);
    StergeDinListaCirculara(head,CautareCirculara(head,5));
    AfiseazaListaCirculara(head);

    std::cout<<std::endl;
    Nod* head2=CreazaLista(100);
    AdaugaInListaD(head2,200);
    AdaugaInListaD(head2,300);
    AdaugaInListaD(head2,400);
    AdaugaInListaD(head2,600);
    AdaugaInListaD(head2,300);
    AdaugaInListaD(head2,500);
    AfiseazaLista(head2);
    StergeDinListaD(head2,Cautare(head2,300));
    AfiseazaLista(head2);
    StergeDinListaD(head2,Cautare(head2,500));
    AfiseazaLista(head2);

    std::cout<<std::endl;
    Nod* head3=CreazaLista(1000);
    AdaugaInLista(head3,2000);
    AdaugaInLista(head3,3000);
    AdaugaInLista(head3,4000);
    AdaugaInLista(head3,6000);
    AdaugaInLista(head3,3000);
    AdaugaInLista(head3,5000);
    AfiseazaLista(head3);
    StergeDinLista(head3,Cautare(head3,3000));
    AfiseazaLista(head3);
    StergeDinLista(head3,Cautare(head3,5000));
    AfiseazaLista(head3);



    return 0;
}