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

void Make_Migration(){
    std::ifstream migin("migration.in");
    int admission_cancelled_number, migration_off_number;
    vector<int> admission_cancelled, migration_off;
    migin >> admission_cancelled_number;
    for(int i = 0; i < admission_cancelled_number; i++){
        int a;
        migin >> a;
        admission_cancelled.push_back(a);
    }
    migin >> migration_off_number;
    for(int i = 0; i < migration_off_number; i++){
        int a;
        migin >> a;
        migration_off.push_back(a);
    }
    
    freopen("dataFile.io","r",stdin);
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
    vector<int> admitted(t_students, 0);
    for(int i = 0; i < t_students; i++){
        cin >> admitted[i];
    }
    map<int, int> merit_map, rev_merit_map;
    bool migrations[t_students];
    int merit, sub_choice_sz, cntr = 0;
    bool status;
    vector<int> given_choice_list[t_students];

    for(int i = 0; i < t_students; i++){
        cin >> merit;
         merit_map[merit] = cntr++; rev_merit_map[cntr - 1] = merit;
        cin >> status; migrations[cntr - 1] = status;
        cin >> sub_choice_sz;
        for(int j = 0; j < sub_choice_sz; j++){
            string str;
            cin >> str; int idx = sub_map[str];
            given_choice_list[i].push_back(idx);
        }
    }
    
    int selected_for_individual[t_students];
    set<int> selected_subjects[t_subjects];
    set<int> waiting_subjects[t_subjects];
    for(int i = 0; i < t_students; i++){
        string str;
        cin >> str;
        if(str == "Not_Selected!"){
            selected_for_individual[i] = -1;continue;
        }
        if(str == "a_c"){
            selected_for_individual[i] = -1; continue;
        }
        int idx = sub_map[str];
        selected_for_individual[i] = idx;
    }
    
    
    for(int i = 0; i < t_subjects; i++){
        for(int j = 0; j < total_seats[i]; j++){
            int idx; cin >> idx;
            if(idx == -1)continue;
            idx = merit_map[idx];
            selected_subjects[i].insert(idx);
        }
    }
    
    for(int i = 0; i < t_subjects; i++){
        int sz;
        cin >> sz;
        for(int j = 0; j < sz; j++){
            int idx; cin >> idx;
        }
    }
   
    
    for(int i = 0; i < admission_cancelled.size(); i++){
        int idx = merit_map[admission_cancelled[i]];
        admitted[idx] = -1;
    }
    for(int i = 0; i < migration_off.size(); i++){
        int idx = merit_map[migration_off[i]];
        admitted[idx] = 1; 
    }
    for(int i = 0; i < admission_cancelled.size(); i++){
        int a = merit_map[admission_cancelled[i]];
        int idx = selected_for_individual[a];
        selected_subjects[idx].erase(a);
    }
    
    for(int i = 0; i < t_subjects; i++){
        waiting_subjects[i].clear();
    }
    for(int i = 0; i < t_students; i++){
        if(admitted[i] == 0){
            for(int j = 0; j < given_choice_list[i].size(); j++){
                int idx = given_choice_list[i][j];
                if(idx == selected_for_individual[i])break;
                if(selected_subjects[idx].size() < total_seats[idx]){
                    int old_idx = selected_for_individual[i];
                    selected_subjects[old_idx].erase(i);
                    selected_for_individual[i] = idx;
                    selected_subjects[idx].insert(i);
                    break;
                }
                else{
                    waiting_subjects[idx].insert(i);
                }
            }
        }
    }
    
    // printing inputs
    freopen("dataFile.io","w",stdout);
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
        cout << admitted[i] <<" ";
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
        if(admitted[i] == -1){
            cout << "a_c"<< " "; continue;
        }
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
        for(int j = selected_subjects[i].size(); j < total_seats[i]; j++){
            cout << -1 <<" ";
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
    //copying from datafileagain.io to datafile.io
    
}

int main(){
    // Locate file here
    
    // starting coding
    
    Make_Migration();
}
