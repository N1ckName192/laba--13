#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void first() {
    int i,j,n,h,k,a[101]={0};
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&k);

        for(j=0;j<k;j++){
            scanf("%d",&h);
            a[h]++;
        }

    }
    for(i=1;i<101;i++){
        if(a[i]==n)
            printf("%d ",i);
    }
}

void second() {
    int n;
    scanf("%d", &n);
    int a[n-1], i, sum1=0, sum2=0;

    for(i=0; i<n-1; i++){
        scanf("%d", &a[i]);
        sum1=sum1+a[i];
    }
    for(i=1; i<=n; i++){
        sum2=sum2+i;
    }
    printf("%d", sum2-sum1);

    return 0;
}

void swap (char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void third() {
    long long t;
    scanf("%lld", &t);

    for (long long i = 0; i < t; i++) {
        char letters[1001];
        scanf("%s", letters);

        bool isIdeal = false;
        long long count_of_elements = strlen(letters);

        for (long long j = 0; j < count_of_elements; j++) {
            if (letters[j] != letters[0]) {
                swap (&letters[j], &letters[count_of_elements - 1]);
                isIdeal = true;
                break;
            }
        }

        if (!isIdeal) {
            printf("-1\n");
        } else {
            printf("%s\n", letters);
        }
    }

    return 0;
}

#define AMOUNT_OF_LETTER 26
#define MAX_AMOUNT_OF_SYMBOLS_IN_NAME 21

void getArrayAmountOfFirstSymbols(int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        char s[MAX_AMOUNT_OF_SYMBOLS_IN_NAME];
        scanf("%s", s);
        a[s[0] - 'a']++;
    }
}

int getAmountOfPairsForOneSymbol(int count_of_name) {
    int b1 = count_of_name / 2;
    int b2 = count_of_name - b1;
    return b1 * (b1 - 1) / 2 + b2 * (b2 - 1) / 2;
}

int getAmountOfPairs(int *array_of_zero) {
    int count_of_pairs = 0;
    for (size_t i = 0; i < AMOUNT_OF_LETTER; i++) {
        count_of_pairs += getAmountOfPairsForOneSymbol(array_of_zero[i]);
    }

    return count_of_pairs;
}

void four() {
    size_t n;
    scanf("%llu", &n);

    int array_of_zero[AMOUNT_OF_LETTER] = {0};

    getArrayAmountOfFirstSymbols(array_of_zero, n);

    printf("%d", getAmountOfPairs(array_of_zero));

    return 0;
}

void five() {
    int n, k;
    scanf("%d %d", &n, &k);

    char colors[101];
    scanf("%s", colors);

    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[colors[i] - 'a']++;
    }

    bool possible = true;
    for (int i = 0; i < 26; i++) {
        if (count[i] > k) {
            possible = false;
            break;
        }
    }

    if (possible) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

void six() {
    char string[100001];
    int puppyAmount;
    bool flag = false;

    scanf("%d %s", &puppyAmount, string);

    for (int i = 0; i < puppyAmount; i++) {
        for (int j = i + 1; j < puppyAmount; j++) {
            if (string[i] == string[j]) {
                flag = true;

                break;
            }
        }

        if (flag) {
            break;
        }
    }

    if (puppyAmount == 1) {
        flag = true;
    }

    printf(flag ? "Yes" : "No");
}

void seven() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[51];
    scanf("%s", s);

    qsort(s, n, sizeof(char), (int(*)(const void*, const void*)) strcmp);

    int total_weight = 0;
    char last_step = 'a' - 2;
    int used_steps = 0;

    for (int i = 0; i < n && used_steps < k; i++) {
        if (s[i] - last_step >= 2) {
            total_weight += s[i] - 'a' + 1;
            last_step = s[i];
            used_steps++;
        }
    }

    if (used_steps == k) {
        printf("%d\n", total_weight);
    } else {
        printf("-1\n");
    }

    return 0;
}

void eight() {
    int n;
    scanf("%d", &n);

    int hight[1001] = {0};
    int i, max_freq = 0, unique_count = 0;
    for (i = 0; i < n; i++) {
        int length;
        scanf("%d", &length);

        hight[length]++;

        if (hight[length] > max_freq)
            max_freq = hight[length];

        if (hight[length] == 1)
            unique_count++;

    }

    printf("%d %d\n", max_freq, unique_count);

    return 0;
}

void nine() {
    int number_of_student;
    scanf("%d", &number_of_student);

    int student_num[number_of_student + 3];
    for (int i = 1; i <= number_of_student; i++){
        scanf("%d", &student_num[i]);
    }
    int result[number_of_student + 3];
    int a = 1, n = 0;
    while (a < number_of_student + 1){
        for (int k = 0; k < number_of_student + 3; k++){
            result[k] = 0;
        }
        int ind = a;
        for (int j = ind; j < number_of_student + 3; ){
            result[j] += 1;
            j = student_num[j];

            for (int l = 1; l <= number_of_student + 3; l++){
                if (result[l] == 2){
                    printf("%d ", l);
                    n = 1;
                    break;
                }
            }
            if (n == 1){
                break;
            }
        }
        a++;
        n = 0;
    }
    printf("\n");

    return 0;
}

void ten() {
    int n;
    scanf("%d", &n);

    getchar();
    char str[n];
    gets(str);

    if(n > 26){
        printf("-1");
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(str[i] == str[j]){
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}

#define MAX_COUNT 1001

int compare(const void *a, const void *b){
    return *((char *) a) - *((char *) b);
}

void eleven() {
    int n;
    char s[1001];
    char m[1001];
    scanf("%d\n %s\n %s", &n, s, m);

    qsort(s, n, sizeof(char), compare);
    qsort(m, n, sizeof(char), compare);

    int cnt = 0;
    int j = 0;

    for(int i = 0; i < n; i++){
        while (j < n && s[i] > m[j]){
            j++;
        }
        if(j >= n){
            cnt++;
        }
        j++;
    }

    printf("%d\n", cnt);
    cnt = 0;
    j = 0;

    for(int i = 0; i < n; i++){
        while(j < n && s[i] >= m[j]){
            j++;
        }
        if(j < n){
            cnt++;
        }
        j++;
    }
    printf("%d\n", cnt);

    return 0;
}

void twelve() {
    int n, t, count[21] = {0};
    scanf("%d", &n);
    while (n--){
        scanf("%d", &t);
        count[t + 10] += 1;
    }

    long long result = (long long)(count[10]) * (long long)(count[10] - 1) /2;

    for (int i = 0; i < 10; ++i){
        result += (long long)(count[i]) * (long long)(count[20 - i]);
    }

    printf("%lld", result);

    return 0;
}