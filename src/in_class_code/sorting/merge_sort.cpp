#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printvector(vector<int> v){
	for (auto x: v){
		cout << x << " ";
	}
	cout << endl;
}

void merge(vector<int> & A,int p,int q,int r){
 
  int n1=q-p+1;
  int n2=r-q;
  int i,j;

  vector<int> L(n1+1);
  vector<int> R(n2+1);
  for (i=0;i<n1;i++)
  	 L[i]=A[p+i-1];
  for (j=0;j<n2;j++)
  	 R[i]=A[q+j];

  L[n1]=999;
  R[n2]=999;
  i=j=0;
  for (int k = p; k<r ; k++){
  	 if (L[i]<R[j]){
  	 	A[k] = L[i];
  	 	i++;
  	 }
  	 else {
  	 	 A[k]=R[j];
  	 	 j++;
  	 }
  }
}

void mergesort(vector<int> & A,int p,int r){

 int q;
 if (p<r){
    q=(p+r)/2;
    mergesort(A,p,q);
    mergesort(A,q+1,r);
    merge(A,p,q,r);
  }
}

int main(int argc, char const *argv[])
{
	int N=argc-1;
	vector<int> v(N);

	// Read in the numbers	
	cout << "sort these numbers" << endl;
	for (int i=0 ; i < N ; i++ )
	 {
		v[i]=stoi(argv[i+1]);
     }

     printvector(v);

     mergesort(v,0,N);

     cout << "the sorted numbers are" << endl;
     printvector(v);

	return 0;
}