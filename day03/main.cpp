#include <iostream>
using namespace std;
int main(){
    // 使用二维数组
    string stu_names[] { "liubei", "guanyu", "zhangfei"};
    string course_names[] {"Chinese", "Math", "English"};
    const int ROW = 3;
    const int COL = 3;
    double scores[ROW][COL];
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << stu_names[i] << "'s" << course_names[j] << "grades: ";
            cin >> scores[i][j]; 
        };
    };
    cout << "\t";
    for(int i = 0; i < COL; i++){
        cout << course_names[i] << "\t";
    };
    cout << endl;
    for(int i = 0; i < ROW; i++){
        cout << stu_names[i] << "\t";
        for(int j = 0; j < COL; j++){
            cout << scores[i][j] << "\t";
        };
        cout << endl;
    } 
    return 0;
};