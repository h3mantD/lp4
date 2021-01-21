/* 
    * Name : Hemant Durdhawale
    * BE-A : 35
    * Set Operations
*/


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
#define fo(i,n) for(int i=0; i<n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

//clear screen 
#define clearScreen cout << "\033[2J\033[1;1H"

auto acceptSet() {
    int n; 
    cout<<"How many elements you want in set : ";
    cin>>n;
    
    set<int>s;
    cout<<"Enter the elements of set : ";
    fo(i,n) {
        int element; cin>>element;
        s.insert(element);
        //print2(i, s1.size());
    }

    return s;
}


void displaySet(set<int>s) {
    cout<<"set :  {";
    set<int> :: iterator it = s.begin();
    
    fo(i, s.size()-1) {
        cout<<*it<<", ";
        it++;
    }
    
    cout<<*it<<"}"<<endl;
    
}


auto unionSet(set<int>s1, set<int>s2) {
    set<int>temp(s1);
    
    for(auto x: s2)
        temp.insert(x);

    return temp;
}

auto intersection(set<int>s1, set<int>s2) {
    set<int>temp;
    
    for(auto x: s1) {
        for(auto y: s2) {
            if (x==y)
                temp.insert(x);
        }
    }

    return temp;

}

auto difference(set<int>s1, set<int>s2) {
    set<int> iSet = intersection(s1,s2);
    set<int> diff;
    
    /* for(auto x:iSet) {
        diff.erase(x);
    }  
    */

    for(auto x:s1) {
        bool found = false;
        for(auto y:iSet) {
            if(x==y) {
                found = true;
            }
        }

        if(!found) {
            diff.insert(x);
        }
    }

    return diff;
}  


int main(int argc, char const *argv[])
{
        
    cout<<"*** [A] set details ***\n\n";
    set<int>s1 = acceptSet(); cout<<endl;
    cout<<"*** [B] set details ***\n\n";
    set<int>s2 = acceptSet(); cout<<endl;

    clearScreen;
    cout<<"A : ";
    displaySet(s1);

    cout<<"B : ";
    displaySet(s2);

    while(true) {

        cout<<"+--------------------------------------------+\n";
        cout<<"|************** Set Operations **************|\n";
        cout<<"+-------+---------------------------+--------+\n";
        cout<<"|       | *** Enter your choice *** |        |\n";
        cout<<"|       +---------------------------+        |\n";
        cout<<"|         1. Union [ A ∪ B ]                 |\n";
        cout<<"|         2. Intersection [ A ∩ B ]          |\n";
        cout<<"|         3. Difference [ A - B ]            |\n";
        cout<<"|         4. Difference [ B - A ]            |\n";
        cout<<"|         5. Symmetric set difference        |\n";
        cout<<"|         6. Change set A                    |\n";
        cout<<"|         7. change set B                    |\n";
        cout<<"|         8. Exit the program                |\n";
        cout<<"+--------------------------------------------+\n";

        int ch; 
        cout<<"Enter your choice : ";
        cin>>ch;

        clearScreen;
        cout<<"A : ";
        displaySet(s1);

        cout<<"B : ";
        displaySet(s2);
        cout<<endl;
        switch (ch)
        {
        case 1:
            cout<<"[ A ∪ B ] : ";
            displaySet(unionSet(s1,s2));
            break;

        case 2:
            cout<<"[ A ∩ B ] : ";
            displaySet(intersection(s1,s2));
            break;

        case 3:
            cout<<"A-B : ";
            displaySet(difference(s1,s2));
            break;

        case 4:
            cout<<"B-A : ";
            displaySet(difference(s2,s1));
            break;

        case 5:
            cout<<"Symmetric set difference is : ";
            displaySet(difference(unionSet(s1,s2),intersection(s1,s2)));
            break;

        case 6:
            cout<<"*** A set details ***\n\n";
            s1 = acceptSet(); cout<<endl;
            break;
            
        case 7:
            cout<<"*** B set details ***\n\n";
            s2 = acceptSet(); cout<<endl;
            break;
        
        case 8:
            clearScreen;
            cout<<"Exiting ......\n....\n..\n.\n";
            exit(0);
            break;

        
        default:
            break;
        }
    
    cout<<endl;

    
    }

    cout<<endl;
    cout<<endl;

    return 0;
}

/* 
    *** Todo 
    * union
    * intersectin
    * differece
    * complement
    * 
    * 
    * 
    * write program in any language to perform various operation on set like union, intersection, difference, complement etc
*/