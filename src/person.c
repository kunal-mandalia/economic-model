#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./economic-model.h"

person *makePerson(int birthYear, int deathYear, int iq, personality *_personality) {
  person *p = malloc(sizeof(person));
  p->birth_year = birthYear;
  p->death_year = deathYear;
  p->iq = iq;
  p->personality = _personality;
  return p;
}

int getAge(int year, person *p) {
  if (p == NULL) {
    return -1;
  }

  if (p->death_year > -1) {
    return (p->death_year - p->birth_year);
  }
  return year - p->birth_year;
}

int healthCheck(int year, person *p) {
  if (p->death_year != -1) {
    return p->death_year;
  }

  int age = getAge(year, p);

  if (age >= 100) {
    p->death_year = year;
    return year;
  }

  return -1;
}

void personTick(int year, person *p) {
  healthCheck(year, p);
}

int countPeople(person **people) {
  int i = 0;
  while (people[i] != NULL) {
    i++;
  }
  return i;
}

// from 1 to 10
int getGrowthFromExperience(experience_option *option, person *p) {
  int r = arc4random_uniform(10) + 1;
  return r;
}
