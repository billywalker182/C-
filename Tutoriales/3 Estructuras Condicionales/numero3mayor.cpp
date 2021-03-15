#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int n1,n2,n3;
	
	
	cout<<"Digite 3 Numero: ";
	cin>>n1>>n2>>n3;
	
	if((n1>=n2) && (n1>=n3)){
		cout<<"El Mayor es: "<<n1<<endl;
	}
	else if((n2>=n1) && (n2>=n3)){
		cout<<"El Mayor es: "<<n2<<endl;
	}
	else{
		cout<<"El Mayor es: "<<n3<<endl;
	}
	
	system("pause");
	return 0;
}
