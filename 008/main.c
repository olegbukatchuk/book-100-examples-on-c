//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Как работает long
int main(void) {

    int a;
    long b;
    long long c;
    double e;
    long double f;

    printf("Размер int = %ld байт\n",sizeof(a));
    printf("Размер long = %ld байт\n",sizeof(b));
    printf("Размер long long = %ld байт\n",sizeof(c));

    printf("Размер double = %ld байт\n",sizeof(e));
    printf("Размер long double = %ld байт\n",sizeof(f));

    return 0;
}
