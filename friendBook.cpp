#include<bits/stdc++.h>
#include"freinds.h"
using namespace std;

int Menu(){
    std::system("clear");
    cout<<"Choose Optioon To Proceed:\n1. Input New Friend Data\n2. view All Friends Data\n3.Exit\nYour Option: ";
    int n;cin>>n;
    return n;
}

int main(){
    list<Friend> friends; Friend f;
    //Initialise The List.
    int size=0;
    try{
        ifstream savedlist("friendData");
        if(!savedlist){
            cout<<"No previous data valable. Please Insert some data.\n";
            throw 1;
        }else{
            savedlist>>size;
            while(size--){
                savedlist>>f;
                friends.push_back(f);
            }
            savedlist.close();
        }
    }catch(int i){
        cout<<"Exception raised "<<i<<endl;
    }

    int choice=0,i;
    while(choice!=3){
        choice = Menu();
        switch (choice)
        {
        case 1:
            cin>>f;
            friends.push_back(f);
            break;
        case 2:
            std::system("clear");
            i=1;
            for(auto fr = friends.begin();fr!=friends.end();fr++,i++){
                cout<<i<<".\n"<<*fr<<endl;
            }
            cout<<"Click any key(Enter) to proceed.";
            cin.get();cin.get();
            break;
        case 3:
            break;
        default:
            cout<<"Input a number between 1 and 3. :(\n";
        }

    }

    //Save the list in the file again.
    ofstream updateFile("friendData");
    if(!updateFile){
        cout<<"Can't open file to save the last updates. :( \n";
        return 1;
    }
    size = friends.size();
    updateFile<<size<<endl;
    for(auto fr=friends.begin();fr!=friends.end();fr++){
        f = *fr;
        updateFile<<f;
    }
    updateFile.close();

    return 0;
}