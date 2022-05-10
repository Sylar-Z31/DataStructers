#include<iostream>
#include<ctime>
#include<string>
#include<cstring>
#include<chrono>

using namespace std;
using namespace std::chrono;


void BubbleSwap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void SelectionSwap(int* arr, unsigned int min, unsigned int i)
{
	int temp = arr[i];
	arr[i] = arr[min];
	arr[min] = temp;
}

void BubbleSortV_1(int* arr, unsigned int size)
{
	unsigned int i, j;  // for degiskenlerimiz
	int temp{ 0 }; // yer degistirme degiskenimizi 0 dan baslatt�k

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++) // iceride son elemani +1 olarak kontrol ediyoruz -1 kadar d�n�cek
		{
			if (arr[j] > arr[j + 1]) // swap islemi
			{
				/*int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;*/

				BubbleSwap(arr, j + 1, j); // �ok kulland�g�m�z icin fonka cevirmek daha iyi
			}
		}
	}
}

void BubbleSortV_2(int* arr, unsigned int size)
{
	unsigned int i{ 0 }, j, devam{ 1 }; // devam isimli flag kullanarak buublesortun daha performansl� olmas�n� saglad�k
	int temp{ 0 };

	while ((i < size) && (devam)) // size kadar ve ilk d�ng�de degisiklik yoksa devam 0 olacag�ndan dolay� s�ralanm�s bir dizide performans saglam�s olacak
	{
		devam = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1]) // swap islemi
			{
				/*temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;*/

				BubbleSwap(arr, j + 1, j); // �ok kulland�g�m�z icin fonka cevirmek daha iyi

				devam = 1; // eger herhangi bir degisiklik olursa d�ng� devam etmeli
			}
		}
		i++;
	}
}

void SelectionSort(int* arr, unsigned int size)
{
	unsigned int i, j, min;

	for (i = 0; i < size - 1; i++) // size-1 ad�mda s�ralanm�� olur her eleman kendisinden sonraki t�m elemanlarla k�yaslan�r
	{
		min = i; // her ad�mda k�yaslanacak eleman�n indisi
		for (j = i + 1; j < size; j++) // elemandan sonraki t�m elemanlarla k�yaslicak
		{
			if (arr[j] < arr[min]) { min = j; } // s�radaki eleman eger eleman�m�zdan k�c�kse, k�c�k olan eleman�n indisini mine atad�k
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		//SelectionSwap(arr, min, i); // swap islemi
	}
}

void InsertionSort(int* arr, unsigned int size)
{
	unsigned int i, j;
	int b; // ge�ilen diziyle k�yaslanacak eleman

	for (i = 1; i < size; i++) // ilk eleman kendi icinde s�ral� kabul edildigi icin 2. elemandan baslad�k
	{
		b = arr[i]; // gecilen diziyle k�yaslanacak eleman
		j = i; // gecilen diziyi k�yaslamak icin 
		while ((j > 0) && arr[j - 1] > b) // negatif indise inmesin ve k�yaslanacak eleman gecilen diziye uygun yere yerlestirilir
		{
			arr[j] = arr[j - 1]; // eleman� gecilen dizideki uygun yere yerlestirdi
			j--; // gecilen dizidek kontrole devam icin j indisini 1 azaltt�k
		}
		arr[j] = b; // buyuk olan eleman� saga dogru kayd�rd�k
	}
}

void MyCountingSort(int* arr, unsigned int size)
{
	unsigned int i, j, k = 0, count = 0; // k elemanlar�m�z olacak count ise hangi elemandan ka� tane oldugunu anlamam�z icin yard�mc� degisken olacak
	int max = arr[0]; // yard�mc� dizinin boyutunu belirlemek icin dizideki en b�y�k eleman� bulma yolunda ilk eleman� en buyuk kabul ettik

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max) { max = arr[i]; } // en buyuk eleman� bulduk
	}

	int* arrB = new int[max + 1]{}; // en buyuk eleman�n +1 fazlas� boyutunda 0 lardan olusan dinamik bir dizi olusturduk

	for (j = 0; j < size; j++) { arrB[arr[j]]++; } // yard�mc� diziye hangi elemandan ka� tane oldugunu s�yledik

	k = max; // yard�mc� dizinin -1 uzunlugu
	while (k >= 0) // k+1 kadar d�n
	{
		if (count >= arrB[k]) { if (k == 0) { break; } k--; continue; } // k == 0'sa bitir, hangi elemandan ka� tane varsa onlar� s�ralamam�z� sagl�yor

		arr[size - 1] = k; // ger�ek dizimize tersten s�ralanm�s halini atiyoruz
		size--; // ger�ek dizide tersten basa gidiyoruz
		arrB[k]--; // yard�mc� dizide ka� tane eleman kald�g�n� anlamam�z icin 1'er azaltiyoruz
	}
}

