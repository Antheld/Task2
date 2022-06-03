#include <string>
#include <iostream>

using namespace std;

int main() {
    string answerPattern = "********** руб: ********** шт., ", answer;

    int orderCost, deposit, change, i = 0, count = 0;
    int moneyValue[]{ 5000,2000,1000,500,200,100,50,10,5,2,1 };

    cin >> orderCost >> deposit;
    change = deposit - orderCost;

    if (change == 0) answer = "0 руб: 0 шт., ";
    else {
        int exitI = 100;
        while (i < 11) {
            if (change - moneyValue[i] >= 0) {
                count++;
                change -= moneyValue[i];
                i--;
            }
            else {
                if (count > 0) {
                    answer += answerPattern;
                    string money = to_string(moneyValue[i]);
                    string moneyCount = to_string(count);
                    answer.replace(answer.find("**********"), 10, money);
                    answer.replace(answer.find("**********"), 10, moneyCount);
                    count = 0;
                    if (change == 0) i = exitI;
                }
            }
            i++;
        }
    }
    answer.resize(answer.size() - 2);
    cout << answer;
}
