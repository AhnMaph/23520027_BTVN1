#include <iostream>
using namespace std;
struct PhanSo{
    int tu;
    int mau;
};
PhanSo a[10001];
int n;
// ham so sanh 2 phan so
bool sosanh(PhanSo a, PhanSo b)
{

    if(a.mau<0) {a.tu = a.tu*-1; a.mau = a.mau*-1;};
    if(b.mau<0) {b.tu = b.tu*-1; b.mau = b.mau*-1;};
    int tu_a = a.tu * b.mau, tu_b = b.tu*a.mau;
    return tu_a<tu_b;
}
// ham tim phan so lon nhat va be nhat
void MaxMin()
{
    PhanSo maxx = a[0], minn = a[0] ;
    for(int i=1;i<n;i++)
    {
        if(sosanh(maxx,a[i])) maxx = a[i];
        if(sosanh(a[i],minn)) minn = a[i];
    }
    cout<<minn.tu<<"/"<<minn.mau<<"\n";
    cout<<maxx.tu<<"/"<<maxx.mau<<"\n";
}
int main()
{
    cin>>n;
    if(n<=0)
    {
        if(n==0) return 0;
        else cout<<"n phai lon hon 0";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int u,v;
        char s;
        cin>>u>>s;
        while(1) {
            cin>>v;
            if(v==0) cout<<"Mau phai khac 0. Nhap lai mau\n";
            else break;
        }
        a[i] = {u,v};
    }
    MaxMin();

    return 0;
}
