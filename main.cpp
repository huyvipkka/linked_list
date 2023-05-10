#include"linked_list.cpp"

int main(){
    Node* head = NULL;
    SV sv;
    std::string name;
    bool run = true;
    std::cout << "+-----------------------------------------------------+\n";
    std::cout << "| 1.Random 1 dssv va in ra                            |\n";
    std::cout << "| 2.Nhap bang tay dssv va in ra                       |\n";
    std::cout << "| 3.Chen sv vao vi tri trong ds(k phai stt) va in ra  |\n";
    std::cout << "| 4.Xoa sv tai vi tri trong ds va in ra               |\n";
    std::cout << "| 5.Sap xep ds theo tuoi tang dan                     |\n";
    std::cout << "| 6.Tim kiem theo ten va in ra sv dau tien            |\n";
    std::cout << "| 0.Thoat                                             |\n";
    std::cout << "+-----------------------------------------------------+\n";
    int choose;
    while (run)
    {
        do{
            std::cout << "Nhap lua chon: ";
            std::cin >> choose;
        }while(choose < 0 || choose > 6);
        switch (choose)
        {
            case 1:
                int n;
                std::cout << "Nhap so luong random: ";
                std::cin >> n;
                head = QuickCreateNode(n);
                PrintNode(head);
                break;
            case 2:
                int slsv;
                std::cout << "Nhap so luong sv: ";
                std::cin >> slsv;
                head = NodeInput(slsv);
                PrintNode(head);
                break;
            case 3:
                int indexInsert;
                NhapSV(sv);
                std::cout << "Nhap vi tri can chen: ";
                std::cin >> indexInsert;
                if(Insert(head, sv, indexInsert) == -1)
                    std::cout << "Loi\n";
                else
                    PrintNode(head);
                break;
            case 4:
                int indexPop;
                std::cout << "Nhap vi tri can xoa: ";
                std::cin >> indexPop;
                if(Pop(head, indexPop) == -1)
                    std::cout << "Loi\n";
                else
                    PrintNode(head);
                break;
            case 5:
                Sort(head);
                PrintNode(head);
                break;
            case 6:
                std::cout << "Nhap dung ten sv can tim: ";
                fflush(stdin);
                std::getline(std::cin, name);
                if(Search(head, name) == NULL)
                    std::cout << "Khong tim thay\n";
                else
                    InSV2(*Search(head, name));
                break;
            default:
                run = false;
                break;
        }
    }
    
}