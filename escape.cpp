#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person {
    string sex; // Cond 1
    int age; // Cond 2
    string weak; // Cond 3
};

vector<struct person> people;
void sortBySex() {
    vector<struct person> Male, Female;

    for(int i = 0; i < people.size(); i++) {
        if(people[i].sex == "M") Male.push_back(people[i]);
        else Female.push_back(people[i]);
    }
    people.clear();

    for(int i = 0; i < Female.size(); i++) people.push_back(Female[i]);
    for(int i = 0; i < Male.size(); i++) people.push_back(Male[i]);

    Male.clear();
    Female.clear();

    return;
}

// Assume Age is 1 ~ 150
void sortByAge() {
    vector<struct person> ageV[150]; // age[i] -> actual i+1 age.

    for(int i = 0; i < people.size(); i++) {
        ageV[people[i].age-1].push_back(people[i]);
    }
    people.clear();

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < ageV[i].size(); j++) people.push_back(ageV[i][j]);
    }

    for(int i = 149; i >= 7; i--) {
        for(int j = 0; j < ageV[i].size(); j++) people.push_back(ageV[i][j]);
    }

    for(int i = 0; i < 150; i++) {
        ageV[i].clear();
    }
    return;
}

void sortByWeak() {
    vector<struct person> PW, DP, P, None;

    for(int i = 0; i < people.size(); i++) {
        if(people[i].weak == "PW") PW.push_back(people[i]);
        else if(people[i].weak == "DP") DP.push_back(people[i]);
        else if(people[i].weak == "P") P.push_back(people[i]);
        else None.push_back(people[i]);
    }
    people.clear();

    for(int i = 0; i < PW.size(); i++) people.push_back(PW[i]);
    for(int i = 0; i < DP.size(); i++) people.push_back(DP[i]);
    for(int i = 0; i < P.size(); i++) people.push_back(P[i]);
    for(int i = 0; i < None.size(); i++) people.push_back(None[i]);

    PW.clear();
    DP.clear();
    P.clear();
    None.clear();

    return;
}

int main() {
    int order[3], numP;
    cin >> order[0] >> order[1] >> order[2] >> numP;
    cin.ignore();

    string delim = " ";
    for(int per = 0; per < numP; per++) {
        struct person temp;
        string line;
        getline (cin,line);

        size_t pos = 0;
        string token;
        int cond = 0;
        while((pos = line.find(delim)) != string::npos) {
            token = line.substr(0,pos);
            line.erase(0, pos + delim.length());

            if(cond == 0) temp.sex = token;
            if(cond == 1) temp.age = atoi(token.c_str());
            cond++;
        }
        if(cond == 1) {
            temp.age = atoi(line.c_str());
            temp.weak = "None";
        }
        else temp.weak = line;

        people.push_back(temp);
    }

    //Use Radix Sort
    for(int i = 2; i >= 0; i--) {
        if(order[i] == 1) sortBySex();
        else if (order[i] == 2) sortByAge();
        else sortByWeak();
    }

    for(int i = 0; i < numP; i++) {
        cout << people[i].sex << " " << people[i].age;
        if(people[i].weak != "None") cout << " " << people[i].weak;
        cout << endl;
    }

    return 0;
}
