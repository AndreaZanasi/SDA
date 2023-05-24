#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

int ScheduleJobs(const job* jobs, size_t j_size) {

    if (jobs == NULL || j_size == 0) {
        return 0;
    }

    int t = 0;
    int p = 0;

    double* v = calloc(j_size, sizeof(double));

    for (size_t i = 0; i < j_size; i++) {
        v[i] = (double)jobs[i].profit / (double)jobs[i].duration;
    }

    int max = 0;

    for (size_t i = 0; i < j_size; i++) {
        for (size_t j = 0; j < j_size; j++) {

            if (v[max] <= v[j]) {
                if (v[max] == v[j]) {
                    if (jobs[max].duration > jobs[j].duration) {
                        max = (int)j;
                    }
                    else {
                        continue;
                    }
                }
                max = (int)j;
            }
            
        }
        if (jobs[max].duration + t <= jobs[max].deadline) {
            t += jobs[max].duration;
            p += jobs[max].profit;
            printf("%d ", max);
        }
        v[max] = 0;
    }

    free(v);

    return p;
}