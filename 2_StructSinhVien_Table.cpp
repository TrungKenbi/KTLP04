#include <bits/stdc++.h>
#include <strstream>
#include "TextTable.h"
using namespace std;

#define ALL 0
#define THILAI 1
#define GIOI 2
#define TOP 3
#define SORT 4


struct SinhVien {
	string hoTen;
	float diemTin = 0;
	float diemNgoaiNgu = 0;
	float diemTB = 0;
};

bool customSort (const SinhVien a, const SinhVien b);
string xuLySoLieu (float x);
string xepLoai (float diem);

void nhapDS(int &n, SinhVien list[]);
void xuatDS(int n, SinhVien list[], int type);

int main()
{
	SinhVien list[30];
	int n;
	nhapDS(n, list);
	xuatDS(n, list, ALL);
	xuatDS(n, list, THILAI);
	xuatDS(n, list, GIOI);
	xuatDS(n, list, TOP);
	xuatDS(n, list, SORT);
	return 0;
}

bool customSort (const SinhVien a, const SinhVien b)
{
	return a.diemTB > b.diemTB;
}

string xuLySoLieu (float x)
{
	ostrstream out;
	out << fixed << setprecision(2) << x;
	string text = out.str();
	return text;
}

string xepLoai (float diem) 
{
	if (diem >= 9)
		return "Xuat sac";
	else if (diem >= 8)
		return "Gioi";
	else if (diem >= 6.5)
		return "Kha";
	else if (diem >= 5)
		return "Trung Binh";
	else if (diem >= 4)
		return "Yeu";
	else return "Kem";
}

void nhapDS(int &n, SinhVien list[])
{
	cout << "Moi nhap so luong sinh vien: ";
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		printf("---- Moi nhap sinh vien %d: ----\n", i + 1);
		cout << "Ho Va Ten: ";
		cin.ignore();
		getline(cin, list[i].hoTen);
		cout << "Diem Tin: ";
		cin >> list[i].diemTin;
		cout << "Diem Ngoai Ngu: ";
		cin >> list[i].diemNgoaiNgu;
		list[i].diemTB = (list[i].diemTin + list[i].diemNgoaiNgu) / 2;
	}
}

void xuatDS(int n, SinhVien list[], int type)
{
	
	TextTable t('-', '|', '+');
	
	// Header Table
	t.add("#");
	t.add("Ho va Ten");
    t.add("Diem Tin");
    t.add("Diem Ngoai Ngu");
    t.add("Diem Trung Binh");
    switch(type) {
        case THILAI:
            t.add("Thi Lai Mon");
        default:
            t.add("Xep Loai");
    }
    t.endOfRow();
    
    int numRows = n;
    int limitBestStudent = 5;
    
    switch(type) {
        case TOP:
            sort(list, list + n, customSort);
            numRows = numRows > limitBestStudent ? 5 : numRows;
            break;
        case SORT:
            sort(list, list + n, customSort);
            break;
    }

	// Body Table
	for(int i = 0; i < numRows; i++)
	{
        switch(type) {
            case THILAI:
                if (list[i].diemTin < 5 || list[i].diemNgoaiNgu < 5)
                {
                    t.add(to_string(i + 1));
                    t.add(list[i].hoTen);
                    t.add(xuLySoLieu(list[i].diemTin));
                    t.add(xuLySoLieu(list[i].diemNgoaiNgu));
                    t.add(xuLySoLieu(list[i].diemTB));
                    t.add((list[i].diemTin < 5 ? "Tin Hoc" : "Ngoai Ngu"));
                    t.endOfRow();
                }
                break;
            case GIOI:
                if (list[i].diemTB >= 8 && list[i].diemTB < 9)
                {
                    t.add(to_string(i + 1));
                    t.add(list[i].hoTen);
                    t.add(xuLySoLieu(list[i].diemTin));
                    t.add(xuLySoLieu(list[i].diemNgoaiNgu));
                    t.add(xuLySoLieu(list[i].diemTB));
                    t.add(xepLoai(list[i].diemTB));
                    t.endOfRow();
                }
                break;
            default:
                t.add(to_string(i + 1));
                t.add(list[i].hoTen);
                t.add(xuLySoLieu(list[i].diemTin));
                t.add(xuLySoLieu(list[i].diemNgoaiNgu));
                t.add(xuLySoLieu(list[i].diemTB));
                t.add(xepLoai(list[i].diemTB));
                t.endOfRow();
        }
	}
	
	t.setAlignment(2, TextTable::Alignment::RIGHT );
	
    switch(type) {
        case THILAI:
            cout << "Danh sach Sinh Vien Thi Lai" << endl;
            break;
        case GIOI:
            cout << "Danh sach Sinh Vien Xep Loai Gioi" << endl;
            break;
        case TOP:
            cout << "Danh sach Sinh Vien Gioi Nhat Lop" << endl;
            break;
        case SORT:
            cout << "Danh sach Sinh Vien Giam Dan Theo Diem Trung Binh" << endl;
            break;
        default:
            cout << "Danh sach Sinh Vien" << endl;
    }
	
	
    cout << t;
    
    cout << endl << endl;
}
