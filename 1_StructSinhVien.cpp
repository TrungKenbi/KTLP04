#include<bits/stdc++.h>
using namespace std;


struct SinhVien {
	string maSV;
	string hoTen;
	float diemCoSo = 0;
	float diemChuyenNganh = 0;
};

void nhapDS(int &n, SinhVien list[]) {
	cout << "Moi nhap so luong sinh vien: ";
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		printf("---- Moi nhap sinh vien %d: ----\n", i + 1);
		cout << "MaSV: ";
		cin >> list[i].maSV;
		cout << "Ho Va Ten: ";
		cin.ignore();
		getline(cin, list[i].hoTen);
		cout << "Diem Co So: ";
		cin >> list[i].diemCoSo;
		cout << "Diem Chuyen Nganh: ";
		cin >> list[i].diemChuyenNganh;
	}
}

void xuatDS(int n, SinhVien list[]) {
	cout << "========================" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << list[i].maSV << " ";
		cout << list[i].hoTen << " ";
		cout << list[i].diemCoSo << " ";
		cout << list[i].diemChuyenNganh << endl;
		cout << "========================" << endl;
	}
}

void xuatDSDau(int n, SinhVien list[]) {
	cout << "Danh sach sinh vien thi dau la: " << endl;
	int numDau = 0;
	
	for(int i = 0; i < n; i++)
	{
		if (list[i].diemCoSo >= 5 && list[i].diemChuyenNganh >= 5) {
			cout << list[i].maSV << " ";
			cout << list[i].hoTen << " ";
			cout << list[i].diemCoSo << " ";
			cout << list[i].diemChuyenNganh << endl;
			cout << "========================" << endl;
			numDau++;
		}
	}
	cout << "So luong sinh vien thi dau la: " << numDau;
	
}

void xuatDSRot(int n, SinhVien list[]) {
	cout << "Danh sach sinh vien thi rot la: " << endl;
	for(int i = 0; i < n; i++)
	{
		if (list[i].diemCoSo < 5 || list[i].diemChuyenNganh < 5) {
			cout << list[i].maSV << " ";
			cout << list[i].hoTen << " ";
			cout << list[i].diemCoSo << " ";
			cout << list[i].diemChuyenNganh << endl;
			cout << "========================" << endl;
		}
	}
}

int main()
{
	SinhVien list[100];
	int n;
	nhapDS(n, list);
	xuatDS(n, list);
	xuatDSDau(n, list);
	xuatDSRot(n, list);
	return 0;
}
