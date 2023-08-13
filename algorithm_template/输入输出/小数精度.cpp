
1. printf写法

// %.3lf: double数据小数点后面保留3位（四舍五入）
printf("%.3Lf\n", x);
// %.3lf: double数据只保留整数
printf("%.0Lf\n", x);

// %.3Lf: long double数据小数点后面保留3位（四舍五入）
printf("%.3Lf\n", x);
// %.3Lf: long double数据只保留整数
printf("%.0Lf\n", x);




2. C++写法

cout << fixed << setprecision(20) << endl;
后面cout小数时，小数点后面都会保留20位小数