#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("dataFile.io","r",stdin);
	freopen("sub.out","w",stdout);
	int stuCt, subCt;
	cin>>stuCt;
	if(stuCt==-1){
		cout<<"The subject list is not ready yet! Please make subject selection first.\n";
		return 0;
	}
	cin>>subCt;
	cout<<subCt<<"\n";
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
	
	vector<vector<int> >output;
	output.resize(stuCt+6);
	int tmp;
	for(int i=1;i<=subCt;i++){
		output[i].clear();
		output[i].push_back(total_seats[i]);
		for(int j=1;j<=total_seats[i];j++){
			cin>>tmp;
			output[i].push_back(tmp);
		}
	}
	for(int i=1;i<=subCt;i++){
		cin>>tmp;
		int tmp2;
		output[i].push_back(tmp);
		for(int j=1;j<=tmp;j++){
			cin>>tmp2;
			output[i].push_back(tmp2);
		}
		int len=output[i].size();
		for(int j=0;j<len;j++){
			if(j!=0)cout<<" ";
			cout<<output[i][j];
		}
		cout<<"\n";
	}
	return 0;
}

