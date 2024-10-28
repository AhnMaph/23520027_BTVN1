#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // std::gcd tu C++17

using namespace std;

// Tim UCLN cua hai so nguyen
int UCLN(int a, int b) {
    return b == 0 ? a : UCLN(b, a % b);
}

// So sanh hai phan so a1/b1 va a2/b2
bool soSanh(pair<int, int> f1, pair<int, int> f2) {
    if(f1.second<0) {f1.first = f1.first*-1; f1.second = f1.second*-1;};
    if(f2.second<0) {f2.first = f2.first*-1; f2.second = f2.second*-1;};
    return f1.first * f2.second < f2.first * f1.second;
}

// Kiem tra neu tich cua tap hop con bang phan so tich
bool sosanh(int tu, int mau, int tutich, int mautich) {
    return tu * mautich == mau * tutich;
}

int main() {
    int n;
    cin >> n;

    // Nhap danh sach cac phan so
    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; ++i) {
        char slash;
        cin >> ps[i].first >> slash >> ps[i].second;
    }

    // Nhap phan so tich
    int tutich, mautich;
    char slash;
    cin >> tutich >> slash >> mautich;

    vector<pair<int, int>> ketQua;
    int soLuongMin = n + 1;  // Khoi tao voi so lon hon n de de so sanh

    // Duyet tat ca cac tap hop con 2^n-1 truong hop
    for (int mask = 1; mask < (1 << n); ++mask) {
        int tu = 1, mau = 1;  // Tich khoi tao la 1/1
        vector<pair<int, int>> tapCon;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                // Nhan phan so vao tich
                tu *= ps[i].first;
                mau *= ps[i].second;
                tapCon.push_back(ps[i]);
            }
        }

        // Rut gon phan so
        int g = UCLN(tu, mau);
        tu /= g;
        mau /= g;

        // Kiem tra neu tich bang phan so tich
        if (sosanh(tu, mau, tutich, mautich)) {
            if (tapCon.size() < soLuongMin) {
                soLuongMin = tapCon.size();
                ketQua = tapCon;
            }
        }
    }

    // Xuat ket qua
    if (ketQua.empty()) {
        return 0;
    } else {
        sort(ketQua.begin(), ketQua.end(), soSanh);
        for (const auto& frac : ketQua) {
            cout << frac.first << "/" << frac.second << " ";
        }
        cout << endl;
    }

    return 0;
}
