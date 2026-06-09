#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // unordered-map
    // 1. creation;
    unordered_map<string,int> m;

    // 2. insertion;
    pair<string,int> p1 = make_pair("prajit",1);
    m.insert(p1);

    pair<string,int> p2("Singh",3);
    m.insert(p2);

    m["kumar"] = 2;
    m["kumar"] = 4;

    // 3. searching;
    cout<<m["prajit"]<<endl;
    cout<<m.at("kumar")<<endl;
    // cout<<m.at("unknown")<<endl;
    cout<<m["unknown"]<<endl;

    // 4. size;
    cout<<m.size()<<endl;

    // 5. to check presence;
    cout<<m.count("Prajit")<<endl;
    cout<<m.count("unknown")<<endl;

    // 6. erase;
    m.erase("kumar");
    cout<<m.size()<<endl;

    // 7. iteration;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


    // map
    // 1. creation;
    map<string,int> mp;

    // 2. insertion;
    pair<string,int> pm1 = make_pair("prajit",1);
    mp.insert(pm1);

    pair<string,int> pm2("Singh",3);
    mp.insert(pm2);

    mp["kumar"] = 2;
    mp["kumar"] = 4;

    // 3. searching;
    cout<<mp["prajit"]<<endl;
    cout<<mp.at("kumar")<<endl;
    // cout<<m.at("unknown")<<endl;
    cout<<mp["unknown"]<<endl;

    // 4. size;
    cout<<mp.size()<<endl;

    // 5. to check presence;
    cout<<mp.count("Prajit")<<endl;
    cout<<mp.count("unknown")<<endl;

    // 6. erase;
    mp.erase("kumar");
    cout<<mp.size()<<endl;

    // 7. iteration;
    for(auto i : mp){
        cout<<i.first<<" "<<i.second<<endl;
    }

    map<string,int> :: iterator it2 = mp.begin();
    while(it2 != mp.end()){
        cout<<it2->first<<" "<<it2->second<<endl;
        it2++;
    } 
    return 0;
}