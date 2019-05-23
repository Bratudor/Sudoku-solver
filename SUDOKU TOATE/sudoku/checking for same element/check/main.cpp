#include <iostream>

using namespace std;
bool checkforsame(int a[]);
int main()
{
    int arr[]={1,4,3,7,5,6,7,8,9};
    cout<<checkforsame(arr);
    return 0;
}
bool checkforsame(int a[]){
    int counter=1;
    int times=0;
    for(int h=0;h<9;h++){
    for(int i=0;i<9;i++){
        if(a[i]==counter){
            //cout<<" da";
            times++;
        }
    }
    if(times!=1){
        //cout<<"FALSE";
        return false;
        }
        counter++;
        times=0;
        //cout<<endl;

    }
        return true;
    }

