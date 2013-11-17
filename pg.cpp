#include<iostream>
#include<map>

using namespace std;

typedef map<int, int> satGpaMap;

int main(){
	int numOfInputs;
	cout<<"Enter num of Input";
	cin>>numOfInputs;
	int GPA, SAT;
	int gpaList[numOfInputs], satList[numOfInputs];
	satGpaMap sgMap;
	cout<<"Enter GPA followed by SAT score"; 
	for(int i=0;i<numOfInputs;i++){
		cin>>SAT;
		cin>>GPA;
		sgMap[SAT] = GPA;
	}
	//Finding longest decreasing subsequence
	satGpaMap::iterator it;
	int i = 0;
	for(it=sgMap.begin(); it!=sgMap.end(); it++){
		gpaList[i] = (*it).second;
		satList[i] = (*it).first;
		i++;
	}

	int longestLength[numOfInputs];
	int prevNode[numOfInputs];
	
	for(i=0;i<numOfInputs;i++){
		prevNode[i] = -1;
		longestLength[i] = 0;
	}
	longestLength[numOfInputs-1] = 0;
	for(i=numOfInputs-2;i>=0;i--){
		for(int j=numOfInputs-1;j>i;j--){
			if(gpaList[i]>gpaList[j] && longestLength[i]>=longestLength[j]){
				longestLength[i] = longestLength[j] + 1;
				prevNode[i] = j;
			}
		}	
	}
	int maxIndex = 0;
	for(i=1;i<numOfInputs;i++){
		if(longestLength[i]>longestLength[maxIndex])
			maxIndex = i;
	}
//	cout<<"Longest Length"<<longestLength[maxIndex]<<"\t"<<maxIndex<<"\n";
	//Printing the final Output
	int longestLen = longestLength[maxIndex];
	while(longestLen>0 && maxIndex!=-1){
		cout<<satList[maxIndex]<<"\t"<<gpaList[maxIndex]<<"\n";
		maxIndex = prevNode[maxIndex];
	}
	return 0;
}
