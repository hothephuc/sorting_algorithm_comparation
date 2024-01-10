#include "DataGenerator.cpp"


void printArr (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//Selection Sort
void selectionSort_t(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = a[i];
		int minIndx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				min = a[j];
				minIndx = j;
				HoanVi(a[j], a[i]);
			}
		}
	}
}

void selectionSort(int a[], int n, unsigned long long& comp)
{
	for (int i = 0; ++comp, i < n; i++)
	{
		int min = a[i];
		int minIndx = i;
		for (int j = i + 1; ++comp, j < n; j++)
		{
			++comp;
			if (a[j] < a[i])
			{
				min = a[j];
				minIndx = j;
				HoanVi(a[j], a[i]);
			}
		}
	}
}

//Insertion Sort
void insertionSort(int a[], int n, unsigned long long& comp)
{
	for (int i = 1; ++comp, i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (++comp, j >= 0 && ++comp, a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void insertionSort_t(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 &&  a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}


//Quick Sort
int partition(int a[], int first, int last,unsigned long long &comp)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (++comp && i <= j)
	{
		while (++comp && a[i] < pivot)
        {
			i++;
        }
		while (++comp && a[j] > pivot)
        {
			j--;
        }
		if (++comp && i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}
void quickSort(int a[], int first, int last, unsigned long long &comp)
{
	int index = partition(a, first, last, comp);
	if (++comp && first < index - 1)
		quickSort(a, first, index - 1, comp);
	if (++comp && index < last)
		quickSort(a, index, last, comp);
}
int partition_t(int a[], int first, int last)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}

void quickSort_t(int a[], int first, int last)
{
	int index = partition_t(a, first, last);
	if (first < index - 1)
		quickSort_t(a, first, index - 1);
	if (index < last)
		quickSort_t(a, index, last);
}



//Bubble Sort

void bubbleSort (int a[], int n, unsigned long long &com)
{
    for (int i = 0; ++com && i < n - 1; i++)
    {
        for (int j = n - 1; ++com &&  j >= i; j--)
        {
            if (++com && a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

void bubbleSort_t (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

//Merge Sort
void merge(int a[], int first, int mid, int last,unsigned long long &comp)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = 0; ++comp && i < n1; i++)
    {
		L[i] = a[first + i];
    }
	for (int j = 0; ++comp && j < n2; j++)
    {
		R[j] = a[mid + j + 1];
    }	int i = 0;
	int j = 0;
	int k = first;
	while (++comp && i < n1 && ++comp && j < n2)
    {
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    }
	while (++comp && j < n2){
		a[k++] = R[j++];
    }
	while (++comp && i < n1)
    {
		a[k++] = L[i++];
    }
	delete[] L;
	delete[] R;
}
void mergeSort(int a[], int first, int last,unsigned long long &comp)
{
	if (++comp && first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(a, first, mid, comp);
		mergeSort(a, mid + 1, last, comp);
		merge(a, first, mid, last, comp);
	}
}

void merge_t(int a[], int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[first + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + j + 1];
	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2)
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];

	while (j < n2)
		a[k++] = R[j++];
	while (i < n1)
		a[k++] = L[i++];
	delete[] L;
	delete[] R;
}
void mergeSort_t(int a[], int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort_t(a, first, mid);
		mergeSort_t(a, mid + 1, last);
		merge_t(a, first, mid, last);
	}
}


//Heap sort

void heapify(int* a,int i , int n, unsigned long long &com)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2*i + 2;

    if(++com && l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if(++com && r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if(++com && largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest, n, com);
    }
} 

//Heap sort
void heapSort(int* a, int n, unsigned long long &com)
{
    for(int i = n / 2 - 1;++com &&  i >= 0; i--)
    {
        heapify(a, i,n, com);
    }
    for(int i = n-1;++com &&  i > 0; i--)
    {
        swap(a [0], a[i]);
        heapify(a, 0, i, com);
    }
}

void heapify_t(int* a,int i , int n){
    //set the root element index as i
    int largest = i;
    // calculate the position of left child
    int l = 2 * i + 1;
    // calculate the position of right child
    int r = 2*i + 2;

    //if left child is greater than root, their's value is swap
    if(l < n && a[l] > a[largest]){
        largest = l;
    }
    //if left child is greater than current root, their's value is swap
    if(r < n && a[r] > a[largest]){
        largest = r;
    }

    if(largest != i){
        swap(a[i],a[largest]);

        // Recursively heapify  the afected sub tree
        heapify_t(a,largest, n);
    }
} 

//Heap sort
void heapSort_t(int* a, int n){
    // heapify the array 
    for( int i = n / 2 - 1; i >= 0; i--){
        heapify_t(a, i,n);
    }
    // arrange element one by one
    for(int i = n-1; i > 0; i--){
        // Move current root to the end
        swap(a [0], a[i]);
        // use heapify on the reduced heap
        heapify_t(a, 0, i);
    }
}

//Shaker Sort 
void shakerSort (int a[], int n, unsigned long long &com)
{
    int left = 0;
    int right = n - 1;
    int temp = right;
    while (++com && left < right)
    {
        for (int i = right; ++com && i > left; i--)
        {
            if (++com && a[i] < a[i - 1])
            {
                swap (a[i], a[i - 1]);
                temp = i;
            }
        }
        left = temp;
        for (int j = left; ++com && j < right; j++)
        {
            if (++com && a[j] > a[j + 1])
            {
                swap (a[j], a[j + 1]);
                temp = j;
            }
        }
        right = temp;
    }
}

void shakerSort_t (int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int temp = right;
    while ( left < right)
    {
        for (int i = right;  i > left; i--)
        {
            if ( a[i] < a[i - 1])
            {
                swap (a[i], a[i - 1]);
                temp = i;
            }
        }
        left = temp;
        for (int j = left;  j < right; j++)
        {
            if ( a[j] > a[j + 1])
            {
                swap (a[j], a[j + 1]);
                temp = j;
            }
        }
        right = temp;
    }
}


//Radix sort function

int getMax(int arr[], int n, unsigned long long  &compare){
    int mx = arr[0];
    for (int i = 1; ++compare && i < n ; i++)
        if (++compare && arr[i] > mx)
            mx = arr[i];
    return mx;
}

void count_sort(int arr[], int n, int exp,unsigned long long  &compare){
    int* temp = new int[n]; // temp array
    int i, count[10] = { 0 };
    for (i = 0; ++compare && i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; ++compare && i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; ++compare && i >= 0; i--) {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }  
    for (i = 0; ++compare && i < n; i++)
        arr[i] = temp[i];
}

void radixSort(int arr[], int n,unsigned long long  &compare) {
    int m = getMax(arr, n, compare);
    for (int exp = 1; ++compare && (m / exp > 0); exp *= 10)
        count_sort(arr, n, exp, compare);
}

int getMax_t(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n ; i++)
        if ( arr[i] > mx)
            mx = arr[i];
    return mx;
}

void count_sort_t(int arr[], int n, int exp){
    int* temp = new int[n]; // temp array
    int i, count[10] = { 0 };
    for (i = 0;  i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }  
    for (i = 0;  i < n; i++)
        arr[i] = temp[i];
}

void radixSort_t(int arr[], int n){
    int m = getMax_t(arr, n);
    for (int exp = 1; (m / exp > 0); exp *= 10)
        count_sort_t(arr, n, exp);
}
//counting sort
void countingSort_t(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++) //Tìm phần tử lớn nhất trong mảng gốc
	{
		if (a[i] > max) max = a[i];
	}

	int* count = new int[max + 1]; //Tạo mảng đếm số lần xuất hiện của mỗi phần tử, độ dài mảng: max + 1
	for (int i = 0; i <= max; i++) //Gán các phần tử của mảng count = 0
	{
		count[i] = 0;
	}

	for (int i = 0; i < n; i++) //Đếm số lần xuất hiện của các phần tử trong mảng gốc
	{
		count[a[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	int* temp = new int[n]; //Mảng tạm 
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}

	delete[] count;
	delete[] temp;
}

void countingSort(int a[], int n, unsigned long long& comp)
{
	int max = a[0];
	for (int i = 1; ++comp, i < n; i++) //Tìm phần tử lớn nhất trong mảng gốc
	{
		if (a[i] > max) max = a[i];
	}

	int* count = new int[max + 1]; //Tạo mảng đếm số lần xuất hiện của mỗi phần tử, độ dài mảng: max + 1
	for (int i = 0; ++comp, i <= max; i++) //Gán các phần tử của mảng count = 0
	{
		count[i] = 0;
	}

	for (int i = 0; ++comp, i < n; i++) //Đếm số lần xuất hiện của các phần tử trong mảng gốc
	{
		count[a[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	int* temp = new int[n]; //Mảng tạm 
	for (int i = 0; ++comp, i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; ++comp, i < n; i++)
	{
		a[i] = temp[i];
	}

	delete[] count;


	delete[] temp;
}

//shell Sort
void shellSort_t(int a[], int n)
{
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}

void shellSort(int a[], int n, unsigned long long &comp)
{
	for (int interval = n / 2; ++comp && interval > 0; interval /= 2)
	{
		for (int i = interval; ++comp && i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; ++comp && j >= interval && ++comp && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}


//flash sort
//https://github.com/leduythuccs/Sorting-Algorithms/blob/master/sorting-methods/flash_sort.h
void flashSort_t(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort_t(a, n);
}

void flashSort(int a[], int n, unsigned long long &comp)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++comp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		if (++comp && a[i] < minVal)
			minVal = a[i];
		if (++comp && a[i] > a[max])
			max = i;
	}
	if (++comp && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0;++comp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1;++comp && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++comp && nmove < n - 1)
	{
		while (++comp &&j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (++comp &&k < 0) break;
		while (++comp &&j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n, comp);
}



void chooseAlgo_com(string algo, int arr[], int n, unsigned long long  &com){
    if (algo== "bubble-sort" ){
        bubbleSort(arr, n, com);
        return;
    }
    else if (algo== "shaker-sort" ){
        shakerSort(arr, n, com);
        return;
    }
    else if (algo== "heap-sort" ){
        heapSort(arr, n, com);
        return;
    }
    else if (algo== "selection-sort" ){
        selectionSort(arr, n, com);
        return;
    }
    else if (algo== "insertion-sort" ){
        insertionSort(arr, n, com);
        return;
    }
    else if (algo== "merge-sort" ){
        mergeSort(arr,0, n, com);
        return;
    }
    else if (algo== "quick-sort"){
        quickSort(arr, 0, n, com);
        return;
    }
    else if (algo== "radix-sort"){
        radixSort(arr, n, com);
        return;
    }
    else if (algo== "shell-sort"){
        shellSort(arr, n, com);
        return;
    }
    else if (algo== "counting-sort"){
        countingSort(arr, n, com);
        return;
    }
    else if (algo== "flash-sort"){
        flashSort(arr, n, com);
        return;
    }
}

void chooseAlgo_time(string algo, int arr[], int n){
    if (algo== "bubble-sort" ){
        bubbleSort_t(arr, n);
        return;
    }
    else if (algo== "shaker-sort" ){
        shakerSort_t(arr, n);
        return;
    }
    else if (algo== "heap-sort" ){
        heapSort_t(arr, n);
        return;
    }
    else if (algo== "selection-sort" ){
        selectionSort_t(arr, n);
        return;
    }
    else if (algo== "insertion-sort" ){
        insertionSort_t(arr,n);
        return;

    }
    else if (algo== "merge-sort" ){
        mergeSort_t(arr, 0, n);
        return;
    }
    else if (algo== "quick-sort"){
        quickSort_t(arr,0, n);
        return;
    }
    else if (algo== "radix-sort"){
        radixSort_t(arr, n);
        return;
    }
    else if (algo== "shell-sort"){
        shellSort_t(arr, n);
        return;
    }
    else if (algo== "counting-sort"){
        countingSort_t(arr, n);
        return;
    }
    else if (algo== "flash-sort"){
        flashSort_t(arr,n);
        return;
    }
}






// miscellaneous
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void readFile(string given,int& n, int* &a){
    ifstream fIn;
    fIn.open(given, ios::in);
    fIn >> n;
    fIn.ignore();
    a = new int[n];
    int i = 0;
    while(!fIn.eof())
    {
        fIn >> a[i];
        i++;
    }
    fIn.close();
}

void writeTXT (string out,int a[], int n)
{
    fstream file;
    file.open (out, ios::out);
    file << n << endl;
    for (int i = 0; i < n; i++)
    {
        file << a[i] << " ";
    }
    file.close ();
}