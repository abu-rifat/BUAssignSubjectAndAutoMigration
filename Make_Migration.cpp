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
    // at first taking input from migration.in
    std::ifstream migin("migration.in");
    //freopen("migration.in","r",stdin);
    //freopen("temp.out","w",stdout);
    int admission_cancelled_number, migration_off_number;
    vector<int> admission_cancelled, migration_off;
    migin >> admission_cancelled_number;
    //cout<<admission_cancelled_number<<"\n";
    
    for(int i = 0; i < admission_cancelled_number; i++){
        int a;
        migin >> a;
        //cout<<a<<"\n";
        admission_cancelled.push_back(a);
    }
    migin >> migration_off_number;
    //cout<<migration_off_number<<"\n";
    for(int i = 0; i < migration_off_number; i++){
        int a;
        migin >> a;
        //cout<<a<<"\n";
        migration_off.push_back(a);
    }
    
    freopen("datafile.io","r",stdin);
    freopen("temp.out","w",stdout);
    // input from migration.in completed
    // input from datafile.io started
    // input output = datafileagain.io
    int t_students, t_subjects;
    cin >> t_students >> t_subjects;
    map<string, int> sub_map; map<int, string> rev_sub_map;
    for(int i = 0; i < t_subjects; i++){
        string str;
        cin >> str; //cout << str << " ";
        sub_map[str] = i;
        rev_sub_map[i] = str;
    }
    //cout << endl;

    vector<int> total_seats(t_subjects);
    for(int i = 0; i < t_subjects; i++){
        int a;
        cin >> a; //cout << a << " ";
        total_seats[i] = a;
    }
    //cout << endl;
    vector<int> admitted(t_students, 0);
    for(int i = 0; i < t_students; i++){
        cin >> admitted[i]; //cout << admitted[i] << " ";
    }
    //cout << endl;
    map<int, int> merit_map, rev_merit_map;
    bool migrations[t_students];
    int merit, sub_choice_sz, cntr = 0;
    bool status;
    vector<int> given_choice_list[t_students];

    for(int i = 0; i < t_students; i++){
        cin >> merit; //cout << merit <<" ";
         merit_map[merit] = cntr++; rev_merit_map[cntr - 1] = merit;
        cin >> status; migrations[cntr - 1] = status;
        cin >> sub_choice_sz;
        for(int j = 0; j < sub_choice_sz; j++){
            string str; //cout << str << endl;
            cin >> str; int idx = sub_map[str];
            given_choice_list[i].push_back(idx); // ith student's subject list
        }
    }
    
    int selected_for_individual[t_students];
    set<int> selected_subjects[t_subjects];
    set<int> waiting_subjects[t_subjects];
    for(int i = 0; i < t_students; i++){
        string str;
        cin >> str; //cout << str << endl;
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
            int idx; cin >> idx; //idx = merit_map[idx];
            //waiting_subjects[i].insert(idx);
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
        //cout << i <<" "<<idx << endl;
    }
    
    for(int i = 0; i < t_subjects; i++){
        waiting_subjects[i].clear();
    }
    ///-----------------------------
    for(int i = 0; i < t_students; i++){
        if(admitted[i] == 0){
            for(int j = 0; j < given_choice_list[i].size(); j++){
                int idx = given_choice_list[i][j];
                if(idx == selected_for_individual[i])break;
                if(selected_subjects[idx].size() < total_seats[idx]){ // if assignable
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
        //if(admitted[i] != 0)continue;
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
