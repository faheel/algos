/*
Bucket sort
----------------------
Distributing the elements of an array into a number of buckets. Bucket sort
is mainly useful when input is uniformly distributed over a range. Each bucket
is then sorted individually, either using a different sorting algorithm, or by
recursively applying the bucket sorting algorithm.
Time complexity
---------------
O(N), where N is the number of elements.
Space complexity
----------------
O(N), where N is the number of elements.
*/
#include <iostream>
using namespace std;
int insertion_sort(float input_array[], const int n) {
	int counter = 0, j;
	for (int i = 0; i < n; i++) {
		float temp = input_array[i];
		for (j = i; j > 0; j--) {
			if (input_array[j - 1] > temp) {
				break;
			}
			counter++;
			input_array[j] = input_array[j - 1];	//Shift numbers to right
		}
		input_array[j] = temp;
	}
	return counter;
}
void bucket_sort(float input_array[], const int n) {
	//a started with 1 to n+1
	int max = input_array[0], maxPer = 0;
	for (int i = 1; i < n + 1; i++) {
		if (input_array[i] > max) {
			max = input_array[i];
		}
	}
	while (max != 0) {
		max /= 10;
		maxPer++;
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < maxPer; j++) {
			input_array[i] /= 10;
		}
	}
	float **bucket;
	bucket = new float*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		bucket[i] = new float[n + 1];
	}
	for (int i = 0; i < n + 1; i++) {
		bucket[i][0] = 0;
	}
	for (int i = 1; i < n + 1; i++) {
		int d = (int)floor(n - n*input_array[i] + 1), e = bucket[d][0];
		bucket[d][e + 1] = input_array[i];
		bucket[d][0]++;
	}
	for (int i = 0; i < n; i++) {
		int num = bucket[i][0];
		float *t;
		t = new float[num];
		for (int j = 1, k = 0; j < num + 1; j++, k++) {
			t[k] = bucket[i][j];
		}
		insertion_sort(t, num);
		for (int j = 1, k = 0; j < num + 1; j++, k++) {
			bucket[i][j] = t[k];
		}
	}
	//Show the result
	for (int i = 0; i < n + 1; i++) {
		int num = bucket[i][0];
		for (int j = 1; j < num + 1; j++) {
			cout << bucket[i][j] << "  ";
		}
	}
	cout << endl;
}
int main() {
	int number_of_inputs;
	float *input_array;
	cin >> number_of_inputs;
	input_array = new float[number_of_inputs];
	for (int i = 1; i < number_of_inputs + 3; i++) {
		cin >> input_array[i];
	}
	bucket_sort(input_array, number_of_inputs);
	return 0;
}