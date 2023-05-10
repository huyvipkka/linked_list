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

void Append(Node* &head, SV a){
    if (head == NULL)
        head = MakeNode(a);
    else{
        Node* t = MakeNode(a);
        Node* p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = t;
    }
}

Node* QuickCreateNode(int n){
    Node* head = NULL;
    while(n > 0){
        Append(head, CreateRandomSV());
        n--;
    }
    return head;
}

Node* NodeInput(int n){
    Node* head = NULL;
    for(;n > 0;){
        SV a;
        NhapSV(a);
        Append(head, a);
        n--;
    }
    return head;
}

void PrintNode(Node* head){
    Node* a = head;
    std::cout << "+------+-------------------------+----------+\n";
    std::cout << std::left << "|" << std::setw(6) << "STT" << "|" << std::setw(25) << "Ten sv" << "|" << std::setw(10) << "Tuoi" << "|" << std::endl;
    std::cout << "+------+-------------------------+----------+\n";
    int i = 1;
    while (a != NULL)
    {
        std::cout << std::left << "|" << std::setw(6) << i;
        InSV(a->data);
        a = a->next;
        i++;
    }
    std::cout << "+------+-------------------------+----------+\n";
}


int Count(Node* head){
    int cnt = 0;
    Node* p = head;
    while (p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

int Insert(Node* &head, SV a, int index){
    if(index < 0 || index > Count(head))
        return -1;
    else if(index == 0){
        Node* t = new Node;
        t->data = a;
        t->next = head;
        head = t;
        return 0;
    }
    else{
        Node* p = head;
        Node* t = MakeNode(a);
        for(int i = 0; i < index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        return 0;
    }
}

int Pop(Node* &head, int index){
    if(index < 0 || index >= Count(head))
        return -1;
    else if(index == 0){
        head = head->next;
        return 0;
    }
    else{
        Node* p = head;
        while (index > 1){
            p = p->next;
            index--;
        }
        Node* after = p->next;
        p->next = after->next;
        return 1;
    }
}

void Sort(Node* head){
    if (head == NULL || head->next == NULL)
        return;

    Node* current;
    Node* last = NULL;
    bool swapped;
    do{
        current = head;
        swapped = false;
        while (current->next != last)
        {
            if(current->data.age > current->next->data.age)
                std::swap(current->data, current->next->data);
            swapped = true;
            current = current->next;
        }
        last = current;
    }while(swapped);
}

SV* Search(Node* head, std::string name){
    Node* p = head;
    while (p != NULL)
    {
        if(p->data.name == name)
            return &(p->data);
        p = p->next;
    }
    return NULL;
}