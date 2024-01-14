#include <iostream>
#include<map>
#include<string>

class human
{
public:
    int iage;
    std::string sz_add;
    std::string sz_tel;

public:
    void set(int age, std::string add, std::string tel);

};








int main()
{
    std::map<std::string, human>map;
    human h1, h2, h3, h4;
    h1.set(33, "제주", "333");
    h2.set(13, "서울", "133");
    h3.set(23, "부산", "233");
    h4.set(43, "대구", "433");

    map["홍"] = h1;
    map["서"] = h2;
    map.insert(std::make_pair("이기자", h3));
    map.insert(std::make_pair("대", h4));
    std::map<std::string, human>::iterator iter = map.find("이기자");
    if (iter != map.end())
    {
        std::string iKey = iter->first;
        human& data = iter->second;
        data.iage = 99;
        std::cout << iKey << "";
        std::cout << data.iage << "Hello World!\n";
        map.erase(iter);
    }
    /*std::map<std::string, int>m;
    m.insert(std::make_pair("첫번째", 1));
    m.insert(std::make_pair("두번째", 2));
    m.insert(std::make_pair("세번째", 3));
    m.insert(std::make_pair("네번째", 4));
    m.insert(std::make_pair("다섯번째", 5));

    m["f"] = 6;

    m.erase("첫번째");
    m.find("두번째");

    std::cout << "두번째:" << m.find("두번째")->second << std::endl;
    std::cout << "두번째:" << m.count("두번째") << std::endl;*/
    std::map<std::string, human*> map2;// 키,값 한쌍구축된 자료구조
    human* p1 = new human;
    human* p2 = new human;
    human* p3 = new human;
    human* p4 = new human;
    p1->set(10, "서울", "010");
    p2->set(20, "수산", "010");
    p3->set(30, "부산", "010");
    p4->set(40, "대전", "010");
    map2["홍길동"] = p1;
    map2["박개동"] = p2;
    map2.insert(std::make_pair("이기자", p3));
    map2.insert(std::make_pair("서리발", p4));
    auto iter2 = map2.find("이기자");

    if (iter2 != map2.end())
    {
        std::string iKey = iter2->first;
        human* data = iter2->second;
        data->iage = 99;
        std::cout << iKey << "";
        std::cout << data->iage << "Hello World!\n";
        delete data;
        data = nullptr;
        map2.erase(iter2);
    }
    for (auto it = map2.begin();
        it != map2.end();
        it++)
    {
        human* data = it->second;
        delete data;
        it->second = nullptr;
    }
    map2.clear();
    std::cout << "Hello World!\n";

}
void human::set(int age, std::string add, std::string tel)
{
    iage = age;
    sz_add = add;
    sz_tel = tel;

}