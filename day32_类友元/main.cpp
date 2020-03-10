#include <iostream>
#include <string>
using namespace std;
class Building
{
    //friend void goodFriend(Building& building);
    //类友元
    //friend class GoodFriend;
    //成员函数做友元
    friend void GoodFriend::visit();
    friend void goodFriend(Building& buliding);
public:
    Building();
    string m_SittingRoom;

private:
    string m_BedRoom;

};
//类外写成员函数
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
};

class GoodFriend
{
public:
    GoodFriend();
    void visit();
private:
    Building* building;
};
//构造函数
GoodFriend::GoodFriend()
{
    //创建建筑物对象
    building = new Building;
};
void GoodFriend::visit()
{
     cout << "好基友正在访问: " << building -> m_SittingRoom << endl;
     cout << "好基友正在访问: " << building -> m_BedRoom << endl;
}
 
//全局函数
void goodFriend(Building& building)
{
    cout << "好基友的全局函数正在访问: " << building.m_SittingRoom << endl;
    cout << "好基友的全局函数正在访问: " << building.m_BedRoom << endl;

}

void test01(){
    GoodFriend g;
    g.visit();
    /*
    Building b;
    goodFriend(b);
    */
}

int main(){
    test01();
    return 0;
}