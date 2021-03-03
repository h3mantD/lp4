#include<bits/stdc++.h>
using namespace std;

//printing and scanning statements...
#define print(x) cout << #x << "=" << x << "\n"
#define print2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

//declarations
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

//loops
#define fo(i,n,a) for(int i=a; i<n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

//clear screen 
#define clearScreen cout << "\033[2J\033[1;1H"


auto acceptSet(int n) {

    map<int, float> A;

    fo(i,n+1,1) {
        float temp; cin>>temp;
        A[i] = temp;
    }

    return A;
}

// degree_of_membership(Y) = max(degree_of_membership(A), degree_of_membership(B)) 
auto unionSet(map<int, float> A, map<int, float> B) {

   int size = A.size();
   map<int, float> Y;
   fo(i,size+1,1) {
       Y[i] = (A[i] > B[i])? A[i]:B[i];
   }

   return Y;
    
}

// degree_of_membership(Y) = min(degree_of_membership(A), degree_of_membership(B)) 
auto intersectionSet(map<int, float> A, map<int, float> B) {

    int size = A.size();
    map<int, float> Y;
    fo(i,size+1,1) {
       Y[i] = (A[i] < B[i])? A[i]:B[i];
    }

    return Y;    

}

// degree_of_membership(Y) = 1 - degree_of_membership(A)
auto complementSet(map<int, float> A) {
    map<int, float> Y;
    for(auto x:A) {
        Y[x.first] = 1-x.second;
    }

    return Y;
}


// degree_of_membership(Y)= min(degree_of_membership(A), 1-degree_of_membership(B)) 
auto differenceSet(map<int, float> A, map<int, float> B) {

    int size = A.size();
    map<int, float> Y;
    fo(i,size+1,1) {
       Y[i] = (A[i] < B[i])? A[i]:B[i];
    }

    return Y;

}


void printSet(map<int, float> s) {
    cout<<"{ ";
    int i=0, size=s.size();
    for(auto x:s) {
        cout<<x.second<<"/"<<x.first;
        if(i<size-1)
            cout<<" + ";
        i++;
    }
    cout<<" }\n";
}


int main() {

    int n; 
    cout<<"\nEnter the size of set : "; cin>>n;
    map<int, float> A = acceptSet(n);
    map<int, float> B = acceptSet(n);


    cout<<"==================================================\n";
    cout<<"Union Set : "; printSet(unionSet(A,B)); 
    cout<<"Intersection Set : "; printSet(intersectionSet(A,B));
    cout<<"Complement of A : "; printSet(complementSet(A)); 
    cout<<"Complement of B : "; printSet(complementSet(B));
    cout<<"A : ";
    printSet(A);

    cout<<"B : ";    
    printSet(B);
    cout<<"A-B : "; printSet(differenceSet(A,complementSet(B)));   
    cout<<"B-A : "; printSet(differenceSet(B,complementSet(A)));   

}