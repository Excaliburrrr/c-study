#include <iostream>
#include "Chat.hpp"
using namespace std;

int main()
{
    cout << "请输入对方的名称：";
    string toName;
    getline(cin, toName);
    cout << "请输入发送给对方的聊天信息：";
    string content;
    getline(cin, content);
    string chat_msg = chatTo(toName, content); 
    cout << chat_msg << endl;
    return 0;
     
}