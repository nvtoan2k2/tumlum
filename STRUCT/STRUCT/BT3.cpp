#include <iostream>
using namespace std;

const int MAX_DEGREE = 100;

struct Polynomial {
    int degree;
    int coefficients[MAX_DEGREE];
};

void inputPolynomial(Polynomial& p) {
    cout << "Nhập bậc của đa thức: ";
    cin >> p.degree;
    cout << "nhập hệ số: ";
    for (int i = p.degree; i >= 0; i--) {
        cin >> p.coefficients[i];
    }
}

void outputPolynomial(Polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        cout << p.coefficients[i] << "x^" << i << " + ";
    }
    cout << p.coefficients[0] << endl;
}
Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial sum;
    sum.degree = max(p1.degree, p2.degree);
    for (int i = sum.degree; i >= 0; i--) {
        sum.coefficients[i] = p1.coefficients[i] + p2.coefficients[i];
    }
    return sum;
}
Polynomial subtractPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial diff;
    diff.degree = max(p1.degree, p2.degree);
    for (int i = diff.degree; i >= 0; i--) {
        diff.coefficients[i] = p2.coefficients[i] - p1.coefficients[i];
    }
    return diff;
}
Polynomial multiplyPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial product;
    product.degree = p1.degree + p2.degree;
    for (int i = 0; i <= p1.degree; i++) {
        for (int j = 0; j <= p2.degree; j++) {
            product.coefficients[i + j] += p1.coefficients[i] * p2.coefficients[j];
        }
    }
    return product;
}

Polynomial differentiatePolynomial(Polynomial p) {
    Polynomial derivative;
    derivative.degree = p.degree - 1;
    for (int i = 0; i < p.degree; i++) {
        derivative.coefficients[i] = p.coefficients[i + 1] * (i + 1);
    }
    return derivative;
}

Polynomial differentiatePolynomialK(Polynomial p, int k) {
    if (k == 0) {
        return p;
    }
    if (p.degree <= 0) {
        Polynomial emptyPolynomial = { 0, {0} };
        return emptyPolynomial;
    }
    Polynomial derivative = differentiatePolynomial(p);
    return differentiatePolynomialK(derivative, k - 1);
}
int main() {
    Polynomial p1, p2, sum, diff, product, derivative;
    cout << "Nhập đa thức đầu tiên: " << endl;
    inputPolynomial(p1);
    cout << "Nhập đa thức thứ hai: " << endl;
    inputPolynomial(p2);
    sum = addPolynomials(p1, p2);
    cout << "Tổng của hai đa thức là: \n";
    outputPolynomial(sum);
    diff = subtractPolynomials(p1, p2);
    cout << "Hiệu của hai đa thức là: \n";
    outputPolynomial(diff);
    product = multiplyPolynomials(p1, p2);
    cout << "Tích của hai đa thức là: \n";
    outputPolynomial(product);
    derivative = differentiatePolynomial(p1);
    cout << "Đạo hàm bậc nhất của đa thức là: \n";
    outputPolynomial(derivative);
    int k;
    cin >> k;
    derivative = differentiatePolynomialK(p1, k);
    cout << "Dao ham thu " << k << "cua da thuc: ";
    outputPolynomial(derivative);
    return 0;
}
