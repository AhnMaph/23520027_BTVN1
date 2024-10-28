#include <iostream>
#include <algorithm>
using namespace std;
struct PhanSo{
    int tu;
    int mau;
};
int n,k, tich = 1,dem=0;
bool xep(PhanSo a, PhanSo b)
{
    int tu_a = int(tich/a.mau)*a.tu;
    int tu_b = int(tich/b.mau)*b.tu;
    return tu_a<tu_b;
}
//
bool sosanh(PhanSo a, PhanSo b)
{
    int tu_a = a.tu * b.mau, tu_b = b.tu*a.mau;
    return tu_a==tu_b;
}
PhanSo a[10001];
int main()
{
    cin>>n;
    cin>>k;
    if(n<=0)
    {
        if(n==0) return 0;
        else cout<<"n phai lon hon 0";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        char slash;
        while(1)
       {
            cin >> a[i].tu >> slash >> a[i].mau;
            if(a[i].mau==0) cout<<"Mau phai khac 0.Nhap lai";
            else break;
       }
       tich = tich * a[i].mau;
    }
    if(n==1)
    {
        if(k==1){
             cout<<a[0].tu<<"/"<<a[0].mau<<"\n";
            cout<<a[0].tu<<"/"<<a[0].mau<<"\n";
        }
        return 0;
    }
    sort(a,a+n,xep);
    if(k==1){
             cout<<a[0].tu<<"/"<<a[0].mau<<"\n";
            cout<<a[n-1].tu<<"/"<<a[n-1].mau<<"\n";
            return 0;
        }
    dem = 1;
    bool f=false;
    PhanSo minn,maxx;
    for(int i=1;i<n;i++)
    {
        if(!sosanh(a[i-1],a[i])) dem++;
        if(dem==k) {
            minn = a[i];
            f = true;
            break;
        }
    }
    dem = 1;

    if(!f) return 0;
    f = false;
    for(int i=n-1;i>=1;i--)
    {
        if(!sosanh(a[i-1],a[i])) dem++;
        if(dem==k) {
            maxx = a[i-1];
            f = true;
            break;
        }
    }
    if(f)
    {
        cout<<maxx.tu<<"/"<<maxx.mau<<"\n";
        cout<<minn.tu<<"/"<<minn.mau<<"\n";
    }
}
