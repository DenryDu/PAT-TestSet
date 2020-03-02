#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
int main(){
    long a, b, c;
    cin>>a;
    cin>>b;
    c = a + b;
    //convert long to string
    ostringstream os;
    os << c;
    istringstream is(os.str());
    string str;
    is >> str;
    size_t len = str.length();
    for(int index =(int) len-3; index > 0; index -= 3)
        if(str[index-1]>='0'&&str[index-1]<='9')
            str.insert(index, ",");
    cout<<str<<endl;
    return 0;
}
