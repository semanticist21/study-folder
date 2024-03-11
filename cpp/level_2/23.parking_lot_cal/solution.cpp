#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    unordered_map<int, string> car_in;
    unordered_map<int, int> fee_paid;

    for(const string info : records){
        istringstream iss(info);
        string buffer;
        
        vector<string> rs;

        while(getline(iss, buffer, ' ')){
            result.emplace_back(buffer);
        }

    }
    

}

int main()
{
}