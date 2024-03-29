#include "./economic-model.h"
#include <stdlib.h>

/**
 * based on a persons existing experience
 * suggest an appropriate next step
 */
experience_option *getNextOpportunity(int year, person *_person)
{
  experience_option *option = malloc(sizeof(experience_option));
  option->year = year;

  if (_person->experience == NULL)
  {
    option->category = EDUCATION;
    option->level = LOW;
    return option;
  }
  return NULL;
}
