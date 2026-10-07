#include <bits/stdc++.h>
using namespace std;
struct date{
	int ngay,thang,nam;
};
struct nhanvien{
	int manv;
	string hoten;
	date ngaysinh;
	float luong;
};
void nhap(nhanvien a[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nnhap nhan vien thu "<<i+1<<endl;
		cout<<"\nnhap ma nhan vien: ";
		cin>>a[i].manv;
		cin.ignore();
		cout<<"\nnhap ho ten: ";
		getline(cin,a[i].hoten);
		cout<<"\nnhap ngay sinh: ";
		cin>>a[i].ngaysinh.ngay>>a[i].ngaysinh.thang>>a[i].ngaysinh.nam;
		cin.ignore();
		cout<<"\nnhap luong: ";
		cin>>a[i].luong;
		cin.ignore();
	}
}
void xuat(nhanvien a[],int n){
	cout<<left<<setw(20)<<"ma nhan vien"
			<<setw(20)<<"ten nhan vien"
			<<setw(20)<<"ngay sinh"
			<<setw(20)<<"luong"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		string ngaysinh=to_string(a[i].ngaysinh.ngay)+"/"+to_string(a[i].ngaysinh.thang)+"/"+to_string(a[i].ngaysinh.nam);
		cout<<left<<setw(20)<<a[i].manv
			<<setw(20)<<a[i].hoten
			<<setw(20)<<ngaysinh
			<<setw(20)<<a[i].luong<<endl;
	}
}
void bubbleSort(nhanvien a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(a[i].luong >a[j].luong){
				nhanvien tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}
}
void in1nv(nhanvien nv){
	string ngaysinh=to_string(nv.ngaysinh.ngay)+"/"+to_string(nv.ngaysinh.thang)+"/"+to_string(nv.ngaysinh.nam);
		cout<<left<<setw(20)<<nv.manv
			<<setw(20)<<nv.hoten
			<<setw(20)<<ngaysinh
			<<setw(20)<<nv.luong<<endl;
}
void binarySearch(nhanvien a[],int n,float x){
	int left=0;
	int right=n-1;
	int index=-1;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid].luong==x){
			index=mid;
			break;
		}
		if(a[mid].luong<x){
			left=mid+1;
		}else{
			right=left-1;
		}
	}
	if(index!=-1){
		cout<<"\nda tim thay luong "<<x<<endl;
		int dem=0;
		int i=index;
		while(i>=0 && a[i].luong==x){
			if(dem==0){
				cout<<left<<setw(20)<<"ma nhan vien"
						<<setw(20)<<"ten nhan vien"
						<<setw(20)<<"ngay sinh"
						<<setw(20)<<"luong"<<endl;
				cout<<"--------------------------------------------------------------"<<endl;
			}
			in1nv(a[i]);
			dem++;
			i--;
		}
		i=index+1;
		while(i<n && a[i].luong==x){	
			in1nv(a[i]);
			dem++;
			i++;
		}
	}else{
		cout<<"\nko tim thay nhan vien co luong "<<x<<endl;
	}
}
int main(){
	int n;
	do{
		cout<<"\nnhap so nhan vien: ";
		cin>>n;
		cin.ignore();
	}while(n<0);
	nhanvien* ds=new nhanvien[n];
	cout<<"\nCAU 1"<<endl;
	nhap(ds,n);
	cout<<"\nCAU 2"<<endl;
	xuat(ds,n);
	cout<<"\nCAU 3"<<endl;
	bubbleSort(ds,n);
	xuat(ds,n);
	cout<<"\nCAU 4"<<endl;
	float x;
	do{
		cout<<"\nnhap luong can tim: ";
		cin>>x;
		cin.ignore();
	}while(x<0);
	binarySearch(ds,n,x);	
}
//4
//101
//thai
//23 10 2006
//10000
//102
//hien
//01 10 2006
//9000
//103
//nga
//03 10 2006
//11000
//104
//trang
//06 10 2006
//7000
