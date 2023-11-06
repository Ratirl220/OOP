#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class NhanVien{
protected:
	string hoten, loai;
	int luong; //float luong;
public:
	int getluong(){
		return luong;
	}
	NhanVien(string hoten = "", string loai = "", int luong = 0)
		: hoten(hoten), loai(loai), luong(luong) {}
//	NhanVien(string hoten = "", string loai = "", int luong = 0){
//		this->hoten = hoten;
//		this->loai = loai;
//		this->luong = luong;
//	}
	
	virtual void Nhap(){
		//cin.ignore();
		cout << "Nhap ho ten: "; cin >> ws; getline(cin, hoten);
		cout << "Nhap loai nhan vien: "; cin >> ws; getline(cin, loai);
	}
	virtual void Xuat(){
		cout << "Ho ten: " << hoten << endl;
		cout << "Loai nhan vien: " << loai << endl;
		cout << "Luong thang: "<< luong << " dong" <<endl;
	}
	virtual void Tinhluong() = 0;
	
	friend istream& operator >> (istream& is, NhanVien& nv){
		nv.Nhap();
		return is;
	}
	friend ostream& operator << (ostream& os, NhanVien& nv){
		nv.Xuat();
		return os;
	}
//	void xuatfile(ofstream file){
//		file << hoten << endl;
//		file << loai << endl;
//		file << luong << endl;
//	}
};

class VanPhong: public NhanVien{
private:
	int heso;
public:
	void Nhap(){
		NhanVien::Nhap();
		cout << "Nhap he so chuc vu: "; cin >> heso;
	}
	void Tinhluong(){
		luong = 1000000 * heso;
	}
};

class Laptrinhvien: public NhanVien{
private:
	int sophanmem;
public:
	void Nhap(){
		NhanVien::Nhap();
		cout << "Nhap so phan mem viet duoc: "; cin >> sophanmem;
	}
	void Tinhluong(){
		luong = 5000000 * sophanmem;
	}
};

class Phucvu: public NhanVien{
private:
	int thuong;
public:
	void Nhap(){
		NhanVien::Nhap();
		cout << "Nhap thuong: "; cin >> thuong;
	}
	void Tinhluong(){
		luong = 3000000 + thuong;
	}
};

class menu{
private:
	vector <NhanVien *> danhsach;
	int sl;
public:
	void Nhap(){
		cout << "Nhap so luong nhan vien: "; cin >> sl;
		for(int i = 0; i < sl; i++){
			int loai;
			cout << "Nhap loai nhan vien (1 - Van phong, 2 - Lap trinh vien, 3 - Phuc vu): "; cin >> loai; 
			
			NhanVien *nv; //dung push_back phai khai bao con tro;
			if (loai == 1) {
				nv = new VanPhong();
			}else if(loai == 2){
				nv = new Laptrinhvien();
			}else if(loai == 3){
				nv = new Phucvu();
			}else{
				cout << "Loai nhan vien khong hop le. Vui long nhap lai" << endl;
				i--;
				continue;
			}
			nv->Nhap();
			danhsach.push_back(nv);
		}
		//cout << "Nhap nhan vien thanh cong" << endl;
	}
	
	void Xuat(){
//		if(danhsach.empty()){
//			cout << "Danh sach nhan vien rong." << endl;
//		}
		cout << "Danh sach nhan vien: " << endl;
		for(int i = 0; i < danhsach.size(); i++){
			danhsach[i]->Tinhluong();
			danhsach[i]->Xuat();
		}
		system("pause");
	}
	void Sapxep(){
		/*if(danhsach.empty()){
			cout << "Danh sach nhan vien rong." << endl;
		}*/
		for(int i = 0; i < danhsach.size() - 1; i++){
			for(int j = i + 1; j < danhsach.size(); j++){
				if(danhsach[j]->getluong() > danhsach[i]->getluong()){
					swap(danhsach[j],danhsach[i]);
				}
			}
		}
		cout << "Danh sach nhan vien sau khi sap xep: " << endl;
		Xuat();
	}
//	void Ghids()
//	{
//		if(danhsach.empty()){
//			cout << "Danh sach nhan vien rong." << endl;
//		}
//		ofstream file;
//		file.open("C:\\Users\\HP\\Desktop\\danhsach.txt");
//		if(file.is_open()){
//			file << danhsach.size() << endl;
//			
//			for(int i = 0; i < danhsach.size(); i++) danhsach[i]->Xuat();
//			cout << "Da ghi xong" <<endl;
//			file.close();
//		}
//		else cout << "Khong mo duoc file!" << endl;
//		system("pause");
//	}
	void inmenu(){
		char luachon;
		do{
			system("cls");
			cout << "=================Menu=================" << endl;
			cout << "1. Nhap danh sach" << endl;
			cout << "2. In danh sach" << endl;
			cout << "3. Sap xep danh sach cho luong hang thang" << endl;
			cout << "======================================" << endl;
			cout << "Moi nhap lua chon" << endl;
			cin >> luachon;
			switch(luachon){
				case '1': Nhap(); break;
				case '2': Xuat(); break;
				case '3': Sapxep(); break;
			}
		}while(luachon != '0');
	}
};

int main(){
	menu a;
	a.inmenu();
	return 0;
}
