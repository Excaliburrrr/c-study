#include <iostream>
using namespace std;

class Building
{
    //在类内加上friend进行声明
    friend void goodFriend(Building& building);
public:
    string m_SittingRoom;
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

private:
    string m_BedRoom;

};

//全局函数
void goodFriend(Building& building)
{
    cout << "好基友的全局函数正在访问: " << building.m_SittingRoom << endl;
    cout << "好基友的全局函数正在访问: " << building.m_BedRoom << endl;

}

void test01(){
    Building b;
    goodFriend(b);
}

int main(){
    test01();
    return 0;
}