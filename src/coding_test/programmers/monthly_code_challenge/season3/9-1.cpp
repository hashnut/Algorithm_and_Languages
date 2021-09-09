#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    bool arr1[10] = {false,};
    
    for (int i = 0; i < numbers.size(); i++)
    {
        arr1[numbers[i]] = true;
    }
 
    for (int i = 1; i < 10; i++)
    {
        if (!arr1[i])
            answer += i;
    }
         
    return answer;
}
