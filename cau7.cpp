#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Nguoi{
private:
	string Hoten, Quequan;
	int ngay, thang, nam;
public:
	Nguoi(string Hoten = "", int ngay = 0, int thang = 0, int nam = 0, string Quequan = "")
	: Hoten(Hoten),ngay(ngay),thang(thang),nam(nam),Quequan(Quequan){}
	void Nhap(){
		
		cout << "Nhap ho ten: "; cin>>ws; getline(cin, Hoten);
		cout << "Nhap ngay sinh: "; cin >> ngay;
		cout << "Nhap thang sinh: "; cin >> thang;
		cout << "Nhap nam sinh: "; cin >> nam;
		cout << "Nhap que quan: "; cin>>ws; getline(cin, Quequan);
	}
	void Xuat(){
		cout << "Ho ten: " << Hoten << endl;
		cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
		cout << "Que quan: " << Quequan << endl;
	}
	string getHoten(){
		return this->Hoten;
	}
	string getQuequan(){
		return this->Quequan;
	}
	int getnam(){
		return this->nam;
	}
};

class HSHocSinh: public Nguoi{
private:
	int kyhoc;
	string lop, khoahoc;
public:
	HSHocSinh(string lop = "", string khoahoc = "", int kyhoc = 0)
	: lop(lop), khoahoc(khoahoc), kyhoc(kyhoc){}
	void Nhap(){
		cout << endl;
        Nguoi::Nhap(); 
        cout << "Nhap lop: "; cin >> ws; getline(cin, lop);
        cout << "Nhap khoa hoc: "; cin >> ws; getline(cin, khoahoc);
        cout << "Nhap ky hoc: "; cin >> kyhoc;
	}
	void Xuat(){
		cout << endl;
		Nguoi::Xuat();
		cout << "Lop: " << lop << endl;
		cout << "Khoa hoc: " << khoahoc << endl;
		cout << "Ky hoc: " << kyhoc << endl;
	}
	string getlop(){
		return this->lop;
	}
};

class menu{
private:
	vector <HSHocSinh> hs;
	int n;
public:
	void Nhap(){
		cout << endl;
		cout << "Nhap so luong hoc sinh: "; cin >> n;
		hs.resize(n);
		for(int i = 0; i < n; i++) hs[i].Nhap();
	}
	void Xuatnamquequan(){
		sapxeptheonamsinh();
		int NhapNam;
		string NhapQuequan;
		cout << "Nhap nam sinh muon xuat: "; cin >> NhapNam;
		cout << "Nhap que quan muon xuat: "; cin.ignore(); getline(cin, NhapQuequan);
		for(int i = 0; i < hs.size(); i++){
			if(NhapNam == hs[i].getnam() && NhapQuequan == hs[i].getQuequan()){
				hs[i].Xuat();
			}
		}
		system("pause");
	}
	void Xuathslop(){
		string Nhaplop;
		cout << "Nhap lop muon xuat: "; cin >> ws; getline(cin, Nhaplop);
		sapxeptheonamsinh();
		for(int i = 0; i < hs.size(); i++){
			if(Nhaplop == hs[i].getlop()){
				hs[i].Xuat();
			}
		}
		system("pause");
	}
	void sapxeptheonamsinh(){
		int i, j;
		for (i = 0; i < hs.size() - 1; i++){
			for(j = i + 1; j < hs.size(); j++){
				if(hs[i].getnam() > hs[j].getnam()){
					swap(hs[i], hs[j]);
				}
			}
		}
	}
	void inmenu(){
		char op;
		do{
			system("cls");
			cout << "================Menu==================" << endl;
			cout << "1. Nhap danh sach hoc sinh" << endl;
			cout << "2. Xuat danh sach theo nam sinh va que quan" << endl;
			cout << "3. Xuat danh sach theo lop" << endl;
			cout << "======================================" << endl;
			cout << "Nhap lua chon: ";
			cin >> op;
			switch(op){
				case '1': Nhap(); break;
				case '2': Xuatnamquequan(); break;
				case '3': Xuathslop(); break;
			}
		}while(op != '0');
	}
};

int main(){
	menu a;
	a.inmenu();
	return 0;
}
