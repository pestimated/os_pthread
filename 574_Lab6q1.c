//2.5 เจอมาแค่แบบเดียวเองค่ะ คือ จะไม่ทำลูกเลย ทำแค่แม่ output จะเป็น -(parent คำนวณ)
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int msum, csum;
void *runner(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);

    int upper = atoi(argv[1]);
    for(int i = 0; i <= upper; i++) {
        msum += i;
    }

    printf("The difference : %d - %d = %d\n", csum, msum, csum - msum);
    return 0;
}
void *runner(void *param) {
    int upper = atoi(param);
    int i;
    if(upper > 0) {
        for(i = 0; i <= upper * 2; i++) {
            csum += i;
        }
    }
    pthread_exit(0);
}
