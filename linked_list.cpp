#include"SinhVien.cpp"

struct Node
{
    SV data;
    Node* next;
};

Node* MakeNode(SV a){
    Node* P = new Node;
    P->data = a;
    P->next = NULL;
    return P;
}

Node* QuickCreateNode(int n){
    if(n <= 0){
        return NULL;
    }
    Node* head = MakeNode(CreateRandomSV());
    Node* a = head;
    while(n > 0){
        Node* tmp = MakeNode(CreateRandomSV());
        a->next = tmp;
        a = a->next;
        n--;
    }
    return head;
}

void PrintNode(Node* head){
    Node* a = head;
    std::cout << "+-------------------------+----------+\n";
    std::cout << "|" << std::left << std::setw(25) << "Ten sv" << "|" << std::setw(10) << "Tuoi" << "|" << std::endl;
    std::cout << "+-------------------------+----------+\n";
    while (a != NULL)
    {
        InSV(a->data);
        a = a->next;
    }
    std::cout << "+-------------------------+----------+\n";
}

