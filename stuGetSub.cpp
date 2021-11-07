#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("dataFile.io","r",stdin);
	freopen("stuGetSub.out","w",stdout);
	int stuCt, subCt;
	cin>>stuCt;
	if(stuCt==-1){
		cout<<"The subject list is not ready yet! Please make subject selection first.\n";
		return 0;
	}
	cout<<stuCt<<"\n";
	cin>>subCt;
	string subject_list[subCt+6];
	map<string,int>sub_map;
	for(int i=1;i<=subCt;i++){
		cin>>subject_list[i];
		sub_map[subject_list[i]]=i;
	}
	
	int total_seats[subCt+6];
	for(int i=1;i<=subCt;i++){
		cin>>total_seats[i];
	}
	int no_need;
	for(int i=1;i<=stuCt;i++){
		cin>>no_need;
	}
	int merit_list[stuCt+6];
	bool migration_status[stuCt+6];
	int number_of_subject_choice[stuCt+6];
	string subject_choice[stuCt+6][30];
	for(int i=1;i<=stuCt;i++){
		cin>>merit_list[i]>>migration_status[i]>>number_of_subject_choice[i];
		for(int j=1;j<=number_of_subject_choice[i];j++){
			cin>>subject_choice[i][j];
		}
	}
	
	string selected_subject[stuCt+6];
	for(int i=1;i<=stuCt;i++)cin>>selected_subject[i];
	int tmp;
	for(int i=1;i<=subCt;i++){
		for(int j=1;j<=total_seats[i];i++){
			cin>>tmp;
		}
	}
	
	for(int i=1;i<=stuCt;i++){
		cout<<merit_list[i]<<" "<<selected_subject[i]<<" ";
		if(selected_subject[i]=="a_c"){
			cout<<"\n";
			continue;
		}
		int idx=0;
		vector<string>waiting_subject;
		for(int j=1;j<=number_of_subject_choice[i];j++){
			if(subject_choice[i][j]!=selected_subject[i]){
				waiting_subject.push_back(subject_choice[i][j]);
			}else{
				break;
			}
		}
		cout<<waiting_subject.size();
		for(int j=0;j<waiting_subject.size();j++){
			cout<<" "<<waiting_subject[j];
		}
		cout<<"\n";
	}
	return 0;
}
