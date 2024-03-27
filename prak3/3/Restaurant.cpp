#include "Restaurant.hpp"

Restaurant::Restaurant(){
}
Restaurant::~Restaurant(){
}
void Restaurant::Push(int val){
    order.push(val);
}
void Restaurant::Pop(int val){
    if (val > order.size()){
        cout << "Proses tidak valid" << endl;
        return;
    }
    for (int i = 0; i < val; i++){
        order.pop();
    }
}
void Restaurant::AddMenu(int k, int val){
    stack<int> temp;
    while (order.size()>k){
        int tempint = order.top();
        order.pop();
        temp.push(tempint);
    }
    while (order.size()>0){
        int tempOrder = order.top() + val;
        order.pop();
        temp.push(tempOrder);
    }
    order = temp;
    Reorder(order.size());
}
void Restaurant::Reorder(int k){
    stack<int> tempOrder;
    if (k > order.size()){
        while (order.size() > 0){
            int temp = order.top();
            order.pop();
            tempOrder.push(temp);
        }
    } else {
        stack<int>temp2Order;
        while (order.size() > k){
            int temp = order.top();
            order.pop();
            temp2Order.push(temp);
        }
        while (order.size() > 0){
            int temp = order.top();
            order.pop();
            tempOrder.push(temp);
        }
        while (temp2Order.size() > 0){
            int temp = temp2Order.top();
            temp2Order.pop();
            tempOrder.push(temp);
        }
    }
    order = tempOrder;
}
ostream& operator<<(ostream& os,Restaurant r){
    os << "(";
    int size = r.order.size();
    for (int i =0; i < size; i++){
        os << r.order.top();
        if (i < size -1){
            os << ", ";
        }
        r.Pop(1);
    }
    return os << ")" << endl;
}