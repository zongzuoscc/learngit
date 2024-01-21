#include <iostream>
#include <iomanip>

using namespace std;

class Salesperson {
private:
	int num; // 员工编号
	int quantity; // 销售数量
	double price; // 商品单价
	static double discount; // 商品折扣
	static double totalPrice; // 总销售款
	
public:
	Salesperson(int num, int quantity, double price) : num(num), quantity(quantity), price(price) { }
	
	static void setDiscount(double d) {
		discount = d;
	}
	
	static void addSales(int quantity, double price) { // 添加销售情况
		price *= (1 - discount);
		double totalPrice = quantity * price;
		if (quantity >= 10) {
			totalPrice *= 0.98;
		}
		Salesperson::totalPrice += totalPrice;
	}
	
	static double getAveragePrice(int count) { // 计算平均售价
		if (count == 0) {
			return 0.0;
		} else {
			return Salesperson::totalPrice / count;
		}
	}
	
	static double getSum() { // 获取总销售款
		return Salesperson::totalPrice;
	}
};

double Salesperson::discount = 0.0; // 静态成员变量初始化
double Salesperson::totalPrice = 0.0;

int main() {
	int n; // 售货员人数
	double discount; // 统一的折扣
	cin >> n >> discount;
	
	Salesperson::setDiscount(discount); // 设置当天的折扣
	
	for (int i = 0; i < n; i++) { // 依次读入售货员的销售情况，并添加到Salesperson中
		int num, quantity;
		double price;
		cin >> num >> quantity >> price;
		Salesperson::addSales(quantity, price);
	}
	
	double totalPrice = Salesperson::getSum();
	double avgPrice = Salesperson::getAveragePrice(n);
	
	cout << setiosflags(ios::fixed) << setprecision(2) << totalPrice << " " << avgPrice << endl;
	
	return 0;
}
