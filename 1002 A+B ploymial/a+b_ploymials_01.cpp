#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
class singleUnit {
public:
	int exp;
	double cof;
};
class poly {
private:
	int k;
	int highestExp;
	singleUnit* unitList;
public:
	void setK(int k) {
		this->k = k;
		this->unitList = (singleUnit*)malloc(k * sizeof(singleUnit));
	}
	int getK() {
		return this->k;
	}
	void setHighestExp(int highestExp) {
		this->highestExp = highestExp;
	}
	void setUnitList(singleUnit* unitList) {
		this->unitList = unitList;
	}
	singleUnit* getUnitList() {
		return this->unitList;
	}
	poly() {
	}
	poly(int k) {
		this->k = k;
		this->unitList = (singleUnit*)malloc(k * sizeof(singleUnit));
		for (int i = 0; i < k; i++) {
			scanf("%d", &this->unitList[i].exp);
			scanf("%lf", &this->unitList[i].cof);
		}
		this->highestExp = this->unitList[0].exp;
	}
	friend poly operator+(poly a, poly b) {
		//get highestExp
		int highestExp = a.unitList[0].exp > b.unitList[0].exp ? a.unitList[0].exp : b.unitList[0].exp;
		poly dst;
		//set highestExp
		dst.setHighestExp(highestExp);
		//get K & unitList
		int k = 0;
		singleUnit* unitList = (singleUnit*)malloc((highestExp + 1) * sizeof(singleUnit));
		singleUnit* src1 = a.getUnitList();
		int k1 = a.getK();
		singleUnit* src2 = b.getUnitList();
		int k2 = b.getK();
		for (int i = highestExp; i >= 0; i--) {
			//init the unitList
			unitList[highestExp - i].exp = i;
			unitList[highestExp - i].cof = 0;
			//search src1 to check if it is possible to add on
			for (int j = 0; j < k1; j++) {
				if (src1[j].exp == i) {
					unitList[highestExp - i].cof += src1[j].cof;
					break;
				}
			}
			//search src2 to check if it is possible to add on
			for (int j = 0; j < k2; j++) {
				if (src2[j].exp == i) {
					unitList[highestExp - i].cof += src2[j].cof;
					break;
				}
			}
			//check whether the cof exists and count the K(num of nonzero terms) 
			if (unitList[highestExp - i].cof) {
				k++;
			}
		}
		//create the unitList used to return 
		singleUnit* unitListFinal = (singleUnit*)malloc(k * sizeof(singleUnit));
		//transmit the value from intermediate variable to final variable( to Eliminate blank area)
		int i = 0;
		for (int j = 0; j < highestExp+1; j++) {
			if (unitList[j].cof) {
				unitListFinal[i].exp = unitList[j].exp;
				unitListFinal[i].cof = unitList[j].cof;
				i++;
			}
		}

		//set k & unitList
		dst.setK(k);
		dst.setUnitList(unitListFinal);
		return dst;
	}
	friend ostream& operator<<(ostream& out, poly& p)    //overload the output stream
	{
		out << p.getK();
		out << fixed;
		out << setprecision(1);
		for (int j = 0; j < p.getK(); j++) {
			out << " ";
			out << p.getUnitList()[j].exp;
			out << " ";
			out << p.getUnitList()[j].cof;
		}
		return out;
	}
};

int main() { 
	int k;
	scanf("%d", &k);
	poly a(k);
	scanf("%d", &k);
	poly b(k);
	poly c = a + b;
	cout << c;
	return 0;
}


