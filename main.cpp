#include "graph.h"
int main()
{
	FILE *fin, *fout;
	int v, e;
	fin=fopen("input.txt", "r");
	fout=fopen("output.txt", "w");
	if(fin==NULL || fout==NULL)
	{
		printf("Loi mo file!");
	}

	cout << "Nhap so dinh"; cin >> v;
	cout << "Nhap so canh"; cin >> e;
	Graph graph(v, e);

	MENU();
	
	int focus, focus1;
	cout << "Nhap lua chon";
	cin >> focus;
	switch (focus)
	{
	case 1:
		cin >> focus1;
		MENUnhap();
		switch(focus1)
		{
			case 1:
				graph.docMaTranKe(fin);
				break;
			case 2:
				graph.docDsKe(fin);
				break;
			case 3: 
				graph.docDsCanh(fin);
				break;
		}
		break;
	case 2:
		cin >> focus1;
		MENUnhap();
		switch(focus1)
		{
			case 1:
				graph.inMaTranKe(fout);
				break;
			case 2:
				graph.inDsKe(fout);
				break;
			case 3: 
				graph.inDsCanh(fout);
				break;
			case 4:
				graph.tinhBacCuaDinh();
				graph.inBacCuaDinh(fout);
		}
		break;
	default:
		break;
	}
}
