#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Kieu du lieu luu toa do va kich thuoc cua hinh chu nhat
struct HinhChuNhat {
    int x, y, w, h;
};

// Ham tim bien cua hinh chu nhat bat dau tu (i, j)
HinhChuNhat timBien(const vector<vector<int>>& maTran, vector<vector<bool>>& daDanhDau, int i, int j, int m, int n) {
    int w = 0, h = 0;
    // Tim chieu rong w cua hinh chu nhat
    if(maTran[i-1][j-1]) return {0,0,0,0};
    while (j + w <= n && maTran[i][j + w] == 1 && maTran[i-1][j + w] == 0
           && !daDanhDau[i][j + w]) {
        w++;
    }
    if(w == 0) return {0,0,0,0};
    // Tim chieu cao h cua hinh chu nhat
    while (i + h <= m && maTran[i+h][j] == 1 && maTran[i+h][j-1] == 0
           && !daDanhDau[i+h][j]) {
        h++;
    }
    for(int x = i-1; x <=i+h ; x++)
    {
        if(maTran[x][j+w]) return {0,0,0,0};
    }
    for(int y = j-1; y < j+w ; y++)
    {
        if(maTran[i+h][y]) return {0,0,0,0};
    }
    // Danh dau cac o trong hinh chu nhat
    for (int x = i; x <= i + h; x++) {
        for (int y = j; y <= j + w; y++) {
            if(daDanhDau[x][y]) return {0,0,0,0};
        }
    }
    for (int x = i; x <= i + h; x++) {
        for (int y = j; y <= j + w; y++) {
            daDanhDau[x][y] = true;
        }
    }

    return {j, i, w, h};
}

// Ham tim tat ca cac hinh chu nhat trong ma tran
vector<HinhChuNhat> timTatCaHinhChuNhat(const vector<vector<int>>& maTran, int m, int n) {

    vector<vector<bool>> daDanhDau(m+3, vector<bool>(n+3, false));
    vector<HinhChuNhat> ketQua;

    // Duyet qua tat ca cac phan tu trong ma tran
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Neu gap so 1 chua duoc danh dau, tim hinh chu nhat moi
            if (maTran[i][j] == 1 && !daDanhDau[i][j] &&!maTran[i-1][j]) {
                HinhChuNhat hcn = timBien(maTran, daDanhDau, i, j,m,n);
                if (hcn.w >= 2 && hcn.h >= 2) {
                    ketQua.push_back(hcn);
                }
            }
        }
    }
    // Sap xep ket qua theo toa do (y, x) (tu tren xuong duoi, tu trai sang phai)
    sort(ketQua.begin(), ketQua.end(), [](const HinhChuNhat& a, const HinhChuNhat& b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    return ketQua;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> maTran(m+3, vector<int>(n+3));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> maTran[i][j];
        }
    }
    vector<HinhChuNhat> ketQua = timTatCaHinhChuNhat(maTran,m,n);

    for (const auto& hcn : ketQua) {
        cout << "[" << hcn.x -1 << ", " << hcn.y-1 << ", " << hcn.w << ", " << hcn.h << "]\n";
    }

    return 0;
}
