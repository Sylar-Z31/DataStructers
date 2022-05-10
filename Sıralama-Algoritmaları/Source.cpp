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
	int temp{ 0 }; // yer degistirme degiskenimizi 0 dan baslattýk

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++) // iceride son elemani +1 olarak kontrol ediyoruz -1 kadar dönücek
		{
			if (arr[j] > arr[j + 1]) // swap islemi
			{
				/*int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;*/

				BubbleSwap(arr, j + 1, j); // çok kullandýgýmýz icin fonka cevirmek daha iyi
			}
		}
	}
}

void BubbleSortV_2(int* arr, unsigned int size)
{
	unsigned int i{ 0 }, j, devam{ 1 }; // devam isimli flag kullanarak buublesortun daha performanslý olmasýný sagladýk
	int temp{ 0 };

	while ((i < size) && (devam)) // size kadar ve ilk döngüde degisiklik yoksa devam 0 olacagýndan dolayý sýralanmýs bir dizide performans saglamýs olacak
	{
		devam = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1]) // swap islemi
			{
				/*temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;*/

				BubbleSwap(arr, j + 1, j); // çok kullandýgýmýz icin fonka cevirmek daha iyi

				devam = 1; // eger herhangi bir degisiklik olursa döngü devam etmeli
			}
		}
		i++;
	}
}

void SelectionSort(int* arr, unsigned int size)
{
	unsigned int i, j, min;

	for (i = 0; i < size - 1; i++) // size-1 adýmda sýralanmýþ olur her eleman kendisinden sonraki tüm elemanlarla kýyaslanýr
	{
		min = i; // her adýmda kýyaslanacak elemanýn indisi
		for (j = i + 1; j < size; j++) // elemandan sonraki tüm elemanlarla kýyaslicak
		{
			if (arr[j] < arr[min]) { min = j; } // sýradaki eleman eger elemanýmýzdan kücükse, kücük olan elemanýn indisini mine atadýk
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
	int b; // geçilen diziyle kýyaslanacak eleman

	for (i = 1; i < size; i++) // ilk eleman kendi icinde sýralý kabul edildigi icin 2. elemandan basladýk
	{
		b = arr[i]; // gecilen diziyle kýyaslanacak eleman
		j = i; // gecilen diziyi kýyaslamak icin 
		while ((j > 0) && arr[j - 1] > b) // negatif indise inmesin ve kýyaslanacak eleman gecilen diziye uygun yere yerlestirilir
		{
			arr[j] = arr[j - 1]; // elemaný gecilen dizideki uygun yere yerlestirdi
			j--; // gecilen dizidek kontrole devam icin j indisini 1 azalttýk
		}
		arr[j] = b; // buyuk olan elemaný saga dogru kaydýrdýk
	}
}

void MyCountingSort(int* arr, unsigned int size)
{
	unsigned int i, j, k = 0, count = 0; // k elemanlarýmýz olacak count ise hangi elemandan kaç tane oldugunu anlamamýz icin yardýmcý degisken olacak
	int max = arr[0]; // yardýmcý dizinin boyutunu belirlemek icin dizideki en büyük elemaný bulma yolunda ilk elemaný en buyuk kabul ettik

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max) { max = arr[i]; } // en buyuk elemaný bulduk
	}

	int* arrB = new int[max + 1]{}; // en buyuk elemanýn +1 fazlasý boyutunda 0 lardan olusan dinamik bir dizi olusturduk

	for (j = 0; j < size; j++) { arrB[arr[j]]++; } // yardýmcý diziye hangi elemandan kaç tane oldugunu söyledik

	k = max; // yardýmcý dizinin -1 uzunlugu
	while (k >= 0) // k+1 kadar dön
	{
		if (count >= arrB[k]) { if (k == 0) { break; } k--; continue; } // k == 0'sa bitir, hangi elemandan kaç tane varsa onlarý sýralamamýzý saglýyor

		arr[size - 1] = k; // gerçek dizimize tersten sýralanmýs halini atiyoruz
		size--; // gerçek dizide tersten basa gidiyoruz
		arrB[k]--; // yardýmcý dizide kaç tane eleman kaldýgýný anlamamýz icin 1'er azaltiyoruz
	}
}

void MyCountingSort2(int* arr, unsigned int size)
{
	unsigned int i, j, k = 0, count = 0; // k elemanlarýmýz olacak count ise hangi elemandan kaç tane oldugunu anlamamýz icin yardýmcý degisken olacak
	int max = arr[0], min = arr[0]; // dizideki en buyuk ve en kucuk elemanlarý 0. indisteki eleman kabul ettik

	for (i = 1; i < size; i++) 
	{
		if (arr[i] > max) { max = arr[i]; } // en büyük elemaný bulduk
		if (arr[i] < min) { min = arr[i]; } // en kücük elemaný bulduk
	}
	
	int* arrB = new int[max - min + 1]{}; // en büyük elemandan en kücük elemaný çýkartýp +1 eklenmiþ boyutunda yardýmcý dizi oluþturduk

	for (j = 0; j < size; j++) { arrB[arr[j] - min]++; } // yardýmcý diziye hangi elemandan kac tane oldugunu söyledik

	k = max - min; // yardýmcý dizinin -1 uzunlugu cünkü indis 0 dan baslar
	while (k >= 0) // yardýmcý dizinin son indisinden basla 
	{
		if (count >= arrB[k]) { if (k == 0) { break; } k--; continue; } // k == 0 ise bitir, hangi elemandan kaç tane varsa onlarý sýralamamýzý saglýyor 

		arr[size - 1] = k + min; // gerçek diziye baþtan sona doðru en son indise en büyük eleman gelecek þekilde yardýmcý "dizinin indis + minimum deðeri" = elemanlar 
		size--; // gerçek dizide sondan baþa gidiyoruz
		arrB[k]--; // yardýmcý dizide kaç tane eleman kaldýgýný anlamamýz icin gerekli indislerdeki elemanlarý 1'er azaltýyoruz
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
	srand(time(0)); // random sayýlar çok sýk olmasýn

	for (unsigned int i = 0; i < size; i++) // her algoritmaya gönderilecek dizilere ayný random deðerler atanýyor
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
	constexpr unsigned int size{ 10 }; // dizilere gönderilecek veri sayýsý

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