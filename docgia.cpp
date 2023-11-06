#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class DocGia {
protected:
    string hoTen;
    string ngayLapThe;
    int soThangHieuLuc;
public:
    DocGia(string hoten = "", string ngaylapthe = "", int sothanghieuluc = 0) {
        hoTen = hoten;
        ngayLapThe = ngaylapthe;
        soThangHieuLuc = sothanghieuluc;
    }
    virtual ~DocGia() {}
    virtual int tinhTien() = 0; // hàm ?o, tính ti?n làm th? c?a m?t d?c gi?
    friend istream& operator>>(istream& is, DocGia& dg) {
        cout << "Nhap ho ten: ";
        getline(is, dg.hoTen);
        cout << "Nhap ngay lap the (dd/mm/yyyy): ";
        getline(is, dg.ngayLapThe);
        cout << "Nhap so thang hieu luc: ";
        is >> dg.soThangHieuLuc;
        return is;
    }
    friend ostream& operator<<(ostream& os, DocGia& dg) {
        os << "Ho ten: " << dg.hoTen << endl;
        os << "Ngay lap the: " << dg.ngayLapThe << endl;
        os << "So thang hieu luc: " << dg.soThangHieuLuc << endl;
        os << "Tien lam the: " << dg.tinhTien() << " VND" << endl;
        return os;
    }
};

class DocGiaTreEm : public DocGia {
private:
    string hoTenNguoiDaiDien;
public:
    DocGiaTreEm(string hoten = "", string ngaylapthe = "", int sothanghieuluc = 0, string hotennguoidaidien = "") : DocGia(hoten, ngaylapthe, sothanghieuluc) {
        hoTenNguoiDaiDien = hotennguoidaidien;
    }
    int tinhTien() {
        return soThangHieuLuc * 5000;
    }
    friend istream& operator>>(istream& is, DocGiaTreEm& dgte) {
    is >> static_cast<DocGia&>(dgte); // d?c thông tin chung c?a d?c gi?
    cout << "Nhap ho ten nguoi dai dien: ";
    getline(is, dgte.hoTenNguoiDaiDien);
    return is;
}
friend ostream& operator<<(ostream& os, DocGiaTreEm& dgte) {
    os << static_cast<DocGia&>(dgte); // xu?t thông tin chung c?a d?c gi?
    os << "Ho ten nguoi dai dien: " << dgte.hoTenNguoiDaiDien << endl;
    return os;
}
};

class DocGiaNguoiLon : public DocGia {
private:
string soCMND;
public:
DocGiaNguoiLon(string hoten = "", string ngaylapthe = "", int sothanghieuluc = 0, string socmnd = "") : DocGia(hoten, ngaylapthe, sothanghieuluc) {
soCMND = socmnd;
}
int tinhTien() {
return soThangHieuLuc * 10000;
}
friend istream& operator>>(istream& is, DocGiaNguoiLon& dgnl) {
is >> static_cast<DocGia&>(dgnl); // d?c thông tin chung c?a d?c gi?
cout << "Nhap so CMND: ";
getline(is, dgnl.soCMND);
return is;
}
friend ostream& operator<<(ostream& os, DocGiaNguoiLon& dgnl) {
os << static_cast<DocGia&>(dgnl); // xu?t thông tin chung c?a d?c gi?
os << "So CMND: " << dgnl.soCMND << endl;
return os;
}
};

class ThuVien {
private:
vector<DocGia*> dsDocGia;
public:
void nhapDS() { // nh?p danh sách các d?c gi?
int n;
cout << "Nhap so luong doc gia: ";
cin >> n;
cin.ignore(); // lo?i b? ký t? \n trong buffer
for (int i = 0; i < n; i++) {
cout << "Nhap thong tin doc gia thu " << i+1 << endl;
cout << "Nhap loai doc gia (0 - Tre em, 1 - Nguoi lon): ";
int loaiDG;
cin >> loaiDG;
cin.ignore(); // lo?i b? ký t? \n trong buffer
switch (loaiDG) {
case 0: {
DocGiaTreEm* dgte = new DocGiaTreEm();
cin >> *dgte;
dsDocGia.push_back(dgte);
break;
}
case 1: {
DocGiaNguoiLon *dgnl = new DocGiaNguoiLon();
cin >> *dgnl;
dsDocGia.push_back(dgnl);
break;
}
default:
cout << "Loai doc gia khong hop le!" << endl;
break;
}
}
}
void xuatDS() {
for(auto it = dsDocGia.begin();it != dsDocGia.end(); it++) {
cout << it << endl;
}
}
int tinhTongTien() { 
int tongTien = 0;
for (auto it = dsDocGia.begin();it != dsDocGia.end(); it++) {
tongTien += (it)->tinhTien(); 
}
return tongTien;
}
void sapXepTheoTien() { 
sort(dsDocGia.begin(), dsDocGia.end(), [](DocGia a, DocGia b) {
return a->tinhTien() > b->tinhTien();
};
}
void sapXepTheoThang() { // s?p x?p danh sách các d?c gi? theo s? tháng có hi?u l?c tang d?n
sort(dsDocGia.begin(), dsDocGia.end(), [](DocGia a, DocGia* b) {
return a->getSoThangHieuLuc() < b->getSoThangHieuLuc();
};

void ghiDSVaoFile(string filename) { // ghi danh sách các d?c gi? vào file
ofstream ofs(filename);
if (!ofs.is_open()) {
cout << "Khong mo duoc file de ghi!" << endl;
return;
}
for (auto it = dsDocGia.begin(); it != dsDocGia.end(); it++) {
ofs << **it << endl; // s? d?ng toán t? * hai l?n d? truy c?p d?n d?i tu?ng DocGia th?c s?
}
ofs.close();
}
};

int main() {
ThuVien tv;
tv.nhapDS();
cout << "Danh sach doc gia:\n";
tv.xuatDS();

cout << "\nTong tien lam the: " << tv.tinhTongTien() << " VND\n";

tv.sapXepTheoTien();
cout << "\nDanh sach doc gia sap xep theo tien lam the:\n";
tv.xuatDS();

tv.sapXepTheoThang();
cout << "\nDanh sach doc gia sap xep theo so thang co hieu luc:\n";
tv.xuatDS();

tv.ghiDSVaoFile("dsdocgia.txt");
cout << "\nDa ghi danh sach doc gia vao file dsdocgia.txt" << endl;

return 0;
}


