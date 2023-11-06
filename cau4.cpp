#include <iostream>
#include <string>
#include <vector>

using namespace std;
class docgia{
	protected:
		string hoten,ngay;
		int sothang,gia;
	public:
	docgia(string hoten="",string ngay="",int sothang=0){
		this->hoten=hoten;
		this->ngay=ngay;
		this->sothang=sothang;
	}
	virtual void nhap(){
		cout<<endl;
		cout<<"nhap ho ten :";cin>>ws;getline(cin,hoten);
		cout<<"nhap ngay lap the :";cin>>ws;getline(cin,ngay);
		cout<<"nhap so thang hieu luc cua the :";cin>>sothang;
	}	
	virtual void xuat(){
		cout<<endl;
		cout<<"ho & ten: "<<hoten<<endl;
		cout<<"ngay lap the: "<<ngay<<endl;
		cout<<"so thang co hieu luc cua the: "<<sothang<<endl;
	}
	friend istream& operator >>(istream& is,docgia& dg){
		dg.nhap();
		return is;
	}
	friend ostream& operator <<(ostream& os,docgia& dg){
		dg.xuat();
		return os;
	}
	virtual void tinhtien()=0;
	int getgia(){
		return gia;
	}
	int getsothang(){
		return sothang;
	}
};
class tre:public docgia{
	private:
		string tenbaby;
	public:
		void nhap(){
			docgia::nhap();
			cout<<"nhap ten thag dai dien: ";cin>>ws;getline(cin,tenbaby);
		}
		void xuat(){
			docgia::xuat();
			cout<<"tien lam the:"<<gia<<endl;
			cout<<" ten thag dai dien:"<<tenbaby<<endl;
		}
		void tinhtien(){
			gia=sothang*5000;
		}
};
class lon:public docgia{
	private:
		string tengia;
	public:
		void nhap(){
			docgia::nhap();
			cout<<"nhap so cccd: ";cin>>ws;getline(cin,tengia);
		}
		void xuat(){
			docgia::xuat();
			cout<<"tien lam the:"<<gia<<endl;
			cout<<" so cccd: "<<tengia<<endl;
			
		}
		void tinhtien(){
			gia=sothang*10000;
		}
};

class menu{
	private:
		vector<docgia *>tv;
		int n;
	public:
		void nhap(){
			cout<<"nhap so luong: ";cin>>n;
			for(int i=0;i<n;i++){
			int loai;
			cout<<"the cho lon or tre :"<<endl;
			cout<<"1.tre em, 2. ng` lon: ";cin>>loai;
			docgia *p;
			if(loai==1){
				p=new tre();
			}
			else{
				p=new lon();
			}
			p->nhap();
			tv.push_back(p);
			}	
			
		}
		void xuat(){
			for(int i=0;i<tv.size();i++){
				tv[i]->tinhtien();
				tv[i]->xuat();
			}
		}
		void sapxeptheotien(){
			for(int i=0;i<tv.size()-1;i++){
				for(int j=i+1;j<tv.size();j++){
					if(tv[i]->getgia()>tv[j]->getgia()){
						swap(tv[i],tv[j]);
					}
					
				}
			}
		}
		void sapxeptheothang(){
			for(int i=0;i<tv.size()-1;i++){
				for(int j=i+1;j<tv.size();j++){
					if(tv[i]->getsothang()>tv[j]->getsothang()){
						swap(tv[i],tv[j]);
					}
				}
			}
		}
		void imenu(){
			char op;
			do{
				system("cls");
				cout<<"1.Nhap danh sach doc gia:"<<endl;
				cout<<"2.Xuat danh sach doc gia:"<<endl;
				cout<<"3.Sap xep theo tien:"<<endl;
				cout<<"4.Sap xep theo thang:"<<endl;
				cin>>op;
				switch(op){
					case('1'):nhap();break;
					case('2'):xuat();
					system("pause");break;
					case('3'):sapxeptheotien();break;
					case('4'):sapxeptheothang();break;
					
				}
			}while(op!='0');
		}
	
};
int main(){
	menu n;
	n.imenu();
	return 0;
}
