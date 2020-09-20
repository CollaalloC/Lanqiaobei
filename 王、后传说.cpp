/*题目描述：
地球人都知道，在国际象棋中，后如同太阳，光芒四射，威风八面，它能控制横、坚、斜线位置。
　　看过清宫戏的中国人都知道，后宫乃步步惊心的险恶之地。各皇后都有自己的势力范围，但也总能找到相安无事的办法。
　　所有中国人都知道，皇权神圣，伴君如伴虎，触龙颜者死......
　　现在有一个n*n的皇宫，国王占据他所在位置及周围的共9个格子，这些格子皇后不能使用（如果国王在王宫的边上，占用的格子可能不到9个）。当然，皇后也不会攻击国王。
　　现在知道了国王的位置（x,y）（国王位于第x行第y列，x,y的起始行和列为1），请问，有多少种方案放置n个皇后，使她们不能互相攻击。
输入格式
　　一行，三个整数，皇宫的规模及表示国王的位置
输出格式
　　一个整数，表示放置n个皇后的方案数
样例输入
8 2 2
样例输出
10
数据规模和约定
　　n<=12
*/

#include<iostream>
#include<cmath>

using namespace std;

int n, k_x,k_y;//棋盘大小，王的坐标
int count;//使用count 的地方改成 ::count 替代（因为std命名空间下也有 std::count ,编译器不确定此处是::count 还是std::count,所以会不明确）
int hashTable[15], P[15];

void queen(int index) //index为列
{
    //递归边界设置
    if(index == n + 1)
    {
        ::count++;
        return;
    }

    //递归条件判断，不满足回溯
    for(int x = 1; x <= n; x++) //皇后 行
    {
        if(hashTable[x] == false) //行是否占据
        {
            bool flag = true; //冲突判定
            if((x >= k_x -1 && x <= k_x + 1)&&(index >= k_y -1 && index <= k_y +1)) //王的范围判定
            //需要都用 && ，将范围限定在王的九宫格内
            {
                flag = false;
                continue;//break直接跳出循环
            }
            for(int pre = 1; pre < index ; pre++)
            {
                if(abs(pre-index)==abs(x - P[pre]))//皇后对角线判定
                //少了abs函数，括号内是P[pre]，上一个皇后的行号
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                P[index] = x;
                hashTable[x] = true;
                queen(index +1);
                hashTable[x] = false;
            }
        }

        
    }

}

int main()
{
    cin >> n >> k_x >>k_y;
    ::count = 0;
    queen(1);
    cout<<::count;
    return 0;
}
