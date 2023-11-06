#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Nguoi{
private:
	string Hoten, Nghenghiep;
	int ngay, thang, nam;
public:
	//Cach viet contructor khac
	Nguoi(string Hoten = "", string Nghenghiep = "", int ngay = 0, int thang = 0, int nam = 0) :
		Hoten(Hoten), Nghenghiep(Nghenghiep), ngay(ngay), thang(thang), nam(nam) {}
	void Nhap(){
		cout << "Nhap ho ten: "; cin >> ws; getline(cin, Hoten);
		cout << "Nhap ngay sinh: "; cin >> ngay;
		cout << "Nhap thang sinh: "; cin >> thang;
		cout << "Nhap nam sinh: "; cin >> nam;
		cout << "Nhap nghe nghiep: "; cin >> ws; getline(cin, Nghenghiep);
	}
	void Xuat(){
		cout << "Ho ten: " << Hoten << endl;
		cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
		cout << "Nghe nghiep: " << Nghenghiep << endl;
	}
	friend istream& operator >> (istream& is, Nguoi& nguoi){
		nguoi.Nhap();
		return is;
	}
	friend ostream& operator << (ostream& os, Nguoi nguoi){
		nguoi.Xuat();
		return os;
	}
	int TinhTuoi(){
		return (2023 - nam);
	}
};

class KhuPho{
private:
	vector <Nguoi> dsNguoi;
	int SoNha,SoNguoi;
public:
	void Nhap(){
		int n;
		cout << "==============================================" << endl;
		cout << "Nhap so nha: "; cin >> SoNha;
		cout << "Nhap so thanh vien trong gia dinh: "; cin >> SoNguoi;
		dsNguoi.resize(SoNguoi);
		for(int i = 0; i < SoNguoi; i++){
			cout << "-----------------Nhap nguoi thu " << i + 1 << "-----------------" << endl;
			dsNguoi[i].Nhap();
		}
	}
	void Xuat(){
		cout << "\n==============================================" << endl;
		cout << "So nha: " << SoNha << endl;
		cout << "Ho co " << SoNguoi << " thanh vien, gom: " << endl;
		for(int i = 0; i < dsNguoi.size(); i++){
			cout << "-----------------Nguoi thu " << i + 1 << "-----------------" << endl;
			dsNguoi[i].Xuat();
		}
	}
	void Xuatmungtuoi(){
		for (int i = 0; i < dsNguoi.size(); i++){
			cout << "----------------Nguoi thu " << i + 1 << "------------------" <<endl;
			if (dsNguoi[i].TinhTuoi() >= 80){
				dsNguoi[i].Xuat();
			}
		}
	}

};

class menu{
private:
	vector <KhuPho> kp;
	int slHo;
public:
	void Nhap(){
		cout << "Nhap so ho dan: "; cin >> slHo;
		kp.resize(slHo);
		for(int i = 0; i < slHo; i++) {
			cout << endl;
			cout << "Nhap thong tin cua can ho thu " << i + 1 << endl;
			kp[i].Nhap();
		}
	}
	void Xuat(){
		for(int i = 0; i < kp.size(); i++) kp[i].Xuat();
		system("pause");
	}
	void Xuatmungtuoi(){
	    cout << "Danh sach cac ho dan co nguoi tren 80 tuoi:\n";
	    for (int i = 0; i < kp.size(); i++) {
	    	cout << endl;
	    	cout << "==============================================" << endl;
	    	kp[i].Xuatmungtuoi();
		}
	    system("pause");
	}

	void inmenu(){
		char op;
		do{
			system("cls");
			cout << "================Menu==================" << endl;
			cout << "1. Nhap" << endl;
			cout << "2. Xuat" << endl;
			cout << "3. Xuat mung tho tren 80 tuoi" << endl;
			cout << "======================================" << endl;
			cout << "Nhap lua chon: ";
			cin >> op;
			switch(op){
				case '1': Nhap(); break;
				case '2': Xuat(); break;
				case '3': Xuatmungtuoi(); break;
			}
		}while(op!='0');
	}
};

int main(){
	menu a;
	a.inmenu();
	return 0;
}
