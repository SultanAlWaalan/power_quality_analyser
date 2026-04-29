#include <stdio.h>
#include <stdlib.h>
#include "io.h"

WaveformSample *load_csv(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[512];

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    }

    int rows = 0;
    while (fgets(line, sizeof(line), file)) {
        rows++;
    }

    if (rows == 0) {
        fclose(file);
        return NULL;
    }

    WaveformSample *samples = malloc(rows * sizeof(WaveformSample));
    if (samples == NULL) {
        fclose(file);
        return NULL;
    }

    rewind(file);
    fgets(line, sizeof(line), file);

    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL && i < rows) {
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &samples[i].timestamp,
               &samples[i].phase_A_voltage,
               &samples[i].phase_B_voltage,
               &samples[i].phase_C_voltage,
               &samples[i].line_current,
               &samples[i].frequency,
               &samples[i].power_factor,
               &samples[i].thd_percent);
        i++;
    }

    fclose(file);
    *count = rows;
    return samples;
}
