#include <iostream>
#include<string_view>
#include "etcd-cpp-apiv3-0.2.6/etcd/Client.hpp"
#include "etcd-cpp-apiv3-0.2.6/etcd/Response.hpp"

using namespace std;
int main(){
    string str="hello";
    cout<<str<<endl;
    std::string_view sv=" world";
    auto result=str+sv.data();
    cout<< result <<endl;

    etcd::Client etcd("http://127.0.0.1:2379");
    etcd::Response response = etcd.get("/test/key1").get();
    std::cout << response.value().as_string();

    return 0;
}