void MyCountingSort2(int* arr, unsigned int size)
{
	unsigned int i, j, k = 0, count = 0; // k elemanlar�m�z olacak count ise hangi elemandan ka� tane oldugunu anlamam�z icin yard�mc� degisken olacak
	int max = arr[0], min = arr[0]; // dizideki en buyuk ve en kucuk elemanlar� 0. indisteki eleman kabul ettik

	for (i = 1; i < size; i++) 
	{
		if (arr[i] > max) { max = arr[i]; } // en b�y�k eleman� bulduk
		if (arr[i] < min) { min = arr[i]; } // en k�c�k eleman� bulduk
	}
	
	int* arrB = new int[max - min + 1]{}; // en b�y�k elemandan en k�c�k eleman� ��kart�p +1 eklenmi� boyutunda yard�mc� dizi olu�turduk

	for (j = 0; j < size; j++) { arrB[arr[j] - min]++; } // yard�mc� diziye hangi elemandan kac tane oldugunu s�yledik

	k = max - min; // yard�mc� dizinin -1 uzunlugu c�nk� indis 0 dan baslar
	while (k >= 0) // yard�mc� dizinin son indisinden basla 
	{
		if (count >= arrB[k]) { if (k == 0) { break; } k--; continue; } // k == 0 ise bitir, hangi elemandan ka� tane varsa onlar� s�ralamam�z� sagl�yor 

		arr[size - 1] = k + min; // ger�ek diziye ba�tan sona do�ru en son indise en b�y�k eleman gelecek �ekilde yard�mc� "dizinin indis + minimum de�eri" = elemanlar 
		size--; // ger�ek dizide sondan ba�a gidiyoruz
		arrB[k]--; // yard�mc� dizide ka� tane eleman kald�g�n� anlamam�z icin gerekli indislerdeki elemanlar� 1'er azalt�yoruz
	}
}

void DivideConquer(int* arr, int ls, int mid, int rs)
{
	int i, ass, usb, g;
	ass = mid; usb = mid + 1;

	while ((ls <= ass) && usb <= rs)
	{
		if (arr[ls] < arr[usb]) { ls++; }
		else
		{
			g = arr[usb];
			for (i = usb - 1; i >= ls; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[ls] = g;
			ls++; ass++; usb++;
		}
	}
}

void DivideMarge(int* arr, int l, int r)
{
	int mid, ls, rs;
	if (l < r)
	{
		ls = l; rs = r;
		mid = (ls + rs) / 2;
		DivideMarge(arr, ls, mid);
		DivideMarge(arr, mid + 1, rs);
		DivideConquer(arr, ls, mid, rs);
	}
}

int LuckySort()
{
	return 1;
}

void SetArray(int* arr, int* arr2, int* arr3, int* arr4, int* arr5, int* arr6, int* arr7, unsigned int size)
{
	srand(time(0)); // random say�lar �ok s�k olmas�n

	for (unsigned int i = 0; i < size; i++) // her algoritmaya g�nderilecek dizilere ayn� random de�erler atan�yor
	{
		arr[i] = rand() % 3000;
		arr2[i] = arr[i];
		arr3[i] = arr2[i];
		arr4[i] = arr3[i];
		arr5[i] = arr4[i];
		arr6[i] = arr5[i];
		arr7[i] = arr6[i];
	}
}

void GetArray(int* array, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	constexpr unsigned int size{ 10 }; // dizilere g�nderilecek veri say�s�

	int* arr = new int[size];
	int* arr2 = new int[size];
	int* arr3 = new int[size];
	int* arr4 = new int[size];
	int* arr5 = new int[size];
	int* arr6 = new int[size];
	int* arr7 = new int[size];

	SetArray(arr, arr2, arr3, arr4, arr5, arr6, arr7, size);

	GetArray(arr, size);
	//GetArray(arr2, size);
	//GetArray(arr3, size);
	//GetArray(arr4, size);
	//GetArray(arr5, size);
	//GetArray(arr6, size);
	//GetArray(arr7, size);
	

#pragma region BubbleSortV_1

	auto start = high_resolution_clock::now(); 
	BubbleSortV_1(arr, size);
	auto stop = high_resolution_clock::now();
	GetArray(arr, size);

	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "BUBBLE SORTV_1:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region BubbleSortV_2

	//GetArray(arr2, size);

	start = high_resolution_clock::now();
	BubbleSortV_2(arr2, size);
	stop = high_resolution_clock::now();
	//GetArray(arr2, size);

	duration = duration_cast<microseconds>(stop - start);
	//cout << "BUBBLE SORTV_2:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region SelectionSort

	//GetArray(arr3, size);

	start = high_resolution_clock::now();
	SelectionSort(arr3, size);
	stop = high_resolution_clock::now();
	//GetArray(arr3, size);

	duration = duration_cast<microseconds>(stop - start);
	//cout << "SELECTION SORT:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region InsertionSort


	//GetArray(arr4, size);

	start = high_resolution_clock::now();
	InsertionSort(arr4, size);
	stop = high_resolution_clock::now();
	//GetArray(arr4, size);

	duration = duration_cast<microseconds>(stop - start);
	//cout << "INSERTION SORT:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region MyCountingSort

	//GetArray(arr5, size);

	start = high_resolution_clock::now();
	MyCountingSort(arr5, size);
	stop = high_resolution_clock::now();
	//GetArray(arr5, size);

	duration = duration_cast<microseconds>(stop - start);
	//cout << "MYCOUNTING SORT:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region CountingSort

	//GetArray(arr7, size);

	start = high_resolution_clock::now();
	MyCountingSort2(arr7, size);
	stop = high_resolution_clock::now();
	//GetArray(arr7, size);

	duration = duration_cast<microseconds>(stop - start);
	//cout << "COUNTING SORT:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region DivideMarge

	//GetArray(arr6, size);

	start = high_resolution_clock::now();
	DivideMarge(arr6, 0, size - 1);
	stop = high_resolution_clock::now();
	//GetArray(arr6, size);

	duration = duration_cast<microseconds>(stop - start);
	//cout << "MARGE SORT:" << duration.count() << " microseconds" << endl;

#pragma endregion

#pragma region LuckySort

	start = high_resolution_clock::now();
	LuckySort();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);
	//cout << "LUCKY SORT:" << duration.count() << " microseconds" << endl;

#pragma endregion


	delete[]arr;
	delete[]arr2;
	delete[]arr3;
	delete[]arr4;
	delete[]arr5;
	delete[]arr6;
	delete[]arr7;

	return 0;
}