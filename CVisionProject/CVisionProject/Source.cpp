#include <iostream>
#include<vector>
#include<cmath>
using namespace std;


union X
{
	unsigned long number;
	unsigned char bytes[4];
};

vector<int> ConvertBytesToIntVector(vector<unsigned char> bytes, long long int sizeFile){

	long long int sizeNumb = sizeFile / 4;

	vector<int> result(sizeNumb);
	for (int i = 0, int j = 0 ; i < sizeNumb; i += 4,++j){
		X x;
		x.bytes[0] = bytes[i];
		x.bytes[1] = bytes[i+1];
		x.bytes[2] = bytes[i+2];
		x.bytes[3] = bytes[i+3];
		result[j] = x.number;
	}
	return result;
}

vector<int> Rotate(const vector<int>& image, double angle){
	double PI = std::atan(1.0) * 4;
	angle = 180 * angle / PI;
	long long int N = sqrt(image.size);

	vector<int> resultImage(image.size());

	for (int yi = 0; yi < N; ++yi) {
		for (int xj = 0; xj < N; ++xj) {
			int nX = cos(angle)*xj - sin(angle)*yi;
			int nY = sin(angle)*xj + cos(angle)*yi;

			resultImage[nY * N + nX] = image[yi * N + jx];
		}
	}
	return resultImage;
}

vector<unsigned char> ConvertIntToBytesVector(vector<int> img){

	long long int sizeVecBytes = img.size() * 4;

	vector<unsigned char> result(sizeVecBytes);
	for (int i = 0; i < img.size(); ++i){
		X x;
		x.number = img[i];
		result[i] = x.bytes[0];
		result[i] = x.bytes[1];
		result[i] = x.bytes[2];
		result[i] = x.bytes[3];
		result[j] = x.number;
	}
	return result;
}

int main() {
	long long int sizeFile = 0;
	cout << "Input file size"<< endl;
	cin >> sizeFile;
	//ConvertIntToBytesVector(Rotate(ConvertBytesToIntVector(bytearr, sizeFile),90))
	//Демонстрация в программе не предусмотрена
	//Алгоритм
	//Из массива байтов получим массивом интов(по 4 байта)
	//Затем поворачиваем используя матрицу поворота
	//Ну и теперь обратно из интов в байты
}