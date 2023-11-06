#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib> //su dung ham rand()
using namespace std;

class SinhVien{
protected:
	string hoten, he;
	int hocphi;
public:
	virtual void Nhap(){
		cout << "Nhap ho ten: "; cin >> ws; getline(cin, hoten);
		cout << "Nhap he: "; cin >> ws; getline(cin, he);
	}
	virtual void Xuat(){
		cout << "Ho ten: " << hoten << endl;
		cout << "He: " << he << endl; 
	}
	friend istream& operator >> (istream& is, SinhVien& sv){
		sv.Nhap();
		return is;
	}
	friend ostream& operator << (ostream& os, SinhVien& sv){
		sv.Xuat();
		return os;
	}
	virtual int Tinhtien() = 0;

	string gethoten(){
		return this->hoten;
	}
	int gethocphi(){
		return this->hocphi;
	}
	
	void xuatfile(ofstream& file){
		file << hoten << endl;
		file << he << endl;
		file << hocphi << endl;
	}
};

class CQ: public SinhVien{
private:
	int tclt, tcth;
	int sumtc;
public:
	void Nhap(){
		SinhVien::Nhap();
		cout << "Nhap so tin chi ly thuyet: "; cin >> tclt;
		cout << "Nhap so tin chi thuc hanh: "; cin >> tcth;
		hocphi = Tinhtien();
	}
	void Xuat(){
		SinhVien::Xuat();
		cout << "So tin chi ly thuyet: " << tclt << endl;
		cout << "so tin chi thuc hanh: " << tcth << endl;
		cout << "Tong tin chi: " << sumtc << endl;
		cout << "Hoc phi: " << hocphi << endl;
	}
	int Tinhtien(){
		sumtc = (tclt*2)+(tcth*3);
		hocphi = sumtc * 200000;
		return hocphi;
		
	}
};
class CLC: public SinhVien{
public:
	int hk;
public:
	void Nhap(){
		SinhVien::Nhap();
		do{
			cout << "Nhap hoc ky (tu 1 den 8): "; cin >> hk;
		}while(hk<1 || hk>8);
		hocphi = Tinhtien();
	}
	void Xuat(){
		SinhVien::Xuat();
		cout << "hoc ky: " << hk << endl;
		cout << "Hoc phi: " << hocphi << endl;
	}
	int Tinhtien(){
		hocphi = 20000000;
		for(int i = 2; i <= hk; i++){ //tu hk 2 tro di
			hocphi *= 1.1; //tang 10% (100+10)/100
		}
		return hocphi;
	}
};

class menu{
private:
	vector <SinhVien *> ds;
	int sl;
public:
	void Nhap(){
		cout << "Nhap so luong sinh vien: "; cin >> sl;
		for(int i = 0; i < sl; i++){
			int loai;
			cout << endl;
			cout << "sinh vien nay thuoc het nao?" << endl;
			cout << "1 - Chinh Quy; 2 - CLC: "; cin >> loai;
			SinhVien *sv;
			if(loai == 1){
				sv = new CQ();
			} else if(loai == 2){
				sv = new CLC();
			} else{
				cout << "Xin moi nhap lai: " << endl;
				i--; continue;
			}
			cin >> *sv;
			ds.push_back(sv);
		}
	}
	void Xuat(){
		for(int i = 0; i < ds.size(); i++) {
			cout << *ds[i] << endl;
		}
	}
	void Chen(){
		sl += 1;
		cout << "Muon chen vao he nao?" << endl;
		cout << "1 - Chinh Quy; 2 - CLC: "; int loai; cin >> loai;
		SinhVien *sv;
		if(loai == 1){
			sv = new CQ();
		} else if (loai == 2){
			sv = new CLC();
		} else {
			cout << "Khong co he nay!" << endl;
			return;
		}
		cin >> *sv;
		ds.push_back(sv);
	}
	void  Xoa(){

		//Nay xoa theo ten
		string find;
		cout << "Nhap ten muon xoa: "; cin.ignore(); getline(cin, find);
		for(int i = 0; i <ds.size(); i++){
			if(find == ds[i]->gethoten()){
				ds.erase(ds.begin()+i);
			}
		}
		
		
/*		//Xoa ngau nhien
		int find = rand() % ds.size(); //Sinh ra so ngau nhien tu 0 den kich thuoc danh sach
		delete ds[find]; //giai phong vung nho cua sinh vien bi xoa
		ds.erase(ds.begin() + find); //xoa phan tu khoi danh sach
		cout << "Xoa thanh cong!" << endl;
		system("pause");*/
	}
	void Sapxep(){
		for(int i = 0; i < ds.size() - 1; i++){
			for(int j = i+1; j < ds.size(); j++){
				if(ds[i]->gethocphi() > ds[j]->gethocphi()){
					swap(ds[i],ds[j]);
				}
			}
		}
		cout << "sap xep thanh cong!" << endl;
		Xuat();
		system("pause");
	}
	
	void Ghids(){
		ofstream file;
		file.open("C:\\Users\\HP\\Desktop\\danhsach.txt");
		if(file.is_open()){
			for(int i = 0; i < ds.size(); i++){
				ds[i]->xuatfile(file);
			}
			cout << "Ghi thanh cong!" << endl;
			file.close();
		} else cout << "Khong mo duoc file!" << endl;
		system("pause");
	}
	void inmenu(){
		char op;
		do{
			system("cls");
			cout << "==============Menu================" << endl;
			cout << "1. Nhap danh sach" << endl;
			cout << "2. In danh sach" << endl;
			cout << "3. Chen them thong tin 1 sinh vien" << endl;
			cout << "4. Xoa thong tin sinh vien" << endl;
			cout << "5. Sap xep danh sach theo hoc phi" << endl;
			cout << "7. Ghi danh sach vao file" << endl;
			cout << "==================================" << endl;
			cout << "Moi nhap lua chon: ";
			cin >> op;
			cout << endl;
			switch(op){
				case '1': Nhap(); break;
				case '2': Xuat(); system("pause"); break;
				case '3': Chen(); system("pause"); break;
				case '4': Xoa(); break;
				case '5': Sapxep(); break;
				case '7': Ghids(); break;
			}
		}while(op != '0');
	}
};

int main(){
	menu a;
	a.inmenu();
	return 0;
}
