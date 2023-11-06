#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class NhanVien{
private:
	int luong; 
	string hoten, loai;
	
public:
	NhanVien(string hoten = "", string loai = "", int luong = 0)
		: hoten(hoten), loai(loai), luong(luong) {}
	
	 void Nhap(){
		cout << "Nhap ho va ten: "; cin >> ws; getline(cin, hoten);
		cout << "Nhap loai nv: "; cin >> ws; getline(cin, loai);
		cout <<"luong thang: ";cin>>luong;
	}
	 void Xuat(){
		cout << "Ho ten: " << hoten << endl;
		cout << "Loai nhan vien: " << loai << endl;
		cout << "Luong thang: "<< luong<<endl;
	}
	virtual void Tongluong() = 0;
	
	friend istream& operator >> (istream& is, NhanVien& nv){
		nv.Nhap();
		return is;
	}
	friend ostream& operator << (ostream& os, NhanVien& nv){
		nv.Xuat();
		return os;
	}
	int getluong(){
		return luong;
	}
};

class VanPhong: public NhanVien{
private:
	int heso;
public:
	void Nhap(){
		NhanVien::Nhap();
		cout << "Nhap he so: "; cin >> heso;
	}
	void Tongluong(){
		int luong = 1000000 * heso;
	}
};

class Laptrinhvien: public NhanVien{
private:
	int spm;
public:
	void Nhap(){
		NhanVien::Nhap();
		cout << "Nhap so phan mem : "; cin >> spm;
	}
	void Tongluong(){
	int	luong = 5000000 * spm;
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
	void Tongluong(){
	int	luong = 3000000 + thuong;
	}
};

class menu{
private:
	vector <NhanVien *> sl;
	int n;
public:
	void Nhap(){
		cout << "Nhap so luong nhan vien: "; cin >> n;
		for(int i = 0; i < n; i++){
			int loai;
			cout << "Nhap loai nhan vien (1.Vp, 2.Ltv, 3.pv): "; cin >> loai; 
			
			NhanVien *nv;
			if (loai == 1) {
				nv = new VanPhong();
			}else if(loai == 2){
				nv = new Laptrinhvien();
			}else {
				nv = new Phucvu();
			}
			nv->Nhap();
			sl.push_back(nv);
		}
	}
	
	void Xuatdanhsach(){
		cout << "Danh sach : " << endl;
		for(int i = 0; i < sl.size(); i++){
			sl[i]->Tongluong();
			sl[i]->Xuat();
		}
		system("pause");
	}
	void Sapxep(){
		for(int i = 0; i < sl.size() - 1; i++){
			for(int j = i + 1; j < sl.size(); j++){
				if(sl[j]->getluong() > sl[i]->getluong()){
					swap(sl[j],sl[i]);
				}
			}
		}
		cout << "Danh sach nhan vien sau khi sap xep: " << endl;
		Xuatdanhsach();
	}
	void inmenu(){
		char luachon;
		do{
			system("cls");
			cout << "=================Menu=================" << endl;
			cout << "1. Nhap danh sach" << endl;
			cout << "2. In danh sach" << endl;
			cout << "3. Sap xep danh sach cho luong hang thang" << endl;
			cout << "4. Ghi danh sach" << endl;
			cout << "======================================" << endl;
			cout << "Moi nhap lua chon" << endl;
			cin >> luachon;
			switch(luachon){
				case '1': Nhap(); break;
				case '2': Xuatdanhsach(); break;
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
