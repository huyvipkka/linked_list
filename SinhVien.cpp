#include<string>
#include<iostream>
#include<iomanip>
#include"random.cpp"

std::string surnames[10] = 
{"Tran Duc","Nguyen Thi","Le Van","Pham Hong","Huynh Thi",
"Hoang Minh","Phan Thi","Vu Van","Dang Xuan","Bui Thi"};
std::string names[10] = 
{"Linh","Huong","An","Hai","Trang",
"Binh","Nam","Ngoc","Thao","Tuan"};

struct SV
{
    std::string name;
    int age;
};

void NhapSV(SV &a){
    std::cout << "Nhap ten sv: ";
    std::getline(std::cin, a.name);
    fflush(stdin);
    std::cout << "Nhap tuoi sv: ";
    std::cin >> a.age;
}

SV CreateRandomSV(){
    SV a;
    a.name = surnames[getRandomNumber(0,9)] + " " + names[getRandomNumber(0,9)];
    a.age = getRandomNumber(18, 28);
    return a;
}

void InSV(SV a){
    std::cout << "|" << std::left << std::setw(25) << a.name << "|" << std::setw(10) << a.age << "|" << std::endl;
}
