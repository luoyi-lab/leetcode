/* 买卖股票的最佳时机 题目描述：
  给定一个数组 prices，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
  你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0。
  示例1：输入 prices = {7,1,5,3,6,4}  输出：5  
  示例2：输入 prices = {7,6,4,3,2,2}  输出：0
*/
#include <iostream>
#include <vector>
#include <algorithm> // 为了用 min 和 max 函数
#include <climits>   // 为了用 INT_MAX 即表示int类型所能存储的最大值
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> & prices)
    {
        if (prices.empty())
        {
            return 0; //先判空
        }

        int min_price = prices[0]; //初始化最低价格为第一天的价格  或者设为INT_MAX也可以
        int max_profit = 0; // 初始化最大利润为0

        for(int i = 0 ; i < prices.size() ; i++)
        {
            if(prices[i] < min_price) // 1.如果当前价格比历史最低价还低，更新最低价
            {
                min_price = prices[i];
            }

            else if(prices[i] - min_price > max_profit) // 2.否则，算今天卖能赚多少钱，如果赚得比之前的最大利润还多，就更新最大利润
            {
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << "prices1最大利润为：" << s.maxProfit(prices1) <<endl;

    vector<int> prices2 = {5,8,2,7,4,1};
    cout << "prices2最大利润为：" << s.maxProfit(prices2) <<endl;

    vector<int> prices3 = {7,6,4,3,1};
    cout << "prices3最大利润为：" << s.maxProfit(prices3) <<endl;
}

// 思考 这道题是拿到全部七天的数据 才算出理论上的最大利润 在现实生活中是事后诸葛没有意义的 
// 主要价值是学会如何在一串数字种 找到最大差值

