#include <iostream>
#include<vector>
using namespace std;

template <typename T>
class stack {
    vector<T> v;

public:
    void push(T ele) {
        v.push_back(ele);
    }

    T top() {
        return v[v.size() - 1];
    }

    void pop() {
        v.pop_back();
    }

    bool isEmpty() {
        return v.size() == 0;
    }
};

int main() {
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout<<"Top element:"<<st.top()<<endl;
	st.pop();
	cout<<"Top element:"<<st.top()<<endl;
	
	return 0;
}
