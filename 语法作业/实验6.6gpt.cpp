/*3 0.05
  101  5  23.66
  102 12 24.22
  103 100 21.88
  
  2420.00 20.68
 */
#include <iostream>
#include <iomanip>
using namespace std;

class Salesperson {
private:
	int num;//员工编号
	int quantity;//销售数量
	double price;//商品单价
	static double discount;//商品折扣
	static double sum;//总销售款
	
public:
	Salesperson(int num, int quantity, double price) : num(num), quantity(quantity), price(price) 
	{
		price=price*(1-discount);
		double totalPrice = quantity * price;
		if (quantity >10) 
		{
			totalPrice *= (1 - 0.02);
		}
		sum += totalPrice;
	}
	
	static void setDiscount(double d) 
	{
		discount = d;
	}
	
	static double getAveragePrice(int count) 
	{
		return sum / count;
	}
	
	static double getSum() 
	{
		return sum;
	}
};

double Salesperson::discount = 0.0;
double Salesperson::sum = 0.0;

int main() 
{
	int n;
	double discount;
	cin >> n >> discount;
	int quantities;
	Salesperson::setDiscount(discount);
	
	for (int i = 0; i < n; i++)
	{
		int num, quantity;
		double price;
		cin >> num >> quantity >> price;
		
		Salesperson salesperson(num, quantity, price);
		quantities+=quantity;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << Salesperson::getSum() << " " << Salesperson::getAveragePrice(quantities) << endl;
	
	return 0;
}
