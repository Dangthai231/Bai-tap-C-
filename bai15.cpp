#include <bits/stdc++.h>
using namespace std;
struct khachhang{
	int makh;
	string tenkh,sdt;
	float tongtien;
};
void nhap(khachhang a[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nnhap khach hang thu "<<i+1<<endl;
		cout<<"\nnhap ma khach hang: ";
		cin>>a[i].makh;
		cin.ignore();
		cout<<"\nnhap ten khach hang: ";
		getline(cin,a[i].tenkh);
		cout<<"\nnhap sdt: ";
		getline(cin,a[i].sdt);
		cout<<"\nnhap tong tien: ";
		cin>>a[i].tongtien;
		cin.ignore();
	}
}
void xuat(khachhang a[],int n){
	cout<<left<<setw(20)<<"ma khach hang"
		<<setw(20)<<"ten khach hang"
		<<setw(20)<<"sdt"
		<<setw(20)<<"tong tien"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<left<<setw(20)<<a[i].makh
			<<setw(20)<<a[i].tenkh
			<<setw(20)<<a[i].sdt
			<<setw(20)<<a[i].tongtien<<endl;
	}
}
void in1kh(khachhang kh){
	cout<<left<<setw(20)<<"ma khach hang"
		<<setw(20)<<"ten khach hang"
		<<setw(20)<<"sdt"
		<<setw(20)<<"tong tien"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<left<<setw(20)<<kh.makh
			<<setw(20)<<kh.tenkh
			<<setw(20)<<kh.sdt
			<<setw(20)<<kh.tongtien<<endl;
}
void inserttionSort(khachhang a[],int n){
	for(int i=1;i<n;i++){
		khachhang key=a[i];
		int j=i-1;
		while(j>=0 && a[j].tongtien > key.tongtien){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}
void binarySearch(khachhang a[],int n,float x){
	int left=0;
	int right=n-1;
	int index=-1;
	while(left<=right){
		int mid=left+ (right -left)/2;
		if(a[mid].tongtien==x){
			index=mid;
			break;
		}
		if(a[mid].tongtien<x){
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	if(index!=-1){
		cout<<"\nda tim thay khach hang co tong tien "<<x<<endl;
		int i=index;
		while(i>=0 && a[i].tongtien==x){
			in1kh(a[i]);
			i--;
		}
		i=index+1;
		while(i<n && a[i].tongtien==x){
			in1kh(a[i]);
			i++;
		}
	}else{
		cout<<"\nko co khach hang co tong tien la "<<x<<endl;
	}
}
int main(){
	int n;
	do{
		cout<<"\nnhap so khach hang: ";
		cin>>n;
		cin.ignore();
	}while(n<0);
	khachhang* ds=new khachhang[n];
	cout<<"\nCAU 1"<<endl;
	nhap(ds,n);
	cout<<"\nCAU 2"<<endl;
	xuat(ds,n);
	cout<<"\nCAU 3"<<endl;
	inserttionSort(ds,n);
	xuat(ds,n);
	cout<<"\nCAU 4"<<endl;
	float x;
	do{
		cout<<"\nnhap tien can tim: ";
		cin>>x;
		cin.ignore();
	}while(x<0);
	binarySearch(ds,n,x);
}
//4
//101
//thai
//03980
//10000
//102
//khanh
//0342534
//8000
//103
//duong
//036786
//9000
//104
//hien
//0456456
//6500
