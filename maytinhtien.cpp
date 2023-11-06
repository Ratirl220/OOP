#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class SanPham{
public:
	int ma, gia, sl;
	string ten;
public:
	SanPham(int ma = 0, int gia = 0, int sl = 0, string ten = ""):
		ma(ma), gia(gia), sl(sl), ten(ten){
		}
	
	void Nhap(){
		cout << endl;
		cout << "Nhap ma hang: "; cin >> ma;
		cout << "Nhap ten hang: "; cin >> ws; getline(cin, ten);
		cout << "Nhap gia tien: "; cin >> gia;
		cout << "Nhap so luong: "; cin >> sl;
	}
	void Xuat(){
		cout << endl;
		cout << "Ma hang: " << ma << endl;
		cout << "Ten hang " << ten << endl;
		cout << "Gia tien: " << gia << endl;
		cout << "So luong: " << sl << endl;
	}
	
	friend istream& operator >> (istream& is, SanPham& sp){
		sp.Nhap();
		return is;
	}
	friend ostream& operator << (ostream& os, SanPham& sp){
		sp.Xuat();
		return os;
	}
	void xuatfile(ofstream& file){
		file << ma << "\t" << ten << "\t" << gia << "\t" << sl << endl;
	}
};

class MTT{
private:
	int n;
	/*
	Tao ra 2 mang dong:
	- 1 mang xu ly san pham trong cua hang: sp
	- 1 mang xu ly san pham trong gio hang: gh
	*/
	vector<SanPham> sp;
	vector<SanPham> gh;
public:
	void Nhap(){
		cout << "Nhap so luong hang: "; cin >> n;
		sp.resize(n);
		for(int i = 0; i < n; i++) sp[i].Nhap();
	}
	void Xuat(){
		for(int i = 0; i < sp.size(); i++) sp[i].Xuat();
		system("pause");
	}
	void Them(){
		int a, b;
		SanPham p;
		cout << "Nhap ma hang muon them: "; cin >> a;
		cout << "Nhap so luong muon them: "; cin >> b;
		for(int i = 0; i < sp.size(); i++){
			if(sp[i].ma == a){
				if(sp[i].sl < b){
					cout << "Hang khong con hoac khong du!" << endl;
					return;
				} else {
					/*
					O day neu ta dung p.Nhap(), thi no se khong xuat ra
					so san pham bi cho vao gio hang, the nen ta phai
					gan tung bien nhu the nay.
					*/
					p.ma = sp[i].ma;
					p.ten = sp[i].ten;
					p.gia = sp[i].gia;
					p.sl = b;
					sp[i].sl -= b;
					gh.push_back(p);
					cout << "Them vao thanh cong!" << endl;
				}
			}
		}
		Xuat(); //Nay muon ghi cung duoc, khong can thiet
	}
	void Tinh(){
		//Neu khong cho bien =0, ket qua chay khong dung.
		int sumsl = 0, sumgia = 0;
		for(int i = 0; i < gh.size(); i++){
			sumsl += gh[i].sl; 
			sumgia += gh[i].sl * gh[i].gia;
		}
		cout << "Tong so luong hang: " << sumsl << endl;
		cout << "Tong tien hang: " << sumgia << endl;
		system("pause");
	}
	void Chen(){
	/*
	Vi chen them 1 san pham vao, the nen so luong san pham (n)
	phai +1;
	*/
	n += 1;
	SanPham p; p.Nhap();
	/*
	Muon hieu ro push_back la gi thi len chat gpt hoi.
	O day t hieu theo kieu, no se chen thong tin vao vi tri cuoi
	cung cua mang.
	*/
	sp.push_back(p);
	cout << "Them san pham vao cua hang thanh cong!" << endl;
	system("pause");
	}
	
	void xuatds(){
		ofstream file;
		file.open("C:\\Users\\HP\\Desktop\\danhsach.txt");
		if(file.is_open()){
			for(int i = 0; i < sp.size(); i++){
				sp[i].xuatfile(file);
			}
			file.close();
			cout << "Ghi thanh cong!" << endl;
		} else cout << "Khong thay file!" << endl;
		system("pause");
	}
	
	void inmenu(){
		char op;
		do{
			system("cls");
			cout << "==============MENU============" << endl;
			cout << "1. Nhap du lieu hang hoa" << endl;
			cout << "2. Them san pham vao gio hang" << endl;
			cout << "3. Tinh so luong hang va tien thanh toan trong gia hang" << endl;
			cout << "4. Chen san pham moi vao cua hang" << endl;
			cout << "5. Xem danh sach hang ton" << endl;
			cout << "6. Ghi danh sach hang ton" << endl;
			cout << "0. Thoat!!!" << endl;
			cout << "------------------------------" << endl;
			cout << "Moi nhap yeu cau: ";
			cin >> op;
			switch(op){
				case'1': Nhap(); break;
				case'2': Them(); break;
				case'3': Tinh(); break;
				case'4': Chen(); break;
				case'5': Xuat(); break;
				case'6': xuatds(); break;
			}
		}while(op != '0');
	}
};

int main(){
	MTT a;
	a.inmenu();
	return 0;
}
