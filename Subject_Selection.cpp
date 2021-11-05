#include<bits/stdc++.h>
using namespace std;

/*
Documentation:
@uthor:
 1. Abu Rifat Muhammed Al Hasib
 2. Sourav Chandra Biswas
 3. Sk Ali Arman
 Created: 5/11/2021
*/

void sub_selection(){

    int t_students, t_subjects;
    cin >> t_students >> t_subjects;

    map<string, int> sub_map; map<int, string> rev_sub_map;
    for(int i = 0; i < t_subjects; i++){
        string str;
        cin >> str;
        sub_map[str] = i;
        rev_sub_map[i] = str;
    }

    vector<int> total_seats(t_subjects);
    for(int i = 0; i < t_subjects; i++){
        int a;
        cin >> a;
        total_seats[i] = a;
    }

    map<int, int> merit_map, rev_merit_map;
    bool migrations[t_students];
    int merit, sub_choice_sz, cntr = 0;
    bool status;
    vector<int> given_choice_list[t_students];

    for(int i = 0; i < t_students; i++){
        cin >> merit; merit_map[merit] = cntr++; rev_merit_map[cntr - 1] = merit;
        cin >> status; migrations[cntr - 1] = status;
        cin >> sub_choice_sz;
        for(int j = 0; j < sub_choice_sz; j++){
            string str;
            cin >> str; int idx = sub_map[str];
            given_choice_list[i].push_back(idx); // ith student's subject list
        }
    }

    int selected_for_individual[t_students];
    for(int i = 0; i < t_students; i++){
        selected_for_individual[i] = -1;
    }
    set<int> selected_subjects[t_subjects];
    set<int> waiting_subjects[t_subjects];

    for(int i = 0; i < t_students; i++){
        for(int j = 0; j < given_choice_list[i].size(); j++){
            int idx = given_choice_list[i][j];
            if(selected_subjects[idx].size() < total_seats[idx]){ // if assignable
                selected_for_individual[i] = idx;
                selected_subjects[idx].insert(i);
                break;
            }
            else{
                waiting_subjects[idx].insert(i);
            }
        }
    }

    // printing inputs
    cout << t_students<<" "<< t_subjects << endl;
    for(int i = 0; i < t_subjects; i++){
        cout << rev_sub_map[i]<<" ";
    }
    cout << endl;
    for(int i = 0; i < t_subjects; i++){
        cout << total_seats[i] <<" ";
    }
    cout << endl;
    for(int i = 0; i < t_students; i++){
        cout << rev_merit_map[i] <<" "<< migrations[i]<<" "<< given_choice_list[i].size()<<" ";
        for(int j = 0; j < given_choice_list[i].size(); j++){
            int idx = given_choice_list[i][j];
            cout << rev_sub_map[idx]<<" ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < t_students; i++){
        if(selected_for_individual[i] != -1){
            string str = rev_sub_map[selected_for_individual[i]];
            cout << str <<" ";
        }
        else cout <<"Not Selected! ";
    }
    cout << endl << endl;

    for(int i = 0; i < t_subjects; i++){
        for(auto j: selected_subjects[i]){
            int merit_ = rev_merit_map[j];
            cout << merit_<<" ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < t_subjects; i++){
        cout << waiting_subjects[i].size()<<" ";
        for(auto j: waiting_subjects[i]){
            int merit_ = rev_merit_map[j];
            cout << merit_<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    // Locate file here

    // starting coding
    sub_selection();
}
