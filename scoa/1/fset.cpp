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
        float temp; 
        cout<<"Enter Membership value for element ["<<i<<"] : ";
        cin>>temp;
        if(temp<=1)
            A[i] = temp;
        else {
            cout<<"warning!!! membership value must be less than 1\n";
            cout<<"re-enter the value again for ["<<i<<"] element : "; cin>>temp;
        }
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
    cout<<"Enter the elements of set A : ";
    map<int, float> A = acceptSet(n);
    cout<<"Enter the elements of set B : ";
    map<int, float> B = acceptSet(n);

    cout<<"A : ";
    printSet(A);

    cout<<"B : ";    
    printSet(B);

    while(true) {

        cout<<"+--------------------------------------------+\n";
        cout<<"|*********** Fuzzy Set Operations ***********|\n";
        cout<<"+-------+---------------------------+--------+\n";
        cout<<"|       | *** Enter your choice *** |        |\n";
        cout<<"|       +---------------------------+        |\n";
        cout<<"|         1. Union [ A ∪ B ]                 |\n";
        cout<<"|         2. Intersection [ A ∩ B ]          |\n";
        cout<<"|         3. Difference [ A - B ]            |\n";
        cout<<"|         4. Difference [ B - A ]            |\n";
        cout<<"|         5. Complement of A                 |\n";
        cout<<"|         6. Complement of B                 |\n";
        cout<<"|         7. Change set A                    |\n";
        cout<<"|         8. change set B                    |\n";
        cout<<"|         9. Exit the program                |\n";
        cout<<"+--------------------------------------------+\n";

        int ch; 
        cout<<"Enter your choice : ";
        cin>>ch;

        clearScreen;
        cout<<"A : ";
        printSet(A);

        cout<<"B : ";    
        printSet(B);

        cout<<"\n\n*** Output ***\n";
        cout<<"\n----------------\n"; 
        switch (ch)
        {
        case 1:
            cout<<"Union Set : "; printSet(unionSet(A,B)); 
            break;
        
        case 2:
            cout<<"Intersection Set : "; printSet(intersectionSet(A,B));
            break;

        case 3:
            cout<<"A-B : "; printSet(differenceSet(A,complementSet(B)));
            break;

        case 4:
            cout<<"B-A : "; printSet(differenceSet(B,complementSet(A)));
            break;

        case 5:
            cout<<"Complement of A : "; printSet(complementSet(A)); 
            break;

        case 6:
            cout<<"Complement of B : "; printSet(complementSet(B)); 
            break;
        
        case 7:
            cout<<"*** Update A set ***\n\n";
            A = acceptSet(n); cout<<endl;
            break;
            
        case 8:
            cout<<"*** Update B set ***\n\n";
            B = acceptSet(n); cout<<endl;
            break;

        case 9:
            clearScreen;
            cout<<"Exiting ......\n....\n..\n.\n";
            exit(0);
            break;
        
        
        default:
            break;
        }
        cout<<"\n\n\n";
    }

    return 0;

}