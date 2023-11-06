#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Nguoi{
private:
	string Hoten,Ngaysinh,Quequan;
public:
	Nguoi(string Hoten = "", string Ngaysinh = "", string Quequan = "")
	: Hoten(Hoten),Ngaysinh(Ngaysinh),Quequan(Quequan){}
	void Nhap(){
		cout<< "Nhap ho ten: ";cin>>ws; getline(cin,Hoten);
		cout<< "Nhap ngay sinh: ";cin>>ws; getline(cin,Ngaysinh);
		cout<< "Nhap que quan: ";cin>>ws; getline(cin,Quequan);
	}
	void Xuat(){
		cout << "Ho ten: " <<Hoten<< endl;
		cout << "Ngay sinh: " <<Ngaysinh<< endl;
		cout << "Que quan: " <<Quequan<< endl;
	}
	friend istream& operator >> (istream& is, Nguoi& nv){
		nv.Nhap();
		return is;
	}
	friend ostream& operator << (ostream& os, Nguoi nv){
		nv.Xuat();
		return os;
	}
};

class CBGV: public Nguoi{
private:
	int luongcung, thuong, phat, luongthuclinh;
public:
	void Nhap(){
		cout << endl;
		Nguoi::Nhap();
		cout << "Nhap luong cung: "; cin >> luongcung;
		cout << "Nhap thuong: "; cin >> thuong;
		cout << "Nhap phat: "; cin >> phat;
		luongthuclinh = Luongthuclinh();
	}
	void Xuat(){
		cout << endl;
		Nguoi::Xuat();
		cout << "Luong cung: " << luongcung << endl;
		cout << "Thuong: " << thuong << endl;
		cout << "Phat: " << phat << endl;
		cout << "Luong thuc linh: " << luongthuclinh << endl;
	}
	int Luongthuclinh(){
		luongthuclinh = luongcung + thuong - phat;
		return luongthuclinh;
	}
	int getluongthuclinh(){
		return this->luongthuclinh;
	}
};

class Menu{
private:
	vector <CBGV> nv;
	int sl;
public:
	void Nhap(){
		cout << "Nhap so luong nhan vien: "; cin >> sl;
		nv.resize(sl);
		for(int i = 0; i < sl; i++) nv[i].Nhap();
		
	}
	void Xuat(){
		sapXepTheoLuongthuclinh();
		for(int i = 0; i < nv.size(); i++) nv[i].Xuat();
		system("pause");
	}
	void sapXepTheoLuongthuclinh() {
		int i, j;
    	for(i = 0; i < nv.size() - 1; i++){
    		for(j = i + 1; j < nv.size(); j++){
    			if(nv[j].getluongthuclinh() > nv[i].getluongthuclinh()){
    				swap(nv[i], nv[j]);
				}
			}
		}
	}
	void inmenu(){
		char op;
		do{
			//system("cls");
			cout << "================Menu==================" << endl;
			cout << "1. Nhap nhan vien" << endl;
			cout << "2. Xuat nhan vien" << endl;
			cout << "3. Loc nhan vien theo luong thuc linh" << endl;
			cout << "======================================" << endl;
			cout << "Nhap lua chon: ";
			cin >> op;
			switch(op){
				case '1': Nhap(); break;
				case '2': Xuat(); break;
				case '3': Inluongthuclinh(); break;
			}
		}while(op != '0');
	}
	void Inluongthuclinh(){
		int loc;
		cout << "Nhap mua luong thuc linh: "; cin >> loc;
		for(int i = 0; i < nv.size(); i++){
			if(loc <= nv[i].getluongthuclinh()){
				nv[i].Xuat();
			}			
		}
		system("pause");
	}
};

int main(){
	Menu n;
	n.inmenu();
	return 0;
}
