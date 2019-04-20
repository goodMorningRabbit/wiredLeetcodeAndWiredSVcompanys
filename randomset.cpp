#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class RandomizedSet {
public:
    // 8.32-8.47
    /** Initialize your data structure here. */
    RandomizedSet() {
        this->size=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)== m.end()){
            cout<<"start insert"<< endl;
            l.push_back(val);
            size++;
            m[ val ]= prev(l.end());
            cout<<"insert:"<<*m[val]<< endl;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)== m.end() ) return false;
        cout<<"bbbb"<<endl;
        cout<<*m[val]<<endl;
        l.erase(m[val]);
        cout<<"aaaaa"<<endl;
        cout<< *m[val]<<" is removed."<< endl;
        m.erase(val);
        size--;
        cout<<"remove:"<<l.size()<< endl;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int t=l[ rand()% size ];
        cout<<"get random:"<<t<< endl;
        return t;
    }
private:
    unordered_map<int, vector<int>::iterator> m;
    vector<int> l;
    int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
int main(){
	RandomizedSet* obj = new RandomizedSet();
	bool a = obj->insert(1);
	bool b = obj->insert(2);
	bool c = obj->insert(3);
	int d= obj->getRandom();
	int e= obj->getRandom();
	int f= obj->getRandom();
	int g= obj->remove(2);
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<< " "<< f<<" "<<g<< endl;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
