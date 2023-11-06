#include <iostream>
#include <string>
#include <vector>

using namespace std;
class nguoi{
	private:
		string hoten,ngaysinh,quequan;
	public:
		nguoi(string hoten="",string ngaysinh="",string quequan="")
		: hoten(hoten),ngaysinh(ngaysinh),quequan(quequan){}
	void nhap(){
		cout<<"nhap ho ten: ";cin>>ws;getline(cin,hoten);
		cout<<"nhap ngay sinh: ";cin>>ws;getline(cin,ngaysinh);
		cout<<"nhap que quan: ";cin>>ws;getline(cin,quequan);
	}
	void xuat(){
		cout<<"ho ten: "<<hoten<<endl;
		cout<<"ngay sinh: "<<hoten<<endl;
		cout<<"que quan: "<<hoten<<endl;
	}
	friend istream& operator >>(istream& is,nguoi& nv){
		nv.nhap();
		return is;
	}
	friend ostream& operator <<(ostream& os,nguoi& nv){
		nv.xuat();
		return os;
	}
};
class cbgv:public nguoi{
	private:
		int luongcung, thuong, phat, luongthuclinh;
	public:
		void nhap(){
			nguoi::nhap();
			cout<<"nhap luong cung: ";cin>>luongcung;
			cout<<"nhap thuong: ";cin>>thuong;
			cout<<"nhap phat: ";cin>>phat;
			luongthuclinh=Luongthuclinh();	
		}
		void xuat(){
			cout<<"luong cung:"<<luongcung<<endl;
			cout<<"luong thuong:"<<thuong<<endl;
			cout<<"luong phat:"<<phat<<endl;
			cout<<"luong thuc tinh:"<<luongthuclinh<<endl;
		}
		int Luongthuclinh(){
			luongthuclinh= luongcung + thuong - phat;
			return luongthuclinh;
		}
		int getluongthuclinh(){
		return this->luongthuclinh;
	}
		
};
class Menu{
private:
	vector <cbgv> nv;
	int sl;
public:
	void nhap(){
		cout << "Nhap so luong nhan vien: "; cin >> sl;
		for(int i = 0; i < sl; i++) nv[i].nhap();
	}
	void xuat(){
		sapXepTheoLuongthuclinh();
		for(int i = 0; i < nv.size(); i++) nv[i].xuat();
		system("pause");
	}
	void sapXepTheoLuongthuclinh() {
    	for(int i = 0; i < nv.size() - 1; i++){
    		for(int j = i + 1; j < nv.size(); j++){
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
				case '1': nhap(); break;
				case '2': xuat(); break;
				case '3': Inluongthuclinh(); break;
			}
		}while(op != '0');
	}
	void Inluongthuclinh(){
		int loc;
		cout << "Nhap mua luong thuc linh: "; cin >> loc;
		for(int i = 0; i < nv.size(); i++){
			if(loc <= nv[i].getluongthuclinh()){
				nv[i].xuat();
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
