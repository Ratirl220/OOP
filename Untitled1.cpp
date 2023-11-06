#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Nguoi{
	private:
		string hoten,ngaysinh,quequan;
		int ma;
	public:
		Nguoi(string hoten="",string ngaysinh="",string quequan="")
		: hoten(hoten),ngaysinh(ngaysinh),quequan(quequan){}
	void nhap(){
		cout<<"nhap ma: ";cin>>ma;
		cout<<"nhap ho ten: ";cin>>ws;getline(cin,hoten);
		cout<<"nhap ngay sinh: ";cin>>ws;getline(cin,ngaysinh);
		cout<<"nhap que quan: ";cin>>ws;getline(cin,quequan);
	}
	void xuat(){
		cout<<"ma: "<<ma<<endl;
		cout<<"ho ten: "<<hoten<<endl;
		cout<<"ngay sinh: "<<ngaysinh<<endl;
		cout<<"que quan: "<<quequan<<endl;
	}
	friend istream& operator >>(istream& is,Nguoi& sv){
		sv.nhap();
		return is;
	}
	friend ostream& operator <<(ostream& os,Nguoi& sv){
		sv.xuat();
		return os;
	}
	int getma(){
		return ma;
	}

};
class cbgv:public Nguoi{
	private:
		int luongcung,thuong,phat,ltl;
	public:
		void nhap(){
			Nguoi::nhap();
			cout<<"nhap luong cung: ";cin>>luongcung;
			cout<<"nhap luong thuong: ";cin>>thuong;
			cout<<"nhap phat tien an vat: ";cin>>phat;
			ltl=tinhluong();
		
		}
		void xuat(){
			Nguoi::xuat();
			cout<<"luong cung: "<<luongcung<<endl;
			cout<<"luong thuong: "<<thuong<<endl;
			cout<<"phat tien an vat: "<<phat<<endl;
			cout<<"luong thuc linh: "<<ltl<<endl;
		}
		int tinhluong(){
			ltl=luongcung+thuong-phat;
			return ltl;
		}
};
class menu{
	private:
	vector<cbgv>ds;
	int n;
	public:
		void nhap(){
			cout<<"nhap so luong nv: ";cin>>n;
			ds.resize(n);
			for(int i=0;i<n;i++)ds[i].nhap();
		}
		void xuat(){
			for(int i=0;i<ds.size();i++)
			ds[i].xuat();
		}
		void sapxep(){
			for(int i=0;i<ds.size()-1;i++){
				for(int j=i+1;j<ds.size();j++){
					if(ds[j].getma()>ds[i].getma()){
						swap(ds[j],ds[i]);
					}
					
				}
			}
			xuat();
		}
		void inmenu(){
			char op;
			do{
				system("cls");
				cout<<"1.Nhap danh sach"<<endl;
				cout<<"2.Xuat danh sach"<<endl;
				cout<<"3.Sap xep danh sach"<<endl;
				
				cin>>op;
				switch(op){
					case('1'):nhap();break;
					case('2'):xuat();
					system("pause");break;
					case('3'):sapxep();
					system("pause");break;
					
				}
			}while(op!='0');
		}	
	
};
int main(){
	menu a;
	a.inmenu();
	return 0;
}
