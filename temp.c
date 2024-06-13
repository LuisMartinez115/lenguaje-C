#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCALITIES 100

typedef struct {
  char localidad[50];
  int hombres;
  int mujeres;
} poblacion;

poblacion *read_data(char *archivo, int *num_localities) {
  FILE *fp;
  poblacion *localities;
  int i = 0;

  fp = fopen(archivo, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 0;
  }

  // Count the number of lines in the file
  while (!feof(fp)) {
    if (fgetc(fp) == '\n') {
      (*num_localities)++;
    }
  }
  rewind(fp); 

  localities = (poblacion *)malloc((*num_localities) * sizeof(poblacion));
  if (localities == NULL) {
    printf("Memory allocation error.\n");
    exit(1);
  }

  // Read data from the file
  while (fscanf(fp, "%[^,],%d,%d", localities[i].localidad, &localities[i].hombres, &localities[i].mujeres) != EOF) {
    i++;
  }
  fclose(fp);
  return localities;
}

void calculate_stats(poblacion *localities, int num_localities, int *max_population, int *min_population, double *mean, double *std_dev) {
  int total_population = 0;
  double variance = 0;
  int i;

  *max_population = localities[0].hombres + localities[0].mujeres;
  *min_population = localities[0].hombres + localities[0].mujeres;
  for (i = 0; i < num_localities; i++) {
    int population = localities[i].hombres + localities[i].mujeres;
    total_population += population;
    if (population > *max_population) {
      *max_population = population;
    }
    if (population < *min_population) {
      *min_population = population;
    }
  }
  *mean = (double)total_population / num_localities;

  for (i = 0; i < num_localities; i++) {
    int population = localities[i].hombres + localities[i].mujeres;
    variance += pow(population - *mean, 2);
  }
  *std_dev = sqrt(variance / num_localities);
}

void print_stats(int max_population, int min_population, double mean, double std_dev) {
  printf("Maximum Population: %d\n", max_population);
  printf("Minimum Population: %d\n", min_population);
  printf("Arithmetic Mean: %.2lf\n", mean);
  printf("Standard Deviation: %.2lf\n", std_dev);
}

int main() {
  char archivo[100] = "muestra.csv"; // Set the filename here
  poblacion *localities;
  int num_localities = 0;
  int max_population, min_population;
  double mean, std_dev;

  localities = read_data(archivo, &num_localities);
  calculate_stats(localities, num_localities, &max_population, &min_population, &mean, &std_dev);
  print_stats(max_population, min_population, mean, std_dev);

  free(localities);
  return 0;
}