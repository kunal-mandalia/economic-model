#include "./economic-model.h"
#include "stdio.h"
#include "stdlib.h"

simulation *_simulation;
person **_people;

simulation *initialiseSimulation(int year, person **people)
{
  _simulation = malloc(sizeof(simulation));
  _simulation->year = year;
  _people = people;

  return _simulation;
}

simulation *getSimulation() { return _simulation; }

person **getPeople() { return _people; }

void simulateYear()
{
  _simulation->year += 1;
  int peopleCount = countPeople(_people);
  for (int i = 0; i < peopleCount; i++)
  {
    personTick(_simulation->year, _people[i]);
  }
}

void simulateYears(int years)
{
  for (int i = 0; i < years; i++)
  {
    simulateYear();
  }
}

void clearSimulation()
{
  if (_people != NULL)
  {
    int done = 0;
    int index = 0;

    while (done == 0)
    {
      if (_people[index] == NULL)
      {
        done = 1;
      }
      else
      {
        free(_people[index]);
        index++;
      }
    }

    free(_people);
  }

  if (_simulation != NULL)
  {
    free(_simulation);
  }
}
