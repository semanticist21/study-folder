#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> s;

    for(int i=0; i<str_list.size();i++)
        if(str_list[i] == "l") {s.insert(s.begin(), str_list.begin(), str_list.begin()+i); break;}
        else if(str_list[i] =="r") {s.insert(s.begin(), str_list.begin()+i+1,str_list.end()); break;}

    return s;
}

int main(){
    return 0;
}