#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    int base_time = fees[0];
    int base_fee = fees[1];
    int time_unit = fees[2];
    int time_fee = fees[3];

    unordered_map<string, int> car_in;
    unordered_map<string, int> car_times;
    unordered_map<string, int> car_fees;

    for (const string &record : records)
    {
        istringstream iss(record);
        string buffer;

        vector<string> rs;

        while (getline(iss, buffer, ' '))
        {
            rs.emplace_back(buffer);
        }

        string time = rs[0];
        int hour = stoi(time.substr(0, time.find(':')));
        int minute = stoi(time.substr(time.find(':') + 1));

        int total_time = hour * 60 + minute;

        string car = rs[1];
        string inout_type = rs[2];

        if (inout_type == "IN")
        {
            car_in.insert(make_pair(car, total_time));
        }
        else if (inout_type == "OUT")
        {
            int in_time = car_in.at(car);
            int gap = total_time - in_time;

            if (car_times.find(car) != car_times.end())
            {
                int existing_time = car_times.at(car);

                auto it = car_times.find(car);
                it->second = existing_time + gap;
            }
            else
            {
                car_times.insert(make_pair(car, gap));
            }

            car_in.erase(car);
        }
    }

    for (const auto &cars_not_out : car_in)
    {
        string car = cars_not_out.first;
        int in_time = cars_not_out.second;

        int forced_time = 23 * 60 + 59;
        int gap = forced_time - in_time;

        if (car_times.find(car) != car_times.end())
        {
            int existing_time = car_times.at(car);

            auto it = car_times.find(car);
            it->second = existing_time + gap;
        }
        else
        {
            car_times.insert(make_pair(car, gap));
        }
    }

    for (const auto &p : car_times)
    {
        string car = p.first;
        int amount = p.second;

        int fee = base_fee;

        if (amount >= base_time)
        {
            int additional = amount - base_time;
            int additional_fee = ceil((double)additional / (double)time_unit) * time_fee;

            fee += additional_fee;
        }

        car_fees.insert(make_pair(car, fee));
    }

    map<string, int> sorted(car_fees.begin(), car_fees.end());
    vector<int> rs;

    for (const auto &p : sorted)
    {
        rs.emplace_back(p.second);
    }

    return rs;
}

int main()
{
}